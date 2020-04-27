#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
	1.Divide and conquer algorithm
	2. NlogN average case.
	3. N^2 worst case.
	4. Fixed by Randomized quicksort 
	5. Inplace algorithm
*/
int partition(vector<int> &arr,int s,int e){
	//In place (Cant take extra array)
	int i = s-1;
	int j = s;
	int pivot = arr[e];

	for(;j<=e-1;){
		if(arr[j] <= pivot){
			//merge the smaller element in the region-1
			i = i + 1;
			swap(arr[i],arr[j]);
		}
		//expand the larger region
		j = j + 1;
	}
	swap(arr[i+1],arr[e]);
	return (i + 1);
} 

void quicksort(vector<int> &arr,int s,int e){
	//Base case
	if(s>=e)
		return;
	//Recusive Case
	int pivot = partition(arr,s,e);
	//left part
	quicksort(arr,s,pivot - 1);
	//right part
	quicksort(arr,pivot + 1,e);

	
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
	quicksort(vec,0,n-1);
	for(int i=0;i<n;i++)
		cout<<vec[i]<<" ";
}