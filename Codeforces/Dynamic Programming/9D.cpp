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

ll dp1[40][40],dp2[40][40][40],n,h;

ll solve1(ll b,ll e){
    if(b==e){
        return 1;
    }
    if(dp1[b][e]!=-1) return dp1[b][e];

    ll ret=0,i,j;
    for(i=b ; i<=e ; i++){
        if(i==b){
            ret+=solve1(b+1,e);
        }
        else if(i==e){
            ret+=solve1(b,e-1);
        }
        else{
            ret+=(solve1(b,i-1)*solve1(i+1,e));
        }
    }

    return dp1[b][e]=ret;

}

ll solve2(ll b,ll e,ll lvl){
    if(lvl>=h) return 0;
    if(b==e) return 1;
    if(dp2[b][e][lvl]!=-1) return dp2[b][e][lvl];

    ll ret=0,i,j;

    for(i=b ; i<=e ; i++){
        if(i==b){
            ret+=solve2(b+1,e,lvl+1);
        }
        else if(i==e){
            ret+=solve2(b,e-1,lvl+1);
        }
        else{
            ret+=(solve2(b,i-1,lvl+1)*solve2(i+1,e,lvl+1));
        }
    }

    return dp2[b][e][lvl]=ret;
}

int main()
{
    fastio;

    cin>>n>>h;

    memset(dp1,-1,sizeof(dp1));
    memset(dp2,-1,sizeof(dp2));

    cout<<solve1(1,n)-solve2(1,n,1);

    nl;


    return 0;

}
