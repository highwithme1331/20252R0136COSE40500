#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int T, n, m, t, a, b;
int graph[501][501];
int indegree[501];

int main() {
	cin>>T;
	
	while(T--) {
		memset(graph, 0, sizeof(graph));
		memset(indegree, 0, sizeof(indegree));
			
		cin>>n;
		
		vector<int> rank;

		for(int i=0; i<n; i++) {
			cin>>t;
			rank.push_back(t);
		}
		
		for(int i=0; i<rank.size()-1; i++)
			for(int j=i+1; j<rank.size(); j++) {
				graph[rank[i]][rank[j]]=1;
				indegree[rank[j]]++;
			}
		
		cin>>m;
		
		for(int i=0; i<m; i++) {
			cin>>a>>b;
			
			if(graph[a][b]) {
				graph[a][b]=0;
				indegree[b]--;
				graph[b][a]=1;
				indegree[a]++;
			}
			
			else if(graph[b][a]) {
				graph[b][a]=0;
				indegree[a]--;
				graph[a][b]=1;
				indegree[b]++;
			}
		}
		
		queue<int> que;
		
		for(int i=1; i<=n; i++)
			if(!indegree[i])
				que.push(i);
		
		bool dont_know=false;
		vector<int> ans;
		
		while(!que.empty()) {
			if(que.size()>=2) {
				dont_know=true;
				break;
			}
			
			int cur=que.front();
			que.pop();
			ans.push_back(cur);
			
			for(int i=1; i<=n; i++) {
				if(graph[cur][i]) {
					indegree[i]--;
					
					if(indegree[i]==0)
						que.push(i);
				}
			}
		}
			
		if(dont_know) {
			cout<<"?"<<"\n";
			continue;
		}
			
		if(ans.size()!=n) {
			cout<<"IMPOSSIBLE"<<"\n";
			continue;
		}
		
		else {
			for(int i=0; i<ans.size(); i++)
				cout<<ans[i]<<" ";
			
			cout<<"\n";
		}
	}
}