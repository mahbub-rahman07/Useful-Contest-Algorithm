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

int main() 
{
	int n;
	cin >> n;
	
	vector<int> v;
	for(int i = 0; i< n ; i++){
		v.push_back(i+1);
	}
	
	ll ans = 0;
	int l = 1;
	int k = 0;
	do {
		ll res = 0;
		l = 1;
		for(int i = 0; i< n; i++){
			res += (v[i]*l);
			l *= 10;
			
		}
		//cout << res << endl;
		ans += res;
		//k++;
	}while (next_permutation(v.begin(), v.end()));
	
	//cout << k << endl;
	cout << ans << endl;
	
	return 0;
}