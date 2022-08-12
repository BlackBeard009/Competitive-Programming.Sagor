/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
*/
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define powr(x,n,p) for(int axy=0 ; axy<p ; axy++){x=x*n;}
#define YES cout<<"YES\n"
#define Yes cout<<"Yes\n"
#define yes cout<<"yes\n"
#define NO cout<<"NO\n"
#define No cout<<"No\n"
#define no cout<<"no\n"
#define nl cout<<"\n"
#define fr0(n,q) for(q=0 ; q<n ; q++)
#define fr1(n,q) for(q=1 ; q<=n ; q++)
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define lst(x) x[x.size()-1]
#define llst(x) x[x.size()-2]
#define md 1000000000
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=(x|(1LL<<y))
#define off(x,y) x=(x&(~(1LL<<y)))
#define pi acos(-1)
#define inf (1<<30)
#define N  200005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3

/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

struct line {
    ll m, c; // y = mx+c
    line(ll _m, ll _c) {
        m = _m, c = _c;
    }
};

struct CHT {
    vector < line > vec;
    ll t, ptr;
    void init(ll x) {
        t = x, ptr = 0;
        vec.clear();
    }
    inline ll func(ll idx, ll x) {
        return vec[idx].m * x + vec[idx].c;
    }
    bool bad(line f1, line f2, line f3) {
        ll a = (f3.c - f1.c);
        a = a * (f1.m - f2.m);
        ll b = (f2.c - f1.c);
        b = b * (f1.m - f3.m);

        if(t == 1) return a <= b; // m_i > m_i+1. min query.
        if(t == 2) return a >= b; // m_i > m_i+1. max query.
        if(t == 3) return a >= b; // m_i < m_i+1. min query.
        if(t == 4) return a <= b; // m_i < m_i+1. max query.
        assert(0);
    }
    void add(line x) {
        ll sz = vec.size();
        while(sz >= 2 && bad(vec[sz - 2], vec[sz - 1], x)) {
            vec.pop_back();
            sz--;
        }
        vec.push_back(x);
    }
    ll ask(ll x) // ternary search
    {
        if(vec.empty())
        return 0;

        ll lo = 0, hi = vec.size() - 1;
        ll ret = (t & 1)? LLONG_MAX : LLONG_MIN;
        while(lo <= hi) {
            ll mid1 = (lo + (hi - lo) / 3);
            ll mid2 = (hi - (hi - lo) / 3);

            ll ans1 = func(mid1,x);
            ll ans2 = func(mid2,x);

            if(ans1 > ans2) {
                if(t & 1)
                    ret = min(ret, ans2), lo = mid1 + 1;
                else
                    ret = max(ret, ans1), hi = mid2 - 1;
            }
            else {
                if(t & 1)
                    ret =  min(ret,ans1), hi = mid2 - 1;
                else
                    ret = max(ret,ans2), lo = mid1 + 1;
            }
        }
        return ret;
    }
    ll ask1(ll x) // pointer search (linear)
    {
        if(vec.empty())
            return 0;
        if(ptr >= vec.size()) ptr = vec.size() - 1;

        while(ptr < (vec.size() - 1)) {
            if(t & 1) {
                if(func(ptr,x) > func(ptr + 1,x))
                    ptr++;
                else break;
            }
            else {
                if(func(ptr,x) < func(ptr + 1,x))
                    ptr++;
                else break;
            }
        }
        return func(ptr,x);
    }
};





int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    fastio;

    ll n,c,i,j;
    cin>>n>>c;

    ll arr[n];

    fr0(n,i) cin>>arr[i];

    CHT solve;
    solve.init(1);


    ll ans;

    line xx(-2*arr[0],arr[0]*arr[0]);
    solve.add(xx);

    for(i=1 ; i<n ; i++){
        ans=solve.ask(arr[i]);
        ans+=(arr[i]*arr[i]+c);

        


        line tmp(-2*arr[i],arr[i]*arr[i]+ans);
        solve.add(tmp);
    }

    cout<<ans;
    nl;

    

    


    
    


    return 0;


}