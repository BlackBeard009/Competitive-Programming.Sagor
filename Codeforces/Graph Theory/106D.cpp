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

int n,m,posx[26],posy[26],row[1005][1005],col[1005][1005];
string s[1005];


int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    fastio ; 

    memset(posx,-1,sizeof(posx));
    memset(posy,-1,sizeof(posy));

    int i,j;

    cin>>n>>m;

    fr0(n,i) cin>>s[i];

    fr0(n,i){
        fr0(m,j){
            if(s[i][j]>='A' && s[i][j]<='Z'){
                posx[s[i][j]-'A']=i;
                posy[s[i][j]-'A']=j;
            }
        }
    }

    fr0(n,i){
        fr0(m,j){
            if(s[i][j]=='#'){
                row[i+1][j+1]++;
                col[j+1][i+1]++;
            }
        }
    }

    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=m ; j++) row[i][j]+=row[i][j-1];
    }

    for(i=1 ; i<=m ; i++){
        for(j=1 ; j<=n ; j++) col[i][j]+=col[i][j-1];
    }

    vector < pair <char,int> > vv;

    int k;
    cin>>k;

    fr0(k,i){
        char ch;
        int step;
        cin>>ch>>step;
        vv.pb({ch,step});
    }

    int f=0;

    for(i=0 ; i<26 ; i++){
        if(posx[i]==-1) continue;
        int x=posx[i],y=posy[i];
        
        for(j=0 ; j<k ; j++){
            int nx=x,ny=y;

            if(vv[j].first=='N') nx-=vv[j].second;
            else if(vv[j].first=='S') nx+=vv[j].second;
            else if(vv[j].first=='W') ny-=vv[j].second;
            else ny+=vv[j].second;

            if(nx<0 || nx>=n || ny<0 || ny>=m) break;



            if(nx>x && (col[y+1][nx+1]-col[y+1][x])){
                break;
            }
            if(nx<x && (col[y+1][x+1]-col[y+1][nx])){
                break;
            }
            if(ny>y && (row[x+1][ny+1]-row[x+1][y])){
                break;
            }
            if(ny<y && (row[x+1][y+1]-row[x+1][ny])){
                break;
            }

            x=nx;
            y=ny;

        }

        if(j==k){
            f=1;
            cout<<(char)(i+'A');
        }
        

    }

    if(f==0) cout<<"no solution";

    nl;

    

    return 0;
    

}