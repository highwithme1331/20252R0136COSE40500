#include <iostream>
using namespace std;

long long N, B;
long long A[5][5];
long long ans[5][5];

void product(long long m1[5][5], long long m2[5][5]) {
	long long temp[5][5];
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) {
			temp[i][j]=0;
			
			for(int k=0; k<N; k++)
				temp[i][j]+=m1[i][k]*m2[k][j];
			
			temp[i][j]%=1000;
		}
		
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			m1[i][j]=temp[i][j];
}

int main() {
	cin>>N>>B;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			cin>>A[i][j];
	
	for(int i=0; i<N; i++)
		ans[i][i]=1;
	
	while(B>0) {
		if(B%2==1)
			product(ans, A);
		
		product(A, A);
		B/=2;
	}
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++)
			cout<<ans[i][j]<<" ";
		
		cout<<"\n";
	}
}