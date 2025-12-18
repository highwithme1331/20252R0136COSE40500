#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int K, V, E, u, v;
vector<int> graph[20001];
int part[20001];

void dfs(int start) {
    if(part[start]==0)
        part[start]=1;
	
	for(int i=0; i<graph[start].size(); i++) {
		int next=graph[start][i];
		
		if(part[next]==0) {
			if(part[start]==1)
				part[next]=2;
			
			else
				part[next]=1;
			
			dfs(next);
		}
	}
}

bool check() {
	for(int i=1; i<=V; i++)
		for(int j=0; j<graph[i].size(); j++) {
			int next=graph[i][j];
			
			if(part[i]==part[next])
				return false;
		}
	
	return true;
}

int main() {
	cin>>K;
	
	while(K--) {
		for(int i=0; i<=V; i++)
			graph[i].clear();
		
		memset(part, false, sizeof(part));
		
		cin>>V>>E;
		
		for(int i=0; i<E; i++) {
			cin>>u>>v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		
		for(int i=1; i<=V; i++)
			if(part[i]==0)
				dfs(i);
			
		if(check())
			cout<<"YES"<<"\n";
		
		else
			cout<<"NO"<<"\n";
	}
}