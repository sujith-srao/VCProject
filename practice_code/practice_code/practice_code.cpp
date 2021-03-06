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
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        
        
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


class Derived : Base
{
public:
	Derived() {};
	~Derived() {};

	void Print() { std::cout << "Derived"; };
};
namespace DynamicProgramming
{

}

int main()
{
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
