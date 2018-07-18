#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;

int Map[6][6],vis[6][6],pre[110];
//pre[]记录每个状态的前一个状态
struct Cam{
	int x,y;	
}List[110];

int Dire[4][2]={-1,0,1,0,0,-1,0,1};

//判断是否可走 
int Go(int x,int y){
	if(x>=0&&x<5&&y>=0&&y<5&&Map[x][y]==0)
		return 1;
	return 0;
}

//输出路径 
void Print(int x){
	int t;
	t=pre[x];
	if(t==0){
		printf("(0, 0)\n");
		printf("(%d, %d)\n",List[x].x,List[x].y);
		return;
	}
	else
		Print(t);
	printf("(%d, %d)\n",List[x].x,List[x].y);
}

void BFS(){
	memset(vis,0,sizeof(vis));
	int Head=0,Tail=1;
	List[0].x=0;
	List[0].y=0;
	pre[0]=-1;
	while(Head<Tail){
		int x=List[Head].x;
		int y=List[Head].y;
		if(x==4&&y==4){
			Print(Head);
			return;
		}
		for(int i=0;i<4;i++){
			int xx=x+Dire[i][0];
			int yy=y+Dire[i][1];
			if(!vis[xx][yy]&&Go(xx,yy)){
				vis[xx][yy]=1;
				List[Tail].x=xx;
				List[Tail].y=yy;
				pre[Tail]=Head;
				Tail++;
			}
		}
		Head++;
	}
	return;
}

int main(){
//	freopen("input_迷宫问题.txt","r",stdin);
	for(int i=0;i<5;i++)
		for(int j=0;j<5;j++)
			scanf("%d",&Map[i][j]);
	BFS();
	return 0;
}
