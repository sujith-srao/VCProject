#include "pch.h"
#include<string>
#include "problems.h"
#include<gtest/gtest.h>
using namespace std;

TEST(ValidParanthesis, DISABLED_Test1) {
    string input("]");
    valid_paranthesis::Solution sut;
    EXPECT_FALSE(sut.isValid(input));
}

TEST(PalindromePartition, DISABLED_TestStringPartition) {
    string input("Hello");
    palindrome_partitioning::Solution sut;

    vector<string> ans = sut.PartitionString(input, 2);;
    EXPECT_TRUE("He" == ans[0]);
    EXPECT_TRUE("llo" == ans[1]);
}

TEST(PalindromePartition, DISABLED_TestisPalindromeTRUE) {
    string input("HeeeH");
    palindrome_partitioning::Solution sut;
    EXPECT_TRUE(sut.isPalindrome(input));
    
}

TEST(PalindromePartition, DISABLED_TestisPalindromeFALSE) {

    string input("Hello");
    palindrome_partitioning::Solution sut;
    EXPECT_FALSE(sut.isPalindrome(input));
}

TEST(PalindromePartition, DISABLED_TestprintPartition) {
    string input("Hello");
    vector<string> ans;
    palindrome_partitioning::printPartition(input, ans, 0);
}

TEST(IsomorphicString, DISABLED_TestisomorphicTRUE) {
    string s("paper");
    string t("title");
    isomorphic_strings::Solution sut;
    EXPECT_TRUE(sut.isIsomorphic(s, t));
    s = "add";
    t = "egg";
    EXPECT_TRUE(sut.isIsomorphic(s, t));
}

TEST(IsomorphicString, DISABLED_TestisomorphicFALSE) {
    string s("xyz");
    string t("xxx");
    isomorphic_strings::Solution sut;
    EXPECT_FALSE(sut.isIsomorphic(s, t));
}

TEST(BoatsToSavePeople, DISABLED_Boatstosavepeople) {
    vector<int> people1{ 3,2,2,1 };
    int limit = 3;
    boats_to_save_people::Solution sut;
    //EXPECT_EQ(sut.numRescueBoats(people1, limit), 3);

    vector<int> people2{ 8,2,3,6,2,6 };
    EXPECT_EQ(sut.numRescueBoats(people2, 8), 4);
}

TEST(MaxOnes_3, DISABLED_maxOnes_test1) {
    vector<int> nums{ 1,1,1,0,0,0,1,1,1,1,0 };
    int k = 2;
    max_consecutive_ones::Solution sut;

    EXPECT_EQ(sut.longestOnes(nums,k),6);
}

TEST(MaxOnes_3, DISABLED_maxOnes_test2) {
    vector<int> nums{ 0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1 };
    int k = 3;
    max_consecutive_ones::Solution sut;

    EXPECT_EQ(sut.longestOnes(nums, k), 10);
}

TEST(Eq_substring_budget, DISABLED_Equal_substring_within_budget) {

    string s("krpgjbjjznpzdfy");
    string t("nxargkbydxmsgby");

    get_equal_substrings_within_budget::Solution sut;

    EXPECT_EQ(sut.equalSubstring(s, t, 14), 4);
}

TEST(LIS, DISABLED_longest_incr_sub) {

    vector<int> nums{ 10,40,50,3,4,5,6,70,80 };

    longest_increasing_subsequence::Solution sut;

    EXPECT_EQ(sut.lengthOfLIS(nums),6);
}

TEST(max_product_subarray, DISABLED_max_product_subarray_1) {

    vector<int> nums{ 2,3,-2,4 };

    max_product_subarray::Solution sut;

    EXPECT_EQ(sut.maxProduct(nums), 6);
}

TEST(target_sum, DISABLED_target_sum_ways) {

    vector<int> nums{ 1,1,1,1,1 };

    target_sum::Solution sut;

    EXPECT_EQ(sut.findTargetSumWays(nums,3), 5);
}

//TEST(two_keys_kb, DISABLED_num_of_ways) {
//
//    two_keys_keyboard::Solution sut;
//
//    EXPECT_EQ(sut.minSteps(3), 3);
//}

TEST(coin_change, DISABLED_coinchange_test_1) {
    coin_change::Solution sut;
    vector<int> coins1{ 1,2,5 };
    EXPECT_EQ(sut.coinChange(coins1, 11), 3);

 
    vector<int> coins2{ 2 };
    EXPECT_EQ(sut.coinChange(coins2, 3),-1);
}

TEST(stone_game_877, DISABLED_stone_game_877_test) {
    //stone_game_mine::Solution sut;
    //vector<int> piles{ 5,3,4,5 };
    //EXPECT_EQ(sut.stoneGame(piles), true);
    Good_indices::driver();
}

TEST(Sum_leaf_nodes, DISABLED_sum_leaf) {
    Sum_leaf_nodes::Solution sut;
    Sum_leaf_nodes::TreeNode tn1{ 1 };
    Sum_leaf_nodes::TreeNode tn2{ 2 };
    Sum_leaf_nodes::TreeNode tn3{ 3 };
    tn1.left = &tn2;
    tn1.right = &tn3;
    EXPECT_EQ(sut.sumNumbers(&tn1), 25);
}

TEST(test_circular_buffer, DISABLED_push_buff_firstElemOverwritten) {
    circular_buffer::CircularBuffer<int> buff;
    for (int i = 1; i <= 5; i++)
        buff.push(i*10);
    vector<int> vi1{ 10,20,30,40,50 };
    EXPECT_EQ(buff.getBuffer(), vi1);

    buff.push(60);
    vector<int> vi2{ 60,10,20,30,40 };
    EXPECT_EQ(buff.getBuffer(), vi2);

    buff.push(70);
    vector<int> vi3{ 70,60,10,20,30 };
    EXPECT_EQ(buff.getBuffer(), vi3);
}

TEST(test_perfect_squares, DISABLED_numSquares) {
    perfect_squares_279::Solution sut;

    EXPECT_EQ(sut.numSquares(12),3);
}

TEST(test_max_profits, DISABLED_max_profits) {
    max_profit_121::Solution sut;
    vector<int> vi{ 7,1,5,3,6,4 };
    EXPECT_EQ(sut.maxProfit(vi),5);
}

//TEST(test_credit_card_issue, check_issuer) {
//    string s = credit_card_issue_checker::getIssuer(std::to_string(4111111111111111));
//    EXPECT_EQ(s, "VISA");
//}

TEST(test_reduce_array_size_in_half, DISABLED_test_reduce_array) {
    vector<int> vi{ 3,3,3,3,5,5,5,2,2,7 };
    EXPECT_EQ(reduce_array_size_to_half::minSetSize(vi), 2);
}

TEST(test_uncrossed_lines_1035, DISABLED_test_uncrossed_lines) {
    vector<int> vi1{ 2,5,1,2,5 };
    vector<int> vi2{ 10,5,2,1,5,2 };
    EXPECT_EQ(uncrossed_lines_1035::maxUncrossedLines(vi1,vi2), 3);
}

TEST(browser_history, test_bh) {
    design_browser_history::BrowserHistory sut("leetcode.com");
    sut.visit("google.com");
    sut.visit("facebook.com");
    sut.visit("youtube.com");
   
    EXPECT_TRUE(sut.back(1). compare("facebook.com")==0);
    EXPECT_TRUE(sut.back(1). compare("google.com")==0);
    EXPECT_TRUE(sut.forward(1). compare("facebook.com")==0);


}
