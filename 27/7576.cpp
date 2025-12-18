#include <iostream>
#include <queue>
using namespace std;
#define INF 987654321

int N, M;
int map[1001][1001];
queue<pair<int, int>> que;
int ans=-INF;
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void bfs() {
	while(!que.empty()) {
		int x=que.front().first;
		int y=que.front().second;
		que.pop();
		
		for(int i=0; i<4; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=0 && nx<M && ny>=0 && ny<N)
				if(map[ny][nx]==0) {
					map[ny][nx]=map[y][x]+1;
					que.push(make_pair(nx, ny));
				}
		}
	}
}

int main() {
	cin>>M>>N;
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++) {
			cin>>map[i][j];
			
			if(map[i][j]==1)
				que.push(make_pair(j, i));
		}
		
	bfs();
	
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++) {
			if(map[i][j]==0) {
				cout<<-1<<"\n";
				
				return 0;
			}
			
			if(ans<map[i][j])
				ans=map[i][j];
		}
	
	cout<<ans-1;
}