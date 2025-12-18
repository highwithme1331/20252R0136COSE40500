#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, C, x;
vector<int> input;
int ans=0;

int main() {
	cin>>N>>C;
	
	for(int i=0; i<N; i++) {
		cin>>x;
		input.push_back(x);
	}
	
	sort(input.begin(),input.end());
	
	int left=0;
	int right=input[N-1];
	
	while(left<=right) {
		int mid=(left+right)/2;
		
		int cnt=1;
		int before=0;
		
		for(int i=1; i<N; i++)
			if(input[i]-input[before]>=mid) {
				cnt++;
				before=i;
			}
			
		if(cnt>=C && ans<mid)
			ans=mid;
		
		if(cnt>=C)
			left=mid+1;
		
		else
			right=mid-1;
	}
	
	cout<<ans;
}