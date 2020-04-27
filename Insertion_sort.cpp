#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &arr){
	int n = arr.size();
	for(int i=1;i<n-1;i++){
		int e = arr[i];
		//place the current element at "right" position in the sorted part.
		int j=i-1;
		while(j>=0 && arr[j] > e){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = e; 
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
	insertion_sort(vec);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
	cout<<endl;
}