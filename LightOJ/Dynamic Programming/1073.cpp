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

int dp[1<<15][16],n,cst[16][16],lst[16][16];
vector <string> vv;

int solve(int mask,int pre){
    if(mask==(1<<n)-1){
        return dp[mask][pre]=0;
    }
    if(dp[mask][pre]!=-1) return dp[mask][pre];

    int ret=INT_MAX,i;

    if(mask==0){
        for(i=0 ; i<n ; i++){
            int tmp=0;
            set(tmp,i);
            ret=min(ret,(int)vv[i].size()+solve(tmp,i));
        }
    }
    else{
        for(i=0 ; i<n ; i++){
            if(!check(mask,i)){
                int tmp=mask;
                set(tmp,i);
                ret=min(ret,cst[pre][i]+solve(tmp,lst[pre][i]));
            }
        }
    }

    return dp[mask][pre]=ret;
    

}

void build(int mask,int pre){
    if(mask==(1<<n)-1) return;

    int mn=INT_MAX,pos=-1,i,j;

    if(mask==0){
        for(i=0 ; i<n ; i++){
            if(mn>dp[1<<i][i]+(int)vv[i].size()){
                mn=dp[1<<i][i]+(int)vv[i].size();
                pos=i;
            }
        }
        cout<<vv[pos];
        build(1<<pos,pos);
        return;
    }



    string mnn="Z";

    for(i=0 ; i<n ; i++){
        if(!check(mask,i)){
            if(dp[mask][pre]==dp[mask|(1<<i)][lst[pre][i]]+cst[pre][i]){
                string tmp;
                for(j=vv[i].size()-cst[pre][i] ; j<vv[i].size() ; j++){
                    tmp.pb(vv[i][j]);
                }
                if(tmp<mnn){
                    mnn=tmp;
                    pos=i;
                }

            }
        }
    }

    cout<<mnn;
    build(mask|(1<<pos),lst[pre][pos]);

}


int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    fastio;

    
    int t,tc=1;
    cin>>t;

    while(t--){

        memset(dp,-1,sizeof(dp));
        vv.clear();

        string s;

        int i,j,k,l;
        cin>>n;

        for(i=0 ; i<n ; i++){
            cin>>s;
            vv.pb(s);
        }
        sort(vv.begin(),vv.end());

        for(i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++) cst[i][j]=INT_MAX;
        }

        for(i=0 ; i<n ; i++){
            for(j=0 ; j<n ; j++){
                if(i==j){
                    cst[i][j]=0;
                    lst[i][j]=i;
                    continue;
                }

                for(k=0 ; k<vv[i].size() ; k++){
                    bool f=0;
                    for(l=0 ; l<vv[j].size() ; l++){
                        if(k+l>=vv[i].size()){
                            f=1;
                            break;
                        }
                        if(vv[i][k+l]!=vv[j][l]) break;
                    }
                    
                    if(l==vv[j].size()){
                        cst[i][j]=0;
                        lst[i][j]=i;
                    }
                    else if(f){
                        if(cst[i][j]>vv[j].size()-l){
                            cst[i][j]=vv[j].size()-l;
                            lst[i][j]=j;
                        }
                    }
                }
                if(cst[i][j]==INT_MAX){
                    cst[i][j]=vv[j].size();
                    lst[i][j]=j;
                }

            }
        }
        

        
        //cout<<(1<<n)-1;
        for(i=(1<<n)-1 ; i>=0 ; i--){
            for(j=0 ; j<n ; j++){
                solve(i,j);
            }
        }
        cout<<"Case "<<tc++<<": ";
        build(0,0);
        nl;

        

        

    }



    


    return 0;


}