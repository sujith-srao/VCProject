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
#include<unordered_set>
#include<cassert>
#include"STL_CookBook.h"
#include<exception>
#include<ctime>
#include<thread>
#include<chrono>

using namespace std;
namespace LS_22 {
    /*22. Generate Parentheses*/
    bool isSolution(int n,int i) {
        if (i == 2 * n) return true;
        else return false;
    }


    void backtrack_algo(int n, string &s,int open,int close,vector<string> &ansVec) {
        vector<char> candidates{ '(',')' };
        /*if (isSolution(n, s.size())) {
            ansVec.push_back(s);
        }*/
        if (s.size() == n * 2) {
            ansVec.push_back(s);
        }
        if (open < n) {
            s.append(1, '(');
            backtrack_algo(n, s,open+1,close,ansVec);
            s.pop_back();
        }
        if (close < open) {
            s.append(1, ')');
            backtrack_algo(n, s, open, close+1, ansVec);
            s.pop_back();
        }
    }
    class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            string s;
            vector<string> ansVec;
            int i = 0;
            backtrack_algo(n,s, 0,0, ansVec);
            return ansVec;
        }
    };
    void func() {
        Solution s;
        s.generateParenthesis(3);
    }
}
namespace LS_17 {
    /*17. Letter Combinations of a Phone Number*/
    map<char, string> phone_map{
        {'2',"abc"},
        {'3',"def"},
        {'4',"ghi"},
        {'5',"jkl"},
        {'6',"mno"},
        {'7',"pqrs"},
        {'8',"tuv"},
        {'9',"wxyz"},
    };

    void backtrack_letterCombi(string digits,int cur,vector<string> &ansVec,string out) {
        if (cur == digits.size()) {
            ansVec.push_back(out);
        }
        string temp = phone_map[digits[cur]];
        for (int i = 0; i < temp.size(); i++) {
            out.push_back(temp[i]);
            backtrack_letterCombi(digits, cur + 1, ansVec, out);
            out.pop_back();
        }

    }
    class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            vector<string> ans;
            backtrack_letterCombi(digits, 0, ans, "");
            return ans;
        }
    };
    void func() {
        Solution s;
        string st("23");
        s.letterCombinations(st);
    }
}
namespace LS_452 {
    
    
        bool point_comp(vector<int> &lhs,vector<int> &rhs) {
            if (lhs[1] <= rhs[1]) return true;
            return false;
        }
    
    class Solution {
    public:
        int findMinArrowShots(vector<vector<int>>& points) {
            sort(points.begin(), points.end(), point_comp);

        }
    };
}
namespace LS_605 {
    class Solution {
    public:
        bool canPlaceFlowers(vector<int>& flowerbed, int n) {
           
            if (flowerbed.at(0) == 0 && flowerbed.at(1) == 0) {
                flowerbed[0] = 1;
                n--;
            }
            for (int i = 0; i < flowerbed.size(); i++) {
                
                if (flowerbed.at(i) == 0) {
                    if (i == 0) {
                        if (flowerbed.at(i + 1) == 0) {
                            n--;
                            flowerbed[i] = 1;

                        }
                    }
                    if (i == flowerbed.size() - 1) {
                        if (flowerbed.at(i - 1) == 0) {
                            n--;
                            flowerbed[i] = 1;

                        }
                    }

                    if (flowerbed.at(i -1) == 0 &&
                        flowerbed.at(i + 1) == 0) {
                        n--;
                        flowerbed[i] = 1;
                    }
                }
            }
            

            return (n <= 0);
        }
    };
}
namespace LS_134 {
    /* Gas Station*/
    class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {

            int res = 0;
            for (int gs_ptr = 0; gs_ptr < gas.size(); gs_ptr++) {
                res = gs_ptr;
                int tank = gas.at(gs_ptr);
                int cur_ptr = gs_ptr + 1;
                for (; cur_ptr < gas.size(); cur_ptr++) {
                    tank = tank - cost[cur_ptr] + gas[cur_ptr];
                    if (tank < 0) {
                        //res = -1;
                        break;
                    }
                }
                if (res != -1) {
                    if (cur_ptr > 0) {
                        for (int cur_ptr_f = 0; cur_ptr_f < gs_ptr; cur_ptr_f++) {
                            tank = tank - cost[cur_ptr_f] + gas[cur_ptr_f];
                            if (tank < 0) {
                                res = -1;
                                break;
                            }
                        }
                    }
                }
                
                if (res != -1) {
                    return gs_ptr;
                }
            }
            return -1;
        }
    };
}
namespace LS_279 {
    class Solution {
    public:
        map<int,int> table;
        int numSquares(int n) {
            int i=1;
            for (;; i++) {
                if (i * i < n) {
                    table[i] = i * i;
                }
                else {
                    break;
                }
            }

        }
    };
}
namespace LS_553 {
    /*Optimal Division*/
    class Solution {
         
        float dyn_prg_divide(vector<int>& nums,int cur) {
            if (nums.size() == cur+2) { /*min of (a/b)/c OR a/(b/c) */
                float ans1 = (nums.at(cur) / nums.at(cur + 1)) / nums.at(cur + 2);
                float ans2 = nums.at(cur) / (nums.at(cur + 1) / (nums.at(cur + 2)));
                if (ans1 < ans2)
                    return ans1;
                else
                    return ans2;
            }
            //float ans1 = nums.at(cur)/ dyn_prg_divide(nums,cur+1)
        }

    public:
        string optimalDivision(vector<int>& nums) {

        }
    };
}
namespace LS_64 {
    /*Minimum Path Sum*/
    class Solution {
        int dyn_pg(vector<vector<int>>& grid,int cur_row,int cur_col) {
            int max_rows = grid.size();
            int max_cols = grid[0].size();

            if (cur_row == max_rows - 1 &&
                cur_col == max_cols - 1) {
                return grid[cur_row].at(cur_col);
            }
            if (cur_row == max_rows - 1) {
                return grid[cur_row][cur_col] + dyn_pg(grid, cur_row, cur_col+1);
            }
            if (cur_col == max_cols - 1) {
                return grid[cur_row][cur_col] + dyn_pg(grid, cur_row+1, cur_col);
            }
            return min(grid[cur_row][cur_col] + dyn_pg(grid, cur_row + 1, cur_col),
                grid[cur_row][cur_col] + dyn_pg(grid, cur_row, cur_col + 1));

        }
    public:
        int minPathSum(vector<vector<int>>& grid) {

        }
    };
}
namespace LS_2266 {
    map<string, char> phone_map{
        {"2"   ,'a'},
        {"22"  ,'b'},
        {"222" ,'c'},
        {"3"   ,'d'},
        {"33"  ,'e'},
        {"333" ,'f'},
        {"4"   ,'g'},
        {"44"  ,'h'},
        {"444" ,'i'},
        {"5"   ,'j'},
        {"55"  ,'k'},
        {"555" ,'l'},
        {"6"   ,'m'},
        {"66"  ,'n'},
        {"666" ,'o'},
        {"7"   ,'p'},
        {"77"  ,'q'},
        {"777" ,'r'},
        {"7777",'s'},
        {"8"   ,'t'},
        {"88"  ,'u'},
        {"888" ,'v'},
        {"9"   ,'w'},
        {"99"  ,'x'},
        {"999" ,'y'},
        {"9999",'z'},
    };

    
    int g_count=0;
    void backTrack(string pressedKeys,int cur,string s,vector<string> ans) {
        if (cur >= pressedKeys.size()) {
            ans.push_back(s);
            return;
        }
        for (int i = cur; i < pressedKeys.size(); i++) {
            
            string temp2;
            temp2.push_back(pressedKeys.at(i));
            s.push_back(phone_map[temp2]);
            backTrack(pressedKeys, cur + 1, s, ans);
            s.pop_back();

            if (i + 1 < pressedKeys.size() && pressedKeys[i] == pressedKeys[i + 1]) {
                string temp;
                temp.push_back(pressedKeys.at(i));
                temp.push_back(pressedKeys.at(i+1));
                if (phone_map.find(temp) != phone_map.end()) {
                    s.push_back(phone_map[temp]);
                    backTrack(pressedKeys, cur + 2, s, ans);
                    s.pop_back();
                }
            }

            if (i + 2 < pressedKeys.size() && pressedKeys[i] == pressedKeys[i + 1] && 
                pressedKeys[i] == pressedKeys[i + 2]) {
                string temp;
                temp.push_back(pressedKeys.at(i));
                temp.push_back(pressedKeys.at(i + 1));
                temp.push_back(pressedKeys.at(i + 2));
                if (phone_map.find(temp) != phone_map.end()) {
                    s.push_back(phone_map[temp]);
                    backTrack(pressedKeys, cur + 3, s, ans);
                    s.pop_back();
                }
            }
            if (i + 3 < pressedKeys.size() && pressedKeys[i] == pressedKeys[i + 1] &&
                pressedKeys[i] == pressedKeys[i + 2] && 
                pressedKeys[i] == pressedKeys[i + 3]) {
                string temp;
                temp.push_back(pressedKeys.at(i));
                temp.push_back(pressedKeys.at(i + 1));
                temp.push_back(pressedKeys.at(i + 2));
                temp.push_back(pressedKeys.at(i + 3));
                if (phone_map.find(temp) != phone_map.end()) {
                    s.push_back(phone_map[temp]);
                    backTrack(pressedKeys, cur + 4, s, ans);
                    s.pop_back();
                }
            }
        }


    }
    class Solution {
    public:
        int countTexts(string pressedKeys) {
            vector<string> ans;
            
            //return backTrack(pressedKeys, 0);
            return 0;
        };
    };
    void func() {
        Solution s;
        s.countTexts("22233");

    }
}
namespace LS_5 {
    /*5. Longest Palindromic Substring*/
    bool isPal(string s) {
        int i = 0;
        for (; i < s.size() / 2+1; i++) {
            if (s[i] != s[s.size() - i]) {
                break;
            }
        }
        if (i == s.size() / 2)
            return true;
        else
            return false;
    }
    class Solution {
    public:
        string longestPalindrome(string s) {
            
            int n = s.size();
            vector<vector<int>> pal_table;
            pal_table.reserve(n);
            for (int i = 0; i < n; i++) {
                pal_table[i].reserve(n);
            }
            for (int i = 0; i < n; i++) {
                pal_table[i][0] = 1;
            }
            string result_string;

            result_string = s.substr(0, 1);
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    string s_temp = s.substr(j, i);
                    if (isPal(s_temp)) {
                        pal_table[i][j] = max(pal_table[i][j - 1], pal_table[i - 1][j - 1]) + 1;
                        result_string = s_temp;
                    }
                }
            }
            return result_string;
        }
    };
}
namespace LS_241 {
    class Solution {
        int solve(string expression) {
            stack<char> exp;
            for (int i = 0; i < expression.size(); i++) {
                exp.push(expression.at(i));
            }
            string act_exp;
            act_exp.append(")");
            
            int i = 0;
            while (!exp.empty()) {
                char ch = exp.top();
                if (isdigit(ch)) {
                    act_exp.append(1, ch);
                }
                
            }
        }
    public:
        vector<int> diffWaysToCompute(string expression) {

        }
    };
}
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

//namespace CompositeDP
//{
//    class Employee
//    {
//    protected:
//        string m_name;
//    public:
//        Employee(string &name)
//        {
//            m_name = name;
//            cout << m_name<<__FUNCTIONW__ << endl;
//        };
//        Employee(const Employee &rhs)
//        {
//            m_name = rhs.m_name;
//            cout << m_name << __FUNCTIONW__ << endl;
//        };
//        virtual void getSalary()
//        {
//            cout << __FUNCTIONW__ << endl;
//        };
//    };
//    
//    class SoftwareEngineer:public Employee
//    {
//    public:
//        SoftwareEngineer(string &name):Employee(name)
//        {
//            cout << m_name << __FUNCTIONW__ << endl;
//        };
//
//        /*SoftwareEngineer(const SoftwareEngineer &rhs):Employee(rhs.m_name)
//        {
//            
//            cout << m_name << __FUNCTIONW__ << endl;
//        };*/
//        virtual void getSalary()
//        {
//            cout << __FUNCTIONW__ << endl;
//        };
//    };
//
//    class Manager : public Employee
//    {
//        vector<Employee*> reportees;
//    public:
//        void addReportees(Employee *emp)
//        {
//            reportees.push_back(emp);
//        }
//    };
//};

namespace LS_349 {
    class Solution {
        bool binSearch(vector<int> &arr, int elem) {
            int l = 0;
            int r = arr.size();
            
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (arr[mid] == elem) return true;
                else if (elem < arr[mid]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
            return false;
        }
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            vector<int> ans;
            vector<int> nums2_copy(nums2);
            
            sort(nums2_copy.begin(), nums2_copy.end());

            for (auto it : nums1) {
                if (binSearch(nums2_copy, it)) {
                    if (!binSearch(ans,it)) {
                        ans.push_back(it);
                    }
                }
            }
            return ans;

        }
    };
}
namespace LS_240 {
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int r = matrix.size();
            int c = matrix[0].size();
            int i = 0, j = c - 1;

            while (i < r && j >= 0) {
                if (target == matrix[i][j])
                    return true;
                else if (target > matrix[i][j])
                    i++;
                else if (target < matrix[i][j])
                    j--;
            }
            return false;
        }
    };
}
namespace SimpleBinarySearch
{
    int binSearch(vector<int> &arr,int elem)
    {
        int l = arr[0];
        int r = arr.size() - 1;

        while (l <= r) {
            int mid = l + (r-l) / 2;
            
            if (arr[mid] == elem)
                return mid;

            if (arr[mid] < elem)
                l = mid + 1;
            else
                r = mid - 1;
        }
        return -1;
    }
}
namespace LS_1277
{
    class Solution {
        double probabilityInternal(int n) {
            if (n == 1) {
                return 1.0;
            }
            return 1.0;
        }
    public:
        double nthPersonGetsNthSeat(int n) {
            double prob = 0.0;
            for (int i = 1; i <= n; i++) {
                prob = 0.0;
            }
        }
    };
}
namespace LS_1706
{
    class Solution {

    public:
        int ballOut(int row,int col,vector<vector<int>>& grid)
        {
            int max_rows = grid.size();
            int max_cols = grid[0].size();
            
            if (row == max_rows)
                return col;
            
            if (col < 0)
                return -1;

            if (col+1 >= max_cols  && grid[row][col] == 1)
                return -1;
               
            if (col + 1 >= max_cols && grid[row][col] == -1 && grid[row][col-1] == 1)
                return -1;

            if (col + 1 >= max_cols && grid[row][col] == -1 && grid[row][col-1] == -1)
                return ballOut(row+1,col-1,grid);

            if (grid[row][col] == 1 && grid[row][col + 1] == -1 || grid[row][col] == -1 && grid[row][col + 1] == 1)
                return -1;

            if (grid[row][col] == 1 && grid[row][col + 1] == 1)
                return ballOut(row + 1, col + 1,grid);

            if (grid[row][col] == -1 && grid[row][col - 1] == -1)
                return ballOut(row + 1, col - 1, grid);

        }
        vector<int> findBall(vector<vector<int>>& grid) {
            int max_rows = grid.size();
            int max_cols = grid[0].size();
            vector<int> ans_vec;
            for (int i = 0; i < max_cols; i++) {
                int cur = ballOut(0, i, grid);
                ans_vec.push_back(cur);
            }
            return ans_vec;
        }
    };
}
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
        //char *hs = "mmHell";
        //char *n = "ll";
        //int i = strStr(hs, n);
        //cout << "Found at "<<i;
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
namespace Smaller_1365 {
    class Solution {
    public:
        vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
            vector<int> ans;

