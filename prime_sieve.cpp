#include <bits/stdc++.h>
#define ll long long int
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
void prime_sieve(int *p){
	//mark all odd nos prime.
	for(int i=3;i<=1000000;i+=2){
		p[i] = 1;
	}
	for(ll i=3;i<=1000000;i+=2){
		if(p[i] == 1){
			for(ll j=i*i;j<=1000000;j = j + i){
				p[j] = 0;
			}
		}
	}
	p[2] = 1;
	p[1] = p[0] = 0;
}

int main(){
	FastIO
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif

	int n;
	cin>>n;
	int p[1000005] = {0};
	prime_sieve(p);

	for(int i=0;i<=n;i++){
		if(p[i] == 1){
			cout<<i<<" ";
		}
	}

}