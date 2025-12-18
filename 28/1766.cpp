#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int N, M, A, B;
vector<int> graph[32001];
int indegree[32001];

int main() {
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		cin>>A>>B;
		graph[A].push_back(B);
		indegree[B]++;
	}
	
	priority_queue<int, vector<int>, greater<int>> pque;
	
	for(int i=1; i<=N; i++)
		if(indegree[i]==0)
			pque.push(i);
		
	while(!pque.empty()) {
		int cur=pque.top();
		pque.pop();
		cout<<cur<<" ";
		
		for(int i=0; i<graph[cur].size(); i++) {
			int next=graph[cur][i];
			indegree[next]--;
			
			if(indegree[next]==0)
				pque.push(next);
		}
	}
}