// practice_code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<vector>
#include<list>
#include<unordered_map>
#include<functional>
#include<locale>
#include<map>
#include<set>
#include<queue>
#include<algorithm>
#include<mutex>
#include<optional>
#include <functional>
#include<stack>
#include<any>
#include<future>
#include<thread>
#include<variant>
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

namespace CompositeDP
{
    class Employee
    {
    protected:
        string m_name;
    public:
        Employee(string &name)
        {
            m_name = name;
            cout << m_name<<__FUNCTIONW__ << endl;
        };
        Employee(const Employee &rhs)
        {
            m_name = rhs.m_name;
            cout << m_name << __FUNCTIONW__ << endl;
        };
        virtual void getSalary()
        {
            cout << __FUNCTIONW__ << endl;
        };
    };
    
    class SoftwareEngineer:public Employee
    {
    public:
        SoftwareEngineer(string &name):Employee(name)
        {
            cout << m_name << __FUNCTIONW__ << endl;
        };

        /*SoftwareEngineer(const SoftwareEngineer &rhs):Employee(rhs.m_name)
        {
            
            cout << m_name << __FUNCTIONW__ << endl;
        };*/
        virtual void getSalary()
        {
            cout << __FUNCTIONW__ << endl;
        };
    };

    class Manager : public Employee
    {
        vector<Employee*> reportees;
    public:
        void addReportees(Employee *emp)
        {
            reportees.push_back(emp);
        }
    };
};

namespace ZigZagString
{
    void func(string sInput,int k)
    {
        std::list<std::string> outString;
        outString.push_back("");
        outString.push_back("");
        outString.push_back("");
        for (int i = 0; i < sInput.length(); i++)
        {
            if (i%k==0)
            {
                std::list<std::string>::iterator itBegin = outString.begin();
                std::list<std::string>::iterator itEnd = outString.end();
                int j = 0;
                for (; j<k && itBegin != itEnd; itBegin++)
                {
                    string s = (*itBegin);
                    char ch = sInput[i + j];
                    
                    j++;
                }
            }
        }
        int arr[] = { 4,5 };
        const int arrlen = sizeof(arr) / sizeof(int);
        cout << arrlen;
        const int al = 5;
        int arr2[arrlen];
        
    }
}

namespace SearchString
{
    class Solution
    {
    public:
        int strStr(string haystack, string needle)
        {
            int iLenHS = haystack.length();
            int iLenNeedle = needle.length();

            for (int i = 0; i < iLenHS; i++)
            {
                int k = 0;
                for (int j = 0; j < iLenNeedle; j++)
                {
                    //if(haystack.at(i) == )
                }
            }
        }
    };
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
//int a[2] = { 0,0 };
//int *ptr1;
//int *ptr2;
//int *ptr[2] = { ptr1,ptr2 };
void simply2(int *arr)
{
    for (int i = 0; i < 4; i++)
    {
        arr[i] = arr[i] * 5;
    }
}
struct MyStruct
{
    char *pCh;
    int *pI;
};

void simply()
{
    MyStruct **lol = (MyStruct**)malloc(sizeof(MyStruct*) * 2);
    lol[0] = (MyStruct*)malloc(sizeof(MyStruct) * 5);
    lol[1] = (MyStruct*)malloc(sizeof(MyStruct) * 5);
    lol[1]->pI = (int*)malloc(sizeof(int) * 5);
    lol[1]->pI[0] = 5;
    lol[1]->pI[1] = 15;
    lol[1]->pI[2] = 25;


    int a = 10;
    char b = a;
    int **ptr;
    ptr = (int**)malloc(2 * sizeof(int*));
    ptr[0] = (int*)malloc(sizeof(int) * 4);
    ptr[1] = (int*)malloc(sizeof(int) * 4);
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            ptr[i][j] = (i+1)*(j + 1);
        }
    }
    cout << "Base ptr=" << ptr << endl;
    cout << "ptr[0]=" << ptr[0] << endl;
    cout << "ptr[1]=" << ptr[1] << endl;
    cout << "&ptr[0]=" << &ptr[0] << endl;
    cout << "&ptr[1]=" << &ptr[1] << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << ptr[i][j] << "\t";
        }
        cout << endl;
    }
    int *p = *(&ptr[1]) + 2;
    cout << "Derferencing logic=" << *p << endl;
    simply2(ptr[0]);
    p = *(&ptr[0]) + 1;
    int *p1 = (int*)&ptr[1][3];
    cout << "After simply2 logic=" << *p1 << endl;

}
//void stringRotation(const char* inp, int n, int d, char* outp)
//{
//    char* temp = inp;
//
//}
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
namespace Min_Max_Prob
{
	void Min_Max_Prob(unsigned int arr[], int n, unsigned int &min, unsigned int &max)
	{
		unsigned int final_sum = 0;
		for (int i = 0; i < n; i++)
		{
			final_sum = final_sum + arr[i];
		}
		max = final_sum - arr[0];
		min = final_sum - arr[0];
		for (int i = 1; i < n; i++)
		{
			unsigned int temp = final_sum - arr[i];
			if (temp > max)
			{
				max = temp;
			}
			if (temp < min)
			{
				min = temp;
			}
		}
	}
	void driver_func()
	{
		int n;
		cin >> n;
		unsigned int *arr = new unsigned int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		unsigned int max = 0;
		unsigned int min = 0;
		Min_Max_Prob(arr, n, max, min);
		cout << max << " " << min;

	}
}
namespace Motu_Patlu_Icecream
{
	/*https://www.hackerearth.com/practice/algorithms/greedy/basics-of-greedy-algorithms/practice-problems/algorithm/motu-and-patlu-1-ab612ad8/*/

	void Motu_Patlu_Icecream_Prob(unsigned int arr[], int n, int &motu, int &patlu)
	{
		motu = 0;
		patlu = 0;
		unsigned int *arr_dup = new unsigned int[n];
		for (int i= 0; i < n; i++)
		{
			arr_dup[i] = arr[i];
		}
		
		int iMotu = 0;
		int iPatlu = n-1;
		
		while (iMotu < iPatlu)
		{
			if (arr[iMotu] <= 0)
			{
				motu++;
				iMotu++;
			}
			else
			{
				arr[iMotu] = arr[iMotu] - 2;
			}
			if (arr[iPatlu] == 0)
			{
				patlu++;
				iPatlu--;
			}
			else
			{
				arr[iPatlu] = arr[iPatlu] - 1;
			}


			if (iPatlu == iMotu - 1)
			{
				if (arr[iPatlu] < arr_dup[iPatlu])
				{
					patlu++;
					break;
				}
			}
		}
		//if (iMotu == iPatlu )
		//{
		//	if (/*arr[iPatlu] == 0 ||*/ arr[iPatlu] < arr_dup[iPatlu])
		//	{
		//		patlu++;
		//	}
		//	else 
		//	{
		//		motu++;
		//	}
		//}
		
	}
	struct Count
	{
		int motu;
		int patlu;
	};
	void driver_fun()
	{
		int t = 0;
		cin >> t;
		Count *solVec = new Count[t];
		for (int j = 0; j < t; j++)
		{
			int n = 0;
			cin >> n;
			unsigned int *arr = new unsigned int[n];
			for (int i = 0; i < n; i++)
			{
				cin >> arr[i];
			}
			Motu_Patlu_Icecream_Prob(arr, n, solVec[j].motu, solVec[j].patlu);
		}
		for (int i = 0; i < t; i++)
		{
			cout << solVec[i].motu << " " << solVec[i].patlu << endl;
			if (solVec[i].motu > solVec[i].patlu)
			{
				cout << "Motu" << endl;
			}
			else if (solVec[i].motu < solVec[i].patlu)
			{
				cout << "Patlu" << endl;
			}
			else
			{
				cout << "Tie" << endl;
			}
		}
	}
}
#include<array>

