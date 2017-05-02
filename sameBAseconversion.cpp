#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int x,y,base1,base2;
	cin>>x>>base1;
	long long Xarray[x+2];
	
	for(int i=0;i<x;i++)cin>>Xarray[i];
	
	cin>>y>>base2;
	long long Yarray[y+2];
	
	for(int i=0;i<y;i++)cin>>Yarray[i];
	
	long long ans1 =0,ans2 =0,p1=1,p2=1;
	for(int i = x-1;i>=0;i--){
		ans1 += Xarray[i]*p1;
		p1 *= base1;
	}
	
	for(int i = y-1;i>=0;i--){
		ans2 += Yarray[i]*p2;
		p2 *= base2;
	}
	//cout<<ans1<<" "<<ans2<<endl;
	if(ans1 == ans2)
		cout<<"="<<endl;
	else if(ans1 > ans2)
		cout<<">"<<endl;
	else {
		cout<<"<"<<endl;
	}
}