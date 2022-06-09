#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define powr(x,n,p) for(int axy=0 ; axy<p ; axy++){x=x*n;}
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
#define nl printf("\n")
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
#define N 1005

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

int n,m,vis[N][N],lvl[N][N],dx[]={1,-1,0,0},dy[]={0,0,1,-1};
string s[N];
bool valid(int x,int y){
    return (x>=0 && x<n && y>=0 && y<m && s[x][y]!='T');
}
int main()
{

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int i,j;
    cin>>n>>m;

    fr0(n,i) cin>>s[i];
    fr0(n,i){
        fr0(m,j) lvl[i][j]=md;
    }


    queue <pair<int,int>  > q;

    int stx,sty,cx,cy;

    fr0(n,i){
        fr0(m,j){
            if(s[i][j]=='E'){
                stx=i;
                sty=j;
            }
            else if(s[i][j]=='S'){
                cx=i;
                cy=j;
            }
        }
    }

    q.push({stx,sty});
    vis[stx][sty]=1;
    lvl[stx][sty]=0;

    while(q.size()){
        auto tmp=q.front();
        q.pop();

        int x=tmp.first,y=tmp.second;

        for(i=0 ; i<4 ; i++){
            int nx=x+dx[i],ny=y+dy[i];
            if(valid(nx,ny) && !vis[nx][ny]){
                vis[nx][ny]=1;
                lvl[nx][ny]=lvl[x][y]+1;
                q.push({nx,ny});
            }
        }
    }

    int ans=0;

    fr0(n,i){
        fr0(m,j){
            if(s[i][j]>='0' && s[i][j]<='9' && lvl[i][j]<=lvl[cx][cy]) ans+=(s[i][j]-'0');

        }

    }


    cout<<ans;
    nl;





    return 0;
}
