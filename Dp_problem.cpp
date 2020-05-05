/*
Q. Find all N-digit Binary Strings without any consecutive 1's:

Input : 3
output : 5

Explanation : 000, 001, 010, 100, 101 (total - 5)

*/
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int ans[1001][2]; //[1001] => length of string, [2] => no of solution.
//[5][0]
//[5][1]
int f(int n){
	ans[0][0] = 0;
	ans[0][1] = 0;
	ans[1][0] = 1;
	ans[1][1] = 1;

	for(int i=2;i<=n;i++){
		ans[i][0] = ans[i-1][0] + ans[i-1][1]; 
		ans[i][1] = ans[i-1][0];
	}
	return ans[n][0] + ans[n][1];

}

int dp(int n, int last_digit){
	if(n == 0) return 0;
	if(n == 1){
		if(last_digit == 1)
			return 1;
		else
			return 2;
	}
	if(last_digit == 0){
		return dp(n-1, 0) + dp(n-1,1);
	}
	//if last digit is 1 for n size problem.
	else{
		return dp(n-1,0);
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
	cout<<f(n)<<endl;
	

	return 0; 
}
