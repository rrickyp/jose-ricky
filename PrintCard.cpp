#include <iostream>
#include <cstdlib>
using namespace std;


#define SPADE   "\xE2\x99\xA0"
#define CLUB    "\xE2\x99\xA3"
#define HEART   "\xE2\x99\xA5"
#define DIAMOND "\xE2\x99\xA6"
#define NUMCARDS  5

//logic board of the print card
void print_cards(int user_card[5], int number_of_cards){
    for(int i = 0; i < number_of_cards; i++){
        cout << user_card[i] % 13 ;
        if (user_card[i] % 13 == 0) {
            cout << 'A';
        }
        else if (user_card[i] % 13 == 10){
            cout << 'J';
        }
        else if (user_card[i] % 13 == 11){
            cout << 'Q';
        }
        else if (user_card[i] % 13 == 12){
            cout << 'K';
        }
        else{
            cout << user_card[i] % 13 ;
        }
        if(user_card[i] >= 0 && user_card[i] < 13) {//converting the given number to end with the symbol
            cout << SPADE << " ";
        }
        else if(user_card[i] >= 13 && user_card[i] < 26) {
            cout << HEART << " ";
        }
        else if(user_card[i] >= 26 && user_card[i] < 39) {
            cout << CLUB << " ";
        }
        else if(user_card[i] >= 39 && user_card[i] < 52) {
            cout << DIAMOND << " ";
        }
        }
    }


int main(){
    int user_card[5] = {};
    int dealer_card[5] = {};
    int total_cards = 0;
    cout << "How many cards that the user inputted?" << endl;
    cin >> total_cards;
    cout << endl;
    for(int i = 0; i < 2; i++){
        int temp = 0;
        cin >> temp;
        user_card[i] = temp;
    }

    print_cards(user_card, total_cards);


    return 0;
}
