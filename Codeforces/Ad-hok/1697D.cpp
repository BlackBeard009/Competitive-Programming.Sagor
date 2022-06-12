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

char ask1(int pos){
    cout<<"? 1 "<<pos<<endl;
    char ch;
    cin>>ch;
    return ch;
}
int ask2(int l,int r){
    cout<<"? 2 "<<l<<" "<<r<<endl;
    int inp;
    cin>>inp;
    return inp;
}


int main()
{

    int n,i,j;
    cin>>n;

    string ans;

    set < pair<int,char> > st;
    int pos[26];
    fr0(26,i) pos[i]=inf;

    for(i=1 ; i<=n ; i++){
        if(st.empty()){
            char ch=ask1(i);
            ans.pb(ch);
            st.insert({i,ch});
            pos[ch-'a']=i;
            continue;
        }

        auto it = st.begin();
        int ff=it->first;
        int x=ask2(ff,i);
        if(x!=st.size()){
            char ch=ask1(i);
            ans.pb(ch);
            st.insert({i,ch});
            pos[ch-'a']=i;
            continue;
        }

        int lo=1,hi=st.size();

        while(lo<hi){
            int mid=(lo+hi+1)/2;
            int xx=1;
            it=st.begin();
            while(1){
                if(xx==mid) break;
                xx++;
                it++;
            }
            int pp=it->first;
            x=ask2(pp,i);
            if(x==st.size()-mid+1) lo=mid;
            else hi=mid-1;
        }

        it=st.begin();
        int xx=1;
        while(1){
            if(xx==lo) break;
            xx++;
            it++;
        }
        ans.pb(it->second);
        char ch=it->second;
        st.erase({pos[ch-'a'],ch});
        st.insert({i,ch});
        pos[ch-'a']=i;
    }

    cout<<"! "<<ans<<endl;

    return 0;

}
