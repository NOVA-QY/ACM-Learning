#include<cstdio>
#include<iostream>
using namespace std;
int vis[10];            //记录本列是否放置 
char maze[10][10];
int sum,m,n,k;;             //sum-方案数、m-已放入棋子个数 
void dfs(int row){      //按行进行访问 
    if(k==m){           //棋子已经放完 
        sum++;
        return;
    }
    if(row>=n)          //边界 
        return;
    //对当前行的每一列进行判断 
    for(int i=0;i<n;i++){
        if(maze[row][i]=='#'&&!vis[i]){
            vis[i]=1;
            m++;
            //基于已放置情况下进行下一行的判断 
            dfs(row+1);
            //改回来方便下次判断
            m--;
            vis[i]=0; 
        }
    }
    //判断下一行 
    dfs(row+1);
}
int main(){
//  freopen("input_A_棋盘问题.txt","r",stdin);
    while(scanf("%d%d",&n,&k)){
        if(n==-1&&k==-1)break;
        for(int i=0;i<n;i++)
            scanf("%s",maze[i]);
        sum=0;
        dfs(0);
        printf("%d\n",sum);
    }
    return 0;
} 