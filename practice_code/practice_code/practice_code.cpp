// practice_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

/*
https://www.hackerearth.com/challenge/competitive/october-circuits-18/algorithm/airfares-dbef7f12/
*/

int Total_cost(int P,int S,int T,int H,int x)
{
	int cost = 0;
	if (S - x < T)
	{
		int normal_priced_tkt = S - T;
		cost = H * (x - (S-T)) + P * (x-T);
	}
	else
	{
		cost = P * x;
	}
	return cost;
}

/*https://www.hackerearth.com/challenge/competitive/october-circuits-18/algorithm/entrance-examination-01e4a1b9/
*/
namespace Entrance_Examination
{

	int func(int N,int a,int b)
	{
		std::list<int> possible_marks_list;
		
			/*for (int j = N; j >= 0; j--)
			{
				for (int k = 0; k < j; k++)
				{
					/*cout << "Right ans:" << N - j << endl;
					cout << "Wrong ans:" << j-k<< endl;
					cout << "Unattempted ans:" << k << endl;
					int marks = a * (N - j) - b * (j - k);
					//cout << "marks :: " <<marks<< endl;
					possible_marks_list.push_back(marks);
					cout << endl;
				}				
			}*/
			int r = N,w=0,u=0;
			for (int i = 0; i < ((N + 1)*(N + 2)); i++)
			{
				if ((r + w + u) == N)
				{
					cout << "Right ans:" << r << endl;
					cout << "Wrong ans:" << w << endl;
					cout << "Unattempted ans:" << u << endl;
				}
				r--;
				w++;
				
			}
			
		int temp = N * a;
		possible_marks_list.push_back(temp);
		possible_marks_list.push_back(0);
		possible_marks_list.unique();
		//cout << "unique marks : "<<possible_marks_list.size();
		return possible_marks_list.size();

	}
}
/****
https://www.hackerearth.com/practice/basic-programming/input-output/basics-of-input-output/practice-problems/algorithm/cartag-948c2b02/
***********/
bool isVowel(char ch)
{
	return ((ch == 'A') || (ch == 'E') ||
		(ch == 'I') || (ch == 'O') ||
		(ch == 'U')) || (ch == 'Y');
}
bool aliHelp(string ins)
{
	bool first = (((ins.at(0) - '0') + (ins.at(1) - '0')) %2) == 0;
	bool sec = isVowel(ins.at(2));
	
	bool third = (((ins.at(3) - '0') + (ins.at(4) - '0'))) % 2 == 0;
	bool four = (((ins.at(4) - '0') + (ins.at(5) - '0'))) % 2 == 0;
	
	bool five = (((ins.at(7) - '0') + (ins.at(8) - '0'))) % 2 == 0;
	
	return first && !sec && third && four && five;
}

/*https://www.hackerearth.com/problem/approximate/escape-1-3b459302/*/

int Mojtaba_and_caching_thief(int X, int vA, int vB)
{
	int t = 0;
	int curPosThief = X;
	int curPosPolice = 0;
	int result = 0;
	if (vB > vA )
	{
		if(X >= 0)
			return -1;		
	}

	while (curPosThief > curPosPolice)
	{
		curPosPolice = curPosPolice + vA;
		curPosThief = curPosThief + vB;
		t++;
	}

	if (curPosThief < curPosPolice)
	{
		return -1;
	}

	if (curPosThief == curPosPolice)
	{
		while (curPosPolice != 0)
		{
			curPosPolice = curPosPolice - vA;
			t++;
		}
		return t;
	}
}

string ceaser_cipher(string ins,int k)
{
	string out;
	for (int i = 0; i < ins.length(); i++)
	{
		char ch = ins.at(i);
		if (isalpha(ch))
		{
			if (ch >='A' && ch <= 'Z')
			{
				if (ch + k > 'Z')
				{
					int rem = 'Z' - ch;
					char temp_ch = 'A' + (k - rem-1);
					out.append(1, temp_ch);
				}
				else
				{
					char temp_ch = ch + k;
					out.append(1, temp_ch);
				}
			}
			else if (ch >= 'a' && ch <= 'z')
			{
				if (ch + k > 'z')
				{
					int rem = 'z' - ch;
					char temp_ch = 'a' + (k - rem-1);
					out.append(1, temp_ch);
				}
				else
				{
					char temp_ch = ch + k;
					out.append(1, temp_ch);
				}
			}
		}
		else
		{
			char temp_ch = ch;
			out.append(1, temp_ch);
		}
	}
	return out;

}
int main()
{
	std::vector<int> vec;
	int num;
	int N,a,b;
	cin >> num;
	while (num)
	{
		cin >> N >> a >> b;
		int result = Entrance_Examination::func(N, a, b);
		vec.push_back(result);
		num--;
	}
	std::vector<int>::iterator itEnd = vec.end();
	for (std::vector<int>::iterator itBegin = vec.begin(); itBegin != itEnd; itBegin++)
	{
		cout << *itBegin<<endl;
	}
   /* std::cout << "Hello World!\n"; 
	string ins("middle-Outz");*/
	/*string out = ceaser_cipher(ins, 2);
	cout << out << endl;*/

	//string str("13A315-66");
	/*string str;
	int X, vA, vB;

	cin >> X >> vA >> vB;
	cout<<Mojtaba_and_caching_thief(X, vA, vB);*/
	////while (!str.compare("xx"))
	//{
	//	cin >> str;
	//	if (aliHelp(str))
	//	{
	//		cout << "valid input" << endl;
	//	}
	//	else
	//	{
	//		cout << "invalid input" << endl;
	//	}
	//}
	getchar();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
