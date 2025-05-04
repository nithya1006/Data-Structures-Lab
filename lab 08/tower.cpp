//Program to find the largest amount of blocks possible in Tower 1
#include <iostream>
#include <numeric>
#include <algorithm>
#include <vector>
using namespace std;

void Max(vector<long long> &arr, int n );

int main(){
    long long t;
    cout<< "Enter no. of testcases: ";
    cin>>t;
    while (t--){
        int n;
        cout<<"Enter the no. of towers: ";
        cin>>n;
        cout<<"Enter "<< n << " values:"<< endl;
        vector<long long> a(n);
        for (long long i=0; i<n; i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        Max(a, n);
        cout<<"Maximum blocks in tower 1 = " << a[0] <<endl;
    }
    return 0;
}

//Function to move blocks from other towers to tower 1 if a[i] is larger
void Max(vector<long long> &a, int n ){
    for (long long i=0; i<n; i++){
        if (a[i]>a[0]){
            a[0] += (a[i]-a[0]+1)/2;
        }
    }
    return;
}