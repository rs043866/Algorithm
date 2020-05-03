#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

void solve(vector<int> s,vector<int> f){
	vector<pair<int,int>> ans;

	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
	for(int i=0;i<s.size();i++){
		p.push(make_pair(f[i],s[i]));
	}

	auto it = p.top();
	int start = it.second;
	int end = it.first;
	p.pop();
	ans.push_back(make_pair(start,end));

	while(!p.empty()){
		auto itr = p.top();
		p.pop();
		if(itr.second >= end){
			start = itr.second;
			end = itr.first;
			ans.push_back(make_pair(start,end));
		}
	}

	for(auto it = ans.begin();it!=ans.end();it++){
		cout<<(*it).first<<","<<(*it).second<<'\n';
	}
}

int main(){
	FastIO
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	vector<int> s(n),f(n);
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n;i++) cin>>f[i];

	solve(s,f);
	return 0; 
}
