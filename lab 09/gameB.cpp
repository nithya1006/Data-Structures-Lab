//Program to find the difference in strengths between the participants of a competition
#include <iostream>
#include <vector>
using namespace std;

void difference();

int main(){
    int t;
    cout<<"Enter no. of testcases: ";
    cin>>t;

    if (t>250 || t<1){
        cout<<"Invalid input. Value of t should be from 1 to 1000."<<endl;
        return 0;
    }

    while(t--){
        difference();
        cout<<endl;
    }
    return 0;
}

//Function to calculate the maximum and 2nd maximum strength of players and display the difference in strength of participants
void difference(){
    int n;
    cout<<"Enter no. of players: ";
    cin>>n;

    vector<int> player(n);

    int max1 =0;
    int max2=0;

    for (int i=0; i<n; i++){
        cout<<"Enter strength of player " << i+1 << ": ";
        cin>>player[i];

        if (player[i]>max1){
            max2=max1;
            max1=player[i];
        }
        else if (player[i]>max2){
            max2=player[i];
        }
    }

    for (int j=0; j<n; j++){
        if (player[j]==max1){
            cout << player[j] - max2 << " ";
        }
        else{
            cout << player[j] - max1 << " ";
        }
    }
    cout<<endl;
    return;
}