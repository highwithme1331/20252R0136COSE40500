#include <iostream>
#include <queue>
using namespace std;

int N, M, x, y, u, v;
int map[101];
int dist[101];

int main() {
	for(int i=1; i<=100; i++)
		map[i]=i;
	
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		cin>>x>>y;
		map[x]=y;
	}
	
	for(int i=0; i<M; i++) {
		cin>>u>>v;
		map[u]=v;
	}
	
	queue<int> que;
	
	dist[1]=0;
	que.push(1);
	
	while(!que.empty()) {
		int cur=que.front();
		que.pop();
		
		for(int i=1; i<=6; i++) {
			int next=cur+i;
			next=map[next];
			
			if(dist[next]==0) {
				dist[next]=dist[cur]+1;
				que.push(next);
			}
		}
	}
	
	cout<<dist[100];
}