#include <iostream>
#include <cmath>
using namespace std;

int N;
int board[15];
int ans=0;

bool check(int cur) {
	for(int i=0; i<cur; i++)
		if(board[cur]==board[i] || abs(board[cur]-board[i])==cur-i)
			return false;
	
	return true;
}

void nqueen(int cur) {
	if(cur==N)
		ans++;
	
	else
		for(int i=0; i<N; i++) {
			board[cur]=i;
			
			if(check(cur))
				nqueen(cur+1);
		}
}

int main() {
	cin>>N;
	
	nqueen(0);
	
	cout<<ans;
}