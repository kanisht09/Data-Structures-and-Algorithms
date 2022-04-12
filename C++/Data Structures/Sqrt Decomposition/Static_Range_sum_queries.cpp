#include <bits/stdc++.h>
#define ll long long int
using namespace std;


//  SQRT DECOMPOSITION  : GENRIC TEMPLATE
// Complexity :  O(Q*sqrt(N)) 
// O(N) : pre-computation


// Problem link :  https://cses.fi/problemset/task/1646


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
        vector<ll>b(len);
        for (int i = 0; i < n; i++)
        {
            b[i / len] += a[i];
        }

        // Answering the queries


        while (q--)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            ll sum = 0;
            for (int i = l; i <= r;)
            {
                if (i % len == 0 && i + len - 1 <= r)
                {
                    sum += b[i / len];
                    i += len;
                }
                else
                {
                    sum += a[i];
                    i++;
                }
            }
            cout << sum << '\n';
        }

    }


    return 0;
}
