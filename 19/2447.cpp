#include <iostream>
using namespace std;

int N;

void printstar(int i, int j, int N) {
	if(N==1)
		cout<<"*";
	
	else {
		if((i/(N/3))%3==1 && (j/(N/3))%3==1) 
			cout<<" ";
	
		else
			printstar(i, j, N/3);
	}
}

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) 
			printstar(i, j, N);

		cout<<"\n";
	}
}