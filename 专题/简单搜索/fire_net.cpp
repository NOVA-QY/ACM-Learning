#include<cstdio>
#include<iostream>
using namespace std;

char map[5][5];
int n,iBest;

//合法性判断 
bool CanPut(int row,int col){
	int i;
	//判断col上合法性
	for(int i=row-1;i>=0;i--){
		if(map[i][col]=='O')return false;
		if(map[i][col]=='X')break;
	} 
	//判断row上合法性
	for(int i=col-1;i>=0;i--){
		if(map[row][i]=='O')return false;
		if(map[row][i]=='X')break;
	} 
	return true;
}

void solve(int k,int current){      //k代表当前单元格的序号,current代表当前放置的碉堡数
	int x,y;
	if(k==n*n){					//整个地图判断完毕
		if(current>iBest)
			iBest=current;
		return;
	}
	else{
	    //将单元格数转化为xy坐标
		x=k/n;
		y=k%n;
		//若单元格可以放置碉堡
		if(map[x][y]=='.'&&CanPut(x,y)){
			map[x][y]='O';
			solve(k+1,current+1);
			//恢复单元格，以便进行下次判断
			map[x][y]='.';
		}
		solve(k+1,current);         //本单元格不放置碉堡
	}
} 

int main(){
	//freopen("input_fire_net.txt","r",stdin);
	while(cin>>n){
		if(n==0)break;
		for(int i=0;i<n;i++)
			scanf("%s",map[i]);
		solve(0,0);
		printf("%d\n",iBest);
		iBest=0;
	}
	return 0;
}