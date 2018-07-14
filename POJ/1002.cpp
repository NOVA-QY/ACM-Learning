/*
	Name: POJ 1002 487-3279(格式转换)
	Copyright: 
	Author: Homosapiens
	Date: 14/07/18 09:06
	Description: 无复杂算法思想，但容易超时，对输出有一定要求
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <map>

using namespace std;

int num[]={
	2,2,2,
	3,3,3,
	4,4,4,
	5,5,5,
	6,6,6,
	7,0,7,7,
	8,8,8,
	9,9,9
};

map<int,int> s;
char buf[128];

int main(){
	
//	freopen("1002_input.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	bool flag=false;
	for(int i=0;i<t;i++){
		scanf("%s",&buf);
		int c=0;
		for(int j=0;buf[j];j++){
			if(isdigit(buf[j]))
				c=c*10+buf[j]-'0';
			else if(isalpha(buf[j]))
				c=c*10+num[buf[j]-'A'];	
		}
		s[c]++;
	}
	for(map<int,int>::iterator it=s.begin();it!=s.end();it++){
		if(it->second>1){
			flag=true;
			printf("%03d-%04d %d\n",it->first/10000,it->first%10000,it->second);
		}
	}
	
	if(!flag)
		puts("No duplicates.");
	
	
	return 0;
}

