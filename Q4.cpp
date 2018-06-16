#include <iostream>

using namespace std;

int compare(const void *num1, const void *num2)
{
	if(*(int*)num1 == *(int*)num2)
		return 0;
	else if(*(int*)num1 > *(int*)num2)
		return 1;
	else
		return -1;
}

int main(void)
{
	int arr[5];
	cout << "¼ö ÀÔ·Â" << endl;
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
	qsort(arr,sizeof(arr)/sizeof(arr[0]),sizeof(arr[0]),compare);
	cout << "ÃÖ´ñ°ª :" << arr[4] << endl;
	cout << "ÃÖ¼Ú°ª :" << arr[0] << endl;

	system("pause");
	return 0;
}