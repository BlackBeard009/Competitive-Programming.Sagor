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
ll del[MAX + 9], sz[MAX + 9], curSize,n,arr[MAX + 9];

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

ll cnt1[20],cnt0[20],ans;

void solve(ll node, ll par,ll t,ll val){
    val^=arr[node];
    ll i,j;



    if(t==0){

        for(i=0 ; i<20 ; i++){
            if(check(val,i)) cnt1[i]++;
            else cnt0[i]++;
        }

        for(auto to : g[node]){
            if(to==par || del[to]) continue;
            solve(to,node,t,val);
        }
    }
    else{
        for(i=0 ; i<20 ; i++){
            if(check(val,i)) cnt1[i]--;
            else cnt0[i]--;
        }

        for(auto to : g[node]){
            if(to==par || del[to]) continue;
            solve(to,node,t,val);
        }
    }
}

void calc(ll node, ll par , ll val){
    val^=arr[node];

    ll i,j;

    ans+=(val*2);

    ll xx=1;

    for(i=0 ; i<20 ; i++){
        if(check(val,i)){
            ans+=(cnt0[i]*xx);
        }
        else ans+=(cnt1[i]*xx);

        xx*=2;
    }

    for(auto to : g[node]){
        if(to==par || del[to]) continue;
        calc(to,node,val);
    }

}

void decompose(ll u, ll p)

{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;

    del[cen] = 1;


    memset(cnt1,0,sizeof(cnt1));
    memset(cnt0,0,sizeof(cnt0));

    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd]){
            solve(nd,cen,0,0);
        }
    }


    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i];

        if(!del[nd]){
            solve(nd,cen,1,0);
            calc(nd,cen,arr[cen]);
            solve(nd,cen,0,0);
        }
    }





    for(ll i = 0 ; i<g[cen].size() ; i++){
        ll nd=g[cen][i];

        if(!del[nd]){
            decompose(nd, cen);
        }
    }
    //nl;


}


int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    fastio;

    ll i,j;
    cin>>n;

    for(i=1 ; i<=n ; i++) cin>>arr[i];

    for(i=1 ; i<n ; i++){
        ll u,v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    decompose(1,-1);



    for(i=1 ; i<=n ; i++) ans+=arr[i]*2;

    cout<<ans/2;
    nl;




    return 0;


}
