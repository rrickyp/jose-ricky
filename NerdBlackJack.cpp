#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "CardFeatures.h"
#include "mathprob.h"
using namespace std;


int main() {
  ifstream fin;
  system("clear");
  fin.open("ASCII-NERD.txt");
  string welcome;
  
  while (getline(fin, welcome)){
    cout << welcome << endl;
  }
  int start = (time(NULL));
  while (time(NULL) != start+3) {

  }
  cout << "ARE YOU READY TO PLAY?? (Y/N): ";
  char ans;
  cin >> ans;
  int sign = 0;
  while ((ans == 'Y')||(ans == 'y')) {
   vector <int> UsedCards; 
   vector <int> PlayerCards;
   vector <int> DealerCards;
   ShareCard(UsedCards, PlayerCards); //initialize card
   ShareCard(UsedCards, PlayerCards); //initialize card
   ShareCard(UsedCards, DealerCards); //initialize card
   sorted(PlayerCards);
   DealerCards.push_back(-1);
   cout <<"Your Cards:"<<endl;
   PrintCard(PlayerCards);
   cout<<endl;
   cout <<"Dealer's Cards:"<<endl;
   PrintCard(DealerCards);
   cout<<endl;
   bool answer;
   answer = HitOrStand();
   ifstream fin;
   fin.open("topspeed.txt");
   if (fin.fail()) {
     cout <<"File error"<<endl;
     exit(1);
   }
   string temp;
   fin>>temp;
   fin.close();

   double Topspeed = atof(temp.c_str());
   double BestTime;
   while (true) {
     double Question = MathQuestion();
     if (Question!=0) {
       if (Question < Topspeed) {
         BestTime = Question;
         cout <<"Wow, You beat the top speed"<<endl;
       }
       else if (Question > Topspeed) {
         cout << "You are slow, the top speed is " << Topspeed<<"s"<<endl;
       }
       if (!answer) {
         break;
       }
       ShareCard(UsedCards, PlayerCards);
       sorted(PlayerCards);
       cout << "Your Cards:"<<endl;
       PrintCard(PlayerCards);
       cout<<endl;
       if (CardsValue(PlayerCards) == 21) {
         cout <<"Congrats, You got BlackJack"<<endl;
         cout <<"You are the winner"<<endl;
         sign = 1;
         break;
       }
       else if (CardsValue(PlayerCards) > 21) {
         cout <<"You lose :(" <<endl;
         cout << "The winner is Dealer"<<endl;
         sign = 1;
         break;
       }
       answer = HitOrStand();
       break;
     }
     else {
       cout <<"You lose :("<<endl;
       sign = 1;
       break;
     }
   }
   if (sign == 1) {
     cout << "Do you want to play again? (Y/N): ";
     cin >> ans;
     continue;
   }
   DealerCards.pop_back();
   DealerMove(UsedCards, DealerCards, PlayerCards); //inside DealerMove, there will be share card for the dealer, and print the cards
   if (CardsValue(PlayerCards) > CardsValue(DealerCards) || CardsValue(DealerCards)>21) {   // assume true if Player wins
     cout <<"Congrats, You won the game"<<endl;
   }
   else if (CardsValue(PlayerCards) == CardsValue(DealerCards)) {
     cout <<"Game Tied, your cards have the same value as the dealer's"<<endl;
   }
   else {
     cout <<"You lose :("<<endl;
     cout << "The winner is Dealer"<<endl;
   }
   if (Topspeed<BestTime) {
   ofstream fout("Topspeed.txt");
   if (fout.fail()) {
     cout <<"Error in file opening"<<endl;
     exit(1);
   }
   fout << BestTime;
   fout.close();
   }
  cout << "Do you want to play again? (Y/N): ";
  cin >>ans;
  }
  cout <<"BYE BYE :)"<<endl;
  return 0;
  
}
