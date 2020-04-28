#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
//Recursive approach
unsigned long int catalan(unsigned int n){
	if(n<=1) return 1;

	unsigned long int res = 0;
	for(int i=0;i<n;i++){
		res += catalan(i) * catalan(n-i-1);
	}
	return res;
}
//Dynamic approach
unsigned long int catalanDp(unsigned int n){
	unsigned long int catalan[n+1];

	catalan[0] = catalan[1] = 1;

	for(int i=2;i<=n;i++){
		catalan[i] = 0;
		for(int j=0;j<i;j++){
			catalan[i] += catalan[j] * catalan[i-j-1];
		}
	}
	return catalan[n];
}
int main(){
	FastIO
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cout<<catalan(i)<<" ";
	}

	

	return 0; 
}