#include <bits/stdc++.h>
using namespace std;

bool judge(string s)
{
      // cout << s << endl;
      int l = s.size();
      for (int i = 0; i < l / 2; i++)
      {
            if (s[i] != s[l - 1 - i])
                  return false;
      }
      return true;
}
int main()
{
      int n;
      cin >> n;
      vector<string> ss(n);
      for (int i = 0; i < n; i++)
      {
            cin >> ss[i];
      }
      for (int i = 0; i < n; i++)
      {
            string t;
            for (int j = 0; j < ss[i].size(); j++)
            {
                  char ch = ss[i][j];
                  if (ch == 'w')
                  {
                        t += "vv";
                  }
                  else if (ch == 'm')
                  {
                        t += "nn";
                  }
                  else if (ch == 'b' || ch == 'd' || ch == 'p' || ch == 'q')
                  {
                        t += 'b';
                  }
                  else if (ch == 'u' || ss[i][j] == 'n')
                  {
                        t += 'n';
                  }
                  else
                  {
                        t += ch;
                  }
            }
            if (judge(t))
                  cout << "Yes\n";
            else
                  cout << "No\n";
      }
      return 0;
}