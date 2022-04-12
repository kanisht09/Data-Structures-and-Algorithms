#include <bits/stdc++.h>
#define ll long long int
using namespace std;


//  SQRT DECOMPOSITION  : GENRIC TEMPLATE
// Complexity :  O(Q*sqrt(N))
// O(N) : pre-computation


// Problem link :  https://cses.fi/problemset/task/1647


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    t = 1;
    // cin >> t;

    while (t--)
    {

        int n, q;
        cin >> n >> q;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // Preprocessing

        int len = (int)sqrt(n + 0.1) + 1;
        vector<int>b(len, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            b[i / len] = min(a[i], b[i / len]);
        }

        // Answering the queries


        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int res = INT_MAX;
            int lb = l / len;
            int rb = r / len;
            if (rb == lb)
            {
                for (int i = l; i <= r; i++)
                    res = min(res, a[i]);
            }
            else
            {
                for (int i = l; i < (lb + 1)*len; i++)
                {
                    res = min(res, a[i]);
                }
                for (int i = lb + 1; i < rb; i++)
                {
                    res = min(res, b[i]);
                }
                for (int i = rb * len; i <= r; i++)
                {
                    res = min(res, a[i]);
                }
            }
            cout << res << '\n';
        }

    }


    return 0;
}
