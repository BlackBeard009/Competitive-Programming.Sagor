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

vector < pair<int,int> > ed;
vector <int> g[N];
int vis[N],level[N],n;
void dfs(int node,int par){
    vis[node]=1;
    for(auto to : g[node]){
        if(to==par) continue;
        level[to]=level[node]+1;
        dfs(to,node);
    }
}
int main()
{
    fastio;

    int i,j;

    cin>>n;

    for(i=1 ; i<n ; i++){
        int u,v;
        cin>>u>>v;
        ed.pb({u,v});
    }

    int ans=0;


    for(i=0 ; i<ed.size() ; i++){
        for(j=0 ; j<=n ; j++){
            g[j].clear();
            vis[j]=0;
            level[j]=-1;
        }
        for(j=0 ; j<ed.size() ; j++){
            if(i==j) continue;
            int u=ed[j].first,v=ed[j].second;
            g[u].pb(v);
            g[v].pb(u);
        }
        level[1]=0;
        dfs(1,0);
        int mx=-1,nd=-1;
        for(j=1 ; j<=n ; j++){
            if(level[j]>=mx){
                mx=level[j];
                nd=j;
            }
        }
        memset(vis,0,sizeof(vis));
        memset(level,-1,sizeof(level));
        level[nd]=0;
        dfs(nd,0);
        mx=-1;
        for(j=1 ; j<=n ; j++){
            if(level[j]>=mx){
                mx=level[j];
            }
        }

        int d1=mx,nvis=-1;
        for(j=1 ; j<=n ; j++){
            if(!vis[j]){
                nvis=j;
                break;
            }
        }

        memset(level,-1,sizeof(level));
        level[nvis]=0;
        dfs(nvis,0);

        mx=-1,nd=-1;

        for(j=1 ; j<=n ; j++){
            if(level[j]>=mx){
                mx=level[j];
                nd=j;
            }
        }
        memset(level,-1,sizeof(level));
        level[nd]=0;
        dfs(nd,0);
        mx=-1;
        for(j=1 ; j<=n ; j++){
            if(level[j]>=mx){
                mx=level[j];
            }
        }

        int d2=mx;

        ans=max(ans,d1*d2);


    }

    cout<<ans;
    nl;


    return 0;

}
