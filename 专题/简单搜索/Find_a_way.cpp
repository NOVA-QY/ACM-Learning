#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#define inf 0xffffff
using namespace std;
const int maxn = 201;
char map[maxn][maxn];
int vis[maxn][maxn],dis[maxn][maxn][2],n,m,flag;
int dir[4][2]={0,1,0,-1,1,0,-1,0};
struct node{
    int x,y,s;
};
int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m && map[x][y]!='#' && vis[x][y]==0)
        return 1;
    return 0;
} 
void bfs(int x,int y){
    queue<node> q;
    node cur,next;
    cur.x=x;
    cur.y=y;
    cur.s=0;
    vis[x][y]=1;
    q.push(cur);
    while(!q.empty()){
        cur=q.front();
        q.pop();
        next.s=cur.s+1;
        for(int i=0;i<4;i++){       
            next.x=x=cur.x+dir[i][0];       //更新坐标 
            next.y=y=cur.y+dir[i][1];
            if(check(x,y)){     //判断下一步可行性 
                vis[x][y]=1;
                if(map[x][y]=='@')
                    dis[x][y][flag]=next.s;
                q.push(next);
            }
        }
    } 
}
int main(){
    //freopen("input_2612_find_way.txt","r",stdin);
    int min;
    while(cin>>n>>m){
        //初始化
        min=inf;
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                dis[i][j][0]=dis[i][j][1]=inf;
        //简化输入 
        for(int i=0;i<n;i++)
            scanf("%s",map[i]);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(map[i][j]=='Y'){
                    flag=0;
                    memset(vis,0,sizeof(vis));
                    bfs(i,j);
                }
                else if(map[i][j]=='M'){
                    flag=1;
                    memset(vis,0,sizeof(vis));
                    bfs(i,j);
                }
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(map[i][j]=='@'&&min>dis[i][j][0]+dis[i][j][1])
                    min=dis[i][j][0]+dis[i][j][1];
        printf("%d\n",min*11);   
    }
    return 0;
}