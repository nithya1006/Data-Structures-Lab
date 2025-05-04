//Program to implement a game between 3 players
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void points();

int main(){
    int t;
    cout<<"Enter no. of testcases: ";
    cin>>t;

    if ((t<1) || (t>100)){
        cout<<"t should be between 1 and 100.";
        return 0;
    }

    while (t--){
        points();
        cout<<endl;
    }
}

//Function to calculate the points of each player and display them
void points(){
    int n;
    cout<<"Enter no. of words: ";
    cin>>n;

    if ((n<1) || (n>1000)){
        cout<<"n should be between 1 and 1000.";
        return;
    }

    vector<vector<string>> words(3, vector<string>(n));
    unordered_map<string, int> freq;

    for (int i=0; i<3; i++){
        cout<<"Enter player " << i+1 << " words: ";
        for (int j=0; j<n; j++){
            cin>>words[i][j];
            freq[words[i][j]]++;
        }
    }
    vector<int> scores(3,0);

    for (int k=0; k<3; k++){
        for (int l=0; l<n; l++){
            if (freq[words[k][l]]==1){
                scores[k]+=3;
            }
            else if (freq[words[k][l]]==2){
                scores[k]+=1;
            }
        }
    }

    cout<<"The score of player 1= "<< scores[0]<<endl;
    cout<<"The score of player 2= "<< scores[1]<<endl;
    cout<<"The score of player 3= "<< scores[2]<<endl;
}