            for (int i = 0; i < nums.size(); i++) {
                int count = 0;
                for (int j = 0; j < nums.size(); j++) {
                    if (i!=j && nums[i] > nums[j]) {
                        count++;
                    }                    
                }
                ans.push_back(count);
            }
            return ans;
        }
    };
}
namespace FindDiff_389 {
    class Solution {
    public:
        char findTheDifference(string s, string t) {
            auto predicate_func = [](char a, char b) {
                if (a < b)
                    return true;
                return false;
            };
            std::sort(s.begin(), s.end(), predicate_func);
            std::sort(t.begin(), t.end(), predicate_func);

            char ans = 'a';
            for (int j = 0; j < t.size(); j++) {
                if (s[j] != t[j]) {
                    ans = t[j];
                }
            }
            return ans;

        }
    };
}
namespace LAndR_2574 {
    class Solution {
    public:
        vector<int> leftRightDifference(vector<int>& nums) {
            vector<int> ans;

            for (int i = 0; i < nums.size(); i++) {
                int lhs_sum = 0;
                for (int j = 0; j < i; j++) {
                    lhs_sum += nums[j];
                }

                int rhs_sum = 0;
                for (int j = i+1; j < nums.size(); j++) {
                    rhs_sum += nums[j];
                }
                ans.push_back(abs(lhs_sum - rhs_sum));

            }
            return ans;
        }
    };
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
namespace LS_537 {
    class Solution {
    public:
        vector<int> getNumbers(string num1) {
            auto r1 = num1.find_first_of("+");
            auto i1 = num1.substr(r1 + 1, num1.size() - 2);
            string ip = num1.substr(r1 + 1, num1.size() - r1 - 2);
            int imag_1 = 0;
            if (ip.find_first_of("-") != string::npos) {
                imag_1 = stoi(num1.substr(r1 + 2, num1.size() - r1 - 2));
                imag_1 = imag_1 * -1;
            }
            else {
                imag_1 = stoi(num1.substr(r1 + 1, num1.size() - r1 - 2));
            }
            int real_1 = stoi(num1.substr(0, r1));
            

            cout << "num1 real = " << real_1 << endl;;
            cout << "num1 imag = " << imag_1 << endl;;
            vector<int> ans;
            ans.push_back(real_1);
            ans.push_back(imag_1);
            return ans;

        }
        string complexNumberMultiply(string num1, string num2) {
            
            vector<int> n1 = getNumbers(num1);
            vector<int> n2 = getNumbers(num2);

            int real_1 = n1[0] * n2[0];
            int imag_1 = n1[1] * n2[1]*(-1);
            int cp = real_1 + imag_1;
            int ip = n1[0] * n2[1] + n1[1] * n2[0];
            string out = to_string(cp);
            out = out + "+" + to_string(ip) + "i";
            
            return out;

        }
    };
    void func() {
        Solution s;
        string s1("1+-1i");
        string s2("1+-1i");
        string ans = s.complexNumberMultiply(s1,s2);
        cout << ans << endl;
        
    }
}

namespace LS_2160 {
    class Solution {
    public:
        int minimumSum(int num) {
            list<int> arr;
            while (num > 0) {
                arr.push_front(num % 10);
                num = num / 10;
            }
            arr.sort();
            int t1 = arr.front();
            arr.pop_front();
            int t2 = arr.front();
            arr.pop_front();
            int sum = t1 * 10 + (arr.front());
            arr.pop_front();
            sum = sum + (t2 * 10) + arr.front();
            arr.pop_front();
            return sum;

        }
    };
}
namespace LS_2353 {
    struct food_data {
        string name;
        string cuisine;
        int rating;
    };
    struct CompareFoodRating {
        bool operator()(food_data& lhs,food_data& rhs) {
            if (lhs.rating < rhs.rating)
                return true;
            else if (lhs.rating == rhs.rating) {
                if (lhs.name.compare(rhs.name) > 0)
                    return false;
                else if (lhs.name.compare(rhs.name) < 0)
                    return true;
            }
        }
    };
    class FoodRatings {
        map<string, food_data> dishes;
        map < string, priority_queue< food_data, vector<food_data>, CompareFoodRating>> csh;
    public:
        FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
            
            for (int i = 0; i < foods.size(); i++) {
                for (int i = 0; i < foods.size(); i++) {
                    food_data temp;
                    temp.name = foods.at(i);
                    temp.cuisine = cuisines.at(i);
                    temp.rating = ratings.at(i);

                    dishes[temp.name] = temp;

                    priority_queue< food_data, vector<food_data>, CompareFoodRating> temp_pq;

                    auto pq = csh.find(cuisines.at(i));
                    if (pq != csh.end()) {
                        temp_pq = csh[cuisines.at(i)];
                    }
                    temp_pq.push(temp);
                    csh[cuisines.at(i)] = temp_pq;
                }
            }
        }

        void changeRating(string food, int newRating) {
            food_data temp = dishes[food];
            temp.rating = newRating;
            auto it = csh.find(temp.cuisine);
        }

        string highestRated(string cuisine) {
            priority_queue< food_data, vector<food_data>, CompareFoodRating> temp_pq;
            temp_pq = csh[cuisine];
            return temp_pq.top().name;
        }
    };
    void func() {

    }
}
namespace LS_2231 {
    class Solution {
    public:
        int largestInteger(int num) {
            list<int> arr;
            while (num > 0) {
                arr.push_front(num % 10);
                num = num / 10;
            }
            priority_queue<int> odd_heap;
            priority_queue<int> even_heap;
            int n = arr.size();
            while (n) {
                int t = arr.front();
                if (t % 2 == 0)
                    even_heap.push(t);
                else
                    odd_heap.push(t);
                arr.pop_front();
                n--;
            }
            list<int> ans;
            

        }
    };
}
namespace LS_1686 {
    class Solution {
        int getMax(vector<int>& arr) {
            int indx = 0;
            for (int i = 1; i < arr.size(); i++) {
                if (indx > arr[i])
                    indx = i;
            }
            return indx;
        }

    public:
        int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
            int val_a = 0;
            int val_b = 0;
            int n = aliceValues.size();
            while(n>=0) {
                /*Alice turn*/
                int indx = getMax(aliceValues);
                int val = aliceValues[indx];
                val_a += val;
                aliceValues.erase(remove(aliceValues.begin(), aliceValues.end(), val));
                val = bobValues[indx];
                bobValues.erase(remove(bobValues.begin(), bobValues.end(), val));
                n--;
                /*Bob turn*/
                indx = getMax(bobValues);
                val = bobValues[indx];
                val_b += val;
                bobValues.erase(remove(bobValues.begin(), bobValues.end(), val));
                val = aliceValues[indx];
                aliceValues.erase(remove(aliceValues.begin(), aliceValues.end(), val));
                n--;
            }
            if (val_a > val_b)
                return 1;
            else if (val_a < val_b)
                return -1;
            else
                return 0;
        }
    };

    void func() {

    }
}
namespace LS_1985 {
    class Solution {
    public:
        string kthLargestNumber(vector<string>& nums, int k) {
            vector<int> in_nums;
            for (auto i : nums) {
                in_nums.push_back(stoi(i));
            }
            sort(in_nums.begin(), in_nums.end());
            
            string out = to_string(in_nums[in_nums.size()-1-k]);
            return out;

        }
    };
}
/*namespace MergeSort {
    vector<int> ans;
    void divide_arr(vector<int>& arr, int l, int r) {
        if (l >= r) {
            return;
        }
        int m = (l + ((l + r) / 2)); 
        divide_arr(arr, l, m);
        divide_arr(arr, m+1, r);
        merge(arr, l, m,m+1,r);

    }
    void merge(vector<int>& arr, int l_begin,int l_end,int r_begin,int r_end) {
        if (l_begin >= r_begin)
            return;

        int i = 0;
        int j = 0;
        
        while (i < l && r < j) {
            
            if (arr[i] <= arr[j])
                ans.push_back(arr[i]);
            else
                ans.push_back(arr[j]);
            i++;
            j++;
        }
        if (i < l) {
            while (i < l)
                ans.push_back(arr[i]);
        }
        if (j < r) {
            while (j < r)
                ans.push_back(arr[j]);
        }
        
    }
    void func() {
        vector<int> arr{ 5,4,3,2,1 };

    }
}*/
namespace variadic_template_tutorial {
    void print() {
        cout << endl;
    }

    template <typename T> void print(const T& t) {
        cout << "only one ...";
        cout << t << endl;
    }

    template <typename First, typename... Rest> void print(const First& first, const Rest&... rest) {
        cout << "first+rest ...";
        cout << first << ", ";
        print(rest...); // recursive call using pack expansion syntax
    }

    void f() {
        print(); // calls first overload, outputting only a newline
        print(1); // calls second overload

        // these call the third overload, the variadic template,
        // which uses recursion as needed.
        print(10, 20);
        print(100, 200, 300);
        print("first", 2, "third", 3.14159);
    }
}

namespace LS_2099 {
    class Solution {
    public:
        vector<int> maxSubsequence(vector<int>& nums, int k) {
            auto fn = [](int lhs, int rhs) {
                if (lhs < rhs)
                    return true;
                else if (lhs == rhs)
                    return true;
                else
                    return false;
            };
            
            priority_queue<int>  pq;
            for (int i = 0; i < nums.size(); i++) {
                if (pq.size() < k) {
                    pq.push(nums[i]);
                }
                else {
                    if (pq.top() < nums[i]) {
                        pq.pop();
                        pq.push(nums[i]);
                    }
                }
            }
            vector<int> sol;
            for (int i = 0; i < pq.size(); i++) {
                sol.push_back(pq.top());
                pq.pop();
            }
            return sol;
        }
        
    };
}
namespace LS_2208 {
    class Solution {
        bool isGreater(double lhs, double rhs) {
            if ((lhs - rhs) >= DBL_EPSILON)
                return true;
            else
                return false;
        }
        bool isLesser(double lhs, double rhs) {
            if ((lhs - rhs) < DBL_EPSILON)
                return true;
            else
                return false;
        }
        
        int getMax(vector<double>& nums) {
            double val = nums[0];
            int indx = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (isGreater(nums[i],val)) {
                    val = nums[i];
                    indx = i;

                }
            }
            return indx;
        }
        double getTotal(vector<double>& nums) {
            double total = 0;
            for (int i = 0; i < nums.size(); i++) {
                total = total + nums.at(i);
            }
            return total;
        }
    public:
        int halveArray(vector<int>& nums) {
            vector<double> dv;
            for (int i = 0; i < nums.size(); i++) {
                dv.push_back(nums.at(i));    
            }

            double total = getTotal(dv);
            double half = total/2;

            int count = 0;
            while (true) {
                count++;
                int max_num_idx = getMax(dv);    
                dv[max_num_idx] = dv[max_num_idx] / 2;
                double cur_total = getTotal(dv) ;
                if (isLesser(cur_total,half))    {
                    break;
                }
            }
            return count;

        }
    };
    void func() {
        Solution s;
        vector<int> arr{ 5,19,8,1 };
        s.halveArray(arr);
    }
}

namespace LS_1438 {
    int cur_max_len = 0;
    int max_len = 0;
    class Solution {

        bool isSolution() {
            return true;
        }
        int getMaxElem(vector<int>& nums) {
            int val = nums[0];
            
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > val)
                    val = nums[i];
            }
            return val;
        }
        int getMinElem(vector<int>& nums) {
            int val = nums[0];

            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] < val)
                    val = nums[i];
            }
            return val;
        }

        void getCandidates(vector<int>& nums, vector<int>& candidates,int cur) {
            for (int i = 0; i < cur; i++) {
                candidates.push_back(nums[i]);
            }
        }
        

    public:
        void solve(vector<int>& nums,int limit,int cur,vector<int>& sol) {
            if (cur >= nums.size()) {
                if (cur_max_len > max_len)
                    max_len = cur_max_len;
            }
            else {
                cur++;
                vector<int> candidates;
                getCandidates(nums, candidates,cur);
                for (int i = 0; i < candidates.size(); i++) {
                    int mx = getMaxElem(candidates);
                    int mn = getMinElem(candidates);
                    if (abs(mx - mn) <= limit) {
                        cur_max_len++;
                        solve(nums, limit, cur, candidates);
                    }
                    else {
                        candidates.pop_back();
                        solve(nums, limit, cur, candidates);
                    }
                }
            }
        }
         
        int longestSubarray(vector<int>& nums, int limit) {
            return 0;
        }
    };
}

namespace LS_1338 {
    class Solution {
    public:
        
        std::map<int, int> getFreqMap(vector<int>& arr) {
            std::map<int, int> frq_map;
            for (int i = 0; i < arr.size(); i++) {
                auto it = frq_map.find(arr.at(i));
                if (it == frq_map.end()) {
                    frq_map[arr.at(i)] = 1;
                }
                else {
                    frq_map[arr.at(i)] += 1;
                }
            }
            return frq_map;
        }

        int minSetSize(vector<int>& arr) {
            sort(arr.begin(), arr.end());
            std::map<int, int> freq_map = getFreqMap(arr);
            int init_size = arr.size();
            int n = init_size;
            int count = 0;
            /*for (auto it = freq_map.begin(); it != freq_map.end();) {
                if (n - it->second > (init_size/2)) {
                    n = n - it->second;
                    it = freq_map.
                }
            }*/
            
        }
    };
}
namespace LS_43 {
    class Solution {
        string multiply_int(string num, int dig) {
            string prod = "";
            int carry = 0;
            for (int i = 0; i < num.size(); i++) {
                
                int m = pow(10, i);
                int cur_dig = (num.at(num.size() - 1 - i) - '0');
                int cur_prod = cur_dig * dig;
                int act = cur_prod * m;
                prod.append(to_string((cur_prod) % 10));

            }
        }
    public:
        string multiply(string num1, string num2) {
            string out;
            int carry = 0;
            for (int i = 0; i < num1.size(); i++) {

                int dig1 = num1.at(num1.size() - 1 - i)-'0';
                
                
            }
            return out;
        }
    };
    void func() {
        Solution s;
        string num1 = "123";
        string num2 = "456";
        s.multiply(num1, num2);
    }
}

