#include "problems.h"
#include <stack>
#include<tuple>
#include<algorithm>
#include<iostream>
#include<map>
#include<list>


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

namespace boats_to_save_people {

    int Solution::numRescueBoats(const vector<int>& people, int limit) {

        vector<int> people_ = people;
        sort(people_.begin(), people_.end());

        int num_boats = 0;
        while(!people_.empty()){
            int i = 0;
            int j = people_.size()-1;
            while (people_[i] + people_[j] > limit && i<j) {
                j--;
            }
            num_boats++;
            int val = people_[j];
            people_.erase(std::remove(people_.begin(), people_.end(), people_[i]));
            if (j > i) {
                people_.erase(std::remove(people_.begin(), people_.end(), val));
            }
        }
        return num_boats;
    }
}

namespace max_consecutive_ones {

    int Solution::longestOnes(vector<int>& nums, int k) {
        int max = -1;
        int cur_max = 0;
        int l = 0, r = 0, sw_size = 0;
        int ptr = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cur_max++;

            }
            else {
                if (sw_size < k) {
                    sw_size++;
                    cur_max++;
                }
                else {
                    sw_size--;
                    if (cur_max > max)
                        max = cur_max;
                    cur_max =1;
                }
            }
        }
        if (cur_max > max)
            max = cur_max;

        return max;
    }
};

namespace get_equal_substrings_within_budget {

    int Solution::equalSubstring(string s, string t, int maxCost) {
        vector<int> cost;

        for (int i = 0; i < s.size(); i++) {
            cost.push_back(abs(t[i] - s[i]));
        }
        int left = 0;
        int right = 0;
        int len = 0;
        int capacity = maxCost;
        int max = INT16_MIN;
        int n = cost.size();

        max = std::max(INT16_MIN, 5);
        max = INT16_MIN;
        while (left < n) {
            if (right<n && cost[right] <= capacity ) {
                len++;
                capacity = capacity - cost[right];
                right++;
            }
            else {
                if (right < n) {
                    max = std::max(max, len);
                    capacity = capacity + cost[left];
                    len--;
                    left++;
                }
                else
                    break;
            }
        }
        return max;
    }
}


namespace longest_increasing_subsequence {
    int solve(vector<int>& nums, int index, int lge) {
        
        if (index == nums.size()) {
            return 0;
        }

        if (nums[index] > lge) {
            return max(1 + solve(nums, index + 1, nums[index]), solve(nums, index + 1, lge));
        }
        else
            return solve(nums, index + 1, lge);
    }

    int Solution::lengthOfLIS(vector<int>& nums) {
        return solve(nums, 0, INT16_MIN);
    }
}

namespace max_product_subarray {
    
    int prod(vector<int>& nums, int index) {
        if (index == nums.size())
            return 1;
        int product = prod(nums, index + 1);
        if (nums[index] * product >= nums[index]) {

        }
        else {

        }

    }

    int Solution::maxProduct(vector<int>& nums) {
        return prod(nums, 0);
    }
}

namespace target_sum {
    
    int solve(vector<int> nums, int target, int index) {
        
        if (index >= nums.size()) {
            int sum = 0;
            for (auto i : nums)
                sum += i;
            if (sum == target)
                return 1;
            else
                return 0;
        }
        int count = 0;
        
        nums[index] = -1 * nums[index];
        count += solve(nums, target, index + 1);
        
        nums[index] = -1 * nums[index];
        count += solve(nums, target, index + 1);
        

        return count;
    }

    int Solution::findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0);
    }
}

//namespace two_keys_keyboard {
//    int solve(int n,string& s, string& cs) {
//        if (n == s.size()-1)
//            return 0;
//
//        string ts(s);
//        if (!cs.empty())
//            ts = s + cs;
//
//        return min(1 + solve(n, ts, cs), 1 + solve(n, s, s));
//    }
//
//    int Solution::minSteps(int n) {
//        string s{ "A" };
//        string cs{""};
//        return solve(n, s, cs);
//    }
//}

