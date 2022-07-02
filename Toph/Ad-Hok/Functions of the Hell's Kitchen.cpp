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
#define N  1000005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

bool st[N];
ll sumdiv[N],bigprm[N];

int main()
{
    fastio;

    ll t,i,j;
    cin>>t;

    for(i=4 ; i<=1000000 ; i+=2){
        st[i]=true;
    }
    st[1]=true;
    bigprm[1]=1;
    for(i=3 ; i<=1000 ; i+=2){
        if(!st[i]){
            for(j=i*2 ; j<=1000000 ; j+=i){
                st[j]=true;
            }
        }
    }

    for(i=1 ; i<=1000000 ; i++){
        for(j=i ; j<=1000000 ; j+=i){
            sumdiv[j]+=i;
            if(!st[i]) bigprm[j]=i;
        }
    }



    while(t--){

        ll l,r,k,x;
        cin>>l>>r>>k>>x;

        for(i=r ; i>=l ; i--){
            if(!st[i]){
                cout<<i;
                nl;
                break;
            }
        }

        if(i>=l) continue;


        ll ans=l,mxprm=0;

        for(i=l ; i<=r ; i++){
            if(k%i==0 || sumdiv[i]>=x){
                ll tmp=i;
                if(bigprm[i]>=mxprm){
                    mxprm=bigprm[i];
                    ans=i;
                }
            }
        }
        cout<<ans;
        nl;



    }



    return 0;

}
