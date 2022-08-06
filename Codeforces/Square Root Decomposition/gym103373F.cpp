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
#define md 998244353
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=(x|(1LL<<y))
#define off(x,y) x=(x&(~(1LL<<y)))
#define pi acos(-1)
#define inf (1<<30)
#define N  200005
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pi acos(-1)
using namespace std;
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(2) -> element at index 2
//s.order_of_key(3) -> lower bound of 3

/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/


int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    fastio;

    ll n,q,i,j;

    cin>>n>>q;

    ll arr[n+5];

    for(i=1 ; i<=n ; i++) cin>>arr[i];

    vector <ll> vv;

    vv.pb(0);

    for(i=2 ; i<=n ; i++){
        if(arr[i]==arr[i-1]){
            vv.pb(i-1);
        }
    }

    vv.pb(n);

    vector < pair <ll,ll> > sq;

    ll s=sqrt(n+1),lst=0;


    for(i=1 ; i<=n ; i++){
        if(i-lst+1==s){
            sq.pb({lst,i});
            lst=i+1;
        }
    }

    if(lst<=n) sq.pb({lst,n});

    ll sz=sq.size();
    

    vector < set <ll> > blocks(sz);

    ll cur=0;

    for(i=0 ; i<vv.size() ; i++){
        while(vv[i]>sq[cur].second){
            cur++;
            if(cur==sz) assert(0);
        }
        blocks[cur].insert(vv[i]);
    }
    vector <ll> ff(sz),ss(sz),val(sz);
    for(i=0 ; i<sz ; i++){
        if(blocks[i].empty()){
            ff[i]=-1;
            ss[i]=-1;
        }
        else{
            ff[i]=*(blocks[i].begin());
            auto it=blocks[i].end();
            it--;
            ss[i]=*it;
        }

        if(blocks[i].size()>=2){
            auto it=blocks[i].begin();
            ll prev=*it;
            it++;
            ll sum=0;
            for( ; it!=blocks[i].end() ; it++){
                ll tmp=*it-prev;
                sum+=(tmp*(tmp+1))/2;
                prev=*it;
            }
            val[i]=sum;
        }
        else{
            val[i]=0;
        }        
    }


    while(q--){

        ll t,l,r;

        cin>>t>>l>>r;
        l--;

        if(t==1){
            for(i=0 ; i<sz && l; i++){
                if(sq[i].first<=l && sq[i].second>=l){
                    if(blocks[i].find(l)!=blocks[i].end()) blocks[i].erase(l);
                    else blocks[i].insert(l);
                    if(blocks[i].empty()){
                        ff[i]=-1;
                        ss[i]=-1;
                    }
                    else{
                        ff[i]=*(blocks[i].begin());
                        auto it=blocks[i].end();
                        it--;
                        ss[i]=*it;
                    }

                    if(blocks[i].size()>=2){
                        auto it=blocks[i].begin();
                        ll prev=*it;
                        it++;
                        ll sum=0;
                        for( ; it!=blocks[i].end() ; it++){
                            ll tmp=*it-prev;
                            sum+=(tmp*(tmp+1))/2;
                            prev=*it;
                        }
                        val[i]=sum;
                    }
                    else{
                        val[i]=0;
                    }
                    break;
                }
                
            }
            for(i=0 ; i<sz && r!=n ; i++){
                if(sq[i].first<=r && sq[i].second>=r){
                    if(blocks[i].find(r)!=blocks[i].end()) blocks[i].erase(r);
                    else blocks[i].insert(r);
                    if(blocks[i].empty()){
                        ff[i]=-1;
                        ss[i]=-1;
                    }
                    else{
                        ff[i]=*(blocks[i].begin());
                        auto it=blocks[i].end();
                        it--;
                        ss[i]=*it;
                    }

                    if(blocks[i].size()>=2){
                        auto it=blocks[i].begin();
                        ll prev=*it;
                        it++;
                        ll sum=0;
                        for( ; it!=blocks[i].end() ; it++){
                            ll tmp=*it-prev;
                            sum+=(tmp*(tmp+1))/2;
                            prev=*it;
                        }
                        val[i]=sum;
                    }
                    else{
                        val[i]=0;
                    }
                    break;
                }
                
            }
        }
        else{

            ll ans=0;

            ll lb=-1,rb=-1;

            for(i=0 ; i<sz ; i++){
                if(sq[i].first<=l && sq[i].second>=l){
                    lb=i;
                    break;
                }
            }

            for(i=0 ; i<sz ; i++){
                if(sq[i].first<=r && sq[i].second>=r){
                    rb=i;
                    break;
                }
            }


            if(lb==rb){
                auto it1=blocks[lb].lower_bound(l);
                ll lst=l;

                for( ; it1!=blocks[lb].end() ; it1++){
                    if(*it1>=r) break;
                    ll tmp=(*it1-lst);
                    ans+=(tmp*(tmp+1))/2;
                    lst=*it1;
                }
                ll tmp=(r-lst);
                ans+=(tmp*(tmp+1))/2;
            }
            else{

                auto it1=blocks[lb].lower_bound(l);
                ll lst=l;

                for( ; it1!=blocks[lb].end() ; it1++){
                    ll tmp=(*it1-lst);
                    ans+=(tmp*(tmp+1))/2;
                    lst=*it1;
                }

                for(i=lb+1 ; i<rb ; i++){
                    if(blocks[i].empty()) continue;

                    ll tmp=(*(blocks[i].begin())-lst);
                    ans+=(tmp*(tmp+1))/2;
                    ans+=val[i];
                    auto it=blocks[i].end();
                    it--;
                    lst=*it;
                }

                for(auto it=blocks[rb].begin() ; it!=blocks[rb].end() ; it++){
                    if(*it>=r) break;
                    ll tmp=(*it-lst);
                    ans+=(tmp*(tmp+1))/2;
                    lst=*it;
                }

                ll tmp=(r-lst);
                ans+=(tmp*(tmp+1))/2;

            }

            cout<<ans;
            nl;



        }



    }




    


    return 0;


}