#include<iostream>
#include<cstdio>
#define MAXN 100
using namespace std;

int N,M;
char field[MAXN][MAXN+1];

void dfs(int x,int y){
	field[x][y]='.';
	for(int dx=-1;dx<=1;dx++){
		for(int dy=-1;dy<=1;dy++){
			int nx=x+dx;
			int ny=y+dy; 
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&field[nx][ny]=='W')
				dfs(nx,ny);
		}
	}
	return;
}

int main(){
	int res=0;
//	freopen("test1.txt","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%s",&field[i]);
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			if(field[i][j]=='W'){
				dfs(i,j);
				res++;
			}
	printf("%d\n",res);
	return 0;
}
