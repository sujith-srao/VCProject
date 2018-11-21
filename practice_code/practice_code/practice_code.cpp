// practice_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<list>
using namespace std;


namespace DesignPatternPractice
{
	namespace Decorator_Practice
	{
		class GUI_Element
		{
		public:
			virtual void draw() = 0;
		};

		class TextBoxDecorator:public GUI_Element
		{
		public:
			virtual void draw() = 0;
		protected:
			TextBoxDecorator* _base;
		};

		class TextBox :public GUI_Element
		{
			GUI_Element *_tbDec;
		public:
			TextBox() :_tbDec(nullptr)
			{

			}

			TextBox(GUI_Element* tb) :_tbDec(tb)
			{
			}

			void draw()
			{
				cout << "Text Box draw" << endl;
				if (_tbDec != nullptr)
				{
					_tbDec->draw();
				}
			}
		};


		class HorizontalScrollBar :public TextBoxDecorator
		{
			//TextBoxDecorator* _base;
		public:
			HorizontalScrollBar()
			{
				_base = nullptr;
			}
			HorizontalScrollBar(TextBoxDecorator* base)
			{
				_base = base;
			}
			void draw()
			{
				cout << "HorizontalScrollBar draw" << endl;
				if (_base != nullptr)
				{
					_base->draw();
				}
			}
		};

		class VerticalScrollBar :public TextBoxDecorator
		{
			
		public:
			VerticalScrollBar()
			{
				_base = nullptr;
			}
			VerticalScrollBar(TextBoxDecorator* base)
			{
				_base = base;
			}
			void draw()
			{
				cout << "VerticalScrollBar draw" << endl;
				if (_base != nullptr)
				{
					_base->draw();
				}
			}
		};

		void driver_func()
		{
			GUI_Element *elem1 = new TextBox(new HorizontalScrollBar(new VerticalScrollBar));
			cout << "Textbox having both vertical and horizontal ScrollBar" << endl;
			elem1->draw();
			cout << "########################" << endl;
			GUI_Element *elem2 = new TextBox(new HorizontalScrollBar);
			cout << "Textbox having horizontal ScrollBar" << endl;
			elem2->draw();
			cout << "########################" << endl;
		}
	}

	namespace Builder_Practice
	{
		class House 
		{
		public:
			void constructWalls()
			{
				cout << "constructing walls" << endl;
			};
			void constructWindows()
			{
				cout << "constructing windows" << endl;
			};
			void constructDoors()
			{
				cout << "constructing doors" << endl;
			};
			void constructInteriors()
			{
				cout << "constructing Interiors" << endl;
			};
		};
		class Builder
		{
		protected:
			House house;
		public:
			virtual void constructWalls() = 0;
			virtual void constructWindows() = 0;
			virtual void constructDoors() = 0;
			virtual void constructInteriors() = 0;
			virtual House& getHouse() = 0;
		};

		class SobhaBuilder :public Builder
		{
			
		public:
			void constructWalls()
			{
				house.constructWalls();
			};
			void constructWindows() 
			{
				house.constructWindows();
			};
			void constructDoors() 
			{
				house.constructDoors();
			};
			void constructInteriors() 
			{
				house.constructInteriors();
			};
			House& getHouse()
			{
				return house;
			}
		};

		class CivilEngineer
		{
			Builder* _builder;
		public:
			void setBuilder(Builder* builder)
			{
				_builder = builder;
			}
			void constructHouse()
			{
				_builder->constructWalls();
				_builder->constructDoors();
				_builder->constructWindows();
				_builder->constructInteriors();
			}
			House& getHouse()
			{
				return _builder->getHouse();
			}
		};

		void driver_func()
		{
			CivilEngineer ce;
			Builder* bdr = new SobhaBuilder;
			ce.setBuilder(bdr);
			cout << "constructing House..." << endl;
			cout << "##############" << endl;
			ce.constructHouse();
			cout << "##############" << endl;
			House house = ce.getHouse();
			cout << "Got finished hosue" << endl;
		}
	}

}
/*
https://www.hackerearth.com/challenge/competitive/october-circuits-18/algorithm/array-revolve-b9c514cb/
*/
namespace Array_Revolve
{
	class Array_Revolve
	{
		unsigned int *vec_Array;
		int N;
		unsigned int *arr;
		
	public:
		Array_Revolve(unsigned int *ar,int n)
		{
			arr = ar;
			vec_Array = new unsigned int[2*n-1];
		}

		void build(int node, int start, int end)
		{
			if (start == end)
			{
				vec_Array[node] = arr[start];
			}
			else
			{
				int mid = (start + end) / 2;
				build(2*node, start, mid);
				build(2*node+1, mid + 1, end);
				vec_Array[node] = vec_Array[2 * node] + vec_Array[2 * node + 1];
			}
		}

		void update(int node, int start, int end, int val, int idx)
		{
			
			if (start == end)
			{
				vec_Array[node] = vec_Array[node] + val;
			}
			int mid = (start + end) / 2;
			if (start <= idx && idx <= mid)
			{
				update(2 * node, start, mid, val, idx);
			}
			else
			{
				update(2 * node+1, mid+1, end, val, idx);
			}
			vec_Array[node] = vec_Array[2 * node] + vec_Array[2 * node + 1];
		}

		unsigned int query(int L,int R)
		{

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
namespace Mannas_First_Name
{
	/*https://www.hackerearth.com/practice/algorithms/searching/linear-search/practice-problems/algorithm/mannas-first-name-4/*/

	void findString(std::string &inputStr,std::string &patternStr,int &nSuvo,int &nSuvojit)
	{
		nSuvo = 0; nSuvojit = 0;
		for (int i = 0; i < inputStr.length();)
		{
			int k = 0;
			int j = i;

			while (k<patternStr.length() && j<inputStr.length() &&  inputStr.at(j) == patternStr.at(k))
			{
				j++;
				k++;
			}
			
			if (k > 0 && k < patternStr.length() && k >= patternStr.length() - 3)
			{
				nSuvo++;
				k--;
			}
			if (k == patternStr.length())
			{
				nSuvojit++;
				k--;
			}
			if (k > 0)
			{
				i = i + k;
			}
			else
			{
				i++;
			}
		}
	}
	struct Count
	{
		int nSuvo;
		int nSuvojit;
	};
	void driverFunc()
	{
		int N;
		cin >> N;
		int i = 0;
		std::string inputStr;
		std::string patStr = "SUVOJIT";
		std::vector<Count> solVec;
		while (i < N)
		{
			int nSuvo = 0, nSuvojit = 0;
			cin >> inputStr;
			Count c;
			findString(inputStr, patStr, c.nSuvo, c.nSuvojit);
			solVec.push_back(c);
			i++;
		}
		std::vector<Count>::iterator itBegin = solVec.begin();
		std::vector<Count>::iterator itEnd = solVec.end();
		for (; itBegin != itEnd; itBegin++)
		{
			cout << "SUVO = " << itBegin->nSuvo<< ", SUVOJIT = " << itBegin->nSuvojit << endl;
		}

	}
}
class sample_class
{
	int a;
	int b;
};

int sample(int a, int b)
{
	int c = 6;
	return (a+b);
}
int main()
{
	Mannas_First_Name::driverFunc();
	return 0;
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
