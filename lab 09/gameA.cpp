//Program to implement a game that declares the no of winners after eliminating players based on their positions
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void game(vector<int>& pos, vector<int>& players, int no_pos, int no_grp);

int main(){
    int t;
    cout<<"Enter no. of testcases: ";
    cin>>t;

    if (t>250 || t<1){
        cout<<"Invalid input. Value of t should be from 1 to 250. Try again."<<endl;
        return 0;
    }
    cout<<endl;

    while (t--){
        int no_pos, no_grp;
        cout<<"Enter no. of positions to delete: ";
        cin>>no_pos;

        cout<<"Enter no. of groups: ";
        cin>>no_grp;

        vector<int> position(no_pos);
        vector<int> player(no_grp);

        for (int i=0; i<no_pos; i++){
            cout<<"Enter position "<< i+1 << " to delete: ";
            cin>>position[i];
        }
        cout<<endl;

        for (int j=0; j<no_grp; j++){
            cout<<"Enter no. of players in group "<< j+1 << ": ";
            cin>>player[j];
        }
        cout<<endl;

        game(position, player, no_pos, no_grp);
        cout<<endl;
    }
}

//Function to find the minimum index and display the no of winners in each group
void game(vector<int>& pos, vector<int>& players, int no_pos, int no_grp){
    int min_idx = *min_element(pos.begin(), pos.end());
    for (int i=0; i< no_grp; i++){
        if (players[i] >= min_idx){
            cout << "The no. of winners in group " << i+1 << ": " << min_idx-1 << endl;
        }
        else{
            cout << "The no. of winners in group " << i+1 << ": " << players[i] << endl;
        }
    }
    return;
}