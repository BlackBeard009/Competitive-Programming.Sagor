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
        int n,i,j;

        cin>>n;

        string a,b;

        cin>>a>>b;

        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());

        set <int> aa,bb,cc;

        fr0(n,i){
            if(a[i]=='a') aa.insert(i);
            else if(a[i]=='b') bb.insert(i);
            else cc.insert(i);
        }

        for(i=0 ; i<n ; i++){
            if(a[i]==b[i]) continue;
            if(a[i]=='a' && b[i]=='b') break;
            if(b[i]=='c') break;
            if(a[i]=='c' && b[i]=='a') break;
            if(a[i]=='b' && b[i]=='a'){
                auto it1=aa.upper_bound(i);
                if(it1==aa.end()) break;
                auto it2=cc.upper_bound(i);
                if(it2==cc.end()){
                    int x=*it1;
                    swap(a[i],a[x]);
                    aa.erase(it1);
                    aa.insert(i);
                    bb.erase(i);
                    bb.insert(x);
                }
                else if(*it2>*it1){
                    int x=*it1;
                    swap(a[i],a[x]);
                    aa.erase(it1);
                    aa.insert(i);
                    bb.erase(i);
                    bb.insert(x);
                }
                else break;
            }
            else{
                auto it1=bb.upper_bound(i);
                if(it1==bb.end()) break;
                auto it2=aa.upper_bound(i);
                if(it2==aa.end()){
                    int x=*it1;
                    swap(a[i],a[x]);
                    bb.erase(it1);
                    bb.insert(i);
                    cc.erase(i);
                    cc.insert(x);
                }
                else if(*it2>*it1){
                    int x=*it1;
                    swap(a[i],a[x]);
                    bb.erase(it1);
                    bb.insert(i);
                    cc.erase(i);
                    cc.insert(x);
                }
                else break;
            }
        }

        if(i==n) YES;
        else NO;



    }

    return 0;

}
