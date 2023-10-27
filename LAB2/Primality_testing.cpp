#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;


ull power(int a,int n,int p){

   ull res=1;
   a =a%p;

   while(n){
    if(n&1){
        res = (res*a)%p;
    }
    n >>=1;
    a = (a*a)%p;
   }
    return res;
}

bool isPrime(ull n){

    if(n<= 1 || n == 4)return false;
    if(n == 2 || n ==3)return true;

    int k=100;
    while(k--){
    ull a = 2 + rand()%(n-4);
    if(__gcd(n,a) != 1)return false;
    if(power(a,n-1,n) != 1)return false; 
    }
    return true;
}


int main() {
	srand(time(NULL));
    //lab2 - primality testing   -  O(klog(n))
    ull n;
    cin>>n;
    
    if(isPrime(n)){
        cout<<n<<" is prime number";
    }
    else{
        cout<<n<<" is not prime number";
    }
    
	return 0;
}