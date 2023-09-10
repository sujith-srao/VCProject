#pragma once

#include<string>
#include<vector>
using namespace std;

namespace valid_paranthesis {
    class Solution {
    public:
        bool isValid(string s);
    };
}

namespace palindrome_partitioning {
    class Solution {
    public:
        vector<vector<string>> partition(string s);
        vector<string> PartitionString(string s, int i);
        bool isPalindrome(string s);
    };
    void printPartition(string s, vector<string>& partitioned_strings, int index);
}

namespace isomorphic_strings {
    class Solution {
    public:
        bool isIsomorphic(string s, string t);
    };
}
