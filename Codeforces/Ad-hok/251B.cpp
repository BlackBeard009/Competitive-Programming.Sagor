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
#define N  1000005
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

int ans[105],a[105],s[105],tmp[105],n,k;

bool ff(){
    int i,j;
    for(i=1 ; i<=n ; i++) ans[i]=i;


    for(i=1 ; i<=k ; i++){

        for(j=1 ; j<=n ; j++){
            tmp[j]=ans[a[j]];
        }

        for(j=1 ; j<=n ; j++){
            ans[j]=tmp[j];
        }

        for(j=1 ; j<=n ; j++){
            if(tmp[j]!=s[j] ) break;
        }

        if(j>n) break;        

    }

    

    if(i>k) return 0;
    else{

        for(j=1 ; j<=n ; j++){
            if(ans[j]!=s[j]) break;         
        }

        if(j<=n){
            return 0;
        }
        else if((k-i)%2){
            return 0;
        }
        else return 1;
    }

}

bool bb(){
    int i,j;
    for(i=1 ; i<=n ; i++) ans[i]=i;


    for(i=1 ; i<=k ; i++){

        for(j=1 ; j<=n ; j++){
            tmp[a[j]]=ans[j];
        }

        for(j=1 ; j<=n ; j++){
            ans[j]=tmp[j];
        }

        for(j=1 ; j<=n ; j++){
            if(tmp[j]!=s[j] ) break;
        }

        if(j>n) break;        

    }

    

    if(i>k) return 0;
    else{

        for(j=1 ; j<=n ; j++){
            if(ans[j]!=s[j]) break;         
        }

        if(j<=n){
            return 0;
        }
        else if((k-i)%2){
            return 0;
        }
        else return 1;
    }

}

int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    

    int i,j;

    cin>>n>>k;

    

    for(i=1 ; i<=n ; i++){
        cin>>a[i];
    }
    for(i=1 ; i<=n ; i++){
        cin>>s[i];
    }

    for(i=1;  i<=n ; i++){
        if(s[i]!=i) break;
    }

    if(i>n){
        NO;
        return 0;
    }

    for(i=1 ; i<=n ; i++){
        if(s[i]!=a[i]) break;
    }



    if(i>n && k>1){
        int xx=0,x[n+5];

        for(i=1 ; i<=n ; i++){
            x[a[i]]=i;
        }

        for(i=1 ; i<=n ; i++){
            if(x[i]!=s[i]) break;
        }

        if(i>n){
            NO;
            return 0;
        }



    }


    if(ff() || bb()) YES;
    else NO;


    


    return 0;
    

}