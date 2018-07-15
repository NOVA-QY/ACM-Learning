#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	double c;	
	while(scanf("%lf",&c)!=EOF){
		if(c==0.00)break;
		double sum=0.0;
		double t=2.0;
		while(sum<=c){
			sum+=(1/t);
			t+=1.0;
		}
		printf("%d card(s)\n",(int)(t-2));
	}
	return 0;
}
