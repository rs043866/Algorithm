#include <bits/stdc++.h> 
using namespace std;
#define     mod             1e9+7
#define     ll              long long
#define     mp              make_pair
#define     t()             int test;cin>>test;while(test--)
#define     setbits(x)      __builtin_popcountll(x)
#define     si              set<int>
#define     ii              pair<int,int>
#define     vi              vector<int>
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

void subsetSum(vector<int> &v,int sum){

    int n = v.size();

    bool t[n+1][sum+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            if(i == 0) t[i][j] = false;
            if(j == 0) t[i][j] = true;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(v[i-1] <= j)
                t[i][j] = t[i-1][j-v[i-1]] || t[i-1][j];
            else
                t[i][j] = t[i-1][j];
        }
    }

    vector<int> ans;
    int i=n;
    for(int j=0;j<=sum/2;j++){
        if(t[i][j]) ans.push_back(j);
    }

    int mini = INT_MAX;

    for(int i=0;i<ans.size();i++){
        mini = min(mini,sum - 2*ans[i]);
    }

    cout<<mini;
}

void solve(){

    int n,range = 0;
    cin>>n;

    vector<int> v(n);

    for(int i=0;i<n;i++) {
        cin>>v[i];
        range += v[i];
    }

    subsetSum(v,range);
}
 
int32_t main()
 
{  
    #ifndef ONLINE_JUDGE
    	freopen("input1.txt", "r", stdin);
    	freopen("output1.txt", "w", stdout);
    #endif

    IOS;

    solve();


}