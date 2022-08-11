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
#define md 1000000000
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

int arr[2005][2005];

int ask(int x,int y){
    if(arr[x][y]!=-1) return arr[x][y];
    cout<<"? "<<x<<" "<<y<<endl;
    cin>>arr[x][y];
    return arr[x][y];
}

int dx[]={1,1,1,0,0,-1,-1,-1,0};
int dy[]={1,0,-1,1,-1,1,0,-1,0};



int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    fastio;

    memset(arr,-1,sizeof(arr));
    
    int n,i,j;
    cin>>n;

    int rowb=1,rowe=n,colb=1,cole=n,cnt=0,mx=-1,x=-1,y=-1;

    while(1){
        if(rowe-rowb+1<=cole-colb+1){
            int mid=(cole+colb)/2;
            int mm=-1,tx=-1,ty=-1;
            for(i=rowb ; i<=rowe ; i++){
                int tmp=ask(i,mid);
                if(tmp>mm){
                    mm=tmp;
                    tx=i;
                    ty=mid;
                }
            }

            int px=tx,py=ty;

            for(i=0 ; i<=8 ; i++){
                int nx=tx+dx[i];
                int ny=ty+dy[i];

                if(nx>=rowb && nx<=rowe && ny>=colb && ny<=cole){
                    int tmp=ask(nx,ny);
                    if(tmp>mm){
                        mm=tmp;
                        px=nx;
                        py=ny;
                    }
                }
            }
            if(mm>mx){
                mx=mm;
                x=px;
                y=py;
            }

            if(y==mid){
                cout<<"! "<<x<<" "<<y<<endl;
                break;
            }
            else if(y<mid){
                cole=mid-1;
            }
            else{
                colb=mid+1;
            }


       }
       else{
            int mid=(rowe+rowb)/2;
            int mm=-1,tx=-1,ty=-1;
            for(i=colb ; i<=cole ; i++){
                int tmp=ask(mid,i);
                if(tmp>mm){
                    mm=tmp;
                    tx=mid;
                    ty=i;
                }
            }

            int px=tx,py=ty;
            //cout<<tx<<" "<<ty<<" "<<mm<<" "<<mx<<endl;

            for(i=0 ; i<8 ; i++){
                int nx=tx+dx[i];
                int ny=ty+dy[i];

                if(nx>=rowb && nx<=rowe && ny>=colb && ny<=cole){
                    int tmp=ask(nx,ny);
                    if(tmp>mm){
                        mm=tmp;
                        px=nx;
                        py=ny;
                    }
                }
            }

            if(mm>mx){
                mx=mm;
                x=px;
                y=py;
            }

            if(x==mid){
                cout<<"! "<<x<<" "<<y<<endl;
                break;
            }
            else if(x<mid){
                rowe=mid-1;
            }
            else{
                rowb=mid+1;
            }
       }
    }

    


    return 0;


}