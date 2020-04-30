#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int longestUniqueChar(string str){
	int cur_len = 1,n = str.size();
	int max_len = 1;
	int prev_index;

	int *visited = new int[sizeof(int) * 256];

	for(int i=0;i<256;i++) visited[i] = -1;

	visited[str[0]] = 0;


	for(int i=1;i<n;i++){

		prev_index = visited[str[i]];

		if(prev_index==-1 || i - cur_len > prev_index)
			cur_len++;


		else{

			if(cur_len > max_len) 
				max_len = cur_len;

			cur_len = i - prev_index;
			cout<<cur_len<<" ";
		}

		visited[str[i]] = i;
	}

	if(cur_len > max_len)
		max_len = cur_len;

	free(visited);
	return max_len;
}

int main(){
	FastIO
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	string str;
	cin>>str;
	cout<<longestUniqueChar(str);

	return 0; 
}