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
#define N  100005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

vector <int> g[N],w[N],t[N];
int dist[N];


int main()
{

    fastio;

    int n,m,i,j;

    cin>>n>>m;
    for(i=0 ; i<=n ; i++) dist[i]=inf;
    fr0(m,i){
        int u,v,c;
        cin>>u>>v>>c;
        g[u].pb(v);
        g[v].pb(u);
        w[u].pb(c);
        w[v].pb(c);
    }

    for(i=1 ; i<=n ; i++){
        int k;
        cin>>k;
        for(j=0 ; j<k ; j++){
            int x;
            cin>>x;
            t[i].pb(x);
        }
        sort(t[i].begin(),t[i].end());
    }
    dist[1]=0;

    priority_queue < pair<int,int> > q;

    q.push({0,1});

    while(q.size()){
        int node=q.top().second,d=-q.top().first;
        q.pop();
        if(dist[node]<d) continue;

        int tmp=dist[node];

        auto it=find(t[node].begin(),t[node].end(),tmp);

        while(it!=t[node].end()){
            if(*it!=tmp) break;
            it++;
            tmp++;
        }

        for(i=0 ; i<g[node].size() ; i++){
            int to=g[node][i],tc=w[node][i];
            if(dist[to]>tmp+tc){
                dist[to]=tmp+tc;
                q.push({-dist[to],to});
            }
        }

    }

    if(dist[n]==inf) cout<<"-1";
    else cout<<dist[n];
    nl;






    return 0;

}
