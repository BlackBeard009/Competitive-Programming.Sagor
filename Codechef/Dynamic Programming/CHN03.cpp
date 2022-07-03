
/*I am the stupidest person alive if this gets AC*/
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
#define N  55
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

ll n,k,t,dp[N][N][N][N],tt[N][3],pp[N][3];

ll solve(ll pos,ll tm,ll sp,ll tk){
    if(tm>t || sp>k || tk>n) return -inf;
    if(tk==n) return 0;
    if(pos>n) return 0;

    if(dp[pos][tm][sp][tk]!=-1) return dp[pos][tm][sp][tk];

    ll ret=0,i,j;

    for(i=0 ; i<=7 ; i++){
        ll tmcnt=0,tkcnt=0,point=0;

        for(j=0 ; j<3 ; j++){
            if(check(i,j)){
                tmcnt+=tt[pos][j];
                tkcnt++;
                point+=pp[pos][j];
            }
        }
        ll spcnt=max(0LL,tkcnt-1);
        ret=max(ret,point+solve(pos+1,tm+tmcnt,sp+spcnt,tk+tkcnt));
    }

    return dp[pos][tm][sp][tk]=ret;




}


int main()
{
    fastio;

    int ti;
    cin>>ti;

    while(ti--){
        ll i,j,x,y;
        cin>>n>>k>>t;

        for(i=0 ; i<=n+2 ; i++){
            for(j=0 ; j<=t+2 ; j++){
                for(x=0 ; x<=n+2 ; x++){
                    for(y=0 ; y<=n+2 ; y++) dp[i][j][x][y]=-1;
                }
            }
        }

        for(i=1 ; i<=n ; i++) cin>>tt[i][0]>>tt[i][1]>>tt[i][2];
        for(i=1 ; i<=n ; i++) cin>>pp[i][0]>>pp[i][1]>>pp[i][2];

        k=min(k,n);

        cout<<solve(1,0,0,0);
        nl;

    }




    return 0;

}
