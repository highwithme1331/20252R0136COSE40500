#include <iostream>
#include <algorithm>
using namespace std;
#define INF 987654321

int N, M, K;
int input[2001][2001];
int black[2001][2001];
int white[2001][2001];
int bsum[2001][2001];
int wsum[2001][2001];
int ans=INF;

int main() {
	cin>>N>>M>>K;
	
	for(int i=1; i<=N; i++) {
		string line;
		cin>>line;

		for(int j=1; j<=M; j++)
			if(line[j-1]=='B')
				input[i][j]=1;
			
			else
				input[i][j]=0;
	}
	
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++) {
			if((i+j)%2==0) {
				black[i][j]=1;
				white[i][j]=0;
			}
			
			else {
				black[i][j]=0;
				white[i][j]=1;
			}
		}
		
	for(int i=1; i<=N; i++) 
		for(int j=1; j<=M; j++) {
			if(input[i][j]==black[i][j]) {
				black[i][j]=0;
				white[i][j]=1;
			}
			
			else {
				black[i][j]=1;
				white[i][j]=0;
			}
		}
		
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++) {
			bsum[i][j]=bsum[i-1][j]+bsum[i][j-1]-bsum[i-1][j-1]+black[i][j];
			wsum[i][j]=wsum[i-1][j]+wsum[i][j-1]-wsum[i-1][j-1]+white[i][j];
		}
	
	for(int i=1; i<=N-K+1; i++)
		for(int j=1; j<=M-K+1; j++) {
			ans=min(ans, bsum[i+K-1][j+K-1]-bsum[i-1][j+K-1]-bsum[i+K-1][j-1]+bsum[i-1][j-1]);
			ans=min(ans, wsum[i+K-1][j+K-1]-wsum[i-1][j+K-1]-wsum[i+K-1][j-1]+wsum[i-1][j-1]);
		}

	cout<<ans;
}