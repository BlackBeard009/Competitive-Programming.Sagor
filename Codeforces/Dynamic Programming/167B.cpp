
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
#define N  205
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

int n,l,k,vis[N][N][N],a[N],b[N];
double dp[N][N][N];
vector < pair<int,int> > vv;

double solve(int pos,int rem,int sp){
    if(sp<0) return 0;
    if(rem<0) return 0;
    if(pos==n){
        if(rem==0) return 1;
        return 0;
    }

    if(vis[pos][rem][sp]) return dp[pos][rem][sp];

    vis[pos][rem][sp]=1;

    double ret=(1-vv[pos].second/100.0)*solve(pos+1,rem,sp);

    if(vv[pos].first==-1) ret+=(vv[pos].second/100.0)*solve(pos+1,rem-1,sp-1);
    else ret+=(vv[pos].second/100.0)*solve(pos+1,rem-1,min(sp+vv[pos].first,n));

    return dp[pos][rem][sp]=ret;

}

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/


    int i,j;
    cin>>n>>l>>k;

    for(i=1 ; i<=n ; i++){
        cin>>a[i];
    }
    for(i=1 ; i<=n ; i++) cin>>b[i];

    for(i=1; i<=n ; i++) vv.pb({b[i],a[i]});

    sort(vv.rbegin(),vv.rend());



    double ans=0;

    for(i=l ; i<=n ; i++){
        ans+=solve(0,i,k);
    }

    cout<<setprecision(8)<<fixed<<ans;
    nl;




    return 0;

}
