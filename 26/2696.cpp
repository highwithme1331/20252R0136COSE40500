#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T, M;

int main() {
	cin>>T;
	
	while(T--) {
		priority_queue<int> maxheap;
		priority_queue<int, vector<int>, greater<int>> minheap;
		vector<int> ans;
	
		cin>>M;
		
		int mid;
		cin>>mid;
		
		ans.push_back(mid);
		
		for(int i=2; i<=M; i++) {
			int input;
			cin>>input;
			
			if(input>mid)
				minheap.push(input);
			
			else
				maxheap.push(input);
			
			if(i%2==1) {
				if(minheap.size()<maxheap.size()) {
					minheap.push(mid);
					mid=maxheap.top();
					maxheap.pop();
					ans.push_back(mid);
				}
				
				else if(minheap.size()>maxheap.size()) {
					maxheap.push(mid);
					mid=minheap.top();
					minheap.pop();
					ans.push_back(mid);
				}
				
				else
					ans.push_back(mid);
			}
		}
		
		cout<<ans.size()<<"\n";
		
		for(int i=0; i<ans.size(); i++) {
			if(i!=0 && i%10==0)
				cout<<"\n";
			
			cout<<ans[i]<<" ";
		}
		
		cout<<"\n";
	}
}