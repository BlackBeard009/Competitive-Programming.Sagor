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



int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    int t;
    cin>>t;


    while(t--){

        int i,j,n,k;

        cin>>n>>k;

        int arr[n+5];

        for(i=1 ; i<=n ; i++) cin>>arr[i];

        vector < set <int> > st(n+5);

        for(i=1 ; i<=n ; i++){
            for(j=1 ; j<=k ; j++){
                int x=arr[i]/j;
                st[i].insert(x);
            }
        }

        int l=0,r=0;
        
        int ans=INT_MAX;

        while(r<=arr[n]){
            bool f=1;

            for(i=1 ; i<=n ; i++){
                if(st[i].lower_bound(l)==st[i].end()){
                    f=0;
                    break;
                }
                int x= *(st[i].lower_bound(l));
                if(x>r){
                    f=0;
                    break;
                }
            }

            if(f){
                ans=min(ans,r-l);
                l++;
            }
            else r++;

            if(l>r) r++;

        }

        cout<<ans;
        nl;

    }

    
    

    return 0;
    

}