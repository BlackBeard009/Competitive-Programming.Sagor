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
#define N  100005
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

ll cnt[N],col[N],sz[N],n,ans[N],sum[N];
bool big[N];
vector <int> g[N];
set <ll> st;
void add(int v, int p, int x){
    if(cnt[col[v]]){
        sum[cnt[col[v]]]-=col[v];
        if(sum[cnt[col[v]]]==0){
            st.erase(cnt[col[v]]);
        }
    }

    cnt[col[v]]+=x;

    if(cnt[col[v]]){
        int prv=sum[cnt[col[v]]];
        sum[cnt[col[v]]]+=col[v];
        if(!prv) st.insert(cnt[col[v]]);
    }


    for(auto u: g[v])
        if(u != p && !big[u])
            add(u, v, x);
}
void dfs(int v, int p, bool keep){
    int mx = -1, bigChild = -1;
    for(auto u : g[v])
       if(u != p && sz[u] > mx)
          mx = sz[u], bigChild = u;
    for(auto u : g[v])
        if(u != p && u != bigChild)
            dfs(u, v, 0);  // run a dfs on small childs and clear them from cnt
    if(bigChild != -1)
        dfs(bigChild, v, 1), big[bigChild] = 1;  // bigChild marked as big and not cleared from cnt
    add(v, p, 1);
    //now cnt[c] is the number of vertices in subtree of vertex v that has color c. You can answer the queries easily.
    if(st.size()){
        auto it = st.end();
        it--;
        ans[v]= sum[*it];
    }
    else ans[v]=0;

    if(bigChild != -1)
        big[bigChild] = 0;
    if(keep == 0)
        add(v, p, -1);
}

void dfs1(int node,int par){
    sz[node]=1;

    for(auto to : g[node]){
        if(to!=par){
            dfs1(to,node);
            sz[node]+=sz[to];
        }
    }
}

int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    
    int i,j;
    cin>>n;

    for(i=1 ; i<=n ; i++){
        cin>>col[i];
    }

    for(i=1 ; i<n ; i++){
        int u,v;
        cin>>u>>v;

        g[u].pb(v);
        g[v].pb(u);
    }

    dfs1(1,-1);

    dfs(1,-1,1);

    
    for(i=1 ; i<=n ; i++) cout<<ans[i]<<" ";
    nl;


    return 0;
    

}