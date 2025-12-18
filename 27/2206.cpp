#include <iostream>
#include <queue>
using namespace std;

typedef struct {
	int x;
	int y;
	int wall;
} point;

int N, M;
char map[1001][1001];
int dist[1001][1001][2];
queue<point> que;
int dx[4]={1, -1, 0, 0};
int dy[4]={0, 0, 1, -1};

void bfs() {
	while(!que.empty()) {
		int x=que.front().x;
		int y=que.front().y;
		int w=que.front().wall;
		que.pop();
		
		for(int i=0; i<4; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			
			if(nx>=0 && nx<M && ny>=0 && ny<N) {
				if(map[ny][nx]=='1' && w==0) {
					dist[ny][nx][w+1]=dist[y][x][w]+1;
					que.push({nx, ny, w+1});
				}
				
				else if(map[ny][nx]=='0' && dist[ny][nx][w]==0) {
					dist[ny][nx][w]=dist[y][x][w]+1;
					que.push({nx, ny, w});
				}
			}
		}
	}
}
	
int main() {
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		string input;
		cin>>input;
		
		for(int j=0; j<M; j++)
			map[i][j]=input[j];
	}
	
	dist[0][0][0]=1;
	point start={0, 0, 0};
	que.push(start);
	
	bfs();
	
	if(dist[N-1][M-1][0]==0 && dist[N-1][M-1][1]==0)
		cout<<-1;
	
	else if(dist[N-1][M-1][0]==0)
		cout<<dist[N-1][M-1][1];
	
	else if(dist[N-1][M-1][1]==0)
		cout<<dist[N-1][M-1][0];
	
	else
		cout<<min(dist[N-1][M-1][0], dist[N-1][M-1][1]);
}