#include"LZ77.h"
#include<iostream>
#include<assert.h>
using namespace std;


LZ77::LZ77()
	: _pWin(new UCH[WSIZE * 2])
	, _ht(WSIZE)
	, _start(0)
{}

LZ77::~LZ77()
{
	if (_pWin)
	{
		delete[] _pWin;
	}
}

void LZ77::CompressFile(const std::string& filePath)
{
	FILE* fIn = fopen(filePath.c_str(), "rb");
	if (nullptr == fIn)
	{
		cout << "打开文件失败" << endl;
		return;
	}

	//获取文件大小
	fseek(fIn, 0, SEEK_END);
	ULL fileSize = ftell(fIn);
	fseek(fIn, 0, SEEK_SET);

	//文件大小小于三个字节，不需要进行压缩
	if (fileSize < 3)
		return;

	USH hashAddr = 0;
	//先读取一个滑动窗口数据
	size_t lookAhead = fread(_pWin, 1, 2*WSIZE,fIn);
	for (size_t i = 0; i < MIN_MATCH; i++)
		_ht.HashFunc(hashAddr, _pWin[i]);
	
	//写源文件后缀
	FILE* fOutD = fopen("1.lzp", "wb");
	assert(fOutD);
	string postFix = filePath.substr(filePath.rfind('.'));
	postFix += '\n';
	fwrite(postFix.c_str(), 1, postFix.size(), fOutD);

	FILE* fOutF = fopen("2.lzp", "wb");
	assert(fOutF);


	USH matchHead = 0;
	UCH chFlag = 0;
	UCH bitCount = 0;
	while (lookAhead)
	{
		//将start为首的是哪个字符插入到哈希表中
		_ht.Insert(hashAddr, _pWin[_start + 2], _start, matchHead);

		if (0 == matchHead)
		{
			//没有找到匹配,写源字符
			fputc(_pWin[_start], fOutD);
			++_start;
			--lookAhead;
			//写标记---源字符用0标记--false
			//写标记位
			WriteFlag(fOutF, chFlag, bitCount, false);
		}
		else
		{
			//找最长匹配
			UCH curMatchDist = 0;
			UCH curMatchLen = longMatch(matchHead, curMatchDist);
			
			//写距离长度对
			fputc(curMatchDist, fOutD);
			fputc(curMatchLen, fOutD);
			
			//写标记位
			//长度距离对--->用1进行标记
			WriteFlag(fOutF, chFlag, bitCount, true);
			
			lookAhead -= curMatchLen;

			//更新哈希表
			curMatchLen -= 1;
			while (curMatchLen)
			{
				++_start;
				_ht.Insert(hashAddr, _pWin[_start + 2], _start, matchHead);
				curMatchLen--;
			}
			++_start;
		}
	}
	//最后一个标记不满8个比特位需要特殊处理
	if (bitCount >> 0 && bitCount << 8)
	{
		chFlag <<= (8 - bitCount);
		fputc(chFlag, fOutF);
	}

	fclose(fIn);
	fclose(fOutF);

	//将标记文件中内容搬移到压缩文件中
	FILE* fInF = fopen("2.lzp", "rb");
	assert(fInF);
	UCH* pReadBuff = new UCH[1024];
	size_t flagSize = 0;
	while (true)
	{
		size_t rdSize = fread(pReadBuff, 1, 1024, fInF);
		if (0 == rdSize)
		{
			break;
		}
		flagSize += rdSize;
		fwrite(pReadBuff, 1, rdSize, fOutD);
	}

	fclose(fInF);

	fwrite(&fileSize, sizeof(fileSize), 1, fOutD);
	fwrite(&fileSize, sizeof(flagSize), 1, fOutD);

	fclose(fOutD);
	remove("2.lzp");
	
}

