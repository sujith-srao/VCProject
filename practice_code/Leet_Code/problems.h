#pragma once

#include<string>
#include<vector>
#include<deque>
#include<queue>

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

namespace boats_to_save_people {
    class Solution {
    public:
        int numRescueBoats(const vector<int>& people, int limit);
    };
}

namespace max_consecutive_ones {
    class Solution {
    public:
        int longestOnes(vector<int>& nums, int k);
    };
};

namespace get_equal_substrings_within_budget {
    class Solution {
    public:
        int equalSubstring(string s, string t, int maxCost);
    };
}

namespace longest_increasing_subsequence {
    class Solution {
    public:
        int lengthOfLIS(vector<int>& nums);
    };
}

namespace max_product_subarray {
    class Solution {
    public:
        int maxProduct(vector<int>& nums);
    };
}

namespace target_sum {
    class Solution {
    public:
        int findTargetSumWays(vector<int>& nums, int target);
    };
}

//namespace two_keys_keyboard {
//    class Solution {
//    public:
//        int minSteps(int n);
//    };
//}

namespace coin_change {
    class Solution {
    public:
        int coinChange(vector<int>& coins, int amount);
    };
}

namespace stone_game_mine {
    class Solution {
    public:
        bool stoneGame(vector<int>& piles);
    };
}
namespace Good_indices {
    int getGoodIndices(vector<int>& nums, int index);
    void driver();
}

namespace surrounded_regions {
    class Solution {
    public:
        void solve(vector<vector<char>>& board);
    };
}

namespace Sum_leaf_nodes {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    class Solution {
    public:
        deque<int> dq;
        void solve(vector<int> vi, TreeNode* root);
        int sumNumbers(TreeNode* root);
    };
}

namespace circular_buffer {
    template<typename T>
    class CircularBuffer {
        deque<T> arr_;
        int index_{ 0 };
        const int kMaxSize = 5;

    public:
        CircularBuffer() = default;
        CircularBuffer(const CircularBuffer<T>& rhs);
        CircularBuffer<T>& operator=(const CircularBuffer<T>& rhs);
        CircularBuffer(CircularBuffer<T>&& rhs) noexcept;
        CircularBuffer<T>& operator=(CircularBuffer<T>&& rhs) noexcept;

        
        void push(const T& val) {
            if (arr_.size() == kMaxSize) {
                arr_.pop_back();
                arr_.push_front(val);
            }
            else {
                arr_.push_back(val);
            }
        }

        vector<T> getBuffer() {
            vector<T> vi;
            for (auto itBegin = arr_.begin(); itBegin != arr_.end(); itBegin++) {
                vi.push_back(*itBegin);
            }
            return vi;
        };


    };
}

namespace perfect_squares_279 {
    class Solution {
    public:
        int numSquares(int n);
    };
}

namespace max_profit_121 {
    class Solution {
    public:
        int maxProfit(vector<int>& prices);
    };
}

namespace consecutive_letters {
    bool containsConsecutiveLetter(const std::string& s);
}

//namespace credit_card_issue_checker {
//    string getIssuer(string cardDetails);
//}

namespace reduce_array_size_to_half {
    int minSetSize(vector<int>& arr);
}

namespace uncrossed_lines_1035 {
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2);
}

namespace design_browser_history {
    class BrowserHistory {
    public:
        BrowserHistory(string homepage);
        void visit(string url);
        string back(int steps);
        string forward(int steps);
    private:
        std::string homepage_;
        std::vector<std::string> urls;
        int cur_{ 0 };
    };
}

