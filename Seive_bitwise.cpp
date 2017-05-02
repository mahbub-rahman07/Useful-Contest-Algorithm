#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;
const int N = 100000000;
long long status[(N/32) + 2];
bool Check(long long N,int pos)
{
	return (bool) (N & (1<<pos));
}
int Set(int N,int pos)
{
	return N=N | (1<<pos);
}

vector <long long >primes;
void Sieve()
{
	int sq = sqrt(N);
	primes.push_back(2);
	for(int i=3; i<= sq ; i+= 2){
		if(Check(status[i>>5], i&31 ) == 0){
			for(int j=i*i ;j<= N;j += 2*i){
				status[j>>5] = Set(status[j>>5] , j&31);
			}
			primes.push_back(i);
		}
	}
//	puts("2");
//	 for(int i=3;i<=N;i+=2)
//		 if( Check(status[i>>5],i&31)==0)
//	       printf("%d\n",i);
}
void print_primes(int n)
{
	for(int i=1;i<=n;i++){
		cout<<"Prime"<<"["<<i<<"] = "<<primes[i]<<endl;
	}
}


int main() {
	
	time_t t1= clock();
	Sieve();
	time_t t2= clock();
	cout<<primes.size()<<endl;
	cout<<"time taken "<<(t2-t1)/double(CLOCKS_PER_SEC)<<endl;
	
	//print_primes(primes.size());
	
	
	return 0;
}