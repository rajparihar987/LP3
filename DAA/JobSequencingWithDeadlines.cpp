#include <bits/stdc++.h>
using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

int main() {
    int n;
    cout<<"Enter number of jobs: ";
    cin>>n;

    vector<Job> jobs(n);

    cout<<"Enter job ID, deadline and profit:\n";
    for(int i=0; i<n; i++){
        cin >> jobs[i].id >> jobs[i].deadline >> jobs[i].profit;
    }

    sort(jobs.begin(), jobs.end(), [](Job a, Job b){
        return a.profit > b.profit;
    });

    int maxDeadline = 0;
    for(auto &j : jobs){
        maxDeadline = max(maxDeadline, j.deadline);
    }

    vector<char> slot(maxDeadline+1, '-');
    int totalProfit = 0;

    for(auto j : jobs){
        for(int t = j.deadline; t >= 1; t--) {
            if(slot[t] == '-'){
                slot[t] = j.id;
                totalProfit += j.profit;
                break; 
            }
        }
    }

    cout<<"\nSchhedules Jobs: ";
    for(int i=1; i<=maxDeadline; i++){
        if(slot[i] != '-'){
            cout<<slot[i]<<" ";
        }
    }
    
    cout<<"\nMaximum Profit: "<<totalProfit<<endl;
}