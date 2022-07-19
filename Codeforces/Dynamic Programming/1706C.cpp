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
#define N  100005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

ll n,arr[N],vis[N];

pair <ll,ll> dp[N];

pair <ll,ll> solve(ll pos){
    if(pos>=n) return {0,0};

    if(vis[pos]) return dp[pos];

    vis[pos]=1;

    pair <ll,ll> ret = solve(pos+1);

    auto tmp = solve(pos+2);

    tmp.first++;
    tmp.second+=(max(0LL,max(arr[pos-1],arr[pos+1])-arr[pos]+1));

    if(ret.first>tmp.first){
        return dp[pos]=ret;
    }
    else if(tmp.first>ret.first){
        return dp[pos]=tmp;
    }
    else{
        if(ret.second<tmp.second) return dp[pos]=ret;
        else return dp[pos]=tmp;
    }

}

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    int t;
    cin>>t;


    while(t--){

        ll i,j;

        cin>>n;

        for(i=1 ; i<=n ; i++) cin>>arr[i];

        for(i=0 ; i<=n+2 ; i++) vis[i]=0;

        auto ans=solve(2);

        cout<<ans.second;
        nl;




    }

    
    

    return 0;
    

}