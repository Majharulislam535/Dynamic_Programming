#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];


int main()
{

    int n;
    cin>>n;
    int ar[n];

    for(int i=0;i<n;i++){
         cin>>ar[i];
    }

    int s;
    cin>>s;

     dp[0][0]=true;

     for(int i=1;i<=s;i++){
         dp[0][i] =0;
     }


    for(int i=1;i<=n;i++){
         for(int j=0;j<=s;j++){

              if (ar[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - ar[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
         }
    }


   cout<<dp[n][s]<<endl;


    return 0;
}
