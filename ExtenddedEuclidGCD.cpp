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

int d, x, y;
void extendedEuclid(int A, int B) {
	if(B == 0) {
		d = A;
		x = 1;
		y = 0;
	}
	else {
		extendedEuclid(B, A%B);
		int temp = x;
		x = y;
		y = temp - (A/B)*y;
	}
}

int main( ) {
	extendedEuclid(16, 10);
	cout << "The GCD of 16 and 10 is "<< d << endl;
	cout << "Coefficient x and y are: "<< x <<  " and  " << y << endl;
	return 0;   
}