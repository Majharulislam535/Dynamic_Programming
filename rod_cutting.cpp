#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];

int rod_cutting(int n,int s,int val[],int w[]){

    if(n==0 || s==0){
         return 0;
    }

    if(dp[n][s] != -1){
        return dp[n][s];
    }

    if(w[n-1] <= s){

         int opt1 =val[n-1]+ rod_cutting(n,s-w[n-1],val,w);
         int opt2 = rod_cutting(n-1,s,val,w);

         return dp[n][s]= max(opt1,opt2);
    }
    else{
        return dp[n][s]= rod_cutting(n-1,s,val,w);
    }

}


int main() {

         int n;
         cin>>n;

         int val[n],w[n];

         for(int i=0;i<=n;i++){
             for(int j=0;j<=n;j++){
                 dp[i][j] = -1;
             }
         }


         for(int i=0;i<n;i++){
             cin>>val[i];
             w[i] = i+1;
         }

         cout<<rod_cutting(n,n,val,w)<<endl;

    return 0;
}
