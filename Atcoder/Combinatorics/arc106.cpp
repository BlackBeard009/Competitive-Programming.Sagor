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
#define md 998244353
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=(x|(1LL<<y))
#define off(x,y) x=(x&(~(1LL<<y)))
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

ll arr[N][305],c[305][305];


int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/


    ll n,k,i,j;

    cin>>n>>k;

    c[0][0];

    for(i=1 ; i<=k ; i++){
        c[i][0]=1;
        for(j=1 ; j<=i ; j++){
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%md;
        }
    }

    for(i=1 ; i<=n ; i++) arr[i][0]=1;
    for(i=1 ; i<=n ; i++) cin>>arr[i][1];
    for(i=2 ; i<=k ; i++){
        for(j=1 ; j<=n ; j++){
            arr[j][i]=(arr[j][i-1]*arr[j][1])%md;
        }
    }

    for(i=0 ; i<=k ; i++){
        for(j=1 ; j<=n ; j++){
            arr[j][i]+=arr[j-1][i];
            arr[j][i]%=md;
        }
    }

    

    for(i=1 ; i<=k ; i++){
        ll ans=0;

        for(j=0 ; j<=i ; j++){
            ll tmp=(arr[n][j]*arr[n][i-j])%md;
            tmp=(tmp-arr[n][i]+md)%md;
            ans=(ans+c[i][j]*tmp)%md;
        }

        cout<<ans;
        nl;
    }


    return 0;


}
