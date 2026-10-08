#include <iostream>
#include <vector>
#include <array>
#include <string>

#include <windows.h> 
using namespace std;
int R;
int C;
vector<string> grid;

void conditions(vector<string>& grid, int C, int R);

int main(){
int G=0;

cin>>R>>C;
cin>>G;
string topBottomBorder(C + 2, ' ');
string row;
grid.push_back(topBottomBorder);
for(int r=0; r<R; r++){
    cin>>row;
    if (row.size()==C){
        grid.push_back(" "+ row+" ");
        } else {cout<<"Invalid Input\n"; r--;}
    }
grid.push_back(topBottomBorder);
cout<<"\n\n\n";

while(true){
//for(int g=0; g<G; g++){
    conditions(grid, C, R);
//}
for(int r=1; r<=R; r++){
    for(int c=1; c<=C; c++){cout<<grid[r][c];}
    cout<<"\n";
}
Sleep(50);
cout << "\033[2J\033[H";
}

}


void conditions(vector<string>& grid, int C, int R){
    vector<string>tempGrid= grid;
    for(int r=1; r<=R; r++){
        
        for(int c=1; c<=C; c++){
            int alive=0;
            int dead=0;
        
            array<char, 8> arr = {tempGrid[r-1][c-1], tempGrid[r-1][c], tempGrid[r-1][c+1],
                                  tempGrid[r][c-1],                     tempGrid[r][c+1],
                                  tempGrid[r+1][c-1], tempGrid[r+1][c], tempGrid[r+1][c+1]};
            
            for(char i: arr){
                if(i=='.') dead++;
                else if(i=='#') alive++;
            }

            if(grid[r][c]=='#'){
                if(alive<2 || alive>3){
                    grid[r][c]='.';
                }
            } else if(grid[r][c]=='.'){
                if(alive==3){
                    grid[r][c]='#';
                }
            }
            
        

        
        }
    }
    return;
}