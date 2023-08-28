#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int T;
char s[2005][2005];
int dp[2005][2005][3];
int n, m;

int main()
{
      scanf("%d %d", &n, &m); // 输入 n 和 m
      for (int i = 1; i <= n; ++i)
      {
            scanf("%s", s[i] + 1); // 输入地图的每一行
      }
      memset(dp, 0x7f, sizeof(dp)); // 初始化 dp 数组为最大值
      dp[1][1][0] = 1;
      dp[1][1][1] = 1;
      dp[1][1][2] = 1;
      for (int i = 1; i <= n; ++i)
      {
            for (int j = 1; j <= m; ++j)
            {
                  if (s[i][j] == '*')
                  {
                        dp[i][j][0] = 1e9; // 如果当前位置是障碍物，将对应 dp 值设置为一个大数
                        dp[i][j][1] = 1e9;
                        dp[i][j][2] = 1e9;
                        continue;
                  }
                  if (i == 1 && j == 1)
                        continue; // 起始位置特殊处理
                  dp[i][j][0] = min(dp[i - 1][j][0], min(dp[i - 1][j][1] + 1, dp[i - 1][j][2] + 1));
                  dp[i][j][1] = min(dp[i - 1][j - 1][0] + 1, min(dp[i - 1][j - 1][1], dp[i - 1][j - 1][2] + 1));
                  dp[i][j][2] = min(dp[i][j - 1][0] + 1, min(dp[i][j - 1][1] + 1, dp[i][j - 1][2]));
            }
      }
      int ans = 1e9; // 初始化答案为一个大数
      ans = min(ans, dp[n][m][0]);
      ans = min(ans, dp[n][m][1]);
      ans = min(ans, dp[n][m][2]);
      if (ans >= 1e9)
      {
            cout << "-1\n"; // 输出结果
      }
      else
      {
            cout << ans << endl;
      }

      return 0;
}
