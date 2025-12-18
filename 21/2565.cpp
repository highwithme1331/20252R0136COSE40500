#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define INF 987654321

int N, A, B;
vector<pair<int, int>> input;
int dp[101];
int ans=INF;

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		cin>>A>>B;
		input.push_back(make_pair(A, B));
	}
	
	sort(input.begin(), input.end());
	
	for(int i=0; i<N; i++) {
		dp[i]=1;
		
		for(int j=0; j<i; j++) {
			if(input[j].second<input[i].second)
				dp[i]=max(dp[i], dp[j]+1);
		}
	}
	
	for(int i=0; i<N; i++) 
		ans=min(ans, N-dp[i]);
	
	cout<<ans;
}