namespace coin_change {
    int Solution::coinChange(vector<int>& coins, int amount) {
        vector<int> coin_needed;
        coin_needed.push_back(0);
        for (int i = 1; i <= amount; i++) {
            coin_needed.push_back(UINT16_MAX);
        }

        for (int i = 0; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                if (j >= coins[i]) {
                    coin_needed[j] = min(coin_needed[j], 1 + coin_needed[j - coins[i]]);
                }
            }
        }
        if (coin_needed[amount] == UINT16_MAX)
            return -1;
        return coin_needed[amount];
    }
}

namespace stone_game_mine {
    void solve(deque<int> &piles, int a,int b,bool turn) {
        if (piles.empty()) {
            cout << "a=" << a <<" b="<<b << endl;
            return;
        }
            

        if (turn) {
            deque<int> temp = piles;
            int a_front = a + piles.front();
            piles.pop_front();
            solve(piles, a_front, b, false);

            int a_back = a + temp.back();
            temp.pop_back();
            solve(temp, a_back, b, false);
        }
        else {
            deque<int> temp = piles;
            int bob_f = b + piles.front();
            piles.pop_front();
            solve(piles, a, bob_f, true);

            int b_back = b + temp.back();
            temp.pop_back();
            solve(temp, a, b_back, true);
        }
    }
    
    bool Solution::stoneGame(vector<int>& piles) {
        deque<int> dq;
        for (int i = 0; i < piles.size(); i++) {
            dq.push_back(piles.at(i));
        }
        int a = 0;
        int b = 0;
        
        solve(dq, a, b, true);
        if (a > b)
            return true;
        else
            return false;
    }

}

namespace Good_indices {
    int getGoodIndices(vector<int>& nums, int index) {
        
        int count = -1;
        int left = index - 1;
        for (; left >=0; left--) {
            if (nums[index] < nums[left]) {
                count++;
            }
            else {
                break;
            }
        }
        
        int right = index + 1;
        for (; right < nums.size(); right++) {
            if (nums[index] > nums[right]) {
                count++;
            }
            else {
                break;
            }
        }
        if (left == -1 && right == nums.size())
            return -1;
        count = (index - left) + (right - index);
        return count;
    }
    void driver() {
        vector<int> vi{ 1,2,3,5,1 };
        vector<int> res;
        
        for (int i = 0; i < vi.size(); i++) {
            int temp = getGoodIndices(vi, i);
            res.push_back(temp);
        }

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
    }
}

namespace surrounded_regions {

    void Solution::solve(vector<vector<char>>& board) {

    }
}

namespace Sum_leaf_nodes {
    void Solution::solve(vector<int> vi, TreeNode* root) {
        if (root == nullptr) {
            int num = 0;
            int n = vi.size();
            for (int i = 0; i < n; i++) {
                num = num + pow(10, i) * vi.back();
                vi.pop_back();
            }
            dq.push_back(num);
            return;
        }
        else {
            vi.push_back(root->val);
            if (root->left != nullptr) {
                solve(vi, root->left);
                vi.pop_back();
            }
            if (root->right != nullptr) {
                solve(vi, root->right);
                vi.pop_back();
            }
            
            
        }

    }
    int Solution::sumNumbers(TreeNode* root) {
        int sum = 0;
        int n = dq.size();
        vector<int> vi;
        solve(vi, root);
        for (int i = 0; i < n; i++) {
            sum = sum + dq.front();
            dq.pop_front();
        }
        return sum;
    }
}

namespace circular_buffer {

    template<typename T>
    CircularBuffer<T>::CircularBuffer(const CircularBuffer<T>& rhs) {
        arr_ = rhs.arr_;
        index_ = rhs.index_;
    }

    template<typename T>
    CircularBuffer<T>& CircularBuffer<T>::operator=(const CircularBuffer<T>& rhs) {
        if (this != &rhs) {
            arr_ = rhs.arr_;
            index_ = rhs.index_;
        }
        return *this;
    }

