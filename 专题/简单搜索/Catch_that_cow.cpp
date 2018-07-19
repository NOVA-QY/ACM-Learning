/*
    Name: Catch that Cow
    Copyright: 
    Author: Homosapiens 
    Date: 19/07/18 21:07
    Description: 将结构体改为两个数组 
*/
#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int maxn = 100001;
int time[maxn];
int vis[maxn];
int n,k;
queue<int> Q;
int bfs(int n,int k){
    int start,next;
    Q.push(n);
    time[n]=0;
    vis[n]=1;
    while(!Q.empty()){
        start=Q.front();
        Q.pop();
        for(int i=0;i<3;i++){
            //移动
            if(i==0)
                next=start-1;
            else if(i==1)
                next=start+1;
            else
                next=start*2;
            //出界情况 
            if(next<0||next>=maxn)continue;
            if(!vis[next]){
                Q.push(next);
                time[next]=time[start]+1;
                vis[next]=1;    
            }
            //到达终点 
            if(next==k)
                return time[next];
        }   
    }
}
int main(){
//  freopen("input_catch_that_cow.txt","r",stdin);
    while(cin>>n>>k){
        memset(vis,0,sizeof(vis));
        //初始化清空 
        while(!Q.empty())
            Q.pop();
        if(n>=k)
            printf("%d\n",n-k);
        else
            printf("%d\n",bfs(n,k));
    }   
    return 0;
} 