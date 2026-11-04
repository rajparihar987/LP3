#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: "<<endl;
    cin>>n;

    long long a = 0, b = 1;
    int steps = 0;

    cout<<"Fibonacci Series: ";

    for(int i=0; i<n ;i++){
        cout<<a<<" ";

        long long c = a+b;
        steps++;
        
        a = b;
        steps++;

        b = c;
        steps++;
    }

    cout<<"\nStep Count: "<<steps<<endl;
}