#include <iostream>
#include <vector>
using namespace std;

int board[9][9];
vector<pair<int, int>> points;
bool success=false;

bool check(pair<int, int> point) {
	for(int i=0; i<9; i++) {
		if(board[point.second][point.first]==board[i][point.first] && point.second!=i)
			return false;
		
		if(board[point.second][point.first]==board[point.second][i] && point.first!=i)
			return false;
	}
	
	for(int i=3*(point.second/3); i<3*(point.second/3)+3; i++)
		for(int j=3*(point.first/3); j<3*(point.first/3)+3; j++)
			if(board[point.second][point.first]==board[i][j] && point.first!=j && point.second!=i)
				return false;
			
	return true;
}

void sudoku(int cur) {
	if(cur==points.size()) {
		for(int i=0; i<9; i++) {
			for(int j=0; j<9; j++)
				cout<<board[i][j]<<" ";
				
			cout<<"\n";
		}
		
		success=true;
	}
	
	else {
		if(success)
			return;
		
		for(int i=1; i<=9; i++) {
			board[points[cur].second][points[cur].first]=i;
			
			if(check(points[cur]))
				sudoku(cur+1);
			
			board[points[cur].second][points[cur].first]=0;
		}
	}
}

int main() {
	for(int i=0; i<9; i++) {
		for(int j=0; j<9; j++) {
			cin>>board[i][j];
			
			if(board[i][j]==0)
				points.push_back(make_pair(j, i));
		}
	}
	
	sudoku(0);
}