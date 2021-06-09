//
// Created by Nhan Nguyen on 01/03/2021.
//
#ifndef MONGOL_H
#define MONGOL_H

// The library here is concretely set, students are not allowed to include any other libraries.

string readyForBattle(const string ID[], const int NID, const string input1[], const int N1);
int decode(const string A, const string B);
string findRoute(const string ID[], const int NID, const string input3[]);
string decodeVfunction(const string A, const string B);
string findBetrayals(const string input5[], const int N5);
int attack(const string input6[]);
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix, const int N7);

////////////////////////////////////////////////////////////////////////////
/// STUDENT'S ANSWER HERE
////////////////////////////////////////////////////////////////////////////
#define MAX 1000
#define ARRAY_MAX 100

// check chỉ huy của trận chiến 
// 1 là vua tran , 2 là trần hưng đạo còn 0 là không có ai
int checkChiHuy(const int NID, const string ID[])
{
	for (int i = 0; i < NID; i++)
	{
		if ((ID[i][0] == 'V') && (ID[i][1] == 'U') && (ID[i][2] == 'A'))
			return 1;
		for (int j = 0; j < ID[i].size(); j++)
			if ((ID[i][j] == 'T') && (ID[i][j + 1] == 'H') && (ID[i][j + 2] == 'D') && (j != 0))
				return 2;
	}
	return 0;
}






// chưa check
string readyForBattle(const string ID[], const int NID, const string input1[], const int N1)
{
	return "chua lam xong";
}
// đã check
int decode(const string A, const string B)
{
    int key = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (B == A.substr(i, B.size())) key++;
    }
    return key;
}

// chưa check
string findRoute(const string input3)
{
	string inp = input3;
	string S;
	int N = 0, B = 0;
	int temp = 0;
	while (inp[temp] != ' ')
	{
		N = N * 10 + ((int)(inp[temp]) - 48);
		temp++;
	}
	temp++;
	while (inp[temp] != ' ')
	{
		B = B * 10 + ((int)(inp[temp]) - 48);
		temp++;
	}
	S = inp.substr(temp + 1);
	
	int s = S.size();
	if(B>0)
		for (int i = 0; i < B; i++)
		{
			char thay = S[s - 1];
			for (int j = 0; j <= s; j++)
			{
				char c = S[j];
				S[j] = thay;
				thay = c;
			}
		}
	if(B<0)
		for (int i = 0; i < abs(B); i++)
		{
			char thay = S[0];
			for (int j = s - 1; j >= 0; j--)
			{
				char c = S[j];
				S[j] = thay;
				thay = c;
			}
		}
	for (int i = 0; i < s; i++)
	{
		int number = 0;
		switch (S[i])
		{
		case 'U' :
			number = 0;
			break;
		case 'D':
			number = 1;
			break;
		case 'L':
			number = 2;
			break;
		case 'R':
			number = 3;
			break;
		}
		number += abs(N - 2 * i);
		number %= 4;
		switch (number)
		{
		case 0:
			S[i] = 'U';
			break;
		case 1:
			S[i] = 'D';
			break;
		case 2:
			S[i] = 'L';
			break;
		case 3:
			S[i] = 'R';
			break;
		}
	}
	int x = 0, y = 0;
	for (char c : S)
	{
		if (c == 'U') x++;
		if (c == 'D') x--;
		if (c == 'L') y--;
		if (c == 'R') y--;
	}
	string str;
	str = "(" + to_string(x) + "," + to_string(y) + ")";
	return str;
}

// tìm số ký tự lặp lại trong chuỗi
int demLap(string str, char c)
{
	int temp = 0;
	for (char ch : str)
	{
		if (ch == c) temp++;
	}
	return temp;
}
// đã check
string decodeVfunction(const string A, const string B)
{
	if (A.size() == 1) return "0";
	if (B.size() == 1) return "0";
	int tempA = 0, tempB = 0;
	tempA = demLap(A, 'V');
	tempB = demLap(B, 'V');
	string str;
	for (int i = 0; i < tempA * tempB; i++)
		str += "V(";
	str += "0";
	for (int i = 0; i < tempA * tempB; i++)
		str += ")";
	return str;
}
// đã check
string findBetrayals(const string input5[], const int N5)
{
	string str;
	int  arr[26] = { 0 };
	for (int i = 0; i < N5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			arr[(int)input5[i][j] - 65]+=(6-j);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		int max = arr[0];
		for (int j = 0; j < 26; j++)
		{
			if (max < arr[j]) max = arr[j];
		}
		for (int j = 0; j < 26; j++)
		{
			if (arr[j] == max)
			{
				str += (char)(j + 65);
				arr[j] = 0;
				break;
			}
		}
	}
	return str;
}
// đã check
int attack(const string input6[])
{
	int arr[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (input6[i][j] == '2')
			{
				arr[i] = -1;
				break;
			}
			if (input6[i][j] == '0')
				arr[i]++;
		}
	}
	int max = arr[0];
	for (int i = 1; i < 10; i++)
	{
		if (max <= arr[i]) max = arr[i];
	}
	int temp = -1;
	if (max == -1) return -1;
	for (int i = 0; i < 10; i++)
	{
		if (max == arr[i]) temp = i;
	}
	return temp;
}

//chưa check
int calculateNoOfWaitingDays(const string input7Str, const string input7Matrix[], const int N7)
{
	return -1;
}

#endif /* MONGOL_H */
