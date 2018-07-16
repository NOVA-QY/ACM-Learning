/*
	Name: hdu 2553 N皇后问题 
	Copyright: 
	Author: 
	Date: 16/07/18 10:10
	Description: 回溯版本 
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int vis[3][50],P[15]; //记录三个方向， ↖↑↗在此三个方向都不能有皇后  
int n,sum;

void dfs(int row){
	int i;
	if(row==n+1){				//已经够n行了 
		sum++;
		return;
	}
	for(i=1;i<=n;i++){
		if(vis[0][row-i+n]==0&&vis[1][i]==0&&vis[2][row+i]==0){
			//回溯法
			vis[0][row-i+n]=vis[1][i]=vis[2][row+i]=1;//变值
			dfs(row+1);//深搜
			vis[0][row-i+n]=vis[1][i]=vis[2][row+i]=0;//回溯 
		}
	}
}

int main(){
//	freopen("input_hdu_2553.txt","r",stdin);
	for(n=1;n<=10;n++){			//打表避免超时 
		memset(vis,0,sizeof(vis));
		sum=0;
		dfs(1);
		P[n]=sum;
	}
	while(scanf("%d",&n),n){
		printf("%d\n",P[n]);
	}
	return 0;
}