namespace LS_1921 {
    class Solution {
    public:
        int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
            int time = 0;
            int n = dist.size();
            while (!dist.empty()) {
                
                int score = INT16_MAX;
                int mn = -1;
                for (int i = 0; i < dist.size(); i++) {
                    int t = dist[i] - speed[i];
                    if (t < score) {
                        score = t;
                        mn = i;
                    }
                }
                if (score > 0 && (mn>=0 && mn<dist.size())) {
                    auto it_dist = dist.begin();
                    auto it_speed = speed.begin();

                    for (int i = 0; i < mn; i++) {
                        it_dist++;
                        it_speed++;
                    }
                    dist.erase(it_dist);
                    speed.erase(it_speed);
                }
                else {
                    break;
                }
                time++;
            }
            return (n - dist.size());
        }
    };
}
namespace LS_841 {
    class Solution {
        
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            vector<bool> opened_bools;
            for (int i = 0; i < rooms.size(); i++) {
                opened_bools[i] = false;
            }
            deque<vector<int>> my_queue;
            my_queue.push_back(rooms.at(0));
            for (int i = 0; i < rooms.size(); i++) {
                
            }
        }
    };
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
namespace Basic_Calculator_2 {
    class Solution {
        vector<string> getOperands(string s,int npos) {
            vector<string> ans;
            string rightNum = "";
            for (int i = npos+1; i < s.length(); i++) {
                if (isdigit(s.at(i)))
                    rightNum.push_back(s.at(i));
                else
                    break;
            }

            string leftNum = "";
            for (int i = npos -1; i >=0 ; i--) {
                if (isdigit(s.at(i)))
                    leftNum.push_back(s.at(i));
                else
                    break;
            }
            std::reverse(leftNum.begin(), leftNum.end());

            ans.push_back(leftNum);
            ans.push_back(rightNum);
            return ans;
        }
    public:
        int calculate(string s) {
            
            bool still_to_process = true;
            string temp = s;
            while (still_to_process) {
                size_t sz = temp.find('*');
                if (sz != string::npos) {
                    vector<string> nums = getOperands(temp,sz);
                    int ans = stoi(nums[0]) * stoi(nums[1]);
                    string ans_str = to_string(ans);
                    temp.replace(sz - nums[0].length(), nums[0].length() + 1 + nums[1].length(), ans_str.c_str());
                    continue;
                }
                sz = temp.find('/');
                if (sz != string::npos) {
                    vector<string> nums = getOperands(temp, sz);
                    int ans = stoi(nums[0]) / stoi(nums[1]);
                    string ans_str = to_string(ans);
                    temp.replace(sz - nums[0].length(), nums[0].length() + 1 + nums[1].length(), ans_str.c_str());
                    continue;
                }
                sz = temp.find('+');
                if (sz != string::npos) {
                    vector<string> nums = getOperands(temp, sz);
                    int ans = stoi(nums[0]) + stoi(nums[1]);
                    string ans_str = to_string(ans);
                    temp.replace(sz - nums[0].length(), nums[0].length() + 1 + nums[1].length(), ans_str.c_str());
                    continue;
                }
                sz = temp.find('-');
                if (sz != string::npos) {
                    vector<string> nums = getOperands(temp, sz);
                    int ans = stoi(nums[0]) - stoi(nums[1]);
                    string ans_str = to_string(ans);
                    temp.replace(sz - nums[0].length(), nums[0].length() + 1 + nums[1].length(), ans_str.c_str());
                    continue;
                }
                still_to_process = false;
            }
            int ans = stoi(temp);
            return ans;
        }
        string removeSpace(string s) {
            string ans = "";
            for (int i = 0; i < s.length();i++) {
                if (!isspace(s.at(i))) {
                    ans.append(1, s.at(i));
                    i++;
                }
            }
            return ans;
        }
    };
    void driver() {
        Solution s;
        string s1 = "10/2-2";
        cout << "Basic cal2 : "<< s1<<" = " << s.calculate(s1);
    }
}
namespace MiniParser_385 {
    class NestedInteger {};
    class Solution {
    public:
        NestedInteger deserialize(string s) {
            stack<char> ntStack;
            bool bProcessed = false;
            int i = 0;
            while(!bProcessed) {
                if (s.at(i) == '[') {
                    while (isdigit(s.at(i))) {
                        ntStack.push(s.at(i));
                        i++;
                    }
                }
                else if (s.at(i) == ',') {
                    ntStack.push(s.at(i));
                    i++;
                }
                else if (isdigit(s.at(i))) {
                    ntStack.push(s.at(i));
                    i++;
                }
                else if (s.at(i) == ']') {

                }
            }
        }
    };
}
namespace LS_2243_DigitSum {
    class Solution {
    public:
        string digitSum(string s, int k) {
            bool bProcessed = false;
            
            while (!bProcessed) {
                
                vector<string> intermediate_strings;
                for (int i = 0; i < s.length();) {
                    if ((i + k) < s.length())
                    {
                        string temp = s.substr(i, k);
                        intermediate_strings.push_back(temp);
                        i = i + k;
                    }
                    else {
                        string temp = s.substr(i);
                        intermediate_strings.push_back(temp);
                        break;
                    }
                }
                for (int i = 0; i < intermediate_strings.size(); i++) {
                    int sum = 0;
                    string temp_string = intermediate_strings[i];
                    for (int j = 0; j < temp_string.length(); j++) {
                        sum = sum + temp_string.at(j) - '0';
                    }

                }

            }
        }
    };
}
namespace EqualRowAndColPairs {
    class Solution {
        vector<int> getColumn(int n, vector<vector<int>>& grid) {
            vector<int> ans;
            int rows = grid.size();
            int cols = grid[0].size();
            for (int i = 0; i < rows; i++) {
                int temp = grid[i].at(n);
                ans.push_back(temp);
            }
            return ans;
        }
        bool vecEqual(vector<int>& lhs, vector<int>& rhs) {
            bool result = true;
            for (int i = 0; i < lhs.size(); i++) {
                if (lhs[i] != rhs[i]) {
                    result = false;
                    break;
                }
            }
            return result;
        }
    public:
        int equalPairs(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            int count = 0;
            for (int i = 0; i < rows; i++) {
                for (int j = 0; j < cols; j++) {
                    vector<int> cur_col = getColumn(j, grid);
                    if (vecEqual(cur_col, grid[i])) {
                        count++;
                    }
                }
            }
        }
    };
}

namespace Word_Search {
    class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            int rows = board.size();
            int cols = board[0].size();

            for (int i = 0; i < rows; i++) {
                int count = 0;
                for (int j = 0; j < cols; j++) {
                    /*while (count < word.length()) {
                        if()
                    }*/
                }
            }

        }
    };
}
namespace MaxIceCreamBars {
    class Solution {
    public:
        int maxIceCream(vector<int>& costs, int coins) {
            sort(costs.begin(), costs.end());
            if (coins < costs[0])
                return 0;
            
            int sum = 0;
            for (int i = 0; i < costs.size(); i++)
                sum = sum + costs[i];
            if (sum < coins)
                return costs.size();
            int count = 1;
            int i = 0;
            while (coins >= 0 && i < costs.size()) {
                if (costs[i] < coins) {
                    count++;
                    coins = coins - costs[i];
                }
                i++;
            }
            return count;
        }
    };
    void driver() {
        Solution s;
        vector<int> vi = { 7,3,3,6,6,6,10,5,9,2 };
        cout << "Ans : " << s.maxIceCream(vi, 56);
    }
}
namespace LS_1464 {
    class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            int prod = (nums[n - 1] - 1) * (nums[n - 2] - 1);
            return prod;
        }
    };
}
namespace LS_1773 {
    class Solution {
    public:
        int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
            int count = 0;
            for (int i = 0; i < items.size(); i++) {
                if (ruleKey == "type" && items[i][0].compare(ruleValue) == 0) {
                    count++;
                }
                else if (ruleKey == "color" && items[i][1].compare(ruleValue) == 0) {
                    count++;
                }
                else if (ruleKey == "name" && items[i][2].compare(ruleValue) == 0) {
                    count++;
                }
            }
            return count;
        }
    };
}

namespace LS_636 {
    class Solution {
        struct FunctionData {
            int proc_id;
            int duration;
        };
    public:
        
        int getCurTime(vector<string>& logs, int i) {
            string log = logs.at(i);
            size_t pos = log.find_first_of(":");
            int proc_id = stoi(log.substr(0, pos));
            int pos_op = log.find_last_of(":");
            string operation = log.substr(pos + 1, ((pos_op - 1) - (pos)));
            int cur_time = stoi(log.substr(pos_op + 1));
            return cur_time;
        }

        string getOperation(vector<string>& logs, int i) {
            string log = logs.at(i);
            size_t pos = log.find_first_of(":");
            int proc_id = stoi(log.substr(0, pos));
            int pos_op = log.find_last_of(":");
            string operation = log.substr(pos + 1, ((pos_op - 1) - (pos)));
            return operation;
        }

        int getProcId(vector<string>& logs, int i) {
            string log = logs.at(i);
            size_t pos = log.find_first_of(":");
            int proc_id = stoi(log.substr(0, pos));
            return proc_id;
        }

        vector<int> exclusiveTime(int n, vector<string>& logs) {
            map<int, int> time_function_map;
            
            int cur_time = 0;
            int cur_proc_id = 0;
            int prev_time = 0;
            int prev_proc_id = 0;
            
            for (int i = 1; i < logs.size(); i++) {
                cur_time = getCurTime(logs, i);
                cur_proc_id = getProcId(logs, i);
                prev_time = getCurTime(logs, i-1);
                prev_proc_id = getProcId(logs, i-1);
                if (time_function_map.find(prev_proc_id) != time_function_map.end()) {
                    string cur_operation = getOperation(logs, i);
                    if (cur_operation == "start") {
                        time_function_map[prev_proc_id] = time_function_map[prev_proc_id] + (cur_time - prev_time);
                    }
                    else if (cur_operation == "end") {
                        time_function_map[prev_proc_id] = time_function_map[prev_proc_id] + (cur_time - prev_time)+1;
                    }
                }
                else {
                    string cur_operation = getOperation(logs, i);
                    time_function_map[prev_proc_id] = 0;
                    if (cur_operation == "start") {
                        time_function_map[prev_proc_id] = 0;
                    }
                    else if (cur_operation == "end") {
                        time_function_map[prev_proc_id] = time_function_map[prev_proc_id] + (cur_time - prev_time) + 1;
                    }
                }
            }
            /*int cur_i = logs.size() - 1;
            cur_time = getCurTime(logs, cur_i);
            cur_proc_id = getProcId(logs, cur_i);
            prev_time = getCurTime(logs, cur_i - 1);
            prev_proc_id = getProcId(logs, cur_i - 1);

            if (time_function_map.find(cur_proc_id) != time_function_map.end()) {
                string cur_operation = getOperation(logs, cur_i);
                if (cur_operation == "start") {
                    time_function_map[prev_proc_id] = time_function_map[prev_proc_id] + (cur_time - prev_time);
                }
                else if (cur_operation == "end") {
                    time_function_map[prev_proc_id] = time_function_map[prev_proc_id] + (cur_time - prev_time) + 1;
                }
            }
            else {
                string cur_operation = getOperation(logs, cur_i);
                time_function_map[prev_proc_id] = 0;
                if (cur_operation == "start") {
                    time_function_map[prev_proc_id] = time_function_map[prev_proc_id] + (cur_time - prev_time);
                }
                else if (cur_operation == "end") {
                    time_function_map[prev_proc_id] = time_function_map[prev_proc_id] + (cur_time - prev_time) + 1;
                }
            }*/
            vector<int> ans;
            return ans;
        }
    };

    void driver() {
        Solution s;
        vector<string> logs{ "0:start:0","0:start:2","0:end:5","1:start:6","1:end:6","0:end:7" };
        int n = 2;
        s.exclusiveTime(n, logs);
    }
}
namespace LS_540 {
    class Solution {
    public:
        int singleNonDuplicate(vector<int>& nums) {
            list<int> table;
            for (int i = 0; i < nums.size(); i++) {
                auto it = find(table.begin(), table.end(), nums[i]);
                if (it == table.end())
                    table.push_back(nums[i]);
            }
            int sum = 0;
            for (auto it : table) {
                sum += it;
            }
            sum = 2 * sum;
            int act_sum = 0;
            for (int i = 0; i < nums.size(); i++) {
                act_sum += nums[i];
            }
            return (sum - act_sum);

        }
    };
    void driver() {
        vector<int> nums{ 1,1,2,3,3,4,4,8,8 };
        Solution s;
        cout<<"Answer :"<<s.singleNonDuplicate(nums);
    }
}
namespace LS_1684 {
    class Solution {
    public:
        int countConsistentStrings(string allowed, vector<string>& words) {
            std::set<char> allowed_chars;
            for (int i = 0; i < allowed.size(); i++) {
                allowed_chars.insert(allowed.at(i));
            }
            int cc = 0;
            
            for (int i = 0; i < words.size(); i++) {
                string s = words.at(i);
                bool flag = true;
                for (int j = 0; j < s.size(); j++) {
                    auto it = allowed_chars.find(s.at(j));
                    if (it == allowed_chars.end()) {
                        flag = false;
                        break;
                    }
                }
                if (flag)
                    cc++;
            }
        }
    };
}
namespace LS_461 {
    class Solution {
    public:
        int hammingDistance(int x, int y) {
            int hd = 0;
            while (x > 0 && y > 0) {
                int last_bit_x = 1 & x;
                int last_bit_y = 1 & y;
                int res = last_bit_x ^ last_bit_y;
                if (res) hd++;
                x = x >> 1;
                y = y >> 1;
            }
            if (y == 0 && x > 0) {
                while (x) {
                    int last_bit_x = 1 & x;
                    if (last_bit_x) hd++;
                    x = x >> 1;
                }
            }
            if (x == 0 && y > 0) {
                while (y) {
                    int last_bit_y = 1 & y;
                    if (last_bit_y) hd++;
                    y = y >> 1;
                }
            }
            return hd;
        }
    };
}
namespace LS_693 {
    class Solution {
    public:
        bool hasAlternatingBits(int n) {
            int t = n;
            bool flag = true;
            if (n % 2 != 0) {
                int res = 0;
                while (t > 0) {
                    if (res != (t ^ 1)) {
                        flag = false;
                        break;
                    }
                    t = t >> 1;
                    res = ~res;
                }
            }
            else {
                int res = 1;
                while (t > 0) {
                    if (res != (t ^ 1)) {
                        flag = false;
                        break;
                    }
                    t = t >> 1;
                    res = ~res;
                }
            }
            return flag;

        }
    };
}
namespace LS_405 {
    class Solution {
    public:
        string toHex(int num) {
            map<int, string> hex_map;
            hex_map[10] = "a";
            hex_map[11] = "b";
            hex_map[12] = "c";
            hex_map[13] = "d";
            hex_map[14] = "e";
            hex_map[15] = "f";
            string out;
            while (num > 0) {
                int mod = num % 16;
                if (mod > 9) {
                    
                    out.append(hex_map[mod]);
                }
                else {
                    out.append(std::to_string(mod));
                }
                num = num/16;
            }
            
            return out;

        }
    };
}
namespace LS_1356 {
    class Solution {
        int oneCounter(int n) {
            int count = 0;
            int one = 1;
            while (n > 0) {
                int res = one & n;
                if (res) count++;
                n = n >> 1;
            }
            return count;
        };
    public:
        vector<int> sortByBits(vector<int>& arr) {
            sort(arr.begin(), arr.end(), [this](int lhs, int rhs) {
                int l_one_counter = oneCounter(lhs);
                int r_one_counter = oneCounter(rhs);
                if (l_one_counter < r_one_counter)
                    return true;
                else if (l_one_counter == r_one_counter) {
                    return lhs < rhs;
                }
                else
                    return false;
                });

        }
    };
}
namespace LS_2185 {
    class Solution {
    public:
        int prefixCount(vector<string>& words, string pref) {
            int count = 0;
            for (int i = 0; i < words.size(); i++) {
                string cur_word = words.at(i);
                auto it = cur_word.find(pref);
                if (it == 0) {
                    count++;
                }
            }
            return count;
        }
    };
}
/*namespace LS_1528 {

    class Solution {
    public:
        string restoreString(string s, vector<int>& indices) {
            string out;
            for (int i = 0; i < indices.size(); i++) {
                string t = "z";
                out.append(t);
            }
            for (int i = 0; i < indices.size(); i++) {
                out[indices[i]] = s.at(i);
            }
            return out;
        };
    }
}*/
namespace LS_1636 {
    struct num_freq_data {
        int num;
        int freq;
    };
    class Solution {
    public:
        vector<int> frequencySort(vector<int>& nums) {
            
            std::map<int, int> freq_map;

            for (int i = 0; i < nums.size(); i++) {
                auto it = freq_map.find(nums.at(i));
                if (it == freq_map.end()) {
                    freq_map[nums.at(i)] = 1;
                }
                else {
                    freq_map[nums.at(i)] += 1;
                }
            }

            std::sort(nums.begin(), nums.end(), [&freq_map](int lhs, int rhs) {
                if (freq_map[lhs] < freq_map[rhs])
                    return true;
                else if (freq_map[lhs] == freq_map[rhs]) {
                    return lhs > rhs;
                }
                else
                    return false; });
            
        }
    };
}
namespace LS_1859 {
    class Solution {
    public:
        string sortSentence(string s) {

            vector<string> words;
            auto begin = 0;
            while (begin<s.size()) {
                auto it = s.find_first_of(' ', begin);
                if (it != string::npos) {
                    string temp = s.substr(begin, it - begin);
                    words.push_back(temp);
                    begin = it + 1;
                }
                else {
                    words.push_back(s.substr(begin));
                    break;
                }
            }
            std::sort(words.begin(), words.end(), [](string& lhs, string& rhs) {
                int n1 = lhs[lhs.size() - 1] - '0';
                int n2 = rhs[rhs.size() - 1] - '0';
                return n1 < n2;
                });
            string fn_string;
            for (int i = 0; i < words.size(); i++) {
                string s_c = words.at(i);
                s_c.resize(s_c.size() - 1);
                fn_string.append(s_c);
                string sp = " ";
                if(i<words.size()-1)
                fn_string.append(sp);

            }
            
            
            return fn_string;
            
        }
    };
    void fun() {
        string sen = "is2 sentence4 This1 a3";
        Solution s;
        s.sortSentence(sen);
    }
}
namespace LS_2154 {
    class Solution {
    public:
        int findFinalValue(vector<int>& nums, int original) {
            //sort(nums.begin(), nums.end());
            int final_val = original;
            while (true) {
                auto it = find(nums.begin(), nums.end(), final_val);
                if (it == nums.end()) {
                    break;
                }
                else {
                    final_val = final_val * 2;
                }
            }
            return final_val;
        }
    };
}
namespace LS_1913 {
    class Solution {
    public:
        int maxProductDifference(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            int prod1 = nums[0] * nums[1];
            int n = nums.size();
            int prod2 = nums[n - 1] * nums[n - 2];
            return prod2 - prod1;

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
    int f1(string s1, string s2) {
        return 0;
    }
    int f2(string s1, string s2) {
        return 0;
    }
    void func() {
        std::map < string, std::function<int (string, string)>> cmd_map;
        cmd_map["Hello"] = f1;
        cmd_map["world"] = f2;
        cmd_map["Hello"]("Hello","World");
        
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
    /*void func()
    {
        std::thread th1(Thread1);
        std::thread th2(Thread2);
        th2.join();
        th1.join();
        
    }*/
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
            int temp_n = n;
            for (int i = 0; i < 32; i++)
            {
                unsigned int temp_r = (n & (one << i));
                temp_r = temp_r ^ (one << i);
                if(temp_r)
                    result = result | (temp_r << i);
            }
            return result;
        }
    };

}
namespace IsAnagram
{

