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

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/



int main()
{

    fastio;




    ll n,m,k,p,i,j;

    cin>>n>>m>>k>>p;


    ll arr[n][m];

    ll rr[n]={0},cc[m]={0};

    priority_queue <ll> row,col;
    fr0(n,i){
        fr0(m,j){
            cin>>arr[i][j];
            rr[i]+=arr[i][j];
            cc[j]+=arr[i][j];
        }
    }

    fr0(n,i) row.push(rr[i]);
    fr0(m,i) col.push(cc[i]);

    ll rmx[k+1],cmx[k+1];
    rmx[0]=0;
    cmx[0]=0;
    for(i=1 ; i<=k ; i++){
        ll tmp=row.top();
        row.pop();
        rmx[i]=rmx[i-1]+tmp;
        tmp-=m*p;
        row.push(tmp);
    }
    for(i=1 ; i<=k ; i++){
        ll tmp=col.top();
        col.pop();
        cmx[i]=cmx[i-1]+tmp;
        tmp-=n*p;
        col.push(tmp);
    }

    ll ans=LLONG_MIN;

    for(i=0 ; i<=k ; i++){

        ans=max(ans,rmx[i]+cmx[k-i]-i*(k-i)*p);
    }
    cout<<ans;
    nl;







    return 0;
}
