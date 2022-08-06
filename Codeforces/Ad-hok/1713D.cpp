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


int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    fastio;

    
    int t;
    cin>>t;


    while(t--){
        int n,i,j;

        cin>>n;

        vector <pair <int,int> > vv;

        for(i=1 ; i<=(1<<n) ; i+=2){
            vv.pb({i,i+1});
        }

        int ans=0;

        while(vv.size()>=2){
            vector <int> tmp;

            for(i=0 ; i<vv.size() ; i+=2){
                int x=vv[i].first;
                int y=vv[i+1].first;
                int z=vv[i+1].second;
                int a,b;
                cout<<"? "<<x<<" "<<y<<endl;
                cin>>a;
                
                if(a){
                    if(a==1){
                        cout<<"? "<<x<<" "<<z<<endl;
                        cin>>b;
                        if(b==1){
                            tmp.pb(x);
                        }
                        else{
                            tmp.pb(z);
                        }

                    }
                    else{
                        x=vv[i+1].first;
                        z=vv[i].second;
                        cout<<"? "<<x<<" "<<z<<endl;
                        cin>>b;
                        if(b==1){
                            tmp.pb(x);
                        }
                        else tmp.pb(z);
                    }

                }
                else{
                    x=vv[i].second;
                    y=vv[i+1].second;
                    cout<<"? "<<x<<" "<<y<<endl;
                    cin>>b;
                    if(b==1){
                        tmp.pb(x);
                    }
                    else tmp.pb(y);
                }

            }

            vv.clear();

            if(tmp.size()>1){
                for(i=0 ; i<tmp.size() ; i+=2){
                    vv.pb({tmp[i],tmp[i+1]});
                }
            }
            else{
                ans=tmp[0];
            }

        }

        if(ans){
            cout<<"! "<<ans<<endl;
            continue;
        }

        cout<<"? "<<vv[0].first<<" "<<vv[0].second<<endl;;

        cin>>ans;

        if(ans==1) cout<<"! "<<vv[0].first<<endl;
        else cout<<"! "<<vv[0].second<<endl;


    }



    


    return 0;


}