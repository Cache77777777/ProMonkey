#include <bits/stdc++.h>
using namespace std;

int bag1(vector<int> &weight, vector<int> &value, int size)
{
      vector<int> dp(size + 1, 0);
      for (int i = 0; i < weight.size(); i++)
      {
            for (int j = size; j >= weight[i]; j--)
            {
                  dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
      }
      return dp[size];
}
int bag2(vector<int> &weight, vector<int> &value, int size)
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

int main()
{
      int size, n;
      cin >> size >> n;
      vector<int> weight(n), value(n);
      for (int i = 0; i < n; i++)
      {
            cin >> weight[i];
      }
      for (int i = 0; i < n; i++)
      {
            cin >> value[i];
      }

      cout << bag1(weight, value, size) << endl;
      cout << bag2(weight, value, size) << endl;
      return 0;
}