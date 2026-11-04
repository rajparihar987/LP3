#include <bits/stdc++.h>
using namespace std;

struct Item {
    int weight, profit;
};

int main() {
    int n, capacity;

    cout<<"Enter number of items: ";
    cin>>n;

    vector<Item> items(n);

    cout<<"Enter weight and profit: "<<endl;
    for(int i=0; i<n ;i++) {
        cin >> items[i].weight >> items[i].profit;
    }

    cout<<"Enter knapsack capacity: ";
    cin>>capacity;

    sort(items.begin(), items.end(), [](Item a, Item b){
        return (double)a.profit / a.weight > (double)b.profit / b.weight;
    });

    double totalProfit = 0;

    for(auto item : items){
        if(capacity == 0) break;

        if(item.weight <= capacity){
            capacity -= item.weight;
            totalProfit += item.profit;
        }
        else{
            totalProfit += (double)item.profit/item.weight*capacity;
            capacity = 0;
        }
    }

    cout<<fixed<<setprecision(2);
    cout<<"Maximum Profit: "<<totalProfit<<endl;
}