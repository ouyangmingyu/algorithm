#include<iostream>
#include<string>

using namespace std;

class CMyString
{
public:
	CMyString(char* pData = nullptr)
	{
		this->m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
	CMyString(const CMyString& str)
	{
		this->m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
	}
	//常规实现
	//CMyString& operator=(const CMyString& str)
	//{
	//	if (this == &str) {
	//		return *this;
	//	}
	//	if (m_pData != nullptr) {
	//		delete[] m_pData;
	//		m_pData = nullptr;
	//	}

	//	m_pData = new char[strlen(str.m_pData) + 1];
	//	strcpy(m_pData, str.m_pData);
	//	return *this;
	//}
	//考虑异常安全性
	CMyString& operator=(const CMyString& str)
	{
		if (this != &str) {
			CMyString strtemp(str);
			char* tempstr = m_pData;
			m_pData = strtemp.m_pData;
			strtemp.m_pData = tempstr;
		}
		return *this;
	}
	~CMyString(void)
	{
		if (m_pData != nullptr) {
			delete[] m_pData;
			m_pData = NULL;
		}
	}


	char* m_pData;
};


int main02()
{
	CMyString str1("mingyu");
	CMyString str2(str1);
	CMyString str3 = str1;
	cout << str1.m_pData << " " << str2.m_pData << " "<<str3.m_pData << endl;
	system("pause");
	return EXIT_SUCCESS;
}