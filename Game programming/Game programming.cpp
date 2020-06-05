﻿/*
#include<iostream>
#include<stdlib.h>

using namespace std;

void StartText();//오목이 시작되었다는 말을 출력하기 위한 함수
void OmokBoard();//오목판 출력하는 함수
void BlackOrder();
void WhiteOrder();
void DrawOrder(int, int);

int main()
{
	int i = 1;
	int cnt = 0;
	while (1)
	{
		while (cnt == 0)//처음에 화면 딱 한번 출력해주기 위한 반복문
		{
			StartText();
			OmokBoard();
			cnt++;
		}

		if (i % 2 != 0)//그 뒤로는 반복해서 99 99입력 전까지 계속 진행 됨.

			BlackOrder();

		else
			WhiteOrder();
		i++;
	};
	return 0;
}

void DrawOrder(int col, int row) {// 판과 돌을 같이 그려줌.(사실상 돌만 그리는 것이 아니라 해당 좌표에 놓인 돌의 위치가 표시된 보드를 그리는 것임)
	StartText();

	static int cnt = 1;//흑돌먼저 시작하고 그다음 백돌, 또 반복... 메인 함수의 흑백순서와 동일 시켜주기 위한것 ||||메인-백일때 오더-백/메인-흑일때 오더-흑
	static int Board[19][37] = {
	{0,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,2},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{6,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,8} };

	if (cnt % 2 != 0)//해당 좌표(배열)에 돌 입력
		Board[row - 1][2 * col - 2] = 9;//돌을 놓아야 하는 부분은 짝수 간격
	else if (cnt % 2 == 0)
		Board[row - 1][2 * col - 2] = 10;

	cnt++;//플레이어의 턴 전환 담당하는 변수

	//바둑판 그리는데 요구사항대로 수정되어 나옴.(1 12 입력시 Board[0][22]에 돌에 해당하는 수가 입력됨)
	int colNum[19] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };//세로 줄 번호
	cout << "  ";
	for (int i = 0; i < 19; i++)//세로 줄 번호 출력
	{
		if (colNum[i] < 10)
			cout << ' ' << colNum[i];
		else if (colNum[i] >= 10)
			cout << colNum[i];
	}
	cout << endl;

	for (int i = 0; i < 19; i++)//가로 줄 번호 출력
	{
		if (i < 9)
			cout << ' ' << i + 1;
		else
			cout << i + 1;

		for (int j = 0; j < 37; j++)//오목 배열내에 있는 번호 해당 기호 출력
		{
			if (Board[i][j] == 9)//흑돌이 올때
			{
				if (j == 0)
					cout << "○";
				else
					cout << "-○";

			}

			else if (Board[i][j] == 10)//백돌이 올떄
			{
				if (j == 0)
					cout << "●";
				else
					cout << "-●";
			}



			//각 상황에 맞춰 사용하기 위한 격자기호와 격자기호,빼기기호의 혼합
			else if (Board[i][j] == 0)
				cout << "┌";
			else if (Board[i][j] == 1)
				cout << "┬";
			else if (Board[i][j] == 2)
				cout << "┐";
			else if (Board[i][j] == 3)
				cout << "├";
			else if (Board[i][j] == 4)
				cout << "┼";
			else if (Board[i][j] == 5)
				cout << "┤";
			else if (Board[i][j] == 6)
				cout << "└";
			else if (Board[i][j] == 7)
				cout << "┴";
			else if (Board[i][j] == 8)
				cout << "┘";
			else if (Board[i][j] == 99)//격자 무늬 사이의 간격을 맞춰주는 - 기호
			{
				if (Board[i][j - 1] == 9 || Board[i][j - 1] == 10 || Board[i][j + 1] == 9 || Board[i][j + 1] == 10)//전열 후열에 돌이 없다면 아무 것도 출력하지 않음
					continue;
				else
					cout << "-";
			}


		}
		cout << endl;
	}


	cout << endl;

}

void BlackOrder()
{
	int col, row;
	cout << "○'s X,Y:";//흑돌
	cin >> col >> row;
	if (col == 99 && row == 99)//99 99 입력하면 종료
		exit(0);
	system("cls");
	DrawOrder(col, row);

}

void WhiteOrder()
{
	int col, row;
	cout << "●'s X,Y:";//흑돌
	cin >> col >> row;
	if (col == 99 && row == 99)
		exit(0);
	system("cls");
	DrawOrder(col, row);

}

void StartText()		//오목이 시작되었다는 말을 출력하기 위한 함수
{
	for (int i = 0; i < 19 / 2 - 4; i++)
		cout << ' ';

	cout << "====== Let's Play Omok ======\n";
}

void OmokBoard() {//일회성 함수
	int colNum[19] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19 };//세로 줄 번호
	cout << "  ";
	for (int i = 0; i < 19; i++)//세로 줄 번호 출력
	{
		if (colNum[i] < 10)
			cout << ' ' << colNum[i];
		else if (colNum[i] >= 10)
			cout << colNum[i];
	}
	cout << endl;
	//오목 판 배열
	int Board[19][37] = {
	{0,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,1,99,2},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{3,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,4,99,5},
	{6,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,7,99,8} };

	for (int i = 0; i < 19; i++)//가로 줄 번호 출력
	{
		if (i < 9)
			cout << ' ' << i + 1;
		else
			cout << i + 1;

		for (int j = 0; j < 37; j++)//오목 배열내에 있는 번호 해당 기호 출력
		{
			if (Board[i][j] == 0)
				cout << "┌";
			else if (Board[i][j] == 1)
				cout << "┬";
			else if (Board[i][j] == 2)
				cout << "┐";
			else if (Board[i][j] == 3)
				cout << "├";
			else if (Board[i][j] == 4)
				cout << "┼";
			else if (Board[i][j] == 5)
				cout << "┤";
			else if (Board[i][j] == 6)
				cout << "└";
			else if (Board[i][j] == 7)
				cout << "┴";
			else if (Board[i][j] == 8)
				cout << "┘";
			else if (Board[i][j] == 99)
				cout << "-";
		}
		cout << endl;
	}
	cout << endl;
}
*/
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