namespace LilMonkABD
{
    void func()
    {
        int N = 0;
        cin >> N;
        std::vector<int> scoreVec;
        for (int i = 0; i < N; i++)
        {
            int temp;
            cin >> temp;
            scoreVec.push_back(temp);
        }
        sort(scoreVec.begin(), scoreVec.end());
        unique(scoreVec.begin(), scoreVec.end());
        int numQuery = 0;
        cin >> numQuery;
        vector<int> ans;
        for (int i = 0; i < numQuery; i++)
        {
            int k;
            cin >> k;
            char ch;
            cin >> ch;
            if (ch == 'S')
            {
                ans.push_back(scoreVec.at(k - 1));
            }
            else if (ch == 'L')
            {
                ans.push_back(scoreVec.at(scoreVec.size()-k+1));
            }
        }
        for (auto i : ans)
        {
            cout << i << endl;
        }
    }
}
namespace Sam
{
    void findUniqueChar(vector<string> inp, set<char> out)
    {
        for (auto i : inp)
        {
            unique(inp.begin(), inp.end());
            for (int j = 0; j < i.size(); j++)
            {
                out.insert(i.at(j));
            }
            
        }
    }
    void func()
    {
        vector<string> inp;
        for (auto i : {"aabb","aaaa","bbab"})
            inp.push_back(i);
        
    }
}
namespace Dream_Team
{
    //https://app.codility.com/programmers/task/dream_team/
    bool isasolution(int k,int sz)
    {
        if (k == sz) return true;
        return false;
    }
    int maxRes = 0;
    void processSolution(vector<int> ans)
    {
        int res = 0;
        for (auto i : ans)
        {
            res = res + i;
        }
        if (res > maxRes)
            maxRes = res;
    }

    void findCandidates(vector<int> A, vector<int> B, int F,int k, vector<int> canVec)
    {

    }

    void backTrack(vector<int> ans, int k, vector<int> A, vector<int> B, int F)
    {
        if (isasolution(k,A.size()))
        {
            processSolution(ans);
        }
        else
        {
            vector<int> canVec;
            findCandidates(A, B, F,k, canVec);

        }
    }
}
namespace StudentFreq
{
    void readInput()
    {
        
        int n = 0;
        cin >> n;
        std::unordered_map<std::string, int> nameList;
        auto nameLBegin = nameList.begin();
        auto nameLEnd = nameList.end();
        for (int i = 0; i < n; i++)
        {
            std::string str;
            cin >> str;
            if (nameList.empty())
            {
                nameList[str] = 1;
                continue;
            }
            auto searchResult = nameList.find(str);
            if (nameLEnd != searchResult && searchResult->second)
            {
                searchResult->second += 1;
            }
            else
            {
                nameList[str] = 1;
            }
        }
        vector<string> vecNameList;
        vector<int> vecFreq;

        nameLBegin = nameList.begin();
        nameLEnd = nameList.end();
        
        for (; nameLBegin != nameLEnd; ++nameLBegin)
        {
            //cout << nameLBegin->first << " " << nameLBegin->second << endl;
            vecNameList.push_back(nameLBegin->first);
        }
        std::sort(vecNameList.begin(), vecNameList.end());
        auto vecItBegin = vecNameList.begin();
        auto vecItEnd = vecNameList.end();
        for (; vecItBegin != vecItEnd; ++vecItBegin)
        {
            cout << *vecItBegin << " " << nameList.find(*vecItBegin)->second<<endl;
        }
    }
}

namespace ElectricType
{
    struct MyPair
    {
        int first;
        int second;
        bool operator==(struct MyPair& rhs)
        {
            return (first == rhs.first && second == rhs.second);
        }
    };

    //https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/the-electric-type/
    void readInput()
    {
        int n;
        cin >> n;
        long *a = new long[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        std::unordered_map<string, int> ht;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                MyPair mp;
                string str = std::to_string(a[i]) + std::to_string(a[j]);
                ht[str] = 1;
            }
        }
        cout << ht.size();
    }
}

namespace BeerString1
{
//https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/string-cake1/

    void func()
    {
        std::string favString;
        cin >> favString;
        std::set<char> favStringSet;
        for (int i = 0; i < favString.length(); i++)
        {
            favStringSet.insert(favString.at(i));
        }
        int t = 0;
        cin >> t;
        std::string inpString;
        int count = 0;
        for (int i = 0; i < t; i++)
        {
            bool possible = true;
            cin >> inpString;
            for (int j = 0; j < inpString.length(); j++)
            {
                auto res = favStringSet.find(inpString.at(j));
                if (res == favStringSet.end())
                {
                    possible = false;
                    break;
                }
            }
            if (possible)
                count++;
            
        }
        cout << count;
    }

}

namespace VowelPhobia
{
    //https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/vowels/
    
    char to_lowercase(char ch)
    {
        if (ch >= 'A' && ch <= 'Z')
            return ch + 32;
        return ch;
    }
    bool isVowel(char ch)
    {
        char vowelArr[] = { 'a','e','i','o','u' };
        for (int i = 0; i < 5; i++)
        {
            if (ch == vowelArr[i])
                return true;
        }
        return false;
    }
    int countVowel(string str)
    {
        int vowelCount = 0;
        //transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        
        for (int i = 0; i < str.length(); i++)
        {
            
            if (isVowel(str.at(i)))
            {
                vowelCount++;
            }
        }
        return vowelCount;
    }

    void func()
    {
        int t = 0;
        cin >> t;
        std::vector<int> ans;
        std::string str;
        for (int i = 0; i < t; i++)
        {
            cin >> str;
            int vowelCount = countVowel(str);
            ans.push_back(vowelCount);
        }
        for (auto i : ans)
        {
            cout << i << endl;
        }

    }
}

namespace Bag_Numbers
{
    //https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/picu-bank-09e29493/
    void readInput()
    {
        std::vector<int> ans;
        int t;
        cin >> t;
        while (t)
        {
            t--;
            int D, A, M, B, X;
            cin >> D >> A >> M >> B >> X;
            int curAmt = D;
            int counterM = 0;
            int numMonth = 0;
            
            while (curAmt <= X)
            {
                int act = X - D;
                int Y = (X - D) / (A*M + B);
                if (Y)
                {
                    numMonth = Y * (M + 1);
                    int rem = act % ((A*M + B));
                    curAmt = rem;
                }
                else
                {

                }
            }
            ans.push_back(numMonth);
        }
        std::vector<int>::iterator itBegin = ans.begin();
        std::vector<int>::iterator itEnd = ans.end();
        for (;itBegin != itEnd;++itBegin)
        {
            cout << *itBegin << endl;
        }

    }
    
}

