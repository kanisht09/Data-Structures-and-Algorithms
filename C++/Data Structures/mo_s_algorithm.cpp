#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")
#define ll long long int
using namespace std;


const int blk = 700;

struct query
{
    int l, r, ind;
};

bool comp(query &a, query &b)
{
    if (a.l / blk != b.l / blk)
        return a.l / blk < b.l / blk;
    return (a.r < b.r) ;
}

int n, nq;
vector<int>a(30001);
query q[200001];

int ct = 0;
int m[1000001];
int ans[1000001];



void add(int pos) {
    m[a[pos]]++;
    if (m[a[pos]] == 1)
        ct++;
}
void remove(int pos) {
    m[a[pos]]--;
    if (m[a[pos]] == 0)
        ct--;
}


int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    ll t;
    t = 1;
    // cin >> t;

    while (t--)
    {
        ct = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> a[i];

        cin >> nq;
        for (int i = 0; i < nq; i++) {
            cin >> q[i].l >> q[i].r;
            q[i].l--, q[i].r--;
            q[i].ind = i;
        }
        sort(q, q + nq, comp);
        int ml = 0;
        int mr = -1;
        for (int i = 0; i < nq; i++) {

            int cl = q[i].l;
            int cr = q[i].r;
            while (ml > cl)
            {
                ml--;
                add(ml);
            }
            while (mr < cr)
            {
                mr++;
                add(mr);
            }
            while (ml < cl)
            {
                remove(ml);
                ml++;
            }
            while (mr > cr)
            {
                remove(mr);
                mr--;
            }
            ans[q[i].ind] = ct;
        }
        for (int i = 0; i < nq; i++) {
            cout << ans[i] << '\n';
        }

    }


    return 0;
}
