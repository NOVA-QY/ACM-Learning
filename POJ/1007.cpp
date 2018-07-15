#include<iostream>
#include<algorithm>
using namespace std;
struct Str{
	char s[51];
	int n;	//逆序数个数 
};

bool cmp(const Str &a,const Str &b){
	if(a.n<b.n)
		return 1;
	return 0;
}

int main(){
	int n,m,i,j;
	Str str[101];
	while(cin>>n>>m){
		//输入 
		for(i=1;i<=m;i++)
			cin>>str[i].s;
		for(i=1;i<=m;i++){
			int num=0;
			int A=0,C=0,G=0;
			for(j=n-1;j>=0;j--){
				switch(str[i].s[j]){
					case 'A':A++;break;
					case 'C':C++;num+=A;break;
					case 'G':G++;num+=A;num+=C;break;
					case 'T':num+=A;num+=C;num+=G;break;
					default:break;	
				}
			}
			str[i].n=num;
		}
		sort(str+1,str+m+1,cmp);
		for(i=1;i<=m;i++)
			cout<<str[i].s<<endl;
	}
	return 0;
}
