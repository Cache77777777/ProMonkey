#include <bits/stdc++.h>
using namespace std;

int main()
{
      int n, m;
      cin >> n >> m;
      vector<int> a(n + 1);
      vector<int> l(m + 1), r(m + 1);
      for (int i = 1; i <= n; i++)
      {
            cin >> a[i];
      }
      for (int i = 1; i <= m; i++)
      {
            cin >> l[i] >> r[i];
      }
      vector<int> s(n + 2, 0);
      vector<long long> angry(n+2,0);
      int res = 1;
      int flag = 0;
      while (res <= m && !flag)
      {
            s[l[res]]++;
            s[r[res] + 1]--;
            for (int i = 1; i <= n; ++i) {
                  angry[i] = angry[i-1]+s[i];
                  if (angry[i] > a[i]) {
                        flag = 1;
                        break;
                  }
            }
            res++;
      }
      cout << res - 1 << endl;
}