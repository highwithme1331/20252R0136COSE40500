#include <iostream>
using namespace std;

long long N, K;

long long count(long long num) {
	long long cnt=0;
	
	for(int i=1; i<=N; i++)
		cnt+=min(num/i, N);
	
	return cnt;
}

int main() {
	cin>>N>>K;
	
	long long left=1;
	long long right=N*N;
	
	while(left<=right) {
		long long mid=(left+right)/2;
		
		long long cnt=count(mid);
		
		if(cnt>=K)
			right=mid-1;
		
		else
			left=mid+1;
	}
	
	cout<<left;
}