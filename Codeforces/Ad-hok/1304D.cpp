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
#define inf (1LL<<60)
#define N  200005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/

 int ans[N];

 void solve(string s){
    int i,j,n=s.size();
    int f=n;

    fr0(n,i){
        if(s[i]=='>') ans[i]=f--;
    }
    f=1;
    int cnt=0;
    for(i=n-1 ; i>=0 ; i--){
        if(s[i]=='<'){
            cnt++;
        }
        else{
            if(cnt){
                for(j=i+1 ; j<n ; j++){
                    if(s[j]=='>') break;
                    else ans[j]=f++;
                }
                cnt=0;
            }
        }

    }
    if(cnt){
        for(i=0 ; i<n ; i++){
            if(s[i]=='>') break;
            else ans[i]=f++;
        }
    }
 }



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

        string s;
        cin>>s;

        if(s[n-2]=='<') s.pb('>');
        else s.pb('<');

        solve(s);

        for(i=0 ; i<n ; i++){
            cout<<ans[i]<<" ";
            ans[i]=0;
        }

        nl;

        s.ppb();

        reverse(s.begin(),s.end());

        for(i=0 ; i<s.size() ; i++){
            if(s[i]=='>') s[i]='<';
            else s[i]='>';
        }

        if(lst(s)=='>') s.pb('>');
        else s.pb('<');

        solve(s);

        for(i=n-1 ; i>=0 ; i--) cout<<ans[i]<<" ";
        nl;






    }


    return 0;


}
