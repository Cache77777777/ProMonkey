#include <bits/stdc++.h>
using namespace std;

int main()
{
      string s;
      cin >> s;
      int n = s.length();
      char s1[2005] = {'0'}, s2[2005] = {'1'};
      for (int i = 1; i < n; ++i)
      {
            if (s1[i - 1] == '0')
            {
                  s1[i] = '1';
            }
            else
            {
                  s1[i] = '0';
            }
            if (s2[i - 1] == '0')
            {
                  s2[i] = '1';
            }
            else
            {
                  s2[i] = '0';
            }
      }
      vector<int> c1(n + 1), c2(n + 1);
      for (int i = 1; i <= n; ++i)
      {
            if (s[i - 1] == s1[i - 1])
            {
                  c1[i] = c1[i - 1];
                  c2[i] = c2[i - 1] + 1;
            }
            else
            {
                  c1[i] = c1[i - 1] + 1;
                  c2[i] = c2[i - 1];
            }
      }
      int res = 0;
      for (int i = 1; i <= n; ++i)
      {
            for (int j = i; j <= n; ++j)
            {
                  res += min(c1[j] - c1[i - 1], c2[j] - c2[i - 1]);
            }
      }
      cout << res << endl;
      return 0;
}
