#include <vector>
using namespace std;
#ifndef CARDFEATURES_H
#define CARDFEATURES_H
int CardsValue(vector <int> cards);
void DealerMove(vector <int> & UsedCards, vector <int> & Dealercards, vector <int> Playercards);
void ShareCard(vector <int> &UsedCards, vector <int> &Cards);
void sorted(vector <int> & cards);
void PrintCard(vector <int> cards);
void PrintCardDealer(vector <int> cards);
bool HitOrStand();
#endif