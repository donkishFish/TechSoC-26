#include <iostream>
#include <cmath>
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
for(int i=1; i<=N; i++){
    cout<<"Entet the weight of container "<<i<<": ";
    cin>>weight;
    if(weight>maxW) maxW=weight;
    if(weight<minW) minW=weight;
    sum+=weight;
}
cout<<"Total shipment weight: "<<sum<<"\n";
cout<<"Average container weight:  "<<sum/N<<"\n";
cout<<"Heaviest container: "<<maxW<<"\n";
cout<<"Lightest container: "<<minW<<"\n";
cout<<"Classification: ";
if(sum>=200) {cout<<"Heavy\n";} else{cout<<"Light\n";}
cout<<"Port Capacity: "<<C<<"\n";
cout<<"Status: ";
if(sum<=C){cout<<"Shipment can be unloaded\n";} else {cout<<"Shipment exceeds port capacity\n";}
return 0;
}