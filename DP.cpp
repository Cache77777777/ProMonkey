#include <bits/stdc++.h>
using namespace std;

// 最长递增子序列
int LIS(vector<int> &nums)
{
      int n = nums.size();
      int res = 0;
      vector<int> dp(n, 1);
      for (int i = 1; i < n; i++)
      {
            for (int j = 0; j < i; j++)
            {
                  if (nums[i] > nums[j])
                  {
                        dp[i] = max(dp[i], dp[j] + 1);
                  }
            }
            if (dp[i] > res)
            {
                  res = dp[i];
            }
      }
      return res;
}

// 最长连续递增子序列
int LCIS(vector<int> &nums)
{
      int n = nums.size();
      int res = 0;
      vector<int> dp(n, 1);
      for (int i = 1; i < n; i++)
      {
            if (nums[i] > nums[i - 1])
            {
                  dp[i] = dp[i - 1] + 1;
            }
            if (dp[i] > res)
            {
                  res = dp[i];
            }
      }
      return res;
}

// 最长重复子数组
int findLength(vector<int> &nums1, vector<int> &nums2)
{
      int res = 0;
      int m = nums1.size();
      int n = nums2.size();
      // dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
      for (int i = 1; i <= m; i++)
      {
            for (int j = 1; j <= n; j++)
            {
                  if (nums1[i - 1] == nums2[j - 1])
                  {
                        dp[i][j] = dp[i - 1][j - 1] + 1;
                  }
                  if (dp[i][j] > res)
                  {
                        res = dp[i][j];
                  }
            }
      }
      return res;
}

//最长公共子序列
int LCS(string s1, string s2) {
    int res = 0;
    int m = s1.size(), n = s2.size();
    // 长度为[0, i - 1]的字符串text1与长度为[0, j - 1]的字符串text2的最长公共子序列为dp[i][j]
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
            if (dp[i][j] > res) res = dp[i][j];
        }
    }
    return res;
}

//最大子序列和
int SubArray(vector<int>& nums) {
    int n = nums.size();
    // dp[i]：包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]
    vector<int> dp(n);
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i-1] + nums[i],nums[i]);
        if (dp[i] > res) res = dp[i];
    }
    return res;
}

// 最长回文子串
int longestPalindromeSubseq(string s) {
    int n = s.size();
    // dp[i][j]：字符串s在[i, j]范围内最长的回文子序列的长度为dp[i][j]
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    int res = 1;
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
            if (dp[i][j] > res) res = dp[i][j];
        }
    }
    return res;
}

// 0/1一维dp，滚动数组
int Knapsack1(vector<int> &weight, vector<int> &value, int size)
{
      vector<int> dp(size + 1, 0);
      for (int i = 0; i < weight.size(); i++)
      {
            for (int j = size; j >= weight[i]; j--) // 遍历背包容量
            {
                  dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
      }
      return dp[size];
}

// 0/1二维dp
int Knapsack2(vector<int> &weight, vector<int> &value, int size)
{
      int n = weight.size();
      vector<vector<int>> dp(n, vector<int>(size + 1, 0));
      for (int j = weight[0]; j <= size; j++)
      {
            dp[0][j] = value[0];
      }
      for (int i = 1; i < n; i++)
      {
            for (int j = 0; j <= size; j++)
            {
                  if (j < weight[i])
                        dp[i][j] = dp[i - 1][j];
                  else
                        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
            }
      }
      return dp[n - 1][size];
}

// 完全背包问题
int CompletePack(vector<int> &weight, vector<int> &value, int size)
{
      int n = weight.size();
      vector<int> dp(size + 1, 0);
      for (int i = 0; i < n; i++)
      {
            for (int j = weight[i]; j <= size; j++) // 遍历背包容量，注意和滚动数组的区别
            {
                  dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
      }
      return dp[size];
}

int main()
{
      vector<int> nums1 = {1,2,3,2,1};
      vector<int> nums2={3,2,1,4,7};
      cout << findLength(nums1,nums2) << endl;
      return 0;
}
