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

    map <int,vector<int> > mpp;
    set <int> st;

    int n,i,j;
    cin>>n;

    int arr[n],ans[n];
    memset(ans,-1,sizeof(ans));

    fr0(n,i){
        cin>>arr[i];
        mpp[arr[i]].pb(i);
        st.insert(arr[i]);
    }
    for(i=n-1 ; i>=0 ; i--){
        auto it=st.upper_bound(arr[i]);
        vector <int> vv;
        while(it!=st.end()){
            int tmp=*it;
            vv.pb(tmp);
            for(j=0 ; j<mpp[tmp].size() ; j++){
                ans[mpp[tmp][j]]=i-mpp[tmp][j]-1;
            }
            it++;
        }
        if(mpp[arr[i]].size() && lst(mpp[arr[i]])==i){
            mpp[arr[i]].ppb();
            if(mpp[arr[i]].empty()) st.erase(arr[i]);
        }
        for(j=0 ; j<vv.size() ; j++){
            st.erase(vv[j]);
            mpp[vv[j]].clear();
        }
    }
    for(i=0 ; i<n ; i++) cout<<ans[i]<<" ";
    nl;

    return 0;

}
