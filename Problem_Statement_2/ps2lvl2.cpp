#include <iostream>
#include <vector>
#include <cstdlib> 
#include <cmath>
#include <windows.h>
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


    int bender1=404;
    int bender2=404;
    int attackerIndex=404;
    int defenderIndex=404;
    int attackIndex=404;
    int damage=0;
    float multiplier=1;
    int crit=1;


int main() {
    Bender Aang("Aang", "Air", 180, 132, 11, 100);
    Bender Luke("Luke", "Water", 199, 125, 12, 90);
    Bender Anakin("Anakin", "Fire", 189, 121, 10, 85);
    Bender Frodo("Frodo", "Earth", 200, 139, 11, 80);

    vector<Bender> benders={Aang, Luke, Anakin, Frodo};
    vector<string> bendersS={"Aang", "Luke", "Anakin", "Frodo"};

    float movePower[]={0.7, 0.8, 0.9, 1};
    string userInput;   

    cout<<"Duel Initialization:\nChoose the two benders\n ";

Initialize:
    do {
        cout<<"Choose bender 1: ";
        cin>>bender1;
        if(bender1>=0 && bender1<4){break;} else cout<<"Invalid Input, try again\n";

    } while(bender1>=0 && bender1<4);

    do {
        cout<<"Choose bender 2: ";
        cin>>bender2;
        if(bender2>=0 && bender2<4){break;}else cout<<"Invalid Input, try again";

    } while(bender2>=0 && bender2<4);

    if(benders[bender1].speed>benders[bender2].speed){attackerIndex=bender1; defenderIndex=bender2;} else{attackerIndex=bender2; defenderIndex=bender1;}
        
  

srand(attackIndex);

SetMultiplier:
        if((benders[attackerIndex].element=="Water" && benders[defenderIndex].element=="Fire")||
        (benders[attackerIndex].element=="Fire" && benders[defenderIndex].element=="Air")||
        (benders[attackerIndex].element=="Air" && benders[defenderIndex].element=="Earth")||
        (benders[attackerIndex].element=="Earth" && benders[defenderIndex].element=="Water")) multiplier=2;
        
        else if((benders[attackerIndex].element=="Fire" && benders[defenderIndex].element=="Water")||
        (benders[attackerIndex].element=="Air" && benders[defenderIndex].element=="Fire")||
        (benders[attackerIndex].element=="Earth" && benders[defenderIndex].element=="Air")||
        (benders[attackerIndex].element=="Water" && benders[defenderIndex].element=="Earth")) multiplier=0.5; else multiplier=1;
    

cout<<"==DUEL BEGINS==";
AttackLoop:
int i=0;
do {
    
    
    cout<<"Choose attack index(0-3) of "<<bendersS[attackerIndex]<<": ";
    cin>>attackIndex;
    
    if(rand()%100<10){crit=2;}else crit=1;

    if (attackIndex < 0 || attackIndex > 3){cout<<"Any other input than (0-3) causes auto choosing\n";
               attackIndex=rand()%4;}
        
        damage=round((benders[attackerIndex].attack)*crit*(movePower[attackIndex])/(benders[defenderIndex].defense))*multiplier;
        cout<<"Turn "<<i<<":\n";
        cout<<bendersS[attackerIndex]<<" used "<<benders[attackerIndex].moves[attackIndex]<<"!\n";
        cout<<bendersS[defenderIndex]<<" took "<<damage<<" damage!\n";

        if(multiplier==2){cout<<bendersS[defenderIndex]<<" took two times damage due to attack from a dominating element!\n";}
        if(multiplier==0.5){cout<<bendersS[defenderIndex]<<" took only half damage being the dominating element bender";}
        if(crit==2){cout<<bendersS[defenderIndex]<<" took a critical hit!";}
        cout<<bendersS[defenderIndex]<<" HP: "<<benders[defenderIndex].hp;

        benders[defenderIndex].hp=benders[defenderIndex].hp-damage;
        swap(attackerIndex, defenderIndex);

        
        if (benders[defenderIndex].hp<=0){cout<<bendersS[defenderIndex]<<" has fainted!\n"<<bendersS[attackerIndex]<<" wins!!";
            return 0;} 
        cout<<"\n\n";
            i++;
        Sleep(1000);
        goto SetMultiplier;
} while(true);

 return 0;


//if(attackerIndex==404||attackIndex==404||defenderIndex==404) cout<<"INPUT WAS INVALID TRY RUNNING AGAIN!";

}
