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
#define N  3005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

ll n,cc[N];

int dp[N][N];

int solve(int i,int j){
    if(j==n) return 1;

    if(dp[i][j]!=-1) return dp[i][j];

    int ret=solve(i,j+1);
    int lo=j+1,hi=n;

    

    while(lo<hi){
        int mid=(lo+hi)/2;

        if(cc[mid]-cc[j]>=cc[j]-cc[i-1]) hi=mid;
        else lo=mid+1;
    }

    if(lo<=n && cc[lo]-cc[j]>=cc[j]-cc[i-1]) ret=max(ret,1+solve(j+1,lo));

    return dp[i][j]=ret;


}


int main()
{
    
    
    ll i,j;
    cin>>n;

    for(i=1 ; i<=n ; i++){
        cin>>cc[i];
        cc[i]+=cc[i-1];
    }

    memset(dp,-1,sizeof(dp));

    cout<<n-solve(1,1);
    nl;
    

    return 0;

}
