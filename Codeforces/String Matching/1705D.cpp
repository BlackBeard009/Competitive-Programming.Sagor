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




int main()
{
    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/
    
    fastio ; 

    int t;
    cin>>t;

    while(t--){
        int n,i,j;
        cin>>n;

        string s,t;
        cin>>s>>t;

        if(s[0]!=t[0] || s[n-1]!=t[n-1]){
            cout<<"-1";
            nl;
            continue;
        }

        vector < pair <int,int> >  a,b;
        int cnt=0;
        fr0(n,i){
            if(s[i]=='1'){
                cnt++;
            }
            else{
                if(cnt) a.pb({i-cnt,cnt});
                cnt=0;
            }
        }

        if(cnt) a.pb({i-cnt,cnt});

        cnt=0;

        fr0(n,i){
            if(t[i]=='1'){
                cnt++;
            }
            else{
                if(cnt) b.pb({i-cnt,cnt});
                cnt=0;
            }
        }

        if(cnt) b.pb({i-cnt,cnt});

        if(a.size()!=b.size()){
            cout<<"-1";
            nl;
            continue;
        }
        

        ll ans=0;

        for(i=0 ; i<a.size() ; i++){
            int l1=a[i].first,r1=a[i].first+a[i].second-1;
            int l2=b[i].first,r2=b[i].first+b[i].second-1;

            ans+=abs(l1-l2);
            ans+=abs(r1-r2);

        }

        cout<<ans;
        nl;


    }

    

    return 0;
    

}