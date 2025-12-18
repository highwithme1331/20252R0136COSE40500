#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int N, K, M, V, C;
vector<pair<int, int>> jewel;
vector<int> bag;
priority_queue<int> avail_value;
long long ans=0;

int main() {
	cin>>N>>K;
	
	for(int i=0; i<N; i++) {
		cin>>M>>V;
		jewel.push_back(make_pair(M, V));
	}
	
	for(int i=0; i<K; i++) {
		cin>>C;
		bag.push_back(C);
	}
	
	sort(jewel.begin(), jewel.end());
	sort(bag.begin(), bag.end());
	
	int idx=0;
	
	for(int i=0; i<K; i++) {
		for(int j=idx; j<N; j++) {
			if(jewel[j].first<=bag[i]) {
				avail_value.push(jewel[j].second);
				idx++;
			}
			
			else
				break;
		}
		
		if(!avail_value.empty()) {
			ans+=avail_value.top();
			avail_value.pop();
		}
	}
					
	cout<<ans;
}