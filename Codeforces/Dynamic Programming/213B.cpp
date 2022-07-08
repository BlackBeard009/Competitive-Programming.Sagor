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
#define md 1000000007
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=x|(1LL<<y)
#define pi acos(-1)
#define inf (1LL<<60)
#define N  105
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

ll arr[15],dp[15][105],n,m,fact[20005],ifact[20005];

ll powmod(ll x,ll y){
    ll ret=1;

    while(y){
        if(y%2) ret=(ret*x)%md;
        x=(x*x)%md;
        y/=2;
    }

    return ret;
}

ll solve(ll pos,ll cnt){
    if(cnt<0) return 0;
    if(pos==10){
        if(cnt==0) return fact[m];
        return 0;
    }
    if(dp[pos][cnt]!=-1) return dp[pos][cnt];

    ll ret=0,i,j;

    for(i=arr[pos] ; i<=cnt ; i++){
        ll tmp=solve(pos+1,cnt-i);
        tmp=(tmp*ifact[i])%md;
        ret=(ret+tmp)%md;
    }

    return dp[pos][cnt]=ret;


}


int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    ll i,j;
    cin>>n;

    fact[0]=1;

    for(i=1 ; i<=20000 ; i++) fact[i]=(fact[i-1]*i)%md;
    for(i=0 ; i<=20000 ; i++) ifact[i]=powmod(fact[i],md-2);

    ll sum=0;

    for(i=0 ; i<10 ; i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    if(sum>n || arr[0]==n){
        cout<<0;
        nl;
        return 0;
    }

    ll ans=0;

    for(i=sum-arr[0] ; i<=n-arr[0] ; i++){
        m=i;
        memset(dp,-1,sizeof(dp));
        /*cout<<solve(1,i);
        nl;*/
        ll x=solve(1,i);


        for(j=arr[0] ; j<=n-m ; j++){
            ll y=x;
            y=(y*fact[i+j-1])%md;
            y=(y*ifact[j])%md;
            y=(y*ifact[i-1])%md;
            ans=(ans+y)%md;
        }
    }

    cout<<ans;
    nl;








    return 0;


}
