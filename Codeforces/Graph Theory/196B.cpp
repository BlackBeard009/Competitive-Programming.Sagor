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

ll n,m;

string s[1505];

//map < pair<int,int> , bool > vis;
ll visx[1505][1505],visy[1505][1505];
ll dx[]={1,-1,0,0};
ll dy[]={0,0,1,-1};

bool valid(ll x,ll y){
    ll xx=x%n;
    xx=(xx+n)%n;
    ll yy=y%m;
    yy=(yy+m)%m;
    if(s[xx][yy]!='#') return 1;
    return 0;

}

int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    ll i,j;

    cin>>n>>m;

    fr0(n,i){
        fr0(m,j){
            visx[i][j]=INT_MAX;
            visy[i][j]=INT_MAX;
        }
    }

    fr0(n,i) cin>>s[i];

    ll stx=-1,sty=-1;

    fr0(n,i){
        fr0(m,j){
            if(s[i][j]=='S'){
                stx=i;
                sty=j;
            }
        }
    }

    queue < pair <ll,ll> > q;

    q.push({stx,sty});
    
    visx[stx][sty]=stx;
    visy[stx][sty]=sty;

    int f=0;

    while(q.size() && !f){
        ll px=q.front().first;
        ll py=q.front().second;
        q.pop();

        for(i=0 ; i<4 ; i++){
            ll nx=px+dx[i];
            ll ny=py+dy[i];
            
            if(valid(nx,ny)){
                ll xx=nx%n;
                xx=(xx+n)%n;
                ll yy=ny%m;
                yy=(yy+m)%m;

                if(visx[xx][yy]==INT_MAX){
                    q.push({nx,ny});
                    visx[xx][yy]=nx;
                    visy[xx][yy]=ny;
                }
                else if(visx[xx][yy]!=nx || visy[xx][yy]!=ny){
                    f=1;
                    
                    break;
                }
            }
        }

    }    

    if(f) Yes;
    else No;


    return 0;
    

}