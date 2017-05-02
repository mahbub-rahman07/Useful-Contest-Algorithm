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
ll fact(int n)
{
	if(n <= 1) return 1;
	return n * fact(n-1);
}
int main() 
{
	int n;
	cin >>n;
	
	ll sum = n * (n+1)/2;
	ll res = fact(n)/n;
	sum *= res ;
	int k = 1;
	ll ans = 0;
	for(int i = 1 ; i <= n ; i++){
		ans += (k * sum );
		k *= 10;
	}
	
	cout << ans << endl;
	
	
	return 0;
}