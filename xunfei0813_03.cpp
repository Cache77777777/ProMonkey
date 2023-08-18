#include <bits/stdc++.h>
using namespace std;

int main()
{
      int n;
      cin >> n;
      vector<int> a(n), b(n);
      vector<int> idxa(n), idxb(b);
      for (int i = 0; i < n; i++)
      {
            cin >> a[i];
            idxa[a[i]] = i;
      }
      for (int i = 0; i < n; i++)
      {
            cin >> b[i];
            idxb[b[i]] = i;
      }
      int total = n * (n + 1);
      for (int i = 0; i < n; i++)
      {
            int tmp = a[i];
            int id = idxb[a[i]];
            int cnt = 1;
            for (int j = 1; j < n - i; j++)
            {
                  if (a[i + j] == b[id + j])
                  {
                        cnt++;
                  }
                  else break;
            }
            total -= cnt * (cnt + 1) / 2;
      }
      cout << total << endl;
      return 0;
}