#include <bits/stdc++.h>
#define ll long long int
#define FastIO ios::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
ll fastExpo(ll a,ll b,ll k){
    ll res = 1;
    while(b > 0){
        if(b&1){
            res = (res*a)%k;
        }
        a = a*a;
        b = b>>1;
    }
    return res;
}
int main(){
	FastIO
    cout<<fastExpo(5,3,100);
     
}