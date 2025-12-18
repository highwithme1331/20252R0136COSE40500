#include <iostream>
using namespace std;

int N;
int input[1000001];
int list[1000001];

int binarysearch(int left, int right, int target) {
	while(left<=right) {
		int mid=(left+right)/2;
		
		if(list[mid]>=target)
			right=mid-1;
		
		else
			left=mid+1;
	}
	
	return left;
}

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++)
		cin>>input[i];
	
	list[0]=input[0];
	int idx=0;
	
	for(int i=1; i<N; i++) {
		if(list[idx]<input[i]) {
			idx++;
			list[idx]=input[i];
		}
		
		else {
			int nidx=binarysearch(0, idx, input[i]);
			list[nidx]=input[i];
		}
	}
	
	cout<<idx+1;
}