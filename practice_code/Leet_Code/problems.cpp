#include "problems.h"
#include <stack>
#include<tuple>
#include<algorithm>
#include<iostream>
#include<map>

using namespace std;

namespace valid_paranthesis {

	bool Solution::isValid(string s) {
		stack<char> bracket_stack;

		for (int i = 0; i < s.size();i++) {
			if (s.at(i) == '{' || s.at(i) == '(' || s.at(i) == '[') {
				bracket_stack.push(s.at(i));
			}
			else if (s.at(i) == '}') {
				if (bracket_stack.empty() || bracket_stack.top() != '{')
					return false;
				bracket_stack.pop();
			}
			else if (s.at(i) == ')') {
				if (bracket_stack.empty() || bracket_stack.top() != '(')
					return false;
				bracket_stack.pop();
			}
			else if (s.at(i) == ']') {
				if (bracket_stack.empty() || bracket_stack.top() != '[')
					return false;
				bracket_stack.pop();
			}
			
		}
		if (!bracket_stack.empty())
			return false;

		return true;
	}
}

namespace palindrome_partitioning {

		vector<string> Solution::PartitionString(string s,int i) {
			
			string first_part = s.substr(0,i);
			string second_part = s.substr(i );

			vector<string> ans;
			
			ans.emplace_back(first_part);
			ans.emplace_back(second_part);
			
			return ans;
		}

		bool  Solution::isPalindrome(string s) {
			for (int i = 0, j = s.size() - 1; i <= j; i++, j--) {
				if (s[i] != s[j])
					return false;
			}
			return true;
		}

		void printPartition(string s, vector<string>& partitioned_strings, int index) {
			if (index == s.length()) {
				for_each(partitioned_strings.begin(), partitioned_strings.end(), [](string& s) {
					cout << s<<", ";
					});
				cout << endl;
			}
			else {
				string first_part;
				
				for (int i = index; i < s.size(); i++) {
					first_part += s[i];
					partitioned_strings.push_back(first_part);
					printPartition(s, partitioned_strings, i + 1);
					partitioned_strings.pop_back();
				}
			}
		}

		vector<vector<string>> Solution::partition(string s) {
			
			for (int i = 1; i < s.size() - 2; i++) {
				vector<string> partitioned_string = PartitionString(s, i);
				if (isPalindrome(partitioned_string[0]) &&
					isPalindrome(partitioned_string[1])) {

				}
			}
			vector<vector<string>> ans;

			return ans;
		}
}

namespace isomorphic_strings {
	bool Solution::isIsomorphic(string s, string t) {
		map<char, char> s_to_t_mapping;
		map<char, char> t_to_s_mapping;

		if (s.length() != t.length())
			return false;
		
		for (int i = 0; i < s.length(); i++) {
			auto it_s = s_to_t_mapping.find(s.at(i));
			auto it_t = t_to_s_mapping.find(t.at(i));

			if (it_s == s_to_t_mapping.end()) {
				if (it_t == t_to_s_mapping.end()) {
					t_to_s_mapping[t.at(i)] = s.at(i);
					s_to_t_mapping[s.at(i)] = t.at(i);
				}
				else {
					if (t_to_s_mapping[t.at(i)] != s.at(i))
						return false;
				}
				
			}
			else {
				if (s_to_t_mapping[s.at(i)] != t.at(i))
					return false;
			}
		}
		return true;
	}
}


