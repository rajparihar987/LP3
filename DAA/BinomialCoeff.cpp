#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter the value of n: "<<endl;
    cin>>n;

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            if(j==0 || j==i){
                dp[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }

    cout<<"Pascal's Triangle"<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }
}