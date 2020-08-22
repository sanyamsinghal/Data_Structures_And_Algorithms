// #include<bits/stdc++.h>
// using namespace std;

// long long int count(long long int n){
//   if(n<=2){
//     return n;
//   }
//   else{
//     return (n-1)*count(n-2) + count(n-1);
//   }
// }

// int main(){
//   freopen("input.txt", "r", stdin);
//   freopen("output.txt", "w", stdout);

//   int t;  cin>>t;
//   while (t--){
//     long long int n;  cin>>n;

//     long long int ans = count(n);
//     cout<<ans<<endl;
    
//   }

//   return 0;
// }



#include<bits/stdc++.h>
using namespace std;

#define ll long long int

void primeSeive(ll p[],ll lim){
	p[0]=p[1]=0;
	p[2]=1;
	for(ll i=3;i<=lim;i+=2){
		p[i]=1;
	}

	for(ll i=3;i<=lim;i+=2){
		if(p[i]==1){
			for(ll j=i*2;j<=lim;j+=i){
				p[j]=0;
			}
		}
	}
  return;
}

int main() {
    freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

	ll p[5000000]={0};
	primeSeive(p,5000000);
	ll x;
	cin>>x;
	ll cnt=0;
	for(ll i=0;i<=5000000;i++){
		// if(p[i]==1){
		// 	cnt++;
		// 	if(cnt==x){
		// 		cout<<i;
		// 		break;
		// 	}
		// }
    cout<<p[i]<<" ";
	}
	return 0;
}