    class Solution {
    public:
        bool isAnagram(string s, string t) {
            if (s.length() != t.length())
                return false;
            map<char, int> charMap1;
            map<char, int> charMap2;
            for (int i = 0; i < s.length(); i++)
            {
                char ch = s.at(i);
                auto temp = charMap1.find(ch);
                if (temp == charMap1.end())
                {
                    charMap1[ch] = 1;
                }
                else
                {
                    charMap1[ch] ++;
                }
            }
            for (int i = 0; i < t.length(); i++)
            {
                char ch = t.at(i);
                auto temp = charMap2.find(ch);
                if (temp == charMap2.end())
                {
                    charMap2[ch] = 1;
                }
                else
                {
                    charMap2[ch] ++;
                }
            }
            if (charMap1.size() != charMap2.size())
                return false;
            for (auto cm:charMap1)
            {
                auto temp = charMap2.find(cm.first);
                if (temp == charMap2.end() || (temp->second != cm.second))
                    return false;
            }
            return true;
        }
    };
}
namespace SetMatrixZeroes
{
    class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {
            
            for (auto rows:matrix)
            {
                for (auto col : rows)
                {
                    if (col == 0)
                    {
                        for (auto k : rows)
                        {
                            k = 0;
                        }
                        for (auto m : matrix)
                        {
                            m[col] = 0;
                        }
                    }
                }
            }
        }
    };
}

namespace SetMatrxZeroes
{
    class Solution {
    public:
        void setZeroes(vector<vector<int>>& matrix) {

            vector<int> ZeroRows,ZeroCol;
            
            int rows = matrix.size();
            int col = matrix[0].size();

            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < col; j++)
                {
                    if (matrix[i][j] == 0)
                    {
                        ZeroRows.push_back(i);
                        ZeroRows.push_back(j);
                    }
                }
            }

            for (int i = 0; i < ZeroRows.size(); i++)
            {
                for (int j = 0; j < col; j++)
                {
                    matrix[i][j] = 0;
                }
            }
            for (int i = 0; i < ZeroCol.size(); i++)
            {
                for (int j = 0; j < rows; j++)
                {
                    matrix[j][i] = 0;
                }
            }
        }
    };
}
namespace Decode_Ways
{
    class Solution {
    public:
        int helper(string s, int indx)
        {
            if (s.size() == 0)
                return 0;
            if (s.size() == 1)
            {
                return 1;
            }
            if (s.size() == 2)
            {
                int i = stoi(s);
                if (i > 26)
                    return 1;
                else
                    return 2;
            }
            string s1 = s.substr(indx, 2);
            int i = stoi(s1);
            if (i > 26)
                return helper(s.substr(indx+1,s.size()),indx+1);
            else
                return helper(s.substr(indx+1,s.size()),indx+1) + helper(s.substr(indx+2,s.size()),indx+2);

            
        }
        int numDecodings(string s) {
            return helper(s, 0);
        }
    };
}
namespace Sum_3_prob
{
    class Solution {
    public:
        bool isDuplicate(vector<int> lhs, vector<int> rhs)
        {
            return lhs[0] == rhs[0] && lhs[1] == rhs[1] && lhs[2] == rhs[2];
        }

        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            unordered_set<int> num_set;
            
            for (auto i : nums)
                num_set.insert(i);

            int len = nums.size();
            for (int i = 0; i < len-2; i++)
            {
                int num1 = nums[i];
                for (int j = i+1; j < len-1; j++)
                {
                    int num2 = nums[j];

                    int temp = num1 + num2;
                    auto it= std::find(nums.begin() + j, nums.end(), temp*-1);
                    if (it != nums.end())
                    {
                        if (it - nums.begin() != i && it - nums.begin() != j)
                        {
                            vector<int> temp;
                            temp.push_back(num1);
                            temp.push_back(num2);
                            temp.push_back(*it);
                            std::sort(temp.begin(), temp.end());
                            for (auto k : result)
                            {
                                if (!isDuplicate(temp,k))
                                {
                                    result.push_back(temp);
                                }
                            }
                        }
                    }
                }
            }
        }
    };
}
namespace DP_Stair_Climb
{
    class Solution {
    public:
        int climbStairs(int n) {
            if (n == 1)
                return 1;
            if (n == 2)
                return 2;

            int *a = new int[n];
            a[0] = 1;
            a[1] = 2;
            for (int i = 2; i < n; i++)
            {
                a[i] = a[i - 1] + a[i - 2];
            }
            return a[n - 1];
            delete[] a;
        }
    };
}
namespace SpiralMatrix
{
    class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {

            int rows = matrix.size();
            int cols = matrix[0].size();
            vector<int> result;
            int cur_rows = rows;
            int cur_cols = cols ;

            for (int i = 0; i < cur_rows; i++)
            {
                for (int j = 0; j < cur_cols; j++)
                {

                }
            }
        }
    };
}

namespace IsValid
{
    class Solution {
    public:
        bool isValid(string s) {
            
            std::stack<char> validator;
            bool bValid = true;
            for (int i = 0; i < s.length(); i++)
            {
                if (s.at(i) == '(' || s.at(i) == '{' || s.at(i) == '[')
                {
                    validator.push(s.at(i));
                }
                else if (s.at(i) == ')')
                {
                    if (!validator.empty() && validator.top() == '(')
                        validator.pop();
                    else
                    {
                        bValid = false;
                        break;
                    }
                }
                else if (s.at(i) == '}')
                {
                    if (!validator.empty() && validator.top() == '{')
                        validator.pop();
                    else
                    {
                        bValid = false;
                        break;
                    }
                }
                else if (s.at(i) == ']')
                {
                    if (!validator.empty() && validator.top() == '[')
                        validator.pop();
                    else
                    {
                        bValid = false;
                        break;
                    }
                }
            }
            if (!validator.empty())
                bValid = false;

            return bValid;
        }
    };
}
namespace Sort_Char_by_Freq
{
    class Solution {
        struct data
        {
            char c;
            int freq;
        };
    public:
        struct my_comparator
        {
            bool operator()(pair<char,int>& lhs, pair<char, int>& rhs)
            {
                return lhs.second > rhs.second;
            }
        };
    public:
        string frequencySort(string s) {
            map<char, int> char_freq_map;
            for (int i = 0; i < s.size(); i++)
            {
                auto it = char_freq_map.find(s.at(i));
                if (it == end(char_freq_map))
                {
                    char_freq_map[s.at(i)] = 1;
                }
                else
                {
                    char_freq_map[s.at(i)]++;
                }
            }
            vector<pair<char, int>> vec;
            for (auto it : char_freq_map)
            {
                pair<char, int> p{ it.first,it.second };
                vec.push_back(p);
            }

            sort(vec.begin(), vec.end(), [](pair<char, int>& lhs, pair<char, int>& rhs)->bool {
                return lhs.second > rhs.second; });

            string result;
            for (auto it : vec)
            {
                result.append(it.second, it.first);
            }
            return result;

        }
    };
}
namespace Avoid_Flood
{
    class Solution {
    public:
        vector<int> avoidFlood(vector<int>& rains) {
            vector<int> ans;
            list<int> list_lake; 
            
            int dry_day_count = 0;
            for (int i = 0; i < rains.size(); i++) {
                if (rains.at(i) > 0) {
                    int dry_lake = 0;
                    while (dry_day_count) 
                    {
                        auto cur_rainy_day = find(list_lake.begin(), list_lake.end(), rains.at(i));
                        if (cur_rainy_day != list_lake.end())
                        {
                            ans.push_back(*cur_rainy_day);
                            list_lake.erase(cur_rainy_day);
                        }
                        else
                        {
                            dry_lake = list_lake.back();
                            list_lake.pop_back();
                        }
                        dry_day_count--;
                    }
                    list_lake.push_back(rains.at(i));
                    ans.push_back(-1);
                }

                if (rains.at(i) == 0) {
                    dry_day_count++;
                }


            }
        }
    };
}
namespace UniquePaths
{
    class Solution {
    public:
        int solve(int cur_row,int cur_col, int m, int n, map<pair<int,int>,int>& memo)
        {
            if (cur_row == m - 1 && cur_col == n - 1) {
                return 1;
            }

            if (cur_row > m - 1)
                return 0;

            if (cur_col > n - 1)
                return 0;
            
            pair<int, int> p{ cur_row,cur_col };
            if (memo.find(p) != memo.end())
                return memo[p];

            int mov_right =  solve(cur_row + 1, cur_col, m, n, memo);
            int mov_down =  solve(cur_row , cur_col+1, m, n, memo);

            memo[p] = mov_right + mov_down;

            return mov_right + mov_down;
                
        }

        int uniquePaths(int m, int n) {

            map<pair<int, int>, int> memo;
            return solve(0, 0, m, n, memo);
        }
    };
}
namespace TaskSch
{
    class Solution {
    public:
        int leastInterval(vector<char>& tasks, int n) {
            vector<char> sch;
            map<char, list<char>> task_list;
            for (int i = 0; i < tasks.size(); i++)
            {
                auto it = task_list.find(tasks[i]);
                if (it == task_list.end())
                {
                    list<char> lst;
                    lst.push_back(tasks[i]);
                    task_list[tasks[i]] = lst;
                }
                else
                {
                    list<char> lst = task_list[tasks[i]];
                    lst.push_back(tasks[i]);
                }
            }
            vector<pair<char, list<char>>> ts_list;
            for (auto it : task_list)
            {
                pair p = make_pair(it.first, it.second);
                ts_list.push_back(p);
            }
            
            /*for (int i = 0; i < n; i++)
            {
                ts_list
            }*/
        }
    };
}
namespace JumpGame
{
    class Solution {
        bool solve(vector<int>& nums, int cur)
        {
            if (cur == nums.size() - 1)
                return true;
            if (cur >= nums.size())
                return false;
            bool result = false;
            for (int i = 1; i <= nums[cur]; i++)
            {
                result = solve(nums, cur+i);
            }
            return result;

        }
    public:
        bool canJump(vector<int>& nums) {
            return solve(nums, 0);
        }
    };
}

namespace Multilevel_DLL
{
    
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


    class Solution {
    public:
        void solve(Node* cur, Node* prevNode, Node* nextNode)
        {
            if (cur->child != nullptr)
            {
                cur->next = cur->child;

            }
            else
            {
                solve(cur->next, cur, cur->next->next);
            }
        }
        Node* flatten(Node* head) {
            
        }
    };
}

namespace Pattern_132
{
    class Solution {
    public:
        int nge(int num, vector<int>& nums2)
        {
            stack<int> orig_s;
            for (auto i : nums2)
                orig_s.push(i);

            int ans = -1;
            
            while (!orig_s.empty())
            {
                if (orig_s.top() == num)
                    break;

                if (orig_s.top() > num)
                {
                    ans = orig_s.top();
                }
                orig_s.pop();
            }
            return ans;
        }
        bool find132pattern(vector<int>& nums) {

            for (int i = 0; i < nums.size(); i++)
            {
                int temp = nge(nums[i], nums);
                if (temp != -1)
                {
                    
                }
            }

        }
    };
}
namespace Contaminated_BTree
{
 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
    class FindElements {
        TreeNode* m_root;
        list<int> mylist;
    
        void solve(TreeNode* cur_root,TreeNode* parent)
        {
            
            if (cur_root == nullptr)
                return;
            if (cur_root->val == -1)
            {
                if (parent->left == cur_root)
                {
                    cur_root->val = parent->val * 2 + 1;
                }
                if (parent->right == cur_root)
                {
                    cur_root->val = parent->val * 2 + 2;
                }
                mylist.push_back(cur_root->val);
                solve(cur_root->left, cur_root);
                solve(cur_root->right, cur_root);
            }
        }

        bool findInternal(TreeNode* root,int val)
        {
            if (root == nullptr)
                return false;

            if (val == root->val)
                return true;
            
            if (root->left != nullptr)
                return findInternal(root->left, val);
            
            if (root->right != nullptr)
                return findInternal(root->right, val);

        }
    public:
        FindElements(TreeNode* root) {
            m_root = root;
            if (root->val == -1)
            {
                root->val = 0;
                mylist.push_back(0);
                if (root->left != nullptr)
                {
                    solve(root->left,root);
                }
                if (root->right != nullptr)
                {
                    solve(root->right,root);
                }
            }
        }

        bool find(int target) {
            //return findInternal(m_root, target);
            auto it = std::find(mylist.begin(), mylist.end(), target);
            if (it == mylist.end())
                return false;
            else
                return true;
        }
    };

    /**
     * Your FindElements object will be instantiated and called as such:
     * FindElements* obj = new FindElements(root);
     * bool param_1 = obj->find(target);
     */
}
namespace DelNodes_RetForest
{
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        
    };
    class Solution {
    public:
        
        vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {

        }
    };
}
namespace ValidSudoko
{
    class Solution {
    public:
        bool isRowValid(vector<char>& board_data) {
            
            int cols = board_data.size();
            set<char> cur_row_Sudoko;
            bool result=true;
            vector<char> vec_cur_row = board_data;
            for (auto i : vec_cur_row) {
                auto it = cur_row_Sudoko.insert(i);
                if (i != '.' && it.second == false) {
                    result = false;
                    break;
                }
            }
            return result;
        }

        vector<char> get_3x3_cell(vector<vector<char>>& board, int row_offset,int col_offset) {
            vector<char> result;

            for (int i = row_offset; i < row_offset + 3 && row_offset < board.size(); i++) {
                for (int j = col_offset; j < col_offset + 3 && col_offset <board[0].size(); j++) {
                    vector<char> temp = board[i];
                    char ch = temp.at(j);
                    result.push_back(ch);
                }
            }
            return result;

        }

        bool isValidSudoku(vector<vector<char>>& board) {
            bool result = true;
            int num_rows = board.size();
            for (int i = 0; i < num_rows; i++) {
                result = isRowValid(board[i]);
                if (!result)
                    return result;
            }
            result = true;
            for (int i = 0; i < num_rows; i++) {
                for (int j = 0; j < board[0].size();) {
                    vector<char> temp = get_3x3_cell(board, i, j);
                    result = isRowValid(temp);
                    if (!result)
                        return result;
                    j=j+3;
                }
                i = i + 3;
            }
            return result;

        }
    };
}
namespace MinJumps
{
    class Solution {
        bool isForbidden(vector<int>& forbidden,int x)
        {
            return false;
        }
        
    public:
        
