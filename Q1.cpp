#include <iostream>
#include <Windows.h>

using namespace std;

int main(void)
{
	int dan=0;

	system("color f0");

	for(;;)
	{
		cout << "출력할 단을 입력해주세요: ";
		cin >> dan;
		
		if(cin.fail() || dan < 1 || dan > 9)
		{
			cout << "1~9 사이의 숫자로 다시 입력해주세요------------" << endl;
			cin.clear();
			cin.ignore(INT_MAX,'\n');
		}
		else
			break;
	}
	for(int i=1; i < 10 ; i++)
	{
		for(int j=1 ; j <= i*dan ; j++)
			cout << "*";
		cout << endl;
	}

	return 0;
}