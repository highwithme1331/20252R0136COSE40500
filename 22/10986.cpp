#include <iostream>
using namespace std;

int N, M, A;
long long modM[1001];
long long ans=0;

int main() {
	cin>>N>>M;
	
	long long sum=0;
	
	for(int i=0; i<N; i++) {
		cin>>A;
		sum+=A;
		modM[sum%M]++;
	}
	
	for(int i=0; i<M; i++)
		ans+=modM[i]*(modM[i]-1)/2;
	
	cout<<ans+modM[0];
}