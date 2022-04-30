#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

//Function that decides whether user win or lose
bool win_or_lose(vector <int> &user_card, vector <int> &dealer_card, int total_card_user, int total_card_dealer){
    int sum_user = 0, sum_dealer = 0;
    //count user's card
    for(int i = 0; i < total_card_user; i++){
        sum_user += user_card[i] % 13 ;
        // cout << sum_user << " ";

    }
    //count dealer's card
    for(int j = 0; j < total_card_dealer; j++){
        sum_dealer += dealer_card[j] % 13  ;
        // cout << sum_dealer << " ";
    }
    // cout << sum_user << " " << sum_dealer << endl;

    //if the cards are bust
    if( sum_user > 21 ){
        cout << "BUST, User Lost!" << endl ;
        return false;
    }
    else if( sum_dealer > 21 ){
        cout << "BUST, Dealer Lost!" << endl ;
        return true;
    }
    //if the user cards worth less than dealer's
    else if( sum_user < sum_dealer){
        cout << "You Lost!" << endl;
        return false;
    }
    //if the user cards worth more than dealer's
    else if( sum_user > sum_dealer){
        cout << "You Won!" << endl;
        return true;
    }


    return false;
}




int main(){
    // int user_card[5] = {};
    // int dealer_card[5] = {};
    // int total_cards = 0;
    // int total_user_card = 2, total_dealer_card = 2;
    // // cout << "How many cards that the user inputted?" << endl;
    // // cin >> total_cards;
    // cout << endl;
    // cout << "Input User's Card ";
    // for(int i = 0; i < total_user_card; i++){
    //     int temp = 0;
    //     cin >> temp;
    //     user_card[i] = temp;
    // }
    // cout << "Input Dealer's Card ";
    // for(int i = 0; i < total_dealer_card; i++ ){
    //     int temp = 0;
    //     cin >> temp;
    //     dealer_card[i] = temp;
    // }
    //calling the function
    // win_or_lose(user_card, dealer_card, total_dealer_card, total_user_card);

    // only use the win_or_lose function in this file
    

    return 0;
}