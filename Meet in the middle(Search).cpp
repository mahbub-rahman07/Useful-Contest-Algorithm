#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <math.h>
#include <queue>
#include <deque>
#include <assert.h>
#include <stack>
#include <list>
#include <set>
#include <map>

using namespace std;

/*******************************************************************\
|                       Md.Mahbubur Rahman                          |
|   	BANGLADESH UNIVERSITY OF BUSINESS & TECHNOLOGY(BUBT)	    |
|		 	    Deptartment of  CSE							        |
|    uva:mahbub07||devskil: mahbub07||codefoces:MAHBUBUR_RAHMAN     |
|                mail:mahbubabid8@gmail.com				            |
\*******************************************************************/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef  vector<int> vi;
typedef  vector<ll> vll;
typedef  vector<string> vs;
typedef  set<int> si;
typedef  set<string> ss;
typedef  map<int,int> mii;
typedef  map<ll,ll> mll;
typedef  map<string,int> msi;
typedef  map<char,int> mci;
//----------------defines-----------------------
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define all(v) v.begin(),v.end()
#define ms(s, n) memset(s, n, sizeof(s))
#define bit(n, i) (((n) >> (i)) & 1)
#define bitcount(n) __builtin_popcountll(n)
#define For0(i,n) for(int i=0;i<(int)n;i++)
#define For1(i,n) for(int i=1;i<=(int)n;i++)
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
#define Case(no) printf("Case %d: ",++no)
#define pb(b) push_back(b)
#define mp make_pair
#define maxall(v) *max_element(all(v))
#define minall(v) *min_element(all(v))
#define sortArr(a,n) sort(a,a+n)
#define sortVec(a) sort(all(a))
#define endl '\n'
#define DIST(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define DIST3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
//----------------functions-----------------------
ll muliplyfast(ll a, ll b, ll c){ if(b==0) return 0;ll x = muliplyfast(a , b/2, c)%c; if(!(b&1)){ return (x%c+x%c)%c;}else return ((a%c + (x+x)%c))%c; }
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=muliplyfast(res,a,mod)%mod;a=muliplyfast(res,a,mod)%mod;}return res;}
ll modInverse(ll a, ll m){return powmod(a,m-2,m);}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
//----------------constants-----------------------
const int MOD = (int) 1e9 + 7;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;

ll sumL[2000009]; // size atmost 2^n
ll sumR[2000009];

void calcsubarray(ll a[], ll x[], int n, int c)
{
	for (int i=0; i<(1<<n); i++)
	{
		ll s = 0;
		for (int j=0; j<n; j++)
			if (i & (1<<j))
				s += a[j+c];
		x[i] = s;
		//cout << x[i]<<endl;
	}
}
ll MeetIntheMiddle(ll arr[],ll n,ll S)
{
	// sum of left array
	calcsubarray(arr, sumL, n/2, 0);	
	// sum of right array
	calcsubarray(arr, sumR,n-n/2 ,n/2);
	
	int L = 1 << (n/2);
	int R = 1 << (n-(n/2));	
		
		
	// sort only right array
	sortArr(sumR, R);
	// binery search for sum of S
	ll max = 0;
	 
		
	for (int i=0; i<L; i++)
	{
		if (sumL[i] <= S)
		{
			// lower_bound() returns the first address
			// which has value greater than or equal to
			// S-X[i].
			int p = lower_bound(sumR, sumR+R, S-sumL[i]) - sumR; // if exist then give p <= S-sumL[i] otherwise size of R
			if (p == R || sumR[p] != (S-sumL[i]))
				p--; // if does not exist then reduce by 1
	 
			if ((sumR[p]+sumL[i]) > max)
				max = sumR[p]+sumL[i];
		}
	}
		return max;
}

int main() 
{
	ll a[] = {3, 34, 4, 12, 5, 2};
	int n=sizeof(a)/sizeof(a[0]);
		ll S = 10;
		printf("Largest value smaller than or equal to given "
			   "sum is %lld\n", MeetIntheMiddle(a,n,S));
		return 0;
}