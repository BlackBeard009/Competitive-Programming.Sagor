/*#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")*/
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
#define N  55
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

string s[N];
int n,m,dx[]={1,-1,0,0},dy[]={0,0,1,-1},dist[N][N];

bool valid(int x,int y){
    if(x<0 || x>=n || y<0 || y>=m || s[x][y]=='#') return 0;
    return 1;
}

int main()
{
    fastio;

    int i,j;
    cin>>n>>m;

    for(i=0 ; i<n ; i++) cin>>s[i];

    queue <pair<int,int> > q;

    dist[0][0]=1;

    q.push({0,0});

    while(q.size()){
        int px=q.front().first,py=q.front().second;
        q.pop();

        for(i=0 ; i<4 ; i++){
            int nx=px+dx[i];
            int ny=py+dy[i];

            if(valid(nx,ny) && dist[nx][ny]==0){
                dist[nx][ny]=dist[px][py]+1;
                q.push({nx,ny});
            }

        }
    }

    int ans=0;

    for(i=0 ; i<n ; i++){
        for(j=0 ; j<m ; j++){
            if(s[i][j]=='.') ans++;
        }
    }

    if(dist[n-1][m-1]) cout<<ans-dist[n-1][m-1];
    else cout<<"-1";
    nl;




    return 0;

}
