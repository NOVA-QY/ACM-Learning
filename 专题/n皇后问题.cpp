#include<iostream>
using namespace std;

int n,sum;
int ans[12],sel[12];

int Abs(int n){
	return n>0?n:-n;
} 

void f(int h){		//确定第i行皇后的位置 
	if(h>n){		//成功，计数+1 
		++sum;
		return;
	}
	int i,x,y;		
	x=h;			//确定纵坐标
	for(y=1;y<=n;y++){
		//检测竖直方向
		for(i=1;i<x;i++)
			if(y==sel[i])
				break;
		if(i<x)
			continue;
		//检测斜着方向
		for(i=1;i<x;i++)
			if(Abs(sel[i]-y)==x-i)
				break;
			if(i<x)
				continue;
			sel[x]=y;
			f(h+1);		
	} 	
}

int main(){
//	freopen("input_2553_hdu.txt","r",stdin); 
	for(n=1;n<=10;n++){
		sum=0;
		f(1);
		ans[n]=sum;
	}
	while(cin>>n){
		if(n==0)break;
		cout<<ans[n]<<endl;
	}
	return 0;
}
