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
  string ans = "test";
  while(ans!="y" && ans != "n") {
    cout << "ARE YOU READY TO PLAY?? (Y/N/RULES): ";
    cin >> ans;
    for_each(ans.begin(), ans.end(), [] (char &c) {
    c = tolower(c);
    });
    string rules;
    ifstream fiin;
    if (ans == "rules") {
      fiin.open("Rules.txt");
      while (getline(fiin, rules)) {
        cout << rules<<endl;
      }
      cout <<endl;
    }
    fiin.close();
    }
  int sign = 0;
  while ((ans == "y")) {
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
    double BestTime = 10000;
    while (true) {
      cout << "You have 15 seconds to complete the question !!"<<endl;
      double Question = MathQuestion();
      if (Question!=0) {
        if (Question >15) {
          cout <<"You ran out of time ("<<Question<<"s)"<<endl;
          cout <<"You lose :("<<endl;
          cout <<"The winner is Dealer"<<endl;
          sign = 1;
          break;
        }
        if (Question < BestTime) {
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
    if (BestTime != 10000) {
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
    ans = "test";
    while (ans!="y" && ans!= "n"){
      ifstream fiin;
      cout << "Do you want to play again? (Y/N/RULES): ";
      cin >>ans;
      for_each(ans.begin(), ans.end(), [] (char &c) {
      c = tolower(c);
      });
      string rules;
      if (ans == "rules") {
        fiin.open("Rules.txt");
        while(getline(fiin, rules)) {
          cout <<rules<<endl;
        }
        cout <<endl;
      }
      fiin.close();
    }
  }
  cout <<"BYE BYE :)"<<endl;
  return 0;
  
}
