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

int nxt[N][26],cnt[N],f[N],vis[N],num;
vector <int> g[N],qrnode; //fail node tree

string s; //given string and pattern

//adding patterns to the trie
void add(){
    int node=0,i,len=s.size();

    for(i=0 ; i<len ; i++){
        int ch=s[i]-'A';

        if(nxt[node][ch]){
            node=nxt[node][ch];
        }
        else{
            nxt[node][ch] = ++num;
            node = num;
        }
        qrnode.pb(node);

    }
}

//building automaton
void build_aho(){
    queue <int> q;
    int i,u,v,curr;

    for(i=0 ; i<26 ; i++){
        if(nxt[0][i]) q.push(nxt[0][i]);
    }

    while(q.size()){
        curr = q.front();
        q.pop();

        for(i=0 ; i<26 ; i++){
            if(nxt[curr][i]){
                u=nxt[curr][i];
                q.push(u);
                v=f[curr];
                while(v && nxt[v][i]==0){
                    v=f[v];
                }
                f[u]=nxt[v][i];
                g[f[u]].pb(u);
            }
        }
    }

}
//searching the string
void search(){
    int j=0,i,len=s.size();

    for(i=0 ; i<len ; i++){
        int ch=s[i]-'A';

        while(j && nxt[j][ch]==0){
            j = f[j];
        }

        j=nxt[j][ch];

        cnt[j]++;
    }
}
//dfs to add cnts of fail node subtree of a node
void dfs(int node){
    vis[node]=1;
    for(auto to : g[node]){
        if(!vis[to]){
            dfs(to);
            cnt[node]+=cnt[to];
        }

    }
}
ll hf1[N],hf2[N],hr1[N],hr2[N],base1=29,base2=59,mod1=281089147,mod2=58343671;
void hh(){
    int i,j,len=s.size();
    ll p1=base1,p2=base2,val1=0,val2=0;
    for(i=0 ; i<len ; i++){
        val1=(val1+(s[i]-'A')*p1)%mod1;
        val2=(val2+(s[i]-'A')*p2)%mod2;
        p1=(p1*base1)%mod1;
        p2=(p2*base2)%mod2;
        hf1[i]=val1;
        hf2[i]=val2;
    }
}

void rhh(){
    int i,j,len=s.size();
    ll val1=0,val2=0;
    for(i=len-1 ; i>=0 ; i--){
        val1=(val1*base1 + (s[i]-'A')*base1)%mod1;
        val2=(val2*base2 + (s[i]-'A')*base2)%mod2;
        hr1[i]=val1;
        hr2[i]=val2;
    }
}


int main()
{

    fastio;

    int i,j;

    cin>>s;

    add();
    build_aho();
    search();
    hh();
    rhh();
    int n=s.size();
    for(i=1 ; i<=n ; i++) dfs(i);
    vector < pair<int,int> > ans;
    for(i=0 ; i<n ; i++){
        if(hf1[i]==hr1[n-i-1] && hf2[i]==hr2[n-i-1]){
            ans.pb({i+1,cnt[qrnode[i]]});
        }
    }

    cout<<ans.size();
    nl;

    for(i=0 ; i<ans.size() ; i++){
        cout<<ans[i].first<<" "<<ans[i].second;
        nl;
    }






    return 0;
}