namespace PlayfulStrings
{
    bool isPlayful(string inputStr)
    {
        bool res = true;
        for (int i = 0; i < inputStr.length()-1; i++)
        {
            if (inputStr.at(i) == 'a')
            {
                if (inputStr.at(i + 1) == 'z' || inputStr.at(i + 1) == 'b')
                {
                }
                else
                {
                    res = false;
                }
            }
            else if (inputStr.at(i) == 'z')
            {
                if (inputStr.at(i + 1) == 'a' || inputStr.at(i + 1) == 'y')
                {
                }
                else
                {
                    res = false;
                    break;
                }
            }
            else 
            {
                if ((inputStr.at(i) - inputStr.at(i + 1) == 1) ||
                    (inputStr.at(i) - inputStr.at(i + 1) == -1))
                {
                }
                else
                {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
    void func()
    {
        int t = 0;
        cin >> t;
        string inputStr;
        vector<int> ans;
        for (int i = 0; i < t; i++)
        {
            cin >> inputStr;
            if (isPlayful(inputStr))
            {
                ans.push_back(1);
            }
            else
            {
                ans.push_back(0);
            }
        }
        for (auto i : ans)
        {
            if (i == 1)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;;
        }
    }
}
namespace Ave_Substrings
{
/*
https://www.hackerearth.com/practice/algorithms/string-algorithm/string-searching/practice-problems/algorithm/ave-and-substrings/description/
*/

    void func()
    {
        int t = 0;
        cin >> t;
        std::vector<int> ans;
        std::string inputStr;
        for (int i = 0; i < t; i++)
        {
            cin >> inputStr;

        }
    }
}
namespace PairSums
{
    //https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/pair-sums/
    void readInput()
    {
        std::unordered_map<int,int> hash_table;
        
        int n = 0;
        int k = 0;

        cin >> n >> k;
        int *a = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            hash_table[a[j]] = 1;
        }
        auto itBegin = hash_table.begin();
        auto itEnd = hash_table.end();
        for (int i = 0; i < n; i++)
        {
            std::unordered_map<int, int>::iterator search = hash_table.find(k - a[i]);
            if (itEnd != search)
            {
                if (search->second == 1)
                {
                    cout << "YES";
                    return;
                }
            }
        }
        cout << "NO";
         
    }
}

namespace StlBe
{
    /*template<class T> 
    struct iterator_traits<T*> {
        typedef ptrdiff_t difference_type;
        typedef T* pointer;
        typedef T& reference;
    };

    template<class T> typename iterator_traits<T>::difference_type distance(T first, T second)
    {
    }*/
}


namespace MicroArrayUpdate
{
    int calculateTime(int *a, int n, int k)
    {
        int min = a[0];
        for (int i = 1; i < n; i++)
        {
            if (a[i] < min)
            {
                min = a[i];
            }
        }
        if (k - min > 0)
            return(k - min);
        else
            return 0;
    }

    //https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/ 
    void readInput()
    {
        int T = 0;
        cin >> T;
        vector<int> solVec;
        for (int i = 0; i < T; i++)
        {
            int n = 0;
            int k = 0;
            
            cin >> n >> k;
            int *a = new int[n];
            for (int j=0; j<n; j++)
            {
                cin >> a[j];
            }
            int ans = calculateTime(a,n,k);
            solVec.push_back(ans);
        }
        vector<int>::iterator itBegin = solVec.begin();
        vector<int>::iterator itEnd = solVec.end();
        for (; itBegin != itEnd; itBegin++)
        {
            cout << *itBegin<<endl;
        }
    }
}

namespace Monk_BoxOfCookies
{
//https://www.hackerearth.com/practice/basic-programming/bit-manipulation/basics-of-bit-manipulation/practice-problems/algorithm/monk-and-the-box-of-cookies/

    int calc(vector<int> &inp)
    {
        int table[32];
        for (int i = 0; i < 32; i++)
        {
            table[i] = 0;
        }
        for (auto i : inp)
        {
            for (int j = 0; j < 32; j++)
            {
                if (i & 1 << j)
                {
                    table[j]++;
                }
            }
        }
        int max = table[0];
        int indx = 0;
        for (int i = 1; i < 32; i++)
        {
            if (table[i] > max)
            {
                indx = i;
                max = table[i];
            }
        }
        return indx;
    }
    void func()
    {
        int t = 0;
        cin >> t;
        vector<int> ans;
        for (int i = 0; i < t; i++)
        {
            int n = 0;
            cin >> n;
            vector<int> inp;
            
            for (int j = 0; j < n;j++)
            {
                int temp = 0;
                cin >> temp;
                inp.push_back(temp);
            }
            int res = calc(inp);
            ans.push_back(res);
        }
        for (auto i : ans)
        {
            cout << i << endl;
        }
    }
}

namespace RegistrationSystem
{
    struct Trie
    {
        bool isLeaf;
        unordered_map<char, Trie*> map;
    };
    Trie* getNewNode()
    {
        Trie* node = new Trie;
        node->isLeaf = false;
        return node;
    }
    void insert(string str, Trie *&head)
    {
        if (head == nullptr)
        {
            head = getNewNode();
            head->isLeaf = false;
        }
        Trie* curr = head;
        for (int i = 0; i < str.length(); i++)
        {
            if (curr->map.find(str.at(i)) == curr->map.end())
                curr->map[str.at(i)] = getNewNode();
            curr = curr->map[str.at(i)];
        }
        curr->isLeaf = true;
    }
}

namespace PriorityQueue
{
    void max_heapify(int Arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left <n && Arr[left] > Arr[largest])
        {
            largest = left;
        }
        if(right <n && Arr[right]>Arr[largest])
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(Arr[i], Arr[largest]);
            max_heapify(Arr, n, largest);
        }
    }

    void BuildMaxHeap()
    {
        /*int arr[10];
        int N;
        for (int i = N / 2; i >= 1; i--)
        {
            max_heapify(arr, N, i);
        }*/
    }
}
namespace SegTree
{
}

namespace StringQ1
{
    /*
    https://www.hackerearth.com/practice/algorithms/string-algorithm/basics-of-string-manipulation/practice-problems/algorithm/string-queries-1/
    */
    
    int doOperate(string str)
    {
        string tempStr = str;
        string::iterator uniqStr= std::unique(tempStr.begin(), tempStr.end());
        tempStr.resize(std::distance(tempStr.begin(), uniqStr));
        for (int i = 0; i < tempStr.length(); i++)
        {
        }
        return 0;
    }

    void func()
    {
        int len = 0;
        int q = 0;
        cin >> len >> q;
        string str;
        cin >> str;
        vector<int> ans;
        for (int i = 0; i < q; i++)
        {
            int l, r;
            cin >> l >> r;
            string actStr = str.substr(l - 1, l - r);
            int temp = doOperate(actStr);
            ans.push_back(temp);
        }
    }
}

namespace LMW
{
    /*
    https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/little-monk-and-williamson/
    */

    void func()
    {
        int q;
        cin >> q;
        std::list<int> arr;
        std::priority_queue<int, vector<int>, less<int>> decArray;
        std::priority_queue<int, vector<int>, greater<int>> incArray;
        std::vector<int> ans;
        
        for (int i = 0; i < q; i++)
        {
            string str;
            cin >> str;
            if (str.compare("CountHigh") == 0)
            {
                if(arr.empty())
                    ans.push_back(-1);
                else
                {
                    int cur = decArray.top();
                    int count = std::count(arr.begin(), arr.end(), cur);
                    ans.push_back(count);
                }
            }
            else if (str.compare("Push") == 0)
            {
                int n;
                cin >> n;
                arr.push_back(n);
                decArray.push(n);
                incArray.push(n);
            }
            else if (str.compare("CountLow") == 0)
            {
                if (arr.empty())
                    ans.push_back(-1);
                else
                {
                    int cur = incArray.top();
                    int count = std::count(arr.begin(), arr.end(), cur);
                    ans.push_back(count);
                }
            }
            else if (str.compare("Diff") == 0)
            {
                if (arr.empty())
                {
                    ans.push_back(-1);
                }
                else if (arr.size() == 1)
                {
                    ans.push_back(0);
                    arr.pop_front();
                    decArray.pop();
                    decArray.pop();
                }
                else
                {
                    int diff = decArray.top() - incArray.top();
                    if (decArray.top() == incArray.top())
                    {
                        arr.remove(incArray.top());
                    }
                    else
                    {
                        arr.remove(decArray.top());
                        arr.remove(incArray.top());
                    }
                    decArray.pop();
                    incArray.pop();
                    ans.push_back(diff);
                }
            }
        }
        for (auto i : ans)
            cout << i << endl;
    }
}

namespace HostelVisit
{
    /*https://www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/hostel-visit/   */

    void min_heapify(vector<int> &pq, int i)
    {
        int min = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left<pq.size() && pq.at(min)>pq.at(left))
            min = left;
        if (right<pq.size() && pq.at(min)>pq.at(right))
            min = right;
        if (min != i)
        {
            swap(pq.at(min), pq.at(i));
            min_heapify(pq, min);
        }
    }
    void insert(int elem, vector<int> &pq)
    {
        pq.push_back(elem);
        for(int i=1;i<=pq.size();i++)
            min_heapify(pq, i);
    }

    void extractKthMin(int k)
    {

    }
    bool myCompare(int a, int b)
    {
        if (a > b)
            return true;
        else
            return false;
    }
#define ll long long
    
    void func()
    {
        int q, k;
        cin >> q >> k;
        vector<int> ans;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        for (int i = 0; i < q; i++)
        {
            int qType;
            cin >> qType;
            if (qType == 1)
            {
                int x, y;
                cin >> x >> y;
                int elem = (x*x) + (y*y);
                pq.push(elem);
            }
            else if (qType==2)
            {
                vector<int> temp;
                for (int i = 0; i < k-1; i++)
                {
                    int top = pq.top();
                    temp.push_back(top);
                    pq.pop();
                }
                ans.push_back(pq.top());
                for (auto i : temp)
                {
                    pq.push(i);
                }
            }
        }
        for (auto i : ans)
            cout << i << endl;
        
    }
}


namespace HeapSort
{
#define item_type int
#define PQ_SIZE 255
    typedef struct {
        //item_type q[PQ_SIZE + 1]; /* body of queue */
        std::vector<int> q;
        int n; /* number of queue elements */
    } priority_queue;

    int pq_parent(int n)
    {
        if (n == 1) return(-1);
        else return((int)n / 2); /* implicitly take floor(n/2) */
    }
    int pq_young_child(int n)
    {
        return(2 * n);
    }