    template<typename T>
    CircularBuffer<T>::CircularBuffer(CircularBuffer<T>&& rhs) noexcept {
        arr_ = rhs.arr_;
        index_ = rhs.index_;
        
        rhs.arr_.clear();
        index_ = 0;
    }

    template<typename T>
    CircularBuffer<T>& CircularBuffer<T>::operator=(CircularBuffer<T>&& rhs) noexcept {
        arr_ = rhs.arr_;
        index_ = rhs.index_;

        rhs.arr_.clear();
        index_ = 0;
        return *this;
    }

    //template<typename T>
    //void CircularBuffer<T>::push(T& val) {
    //    if (index_ == kMaxSize) {
    //        index_ = 0;
    //    }
    //    arr_.insert(arr_.begin() + index_, val);
    //    index_++;
    //}

    /*template<typename T>
    vector<T> CircularBuffer<T>::getBuffer() {
        return arr_;
    }*/
}
namespace perfect_squares_279 {

    int Solution::numSquares(int n) {
        vector<int> dp(n+1, 0);
        for (int i = 1; i <= n; i++) {
            dp[i] = i;
        }
        int x = 1;
        while (x * x <= n) {
            x++;
        }
        x = x - 1;
        for (int j = 2; j <= x; j++) {
            for (int i = j*j; i <= n; i++) {
                /*if ((i - j * j) >= 0)*/ {
                    dp[i] = std::min(dp[i], 1 + dp[i - (j * j)]);
                }
            }
        }
        return dp[n];
    }
}

namespace max_profit_121 {
    int Solution::maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> profits(n, INT16_MIN);

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                profits[i] = std::max(profits[i], prices[j] - prices[i]);
            }
        }

        auto max_elem = std::max_element(profits.begin(), profits.end());
        if (*max_elem < 0)
            return 0;
        return *max_elem;
    }
}

namespace consecutive_letters {
    bool containsConsecutiveLetter(const std::string& s) {
        std::list<int> alphabet_index;

        for (int i = 0; i < s.length(); i++) {
            auto it = std::find(alphabet_index.begin(), alphabet_index.end(), s.at(i) - 'a');
            if (it == alphabet_index.end()) {
                alphabet_index.push_back(s.at(i) - 'a');
            }
            else
                return false;
        }

        int count = 0;
        for (auto itBegin = alphabet_index.begin(), itNext = itBegin++; 
            itNext != alphabet_index.end(); 
            itBegin++, itNext++) {
            if (*itNext == *itBegin + 1) {
                count++;
            }
            else
                return false;
        }
        if(count==s.size()-1)
            return true;
        return false;
    }
}
//namespace credit_card_issue_checker {
//    struct CardData {
//        string beginWith_;
//        int length_;
//        CardData(string s, unsigned int len) :beginWith_(s), length_(len) {};
//        bool operator==(struct CardData& rhs) {
//            return (rhs.beginWith_ == beginWith_) && (rhs.length_ == length_);
//        };
//    };
//    string getIssuer(string cardDetails){
//        std::map<CardData,std::string> carddata_issuer_map;
//        carddata_issuer_map[{"34", 15}] = "AMEX";
//        carddata_issuer_map[{"37", 15}] = "AMEX";
//        carddata_issuer_map[{"6011", 16}] = "Discover";
//        carddata_issuer_map[{"51", 15}] = "Mastercard";
//        carddata_issuer_map[{"52", 15}] = "Mastercard";
//        carddata_issuer_map[{"53", 15}] = "Mastercard";
//        carddata_issuer_map[{"54", 15}] = "Mastercard";
//        carddata_issuer_map[{"55", 15}] = "Mastercard";
//        carddata_issuer_map[{"4", 13}] = "VISA";
//        carddata_issuer_map[{"4", 16}] = "VISA";
//
//        string beginsWith{ cardDetails.at(0) };
//        CardData c{ beginsWith ,cardDetails.length() };
//        if (carddata_issuer_map.find(c) != carddata_issuer_map.end())
//            return carddata_issuer_map[c];
//
//        beginsWith = cardDetails.substr(0, 2);
//        c.beginWith_ = beginsWith;
//        c.length_ = cardDetails.length();
//        if(carddata_issuer_map.find(c) != carddata_issuer_map.end())
//            return carddata_issuer_map[c];
//
//        beginsWith = cardDetails.substr(0, 4);
//        c.beginWith_ = beginsWith;
//        c.length_ = cardDetails.length();
//        if (carddata_issuer_map.find(c) != carddata_issuer_map.end())
//            return carddata_issuer_map[c];
//    }
//}

