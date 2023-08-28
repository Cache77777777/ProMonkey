#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    map<int, int> id;
    for (int i = 0; i < n ; ++ i) {
        cin >> a[i];
        b[i] = a[i] - k;
    }
    int sum = 0;
    int res = 0;
    id[0] = -1;
    for (int i = 0; i < n ; ++i) {
        sum += b[i];
        if (id.find(sum) == id.end()) {
            id[sum] = i;
        } else {
            res = max(res, i - id[sum]);
        }
    }
    cout << res << endl;
    return 0;
}
