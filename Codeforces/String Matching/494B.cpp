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
#define N  100005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/


ll arr[N],x[N],y[N],z[N],f[N];
string s,t;
void build_table(){
    f[0]=0;
    f[1]=0;
    int i,j;
    for(i=2 ; i<=t.size() ; i++){
        j=f[i-1];
        while(1){
            if(t[j]==t[i-1]){
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
void kmp(){
    build_table();
    int i=0,j=0,ret=0;
    while(1){
        if(j==s.size()){
            break;
        }
        if(s[j]==t[i]){
            i++;
            j++;
            if(i==t.size()) {
                arr[j]++;
                i=f[i];
            }
        }
        else{
            if(i==0){
                j++;
            }
            else{
                i=f[i];
            }
        }
    }
}

int main()
{
    fastio;

    ll i,j;

    cin>>s>>t;

    build_table();
    kmp();
    ll ans=0;
    for(i=1 ; i<=s.size() ; i++){
        if(arr[i]){
            x[i]=(z[i-t.size()]+i-t.size()+1);
        }
        else x[i]=x[i-1];

        y[i]=(x[i]+y[i-1])%md;
        z[i]=(y[i]+z[i-1])%md;
        ans=(ans+x[i])%md;
    }

    cout<<ans;
    nl;


    return 0;

}
