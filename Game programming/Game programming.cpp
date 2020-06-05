#include <iostream>
using namespace std;
int main() {
	int arr[7] = { 1,4,3,2,5,7,6 };
	int* front = &arr[0];
	int* back = &arr[6];

	for (int i = 0; i < 3; i++) 
	{
		int num = *(front+i);//num에 3번 돌려서 1,4,3 순으로 저장됨 - 이거 나중에 뒤에 역순으로 붙이기
		*(front + i) = *(back - i);//뒷숫자들 마련해놈. 그러니깐 앞 숫자구하기 이제 - 6 7 5 2 5 7 6 됨
		//그리고 num의 처음값은 1 두번째는 4, 세번째는 3
		//6 7 5 2 까지 구했으니		3 4 1 로 만들면 된다.
		*(back - i) = num;
	}


	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}


