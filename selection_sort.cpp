#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> &arr){
	int n = arr.size();
	for(int i=0;i<n-1;i++){
		int min_idx = i;
		for(int j=i;j<=n-1;j++){
			if(arr[j] < arr[min_idx])
				min_idx = j;
		}
		swap(arr[i],arr[min_idx]);
	}
}

int main(){
	int n;
	cin>>n;
	vector<int> vec;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		vec.push_back(t);
	}
	selection_sort(vec);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
}