    void pq_swap(priority_queue *q, int indx1, int indx2)
    {
        item_type temp = q->q[indx1];
        q->q[indx1] = q->q[indx2];
        q->q[indx2] = temp;
    }

    void bubble_up(priority_queue *q, int p)
    {
        if (pq_parent(p) == -1) return; /* at root of heap, no parent */
        if (q->q[pq_parent(p)] > q->q[p]) {
            pq_swap(q, p, pq_parent(p));
            bubble_up(q, pq_parent(p));
        }
    }
    void pq_insert(priority_queue *q, item_type x)
    {
        if (q->n >= PQ_SIZE)
            printf("Warning: priority queue overflow insert x=%d\n", x);
        else {
            q->n = (q->n) + 1;
            q->q[q->n] = x;
            bubble_up(q, q->n);
        }
    }
    void pq_init(priority_queue *q)
    {
        q->n = 0;
    }
    void make_heap(priority_queue *q, item_type s[], int n)
    {
        int i; /* counter */
        pq_init(q);
        for (i = 0; i < n; i++)
            pq_insert(q, s[i]);
    }
    void bubble_down(priority_queue *q, int p)
    {
        int c; /* child index */
        int i; /* counter */
        int min_index; /* index of lightest child */
        c = pq_young_child(p);
        min_index = p;
        for (i = 0; i <= 1; i++)
            if ((c + i) <= q->n) {
                if (q->q[min_index] > q->q[c + i]) min_index = c + i;
            }
        if (min_index != p) {
            pq_swap(q, p, min_index);
            bubble_down(q, min_index);
        }
    }

    item_type extract_min(priority_queue *q)
    {
        int min = -1; /* minimum value */
        if (q->n <= 0) printf("Warning: empty priority queue.\n");
        else {
            min = q->q[1];
            q->q[1] = q->q[q->n];
            q->n = q->n - 1;
            bubble_down(q, 1);
        }
        return(min);
    }

    void heapsort(item_type s[], int n)
    {

        
        int i; /* counters */
        priority_queue q; /* heap for heapsort */
        make_heap(&q, s, n);
        for (i = 0; i < n; i++)
        {
            s[i] = extract_min(&q);
        }
        
    }
    void func()
    {
        int arr[] = { -1,200,162,98,72,50 };
        item_type s[100];
        for (int i = 0; i < 6; i++)
        {
            s[i + 1] = arr[i];
        }
        for (int i = 0; i <5; i++)
        {
            cout << s[i] << endl;
        }
        heapsort(s, 5);
    }
    
}

namespace PermuteBackTrack
{
    bool isASolution(int a[], int n, int k)
    {
        return (n == k);
    }
    
    void processSolution(int a[], int n)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i] << " ";
        cout << endl;
    }

    void constructCandidates(int a[], int n,int k, int *nCandidates, int c[])
    {
        int i;
        bool in_perm[255];
        for (i = 1; i < 255; i++)
        {
            in_perm[i] = false;
        }
        for (i = 0; i < k; i++)
        {
            in_perm[a[k]] = true;
        }
        *nCandidates = 0;
        for (i = 1; i <= n; i++)
            if (in_perm[i] == false) 
            {
                c[*nCandidates] = i;
                *nCandidates = *nCandidates + 1;
            }

    }

    void BackTrack(int a[], int n,int k)
    {
        if (isASolution(a, n, k))
        {
            processSolution(a, n);
        }
        else
        {
            k = k + 1;
            int nCandidates=0, can[255];
            /*constructCandidates(a, k, &nCandidates, can);
            for (int i = 0; i < nCandidates; i++)
            {
                a[k] = can[i];
                BackTrack(a, n, k);
            }*/
        }
    }
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
		/*int N;
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
        */
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

class Base
{
public:
	Base() {};
	~Base() {};

	virtual void Print() { std::cout << "Base"; };
};

namespace KK_Crush
{
    void func()
    {
        int t = 0;
        cin >> t;
        vector<string> ans;
        for (int i = 0; i < t; i++)
        {
            unordered_map<int, int> ht;
            int n = 0;
            cin >> n;
            int *arr = new int[n];
            for (int j = 0; j < n; j++)
            {
                int temp;
                cin >> temp;
                arr[j] = temp;
                ht[arr[j]] = 1;
            }
            int numQ;
            cin >> numQ;
            for (int j = 0; j < numQ; j++)
            {
                int temp;
                cin >> temp;
                unordered_map<int, int>::iterator it = ht.find(temp);
                if (it != ht.end())
                {
                    ans.push_back("Yes");
                }
                else
                {
                    ans.push_back("No");
                }
            }
        }
        for (auto i : ans)
        {
            cout << i;
        }
    }
}
namespace AndiBob
{
/*
https://www.hackerearth.com/practice/data-structures/hash-tables/basics-of-hash-tables/practice-problems/algorithm/bob-an-idiot-11/
*/

    void func()
    {
        int swaps = 0;
        cin >> swaps;
        std::map<char, char> swapMap;
        for (int i = 0; i < swaps; i++)
        {
            char key;
            cin >> key;
            
            char val;
            cin >> val;
            
            swapMap[key] = val;
            swapMap[val] = key;
        }
        std::map<char, char> finalMap;

        string inputStr;
        cin >> inputStr;
        char *out = new char[inputStr.length()+1];
        char *ptr = out;
        int j = 0;
        for (int i = 0; i < inputStr.length(); i++)
        {
            char ch = inputStr.at(i);
            std::map<char, char>::iterator it = swapMap.find(ch);
            if (it != swapMap.end())
            {
                char act = it->second;
                *ptr = act;
            }
            else
            {
                *ptr = ch;
            }
            ptr++;
        }
        *ptr = '\0';
        cout << out;
        delete out;
    }
}

namespace Birthday_Greetings
{
    struct Date
    {
        int month;
        int year;
        int day;
    };
    struct Person
    {
        string _first_name;
        string _last_name;
    };
    class DataStore
    {
        Person person;
        Date _DOB;
        string _email;
    public:
        virtual string getFirstName()=0;
        virtual string getLastName()=0;
        virtual Date getDOB()=0;
        virtual string getEmail()=0;

    };

    class FileDataStore :public DataStore
    {
    public:
        FileDataStore(string file_name)
        {

        }
        string getFirstName() override
        {

        }
        /*return names who are born on this date*/
        Person searchOnBday(Date date)
        {

        }

        /*return names who are born on this date*/
        Date searchOnPerson(Person person)
        {

        }
    };

    /*void func()
    {
        string todayDate = getTodaysDate();

    }*/
}

class Derived : Base
{
public:
	Derived() {};
	~Derived() {};

	void Print() { std::cout << "Derived"; };
};

//namespace TennisKata
//{
//    class Player;
//    class Match
//    {
//        enum MatchState
//        {
//            eScheduled,
//            eRunning,
//            eFinished,
//            eAbandoned
//        };
//
//        string venue;
//        string stage;
//        vector<Player> participants;
//        string umpire;
//
//    public:
//        Match(Player p1, Player p2)
//        {
//            participants.push_back(p1);
//            participants.push_back(p2);
//        }
//        string getScore()
//        {
//
//        }
//    };
//
//    class Score;
//    class Player
//    {
//        Score *_score;
//    public:
//        Player();
//        string getScore();
//        void increaseScore(Player &opponent);
//        void decreaseScore(Player &opponent);
//    };
//
//    class Score
//    {
//        enum TennisScore
//        {
//            eLove,
//            e15,
//            e30,
//            e40,
//            eDeuce,
//            eAdvantage
//        };
//        TennisScore _tennisScore;
//        std::map<TennisScore, string> _score_map;
//    public:
//        Score():_tennisScore(eLove)
//        {
//            _score_map[eLove] = "Love";
//            _score_map[e15] = "15";
//            _score_map[e30] = "30";
//            _score_map[e40] = "40";
//            _score_map[eDeuce] = "Deuce";
//            _score_map[eAdvantage] = "Advantage";
//        }
//        string get()
//        {
//            return _score_map[_tennisScore];
//        };
//        void increase(Player& opponent)
//        {
//            if (_tennisScore == eAdvantage)
//            {
//                _tennisScore = eLove;
//            }
//            else if (_tennisScore == e40)
//            {
//                if (opponent.getScore() == "40")
//                {
//                    _tennisScore = static_cast<TennisScore>(static_cast<int>(_tennisScore) + 1);
//                }
//                else
//                {
//                    _tennisScore = eLove;
//                }
//            }
//            else
//            {
//                _tennisScore = static_cast<TennisScore>(static_cast<int>(_tennisScore) + 1);
//            }
//        };
//        void decrease(Player& opponent)
//        {
//            if(_tennisScore == eLove)
//            {
//                _tennisScore = eLove;
//            }
//            else
//            {
//                _tennisScore = static_cast<TennisScore>(static_cast<int>(_tennisScore) - 1);
//            }
//        };
//    };
//
//    Player::Player() :_score(new Score) {};
//    string Player::getScore()
//    {
//        return _score->get();
//    };
//
//    void Player::increaseScore(Player &opponent)
//    {
//        _score->increase(opponent);
//    };
//
//    void Player::decreaseScore(Player &opponent)
//    {
//        _score->decrease(opponent);
//    };
//    
//
//    /*void func()
//    {
//        Player p1;
//        Player p2;
//        p1.increaseScore(p2);
//        p1.increaseScore(p2);
//        p1.increaseScore(p2);
//        cout << "Player - 1 score:" << p1.getScore() << endl;;
//        cout << "Player - 2 score:" << p2.getScore() << endl;
//        
//        p2.increaseScore(p1);
//        p2.increaseScore(p1);
//        p2.increaseScore(p1);
//        cout << "Player - 1 score:" << p1.getScore() << endl;
//        cout << "Player - 2 score:" << p2.getScore() << endl;
//    }*/
//
//}

