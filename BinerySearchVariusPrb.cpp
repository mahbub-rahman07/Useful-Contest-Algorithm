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

int firstOccurrence(int A[], int left, int right, int item) {
	int mid;
	while (right - left > 1) {
		mid = left + (right - left) / 2;
		if (A[mid] >= item) 
			right = mid;
		else
			left = mid;
	}
	return right;
}

int lastOccurrence(int A[], int left, int right, int item) {
	int mid;
	while (right - left > 1) {
		mid = left + (right - left) / 2;
		if (A[mid] <= item)
			left = mid;
		else
			right = mid;
	}
	return left;
}

int numberOfOccurrences(int A[], int size, int item) {
	// Note the boundary parameters
	int left = firstOccurrence(A, -1, size - 1, item);
	int right = lastOccurrence(A, 0, size, item);
	if (A[left] == item && A[right] == item)            // If the item is in the array A
		return (right - left + 1);
	else                                                            // If the item is not in the array A
		return 0;
}

int main() 
{
	int A[] = {5, 2, 6, 2, 2, 1, 1, 6, 3, 2};
	int item  = 6;
	int size = 10;
	sort(A,A+10);
	
	 int left = firstOccurrence(A, -1, size - 1, item);
	 int right = lastOccurrence(A, 0, size, item);
	int occer = numberOfOccurrences(A, size, item);
	
	cout << left <<" " << right << " & Nomber of Occer : " << occer<< endl;
	
	return 0;
}