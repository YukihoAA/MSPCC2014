#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main(void)
{
	string str;

	system("color f0");

	cout << "���ڿ��� �Է��ϼ���: ";
	cin >> str;

	for(size_t i=0; i<str.length(); i++)
	{
		if(str[i]<'A' || str[i] > 'z' || str[i] > 'Z' && str[i] <'a')
			continue;
		str[i]>='a'?str[i]-=('a'-'A'):str[i]+=('a'-'A');
	}
	cout << "�ٲ� ���ڿ�: " << str;
	return 0;
}