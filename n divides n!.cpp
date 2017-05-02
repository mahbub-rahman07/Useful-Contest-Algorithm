#include <bits/stdc++.h>
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
#define skip scanf("%*c");
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
#define PrimefactorsT(x1,y1, x2, y2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)))
#define PrimefactorsT3D(x1,x2, y1, y2, z1, z2) (((x1-x2)*(x1-x2))+((y1-y2)*(y1-y2)) + ((z1-z2)*(z1-z2)))
//----------------functions-----------------------
ll multiplyfast(ll a, ll b, ll c){ if(b==0) return 0;ll x = multiplyfast(a , b/2, c)%c; if(!(b&1)){ return (x%c+x%c)%c;}else return ((a%c + (x+x)%c))%c; }
ll powmod(ll a,ll b,ll mod) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=multiplyfast(res,a,mod)%mod;a=multiplyfast(res,a,mod)%mod;}return res;}
ll modInverse(ll a, ll m){return powmod(a,m-2,m);}
inline ll gcd(ll a, ll b) {ll r; while (b) {r = a % b; a = b; b = r;} return a;}
inline ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
//----------------constants-----------------------
const int MOD = (int) 1e9 + 7;
const ld PI = acos((ld) -1);
const ld EPS = 1e-9;
const int INF = (int) 1e9;
const ll LINF = (ll) 1e18;


int main() 
{
	ll n,m;
		
	//WRITE("test.txt");
	while(cin >> m >> n){

			//int sz = primes.size();
		bool flag = 1;
		int divident = m;
		int divisor = n;
		if( n == 0 ){
			flag = 1;
		}else if( m == 0 && n > 1){
			flag = 0;
		}else if(m == 0 && n == 1){
			flag = 1;
		}
		else{
		map<int,int>Primefactors;
		while (n%2 == 0) {
			Primefactors[2]++;
			//cout <<"2 ";
			n /= 2;
		}
		for(int i = 3 ; i <= sqrt(divisor)+1 ; i+=2){
			if(n % i == 0){
				while (n%i == 0) {
					Primefactors[i]++;
					//cout <<i<<" ";
					n /= i;
				}
			}
		}
		if(n > 1){
			Primefactors[n]++;
		}
		map<int ,int>::iterator it;
		
		for(it = Primefactors.begin();it != Primefactors.end(); ++it){
			int p = it->second;
			int d = it->first;
		//	cout << d <<" power is "<<p<<endl;
			ll divi = m;
			int cont = 0;
			while(divi > 0 && cont < p){
				divi /= d;
				cont += divi;
			}
			if(cont < p){
				flag = 0; // if there is not enough factor so its not possible to divide by 
				break;
			}
		}
		
		}
		if(flag){
			cout <<divisor <<" divides " << divident <<"!"<<endl;
		}else{
			cout << divisor <<" does not divide " <<divident  <<"!"<<endl;
		}
	}
	return 0;
}