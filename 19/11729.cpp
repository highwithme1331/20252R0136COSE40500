#include <iostream>
#include <cmath>
using namespace std;

int N;

void hanoi(int col1, int col2, int col3, int N) {
	if(N==1)
		cout<<col1<<" "<<col3<<"\n";
	
	else {
		hanoi(col1, col3, col2, N-1);
		cout<<col1<<" "<<col3<<"\n";
		hanoi(col2, col1, col3, N-1);
	}
}

int main() {
	cin>>N;

	cout<<pow(2, N)-1<<"\n";
	
	hanoi(1, 2, 3, N);
}