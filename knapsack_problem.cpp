#include <bits/stdc++.h> 
using namespace std;
#define     mod             1e9+7
#define     ll              long long
#define     mp              make_pair
#define     t()             int test;cin>>test;while(test--)
#define     setbits(x)      __builtin_popcountll(x)
#define     si              set<int>
#define     ii              pair<int,int>
#define     que_max         priority_queue <int>
#define     que_min         priority_queue <int, vi, greater<int>>
#define     IOS             ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define     endl            '\n'

/*
	For Debugging we have define TRACE.
*/

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
    template <typename Arg1>
    void __f(const char* name, Arg1&& arg1){
        cout << name << " : " << arg1 << endl;
        //use cerr if u want to display at the bottom
    }
    template <typename Arg1, typename... Args>
    void __f(const char* names, Arg1&& arg1, Args&&... args){
        const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
    }
#else
#define trace(...)
#endif  

const int N = 2e5 + 5;
int a[N];

int knapsack(vector<int> &wt,vector<int> &val,int w,int n,int t[][1002]){

	if(n == 0 || w == 0)
		return 0;
	if(wt[n-1] <= w)
		return t[n][w] = max(val[n-1] + knapsack(wt,val,w-wt[n-1],n-1,t),knapsack(wt,val,w,n-1,t));
	else
		return t[n][w] = knapsack(wt,val,w,n-1,t);
}

void solve(){

	int n,w;
	cin>>n>>w;
	vector<int> wt(n),val(n);

	for(int i=0;i<n;i++) cin>>wt[i];
	for(int i=0;i<n;i++) cin>>val[i];

	int t[n+1][w+1];

	for(int i=0;i<n+1;i++){
		for(int j=0;j<w+1;j++){
			if(i==0 || j == 0) 
				t[i][j] = 0;
		}
	}
	for(int i=1;i<n+1;i++){
		for(int j=1;j<w+1;j++){
			if(wt[i-1] <= j)
				t[i][j] = max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
			else
				t[i][j] = t[i-1][j];
		}
	}
	cout<<t[n][w];
}
 
int32_t main()
 
{  
    #ifndef ONLINE_JUDGE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
    #endif

    IOS;

    solve();


}