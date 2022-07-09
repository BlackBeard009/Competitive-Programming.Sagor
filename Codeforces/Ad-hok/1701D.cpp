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


vector < pair < pair<int,int> ,int> > vv;
set <int> rem;


int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    int t;
    cin>>t;

    while(t--){
        int n,i,j;
        cin>>n;
        int ans[n+5]={0};

        vv.clear();
        rem.clear();

        for(i=1 ; i<=n ; i++) rem.insert(i);

        for(i=1 ; i<=n ; i++){
            int x;
            cin>>x;

            if(x==0) continue;

            int r=i/x;
            int l=(i/(x+1))+1;

            vv.pb({{r,l},i});
        }

        sort(vv.begin(),vv.end());

        for(i=0 ; i<vv.size() ; i++){
            auto it=rem.lower_bound(vv[i].first.second);
            ans[vv[i].second]=*it;
            rem.erase(it);
        }

        for(i=n ; i>0 ; i--){
            if(ans[i]==0){
                auto it = rem.end();
                it--;
                ans[i]=*it;
                rem.erase(it);
            }
        }

        for(i=1 ; i<=n ; i++) cout<<ans[i]<<" ";
        nl;


    }



    return 0;


}
