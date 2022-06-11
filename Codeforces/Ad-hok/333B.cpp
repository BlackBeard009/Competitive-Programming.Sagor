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

    int n,m,i,j;
    cin>>n>>m;

    set <int> row,col;

    for(i=2 ; i<n ; i++){
        row.insert(i);
        col.insert(i);
    }

    for(i=0 ; i<m ; i++){
        int x,y;
        cin>>x>>y;

        if(row.find(x)!=row.end()) row.erase(x);
        if(col.find(y)!=col.end()) col.erase(y);
    }

    if(n%2){
        if(row.find((n+1)/2)!=row.end() && col.find((n+1)/2)!=col.end()) cout<<row.size()+col.size()-1;
        else cout<<row.size()+col.size();
    }
    else cout<<row.size()+col.size();

    nl;


    return 0;

}
