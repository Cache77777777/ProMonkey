#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100005];
int dp[100005] = {0};
int nxt[100005];

int dfs(int v, int fa)
{
      int m = 1e6;
      for (auto u : edge[v])
      {
            if (u == fa)
                  continue;
            m = min(m, dfs(u, v));
      }
      nxt[v] = m;
      if (nxt[v] == 1e6)
      {
            dp[v] = 1;
      }
      else
      {
            dp[v] = dp[nxt[v]] + 1;
      }
      return min(m, v);
}

int main()
{
      int n;
      cin >> n;

      for (int i = 1; i < n; i++)
      {
            int u, v;
            cin >> u >> v;
            edge[u].push_back(v);
            edge[v].push_back(u);
      }
      dfs(1,0);
      for (int i = 1; i <= n; i++)
      {
            cout << dp[i] << " ";
      }
      cout << endl;
}