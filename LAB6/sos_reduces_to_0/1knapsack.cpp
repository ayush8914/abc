#include<bits/stdc++.h>
using namespace std;


int knapsack(int n, int W, int weight[], int profit[]){

   int dp[n+1][W+1] = {0};

   for(int i=0;i<=n;i++)dp[i][0] = 0;
    for(int i=0;i<=W;i++)dp[0][i] = 0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
           
           if(weight[i-1] <= j){
               dp[i][j] = max(profit[i-1] + dp[i-1][j-weight[i-1]], dp[i-1][j]);
           }
           else dp[i][j] = dp[i-1][j];
           
        }
    }

    return dp[n][W];
}


int main(){
    


    //lab6 - sos reduces to 0/1 knapsack  -  O(n*sum)

    //taking input for the sos
    int n,sum;
    cin>>n>>sum;

    int s[n];
    for(int i=0;i<n;i++)cin>>s[i];
    

    //making instance of   0/1 knapsack from sos

    int i = n;
    int W = sum;
    // int V = sum;
    int w[n],p[n];
    
    for(int i=0;i<n;i++){
        w[i] = s[i];
        p[i] = s[i];
    }

    if(knapsack(i,W,w,p) >= sum){
      cout<<"yes";
    }
    else{
       cout<<"no";
    }

    return 0;
}