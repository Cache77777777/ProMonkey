#include <bits/stdc++.h>
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
void dfs(int x, int y, int row, int col, vector<char> &s, vector<int> &visit)
{
      char p = s[x * col + y];
      visit[x * col + y] = 1;
      for (int i = 0; i < 4; i++)
      {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (xx >= 0 && xx < row && yy >= 0 & yy < col && s[xx * col + yy] == p && visit[xx * col + yy] == 0)
            {
                  dfs(xx, yy, row, col, s, visit);
            }
      }
}
int weight(int row, int col, vector<char> &s)
{
      int t = 0;
      vector<int> visit(s.size(), 0);
      for (int i = 0; i < row; i++)
      {
            for (int j = 0; j < col; j++)
            {
                  if (visit[i * col + j] == 0)
                  {
                        t++;
                        dfs(i, j, row, col, s, visit);
                  }
            }
      }
      return t;
}
int main()
{
      int n;
      cin >> n;
      vector<char> s(n);
      for (int i = 0; i < n; i++)
      {
            cin >> s[i];
      }
      int res = INT_MAX;
      for (int i = 1; i <= n; i++)
      {
            if (n % i == 0)
            {
                  int row = i;
                  int col = n / i;
                  res = min(res, weight(row, col, s));
            }
      }
      cout << res << endl;
      return 0;
}