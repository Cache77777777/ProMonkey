#include <bits/stdc++.h>
using namespace std;

int main()
{
      string s;
      cin >> s;
      unordered_set<char> sh;
      string t;
      for (auto c : s)
      {
            sh.insert(c);
      }
      if (sh.size() == 1)
      {
            cout << -1 << endl;
            return 0;
      }
      vector<char> l(sh.begin(), sh.end());
      for (int i = 0; i < s.size(); i++)
      {
            int flag = 0;
            for (char c : sh)
            {
                  if (s[i] != c)
                  {
                        t.push_back(c);
                        sh.erase(c);
                        flag = 1;
                        break;
                  }
            }
            if (!flag)
            {
                  if (l[0] != s[i])
                  {
                        t.push_back(l[0]);
                  }
                  else
                  {
                        t.push_back(l[1]);
                  }
            }
      }
      cout << t << endl;
      return 0;
}