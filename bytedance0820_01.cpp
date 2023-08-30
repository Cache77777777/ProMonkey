#include <bits/stdc++.h>
using namespace std;

int main()
{
      int t, n, k;
      cin >> t;
      vector<int> ans;
      for (int i = 0; i < t; ++i)
      {
            int n, k;
            vector<int> a(3);
            cin >> n >> k >> a[0] >> a[1] >> a[2];
            if (3 * k > n)
            {
                  ans.push_back(-1);
                  continue;
            }
            int res = 0;
            int d[3];
            sort(a.begin(), a.end());
            d[0] = a[1] - a[0];
            d[1] = a[2] - a[1];
            d[2] = a[0] + n - a[2];
            if (d[0] < k)
            {
                  res += (k - d[0]);
            }
            if (d[1] < k)
            {
                  res += (k - d[1]);
            }
            if (d[2] < k)
            {
                  res += (k - d[2]);
            }
            ans.push_back(res);
      }
      for (int i = 0; i < t; ++i)
      {
            cout << ans[i] << endl;
      }
      return 0;
}