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

/***
   * Multiply (7x^2 + 8x^1 + 9x^0) with (6x^1 + 5x^0)
   * ans = 42x^3 + 83x^2 + 94x^1 + 45x^0
   * A = {9, 8, 7}
   * B = {5, 6}
   * V = multiply(A,B)
   * V = {45, 94, 83, 42}
***/

/*** Tricks
   * Use vector < bool > if you need to check only the status of the sum
   * Use bigmod if the power is over same polynomial && power is big
   * Use long double if you need more precision
   * Use long long for overflow
***/
typedef vector <int> vi;
const double PI = 2.0 * acos(0.0);
using cd = complex<double>;

void fft(vector<cd> & a, bool invert = 0)

{
    int n = a.size();

    for (int i = 1, j = 0; i < n; i++) {
        int bit = n >> 1;
        for (; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;

        if (i < j)
            swap(a[i], a[j]);
    }

    for (int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for (int i = 0; i < n; i += len) {
            cd w(1);
            for (int j = 0; j < len / 2; j++) {
                cd u = a[i+j], v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w *= wlen;
            }
        }
    }

    if (invert) {
        for (cd & x : a)
            x /= n;
    }
}

void ifft(vector <cd> & p)

{
    fft(p, 1);
}

vi multiply(vi const& a, vi const& b)

{

    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);

    fft(fa);
    fft(fb);
    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    ifft(fa);

    vi result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());

    return result;
}

int main()
{

    fastio;


    int t,tc=1;

    cin>>t;

    vector <int> a,b,ans;

    while(t--){
        a.clear();
        b.clear();
        int n,m,i,j;

        cin>>n;

        fr0(n+1,i){
            cin>>j;
            a.pb(j);
        }

        cin>>m;

        fr0(m+1,i){
            cin>>j;
            b.pb(j);
        }

        ans = multiply(a,b);
        cout<<"Case "<<tc++<<": ";
        while(ans.size()>1 && lst(ans)==0) ans.ppb();
        cout<<ans.size()-1<<" ";
        for(i=0 ; i<ans.size() ; i++){
            cout<<ans[i]<<" ";
        }

        nl;


    }








    return 0;
}
