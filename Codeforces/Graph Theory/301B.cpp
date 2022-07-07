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
#define N  105
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

ll arr[N],n,d,x[N],y[N],dist[N];

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    ll i,j;
    cin>>n>>d;

    for(i=0 ; i<=n+2 ; i++) dist[i]=LLONG_MAX;

    for(i=2 ; i<n ; i++) cin>>arr[i];

    for(i=1 ; i<=n ; i++){
        cin>>x[i]>>y[i];
    }


    priority_queue < pair <ll,ll> > q;

    dist[1]=0;

    q.push({0,1});

    while(q.size()){

        ll now=q.top().second;
        q.pop();

        for(i=1 ; i<=n ; i++){
            if(i==now) continue;
            if(dist[i]>dist[now]+(abs(x[i]-x[now])+abs(y[i]-y[now]))*d - arr[i]){
                dist[i]=dist[now]+(abs(x[i]-x[now])+abs(y[i]-y[now]))*d - arr[i];
                q.push({-dist[i],i});
            }
        }

    }

    cout<<dist[n];
    nl;




    return 0;

}
