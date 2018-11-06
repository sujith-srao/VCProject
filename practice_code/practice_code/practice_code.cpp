// practice_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;

/*
https://www.hackerearth.com/challenge/competitive/october-circuits-18/algorithm/array-revolve-b9c514cb/
*/
namespace Array_Revolve
{
	class Array_Revolve
	{
		std::vector<int> vec_Array;
	public:
		Array_Revolve(vector<int> &vec)
		{
			vec_Array = vec;
		}

		void Update(int id,int val)
		{
			if (val == 0)
			{
				return;
			}
			vector<int>::iterator itBegin = vec_Array.begin();
			vector<int>::iterator itTemp = itBegin + (id-1);
			*itTemp = *itTemp + val;
			if (id == vec_Array.size())
			{
				Update(1, val - 1);
			}
			else
			{
				Update(id+1, val - 1);
			}
		}

		int Query(int L, int R)
		{
			vector<int>::iterator itBegin = vec_Array.begin();
			if (L == R)
			{
				return *(itBegin + L-1);
			}
			
			if (L == vec_Array.size())
			{
				int ans = *(itBegin + L-1);
				return (ans + Query(1, R));
			}
			else
			{
				int ans = *(itBegin + L-1);
				return ( ans + Query(L+1, R));
			}
		}
	};
}

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
	int N, Q;
	cin >> N >> Q;
	std::vector<int> vec;
	int inp;
	for (int i = 0; i < N; i++)
	{
		cin >> inp;
		vec.push_back(inp);
	}
	Array_Revolve::Array_Revolve ar(vec);
	int qType,var1,var2;
	
	std::vector<int> sol;
	for (int i = 0; i < Q; i++)
	{
		
		cin >> qType>>var1>>var2;
		switch (qType)
		{
		default:
		case 1:
			
			ar.Update(var1, var2);
			break;
		case 2:
			
			int ans = ar.Query(var1, var2);
			sol.push_back(ans);
			break;
		}
	}
	vector<int>::iterator itBegin = sol.begin();
	vector<int>::iterator itEnd = sol.end();
	for (; itBegin != itEnd; ++itBegin)
	{
		cout << *itBegin << endl;
	}
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
