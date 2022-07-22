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
#define inf (1<<30)
#define N  200005
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

int s,t,m,vis[3005];

vector <int> g[303005];


int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    int i,j;

    cin>>s>>t>>m;

    for(i=1 ; i<=m ; i++){
        int u,v;

        cin>>u>>v;

        g[u].pb(v);
        g[v].pb(u);
    }
    int f=0;

    for(i=s+1 ; i<=s+t ; i++){

        memset(vis,0,sizeof(vis));

        for(auto to : g[i]){
            for(auto to2 : g[to]){
                if(to2==i) continue;
                if(vis[to2-s]){
                    f=1;
                    cout<<i<<" "<<to<<" "<<to2<<" "<<vis[to2-s];
                    nl;
                    break;
                }
                else{
                    vis[to2-s]=to;
                }
            }
            if(f) break;
        }
        if(f) break;

    }
    if(!f) cout<<"-1\n";
    

    return 0;
    

}