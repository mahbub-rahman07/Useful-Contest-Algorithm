#include <iostream>

using namespace std;
bool t[100][100];
int arr[] = {2,3,7,8,10};
bool subsetsum(int arr[],int n,int totall)
{
	
	
	for(int i=0;i<=n;i++){
		t[i][0] = true;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=totall;j++){
			if(j-arr[i-1] >= 0){
				t[i][j] = t[i-1][j] || t[i-1][j-arr[i-1]];
				//cout<<t[i][j]<<endl;
			}else{
				t[i][j] = t[i-1][j];
			//cout<<j<<endl;
			}
		}
	}
	return t[n][totall];
	
}
bool isSubsetSum(ll set[], ll n, ll sum)
{
	// Base Cases
	if (sum == 0)
	  return true;
	if (n == 0 && sum != 0)
	  return false;

	if (set[n-1] > sum)
	  return isSubsetSum(set, n-1, sum);
 
	
	return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
}

int main(int argc, char *argv[]) {
	
	cout<<subsetsum(arr, 4, 11)<<endl;

}