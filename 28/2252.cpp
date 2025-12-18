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
	
	queue<int> que;
	
	for(int i=1; i<=N; i++)
		if(indegree[i]==0)
			que.push(i);
	
	while(!que.empty()) {
		int cur=que.front();
		que.pop();
		cout<<cur<<" ";
	
		for(int i=0; i<graph[cur].size(); i++) {
			int next=graph[cur][i];
			indegree[next]--;
		
			if(indegree[next]==0)
				que.push(next);
		}
	}
}