        int solve(vector<int>& forbidden, int a, int b, int x,int cur)
        {
            if (cur == x)
                return 0;

            if (cur > x)
                return -1;

            if (cur < x)
                return 1 + solve(forbidden, a, b, x, cur + a);
            
        }
        int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
            int jumps = 0;
            //return solve(forbidden, a, b, x, 0, jumps);
            return 0;
        }
    };
}
namespace Triangle
{
    class Solution {
        int solve(vector<vector<int>>& triangle, int row, int indx)
        {
            if (row >= triangle.size())
                return 0;

            else if (row + 1 < triangle.size() - 1)
                return min(triangle[row][indx] + solve(triangle, row + 1, indx), triangle[row][indx] + solve(triangle, row + 1, indx + 1));
            else
                return 0;
            
        }
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            return solve(triangle, 0, 0);
        }
    };
}
namespace NextRightPtr
{
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };
    

        class Solution {
        public:
            Node* connect(Node* root) {

                Node* cur = root;
                deque<Node*> dq;

                dq.push_back(cur);
                cur->right = NULL;
                int count = 1;
                int level = 0;
                while (!dq.empty())
                {
                    Node* temp = dq.front();
                    dq.pop_front();
                    int level_node_count = pow(2, level);
                    
                    if (level_node_count == count)
                    {
                        cout << "#" << endl;
                        level++;
                    }
                    
                    if (temp->left != NULL)
                    {
                        dq.push_back(temp->left);
                    }
                    
                    if (temp->right != NULL)
                    {
                        dq.push_back(temp->right);
                    }
                }



            }
    };
}
namespace TopKFreq
{
    struct comparator
    {
        bool operator()(pair<int, int>& lhs, pair<int, int>& rhs)
        {
            return lhs.second < rhs.second;
        }
    };
    class Solution {

    public:
        vector<int> topKFrequent(vector<int>& nums, int k) {
            unordered_map<int, int> us;

            for (int i = 0; i < nums.size(); i++)
            {
                if (us.find(nums.at(i)) != us.end())
                {
                    us[nums.at(i)] = us[nums.at(i)] + 1;
                }
                else
                {
                    us[nums.at(i)] = 1;
                }
            }
            priority_queue<pair<int,int>,vector<pair<int,int>>,comparator> pq;
            for (auto it : us)
            {
                pair<int, int> p{ it.first,it.second };
                pq.push(p);
            }
            vector<int> result;

            for (int i = 0; i < k; i++)
            {
                result.push_back(pq.top().first);
                pq.pop();
            }
            return result;
        }
    };
}
namespace Rem_Stones_to_min
{
    class Solution {
    public:
        int minStoneSum(vector<int>& piles, int k) {

            priority_queue<int> pq;
            for (auto i : piles)
                pq.push(i);

            for (int i = 0; i < k; i++)
            {
                int temp = pq.top();
                pq.pop();
                temp = floor(temp / 2);
                pq.push(temp);
            }
            int res = 0;
            for (int i = 0; i < pq.size(); i++)
            {
                res = res + pq.top();
                pq.pop();
            }
            return 0;

        }
    };
}
namespace SeatResMgr
{
    struct comparator
    {
        bool operator()(int lhs, int rhs)
        {
            return lhs > rhs;
        }
    };
    class SeatManager {
        priority_queue<int,vector<int>,comparator> pq;
    public:
        SeatManager(int n) {
            for (int i = 1; i <= n; i++)
            {
                pq.push(i);
            }
        }

        int reserve() {
            int ans = pq.top();
            pq.pop();
            return ans;
        }

        void unreserve(int seatNumber) {
            pq.push(seatNumber);
            
        }
    };


}

namespace Reorg_string
{
    struct comparator
    {
        bool operator()(char a, char b)
        {
            return (a != b);
        }
    };
    class Solution {
    public:
        string reorganizeString(string s) {
            int n = s.length();
            stack<char> s1;
            stack<char> s2;
            s1.push(s.at(0));
            for (int i = 1; i < n; i++)
            {

                if (s1.top() == s.at(i))
                {
                    if (!s2.empty() && s2.top() != s.at(i))
                    {
                        char ch = s2.top();
                        s2.pop();
                        s1.push(ch);
                    }
                    if (s2.top() == s.at(i))
                    {
                        s2.push(s.at(i));
                    }
                }
                else
                {
                    s1.push(s.at(i));
                }
            }
        }
    };
}
namespace Word_break
{
    class Solution {
    public:

        bool solve(string s, int start,int cur_pos,int end,vector<string>& wordDict) {
            
            if (cur_pos == end)
            {
                string s1 = s.substr(start, cur_pos);
                auto it = find(wordDict.begin(), wordDict.end(), s1);
            }

            if (start == end)
                return true;

            string s1 = s.substr(start, cur_pos);
            

            auto it = find(wordDict.begin(), wordDict.end(), s1);
            if (it != wordDict.end())
            {
                return solve(s, cur_pos+1, cur_pos + 2, end, wordDict);
            }
            else
            {
                return solve(s, start, cur_pos + 1, end, wordDict);
            }
            return false;
        }

        bool wordBreak(string s, vector<string>& wordDict) {

        }
    };
}
namespace ST_CPU
{
    class Solution {
    public:
        vector<int> getShortestJobAt(int enqueTime, vector<vector<int>>& tasks)
        {
            for (auto it : tasks)
            {
                if (it[0] == enqueTime)
                    return it;
            }
        }
        vector<int> getOrder(vector<vector<int>>& tasks) {

            sort(tasks.begin(), tasks.end(), [](vector<int> &lhs, vector<int>& rhs)->bool {
                return lhs[0] < rhs[0];
            });
            deque<vector<int>> dq;
            vector<int> sj = getShortestJobAt(tasks[0][0],tasks);
            
        }
    };

}

namespace k_pair_smallest_sum
{
    class Solution {
        struct data
        {
            int u1;
            int v1;
            int sum;
        };
        struct compare_data
        {
            bool operator()(struct data& a, struct data &b)
            {
                return a.sum < b.sum;
            }
        };
    public:
        vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
            
            auto comp = [](struct data a, struct data b)->bool {return a.sum <= b.sum; };
            
            priority_queue<data,vector<data>,decltype(comp)> pq;
            for (int i = 0; i < nums1.size(); i++)
            {
                for (int j = 0; j < nums2.size(); j++)
                {
                    struct data temp;
                    temp.u1 = nums1[i];
                    temp.v1 = nums2[j];
                    temp.sum = temp.u1 + temp.v1;
                    pq.push(temp);
                }
            }
            vector<vector<int>> result;
            for (int i = 0; i < k; i++)
            {
                struct data t = pq.top();
                pq.pop();
                vector<int> temp{ t.u1,t.v1 };
                result.push_back(temp);
               
            }
            return result;
        }
    };
}
namespace Kth_Largest
{
    class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            
            priority_queue<int> pq;
            for (int i = 0; i < nums.size(); i++)
            {
                pq.push(nums[i]);
            }
            
            for (int i = 0; i < k - 1; i++)
                pq.pop();

            return pq.top();
        }
    };
}
namespace LL_Rearrange
{
    
 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    class Solution {
    public:
        void reorderList(ListNode* head) {

            deque<ListNode*> dq_Node;
            
            ListNode* temp = head;

            while (temp != nullptr)
            {
                dq_Node.push_back(temp);
                temp = temp->next;
            }

            ListNode* cur = head;
            dq_Node.pop_front();

            bool front = false;
            while (!dq_Node.empty())
            {
                if (!front)
                {
                    ListNode* fut = dq_Node.back();
                    cur->next = fut;
                    cur = cur->next;
                    dq_Node.pop_back();
                    front = !front;
                }
                else
                {
                    ListNode* fut = dq_Node.front();
                    cur->next = fut;
                    cur = cur->next;
                    dq_Node.pop_front();
                    front = !front;
                }
            }
        }
    };
}
namespace BTreeLOT
{

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    class Solution {
    public:
        vector<vector<int>> levelOrder(TreeNode* root) {

            TreeNode* cur = root;
            deque<TreeNode*> tree_queue;
            vector<vector<int>> result;
            
            if (cur != nullptr)
                tree_queue.push_back(cur);

            
                
                while (!tree_queue.empty())
                {
                    vector<int> temp;
                    int count = 0;
                    for (auto it : tree_queue)
                    {
                        temp.push_back(it->val);
                        count++;
                    }
                    result.push_back(temp);

                    while (count)
                    {
                        TreeNode* tn = tree_queue.front();
                        tree_queue.pop_front();
                        if (tn->left != nullptr)
                            tree_queue.push_back(tn->left);
                        if (tn->right != nullptr)
                            tree_queue.push_back(tn->right);
                        count--;
                    }
                    
                    
                }
            

        }
    };
}
namespace Intersection_Two_ll
{

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

    class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            
            if (headA == NULL || headB == NULL)
                return NULL;

            unordered_set<ListNode*> list;
            ListNode* temp = headA;
            while (temp != NULL)
            {
                list.insert(temp);
                temp = temp->next;
            }
            temp = headB;
            bool found = false;
            while (temp != NULL)
            {
                auto it = list.find(temp);
                if (it != end(list))
                {
                    found = true;
                    break;
                }
                temp = temp->next;
            }
            if (found)
                return temp;
            else
                return NULL;

        }
    };
}

