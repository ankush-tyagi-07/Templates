#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
int m=1e9+7;

ll modmul(ll a,ll b){
    return ((a%m)*(b%m))%m;
}

int binexp_rec(int a,int b){
    if(b==0) return 1;
    long long res=binexp_rec(a,b/2);
    if(b&1){
        return modmul(modmul(res,a),res);
    }
    else return modmul(res,res);
}

int binexp_iter(int a,int b){
    int ans=1;
    while(b){
        if(b&1){
            ans=(ans*1LL*a)%m;
        }
        a=(a*1LL*a)%m;
        b>>=1;
    }
    return ans;
}

// if m=too large we use binary multiplication a*a=a+a+a+a.....
// int binmultiply(ll a,ll b){
//     int ans=0;
//     while(b){
//         if(b&1){
//             ans=(ans+a)%m;
//         }
//         a=(a+a)%m;
//         b>>=1;
//     }
//     return ans;
// }

// if a is too large (a^b)%m=((a%m)^b)%m;

// if b is too large we use euler totient function;
// phi(n)=n*(pi(1-(1/p)));
// p for all factors one by one;
// if(n==prime) phi(n)=n-1;
// (a^b)%m=(a^(b%phi(n)))%n;


int main(){
    cout<<binexp_rec(3,5000)<<endl<<binexp_iter(3,5000);
    return 0;
}