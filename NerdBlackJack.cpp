#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
using namespace std;

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
    int usedCards[15];
    int PlayerCards[5];
    int DealerCards[5];
    int length = 0, playerCards_length = 0;
    initial_card(PlayerCards, DealerCards, usedCards, length);
    PrintCard(PlayerCards, playerCards_length);
    PrintCard(DealerCards, 1); // inside of PrintCard , if length == 1, print the card and the closed card.
  }
  else {
    return 0;
  }
}
