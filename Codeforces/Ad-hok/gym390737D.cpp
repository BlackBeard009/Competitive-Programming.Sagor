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


int n,table[N][30],arr[N];
void build(){
    int i,j;
    int size=2;
    for(i=1 ; i<=n ; i++){
        table[i][0]=arr[i];
    }
    for(j=1 ; ; j++){
        if(size>n) break;
        for(i=1 ; i+(1<<j)-1<=n; i++){
            table[i][j]=__gcd(table[i][j-1],table[i+(1<<(j-1))][j-1]);
        }
        size*=2;
    }
}
//query for rmq/gcd in O(1)



int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    int t;
    cin>>t;

    while(t--){
        int i,j;
        cin>>n;

        for(i=1 ; i<=n ; i++){
            cin>>arr[i];
        }

        sort(arr+1,arr+n+1);

        build();

        for(i=1 ; i<=n ; i++){
            int l=(i+1)/2;
            int r=n-(i-l);

            int xx=log2(r-l+1);

            int ans=table[l][xx];

            ans=__gcd(ans,table[r-(1<<xx)+1][xx]);

            cout<<ans<<" ";
        }
        nl;


        

    }
    
    

    return 0;
    

}