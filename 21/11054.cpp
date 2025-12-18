#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int N;
int input[1001];
int dp1[1001];
int dp2[1001];
int ans=-INF;

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) 
		cin>>input[i];
	
	for(int i=0; i<N; i++) {
		dp1[i]=1;
		
		for(int j=0; j<i; j++)
			if(input[j]<input[i])
				dp1[i]=max(dp1[i], dp1[j]+1);
	}
	
	for(int i=N-1; i>=0; i--) {
		dp2[i]=1;
		
		for(int j=N-1; j>i; j--)
			if(input[j]<input[i])
				dp2[i]=max(dp2[i], dp2[j]+1);
	}
	
	for(int i=0; i<N; i++)
		ans=max(ans, dp1[i]+dp2[i]-1);
	
	cout<<ans;
}