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


    int t;
    cin>>t;


    while(t--){

        int n,i,j,a,b,c;

        cin>>n>>a>>b>>c;

        int y=(-a+b+c);

        if(y%2){
            NO;
            continue;
        }

        y/=2;

        int x=b-y;
        int z=c-y;

        if(x<0 || y<0 || z<0){
            NO;
            continue;
        }

        if(x+y+z+1>n){
            NO;
            continue;
        }

        int cnt=0;
        if(x) cnt++;
        if(y) cnt++;
        if(z) cnt++;

        if(cnt<2){
            NO;
            continue;
        }

        YES;


        if(cnt==3){
            vector <int> vv;



            for(i=5 ; i<=n ; i++) vv.pb(i);

            int par=4;

            for(i=1 ; i<x ; i++){
                cout<<lst(vv)<<" "<<par;
                nl;
                par=lst(vv);
                vv.ppb();
            }

            cout<<par<<" "<<2;

            nl;

            par=4;

            for(i=1 ; i<y ; i++){
                cout<<lst(vv)<<" "<<par;
                nl;
                par=lst(vv);
                vv.ppb();
            }

            cout<<par<<" "<<3;
            nl;

            par=4;

            for(i=1 ; i<z ; i++){
                cout<<lst(vv)<<" "<<par;
                nl;
                par=lst(vv);
                vv.ppb();
            }

            cout<<par<<" "<<1;
            nl;

            par=1;
            while(vv.size()){
                cout<<par<<" "<<lst(vv);
                nl;
                par=lst(vv);
                vv.ppb();
            }
        }
        else{
            if(x==0){
                vector <int> vv;

                for(i=4 ; i<=n ; i++) vv.pb(i);

                int par=2;

                for(i=1 ; i<y ; i++){
                    cout<<lst(vv)<<" "<<par;
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }

                cout<<par<<" "<<3;
                nl;

                par=2;

                for(i=1 ; i<z ; i++){
                    cout<<lst(vv)<<" "<<par;
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }

                cout<<par<<" "<<1;
                nl;

                par=1;
                while(vv.size()){
                    cout<<par<<" "<<lst(vv);
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }

            }
            else if(y==0){
                vector <int> vv;

                for(i=4 ; i<=n ; i++) vv.pb(i);

                int par=3;

                for(i=1 ; i<x ; i++){
                    cout<<lst(vv)<<" "<<par;
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }

                cout<<par<<" "<<2;
                nl;

                par=3;

                for(i=1 ; i<z ; i++){
                    cout<<lst(vv)<<" "<<par;
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }

                cout<<par<<" "<<1;
                nl;

                par=1;
                while(vv.size()){
                    cout<<par<<" "<<lst(vv);
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }
            }
            else{
                vector <int> vv;

                for(i=4 ; i<=n ; i++) vv.pb(i);

                int par=1;

                for(i=1 ; i<x ; i++){
                    cout<<lst(vv)<<" "<<par;
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }

                cout<<par<<" "<<2;
                nl;

                par=1;

                for(i=1 ; i<y ; i++){
                    cout<<lst(vv)<<" "<<par;
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }

                cout<<par<<" "<<3;
                nl;

                par=1;
                while(vv.size()){
                    cout<<par<<" "<<lst(vv);
                    nl;
                    par=lst(vv);
                    vv.ppb();
                }
            }

        }


    }


    return 0;


}
