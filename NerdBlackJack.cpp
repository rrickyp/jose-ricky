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
  system("clear");
  cout <<"To have the best experience, make your terminal full screen"<<endl;
  system("sleep 2");
  ifstream fin;
  system("clear");
  fin.open("ASCII-NERD.txt");
  string welcome;
  while (getline(fin, welcome)){
    cout << welcome << endl;
    
  }

  system("sleep 2");
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
   double BestTime = -1;
   while (true) {
     double Question = MathQuestion();
     if (Question!=0) {
       if (Question < Topspeed) {
         BestTime = Question;
       }
       if (!answer) {
         sign = 0;
         break;
       }
       ShareCard(UsedCards, PlayerCards);
       sorted(PlayerCards);
       cout << "Your Cards:"<<endl;
       PrintCard(PlayerCards);
       cout<<endl;
       if (CardsValue(PlayerCards) > 21) {
         system("sleep 1");
         cout << "Your cards are bust"<<endl;
         cout <<"You lose :(" <<endl;
         cout << "The winner is Dealer"<<endl;
         sign = 1;
         break;
       }
       answer = HitOrStand();
     }
     else {
       cout << "Your calculation is wrong"<<endl;
       cout <<"You lose :("<<endl;
       sign = 1;
       break;
     }
   }
   if (sign == 0) {
   DealerCards.pop_back();
   DealerMove(UsedCards, DealerCards, PlayerCards); //inside DealerMove, there will be share card for the dealer, and print the cards
   cout << "Your cards' value is "<<CardsValue(PlayerCards)<<endl;
   cout << "Dealer's cards value is "<<CardsValue(DealerCards)<<endl;
   if (CardsValue(PlayerCards) > CardsValue(DealerCards) || CardsValue(DealerCards)>21) {   // assume true if Player wins
     if (CardsValue(PlayerCards) == 21) {
       cout << "You got BlackJack"<<endl;
     }
     cout <<"Congrats!! You won the game"<<endl;
   }
   else if (CardsValue(PlayerCards) == CardsValue(DealerCards)) {
     cout <<"Game Tied, your cards have the same value as the dealer's"<<endl;
   }
   else {
     cout <<"You lose :("<<endl;
     cout << "The winner is Dealer"<<endl;
   }
   }
   if (BestTime != -1) {
     if (BestTime >= Topspeed) {
       cout << "You are smart, but you are not fast enough!!"<<endl;
       cout << "You have not beaten the best time"<<endl;
       cout << "The best time is "<<Topspeed<<"s"<<endl;
     }
     else if (BestTime < Topspeed) {
       cout << "Wow, you are so fast, you have beaten the best time"<<endl;
       system("sleep 1");
       cout << "Your best time is "<<BestTime<<"s, "<<Topspeed-BestTime<<"s faster than the best time"<<endl;

     }
   }
   system("sleep 2");
   if (Topspeed>BestTime) {
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
