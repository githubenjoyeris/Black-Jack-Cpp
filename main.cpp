#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;
xddddd
string deck[1000] = {}; //sitas
string cards = "1234567890kqj";
string suits = "cdhs";
int ssize = 52;
int random;
int player = 0;
bool oneacep = false;

int randomcard() //renka atsitiktines kortas grafikai ir skaiciui galbut bus galima padaryti su kintauoju ssize
{
        srand(time(nullptr));
        int random;
        random = rand()%ssize;
        switch(deck[random].at(0))
        {
            case '1': // 1
            cout << "an Ace"<<endl;
            return 11;
            break;

            case '2':
            cout << "a 2" << endl;
            return 2;
            break;

            case '3':
            cout << "a 3" << endl;
            return 3;
            break;

            case '4':
            cout << "a 4" << endl;
            return 4;
            break;

            case '5':
            cout << "a 5" << endl;
            return 5;
            break;

            case '6':
            cout << "a 6" << endl;
            return 6;
            break;

            case '7':
            cout << "a 7" << endl;
            return 7;
            break;

            case '8':
            cout << "a 8" << endl;
            return 8;
            break;

            case '9':
            cout << "a 9" << endl;
            return 9;
            break;

            case '0':
            cout << "a 10" << endl;
            return 10;
            break;

            case 'k':
            cout << "a King" << endl;
            return 10;
            break;

            case 'q':
            cout << "a Queen" << endl;
            return 10;
            break;

            case 'j':
            cout << "a Jack" << endl;
            return 10;
            break;

        }
        for(int j = random; j<ssize; j++)
        {
            deck[j] = deck[j+1];

        }
        ssize--;
}

int playerinput()
{
   char input;
   cout<<"Your turn (Hit or Pass)"<<endl;
   cin>>input;
   if(input == 'p')
   {
       cout<<"a Pass"<<endl;
       return 0; //round to other player
   }
   else if(input == 'h')
   {
       random = randomcard();


       if(random == 11 && oneacep == true)
       {
           player++;
       }
       else if(random == 11 && oneacep == false)
       {
           oneacep = true;
           player = player + random;
       }
       else
       {
           player = player + random;
       }


       if(player > 21 && oneacep == true)
       {
           oneacep = false; //toliau neatimines 10
           player = player - 10;
           if(player == 21)
           {
               cout<<"Black Jack!"<<endl;
               return 0; //round to next player
           }
           else //in all other cases, player<21
           {
               playerinput();
           }
       }
       else if(player > 21 && oneacep == false)
       {
           cout<<"Bust!"<<endl;
           return 0; //round to other player
       }
       else if (player == 21)
       {
           cout<<"Black Jack!"<<endl;
           return 0; //round to other player
       }
       else
       {
           playerinput();
       }

   }
   else
   {
       cout<<"Invalid"<<endl;
       playerinput();
   }
}

int main()
{
   //sukuria kortu rinkini
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<13; j++)
        {
            deck[13*i+j] = cards.substr(j, 1) + suits.substr(i, 1);
        }
    }

 //The dealer
 int dealer = 0;
 bool oneaced = false;
   cout << "The dealer has "; //svarbu islaikyti tokia tvarka
   random = randomcard();
   if(random == 11)
   {
      oneaced = true;
   }
   dealer = dealer + random;
   _sleep(400+rand()%1000);
//The player
cout <<"You have ";

   random = randomcard();
   if(random == 11)
   {
       oneacep = true;
   }
   player = player + random;
   _sleep(400+rand()%1000);
   cout << "and ";
   random = randomcard();


   if(random == 11 && oneacep == true)
   {
       player++;
   }
   else if(random == 11 && oneacep == false)
   {
       oneacep = true;
       player = player + random;
   }
   else
   {
       player = player + random;
   }


   if(player == 21) //ace and 10
   {
       cout<<"Natural Black Jack!"<<endl;
       return 0; //round to other player
   }
playerinput();
    return 0;
}
