#include <iostream>
#include <Windows.h>

using namespace std;

int main(void)
{
	int dan=0;

	system("color f0");

	for(;;)
	{
		cout << "����� ���� �Է����ּ���: ";
		cin >> dan;
		
		if(cin.fail() || dan < 1 || dan > 9)
		{
			cout << "1~9 ������ ���ڷ� �ٽ� �Է����ּ���------------" << endl;
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