namespace Length_last_word
{
    class Solution {
    public:
        int lengthOfLastWord(string s) {
            int len_last_word = 0;
            int len_cur_word = 0;
            for (int i = 0; i < s.size(); i++)
            {
                if (s.at(i) == ' ')
                    continue;
                else
                {
                    size_t temp = s.find(' ', i);
                    if (temp == string::npos)
                    {
                        len_cur_word = s.size() - i;
                        break;
                    }
                    else
                    {
                        len_cur_word = temp - i;
                        i = temp;
                    }

                }
            }
            return len_cur_word;
        }
    };
}
//namespace IsAnagram
//{
//    class Solution {
//    public:
//        bool isPalindrome(string s) {
//            
//            s.erase(std::remove_if(s.begin(), s.end(), [](char c) {
//                return !isdigit(c);
//            }),s.end());
//            
//            transform(s.begin(), s.end(), s.begin(),tolower);
//            bool result = true;
//            int end = s.length() - 1;
//            for (int start = 0; start <= end; start++,end--)
//            {
//                if (s.at(start) != s.at(end))
//                {
//                    result = false;
//                    break;
//                }
//            }
//            return result;
//        }
//    };
//}
namespace GroupAnagrams
{
    class Solution {
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs) {
            unordered_map<string, vector<string>> m;
            for (int i = 0; i < strs.size(); i++)
            {
                string s = strs[i];
                sort(s.begin(), s.end());
                m[s].push_back(strs[i]);
            }
            vector<vector<string>> res;
            for (auto i : m)
            {
                res.push_back(i.second);
            }
            return res;
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
            sort(intervals.begin(), intervals.end(), [](auto lhs, auto rhs) {
                return lhs[0] < rhs[0]; });
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
namespace CPP_Templates_Complete_Guide {

    template <typename T>
    const T& max(const T& a, const T& b) {
        return a > b ? a : b;
    }

    template <typename T>
    class Base {
    protected:
        void bar() {
            cout << "bar" << endl;
        }
    };
    template<typename T>
    class Derived : Base<T> {
    public:
        void foo() {
            cout << "foo" << endl;
            this->bar();
        }
    };
    template<typename T,typename CONT=std::deque<T>>
    class Stack {

        CONT cont;
    public:
        template <typename CONT>
        void push(const T& val) {
            cont.push();
        }
        void pop() {
            cont.pop();
        }
        const T& front() {
            return cont.front();
        }
    };
    class Sample {
        float s = 5.5;
    public:
        Sample() {

        };
        ~Sample() {

        }
    };

    template <typename T>
    void printColl(T const& cont) {
        typename T::const_iterator pos(T.begin());
        typename T::const_iterator end(T.end());

        while (pos != end) {
            cout << *pos << "\t";
            ++pos;
        }
        cout << endl;
    }

    template <typename T>
    class TypeSize {
    public:
        static size_t const value = sizeof(T);
    };
    
    template <typename T>
    class ExposeTypeName {
    public:
        typedef typename T::value_type Type;
    };
    typedef stack<int> IntStack;
    template <typename T> class ElementT;

    template <typename T>
    class ElementT<std::stack<T>> {
    public:
        typedef T Type;
    };
    template <>
    class Stack < std::string> {
        std::deque<string> cont;
    public:
        void push(string const& elem) {
            cont.push_back(elem);
        }
    };

    template <typename T1,typename T2>
    class MyClass {};

    template<typename T>
    class MyClass<T,T>{};
    
    template<typename T>
    class MyClass<T, int> {};
    
    template <typename T,typename CONT=std::deque<T>>
    class MyStStack {};

    template <typename T,int MAX_SIZE=5>
    class Stack_5_Size {
        std::deque<T> cont;
        int max_size;
    public:
        Stack_5_Size() :max_size(MAX_SIZE) {};
        void push(T const& obj);
        /*template <typename T2,int MAX_SIZE_T2>
        Stack_5_Size<T> const& operator=(Stack_5_Size<T2, MAX_SIZE_T2> const& rhs) {
            return *this;
        }*/
    };
    
    template <typename T,int MAX_SIZE>
    void Stack_5_Size<T, MAX_SIZE>::push(T const& obj) {
        if (cont.size() >= MAX_SIZE) {
            throw overflow_error;
        }
    }

    void type_name_driver_15_2() {
        std::cout << "Type size int " << TypeSize<int>::value << endl;
        std::cout << "Type size char " << TypeSize<char>::value << endl;
        cout << typeid(ExposeTypeName<vector<int>>).name();
    }
    template <typename C>
    typename C::value_type sumColl(C const& coll) {
        typename C::value_type sum = C::value_type();
        typename C::const_iterator pos = coll.begin();
        typename C::const_iterator end = coll.end();
        while (pos != end) {
            sum += (*pos);
            ++pos;
        }
        return sum;
    }
     template <typename T1,typename T2>
     T1 const& max(T1 const& a, T2 const& b) {
         return a > b ? a : b;
     }

    template <typename T>
    T const& max(T const& a, T const& b,T const& c) {
        return max(max(a, b), c);
    }
    //template <typename T, typename Cont>
    //void fill( C const& cont, T const& val = T()) {
    //     
    //}
    void func() {
        Stack_5_Size<int, 10> si_10;
        Stack_5_Size<int, 20> si_20;
        //si_10 = si_20;
        vector<int> vi{1,2,3,4,5};
        cout<<sumColl(vi);
        max(4, 5, 6);
        Sample ss;
        Stack<int, vector<int>> mystack;
        int i = 5;
        int j = 10;
        const int& ri1 = i;
        i = 20;
        //ri1 = 10;
        //ri1 = j;
        int& const ri2 = i;
        ri2 = 100;
        ri2 = j;
        cout << "max(4,5)::" << max(i, j) << endl;
        max<int>(4.5, 5);
    }
}
namespace Fraction_Sample {
    template <typename T>
    class Fraction {
        typedef T Type;
        Type nr_;
        Type dr_;
    public:
        Fraction(Type const& nr, Type const& dr) :nr_(nr), dr_(dr) {
        };

        Fraction<Type> operator+(Fraction<Type> const& op2) {
            Fraction<Type> temp;
            if (op2.dr_ == dr_) {
                temp.dr_ = dr_;
                temp.nr_ = nr_+op2.nr_;
            }
            else {
                temp.nr_ = (nr_ * op2.dr_) + (op2.nr_ * dr_) ;
                temp.dr_ = (op2.dr_ * dr_);
            }
        };

    };
}
namespace Rem_Dup_Sorted_List {
    /**
 * Definition for singly-linked list.*/
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    class Solution {
    public:
        ListNode* deleteDuplicates(ListNode* head) {
            if (head == nullptr|| head->next == nullptr)
                return head;
            ListNode* cur = head;

            while (cur != nullptr) {
                ListNode* fut = cur->next;
                if (fut != nullptr) {
                    if (fut->val == cur->val) {
                        ListNode* temp = fut;
                        cur->next = temp->next;
                        delete fut;
                    }
                    else {
                        cur = cur->next;
                    }
                }
                else {
                    break;
                }
            }
            return head;
        }
    };
}
namespace Pascal_triangle {
    class Solution {
        vector<vector<int>> ans;
    public:
        vector<vector<int>> generate(int numRows) {
            if (numRows == 1) {
                vector<int> temp;
                temp.push_back(1);
                ans.push_back(temp);
            }
            if (numRows == 2) {
                vector<int> temp;
                temp.push_back(1);
                temp.push_back(1);
                ans.push_back(temp);
            }
            //for(int i=0;i< numRows)
        }
        
    };
}
namespace Plus_One {
    class Solution {
    public:
        int plusOneRec(vector<int>& digits, int indx) {
            if (indx == digits.size() - 1) {
                if (1 + digits[indx] > 9) {
                    digits[indx] = 0;
                    return 1;
                }
                else {
                    digits[indx] = 1 + digits[indx];
                    return 0;
                }
                    
            }
                
            if (plusOneRec(digits, indx + 1) + digits[indx] > 9) {
                digits[indx] = 0;
                return 1;
            }
            else {
                digits[indx] = plusOneRec(digits, indx + 1) + digits[indx];
                return 0;
            }
        }

        vector<int> plusOne(vector<int>& digits) {
            plusOneRec(digits, 0);
        }
    };
}
namespace ExcelColumn {
    class Solution {
    public:
        int titleToNumber(string columnTitle) {
            int col = 0;
            int len = columnTitle.size();
            for (int i = 0; i < len; i++) {
                
                col = col + (columnTitle.at(len - i - 1) - 'A' + 1) * (pow(26, i));
            }
            return col;
        }
    };
}
namespace ReverseInt {
    class Solution {
    public:
        int reverse(int x) {
            int num_of_digits = 0;
            int temp_x = x;
            while (temp_x > 0) {
                temp_x = temp_x / 10;
                num_of_digits++;
            }
            num_of_digits--;
            int ans = 0;

            while (x>0) {
                int last_digit = x % 10;
                ans = ans + last_digit * pow(10, num_of_digits);
                num_of_digits--;
                x = x / 10;
            }
            return ans;
        }
    };
    void driver() {
        Solution s;
        int rev = s.reverse(123);
        cout << "Reverse int : "<<rev << endl;
    }
}
namespace Count_Consistent_1684 {
    class Solution {
    public:
        int countConsistentStrings(string allowed, vector<string>& words) {
            //map<char, int> table;
            //for (int i = 0; i < 26; i++) {
            //    table[i]
            //}
            return 0;
        }
    };
}
namespace ToLower {
    class Solution {
    public:
        string toLowerCase(string s) {
            string ans = "";
            for (int i = 0; i < s.length();i++) {
                if (s.at(i) >= 'A' && s.at(i) <= 'Z') {
                    char t = s.at(i) + ('a'-'A');
                    ans.append(&t,1);
                }
                else {
                    char ch = s.at(i);
                    ans.append(& ch,1);
                }
            }
            return ans;
        }
    };
    void driver() {
        Solution s;
        cout << "To lower test" << s.toLowerCase("ABC");
    }
}

namespace RotateLinkedList {

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
    class Solution {
    public:
        ListNode* rotate1(ListNode* head) {
            ListNode* last = head;
            ListNode* last_but_one = nullptr;
            while (last->next != nullptr) {
                last_but_one = last;
                last = last->next;
            }
            last->next = head;
            last_but_one->next = nullptr;
            return last;
        }
        ListNode* rotateRight(ListNode* head, int k) {
            while (k) {
                head = rotate1(head);
                k--;
            }
            return head;

        }
    };
}
namespace ReverseWordsinaString {
    class Solution {
    public:
        string reverseWords(string s) {
            
            size_t found = s.find_last_of(" ");
            string ans;
            while (found != string::npos) {
                string rhs = s.substr(found+1);
                ans.append(rhs);
                ans.append(" ");
                s = s.substr(0, found);
                found= s.find_last_of(" ");
            }
            ans = ans + s;
            return ans;
        }

    };
    string removeConsecutiveSpace(string s) {
        string ans="";
        for (int i = 0; i < s.length();) {
            if (isalnum(s.at(i))) {
                
                ans.append(1,s.at(i));
                i++;
            }
            else if(isspace(s.at(i))){
                if(i>0)
                    ans.append(1,s.at(i));
                int t = i;
                while (isspace(s.at(t))) {
                    t++;
                }
                i = t;
            }
        }
        return ans;
    }
    void driver() {
        Solution s;
        string s1 = " the    sky is blue";
        s1 = removeConsecutiveSpace(s1);
        string ans = s.reverseWords(s1);
        cout << "answer:" << ans;
    }
}
namespace Largest_Number {
    class Solution {
    public:
        struct Number {
            string num;
            bool operator<(Number& rhs) {
                int len1 = num.length();
                int len2 = rhs.num.length();
                int len = (len1<len2)? len1:len2;
                bool gt = true;
                int i;
                for (i = 0; i < len; i++) {
                    if (num.at(i) - '0' < (rhs.num.at(i) - '0')) {
                        gt = false;
                        break;
                    }
                }
                //for (int j = i; j < len2; j++) {
                //    if (num.at(i - 1) - '0' < (rhs.num.at(j) - '0')) {
                //        gt = false;
                //        break;
                //    }
                //}
                return gt;
            }
        };
        string largestNumber(vector<int>& nums) {
            vector<Number> vn;
            for (int i = 0; i < nums.size(); i++) {
                Number n;
                string s = to_string(nums[i]);
                n.num = s;
                vn.push_back(n);
            }
            string ans;
            sort(vn.begin(), vn.end());
            for (int i = 0; i < vn.size(); i++) {
                ans.append(vn.at(i).num);
            }
            return ans;
        }
    };
    void driver() {
        Solution s;
        vector<int> str{ 31,3 };
        cout << "answer" << s.largestNumber(str);
    }
}
namespace MaxProductofWordLengths {
    class Solution {
    public:

        int maxProduct(vector<string>& words) {
            
            int max_prod = 0;
            for (int i = 0; i < words.size()-1; i++) {
                for (int j = 0; j < words[i].size(); j++) {
                    for (int k = i + 1; k < words.size(); k++) {
                        auto pos = std::find(words[k].begin(), words[k].end(), words[i].at(j));
                        //if(pos == )
                    }
                }

            }
            return max_prod;
        }
    };

}
namespace TownJudge {
    class Solution {
    public:
        bool is_everybody_trusts(int n, int trusted, vector<int>& trustees) {
            bool result = false;
            int num_trustees = trustees.size();
            if (num_trustees < n - 1)
                return result;
            int count = 1;
            while (count != trusted && find(trustees.begin(), trustees.end(), count) != trustees.end())
                count++;
            if (count == n - 1)
                result = true;
            return result;
        }
        int findJudge(int n, vector<vector<int>>& trust) {
            
            map<int, vector<int>> trust_map;
            for (int i = 0; i < trust.size(); i++) {
                vector<int> rel = trust[i];
                trust_map[rel[1]].push_back(rel[0]);
            }
            int ans = -1;
            auto itBegin = trust_map.begin();
            auto itEnd = trust_map.end();
            int count = 1;
            for (; itBegin != itEnd; itBegin++) {
                if (trust_map.find(itBegin->first) == trust_map.end() && is_everybody_trusts(n,itBegin->first, itBegin->second)) {
                    ans = count;
                    break;
                }
            }
            return ans;
        }
    };
    void driver() {
        vector<vector<int>> vm{ {1,3},{2,3} };
        Solution s;
        cout<<"ans = "<< s.findJudge(3, vm);

    }
}

namespace Percentage_letter {
    class Solution {
    public:
        int percentageLetter(string s, char letter) {

        }
    };
}
namespace FractiontoRecurringDecimal {
    class Solution {
    public:
        string fractionToDecimal(int numerator, int denominator) {
            string ans="";
            int q = numerator / denominator;
            int rem = numerator % denominator;
            unordered_map<int, int> rem_quo_map;
            if (rem == 0) {
                ans.append(to_string(q));
                return ans;
            }
            ans.append(to_string(q));
            ans += ".";
            unordered_map<int, int> mp;
            while (rem != 0) {
                if (mp.find(rem) != mp.end()) {
                    int pos = mp[rem];
                    ans.insert(pos, "(");
                    ans += ')';
                    break;
                }
                else {
                    mp[rem] = ans.length();
                    rem *= 10;
                    q = rem / denominator;
                    rem = rem % denominator;
                    ans += to_string(q);
                }
            }
            return ans;
        }
    };

    void driver()
    {
        Solution s;
        cout << "fraction to decimal : 14/3 : " << s.fractionToDecimal(1444, 10);
    }
}

namespace SuminaMatrix {
    class Solution {
    public:
        int getLargestPos(vector<int> nums) {
            int largest = nums[0];
            int pos = 0;
            for (int i = 1; i < nums.size(); i++) {
                if (nums[i] > largest) {
                    largest = nums[i];
                    pos = i;
                }
            }
            return pos;
        }

        int matrixSum(vector<vector<int>>& nums) {
            int rows = nums.size();
            int cols = nums[0].size();
            int score = 0;
            for (int i = 0; i < rows; i++) {
                vector<int> largest_in_row;
                int largest_elem_pos = getLargestPos(nums[i]);
                int elem = nums[i][largest_elem_pos];
                nums[i].erase(nums[i].begin()+largest_elem_pos);
                largest_in_row.push_back(elem);
                int temp = getLargestPos(largest_in_row);
                score += largest_in_row[temp];
            }
            return score;
        }
    };

    void driver() {
        vector<vector<int>> vs;
    }


}
namespace Subdomain_Visit_Count_811 {
    class Solution {
    public:
        vector<string> subdomainVisits(vector<string>& cpdomains) {
            unordered_map<string, int> domains_table;

            for (int i = 0; i < cpdomains.size(); i++) {
                string cur_cp_domain = cpdomains.at(i);
                size_t domain_index = cur_cp_domain.find_last_of(".");
                while (domain_index != string::npos) {
                    
                    string domain_rhs = cur_cp_domain.substr(domain_index);
                    auto domains_table_index = domains_table.find(domain_rhs);
                    if (domains_table_index != domains_table.end()) {
                        domains_table[domain_rhs]++;
                    }
                    else {
                        domains_table[domain_rhs] = 1;
                    }
                    domain_index = cur_cp_domain.find_last_of(".", domain_index);
                }
            }
        }
    };
    void driver() {

        unordered_map<string, int> domains_table;
        vector<string> cpdomains{ "9001 discuss.leetcode.com" };
        size_t spc_indx = cpdomains.at(0).find(" ");
        string domain_count = cpdomains.at(0).substr(spc_indx);
        string domain = cpdomains.at(0).substr(spc_indx + 1);
        size_t indx = domain.find(".");
        string lhs = domain.substr(0, indx);
        string rhs = domain.substr(indx + 1);
        size_t indx2 = rhs.find(".");
        string rhs2 = rhs.substr(indx2 + 1);
    }

}
namespace Reverse_Int_7 {
    class Solution {
    public:
        int reverse(int x) {
            int temp_x = abs(x);
            int digits = 0;
            while (temp_x > 0) {
                digits++;
                temp_x = temp_x / 10;
            }
            digits--;
            temp_x = abs(x);
            int ans = 0;
            while (temp_x > 0) {
                int digit = temp_x % 10;
                ans += digit * pow(10, digits);
                digits--;
                temp_x = temp_x / 10;
            }
            if (x < 0)
                ans = ans * (-1);
            return ans;
        }
    };
    void driver() {
        Solution s;
        s.reverse(123);
    }
}
namespace Reverse_words_557 {
    class Solution {
    public:
        string reverseWords(string s) {
            int start_indx = 0;
            string ans;
            while (true) {
                size_t spc_indx = s.find(" ", start_indx);

                if (spc_indx == string::npos) {
                    cout << " Word is" << s.substr(start_indx);
                    string rev_str = s.substr(start_indx);
                    reverse(rev_str.begin(), rev_str.end());
                    ans += rev_str;
                    break;
                }

                cout << " Word is" << s.substr(start_indx, spc_indx - start_indx) << endl;
                string rev_str = s.substr(start_indx, spc_indx - start_indx);
                reverse(rev_str.begin(), rev_str.end());
                ans += rev_str;
                ans += " ";
                start_indx = spc_indx + 1;
            }
            return ans;
        }
    };

    void driver() {
        string s = "Let's take LeetCode contest";
        int start_indx = 0;
        string ans;
        while (true) {
            size_t spc_indx = s.find(" ", start_indx);
            
            if (spc_indx == string::npos) {
                cout << " Word is" << s.substr(start_indx);
                string rev_str = s.substr(start_indx);
                reverse(rev_str.begin(), rev_str.end());
                ans += rev_str;
                break;
            }
                
            cout << " Word is" << s.substr(start_indx, spc_indx - start_indx) << endl;
            string rev_str = s.substr(start_indx, spc_indx - start_indx);
            reverse(rev_str.begin(), rev_str.end());
            ans += rev_str;
            ans += " ";
            start_indx = spc_indx + 1;
        }
        cout << " ANswer is <<" << ans << endl;;
    }
}
namespace MinStringAfterRemovingSubstrings {
    class Solution {
    public:
        int minLength(string s) {
            while (true) {
                size_t foundAB = s.find("AB");
                if (foundAB != string::npos) {
                    s.erase(foundAB, 2);
                }
                else {
                    size_t foundCD = s.find("CD");
                    if (foundCD != string::npos) {
                        s.erase(foundCD, 2);
                    }
                    else {
                        break;
                    }
                }
                
            }
            return s.length();

        }
    };
}

namespace SwapNode {

     struct ListNode {
         int val;
         ListNode *next;
         ListNode() : val(0), next(nullptr) {}
         ListNode(int x) : val(x), next(nullptr) {}
         ListNode(int x, ListNode *next) : val(x), next(next) {}
     };
 
    class Solution {
    public:
        ListNode* swapNodes(ListNode* head, int k) {
            ListNode* temp = head;
            int n = 0;
            while (temp != nullptr) {
                n++;
                temp = temp->next;
            }

            temp = head;
            ListNode* swap_left = nullptr;
            for (int i = 0; i < k && temp != nullptr; i++) {
                swap_left = temp;
                temp = temp->next;
            }
            ListNode* swap_right = nullptr;
            for (int i = 0; i < n-k && temp != nullptr; i++) {
                swap_right = temp;
                temp = temp->next;
            }
 

        }
    };
}
namespace RotateArray{
    class Solution {
    public:
        void rotate(vector<int>& nums, int k) {
            stack<int> int_stack;
            int len = nums.size();
            for (int i = 0; i < k; i++) {
                int_stack.push(nums[len - 1 - i]);
            }
            vector<int> ans;
            while(!int_stack.empty()) {
                ans.push_back(int_stack.top());
                int_stack.pop();
            }
            for (int i = 0; i < len - k; i++) {
                ans.push_back(nums[i]);
            }
            for (int i = 0; i < len; i++)
                nums[i] = ans[i];
        }
    };
}
namespace TruncateSentence {
    class Solution {
    public:
        string truncateSentence(string s, int k) {
            int words = 0;
            auto it = s.begin();
            auto itend = s.end();
            size_t found = s.find_first_of(" ");
            string ans;
            while (found != std::string::npos) {
                words++;
                if (words<k)
                    found = s.find_first_of(" ", found + 1);
                else
                {
                    s.find_last_of(" ");
                    //ans = s.substr(0, )
                }
            }
            cout << "no. of words" << words<<endl;
            size_t endWord = s.find_last_of(" ");
            string s1 = s.substr(0, endWord);
            return s1;
        }
    };
    void driver() {
        Solution s1;
        string s = s1.truncateSentence(" Hello how are you Contestant", 4);
        cout << " truncated string" << s << endl;;
        
    }
}

namespace HeightReorder {
    class Solution {
        struct PeopleData {
            string name;
            int height;
            bool operator<(struct PeopleData& rhs) {
                if (height < rhs.height)
                    return false;
                return true;
            }
        };
    public:
        vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
            vector<PeopleData> people_data_list;
            for (int i = 0; i < names.size(); i++) {
                PeopleData pd;
                pd.name = names[i];
                pd.height = heights[i];
                people_data_list.push_back(pd);
            }
            sort(people_data_list.begin(), people_data_list.end());
            vector<string> ans;
            for (auto it : people_data_list) {
                ans.push_back(it.name);
            }

            return ans;
        }
    };
    void driver() {
        vector<string> vs = { "Mary","John","Emma" };
        vector<int>    vi = { 180,165,170 };
        Solution s;
        vector<string> va = s.sortPeople(vs, vi);
        cout << "Sorted names" << endl;
        for (auto it : va) {
            cout << it << endl;
        }
    }
}
namespace StringMult {
    class Solution {
    public:
        string multiply(string num1, string num2) {
            int len1 = num1.length();
            int len2 = num2.length();
            int prod = 0;
            for (int i = 0; i < len1; i++) {
                int temp = 0;
                for (int j = 0; j < len2; j++) {
                    temp = temp + ((num1.at(len1 - i - 1) - '0')) * ((num2.at(len2 - j - 1) - '0')*pow(10,j));
                }
                
            }
        }
    };
}
namespace RobotReturnsToOrigin {
    class Solution {
    public:
        bool judgeCircle(string moves) {
            pair<int, int> coordinates;
            coordinates.first = 0;
            coordinates.second = 0;
            for (int i = 0; i < moves.length(); i++) {
                char ch = moves.at(i);
                switch (ch) {
                case 'R':
                    coordinates.first = coordinates.first + 1;
                    break;
                case 'L':
                    coordinates.first = coordinates.first -1;
                    break;
                case 'U':
                    coordinates.second = coordinates.second + 1;
                    break;
                case 'D':
                    coordinates.second = coordinates.second - 1;
                    break;

                }

            }
            if (coordinates.first == 0 && coordinates.second == 0)
                return true;
            return false;
        }
    };
}
namespace TopKFrequentWords {
    class Solution {
    public:
        struct comparator
        {
            bool operator()(pair<string, int>& lhs, pair<string, int>& rhs)
            {
                return lhs.second < rhs.second;
            }
        };
        vector<string> topKFrequent(vector<string>& words, int k) {


            map<string, int> freq_map;
            for (int i = 0; i < words.size(); i++) {
                auto it = freq_map.find(words.at(i));
                if (it == freq_map.end()) {
                    freq_map[words.at(i)] = 1;
                }
                else {
                    freq_map[words.at(i)] += 1;
                }
            }
            priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;
            for (auto it: freq_map)
            {
                pair<string, int> p{ it.first,it.second };
                pq.push(p);
            }
            vector<string> result;

            for (int i = 0; i < k; i++)
            {
                result.push_back(pq.top().first);
                pq.pop();
            }
            return result;
        }
    };
    void driver() {
        vector<string> words{ "i","love","leetcode","i","love","coding" };
        Solution s;
        s.topKFrequent(words, 2);
    }
}

namespace Count_Teams_1395 {


