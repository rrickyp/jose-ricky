#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include "CardFeatures.h"
#include <fstream>
using namespace std;


void ShareCard(vector <int> &UsedCards, vector <int> &Cards) {
  srand(time(NULL));
  int card = rand()%52;
  while (find(UsedCards.begin(), UsedCards.end(), card) != UsedCards.end()) {
    card = rand()%52;
  }
  UsedCards.push_back(card);
  Cards.push_back(card);
}

void DealerMove(vector <int> & UsedCards, vector <int> & Dealercards, vector <int> Playercards) {
  while(CardsValue(Dealercards) < CardsValue(Playercards) || CardsValue(Dealercards)< 14) {
    ShareCard(UsedCards, Dealercards);
    sorted(Dealercards);
    cout << "Dealer's Cards:"<<endl;
    PrintCard(Dealercards);
    system("sleep 1");
    if (CardsValue(Dealercards) == 21) {
      break;
    }
    cout<<endl;
  }
}
int CardsValue(vector <int> cards) {
  int total = 0;
  int AceCount = 0;
  for (int i = 0; i < cards.size();i++) {
    if (cards[i]%13 == 0) {
      AceCount++;
    }
  }
  for (int i = cards.size()-1;i>=0;i--) {
    int value = (cards[i]%13)+1;
    if (cards[i]%13 == 10 || cards[i]%13 == 11 || cards[i]%13 == 12) {
      value = 10;
    }
    else if (cards[i]%13 == 0) {
      value = 11;
    }
    total = total + value;
  }
  for (int i = 0; i<AceCount;i++) {
    if (total <= 21) {
      break;
    }
    total = total -10;
  }
  return total;
    
}
bool cmpcard(const int & a, const int & b) {
  if (b%13>a%13) {
    return true;
  }
  return false;
}
void sorted(vector <int> & cards) {
  sort(cards.begin(), cards.end());
  sort(cards.begin(), cards.end(), cmpcard);
}
void PrintCard(vector <int> cards) {
  vector <ifstream*> fin;
  vector <string> txtFile;
  string line;

  for(int i = 0;i<cards.size();i++) {
    if(cards[i]==-1) {
      txtFile.push_back("CardsPictures/back.txt");
      break;
    }
    txtFile.push_back("CardsPictures/"+ to_string(cards[i])+".txt");
  }
  for (int i = 0; i < cards.size();i++) {
    ifstream * f = new ifstream(txtFile[i], ios::in);
    fin.push_back(f);
  }
  for (int i = 0; i < 6;i++) {
    for (int j = 0; j < cards.size();j++) {
      getline(*fin[j], line);
      cout <<line;
    }
    cout <<endl;

  }
  for (int i = 0; i < cards.size();i++) {
    fin[i]->close();
  }
  
}
/*
void PrintCardDealer(vector <int> cards) {
  PrintCard(cards);
  ifstream fin;
  fin.open("CardsPictures/back.txt");
  string line;
  while (getline(fin, line)) {
    cout <<line<<endl;
  }
}
*/
bool HitOrStand() {
  string ans;
  cout <<"Hit or Stand? ";
  cin >>ans;
  for_each(ans.begin(), ans.end(), [] (char &c) {
    c = tolower(c);
  });
  while( true ){
    if (ans == "hit") {
      return true;
    }
    else if( ans == "stand"){
      return false;
    }
  }
}