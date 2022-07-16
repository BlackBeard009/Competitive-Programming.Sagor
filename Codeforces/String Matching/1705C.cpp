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
#define N  200005
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
    
    fastio ; 

    int t;
    cin>>t;

    while(t--){
        ll n,c,q,i,j;
        cin>>n>>c>>q;

        string s;
        cin>>s;

        vector < pair <ll,ll> > vv;

        vv.pb({1,n});
        ll len=n;

        while(c--){
            ll l,r;
            cin>>l>>r;
            vv.pb({l,r});
        }

        while(q--){
            ll k;
            cin>>k;

            while(k>n){
                ll rem=k;
                for(i=0 ; i<vv.size() ; i++){
                    if(vv[i].second-vv[i].first+1<rem){
                        rem-=(vv[i].second-vv[i].first+1);
                    }
                    else{
                        k=(vv[i].first+rem-1);
                        break;
                    }
                }
            }

            cout<<s[k-1];
            nl;
        }


    }

    

    return 0;
    

}