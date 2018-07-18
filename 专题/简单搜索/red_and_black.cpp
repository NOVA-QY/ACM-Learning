/*
	Name: Red and Black 
	Copyright: 
	Author: Homosapiens
	Date: 18/07/18 10:05
	Description: HDU 1312 深搜 
*/

#include<cstdio>
#include<iostream>
using namespace std;
char maze[25][25];
int dir[4][2] = {-1,0,1,0,0,1,0,-1};

int w,h,sum;


void dfs(int x0,int y0){
	maze[x0][y0]='#';
	sum++;
	int x,y;
	for(int i=0;i<4;i++){
		x=x0+dir[i][0];
		y=y0+dir[i][1];
		if(x>=0&&y>=0&&x<h&&y<w&&maze[x][y]=='.')
			dfs(x,y);
	}
}

int main(){
	
//	freopen("input_1312_red_and_black.txt","r",stdin);
	
	int di,dj,i,j;

	while(scanf("%d%d",&w,&h)!=EOF){
		getchar();
		if(w==0&&h==0)break; 
		//输入并初始化 
		for(i=0;i<h;i++){
			for(j=0;j<w;j++){
				scanf("%c",&maze[i][j]);
				if(maze[i][j]=='@'){
					di=i;
					dj=j;
				}
			}	
			getchar();
		} 
		
		sum=0;
		dfs(di,dj);	
		printf("%d\n",sum);
	}
	return 0;
} 
