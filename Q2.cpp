#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

int main(void)
{
	string str;

	system("color f0");

	cout << "문자열을 입력하세요: ";
	cin >> str;

	for(size_t i=0; i<str.length(); i++)
	{
		if(str[i]<'A' || str[i] > 'z' || str[i] > 'Z' && str[i] <'a')
			continue;
		str[i]>='a'?str[i]-=('a'-'A'):str[i]+=('a'-'A');
	}
	cout << "바뀐 문자열: " << str;
	return 0;
}