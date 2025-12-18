#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int W[101];
int V[101];
int dp[101][100001];

int main() {
	cin>>N>>K;
	
	for(int i=1; i<=N; i++)
		cin>>W[i]>>V[i];
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=K; j++) {
            dp[i][j]=dp[i-1][j];
            
			if(W[i]<=j)
				dp[i][j]=max(dp[i][j], dp[i-1][j-W[i]]+V[i]);
		}
	
	cout<<dp[N][K];
}