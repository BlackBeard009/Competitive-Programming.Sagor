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
#define N  100005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

int n,m,dp[N];
vector <int> g[N];
vector < pair<int,int> > ed;


int solve(int node){
    if(dp[node]!=-1) return dp[node];

    int ret=1;

    for(auto to : g[node]){
        ret=max(ret,1+solve(to));
    } 

    return dp[node]=ret;
}

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    fastio ; 

    int i,j;

    cin>>n>>m;

    memset(dp,-1,sizeof(dp));

    for(i=1 ; i<=m ; i++){
        int u,v;
        cin>>u>>v;

        g[u].pb(v);
        ed.pb({u,v});
    }

    int ans=-1,node=-1;

    for(i=1 ; i<=n ; i++){
        if(ans<solve(i)){
            ans=solve(i);
            node=i;
        }
    }

    if(ans!=n) cout<<"-1";
    else{
        vector < pair<int,int> > vv;

        for(i=1 ; i<=n ; i++){
            vv.pb({dp[i],i});
        } 

        sort(vv.begin(),vv.end());

        map < pair <int,int> , bool > val;

        for(i=0 ; i<n-1 ; i++){
            val[{vv[i+1].second,vv[i].second}]=true;
        }

        while(ed.size()){
            auto it = lst(ed);

            if(val[it]) break;

            ed.ppb();

        }

        cout<<ed.size();
        nl;



    }



    
    
    
    return 0;
    

}