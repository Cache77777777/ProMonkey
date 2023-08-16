#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
int n;
vector<int> a(N);
vector<int> edge[N];
vector<int> depth(N);
vector<long> sum(N);
// 树型DP
void dfs(int u, int v)
{
      sum[u] += a[u];
      for (int i : edge[u])
      {
            if (i != v)
            {
                  depth[i] = depth[u] + 1;
                  dfs(i, u);
                  sum[u] += sum[i];
            }
      }
}

int main()
{
      
      cin >> n;
      for (int i = 1; i <= n; i++)
      {
            cin >> a[i];
      }
      for (int i = 1; i < n; i++)
      {
            int x, y;
            cin >> x >> y;
            // 构建邻接关系
            edge[x].push_back(y);
            edge[y].push_back(x);
      }
      depth[1] = 1;
      dfs(1, 0);
      long long res = 0;
      for (int i = 1; i <= n; i++){
            cout << depth[i] << " ";
      }
      cout << endl;
      for (int i = 1; i <= n; ++i){
            res += depth[i] * a[i];
      }
      cout << res << endl;
      long long t = res;
      for (int i = 2; i <= n; ++i){
            res = min(res, t - (depth[i] - 2) * sum[i]);
      }
      cout << res << endl;
      return 0;
}