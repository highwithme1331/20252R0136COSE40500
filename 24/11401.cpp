#include <iostream>
using namespace std;
#define mod 1000000007

int N, K;

long long power(int num, int exp) {
	if(exp==0)
		return 1;
	
	else {
		if(exp%2==1)
			return num*power(num, exp-1)%mod;
		
		else
			return power(num, exp/2)*power(num, exp/2)%mod;
	}
}

int main() {
	cin>>N>>K;
	
	long long A=1;
	
	for(int i=N-K+1; i<=N; i++)
		A=(A*i)%mod;
	
	long long B=1;
	
	for(int i=1; i<=K; i++)
		B=(B*i)%mod;
	
	B=power(B, mod-2);
	
	cout<<A*B%mod;
}