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


    int t;
    cin>>t;
    while(t--){
        int n,i,j,ans=0;
        cin>>n;
        int arr[n],xx[n]={0};
        fr0(n,i) cin>>arr[i];
        for(i=1 ; i<n-1 ; i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]) xx[i]=1,ans++;
            if(arr[i]<arr[i-1] && arr[i]<arr[i+1]) xx[i]=1,ans++;
        }
        int mx=0;
        for(i=1 ; i<n-1 ; i++){
            int cnt=0;
            if(i+2<n && ((arr[i+1]>arr[i-1] && arr[i+1]>arr[i+2]) || (arr[i+1]<arr[i-1] && arr[i+1]<arr[i+2]))) cnt++;
            mx=max(mx,xx[i]+xx[i+1]+xx[i-1]-cnt);
            cnt=0;
            if(i-2>=0 && ((arr[i-1]>arr[i+1] && arr[i-1]>arr[i-2]) || (arr[i-1]<arr[i+1] && arr[i-1]<arr[i-2]))) cnt++;
            mx=max(mx,xx[i]+xx[i+1]+xx[i-1]-cnt);
            if(arr[i+1]==arr[i-1]) mx=max(mx,xx[i]+xx[i-1]+xx[i+1]);
        }
        cout<<ans-mx;
        nl;
    }

    return 0;

}