    class Solution {
    public:
        int ans;
        bool isValidSol(vector<int> ans) {

        }
        void getCandidates(vector<int>& curCandidates, vector<int>& rating, int cur_pos) {

        }
        int backtrack(vector<int>& rating, int index, vector<int>& cur_candidates) {
            if (isValidSol(cur_candidates)) {
                ans++;
            }
            else {
                cur_candidates.push_back(rating[index]);
                getCandidates(cur_candidates, rating, index);
                for (int i = 0; i < cur_candidates.size(); i++) {

                }
            }
        }
        int numTeams(vector<int>& rating) {
            vector<int> ans;
            return backtrack(rating, 0, ans);
        }
    };
}

namespace LS_1669 {

    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
 
    class Solution {
    public:
        ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
            ListNode* cur = list1;
            ListNode* prev = nullptr;
            ListNode* temp = list1;
            
            while (temp->val != a) {
                prev = temp;
                temp = temp->next;
            }
            ListNode* a_node = temp;
            
            temp = list1;
            while (temp->val != b) {
                temp = temp->next;
            }
            ListNode* b_node = temp;
            if(prev!=nullptr)
                prev->next = list2;

            temp = list2;
            ListNode* prev_2 = nullptr;
            while (temp != nullptr) {
                prev_2 = temp;
                temp = temp->next;
            }
            prev_2->next = b_node->next;
            return list1;
        }
    };
}

namespace LS_1685 {
    class Solution {
    public:
        vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
            vector<int> sum;
            sum.reserve(nums.size());
            for (int i = 0; i < nums.size(); i++) {
                sum.push_back(0);
            }

            for (int i = 0; i < nums.size(); i++) {
                for (int j = i; j < nums.size(); j++) {
                    int diff = nums[i] - nums[j];
                    diff = abs(diff);
                    sum[i] = sum[i] + diff;
                    sum[j] = sum[j] + diff;
                }
            }
            return sum;
        }
    };
    void driver() {
        vector<int> nums{2,3,5};
        Solution s;
        s.getSumAbsoluteDifferences(nums);
    }
}
namespace LS_1695 {
    class Solution {
    public:
        int maximumUniqueSubarray(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            list<int> uniq_list;
            for (int i = 0; i < nums.size(); i++) {
                auto it = find(uniq_list.begin(), uniq_list.end(), nums[i]);
                if (it == uniq_list.end())
                    uniq_list.push_back(nums[i]);
            }
            int sum = 0;
            for (auto it : uniq_list) {
                sum = sum + it;
            }
            return sum;
        }
    };
    void driver() {
        vector<int> nums{ 187,470,25,436,538,809,441,167,477,110,275,133,666,345,411,459,490,266,987,965,429,166,809,340,467,318,125,165,809,610,31,585,970,306,42,189,169,743,78,810,70,382,367,490,787,670,476,278,775,673,299,19,893,817,971,458,409,886,434 };
        Solution s;
        s.maximumUniqueSubarray(nums);
    }
}
namespace LS_1903 {
    class Solution {
    public:
        string largestOddNumber(string num) {
            for (int i = 0; i < num.length(); i++) {
                int cur_digit = num.at(i)-'0';
                 
            }
        }
    };
}
namespace LS_118 {
    class Solution {
    public:
        vector<vector<int>> generate(int numRows) {
            vector<vector<int>> ans;
            vector<int> temp;
            temp.push_back(1);
            ans.push_back(temp);
            if (numRows == 1)
                return ans;
            temp.push_back(1);
            ans.push_back(temp);
            if (numRows == 2)
                return ans;
            
            for (int i = 3; i < numRows; i++) {
                vector<int> cur;
                vector<int> prev = ans[i - 2];
                cur.push_back(1);
                for (int j = 1; j < i-1; j++) {
                    cur.push_back(prev[j] + prev[j - 1]);
                }
                cur.push_back(1);
                ans.push_back(cur);
            }
            return ans;
        }
    };
    void driver() {
        Solution s;
        s.generate(5);
    }
}
namespace LS_299 {
    class Solution {
    public:
        string getHint(string secret, string guess) {
            int cows = 0;
            int bulls = 0;
            list<int> bull_marker;

            

            for (int i = 0; i < guess.length(); i++) {
                char ch = guess.at(i);
                if (ch == secret.at(i)) {
                    bull_marker.push_back(i);
                }
            }
            list<int> cow_marker;

            for (int i = 0; i < guess.length(); i++) {
                char ch = guess.at(i);
                size_t pos = secret.find(ch);
                if ( pos != string::npos && find(bull_marker.begin(),bull_marker.end(),pos) == bull_marker.end() &&
                    find(cow_marker.begin(), cow_marker.end(), pos) == cow_marker.end()) {
                    cow_marker.push_back(pos);
                }
            }
            string ans;

            ans = to_string(bull_marker.size()) + "A" + to_string(cow_marker.size()) + "B";
            return ans;
        }
    };

    void driver() {
        Solution s;
        s.getHint("11", "01");
    }
}
namespace LS_826 {
    class Solution {
    public:
        void getAbleJobs(int worker_ability, vector<int>& difficulty, vector<int>& profit_candidates,vector<int> & profit) {
            for (int i = 0; i < difficulty.size(); i++) {
                if (difficulty[i] <= worker_ability) {
                    profit_candidates.push_back(profit[i]);
                }
            }
        }
        
        int getMaxProfit(vector<int>& profit) {
            if (profit.empty())
                return 0;
            int max_profit = profit[0];
            for (int i = 1; i < profit.size(); i++)
                if (max_profit < profit[i])
                    max_profit = profit[i];
            return max_profit;
        }

        int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {

            int sum = 0;
            for (int i = 0; i < worker.size(); i++) {
                vector<int> profit_candidates;
                getAbleJobs(worker[i], difficulty, profit_candidates, profit);
                int cur = getMaxProfit(profit_candidates);
                sum = sum + cur;
            }
            return sum;
        }
    };

    void driver() {
        vector<int> diff{ 2,4,6,8,10 };
        vector<int> prof{ 10,20,30,40,50 };
        vector<int> work{ 4,5,6,7 };
        Solution s;
        s.maxProfitAssignment(diff, prof, work);
    }
}

namespace LS_611 {
    class Solution {
    public:
        int triangleNumber(vector<int>& nums) {
            if (nums.size() < 3)
                return 0;
            sort(nums.begin(), nums.end());
            int count = 0;
            for (int i = 0; i < nums.size()-2; i++) {
                for (int j = i + 1; j < nums.size() - 1; j++) {
                    int s1 = nums[i];
                    int s2 = nums[j];
                    for (int k = j + 1; k < nums.size(); k++) {
                        if ( (s1 + s2)>nums[k]) {
                            count = count + 1;
                        }
                        else {
                            break;
                        }
                            
                    }
                }
            }
            return count;
        }
    };
    void driver() {
        Solution s;
        vector<int> vi{ 2,2,3,4 };
        cout<<"ans::"<<s.triangleNumber(vi);
    }
}

namespace LS_861 {
    class Solution {

    public:
        void flipRow(vector<vector<int>>& grid, int row) {
            int cols = grid[0].size();
            for (int j = 0; j < cols; j++) {
                if (grid[row][j] == 0) {
                    grid[row][j] = 1;
                }
                else if (grid[row][j] == 1) {
                    grid[row][j] = 0;
                }
            }
        }
        int getValRow(vector<vector<int>>& grid, int row) {
            int cols = grid[0].size();
            int val = 0;
            for (int i = 0; i < cols; i++) {
                if (grid[row][i] == 1) {
                    val = val + pow(2, cols - i - 1);
                }
            }
            return val;
        }
        void flipCol(vector<vector<int>>& grid, int col) {
            int rows = grid.size();
            for (int j = 0; j < rows; j++) {
                if (grid[j][col] == 0) {
                    grid[j][col] = 1;
                }
                else if (grid[j][col] == 1) {
                    grid[j][col] = 0;
                }
            }
        }
        int getValCol(vector<vector<int>>& grid, int col) {
            int rows = grid.size();
            int val = 0;
            for (int i = 0; i < rows; i++) {
                if (grid[i][col] == 1) {
                    val = val + pow(2, rows - i - 1);
                }
            }
            return val;
        }
        int matrixScore(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();
            for (int i = 0; i < rows; i++) {
                int cur_val = getValRow(grid, i);
                flipRow(grid, i);
                int flip_val = getValRow(grid, i);
                if (flip_val < cur_val) {
                    flipRow(grid, i);
                }
            }
            for (int i = 0; i < cols; i++) {
                int cur_val = getValCol(grid, i);
                flipCol(grid, i);
                int flip_val = getValCol(grid, i);
                if (flip_val < cur_val) {
                    flipCol(grid, i);
                }
            }
            int ans = 0;
            for (int i = 0; i < rows; i++) {
                int cur_val = getValRow(grid, i);
                ans += cur_val;
            }
            return ans;
        }
    };
    void driver() {
        Solution s;
        vector<vector<int>> vi{ 
            {0,0,1,1},
            {1,0,1,0},
            {1,1,0,0} };

        cout<<"Answer is :: "<<s.matrixScore(vi);
    }
}

namespace LS_763 {
    class Solution {
    public:
        vector<int> partitionLabels(string s) {
            unordered_map<char, int> char_table;

            for (int i = 0; i < s.length(); i++) {
                char_table[s.at(i)] = i;
            }
            int init = -1;
            int maxi = 0;
            vector<int> ans;
            for (auto itBegin = char_table.begin(); itBegin != char_table.end();
                ++itBegin) {
                //maxi = std::max(maxi, itBegin->second);
                //ans.push_back(max - init);
                //init = max;
                //max = itBegin->second;
            }
            return ans;
        }
    };
}
namespace LS_78 {
    class Solution {
    public:
        vector<int> getBinRep(int n) {
            vector<int> ans;
            while (n) {
                ans.push_back(n % 2);
                n = n / 2;
            }
            return ans;
        }
        vector<vector<int>> subsets(vector<int>& nums) {
            int len = nums.size();
            int n = pow(2, len);
            vector<vector<int>> ans;
            vector<int> za;
            ans.push_back(za);

            for (int i = 1; i < n; i++) {
                vector<int> cur_set;
                vector<int> bin_rep = getBinRep(i);
                for (int j = 0; j < bin_rep.size();j++) {
                    if (bin_rep[j] == 1) {
                        cur_set.push_back(nums[j]);
                    }
                }
                ans.push_back(cur_set);
            }
            return ans;
        }
    };
    void driver() {
        vector<int> num{ 1,2,3 };
        Solution s;
        s.subsets(num);
    }
}
namespace LS_875 {
    class Solution {
    public:
        int getHours(vector<int>& piles, int speed) {
            int total_hours = 0;
            for (int i = 0; i < piles.size(); i++) {
                total_hours += ceil(double(piles[i]) / speed);
            }
            return total_hours;
        }

        int minEatingSpeed(vector<int>& piles, int h) {
            int sum = 0;
            for (int i = 0; i < piles.size(); i++) {
                sum += piles[i];
            }
            int avg = ceil((double)sum / piles.size());

            while (true) {
                int req = getHours(piles, avg);
                if (req <= h) {
                    return avg;
                }
                avg++;
            }
            return avg;
        }
    };
    void driver() {
        vector<int> piles1{ 3,6,7,11 };
        vector<int> piles2{ 30,11,23,4,20 };
        Solution s;
        cout<<"ans ::{ 3,6,7,11 }:"<<s.minEatingSpeed(piles1, 8);
        cout<<"ans ::{ 30,11,23,4,20 }:"<<s.minEatingSpeed(piles2, 5);

    }
}
namespace Empl_importance_690 {
    class Employee {
    public:
        int id;
        int importance;
        vector<int> subordinates;
    };

    class Solution {
    public:
        int getImportance(vector<Employee*> employees, int id) {
            auto employee = find_if(employees.begin(), employees.end(), [id](Employee* cur_empl) {
                return (cur_empl->id == id);
                });
            int ans = (*employee)->importance;
            vector<int> reportees = (*employee)->subordinates;

            deque<int> employee_queue;
            for (int i = 0; i < reportees.size(); i++) {
                employee_queue.push_back(reportees.at(i));
                
            }
            while (!employee_queue.empty()) {

            }
        }
    };
}

namespace Distant_barcodes_1054 {
    class Solution {
        
    public:
        vector<int> rearrangeBarcodes(vector<int>& barcodes) {
            map<int, int> elem_counter;
            int len = barcodes.size();
            for (auto i : barcodes) {
                auto elem = elem_counter.find(i);
                if (elem == elem_counter.end()) {
                    elem_counter[i] = 1;
                }
                else {
                    elem_counter[i]++;
                }
            }
            vector<int> ans;
            map<int, int>::iterator itBegin = elem_counter.begin();
            map<int, int>::iterator itEnd = elem_counter.end();
            
            int count = 0;
            int type_of_elems = elem_counter.size();
             
            while (count < len) {
                if (itBegin->second > 0) {
                    ans.push_back(itBegin->first);
                    count++;
                    itBegin++;
                    itBegin->second--;
                }
                else {
                    itBegin++;
                }
                if (itBegin == itEnd) {
                    itBegin = elem_counter.begin();
                }
            }
        }
    };
}

namespace Qt_experiment {
    template<typename T>
    class MyArray {
    private:
        T* _arr;
        size_t _size;
    public:
        MyArray() :_arr(nullptr), _size(0) {};
        
        MyArray(int n) :_arr(new T[n]), _size(n) {};

        template <typename T>
        MyArray(int n,T &val) :_arr(new T[n]), _size(n) {
            for (int i = 0; i < _size; i++) {
                _arr[i] = val;
            }
        };
        
        MyArray(const MyArray<T> &rhs)  {
            _size = rhs._size;
            _arr = new T[rhs._size];

            for(int i=0;i<_size;i++)
                _arr[i] = rhs._arr[i];
        };