namespace reduce_array_size_to_half {
    int minSetSize(vector<int>& arr) {
        map<int, int> freq_map;
        for (auto i : arr) {
            auto it = freq_map.find(i);
            if (it != freq_map.end()) {
                freq_map[i]++;
            }
            else {
                freq_map[i]=1;
            }
        }
        std::vector<pair<int, int>> pairs;
        for (auto it : freq_map)
            pairs.push_back(it);

        std::sort(pairs.begin(), pairs.end(), [&pairs](auto &lhs,auto &rhs) {
            return lhs.second > rhs.second;
            });
        int sum = 0;
        int count = 0;
        for (auto i : pairs) {
            if (sum >= arr.size() / 2)
                break;
            sum = sum + i.second;
            count++;
        }
        return count;
    }
}
namespace uncrossed_lines_1035 {
    int solve(int left, int right, vector<int>& nums1, vector<int>& nums2) {
        if (left >= nums1.size())
            return 0;

        if (right >= nums2.size())
            return 0;

        for (int i = left; i < nums1.size(); i++) {
            for (int j = right; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j])
                    int left = 1 + solve(i + 1, j + 1, nums1, nums2);
                    int right = solve(i, j + 1, nums1, nums2);
                    return std::max(left, right);
            }
        }
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return solve(0, 0, nums1, nums2);
    }
}

namespace design_browser_history {
    BrowserHistory::BrowserHistory(string homepage) {
        urls.reserve(5000);
        urls.insert(urls.begin() + cur_,homepage);
        cur_++;
    }

    void BrowserHistory::visit(string url) {
        urls.insert(urls.begin() + cur_, url);
        cur_++;
    }

    string BrowserHistory::back(int steps) {
        //if()
        return urls.at(cur_-steps);
    }

    string BrowserHistory::forward(int steps) {
        if (cur_ + steps >= urls.size())
            cur_ = urls.size() - 1;
        else
            cur_ = cur_ + steps;
        return urls.at(cur_ - steps);
    }
}

namespace find_island {
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> visited;
        for (int i = 0; i < rows; i++) {
            vector<int> temp(0, cols);
            visited.push_back(temp);
        }
        
        int max_area = INT16_MIN;
        
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    int cur_area = 0;
                    queue<pair<int, int>> island;
                    island.push(make_pair(i,j));
                    while (!island.empty()) {
                        std::pair<int, int> temp = island.front();
                        if (temp.first - 1 >= 0 && visited[temp.first - 1][temp.second] == 0 && grid[temp.first - 1][temp.second] == 1) {
                            island.push(make_pair(temp.first - 1, temp.second));
                        }
                        if (temp.first + 1 <= rows && visited[temp.first + 1][temp.second] == 0 && grid[temp.first + 1][temp.second] == 1) {
                            island.push(make_pair(temp.first + 1, temp.second));
                        }
                        if (temp.second - 1 >= 0 && visited[temp.first][temp.second-1] == 0 && grid[temp.first][temp.second-1] == 1) {
                            island.push(make_pair(temp.first, temp.second-1));
                        }
                        if (temp.second + 1 <= cols && visited[temp.first][temp.second + 1] == 0 && grid[temp.first][temp.second + 1] == 1) {
                            island.push(make_pair(temp.first, temp.second + 1));
                        }
                        visited[temp.first][temp.second] = 1;
                        cur_area++;
                        island.pop();
                    }
                    if (cur_area > max_area)
                        cur_area = max_area;
                }
            }
        }
    }
}