namespace RvalExample
{
    class Metadata
    {
        string _name;
        int _size;
    public:
        Metadata(string name, int n) :_name(name), _size(n) {};
        Metadata() :_name("ArrayWrapper"), _size(64) {};
        Metadata(int n) :_name("ArrayWrapper"), _size(n) {};
        Metadata(const Metadata& rhs) :_name(rhs._name), _size(rhs._size) {};
        int getSize() { return _size; };
        string getName() { return _name; };
        Metadata(Metadata&& rhs)
        {
            _size = rhs._size;
            _name = std::move(rhs._name);
        };


    };
    class ArrayWrapper
    {
        int *_arr;
        Metadata _metadata;
    public:
        ArrayWrapper(int n) :_metadata(n), _arr(new int[n]) {};
        
        ArrayWrapper() :_metadata(64), _arr(new int[64]) {};
        
        ArrayWrapper(const ArrayWrapper &rhs):_metadata(rhs._metadata)
        {
            for (int i = 0; i < _metadata.getSize(); i++)
            {
                _arr[i] = rhs._arr[i];
            }
        };
       
        ArrayWrapper(ArrayWrapper&& rhs) :_arr(rhs._arr),_metadata(std::move(rhs._metadata))
        {
           
            rhs._arr = nullptr;
        };



    };
}
namespace CombinationSum
{
    /*vector<vector<int>> total_solution;
    bool isSolution(vector<int> input_vec, int target)
    {
        int temp = 0;
        for (auto i : input_vec)
            temp = temp + i;

        if (temp == target)
            return true;
        else 
            return false;
    }

    void processSolution(vector<int> solution)
    {
        total_solution.push_back(solution);
    }

    void findCandidates(vector<int> solution_vector, int pos,vector<int> input_vector,vector<int> candidate_vector,int target)
    {
        int temp_sum = 0;
        for (auto i : solution_vector)
            temp_sum = temp_sum + i;
        
        for (int i = pos; i < input_vector.size(); i++)
        {
            if (temp_sum + input_vector.at(pos) < target)
                candidate_vector.push_back(input_vector.at(pos));
        }
    }

    void backTrack(vector<int> solution_vector,int k,vector<int> input_vector,int target)
    {
        if (isSolution(solution_vector, target))
        {

        }
        else
        {
            k = k + 1;


        }
    }

    void func()
    {
        backTrack()
    }*/
}

