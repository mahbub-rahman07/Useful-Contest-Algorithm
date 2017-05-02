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



//binary_search(): Return true if the item in equal to any element in the range passed as parameter.
//lower_bound(): Returns an iterator to the first element which is greater than or equal to the item.
//upper_bound(): Returns an iterator to the first element which is greater than the item.
//equal_range(): Returns a pair of iterators whose first element is equal to the lower_bound() and second element is equal to the upper_bound().

int main() 
{
	
		int A[] = {5, 2, 6, 2, 2, 1, 1, 6, 3, 2};        
		vector <int> v(A, A + 10);            // v =  5, 2, 6, 2, 2, 1, 1, 6, 3, 2
		sort (v.begin(), v.end());                // v =  1, 1, 2, 2, 2, 2, 3, 5, 6, 6    
		vector <int>::iterator it;
		if(binary_search(v.begin(), v.end(), 2))
			cout << "2 is in the array" << endl;
		else
			cout << "2 is not in the array" << endl;
		it = lower_bound(v.begin(), v.end(), 2);
		cout << "lower_bound: " << (it - v.begin()) << endl;
		it = upper_bound(v.begin(), v.end(), 2);
		cout << "upper_bound: " << (it - v.begin()) << endl;
		pair < vector <int>::iterator, vector <int>::iterator > p;
		p = equal_range(v.begin(), v.end(), 2);
		cout << "equal_range First: " << (p.first - v.begin()) << endl;
		cout << "equal_range Second: " <<  (p.second - v.begin()) << endl;
		return 0;
	
}