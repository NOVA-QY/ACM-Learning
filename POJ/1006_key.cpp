/*
	Name: POJ 1006 Biorhythms(中国剩余定理)
	Copyright: 
	Author: Homosapiens
	Date: 15/07/18 09:18
	Description: 问题简化：一个数x，除3余2，除5余3，除7余2，求x？ 
*/

#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;

int p,e,k,d,sum;
int r1,r2,r3,r;

//求解r1,r2,r3,r 
void solve(){
	int i;
	for(i=1,r1=28*33;;i++)
		if(r1*i%23==1)break;
	r1*=i;
	
	for(i=1,r2=33*23;;i++)
		if(r2*i%28==1)break;
	r2*=i;
	for(i=1,r3=23*28;;i++)
		if(r3*i%33==1)break;
	r3*=i;
	r=23*28*33;	
}

int main(){
	int t=1;
	solve();
	while(scanf("%d%d%d%d",&p,&e,&k,&d)==4){
		if(p==-1&&e==-1&&k==-1&&d==-1)break;
		sum=(r1*p+r2*e+r3*k-d)%r;
		sum=(sum+r-1)%r+1;
		printf ("Case %d: the next triple peak occurs in %d days.\n",t++, sum);
	}
	return 0;
}