//matchHead--->哈希匹配链起始位置
UCH LZ77::longMatch(USH matchHead, UCH& curMatchDist)
{


	
	UCH curMatchLen = 0;
	UCH maxLen = 0;
	UCH pos = 0;
	UCH Matchchainlen = 255;
	do{	
		UCH* pStart = _pWin + _start;
		UCH* pEnd = pStart + MAX_MATCH;
		//在查找缓冲区找到匹配串的位置
		UCH* pCurStart = _pWin + matchHead;
		
		curMatchLen = 0;

		//找单条链的匹配长度
		while (pCurStart <pEnd && *pStart == *pCurStart)
		{
			pStart++;
			pCurStart++;
			curMatchLen++;
		}
		if (curMatchLen>maxLen)
		{
			maxLen = curMatchLen;
			pos = matchHead;		
		}
	} while((matchHead = _ht.GetNext(matchHead))&& Matchchainlen--);
	
	curMatchDist = _start - pos;

	return maxLen;
}



void  LZ77::WriteFlag(FILE* fOutF, UCH& chFlag, UCH& bitCount, bool IsChar)
{
	chFlag <<= 1;

	//检测当前标记是否为距离对
	if (IsChar)
	{
		chFlag |= 1;
	}
	
	bitCount++;
	if (8 == bitCount)
	{
		fputc(chFlag, fOutF);
		chFlag = 0;
		bitCount = 0;
	}
}

void LZ77::UNCompressFile(const std::string& filePath)
{
	string strPostFix = filePath.substr(filePath.rfind('.'));
	if (strPostFix != ".lzp")
	{
		cout << "压缩文件不支持" << endl;
		return;
	}

	FILE* fInD = fopen(filePath.c_str(),"rb");
	if (nullptr == fInD)
	{
		cout << "压缩文件打开失败" << endl;
		return;
	}

	//获取标记的的大小
	size_t flagSize = 0;
	int offset = 0 - sizeof(flagSize);
	fseek(fInD, offset, SEEK_END);
	
	fread(&flagSize, sizeof(flagSize), 1, fInD);
	
	//获取源文件的大小
	ULL fileSize = 0;
	offset = 0 - sizeof(fileSize)-sizeof(flagSize);
	fseek(fInD, offset, SEEK_END);
	fread(&fileSize, sizeof(fileSize), 1, fInD);

	//fInF作用：读取标记数据
	FILE* fInF = fopen(filePath.c_str(), "rb");
	assert(fInF);
	offset = 0 - (sizeof(fileSize) + sizeof(flagSize) + flagSize);
	fseek(fInF, offset, SEEK_END);
	
	//解压缩文件
	fseek(fInD, 0, SEEK_SET);
	string strUNComFileName("3");
	strPostFix = "";
	GetLine(fInD, strPostFix);
	strUNComFileName += strPostFix;

	//fOut作用：写压缩数据
	FILE* fOut = fopen(strUNComFileName.c_str(), "wb");
	assert(fOut);

	//处理长度距离对
	FILE* fWin = fopen(strUNComFileName.c_str(), "rb");
	assert(fWin);

	UCH charFlag = 0;
	char bitCount = -1;


	while (fileSize)
	{
		//读取标记
		if (bitCount < 0)
		{
			charFlag = fgetc(fInF);
			bitCount = 7;
		}
		//0	源数据
		//1	距离对
		if (charFlag & (1 << bitCount))
		{
			//距离对
			UCH dist = fgetc(fInD);
			UCH length = fgetc(fInD);

			fflush(fOut);
			fseek(fWin, 0 - dist, SEEK_END);
			fileSize -= length;
			

			while (length)
			{
				UCH ch = fgetc(fWin);
				fputc(ch, fOut);
				length--;
			}

		}
		else
		{
			UCH ch = fgetc(fInD);
			fputc(ch, fOut);
			fileSize -= 1;
		}

		bitCount--;
	}
	fclose(fInD);
	fclose(fInF);
	fclose(fOut);
	fclose(fWin);

}

void LZ77::GetLine(FILE* fIn, std::string& strContent)//获取每一行的信息的实现
{
	while (!feof(fIn))
	{
		char ch = fgetc(fIn);
		if ('\n' == ch)
		{
			return;
		}
		strContent += ch;
	}
}