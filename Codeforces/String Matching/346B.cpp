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

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

string s,t,v;
int n,m,k,dp[105][105][105],f[105],vis[105][105][105];

int solve(int x,int y, int z){
    if(z==k) return dp[x][y][z]=INT_MIN;
    if(x==n || y==m) return dp[x][y][z]=0;
    if(vis[x][y][z]) return dp[x][y][z];

    vis[x][y][z]=1;
    int ret=0;

    if(s[x]==t[y]){
        if(s[x]==v[z]) ret=max(ret,1+solve(x+1,y+1,z+1));
        else{
            int tmp=z;
            while(1){
                if(s[x]==v[tmp]){
                    ret=max(ret,1+solve(x+1,y+1,tmp+1));
                    break;
                }
                else{
                    if(tmp==0){
                        ret=max(ret,1+solve(x+1,y+1,0));
                        break;
                    }
                    else{
                        tmp=f[tmp];
                    }
                }
            }
        }
    }
    ret=max(ret,solve(x+1,y,z));
    ret=max(ret,solve(x,y+1,z));

    return dp[x][y][z]=ret;


}

void build(int x,int y,int z){
    if(x==n || y==m) return;

    int ret=0,pos=0;

    if(s[x]==t[y]){
        if(s[x]==v[z] && dp[x+1][y+1][z+1]+1==dp[x][y][z]){
            cout<<s[x];
            build(x+1,y+1,z+1);
            return ;
        }
        else{
            int tmp=z;
            while(1){
                if(s[x]==v[tmp]){
                    if(dp[x+1][y+1][tmp+1]+1==dp[x][y][z]){
                        cout<<s[x];
                        build(x+1,y+1,tmp+1);
                        return ;
                    }
                    break;
                }
                else{
                    if(tmp==0){
                        if(dp[x+1][y+1][0]+1==dp[x][y][z]){
                            cout<<s[x];
                            build(x+1,y+1,0);
                            return ;
                        }
                        break;
                    }
                    else{
                        tmp=f[tmp];
                    }
                }
            }
        }
    }

    if(dp[x+1][y][z]>dp[x][y+1][z]) build(x+1,y,z);
    else build(x,y+1,z);


    return ;

}

void build_table(){
    f[0]=0;
    f[1]=0;
    int i,j;
    for(i=2 ; i<=k ; i++){
        j=f[i-1];
        while(1){
            if(v[j]==v[i-1]){
                f[i]=j+1;
                break;
            }
            if(j==0){
                f[i]=0;
                break;
            }
            j=f[j];
        }
    }
}


int main()
{
    fastio;

    int i,j;
    cin>>s>>t>>v;

    n=s.size();
    m=t.size();
    k=v.size();

    build_table();

    if(solve(0,0,0)){

        build(0,0,0);
    }
    else cout<<"0";
    nl;



    return 0;

}
