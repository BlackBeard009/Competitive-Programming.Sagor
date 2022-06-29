#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
#define N  205
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

using namespace std;
/*mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int gen_random(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}*/


int main()
{
    fastio;

    int a,b,c,d,i,j;

    cin>>a>>b>>c>>d;

    string ans;

    if(c==d+1){
        a-=c;
        b-=c;
        if(a<0 || b<0) cout<<"-1";
        else{
            for(i=0 ; i<c ; i++){
                ans.pb('4');
                ans.pb('7');
            }
        }
        int posa=-1,posb=-1;
        for(i=0 ; i<ans.size() ; i++){
            if(ans[i]=='4'){
                posa=i;
                break;
            }
        }
        for(i=ans.size()-1 ; i>=0 ; i--){
            if(ans[i]=='7'){
                posb=i;
                break;
            }
        }

        for(i=0 ; i<ans.size() ; i++){
            cout<<ans[i];
            if(i==posa){
                for(j=0 ; j<a ; j++) cout<<'4';
            }
            if(i==posb){
                for(j=0 ; j<b ; j++) cout<<'7';
            }

        }

    }
    else if(d==c+1){
        a-=d;
        b-=d;
        if(a<0 || b<0) cout<<"-1";
        else{
            for(i=0 ; i<d ; i++){
                ans.pb('7');
                ans.pb('4');
            }
        }
        int posa=-1,posb=-1;
        for(i=0 ; i<ans.size() ; i++){
            if(ans[i]=='4'){
                posa=i;
                break;
            }
        }
        for(i=ans.size()-1 ; i>=0 ; i--){
            if(ans[i]=='7'){
                posb=i;
                break;
            }
        }

        for(i=0 ; i<ans.size() ; i++){
            cout<<ans[i];
            if(i==posa){
                for(j=0 ; j<a ; j++) cout<<'4';
            }
            if(i==posb){
                for(j=0 ; j<b ; j++) cout<<'7';
            }

        }
    }
    else if(c==d){
        if(a>=c+1 && b>=c){
            ans.pb('4');
            for(i=0 ; i<c ; i++){
                ans.pb('7');
                ans.pb('4');
            }
            a-=(c+1);
            b-=c;
            int posa=-1,posb=-1;
            for(i=0 ; i<ans.size() ; i++){
                if(ans[i]=='4'){
                    posa=i;
                    break;
                }
            }
            for(i=ans.size()-1 ; i>=0 ; i--){
                if(ans[i]=='7'){
                    posb=i;
                    break;
                }
            }

            for(i=0 ; i<ans.size() ; i++){
                cout<<ans[i];
                if(i==posa){
                    for(j=0 ; j<a ; j++) cout<<'4';
                }
                if(i==posb){
                    for(j=0 ; j<b ; j++) cout<<'7';
                }

            }
        }
        else if(a>=c && b>=c+1){
            ans.pb('7');
            for(i=0 ; i<c ; i++){
                ans.pb('4');
                ans.pb('7');
            }
            a-=c;
            b-=(c+1);
            int posa=-1,posb=-1;
            for(i=0 ; i<ans.size() ; i++){
                if(ans[i]=='4'){
                    posa=i;
                    break;
                }
            }
            for(i=ans.size()-1 ; i>=0 ; i--){
                if(ans[i]=='7'){
                    posb=i;
                    break;
                }
            }

            for(i=0 ; i<ans.size() ; i++){
                cout<<ans[i];
                if(i==posa){
                    for(j=0 ; j<a ; j++) cout<<'4';
                }
                if(i==posb){
                    for(j=0 ; j<b ; j++) cout<<'7';
                }

            }
        }
        else cout<<"-1";
    }
    else cout<<"-1";

    nl;

    return 0;

}
