//Program to deteremine the min no. of moves to make so that the remaining sequence is unique
#include <iostream>
#include <vector>
using namespace std;

void min_del();

int main(){
    int t;
    cout<<"Enter no. of testcases: ";
    cin>>t;
    if (t>10000){
        cout<<"t should be between 1 and 10000"<<endl;
        return 0;
    }
    while (t--){
        min_del();
        cout<<endl;
    }
    return 0;
}

//Function to find min no of elements to remove
void min_del(){
    int n;
    cout<<"Enter no. of integers: ";
    cin>>n;

    if ((n<1) || (n>1000)){
        cout<<"n should be between 1 and 1000.";
        return;
    }

    vector<int> a(n);
    cout<<"Enter "<< n << " integers: ";
    for (int i =0; i<n; i++){
        cin>>a[i];
    }

    int min_delete=0;

    vector<int> freq(n+1,0);

    for (int j=n-1;j>=0;j--){
        if (freq[a[j]]>0){
            min_delete=j+1;
            break;
        }
        freq[a[j]]++;
    }

    cout<<"Minimum number of elements to be removed = " << min_delete << endl;

    return;
}