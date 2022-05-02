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
  while(CardsValue(Dealercards) < CardsValue(Playercards)) {
    ShareCard(UsedCards, Dealercards);
    sorted(Dealercards);
    PrintCard(Dealercards);
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
    int value = cards[i]%13+1;
    if (cards[i]%13 == 11 || cards[i]%13 == 12) {
      value = 10;
    }
    else if (cards[i]%13 == 0) {
      value = 11;
    }
    total = total + value;
  }
  for (int i = 0; i<AceCount;i++) {
    if (total < 21) {
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
    vector <ifstream> fin;
    vector <string> txtFile;
    string * line = new string[cards.size()];
    for(int i = 0;i<cards.size();i++) {
      txtFile.push_back("CardsPictures/"+ to_string(cards[i])+".txt");
      fin[i].open(txtFile[i]);
    }
    for (int i = 0; i < cards.size();i++) {
      for (int j = 0; j < cards.size();j++) {
        line[i].push_back(" ");
      }
    }
    for (int i = 0; i < cards.size();i++) {
      for (int j = 0; j< cards.size();j++) {
        getline(fin[i], line[i][j]);
      }
    }
    for (int i = 0; i < cards.size();i++) {
      for (int j = 0; j < cards.size();j++) {
        cout << line[i][j];
      }
      cout <<endl;
    }

  }

void PrintCardDealer(vector <int> cards) {
  PrintCard(cards);
  ifstream fin;
  fin.open("CardPictures/back.txt");
}
bool HitOrStand() {
  string ans;
  cout <<"Hit or Stand?";
  cin >>ans;
  if (ans == "Hit") {
    return true;
  }
  return false;
}