        template<typename T>
        MyArray<T>& operator=(const MyArray<T>& rhs) {
            if (rhs == *this) {
                return *this;
            }

            delete[] _arr;
            _size = 0;

            _arr = new T[rhs._size];
            _size = rhs._size;

            for (int i = 0; i < rhs._size; i++) {
                _arr[i] = rhs._arr[i];
            }

            return *this;
        };

        template<typename T>
        MyArray(MyArray<T>&& rhs) {
            swap(_arr, rhs._arr);
            swap(_size, rhs._size);
        };

        template<typename T>
        MyArray<T>& operator=(MyArray<T>&& rhs) {
            if (rhs == *this)
                return *this;

            swap(_arr, rhs._arr);
            swap(_size, rhs._size);
            
            return *this;
        };

        
        ~MyArray() {
            delete[] _arr;
            _size = 0;
        };

        template <typename T>
        T& operator[](int i) {
            assert(_arr != nullptr);

            if (i > _size)
                throw std::out_of_range("Index out of range");

            return _arr[i];
        }


        template <typename T>
        void removeFirst() {
            for (int i = 0, j = i + 1; i < _size-1; i++) {
                _arr[i] = _arr[j];
            }
            delete _arr[_size]-1;
            _size = _size - 1;
        }



    };

    void driver() {
        int x = 5;
        MyArray<int> m1(10,x);
        MyArray<int> m2 = m1;
        MyArray<int> m3;
        m3 = m2;

    }
}

namespace CountNegativeInSortedMatrix_1351 {
    class Solution {
    public:
        int countNegatives(vector<vector<int>>& grid) {
            int rows = grid.size();
            int cols = grid[0].size();

            auto first_nve_num = [](vector<int>& row) {
                int indx = 0;
                for (int i = 0; i < row.size(); i++) {
                    if (row[i] < 0) {
                        indx = i;
                        break;
                    }
                }
                return indx;
            };
            int count = 0;
            for (int i = 0; i < rows; i++) {
                int indx = first_nve_num(grid[i]);
                count = count + (cols - indx + 1);
            }
            return count;
        }
    };
}
namespace DivArrayInKConsSets {
    class Solution {
    public:
        bool isPossibleDivide(vector<int>& nums, int k) {
            int n = nums.size();
            if (n % k != 0)
                return false;
            multiset<int> nums_list;
            for (int i=0;i< nums.size();i++)
                nums_list.insert(nums[i]);
            
            
            int cur_set_count = 0;
            list<int> cur_set;

            for (int i = 0; i < n; i++) {
                int elem = nums[i];
                if (cur_set.empty()) {
                    cur_set.push_back(elem);
                    nums_list.erase(elem);
                }
                else {
                    int last_elem = cur_set.back();
                    auto next_elem = nums_list.find(last_elem + 1);
                    if (next_elem == nums_list.end())
                        return false;
                    cur_set.push_back(*next_elem);
                    nums_list.erase(elem);
                    if (cur_set.size() == k) {
                        cur_set.clear();
                    }
                }
                
            }
            return true;
        }
    };
    void driver() {
        vector<int> nums{ 1,2,3,3,4,4,5,6 };
        int k = 4;
        Solution s;
        s.isPossibleDivide(nums, k);
    }
}
namespace MDSN_tutorial {


    std::optional<string> sample(int v) {
        string str;
        if (v > 0) {
            str = "hello";
            return { str };
        }
        return {};
    }

    void driver() {
        auto m = sample(-5);
        if (m.has_value())
            cout << m.value() << endl;
        else
            cout << "m doesn't hv value" << endl;
    }
}



namespace ReduceArraySize_1338 {
    class Solution {
    public:
        struct Comparator {
            bool operator()(pair<int, int>& lhs, pair<int, int>& rhs) {
                return lhs.second < rhs.second;
            }
        };
        int minSetSize(vector<int>& arr) {
            
            unordered_map<int, int> arr_count;
            
            for (int i = 0; i < arr.size(); i++) {
                auto found = arr_count.find(arr[i]);

                if (found == arr_count.end())
                    arr_count[arr[i]] = 1;
                else
                    arr_count[arr[i]]++;
            }

            priority_queue<pair<int, int>, vector<pair<int, int>>, Comparator> pq;
            
            unordered_map<int, int>::iterator itBegin = arr_count.begin();
            unordered_map<int, int>::iterator itEnd = arr_count.end();
            for (; itBegin != itEnd; itBegin++) {
                std::pair<int, int> temp(make_pair(itBegin->first, itBegin->second));
                pq.emplace(temp);
            }
            int count = 0;
            int sum = 0;
            int mid = arr.size() / 2;


            while (!pq.empty()) {
                sum = pq.top().second + sum;
                count++;
                pq.pop();
                if (sum > mid)
                    break;
            }
            return count;
        }
    };
    void driver() {
        vector<int> arr{ 3,3,3,3,5,5,5,2,2,7 };
        Solution s;
        s.minSetSize(arr);
    }
}
namespace MV_Copy_Working {
    class Employee {
    public:
        int id;
        Employee(int i):id(i) {
            cout << "Employee CTOR:" <<id<< endl;
        }
        Employee(const Employee & rhs) {
            id = rhs.id;
            cout << "Employee Copy CTOR" <<rhs.id<< endl;
        }
        Employee(Employee&& rhs) noexcept{
            id = rhs.id;
            rhs.id = 0;
            cout << "Employee move CTOR"<<id << endl;
        }

        Employee& operator =(const Employee& rhs) {
            id = rhs.id;
            return *this;
        }
        ~Employee() {

        }
    };

    unique_ptr<Employee> makeEmpl(int i) {
        return make_unique<Employee>(Employee(i));
    }

    void f(vector<Employee>& ve,Employee e) {
        cout << "Processing in f" << endl;  
        for_each(ve.begin(), ve.end(), [](auto &emp) {
            cout << "Emp id:: " << emp.id << endl;;
            });
    }

    Employee makeEmployee(int id) {
        Employee e(id);
        return e;
    }

    std::array<Employee, 5> make_five_employees() {
        std::array< Employee, 5> emp_arr{1,2,3,4,5};
        return emp_arr;

    }

    class MyCount {
    public:
        int x_;
        MyCount(int x):x_(x) {};
    };

    class Sample {
        const int& x;
    public:
        Sample(const int& i) :x(i) {
            const int* pi = &i;
            const int* px = &x;
        };
        void print_x() {
            cout << "print x" << x << endl;;
        }

        string getHello() {
            string s("Hello");
            return s;
        }
    };

    vector<shared_ptr<Employee>> getEmployeeSharedArray(vector< shared_ptr<Employee>> vsp2) {
        cout << "getEmployeeSharedArray--------" << endl;
        shared_ptr<Employee> spe1 = make_shared<Employee>(Employee(35));
        shared_ptr<Employee> spe2 = make_shared<Employee>(Employee(45));
        shared_ptr<Employee> spe3 = make_shared<Employee>(Employee(55));
        vsp2.push_back(spe1);
        vsp2.push_back(spe2);
        vsp2.push_back(spe3);
        return vsp2;
    }
    
    void driver() {
        deque<double> ddq1{ 1,2,3 };
        auto print = [](deque<double> ddq) {
            cout << "printing dequeu***********" << endl;
            for (auto i : ddq)
                cout << i << " ";
        };
        print(ddq1);
        deque<double> ddq2 = ddq1;
        print(ddq2);

        Sample s(5);
        s.print_x();
        const char* res = s.getHello().c_str();
        printf("Hello %s", res);
        vector<Employee> ve;
        Employee e1(5), e2(6), e3(7), e(10);
        cout << "Calling push back" << endl;
        ve.push_back(Employee(5));
        ve.push_back(Employee(6));
        ve.push_back(Employee(7));

        f(ve, e);
        cout << "After f "<< e.id<< endl;
        Employee er=10;

        cout << "e1 :" << ve[0].id << endl;;
        cout << "e2 :" << ve[1].id << endl;;
        cout << "e3 :" << ve[2].id << endl;;
        cout << "Make employee" << endl;
        Employee a(15);
        a = (makeEmployee(10));
        cout << a.id << endl;
        cout << "Assigning vector employee" << endl;
        vector<Employee> ve2;
        ve2 = ve;

        cout << "Uniqueptr example" << endl;
        unique_ptr<Employee> emp = makeEmpl(90);

        cout << "================Making 5 employees ----------------" << endl;
        std::array< Employee, 5> emp_arr = make_five_employees();

        cout << "***********Shared pointer trials******************" << endl;
        shared_ptr<Employee> spe1 = make_shared<Employee>(Employee(5));
        shared_ptr<Employee> spe2 = make_shared<Employee>(Employee(15));
        shared_ptr<Employee> spe3 = make_shared<Employee>(Employee(25));
        vector< shared_ptr<Employee>> vspe;
        vspe.push_back(spe1);
        vspe.push_back(spe2);
        vspe.push_back(spe3);

        cout << "Reference count after pushback::" << vspe[0].use_count() << endl;
        vector<shared_ptr<Employee>> vspe2 = getEmployeeSharedArray(vspe);
        cout << "Reference count after getEmployeeSharedArray::" << vspe2[0].use_count() << endl;
        cout << "Reference count after getEmployeeSharedArray:: 3rd element" << vspe2[3].use_count() << endl;

    }
}

namespace EVS_sample {
    class MyClass {
    public:
        MyClass(std::string bar) :
            m_foo(),
            m_bar(bar),
            m_done(false),
            m_thread([this] {doSomethingComplex(); }) {};

        ~MyClass() {
            m_thread.join();
        }

        std::string foo() {
            return m_bar;
        }

        bool areweDone() {
            return m_done;
        }
        void doSomethingComplex() {
            cout << "thread started..." << endl;
            std::this_thread::sleep_for(std::chrono::seconds(2));
            m_done = true;
            cout << "thread ended..." << endl;
        }

    
        string m_bar;
        string m_foo;
        bool m_done;
        thread m_thread;

            
    };

    void driver() {
        cout << "main thread entry..." << endl;
        auto* c = new MyClass("test");
        const char* res = c->foo().c_str();
        if (c->areweDone())
            return ;
        free(c);
        cout << "main thread exit..." << endl;
    }
}


namespace forward_example {
    
    struct W {
        W(int& x, const int& y) {

        }
    };

    struct X {
        X(int& x, int& y) {

        }
    };

    struct Y {
        Y(const int& x,int& y) {

        }
    };

    struct Z {
        int m;
        Z(const int& x, const int& y) {

        }
    };

    template <typename RT,typename T1,typename T2>
    RT* factory(T1 &&t1, T2 &&t2) {
        return new RT(std::forward<T1>(t1), std::forward<T2>(t2));
    }
    void driver() {
        Z* pz = factory<Z>(1, 2);
        const int a = 5,b=6;
        unique_ptr<Z> puz = make_unique<Z>(*pz);
        
    }
}
namespace Consumer_Producer_Thread {
    std::mutex queue_mutex;
    std::deque<int> rsrc_queue;
    std::atomic_bool stop_th = false;
    std::condition_variable queue_empty;

    void producer_thread() {
        while (!stop_th.load()) {
            std::srand(std::time(nullptr));
            int random_variable = std::rand();
            int val = random_variable;
            {
                std::lock_guard<std::mutex> guard(queue_mutex);
                cout << "Produced value : " << val << endl;
                rsrc_queue.push_back(val);
                std::this_thread::sleep_for(std::chrono::milliseconds(300));
            }
            queue_empty.notify_all();
        }
        
    }

    void consumer_thread() {
        while (!stop_th.load()) {
            std::unique_lock<std::mutex> guard(queue_mutex);

            if (rsrc_queue.empty()) {
                cout << "resource queue is empty ::" << std::this_thread::get_id() << endl;
                queue_empty.wait(guard);
            }
            else {
                cout << "Consuming value " << rsrc_queue.front() << "from thread-: " << std::this_thread::get_id() << endl;
                rsrc_queue.pop_front();
                std::this_thread::sleep_for(std::chrono::milliseconds(600));
            }
        }
    }

    void driver() {
        std::thread producer(producer_thread);
        std::thread consumer1(consumer_thread);
        std::thread consumer2(consumer_thread);
        char m;
        std::this_thread::sleep_for(std::chrono::seconds(10));
        stop_th = true;
        producer.join();
        consumer1.join();
        consumer2.join();
    }
}

namespace Observer_Pattern_Example {
    class Sensor {
    private:
        int val_;
        vector<std::function<void(int)>> callbacks_;
    public:
        
        void register_cb(std::function<void(int)> callback) {
            callbacks_.push_back(callback);
        }

        void measure() {
            val_ = 20;
        }
        void notify() {
            for (auto cb : callbacks_)
                cb(val_);
        }
        explicit Sensor(int val) :val_(val) {

        };

    };

    void driver() {
        Sensor sensor(10);
        sensor.register_cb([](int val) {
            cout << "new value is" << val << endl;
            });
    }

}
namespace state_design_pattern {
    
    class State {
    protected:
        string state;
    public:
        virtual void execute() = 0;
    };

    class Morning:public State {
    public:
        void execute() override{
            state.clear();
            state = state+"Good morning";
            cout << "Good morning" << endl;
        }

    };

    class Afternoon :public State {
    public:
        
        void execute() override {
            state.clear();
            state = state + "Good afternoon";
            cout << "Good afternoon" << endl;
        }
    };

    class Evening :public State {
    public:
        void execute() override {
            state.clear();
            state = state + "Good Evening";
            cout << "Good Evening" << endl;
        }
    };


    class Sun {
    private:
        State* state_;
    
    public:
        
        Sun(State* state) : state_(state) {

        }
        Sun(const Sun& rhs):state_(rhs.state_) {
            
        }

        Sun& operator=(const Sun& rhs) {
            if (this != &rhs) {
                state_ = rhs.state_;
            }
            return *this;
        }

        Sun(Sun&& rhs) noexcept :state_(rhs.state_) {
            
        }

        Sun& operator=(Sun&& rhs) noexcept {
            if (this != &rhs) {

            }
            return *this;
        }

        void printGreeting(string name) {
            state_->execute();
            cout <<" "<<name << endl;

        }

        void setState(State* state) {
            state_ = state;
        }


    };
    void driver() {

        unique_ptr<State> state = make_unique<Morning>(Morning());
        Sun sun(state.get());
        sun.printGreeting("Sujith");

        state.reset(new Afternoon());
        sun.setState(state.get());
        sun.printGreeting("Sujith");

       /* state.reset(make_unique<Afternoon>(Afternoon()));
        sun.setState(*state);
        sun.printGreeting("Sujith");
        state.reset(new Evening);
        sun.setState(*state);
        sun.printGreeting("Sujith");*/
    }
}

namespace chain_of_responsibility {
    class Handler {
    protected:
        Handler* next_handler_;
        
    public:
        
        void setNext(Handler *handler) {
            next_handler_ = handler;
        }

        void handleNext() {
            next_handler_->handle();
        }

        virtual void handle() = 0;
    };

    class Customer_Support1 : public Handler{
    public:
        void handle() override {
            cout << "Customer_Support1" << endl;
            handleNext();
        }
    };

    class Customer_Support2 : public Handler {
    public:
        void handle() override {
            cout << "Customer_Support2" << endl;
            handleNext();
        }
    };

    class Customer_Support3 : public Handler {
    public:
        void handle() override {
            cout << "Customer_Support3" << endl;
            //handleNext();
        }
    };

    void driver() {
        unique_ptr<Handler> cs1 = make_unique<Customer_Support1>(Customer_Support1());
        unique_ptr<Handler> cs2 = make_unique<Customer_Support2>(Customer_Support2());
        unique_ptr<Handler> cs3 = make_unique<Customer_Support3>(Customer_Support3());
        cs1->setNext(cs2.get());
        cs2->setNext(cs3.get());
        cs1->handle();

    }
}

namespace Optional_Sample {
    std::optional<int> getValue(int i) {
        int ret = 10;
        if (i > 10)
            return ret;
        else {
            std::optional<int> o{};
            return o;
        }    
    }
    void driver() {
        optional<int> ans = getValue(1);
        if (ans.has_value())
            cout << *ans << endl;
        else
            cout << "optional has no value" << endl;
    }
}


int main()
{
    chain_of_responsibility::driver();
    //Optional_Sample::driver();
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

