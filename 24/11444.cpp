#include <iostream>
using namespace std;
#define mod 1000000007

long long n;
long long F[2][2];
long long ans[2][2];

void product(long long m1[2][2], long long m2[2][2]) {
	long long temp[2][2];
	
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++) {
			temp[i][j]=0;
			
			for(int k=0; k<2; k++)
				temp[i][j]+=m1[i][k]*m2[k][j];
			
			temp[i][j]%=mod;
		}
	
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			m1[i][j]=temp[i][j];
}
			
int main() {
	cin>>n;
	
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++) {
			F[i][j]=1;
			
			if(i==1 && j==1)
				F[i][j]=0;
		}
	
	for(int i=0; i<2; i++)
		ans[i][i]=1;
	
	while(n>0) {
		if(n%2==1)
			product(ans, F);
		
		product(F, F);
		n/=2;
	}

	cout<<ans[1][0];
}