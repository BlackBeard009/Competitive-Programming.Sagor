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
#define N  200005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/


vector <int> vv[N];


int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    int t;
    cin>>t;

    while(t--){
        int n,m,i,j;

        cin>>n>>m;

        for(i=0 ; i<=n ; i++) vv[i].clear();

        for(i=1 ; i<=m ; i++){
            cin>>j;
            vv[j].pb(i);
        }


        int lo=1, hi=2*m;

        while(lo<hi){
            int mid=(lo+hi)/2;



            int st[m+5]={0};

            for(i=1 ; i<=n ; i++){
                int cnt=0;
                for(auto it : vv[i]){
                    if(cnt==mid) break;
                    st[it]=1;
                    cnt++;
                }
            }

            int cnt=0;

            for(i=1 ; i<=m ; i++){
                if(st[i]==0) cnt++;
            }

            for(i=1 ; i<=n ; i++){
                int rem=max(0,mid-(int)vv[i].size());

                while(rem>1 && cnt){
                    cnt--;
                    rem-=2;
                }

            }


            if(cnt) lo=mid+1;
            else hi=mid;

        }

        cout<<lo;
        nl;





    }



    return 0;


}
