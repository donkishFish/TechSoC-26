#include <iostream>
#include <cmath>
#include <vector>
int main(){
using namespace std;
int C=0;
int N=0;
float weight=0;
float sum=0;
float maxW=0;
float minW=INFINITY;
cout<<"Enter maximum capacity of port: ";
cin>>C;
cout<<"Enter number of containers: ";
cin>>N;
vector<int> loads;
for(int i=0; i<N; i++){
    cout<<"Enter the weight of container "<<(i+1)<<": ";
    cin>>weight;
    loads.push_back(weight);
}
for(int i=0; i<loads.size(); i++){
    int j=1;
    while(loads[i]>loads[i+j] && (i+j)<loads.size()){
    
        swap(loads[i], loads[i+j]);
        j++;

    }
    i++;
}
cout<<"\nSorted weights are as: ";
for (int x : loads) {
        std::cout << x << " ";
    } cout<<"\n";


cout<<"\nThe bar chart for the ships is as follows:\n";
for(int m=0; m<loads.size(); m++){
    cout<<"Container "<<m+1<<"| ";
    for(int w=0; w<loads[m]; w++){cout<<"*";} cout<<endl;

} cout<<"\n";

return 0;
}