namespace NeedleInHayStack
{
    int strStr(const char* hs, const char* needle)
    {
        int len_hs = strlen(hs);
        int len_ne = strlen(needle);

        for (int i = 0; i < len_hs - len_ne; i++)
        {
            int k = i;
            for (int j = 0; j < len_ne; j++)
            {
                if (hs[k] == needle[j])
                {
                    k++;
                    j++;
                }
                else
                {
                    break;
                }
            }
            
            if (k - i == len_ne)
                return k;

        }
    }
    void func()
    {
        char *hs = "mmHell";
        char *n = "ll";
        int i = strStr(hs, n);
        cout << "Found at "<<i;
    }
}
namespace ReverseSentence
{
    /*string reverseWords(string inp)
    {
        stack<string> ss;
        for (int i = 0; i < inp.length(); i++)
        {
            int indx = inp.find(' ', i);
            if (indx != std::string::npos)
            {

            }
        }
    }
    void func()
    {

    }*/
}
namespace MixParanValidator
{
    bool isValid(string inp)
    {
        std::stack<char> validator;

        for (int i = 0; i < inp.length(); i++)
        {
            if (inp.at(i) == '[' ||
                inp.at(i) == '(' ||
                inp.at(i) == '{')
            {
                validator.push(inp.at(i));
            }
            else if (inp.at(i) == ']' ||
                inp.at(i) == ')' ||
                inp.at(i) == '}')
            {
                char ch = validator.top();
                if (!validator.empty())
                {
                    if ((ch == '[' && inp.at(i) ==']') ||
                        (ch == '(' && inp.at(i) == ')')||
                        (ch == '{' && inp.at(i) == '}'))
                    {
                        validator.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
                
        }
    }
    void func()
    {

    }
}
namespace GroupAnagram
{
    int isAnagram(string s1, string s2)
    {
        auto len1 = s1.length();
        auto len2 = s2.length();
        if (len1 != len2)
            return false;

        unordered_map<char, int> char_table;
        for (int i=0;i<len1;i++)
        {
            char_table[s1.at(i)]++;
        }
        for (int i = 0; i < len2; i++)
        {
            auto it = char_table.find(s2.at(i));
            
            if(it == std::end(char_table))
            {
                return 0;
            }
            else
            {
                char_table[s2.at(i)]--;
                if (char_table[s2.at(i)] == 0)
                {
                    char_table.erase(s2.at(i));
                }
            }
        }
        if (char_table.empty())
            return 1;
        else
            return 0;
    }
    
    void func()
    {
        cout << "IS anagram abc,bca" << isAnagram("abc", "bca")<<endl;
        cout << "IS anagram abc,bcd" << isAnagram("abc", "bcd")<<endl;
    }

    void getAnagramGroup(list<vector<string>> solution_list, vector<string> input_strings)
    {
  
    }
}
namespace Sort_Char_Freq
{

    void func()
    {
        std::string input_string;
        cout << "Input the string" << endl;
        cin >> input_string;
        using char_freq_map = map<char, int>;
        auto i = 0;
        char_freq_map cf_map;

        while (i < input_string.length())
        {
            auto it = cf_map.find(input_string.at(i));
            if (it != std::end(cf_map))
            {
                cf_map[input_string.at(i)]++;
            }
            else
            {
                cf_map[input_string.at(i)] = 1;
            }
            i++;
        }
        vector<std::pair<char, int>> vec;
        for (auto it : cf_map)
        {
            vec.push_back(it);
        }
        std::sort(vec.begin(), vec.end(), [](auto it1, auto it2) {return it1.second < it2.second; });
        for (auto it : vec)
        {
            char ch = it.first;
            int i = it.second;
            cout << ch << ' : ' << i << endl;
        }
    }
}
namespace Climbing_Stairs
{
    int Climbing_Stairs(int n)
    {
        if (n == 1) return 1;
        if (n == 2) return 2;
        return(1 + Climbing_Stairs(n - 1)+Climbing_Stairs(n-2));
    }
    void func()
    {
        int n;
        cin >> n;
        cout << "Climbiing stairs way::" << Climbing_Stairs(n) << endl;
    }
}
namespace Poly_Array
{
    struct X {
        virtual void f() const { std::cout << "X"; }
    };

    struct Y : public X {
        void f() const { std::cout << "Y"; }
    };

    void print(const X &x) { x.f(); }

    void func()
    {
        unsigned short x = 0xFFFF;
        unsigned short y = 0xFFFF;
        auto z = x * y;
        std::cout << (z > 0);
    }
}



namespace Modern_Effective_CPP
{

    enum class Car
    {
        eNone,
        eSedan,
        eHatchBack,
        eSUV,
        eLuxury
    };
    enum Car2
    {
        eNone,
        eSedan,
        eHatchBack,
        eSUV,
        eLuxury
    };
    using SSMap = std::map<string, string>;
    void myfunc(int m)
    {

    }
    
    
    void myfunc(char a) =delete;
    void myfunc(double a) =delete;

    void makeLogEntry() {};
    class Investment
    {    };
    class Stock:public Investment{};
    class Bond:public Investment {};
    class RealEstate:public Investment {};
    
    /*auto loggingDel = [](Widget* pw) {
        makeLogEntry();
        delete pw;
    };*/

    class Widget : public std::enable_shared_from_this<Widget>{
    public:
        void process()
        {
            //processed_widgets.emplace_back(shared_from_this());
            
        };

        Widget(bool b, double d) {
            cout << "Normal widget" << endl;
        };

        Widget(std::initializer_list<long double> il) {
            cout << "initializer_list widget" << endl;
        };

    };
    vector<shared_ptr<Widget>> processed_widgets;

    void processWidget(const Widget& wdg)
    {

    }

    void processWidget(Widget&& wdg)
    {

    }
    template <typename Ts>
    void logAndProcess(Ts&& wdg)
    {
        processWidget(std::forward<Ts>(wdg));
    }
    std::function<int()> make_my_closure(int x) {
        return [x]() mutable {
            ++x;
            return x;
        };
    }
    void func2()
    {
        //Widget w;
        //logAndProcess(w);
        //logAndProcess(std::move(w));
        auto my_f = make_my_closure(10);
        
        std::cout << my_f() << std::endl; // 11
        std::cout << my_f() << std::endl; // 12
        std::cout << my_f() << std::endl; // 13

        auto my_f1 = make_my_closure(1);

        std::cout << my_f1() << std::endl; // 2
        std::cout << my_f1() << std::endl; // 3
        std::cout << my_f1() << std::endl; // 4

        std::cout << my_f() << std::endl; // 14
    }
    auto delInvmt = [](Investment* ptr) {
        makeLogEntry();
        delete ptr; 
    };

    std::unique_ptr<Investment,decltype(delInvmt)> makeInvestment(int num)
    {
        std::unique_ptr<Investment, decltype(delInvmt)> inv (nullptr, delInvmt);
        if (num == 1) inv.reset(new Stock());
        else if (num == 2) inv.reset(new Bond());
        else if (num == 3) inv.reset(new RealEstate());
        return inv;
    }

    constexpr int pow(int base, int exp)
    {
        int ret = 1;
        for (int i = 0; i < exp; i++)
            ret = ret * base;
        return ret;
    }

    void func()
    {
        auto m = Car::eNone;
        int n = static_cast<int>(m);
        int n1 = Car2::eNone;
        SSMap kv;
        kv["Hello"] = "World";
        kv["Me"] = "Mine";
        char c = 'A'; 
        auto inv = makeInvestment(1);
        //std::shared_ptr<Widget> spw1(new Widget, loggingDel);
        //std::shared_ptr<Widget> spw2(spw1);
        //std::weak_ptr<Widget> wps(spw1);

        const int sz = 10;
        constexpr auto size = sz;
        std::array<int, size> arr;

        constexpr auto numCOnds = 5;
        
        auto a = 3;
        decltype(a) b;
    }
}
namespace CPP_17_Concepts
{
    void func()
    {
        double d = 2;
        auto p = (long*)&d;
        auto q = (long long*)&d;
        cout << "double sizz:" << sizeof(double) << ' ' << sizeof(long) << ' ' << sizeof(long long) << endl;;
        std::cout << d << ' ' << *p << ' ' << *q << '\n';

    }
}
#include <sstream>
namespace ThreadSafeLogger
{
    class SimpleLogger
    {
    public:
        template <typename T>
        static void log(T& message)
        {
            mutex.lock();
            std::cout << message.str();
            message.flush();
            mutex.unlock();
        }
    private:
        static std::mutex mutex;
    }LOG;
    std::mutex SimpleLogger::mutex;

    struct SimpleLoggerBuffer {
        stringstream ss;

        SimpleLoggerBuffer() = default;
        SimpleLoggerBuffer(const SimpleLoggerBuffer&) = delete;
        SimpleLoggerBuffer& operator=(const SimpleLoggerBuffer&) = delete;
        SimpleLoggerBuffer& operator=(SimpleLoggerBuffer&&) = delete;
        SimpleLoggerBuffer(SimpleLoggerBuffer&& buf) : ss(move(buf.ss)) {
        }
        template <typename T>
        SimpleLoggerBuffer& operator<<(T&& message)
        {
            ss << std::forward<T>(message);
            return *this;
        }

        ~SimpleLoggerBuffer() {
            LOG.log(ss);
        }
    };
}
namespace lambda_c11_sample
{
    struct Student
    {
        string name;
        int id;
    };
    void func()
    {
        vector<Student> vec;
        Student s[3] = { {"Ram",6},{"Jai",5},{"Krish",2} };
        for (size_t i = 0; i < 3; i++)
        {
            vec.push_back(s[i]);
        }
        for_each(vec.begin(), vec.end(),[](const Student& s) {
            cout << "Name:" << s.name << " id:" << s.id << endl;
        });
        std::sort(vec.begin(), vec.end(), [](const Student& s1, const Student& s2)->bool {return s1.id < s2.id; });
        for_each(vec.begin(), vec.end(), [](const Student& s) {
            cout << "Name:" << s.name << " id:" << s.id << endl;
        });

    }
}
namespace LRU_Cache
{
    class LRUCache
    {
        int _capacity;
        unordered_map<int, int> data_table;
        deque<int> cache_queue;
        int _current_capacity;
    public:
        LRUCache(int capacity) :_capacity(capacity), _current_capacity(1)
        {};
        
        void update_dq(int key)
        {
            auto it = std::find(cache_queue.begin(), cache_queue.end(), key);
            if (it != std::end(cache_queue))
            {
                auto it = remove(cache_queue.begin(), cache_queue.end(), key);
                cache_queue.erase(it,cache_queue.end());
            }
            cache_queue.push_front(key);
        }

        int get(int key)
        {
            auto it = data_table.find(key);
            if (it == std::end(data_table))
                return -1;
            else
            {
                update_dq(key);
                return data_table[key];
            }
            
        };
        
        void put(int key, int val)
        {
            if (_current_capacity <= _capacity)
            {
                data_table[key] = val;
                update_dq(key);
                _current_capacity++;
            }
            else
            {
                int keyToRemove = cache_queue.back();
                cache_queue.pop_back();
                data_table.erase(keyToRemove);
                data_table[key] = val;
                update_dq(key);
                _current_capacity--;

            }
        }

    };

}

namespace StringToInt
{
    int MyAtoI(string s)
    {
        bool sign = 0;
        string temp_str = s;
        
        /*auto it = remove_if(temp_str.begin(), temp_str.end(), ' ');
        temp_str.erase(it, temp_str.end());

        std::size_t sz = temp_str.find('-');
        if (sz != std::string::npos)
        {
            it = remove_if(temp_str.begin(), temp_str.end(), '-');
        }
        temp_str.erase(it, temp_str.end());*/

        if (s.at(0) == '-')
            sign = 1;
        
        int len = s.length();
        if (sign)
            len = len - 1;

        int out = 0;
        int dig = 0;
        int i = len;
        
        for (int j=0; i >0; i--)
        {
            dig = s.at(i-1) - '0';
            out = out + dig * pow(10, j);
            j++;
        }
        return out;
    }

    void func()
    {
        int num = StringToInt::MyAtoI("123");
        cout << "MyATOI :: " << num;
    }
}

namespace NonRepeatingElem_ThreadVer
{
    std::unordered_map<int,int> output_array;
    std::mutex output_mutex;
    int g_indx = 1;
    void runThread(int id,std::vector<int> input_array)
    {
        for (; g_indx<input_array.size();)
        {
            std::lock_guard<std::mutex> guard(output_mutex);
            cout << "Thread-" << id << " processing " << g_indx << endl;
            auto elem = output_array.find(input_array.at(g_indx));
            if (elem == std::end(output_array))
            {
                output_array[g_indx] = 1;
            }
            g_indx++;
        }
    }

    void findNonRepeatElem(std::vector<int> input_array, int T)
    {
        std::thread th1(runThread, 1,input_array);
        std::thread th2(runThread, 2,input_array);
        th1.join();
        th2.join();
        std::unordered_map<int, int>::iterator itBegin = output_array.begin();
        std::unordered_map<int, int>::iterator itEnd = output_array.end();
        for (; itBegin!=itEnd;itBegin++)
        {
            cout << (*itBegin).first<< ' ';
        }
    }

    void func()
    {
        std::vector<int> input_array;
        int n = 100;
        for (int i=1;i<=n;i++)
        {
            input_array.push_back(i);
        }
        for (int i = 1; i <= n; i++)
        {
            input_array.push_back(i);
        }
        findNonRepeatElem(input_array, 2);
    }
}

namespace PrintAltThread
{
    int g_counter = 1;
    std::mutex print_controller;
    int g_thread_alternator = 1;
    void Thread1()
    {
        while (g_counter<100)
        {
            std::lock_guard< std::mutex> guard(print_controller);
            if (g_thread_alternator == 1)
            {
                cout << "Thread-1::g_counter::" << g_counter << endl;
                g_counter++;
                g_thread_alternator = 2;
            }
        }
    }

    void Thread2()
    {
        while (g_counter < 100)
        {
            std::lock_guard< std::mutex> guard(print_controller);
            if (g_thread_alternator == 2)
            {
                cout << "Thread-2 ::g_counter::" << g_counter << endl;
                g_counter++;
                g_thread_alternator = 1;
            }
        }
    }
    void func()
    {
        std::thread th1(Thread1);
        std::thread th2(Thread2);
        th2.join();
        th1.join();
        
    }
}

namespace jmossBergExercise
{
    class A
    {
        int * _number;
    public:
        A(int number)
        {
            _number = new int;
            *_number = number;
            cout << "class A constructor: " << *_number << endl;
        };
        A(const A& rhs)
        {
            _number = new int;
            *_number = *rhs._number;
            cout << "class A copy constructor: " << *_number << endl;
        };

        A(A&& rhs)
        {
            _number = std::move(rhs._number);
            rhs._number = nullptr;
            cout << "class A move constructor: " << *_number << endl;
        };

        A& operator=(const A& rhs)
        {
            *_number = *rhs._number;
            cout << "class A copy assignment operator: " << *_number << endl;
            return *this;
        };

        A& operator=(A&& rhs)
        {
            *_number = *rhs._number;
            rhs._number = nullptr;
            cout << "class A move assignment operator: " << *_number << endl;
            return *this;
        };

        ~A()
        {
            if(_number == nullptr)
                cout << "class A destructor: nullptr" << endl;
            else
                cout << "class A destructor: " << *_number << endl;
        };
    };

    void func()
    {
        A a8{ 11 };
        A a9{ move(a8) };
    }
}
namespace RValExample
{
    class MyString
    {
    public:
        MyString()
        {
            cout << "Constructor" << endl;
        };
        MyString(const MyString& rhs)
        {
            cout << "Copy constructor" << endl;
        };
        MyString(MyString&& rhs)
        {
            cout << "MOve constructor" << endl;
        };
    };
    MyString simply()
    {
        MyString s;
        return s;
    }
    void func()
    {
        MyString ms;
        MyString ms2 = simply();
        MyString ms3(ms2);
    }
}

//namespace Observer_With_WP
//{
//    class Subscriber
//    {
//    protected:
//        std::shared_ptr<Observer> _ob;
//    public:
//        Subscriber(std::shared_ptr<Observer> ob) :_ob(ob) {};
//        virtual void update() = 0;
//    };
//
//    class Observer
//    {
//        vector<weak_ptr<Subscriber>> subscribers;
//    public:
//        void subscribe(std::shared_ptr<Subscriber> sub)
//        {
//            subscribers.push_back(sub);
//        }
//
//        void notify()
//        {
//            for (auto subs : subscribers)
//            {
//                if (!subs.expired())
//                {
//                    auto w = subs.lock();
//                    w->update();
//                }
//            }
//        }
//    };
//    
//    class Subscriber1 :public Subscriber
//    {
//    public:
//        Subscriber1(shared_ptr<Observer> ob) :Subscriber(ob)
//        {};
//        void update() override
//        {
//            cout << "Subscriber1 update" << endl;
//        }
//    };
//    class Subscriber2 :public Subscriber
//    {
//    public:
//        Subscriber2(shared_ptr<Observer> ob) :Subscriber(ob) {};
//        void update() override
//        {
//            cout << "Subscriber2 update" << endl;
//        }
//    };
//
//    void func()
//    {
//        shared_ptr<Observer> ob = make_shared<Observer>();
//        shared_ptr<Subscriber> sub1 = make_shared<Subscriber1>(ob);
//        shared_ptr<Subscriber> sub2 = make_shared<Subscriber2>(ob);
//        ob->subscribe(sub1);
//        ob->subscribe(sub2);
//    }
//}
namespace SP_sample
{
    class Base{};
    class Derived1:public Base{};
    class Derived2:public Base{};
    void func2(shared_ptr<Base> &bp)
    {
        cout << "Third Reference count" << bp.use_count() << endl;
    }
    void func()
    {
        shared_ptr<Base> bp = make_shared<Derived1>();
        shared_ptr<Base> bp2(bp);
        {
            auto bp3 = bp2;
            cout << "First Reference count" << bp3.use_count() << endl;;
        }
        func2(bp);
        cout << "Second Reference count" << bp2.use_count() << endl;
    }
}
namespace MV_Sample
{
    template <typename T>
    class ArrayWrapper
    {
        int num;
        T* ptr;
    public:
        ArrayWrapper() :num(64), ptr(new T[num]) {};
        ArrayWrapper(const ArrayWrapper& rhs)
        {
            num = rhs.num;
            ptr = new T[num];
            for (int i = 0; i < num; i++)
                ptr[i] = rhs.ptr[i];
        };
        ~ArrayWrapper()
        {
            delete[] ptr;
        }
        ArrayWrapper& operator=(const ArrayWrapper& rhs)
        {
            num = rhs.num;
            delete[] ptr;
            ptr = new T[num];
            for (int i = 0; i < num; i++)
                ptr[i] = rhs.ptr[i];
            return *this;
        }
        ArrayWrapper(ArrayWrapper&& rhs)
        {
            num = rhs.num;
            ptr = rhs.ptr;
            rhs.num = 0;
            rhs.ptr = nullptr;
        }
        ArrayWrapper& operator=(ArrayWrapper&& rhs)
        {
            delete[] ptr;
            num = rhs.num;
            ptr = rhs.ptr;
            rhs.num = 0;
            rhs.ptr = nullptr;
            return *this;
        }
    };
    void process(ArrayWrapper<int>& aw)
    {
        cout << "lvalue process" << endl;
    }

    void process(ArrayWrapper<int>&& aw)
    {
        cout << "rvalue process" << endl;
    }
    
    void logAndProcess(ArrayWrapper<int>&& aw)
    {
        process(std::forward<ArrayWrapper<int>>(aw));
    }
    ArrayWrapper<int> getAW(int n)
    {
        ArrayWrapper<int> aw;
        return aw;
    }

    void func()
    {
        
    }
}

/*namespace Future_and_Promise
{
    void th(promise<int>& pr)
    {
        pr.set_value(35);
    }
    void func()
    {
        std::promise<int> prom;
        future fut = prom.get_future();
        thread mythread(th, prom);
        int v = fut.get();

        mythread.join();
    }
}*/
namespace CPP_17_sample_optional
{
    class Name
    {
        string first_name;
        std::optional<std::string> second_name;
        string last_name;

    public:
        Name(string f, std::optional<std::string> s, string l) :
            first_name(std::move(f)),second_name(move(s)),last_name(move(l))
        {};
        
    };
    class Base {
    public:
        virtual void printName() = 0;
    };
    class Derived1:public Base
    {
    public:
        void printName() override
        {
            cout << "Derived1" << endl;
        }
    };
    class Derived2:public Base
    {
    public:
        void printName() override
        {
            cout << "Derived1" << endl;
        }
    };

    std::optional<int> asInt(string s)
    {
        try
        {
            return atoi(s.c_str());
        }
        catch (...)
        {
            return std::nullopt;
        }
    }

    void func()
    {
        for (auto s : { "42","hello","89" })
        {
            std::optional p = asInt(s);
            if (p.has_value())
                cout << "Converted value for " << s << " is " << p.value() << endl;
            else
                cout << "Not able to convert "<<s << endl;
        }
        std::any a = 4.3;
        std::any b = "Hello";
        cout << "a' type " << a.type().name();
        cout << "b' type " << b.type().name();
        /*a = std::string{ "world" };
        std::string s1 = any_cast<string>(a);
        string s2 = any_cast<string>(b);
        cout << "s==" << (s1+s2);*/
        vector<any> vec;
        vec.push_back(42);
        vec.push_back(4.2);
        vec.push_back(4.2f);
        string san("hello world");
        vec.push_back(san);
        for (auto i : vec)
        {
            if (i.type() == typeid(int))
            {
                auto t = std::any_cast<int>(i);
                cout <<"int type"<< t;
            }
            if (i.type() == typeid(float))
            {
                auto t = std::any_cast<float>(i);
                cout << "float type" << t;
            }
            if (i.type() == typeid(double))
            {
                auto t = std::any_cast<double>(i);
                cout << "double type" << t;
            }
            if (i.type() == typeid(string))
            {
                auto t = std::any_cast<string>(i);
                cout << "string type" << t;
            }
        }
        variant<Derived1, Derived2> var;
        auto caller = [](Base& obj) {obj.printName(); };
        visit(caller, var);

    }
}

namespace Two_Sum
{
    class Solution 
    {
    public:
        vector<int> twoSum(vector<int>& nums, int target) 
        {
            vector<int> resultVec;
            vector<int>::iterator itBegin = nums.begin();
            vector<int>::iterator itEnd = nums.end();
            for (;itBegin!=itEnd;itBegin++)
            {
                auto j = target - *itBegin;
                auto k = std::find(itBegin+1, itEnd, j);
                if (k != itEnd)
                {
                    resultVec.push_back(itBegin-nums.begin());
                    resultVec.push_back(k-nums.begin());
                    break;
                }
            }
            return resultVec;
        }
    };
    void func()
    {
        Solution s;

        vector<int> vec{ 3,2,4 };
        int target = 6;
        vector<int> out = s.twoSum(vec, target);
    }
}
namespace Buy_N_Sell_Stock
{
    class Solution {
    public:
        int maxProfit(vector<int>& prices) 
        {
            vector<int>::iterator itBegin = prices.begin();
            vector<int>::iterator itEnd = prices.end();
            int maxProfit = 0;
            for (; itBegin != itEnd; itBegin++)
            {
                for (auto j = itBegin + 1; j != itEnd; j++)
                {
                    auto temp =  *j - *itBegin;
                    if (temp > maxProfit)
                        maxProfit = temp;
                }
            }
            return maxProfit;
        }
    };
}
namespace Sum_WO_Plus
{
    class Solution {
    public:
        int getSum(int a, int b) {

            int bit_op = 1;
            int count = 0;
            int carry = 0;
            int fr = 0;
            int temp_a = a;
            int temp_b = b;
            while (temp_a != 0 && temp_b !=0)
            {
                if ((a & bit_op) && (b&bit_op)) // both 1
                {
                    int res = (a&bit_op) ^ (b&bit_op) ^ carry;
                    carry = 1;
                    fr = fr | (res << count);
                }
                else if ((a & bit_op) ^ (b&bit_op)) // 1&0 or 0&1 case
                {
                    int res = (a&bit_op) ^ (b&bit_op)^ carry;
                    if(res != 0)
                        fr = fr | (res << count);
                    carry = 0;
                }
                else //0&0 case
                {
                    if (carry)
                    {
                        fr = fr | (carry << count); 
                    }
                }
                
                bit_op = bit_op << 1;
                temp_a = temp_a >> 1;
                temp_b = temp_b >> 1;
                count++;
            }
            if (temp_a == 0)
            {
                while (temp_b != 0)
                {
                    temp_b = temp_b >> 1;
                    if (carry)
                    {

                    }
                    else
                    {

                    }
                }
            }
        }
    };
}
namespace Counting_Bits
{
    class Solution {
    public:
        int count1s(int n)
        {
            int temp_n = n;
            int count = 0;
            int one = 1;
            while (temp_n) 
            {
                if (n&one)
                {
                    count++;
                }
                one = one << 1;
                temp_n = temp_n >> 1;
            }
            return count;
        }
        vector<int> countBits(int n) {
            vector<int> vecInt;
            vecInt.push_back(0);
            for (int i = 1; i <= n; i++)
            {
                int res = count1s(i);
                vecInt.push_back(res);
            }
            return vecInt;
        }
    };
}

namespace MissingNum
{
    class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int len = nums.size();
            int sum = (len*(len + 1)) / 2;
            int actSum = 0;
            for (auto i : nums)
            {
                actSum += i;
            }
            return sum - actSum;
        }
    };
}

namespace Reverse_Bits
{
    class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            uint32_t result = 0;
            int one = 1;
            int temp_r = 1;
            
        }
    };

}

