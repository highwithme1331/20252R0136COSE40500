#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
#define INF 987654321

int N, M, H;
int map[101][101][101];
queue<tuple<int, int, int>> que;
int ans=-INF;
int dx[6]={1, -1, 0, 0, 0, 0};
int dy[6]={0, 0, 1, -1, 0, 0};
int dz[6]={0, 0, 0, 0, 1, -1};

void bfs() {
	while(!que.empty()) {
		int x=get<0>(que.front());
		int y=get<1>(que.front());
		int z=get<2>(que.front());
		que.pop();
		
		for(int i=0; i<6; i++) {
			int nx=x+dx[i];
			int ny=y+dy[i];
			int nz=z+dz[i];
			
			if(nx>=0 && nx<M && ny>=0 && ny<N && nz>=0 && nz<H)
				if(map[nz][ny][nx]==0) {
					map[nz][ny][nx]=map[z][y][x]+1;
					que.push(make_tuple(nx, ny, nz));
				}
		}
	}
}

int main() {
	cin>>M>>N>>H;
	
	for(int i=0; i<H; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<M; k++) {
				cin>>map[i][j][k];
				
				if(map[i][j][k]==1)
					que.push(make_tuple(k, j, i));
			}
	
	bfs();

	for(int i=0; i<H; i++)
		for(int j=0; j<N; j++)
			for(int k=0; k<M; k++) {
				if(map[i][j][k]==0) {
					cout<<-1<<"\n";
					
					return 0;
				}
			
				if(ans<map[i][j][k])
					ans=map[i][j][k];
			}
	
	cout<<ans-1;
}