/*
    Name: Dungeon Master 
    Copyright: 
    Author: Homosapiens 
    Date: 19/07/18 08:56
    Description: POJ 2251 BFS题目，DFS会超时 
*/
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
char maze[35][35][35];
int vis[35][35][35];
int sum,l,r,c;; 
int si,sj,sk,di,dj,dk;                                                  //记录起点及终点 
int to[6][3]={{0,0,1},{0,0,-1},{0,1,0},{0,-1,0},{1,0,0},{-1,0,0}};      //定义三维方向数组 
struct node{
    int i,j,k,step;
};
//检查移动合法性 
int check(int x,int y,int z){
    if(x<0||y<0||z<0||x>=l||y>=r||z>=c)
        return 1;
    else if(maze[x][y][z]=='#')
        return 1;
    else if(vis[x][y][z])
        return 1;
    return 0;
}
int bfs(){
    int i;
    node start,next;
    queue<node> Q;
    start.i=si;
    start.j=sj;
    start.k=sk;
    start.step=0;
    vis[si][sj][sk]=1;
    Q.push(start);
    while(!Q.empty()){
        start=Q.front();
        Q.pop();
        if(start.i==di&&start.j==dj&&start.k==dk)
            return start.step;
        for(int i=0;i<6;i++){
            next=start;
            next.i=start.i+to[i][0];
            next.j=start.j+to[i][1];
            next.k=start.k+to[i][2];
            if(check(next.i,next.j,next.k))
                continue;
            vis[next.i][next.j][next.k]=1;
            next.step=start.step+1;
            Q.push(next);
        }
    }
    return 0;
}
int main(){
//  freopen("input_Dungeon_Master.txt","r",stdin);
    while(scanf("%d%d%d",&l,&r,&c)){
        if(l==0&&r==0&&c==0)break;
        //读入数组 
        getchar();
        for(int i=0;i<l;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<c;k++){
                    scanf("%c",&maze[i][j][k]);
                    if(maze[i][j][k]=='S'){
                        si=i;
                        sj=j;
                        sk=k;
                    }
                    if(maze[i][j][k]=='E'){
                        di=i;
                        dj=j;
                        dk=k;
                    }       
                } 
                getchar(); 
            } 
            getchar();
        }
        memset(vis,0,sizeof(vis));
        sum=bfs();
        if(sum){
            printf("Escaped in %d minute(s).\n",sum);
        }
        else{
            printf("Trapped!\n");
        }   
    }
    return 0;
} 