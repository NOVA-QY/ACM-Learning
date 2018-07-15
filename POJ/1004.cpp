#include<iostream>
#include<cstdio> 
using namespace std;
int main(){
//	freopen("input_1004.txt","r",stdin);
	double sum=0;
	for(int i=0;i<12;i++){
		double m;
		scanf("%lf",&m);
		sum+=m;
		
	} 
	printf("$%.2lf\n",sum/12.0);
	return 0;
}
