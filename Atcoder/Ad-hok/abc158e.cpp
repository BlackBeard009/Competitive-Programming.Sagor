/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
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
#define N  200005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/


ll cnt[10005];

int main()
{
    fastio;

    ll n,p,i,j;
    string s;
    cin>>n>>p;
    cin>>s;


    reverse(s.begin(),s.end());

    if(p==2 || p==5){
        ll ans=0;
        for(i=0 ; i<s.size() ; i++){
            if((s[i]-'0')%p==0) ans+=(n-i);
        }
        cout<<ans;
        nl;
        return 0;
    }

    cnt[0]++;
    ll ans=0,sum=0,pp=1;

    for(i=0 ; i<s.size() ; i++){
        sum=(sum+((s[i]-'0')*pp)%p)%p;
        ans+=cnt[sum];
        cnt[sum]++;
        pp=(pp*10)%p;
    }

    cout<<ans;
    nl;




    return 0;

}
