#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;

    cout<<"Enter the number of items: "<<endl;
    cin>>n;

    vector<int> weight(n), profit(n);

    cout<<"Enter the weight and profit"<<endl;
    for(int i=0;i<n;i++){
        cin>>weight[i]>>profit[i];
    }

    cout<<"Enter the knapsack capacity"<<endl;
    cin>>W;

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    for(int i=1;i<=n;i++){
        for(int w=0; w<=W; w++){
            if(weight[i-1] <= w){
                dp[i][w] = max(dp[i-1][w], profit[i-1] + dp[i-1][w-weight[i-1]]);
            }
            else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }

    cout<<dp[n][W]<<endl;
}