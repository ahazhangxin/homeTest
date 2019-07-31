#include"FileCompressHuff.h"

int main()
{
	FileCompressHuffM fc;
	fc.CompressFile("123.txt");

	fc.UNCompressFile("123.hzp");
	return 0;
}

/*
#include"LZ77.h"

int main()
{
	LZ77 lz;
	lz.CompressFile("1.txt");
	//lz.UNCompressFile("1.lzp");
	return 0;
}*/