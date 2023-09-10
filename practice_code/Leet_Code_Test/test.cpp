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