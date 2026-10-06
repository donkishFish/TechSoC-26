#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Bender {
public:
    string name;
    string element;
    int hp;
    int attack;
    int defense;
    int speed;
    vector<string> moves;

    Bender(string name, string element, int hp, int attack, int defense, int speed){
       
        this->name= name;
        this->element= element;
        this->attack= attack;
        this->defense= defense;
        this->hp= hp;
        this->speed= speed;

        if(element=="Water") moves= {"Water Wave", "Water Bubble", "Ice Claw", "Waterspout"};
        if(element=="Fire") moves= {"Flamethrower", "Fireball", "Flame Charge", "Eruption"};
        if(element=="Earth") moves= {"Bind", "Rock Charge", "Sink", "Shake"};
        if(element=="Air") moves= {"Fog", "Wind Charge", "Suffocation", "Tornado"};


    }
    };

    class Attacker : public Bender {

    };

    class Defender : public Bender {

    };


    int benderIndex=404;
    int attackerIndex=404;
    int defenderIndex=404;
    int attackIndex=404;
    int damage=0;

    int askBender(string userInput);

    
    

int main() {
    Bender Aang("Aang", "Air", 180, 87, 20, 100);
    Bender Luke("Luke", "Water", 199, 99, 17, 90);
    Bender Anakin("Anakin", "Fire", 189, 98, 18, 85);
    Bender Frodo("Frodo", "Earth", 200, 100, 11, 80);

    vector<Bender> benders={Aang, Luke, Anakin, Frodo};
    vector<string> bendersS={"Aang", "Luke", "Anakin", "Frodo"};

    float movePower[]={0.5, 0.6, 0.7, 1};
    string userInput;
   // cout<<"Player Stats:\n";
    //displayStats();
  for(Bender guy: benders){
   cout<<guy.name<<"("<<guy.element<<")"<<" - ";
    cout<<"HP: "<< guy.hp<<"/100, Attack: "<< guy.attack<<", Defense: "<<guy.defense<<", Speed: "<<guy.speed<<"\nMoves: ";
    for(string move: guy.moves){cout<<move<<", ";}
    cout<<"\n";
    };

    
        cout<<"Choose attacker: ";
        cin>>userInput;
        attackerIndex= askBender(userInput);
        benderIndex=attackerIndex;
    

    
        cout<<"Choose attack: ";
        cin>>userInput;
        //attackIndex= askAttack(userInput);
        for(int i=0; i<4; i++){
        if(benders[attackerIndex].moves[i]==userInput) attackIndex=i;

        if(i>3){cout<<"Invalid Input"; return 404;
        }
    }
        
    

        cout<<"Choose defender: ";
        cin>>userInput;
        defenderIndex= askBender(userInput);
        
cout<<bendersS[attackerIndex]<<" used "<<benders[attackerIndex].moves[attackIndex]<<"!\n";
cout<<bendersS[defenderIndex]<<" took "<<round((benders[attackerIndex].attack)*(movePower[attackIndex])/(benders[defenderIndex].defense))<<" damage!";

if (benders[defenderIndex].hp<=0){cout<<bendersS[defenderIndex]<<" has fainted!";}

return 0;
}





int askBender(string userInput){
    
    if(userInput=="Aang") return 0;
    else if(userInput=="Luke") return 1;
    else if(userInput=="Anakin") return 2;
    else if(userInput=="Frodo") return 3;
    else cout<<"Invalid Input"; return 404;
}

