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
#define md 1000000000
#define check(x,y) (x&(1LL<<y))
#define set(x,y) x=(x|(1LL<<y))
#define off(x,y) x=(x&(~(1LL<<y)))
#define pi acos(-1)
#define inf (1<<30)
#define N  100005
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

typedef vector <ll> vi;
const double PI = 2.0*acos(0.0);
using cd = complex<double>;

void fft(vector<cd> &a, bool invert = 0){
    ll n=a.size();
    for(ll i=1, j=0 ; i<n ; i++){
        ll bit=n>>1;
        for( ; j & bit ; bit>>=1)
            j^=bit;
        j^=bit;

        if(i<j) swap(a[i],a[j]);
    }

    for(ll len=2 ; len<=n ; len<<=1){
        double ang = 2*PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang),sin(ang));
        for(ll i=0 ; i<n ; i+=len){
            cd w(1);
            for(ll j=0 ; j<len/2 ; j++){
                cd u = a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v;
                a[i+j+len/2]=u-v;
                w*=wlen;
            }
        }
    }

    if(invert){
        for(cd & x : a){
            x/=n;
        }
    }
}

void ifft(vector <cd> &p){
    fft(p,1);

}

vi multiply(vi const& a, vi const& b){
    vector <cd> fa(a.begin(),a.end()),fb(b.begin(),b.end());
    ll n=1;
    while(n<a.size() + b.size())
        n<<=1;

    fa.resize(n);
    fb.resize(n);

    fft(fa);
    fft(fb);

    for(ll i=0 ; i<n ; i++)
        fa[i]*=fb[i];
    ifft(fa);
    vi result(n);

    for(ll i=0 ; i<n ; i++)
        result[i]=round(fa[i].real());

    return result;


}

int main()
{

    /*freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);*/

    fastio;


    ll n,m,i,j;

    cin>>n>>m;

    vector <ll> a(N),b;

    for(i=1 ; i<=n ; i++){
        ll tmp;
        cin>>tmp;

        a[tmp]++;

    }

    b=a;

    vector <ll> ans;

    ans=multiply(a,b);

    ll anss=0;
    for(i=ans.size()-1 ; i>=0 && m ; i--){
        ll tmp=min((ll)ans[i],(ll)m);
        anss+=(tmp*i);

        m-=tmp;
    }

    cout<<anss;
    nl;






    return 0;


}
