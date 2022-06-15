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

int n,m,k,vis[N],par[N];
vector <int> g[N],w[N],arr;
ll d[505][505];

int find(int node){
    if(par[node]==node) return node;
    return par[node]=find(par[node]);
}
void uni(int u, int v){
    int x = find(u);
    int y = find(v);

    par[x] = y;

}

int main()
{
    fastio;

    int i,j,xx;
    cin>>n>>m>>k;
    arr.pb(0);
    for(i=1 ; i<=n ; i++) par[i]=i;
    for(i=1 ; i<=k ; i++){
        cin>>j;
        arr.pb(j);
        arr[i]+=arr[i-1];

    }

    for(i=1 ; i<=k ; i++){
        for(j=1 ; j<=k ; j++) d[i][j]=INT_MAX;
    }

    for(i=1 ; i<=m ; i++){
        int u,v,x;
        cin>>u>>v>>x;
        if(u>n || v>n) assert(0);
        g[u].pb(v);
        g[v].pb(u);
        w[u].pb(x);
        w[v].pb(x);
        if(x==0){
            if(find(u)!=find(v)) uni(u,v);
        }
        int posu,posv,lo=1,hi=k;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>=u) hi=mid;
            else lo=mid+1;
        }
        posu=lo;
        lo=1,hi=k;
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(arr[mid]>=v) hi=mid;
            else lo=mid+1;
        }
        posv=lo;
        d[posu][posv]=min(d[posu][posv],(ll)x);
        d[posv][posu]=min(d[posv][posu],(ll)x);
    }

    for(i=1 ; i<=k ; i++){
        set <int> st;
        for(j=arr[i-1]+1 ; j<=arr[i] ; j++){
            st.insert(find(j));
        }
        if(st.size()>1){
            No;
            return 0;
        }
    }

    Yes;

    for(xx=1 ; xx<=k ; xx++){
        for(i=1 ; i<=k ; i++){
            for(j=1 ; j<=k ; j++){
                if(d[i][xx]+d[xx][j]<d[i][j]) d[i][j]=d[i][xx]+d[xx][j];
            }
        }
    }


    for(i=1 ; i<=k ; i++){
        for(j=1 ; j<=k ; j++){
            if(i==j) cout<<"0 ";
            else if(d[i][j]==INT_MAX) cout<<"-1 ";
            else cout<<d[i][j]<<" ";
        }
        nl;
    }





    return 0;

}
