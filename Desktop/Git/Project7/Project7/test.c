#include<Windows.h>

typedef int DataType;

typedef struct Seq{
	DataType data[100];
	int sz;
}Seq, *pSeq;

void Init()
{
	Seq seq;
	seq.sz = 0;
	for (int i = 0; i < 100; i++){
		seq.data[i] = 0;
	}
}

int main()
{
	Init();
	system("pause");
	return 0;
}