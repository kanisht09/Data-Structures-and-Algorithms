#include <bits/stdc++.h>
#define ll long long
#define ff first
#define ss second
#define pb push_back
using namespace std;
const int N = 200001;

// problem link : https://www.spoj.com/problems/INVCNT/


ll bit[N + 5];

void update(int i, ll x) {
    for (; i < N; i += i & (-i)) {
        bit[i] += x;
    }
}
ll sum(int i) {

    ll res = 0;
    for (; i > 0; i -= i & (-i)) {
        res += bit[i];
    }
    return res;
}
ll sum(int l, int r) {
    return sum(r) - sum(l - 1);
}






int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t;
    t = 1;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<ll>a(n + 1);
        map<ll, int>m;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            m[a[i]] = 1;
        }
        int ct = 1;
        for (auto &i : m) {
            i.ss = ct++;
        }
        for (int i = 1; i <= n; i++) {
            a[i] = m[a[i]];
        }
        ll c = 0;
        for (int i = 1; i <= n; i++)
        {
            c += sum(a[i], N);
            update(a[i], 1);
        }
        cout << c << '\n';
        for (int i = 1; i < N; i++) {
            bit[i] = 0;
        }


    }
    return 0;


}



