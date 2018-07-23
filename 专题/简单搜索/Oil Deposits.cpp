#include<cstdio>
#include<iostream>
using namespace std;
char land[100][100];
int num;
int dir[8][2]={1,0,-1,0,0,1,0,-1,1,-1,1,1,-1,-1,-1,1};
int m,n;
void dfs(int x,int y){
    int nx,ny;
    land[x][y]='*';
    for(int i=0;i<8;i++){
        nx=x+dir[i][0];
        ny=y+dir[i][1];
        if(nx>=0&&nx<m&&ny>=0&&ny<n&&land[nx][ny]=='@')
            dfs(nx,ny);
    }
}
int main(){
//  freopen("input_1241.txt","r",stdin);
    while(scanf("%d%d",&m,&n)){
        num=0;
        if(n==0&&m==0)break;
        for(int i=0;i<m;i++){
            scanf("%s",land[i]);
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]=='@'){
                    num++;
                    dfs(i,j);
                }   
            }
        }   
        printf("%d\n",num);
    } 
    return 0;
}