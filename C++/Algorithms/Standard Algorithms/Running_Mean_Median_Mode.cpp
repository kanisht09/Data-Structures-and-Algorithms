#include <bits/stdc++.h>
#define mod 1000000007
#define ull unsigned ll
#define ll long long int
#define ld long double
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi acos(-1)
#define nui 100
#define INF 100000000000

#define F(i,a,n) for(ll i=a;i<n;i++)
#define B(i,a,n) for(ll i=n-1;i>=a;i--)
#define tc int t;cin>>t;while(t--)
#define tcf int t;cin>>t;for(int w=1;w<=t;w++)

using namespace std;

struct runningMean {

  ll sum, ct;
  runningMean() {
    sum = ct = 0;
  }
  void add(ll x) {
    sum += x;
    ct++;
  }
  void remove(ll x) {
    sum -= x;
    ct--;
  }
  ld getMean() {
    ld temp = sum;
    return temp / ct;
  }


} mean;


struct runningMedian {

  multiset<ll>lo, hi;

  void add(ll x) {
    if (!lo.empty()) {
      auto it = lo.rbegin();
      if (x <= *it) {
        lo.insert(x);
        return;
      }
    }
    if (!hi.empty()) {
      auto it = hi.begin();
      if (x >= *it) {
        hi.insert(x);
        return;
      }
    }
    lo.insert(x);
  }
  void remove(ll x) {
    if (!lo.empty()) {
      auto it = lo.rbegin();
      if (x <= *it) {
        lo.erase(lo.find(x));
        return;
      }
    }
    if (!hi.empty()) {
      auto it = hi.begin();
      if (x >= *it) {
        hi.erase(hi.find(x));
        return;
      }

    }
  }
  void rebalance() {
    while (lo.size() >= hi.size() + 2) {
      auto it = lo.end();
      it--;
      ll val = *it;
      lo.erase(it);
      hi.insert(val);
    }
    while (hi.size() > lo.size()) {
      auto it = hi.begin();
      ll val = *it;
      hi.erase(it);
      lo.insert(val);
    }
  }
  ld getMedian() {

    rebalance();
    auto it1 = lo.end();
    it1--;
    auto it2 = hi.begin();
    if (lo.size() == hi.size()) {


      ld val = *it1;
      return (val + *it2) / 2.0;
    }
    else {
      return *it1;
    }

  }

} median;



struct runningMode {

  map<ll, ll>freq;
  set<pair<ll, ll>>s;

  void add(ll x)
  {

    if (freq.find(x) != freq.end())
    {
      s.erase({freq[x], x});
    }

    freq[x]++;

    s.insert({freq[x], x});

  }

  void remove(ll x)
  {

    if (freq.find(x) != freq.end())
    {
      s.erase({freq[x], x});

      freq[x]--;

      if (freq[x] == 0) {
        freq.erase(x);
      }
      else {
        s.insert({freq[x], x});

      }
    }

  }

  ll getMode() {
    //  In case of ties return the lowest value.
    ll ans;
    ll mxfreq = (*s.rbegin()).ff;
    auto it = s.lower_bound({mxfreq, INT_MIN});
    ans = (*it).ss;
    return ans;

  }



} Mode;


int main()
{



  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t;
  t = 1;
  // cin >> t;

  while (t--)
  {

    runningMean a;
    a.add(6);
    a.add(3);
    // cout << a.getMean() << '\n' ;


    runningMode b;
    b.add(3);
    b.add(2);
    b.add(1);
    // b.add(3);

    // b.add(2);
    // b.add(3);
    // cout << b.getMode();


    runningMedian c;
    c.add(1);
    c.add(2);
    cout << c.getMedian() << '\n';

    c.add(3);
    cout << c.getMedian() << '\n';

  }
  return 0;

}