namespace InsInterval
{
    class Solution {
        void sorting(vector<vector<int>>& intervals, vector<int>& newInterval){
            pair<int, int> p;
            p.first = newInterval[0];
            int i = 0;
            for (; i < intervals.size(); i++)
            {
                if (intervals[i][0] > p.first)
                    break;
            }
            intervals.insert(intervals.begin() + i, newInterval);
        }
    public:
        vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
            sorting(intervals, newInterval);
            pair<int, int> p ;
            p.first = intervals[0][0];
            p.second = intervals[0][1];
            vector<vector<int>> result;
            for (int i = 1; i < intervals.size(); i++)
            {
                if (p.second > intervals[i][0])
                {
                    p.second = max(p.second, intervals[i][1]);
                }
                else
                {
                    result.push_back({p.first,p.second});
                    p.first = intervals[i][0];
                    p.second = intervals[i][1];
                }
            }
            result.push_back({ p.first,p.second });
            return result;

        }
    };
}

namespace MergeInterval
{
    class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) {
            sort(intervals.begin(), intervals.end(), [](auto lhs,auto rhs) {
            return lhs[0]<rhs[0]});
            pair<int, int> p;
            vector<vector<int>> res;
            p.first = intervals[0][0];
            p.second = intervals[0][1];
            int i;
            for (i = 1; i < intervals.size(); i++)
            {
                if (p.second > intervals[i][0])
                    p.second = max(p.second, intervals[i][1]);
                else
                {
                    res.push_back({ p.first,p.second });
                    p.first = intervals[i][0];
                    p.second = intervals[i][1];
                }
            }
            res.push_back({ p.first,p.second });
            return res;
        }
    };
}

