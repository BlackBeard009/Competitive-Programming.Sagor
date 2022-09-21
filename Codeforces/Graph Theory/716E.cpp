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
vector < pair <ll,ll> > g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], curSize,n,m;

void dfs(ll u, ll p)

{
    sz[u] = 1;
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i].first;
        if(nd == p || del[nd])
            continue;
        dfs(nd, u);
        sz[u] += sz[nd];
    }
}

ll findCentroid(ll u, ll p)

{
    for(ll i = 0; i < g[u].size(); i++) {
        ll nd = g[u][i].first;
        if(nd == p || del[nd] || sz[nd] <= curSize / 2)
            continue;

        return findCentroid(nd, u);
    }
    return u;
}

ll gcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    ll x1, y1;
    ll d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

ll inv(ll a,ll m){
    ll x,y;
    int g = gcd(a, m, x, y);
    x = (x % m + m) % m;

    return x;
}

ll powmods[MAX + 9];

map <ll,ll> cnt;

ll ans;

void solve(ll node, ll par, ll val, ll pp,ll t){

    if(t==0){
        cnt[val]++;
        //if(val==0) ans++;
    }
    else cnt[val]--;

    pp=(pp*10)%m;

    for(auto to : g[node]){
        if(to.first==par || del[to.first]) continue;
        solve(to.first,node,(val+to.second*pp)%m,pp,t);
    }
}


void calc(ll node,ll par,ll val,ll h){
    ll need=(m-val)%m;

    need=(need*powmods[h])%m;

    if(val==0) ans++;

    ans+=cnt[need];

    for(auto to : g[node]){
        if(to.first==par || del[to.first]) continue;
        calc(to.first,node,(val*10 + to.second)%m,h+1);
    }

}

void decompose(ll u, ll p)
{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;

    del[cen] = 1;

    cnt.clear();

    for(ll i=0 ; i<g[cen].size() ; i++){
        ll nd=g[cen][i].first;
        if(del[nd]) continue;
        solve(nd,cen,g[cen][i].second%m,1%m,0);
    }

    ans+=cnt[0];



    for(ll i=0 ; i<g[cen].size() ; i++){
        ll nd=g[cen][i].first;
        if(del[nd]) continue;
        solve(nd,cen,g[cen][i].second%m,1%m,1);
        calc(nd,cen,g[cen][i].second%m,1);
        solve(nd,cen,g[cen][i].second%m,1%m,0);
    }





    for(ll i = 0 ; i<g[cen].size() ; i++){
        ll nd=g[cen][i].first;

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
    cin>>n>>m;

    for(i=1 ; i<n ; i++){
        ll u,v,w;
        cin>>u>>v>>w;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }

    ll xx=1;

    for(i=0 ; i<=n ; i++){
        powmods[i]=inv(xx,m);
        xx=(xx*10)%m;
    }

    decompose(0,-1);

    cout<<ans;
    nl;

    return 0;


}
