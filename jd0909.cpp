#include <bits/stdc++.h>
using namespace std;

int main()
{
      int n;
      cin >> n;
      vector<int> a(n + 1);
      for (int i = 1; i <= n; i++)
      {
            cin >> a[i];
      }
      long long res = 0;
      long long mod = 1e9 + 7;
      for (int i = 1; i <= n; ++i)
      {
            long long cnt = ((i + 1) * i / 2) % mod;
            res = (res + (n - i + 1) * cnt * a[i]) % mod;
      }
      cout << res << "\n";
      return 0;
}