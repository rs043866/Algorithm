#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//nth fibonacci number;
//top down approach : recursion + dp array (memoisation)
int fib_top(int n,int dp[]){
	//Base case
	if(n==0 || n==1)
		return n;
	//Recursive case. 
	if(dp[n]!=0){
		return dp[n];
	}  
	int ans;
	ans = fib(n-1,dp) + fib(n-2,dp);
	return dp[n] = ans;
}
//Bottom - up approach;
int fib_bottom(){
	int dp[1001] = {0};
	dp[1] = 1;

	for(int i=2;i<n;i++){
		dp[i] = dp[i-1] + dp[i-2];
	}
	return dp[n];

}
//Bottom up approach with Space Optimization
int fib_space_optimize(int n){
	if(n==0 || n==1)
		return n;
	int a = 0;
	int b = 1;
	int c;
	for(int i=2;i<=n;i++){
		c = a + b;
		a = b;
		b = c;
	}
	return c;
}
//Matrix Exponentiation to reduce space complexity.
//O(LogN)
int main(){  
	int n;
	cin>>n;
	int dp[1001] = {0};
	//cout<<fib_top(n,dp);
	cout<<fib_bottom()
	return 0;
}