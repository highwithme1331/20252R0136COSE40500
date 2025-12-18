#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> input;
int ans=1;

int main() {
	cin>>N;
	
	for(int i=0; i<N; i++) {
		int start, end;
		cin>>start>>end;
		input.push_back(make_pair(end, start));
	}
	
	sort(input.begin(), input.end());
	
	int cur_end=input[0].first;
	
	for(int i=1; i<N; i++)
		if(input[i].second>=cur_end) {
			ans++;
			cur_end=input[i].first;
		}
		
	cout<<ans;
}