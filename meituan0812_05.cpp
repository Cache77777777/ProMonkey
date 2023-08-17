#include <bits/stdc++.h>
using namespace std;

int n;
int ans = 0;
int a[100005];
int visit[100005] = {0};
vector<int> e[100005];
typedef long long ll;

bool judge(int a, int b)
{
      ll d = a * b;
      double s = sqrt(d);
      ll ss = (ll)s;
      // cout << "ss: " << ss << " s: " << s << endl;
      if (ss == s)
            return true;
      else
            return false;
}

void dfs(int u, int f)
{
      // cout << "u1: " << u << " f1: " << f << endl;
      for (int s : e[u])
      {
            // cout << "s: " << s << " u: " << u << endl;
            if (s == f)
                  continue;
            dfs(s, u);
            if (visit[u] == 0 && visit[s] == 0 && judge(a[u], a[s]) == true && a[u] != 0)
            {
                  ans += 2;
                  visit[u] = 1;
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
            int u, v;
            cin >> u >> v;
            e[u].push_back(v);
            e[v].push_back(u);
      }
      dfs(1, 0);
      cout << ans << endl;
      return 0;
}