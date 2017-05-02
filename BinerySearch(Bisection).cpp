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
double Mysqrt(double n)
{
	double low ,high,mid;
	low = 0.0;
	high = n;
	
	while(high-low >0.000001){
		mid = (low+high)/2.0;
		cout << low <<" "<<mid << " "<< mid*mid <<endl;
		if(mid*mid > n){
			high = mid;
		}else{
			low = mid;
		}
	}
	return mid;
}
int main() 
{
	cout << Mysqrt(15)<<endl;
	return 0;
}