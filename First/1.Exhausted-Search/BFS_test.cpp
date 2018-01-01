#include<iostream>
#include<cstdio>
#include<queue>
#define MAXN 100
const int INF=10000;
using namespace std;

typedef pair<int,int> P;

char maze[MAXN][MAXN+1];
int N,M;
int sx,sy,gx,gy;		//定义起点、终点坐标 
int d[MAXN][MAXN];	//存放到每个点的最短距离 
int dx[4]={1,0,-1,0};	//顺序？ 
int dy[4]={0,1,0,-1};

int bfs(){
	//初始化 
	queue<P> que;
	for(int i=0;i<N;i++)
		for(int j=0;j<M;j++)
			d[i][j]=INF;
	
	for(int i=0;i<N;i++){ 
		for(int j=0;j<M;j++){ 
			if(maze[i][j]=='S'){
				sx=i;
				sy=j;
			}
		}
	} 
	for(int i=0;i<N;i++){ 
		for(int j=0;j<M;j++){ 
			if(maze[i][j]=='G'){
				gx=i;
				gy=j;
			}
		}
	}  
	
	printf("%d %d %d %d\n",sx,sy,gx,gy);
	//把起点入队，并设置距离为0 
	que.push(P(sx,sy));
	d[sx][sy]=0;
	
	
	while(que.size()){
		P p=que.front();
		que.pop();
		//若是终点，直接退出 
		if(p.first==gx&&p.second==gy)break;
		
		//朝四个方向移动 
		for(int i=0;i<4;i++){
			
			int nx=p.first+dx[i];
			int ny=p.second+dy[i];
		
			//判断是否可以移动以及是否已经访问过
			if(0<=nx&&nx<N&&0<=ny&&ny<M&&maze[nx][ny]!='#'&&d[nx][ny]==INF){
				que.push(P(nx,ny));
				d[nx][ny]=d[p.first][p.second]+1;
			}
		}
	}
	return d[gx][gy];
}

int main(){
//	freopen("test2.txt","r",stdin);
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%s",&maze[i]);
//	//打印输出结果 
//	for(int i=0;i<N;i++)
//		for(int j=0;j<M;j++)
//			printf("%c",maze[i][j]);

	int res=bfs();
	printf("%d\n",res);
	return 0;
} 

/*
Input:
10 10
#S######.#
......#..#
.#.##.##.#
.#........
##.##.####
....#....#
.#######.#
....#.....
.####.###.
....#...G#

Output:
0 1 9 8
22
		*/ 
