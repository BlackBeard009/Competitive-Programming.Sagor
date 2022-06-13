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
    fastio;

    string s;
    int i,j,k;
    cin>>s;

    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<2 ; j++){
            for(k=0 ; k<2 ; k++){
                int tmp=s[0]-'0';
                if(i) tmp+=(s[1]-'0');
                else tmp-=(s[1]-'0');
                if(j) tmp+=(s[2]-'0');
                else tmp-=(s[2]-'0');
                if(k) tmp+=(s[3]-'0');
                else tmp-=(s[3]-'0');

                if(tmp==7){
                    cout<<s[0];
                    if(i) cout<<"+";
                    else cout<<"-";
                    cout<<s[1];
                    if(j) cout<<"+";
                    else cout<<"-";
                    cout<<s[2];
                    if(k) cout<<"+";
                    else cout<<"-";
                    cout<<s[3];
                    cout<<"=7";
                    nl;
                    return 0;

                }
            }
        }
    }


    return 0;

}
