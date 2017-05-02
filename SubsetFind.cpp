#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <list>
#include <map>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define For0(i,n) for(int i=0;i<(int)n;i++)
#define For1(i,n) for(int i=1;i<=(int)n;i++)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
vector<int>v;
void gen(int k,int n)
{
	if(k == n+1 ){
		int i = 0;
		while(i < v.size()){
			cout << v[i];
			i++;
		}
		cout << endl;
		
	}else{
		gen(k+1,n);
		v.push_back(k);
		gen(k+1, n);
		v.pop_back();
	}
}

void Subset(int n){
	for(int b = 0; b < (1<<n) ; b++){
		vector<int>S;
		for(int i = 0; i < n; i++){
			if(b&(1<<i)) S.push_back(i+1);
		}
		for(int j = 0; j < S.size() ; j++){
			cout << S[j]<<" ";
		}
		cout << endl;
	}
	
}
int main() 
{
	//memset(visit, 0, sizeof(visit));
	//gen(1, 3);	
	Subset(3);
	return 0;
}