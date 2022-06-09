#include <iostream>
#include <queue>
#include <set>
#include <list>
#include <deque>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <string>
#include <iterator>
#define ll long long
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define powr(x,n,p) for(int axy=0 ; axy<p ; axy++){x=x*n;}
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
#define nl printf("\n")
#define fr0(n,q) for(q=0 ; q<n ; q++)
#define fr1(n,q) for(q=1 ; q<=n ; q++)
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define lst(x) x[x.size()-1]
#define llst(x) x[x.size()-2]
using namespace std;
int main()
{
	int n,m;
	sci(n);
	sci(m);
	int arr[n+1],i;
	map <int, set<int> > var;
	for(i=1 ; i<=n ; i++){
		sci(arr[i]);
		var[arr[i]];
	}
	for(i=0 ; i<m ; i++){
		int u,v;
		sci(u);
		sci(v);
		int x=arr[u],y=arr[v];
		if(x!=y){
			var[x].insert(y);
			var[y].insert(x);
		}
	}
	int ans=-1,mx=-1;
	for(auto it=var.begin() ; it!=var.end() ; it++){
		int xx=it->first;
		int sz=var[xx].size();
		if(sz>mx){
			mx=sz;
			ans=xx;
		}
	}
	cout<<ans;
	nl;
	return 0;
}
