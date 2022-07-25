#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization ("unroll-loops")

#define ull unsigned ll
#define ll long long int
#define ld long double
#define pll pair<ll,ll>
#define piii pair<int,pair<int,int>>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

#define F(i,a,n) for(int i=a;i<n;i++)
#define vll vector<ll>
#define vi vector<int>
#define tcf ll t;cin>>t;for(int w=1;w<=t;w++)
#define Ans(a,b) cout<<"Case #"<<a<<": "<<b<<"\n";

#define INF 100000000000


ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}


#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>



using namespace std;



struct Node {
    Node* links[26];
    bool flag = false;
    int cp = 0;
    int ew = 0;
    bool containsKey(char x) {
        return links[x - 'a'] != NULL;
    }
    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }
};

class Trie {

    Node* root;

public:

    Trie() {
        root = new Node();
    }
    void insert(string word) {

        Node* node = root;
        for (auto ch : word) {
            if (!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->links[ch - 'a'];
            node->cp += 1;

        }
        node->ew += 1;
        node->flag = true;
    }
    bool search(string word) {
        Node* node = root;
        for (auto ch : word) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->links[ch - 'a'];
        }
        return node->flag;
    }
    bool startsWith(string pref) {

        Node* node = root;
        for (auto ch : pref) {
            if (!node->containsKey(ch)) {
                return false;
            }
            node = node->links[ch - 'a'];
        }
        return true;
    }

    int countWordsEqualTo(string &word) {
        // Write your code here.
        Node* node = root;
        for (auto ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->links[ch - 'a'];
        }
        return node->ew;

    }

    int countWordsStartingWith(string &word) {
        Node* node = root;
        for (auto ch : word) {
            if (!node->containsKey(ch)) {
                return 0;
            }
            node = node->links[ch - 'a'];
        }
        return node->cp;
    }

    void erase(string &word) {
        Node* node = root;
        for (auto ch : word) {
            node = node->links[ch - 'a'];
            node->cp -= 1;
        }
        node->ew -= 1;
    }
};


int main()
{


    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int  t;
    t = 1;
    // cin >> t;
    while (t--) {


       
    }
    return 0;

}



