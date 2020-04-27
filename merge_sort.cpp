#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 divide and conquer algorithm
*/

void merge(vector<int> &arr,int s,int e){
	int mid = (s+e)/2;

	int i = s;
	int j = mid+1;
	int k = s;

	int temp[10001];

	while(i<=mid && j<=e){
		if(arr[i] < arr[j]){
			temp[k++] = arr[i++];
		}
		else{
			temp[k++] = arr[j++];
		}
	}
	while(i<=mid){
		temp[k++] = arr[i++];
	}
	while(j<=e){
		temp[k++] = arr[j++];
	}

	for(int i=s;i<=e;i++){
		arr[i] = temp[i];
	}

}
void mergeSort(vector<int> &arr,int s,int e){
	//Base case - 1 or 0 elements
	if(s>=e) return;

	//Follow 3 steps.
	//1.Divide
	int mid = (s+e)/2;
	//Recursively the arrays - s,mid and mid+1,e;
	mergeSort(arr,s,mid);
	mergeSort(arr,mid+1,e);

	//Merge the two parts.
	merge(arr,s,e);
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
	mergeSort(vec,0,n-1);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
}
