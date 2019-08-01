#pragma once
#include<string>
#include<vector>
#include"HuffmanTree.hpp"

typedef unsigned char UCH;

//
struct CharInfo
{
	CharInfo(size_t charCount = 0)
		: _charCount(charCount)
	{}
	CharInfo operator+(const CharInfo& info)
	{
		return CharInfo(_charCount + info._charCount);
	}

	bool operator>(const CharInfo& info)
	{
		return _charCount > info._charCount;
	}

	bool operator!=(const CharInfo& info)const
	{
		return _charCount != info._charCount;
	}

	bool operator==(const CharInfo& info)const
	{
		return _charCount == info._charCount;
	}

	UCH _ch;
	size_t _charCount;
	std::string _strCode;
};


class FileCompressHuffM
{
public:
	FileCompressHuffM();
	void CompressFile(const std::string& strFilePath);//文件压缩部分
	void UNCompressFile(const std::string& strFilePath);//解压缩部分
	void WriteHead(FILE* fOut,const std::string& strFilePath);
private:
	void GetHuffmanCode(HuffmanTreeNode<CharInfo>* pRoot);
	void GetLine(FILE* fIn, std::string&strContent);
private:
	std::vector<CharInfo>_charInfo;
};

