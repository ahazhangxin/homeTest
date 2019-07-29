#include<iostream>
using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr);
	CMyString(const CMyString &str);
	~CMyString(void);


	CMyString& operator=(const CMyString &str)
	{
		if (this != &str)
		{
			CMyString strTemp(str);

			char* Temp = strTemp.m_pData;
			strTemp.m_pData = m_pData;
			m_pData = Temp;
		}
		return *this;
	}

	/*
	CMyString& operator=(const CMyString &str)
	{
		if (this == &str)
		{
			return *this;
		}

		delete[] m_pData;
		m_pData = nullptr;

		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
		
		return *this;
	}
	*/
	
private:
	char* m_pData;
};

