#pragma once
#include"HashTable.h"
#include<string>


class LZ77
{
public:
	LZ77();
	~LZ77();

	void CompressFile(const std::string& filePath);
	void UNCompressFile(const std::string& filePath);

private:
	UCH longMatch(USH matchHead,UCH& curMatchDist);
	void WriteFlag(FILE* fOutF,UCH& chFlag,UCH& bitCount,bool IsChar);
	void FileWindow(FILE* fIn);
	void GetLine(FILE* fIn, std::string&strContent);
private:
	USH _start;
	UCH* _pWin;
	HashTable _ht;
};
