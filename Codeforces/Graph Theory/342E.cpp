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
#define set(x,y) x=(x|(1LL<<y))
#define off(x,y) x=(x&(~(1LL<<y)))
#define pi acos(-1)
#define inf (1<<30)
#define N  500005
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

/// decompose(1, -1)   //For 1 rooted tree

#define ll long long
#define pb push_back
const ll MAX = 1e5;
vector <ll> g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], curSize,n,m,pre[MAX + 9],dist[MAX + 9],level[MAX + 9],par[MAX + 9];

void dfs(ll u, ll p)

{

    sz[u] = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd])
            continue;
        dfs(nd, u);
        sz[u] += sz[nd];
    }
}

void dfs1(ll node,ll pr, ll h){
    level[node]=h;
    pre[node]=pr;
    for(auto to : g[node]){
        if(to==pr) continue;
        dfs1(to,node,h+1);
    }

}

ll findCentroid(ll u, ll p)

{
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i];
        if(nd == p || del[nd] || sz[nd] <= curSize / 2)
            continue;

        return findCentroid(nd, u);
    }
    return u;
}



void decompose(ll u, ll p)
{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);

    par[cen]=p;
    del[cen] = 1;


    for(ll i = 0 ; i<g[cen].size() ; i++){
        ll nd=g[cen][i];

        if(!del[nd]){
            decompose(nd, cen);
        }
    }
    //nl;
}

ll table[20][MAX + 9];

void build_table(int n){
    int i,j;
    for(i=1 ; i<=n ; i++) table[0][i] = pre[i];
    for(i=1 ; (1<<i)<n ; i++){
        for(j=1 ; j<=n ; j++){
            if(table[i-1][j]!=-1) table[i][j]=table[i-1][table[i-1][j]];
        }
    }

    return ;
}
int lca_query(int n, int p, int q)
{
    int tmp, log, i;

    if (level[p] < level[q]) swap(p,q);

    log=1;
    while(1) {
        int next=log+1;
        if((1<<next)>level[p]) break;
        log++;

    }

    for(i = log; i >= 0; i--){
        if (level[p] - (1 << i) >= level[q]) p = table[i][p];
    }

    if(p == q) return p;

    for(i = log; i >= 0; i--){
        if (table[i][p] != -1 && table[i][p] != table[i][q]){
            p = table[i][p];
            q = table[i][q];
        }
    }
    return pre[p];
}

void update(ll node){

    dist[node]=0;
    ll nn=par[node];

    while(1){
        if(nn==-1) break;

        ll p=lca_query(n,nn,node);

        dist[nn]=min(dist[nn],level[node]+level[nn]-2*level[p]);

        nn=par[nn];
    }

}

ll query(ll node){
    ll ret=INT_MAX;
    ll nn=node;
    while(1){
        if(nn==-1) break;

        ll p=lca_query(n,nn,node);

        ll d=level[node]+level[nn]-2*level[p];

        ret=min(ret,d+dist[nn]);

        nn=par[nn];
    }

    return ret;

}



int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    fastio;

    ll i,j;
    cin>>n>>m;

    for(i=1 ; i<n ; i++){
        ll u,v;
        cin>>u>>v;

        g[u].pb(v);
        g[v].pb(u);
    }

    decompose(1,-1);

    for(i=1 ; i<=n ; i++) dist[i]=INT_MAX;

    dfs1(1,-1,0);

    build_table(n);

    update(1);


    while(m--){
        ll t,v;
        cin>>t>>v;

        if(t==1) update(v);
        else{
            cout<<query(v);
            nl;
        }
    }



    return 0;


}
