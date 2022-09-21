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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3

/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

const ll MAX = 1e5;
vector < pair<ll,ll> > g[MAX + 9];
ll del[MAX + 9], sz[MAX + 9], par[MAX + 9], curSize,n,l,w,ans;

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

vector < pair <ll,ll> > vv;
ll xx=1;
multiset <pair<ll,ll>> st;
ordered_set < pair<ll,ll> > qq;

void solve(ll node,ll pre ,ll len,ll wt,ll t){
    if(t==0){
        st.insert({len,wt});
    }
    else{
        if(l-len>=0 && w-wt>=0) vv.pb({l-len,w-wt});

        auto it = st.find({len,wt});
        st.erase(it);
    }

    for(auto to : g[node]){
        if(to.first==pre || del[to.first]) continue;
        solve(to.first,node,len+1,wt+to.second,t);
    }
}



void calc(){
    ll i,j;

    qq.clear();

    auto it=st.begin();

    for(auto to : vv){
        while(1){
            if(it->first > to.first){
                ans+=qq.order_of_key({to.second+1,0});
                break;
            }
            else if(it->first == to.first && it->second > to.second){
                ans+=qq.order_of_key({to.second+1,0});
                break;
            }

            qq.insert({it->second,xx++});
            it++;
        }
    }

}


void decompose(ll u, ll p)
{
    dfs(u, -1);
    curSize = sz[u];
    ll cen = findCentroid(u, -1);
    if(p == -1) p = cen;
    par[cen] = p, del[cen] = 1;

    st.clear();
    st.insert({0,0});
    st.insert({0,0});
    st.insert({LLONG_MAX,LLONG_MAX});

    for(ll i=0 ; i<g[cen].size() ; i++){
        ll nd=g[cen][i].first;
        if(!del[nd]) solve(nd,cen,1,g[cen][i].second,0);
    }

    for(ll i=0 ; i<g[cen].size() ; i++){
        ll nd=g[cen][i].first;
        if(!del[nd]){
            solve(nd,cen,1,g[cen][i].second,1);
            sort(vv.begin(),vv.end());
            calc();
            vv.clear();
            solve(nd,cen,1,g[cen][i].second,0);
        }
    }


    for(ll i = 0; i < g[cen].size(); i++) {
        ll nd = g[cen][i].first;

        if(!del[nd])
            decompose(nd, cen);
    }
}



int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    fastio;

    ll i,j;
    cin>>n>>l>>w;

    for(i=1 ; i<n ; i++){
        ll v,w;
        cin>>v>>w;

        g[i+1].pb({v,w});
        g[v].pb({i+1,w});

    }

    decompose(1,-1);

    cout<<ans/2;
    nl;


    return 0;


}