namespace WP_sample
{
    class Controller
    {

    public:
        int num;
        string status;
        vector<weak_ptr<Controller>> others;
        Controller(int i) :num(i),status("On")
        {
            cout << "Creating controller" << num << endl;
        };
        ~Controller()
        {
            cout << "Creating controller" << num << endl;
        };
        void checkStatus()
        {
            for_each(others.begin(), others.end(), [](weak_ptr<Controller> p) 
            {
                auto w = p.lock();
                if (w)
                    cout << "Status of controller-" << w->num << " is " << w->status << endl;
            });
        }
    };
    void func()
    {
        vector<shared_ptr<Controller>> controllers{
        make_shared<Controller>(0),
        make_shared<Controller>(1),
        make_shared<Controller>(2),
        make_shared<Controller>(3),
        make_shared<Controller>(4),
        };
        for (int i = 0; i < controllers.size(); ++i)
        {
            for_each(controllers.begin(), controllers.end(), [&controllers, i](shared_ptr<Controller> p)
            {
                if (p->num != i)
                {
                    controllers[i]->others.push_back(p);
                }
            });

        }
        
    }
}
namespace Memento_DP
{
    class State
    {

    };
    
    class TextEditor
    {
        class Memento
        {
            State _state;
        public:
            Memento(State state) :_state(state) {};
        };

        State state;
        stack<Memento> TE_states;
    public:
        Memento Save()
        {
            TE_states.push(state);
        }
        void Restore(Memento& mem)
        {

        }
    };
    class Caretaker
    {

    };
}

int main()
{
    Two_Sum::func();

    //simply();
    return 0;

	string message1 = "logg message 1 ...";
	string message2 = "logg message 2 ...";
	int    nNum = 10;
    //ElectricType::readInput();
    LMW::func();
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
