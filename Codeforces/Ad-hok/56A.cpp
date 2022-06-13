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




int main()
{

    int n,i,j;
    cin>>n;

    string s[11]={"ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE"};
    int ans=0;
    for(i=1 ; i<=n ; i++){
        string a;
        cin>>a;
        if(a[0]>='0' && a[0]<='9'){
            int num=0,pow=1;
            reverse(a.begin(),a.end());
            for(j=0 ; j<a.size() ; j++){
                num+=pow*(a[j]-'0');
                pow*=10;
            }
            if(num<18) ans++;
        }
        else{
            for(j=0 ; j<11 ; j++){
                if(a==s[j]) break;
            }
            if(j!=11) ans++;
        }
    }

    cout<<ans;
    nl;


    return 0;

}
