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


string s,tt[N];

int cnt[20][N],n,m,msk[1<<20];

void dfs(int node,int st){
    if(msk[node]) return ;
    int i,j;
    msk[node]=st;
    for(i=0 ; i<20 ; i++){
        if(check(node,i)){
            int tmp=node;
            off(tmp,i);
            dfs(tmp,st);
        }
    }
}

int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    int t;
    cin>>t;


    while(t--){

        cin>>n>>m;

        int i,j;

        cin>>s;

        for(i=1 ; i<=m ; i++) cin>>tt[i];

        for(i=1 ; i<=n ; i++){
            for(j=0 ; j<20 ; j++) cnt[j][i]=0;
        }

        for(i=1 ; i<=n ; i++){
            cnt[s[i-1]-'a'][i]++;
        }

        for(i=0 ; i<20 ; i++){
            for(j=1 ; j<=n ; j++) cnt[i][j]+=cnt[i][j-1];
        }

        memset(msk,0,sizeof(msk));

        for(i=1 ; i<=m ; i++){
            int tmp=0;
            for(j=0 ; j<tt[i].size() ; j++){
                set(tmp,tt[i][j]-'a');
            }
            dfs(tmp,i);
        }

        
        for(i=1 ; i<=n ; i++){
            int lo=i,hi=n,tmp=0;

            while(lo<hi){

                int mid=(lo+hi+1)/2;

                tmp=0;

                for(j=0 ; j<20 ; j++){
                    if(cnt[j][mid]-cnt[j][i-1]) set(tmp,j);
                }

                if(msk[tmp]) lo=mid;
                else hi=mid-1;

            }

            tmp=0;

            for(j=0 ; j<20 ; j++){
                if(cnt[j][lo]-cnt[j][i-1]) set(tmp,j);
            }

            for(j=i ; j<=lo ; j++) cout<<msk[tmp]<<" ";

            i=lo;


        }

        nl;


    }
    

    return 0;
    

}