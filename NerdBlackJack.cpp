#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

/*
bool exist(int card, int cards[], int length) { // full of bugs
  for (int i = 0; i < length; i ++) {
    if (card == cards[i]) {
      return true;
    }
  }
  return false;
}
int shareCard(int cards[], int length){ //full of bugs
  srand(time(NULL));
  int card = rand()%52;
  while (exist(card, cards, length)) {
    card = rand()%52;
  }
  return card;
}

void initial_card(int player[5], int dealer[5], int usedCard[], int &length){ //full of bugs
  int i =0;
  while(i < 2){
    player[i] = shareCard(usedCard, length);
    usedCard[length] = player[i];
    length++;
    dealer[i] = shareCard(usedCard, length);
    i++;
    usedCard[length] = dealer[i];
    length++;
  }

}
*/
void ShareCard(vector <int> &UsedCards, vector <int> &Cards) {
  srand(time(NULL));
  int card = rand()%52;
  while (find(UsedCards.begin(), UsedCards.end(), card) != UsedCards.end()) {
    card = rand()%52;
  }
  UsedCards.push_back(card);
  Cards.push_back(card);
}

void PrintCard(vector <int> cards) {
  for (int i= 0; i< cards.size(); i++) {
    cout << cards[i]<<" ";
  }
  cout <<endl;
}
void PrintCardDealer(vector <int> cards) {
  PrintCard(cards);
  cout << "#########"<<endl; // assume # as cards' back
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
int main() {
  ifstream fin;
  system("clear");
  fin.open("ASCII-NERD.txt");
  string welcome;
  while (getline(fin, welcome)){
    cout << welcome << endl;
    
  //
  }
  int start = (time(NULL));
  while (time(NULL) != start+3) {

  }
  cout << "ARE YOU READY TO PLAY?? (Y/N): ";
  char ans;
  cin >> ans;
  if ((ans == 'Y')||(ans == 'y')) {
    /*
    int usedCards[15];
    int PlayerCards[5];
    int DealerCards[5];
    int length = 0, playerCards_length = 0;
    initial_card(PlayerCards, DealerCards, usedCards, length);
    //PrintCard(PlayerCards, playerCards_length);
    //PrintCard(DealerCards, 1); // inside of PrintCard , if length == 1, print the card and the closed card.
    */
   vector <int> UsedCards;
   vector <int> PlayerCards;
   vector <int> DealerCards;
   ShareCard(UsedCards, PlayerCards); //initialize card
   ShareCard(UsedCards, PlayerCards); //initialize card
   ShareCard(UsedCards, DealerCards); //initialize card
   PrintCard(PlayerCards);
   PrintCardDealer(DealerCards);
   bool ans;
   ans = HitOrStand();
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
   while (ans) {
     ShareCard(UsedCards, PlayerCards);
     //MathQuestion();
     if (MathQuestion()!=0) {
       if (MathQuestion() < Topspeed) {
         BestTime = MathQuestion();
         cout <<"Wow, You beat the topspeed"<<endl;
       }
       else if (MathQuestion() > Topspeed) {
         cout << "You are slow, the top speed is" << Topspeed<<"s"<<endl;
       }
       PrintCard(PlayerCards);
       if (isBlackJack(DealerCards)) {
         cout <<"Congrats, You got BlackJack"<<endl;
         cout <<"You are the winner"<<endl;
         return 0;
       }
       if (isBust(PlayerCards)) {
         cout <<"You lose :(" <<endl;
         cout << "The winner is Dealer"<<endl;
         return 0;
       }
       ans = HitOrStand();
       continue;
     }
     else {
       cout <<"You lose :("<<endl;
     }
   }
   DealerMove(UsedCards, DealerCards); //inside DealerMove, there will be share card for the dealer, and print the cards
   if (WhoIsTheWinner(PlayerCards, DealerCards)) {   // assume true if Player wins
     cout <<"Congrats, You won the game"<<endl;
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

  }
  else {
    cout <<"BYE BYE :)"<<endl;
    return 0;
  }
}
