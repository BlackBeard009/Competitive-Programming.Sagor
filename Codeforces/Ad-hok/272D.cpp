#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
#define md 1000000007
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=x|(1LL<<y)
#define pi acos(-1)
#define inf (1<<30)
#define N  205
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/


int main()
{
    fastio;

    ll n,i,j;
    cin>>n;

    map <int, vector <int> > mpp;

    fr0(n,i){
        cin>>j;
        mpp[j].pb(i);
    }
    fr0(n,i){
        cin>>j;
        mpp[j].pb(i);
    }
    ll ans=1,m;
    cin>>m;
    for(auto it : mpp){
        sort(it.second.begin(),it.second.end());
        vector <ll> ev,od;
        for(i=1 ; i<=it.second.size() ; i++){
            if(i%2==0) ev.pb(i);
            else od.pb(i);
        }

        for(i=1 ; i<it.second.size() ; i++){
            if(it.second[i]==it.second[i-1]){
                od.pb(lst(ev)/2);
                ev.ppb();
            }
        }

        ll tmp=1;

        for(auto it : ev) tmp=(tmp*it)%m;
        for(auto it : od) tmp=(tmp*it)%m;

        ans=(ans*tmp)%m;


    }

    cout<<ans;
    nl;


    return 0;

}
