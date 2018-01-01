#include<iostream>
#include<cstdio>
using namespace std;

int a[20];
int n,k;

//已经从前i项得到了和sum，然后对于i项之后进行分支 
bool dfs(int i,int sum){
	//如果前n项都计算过了，则返回sum是否与k相等 
	if(i==n)return sum==k;
	
	//不加上a[i] 
	if(dfs(i+1,sum))return true;
	
	//加上a[i] 
	if(dfs(i+1,sum+a[i]))return true;
	
	//无论是否加上，都不能凑成k 
	return false;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	scanf("%d",&k);
	if(dfs(0,0))printf("Yes\n");
	else printf("No\n");

	return 0;
}

/*
	输入n个数，存储在数组a中，看这n个数能否凑成k
	Input:
	4
	1 2 4 7
	15
	Output:
	No 

*/
