#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include "features_and_mathprob/CardFeatures.h"
#include "features_and_mathprob/mathprob.h"
using namespace std;


int main() {
  // Every beginning of the game, we clear the CLI.
  system("clear");
  cout <<"To have the best experience, make your terminal full screen"<<endl;
  // Give the user time to change their terminal to full screen mode
  system("sleep 2");
  system("clear");
  // Initializing fin, and printing "Welcome to Nerd Blackjack" ASCII
  ifstream fin;
  fin.open("OtherData/ASCII-NERD.txt");
  string welcome;
  while (getline(fin, welcome)){
    cout << welcome << endl;
  }

  system("sleep 2");
  // Initializing string ans to "test", so that it does not break the while loop.
  // Inputting user's ans and transform it into lowercase number using for_each function and tolower.
  string ans = "test";
  while(ans != "y" && ans != "n") {
    cout << "ARE YOU READY TO PLAY?? (Y/N/RULES): ";
    cin >> ans;
    for_each(ans.begin(), ans.end(), [] (char &c) {
      c = tolower(c);
    });
    // If the user input rules, then set of rules would be displayed for the user.
    string rules;
    ifstream fiin;
    if (ans == "rules") {
      fiin.open( "OtherData/Rules.txt" );
      // Getting every line in the "OtherData/Rules.txt" file using getline function.
      while ( getline(fiin, rules) ) {
        cout << rules << endl;
      }
      cout << endl;
    }
    // Closing the opened file to avoid memory leaks
    fiin.close();
  }

  // If the user answered "y", then the first while loop would break and move to the second while loop that captured "y".
  int sign = 0;
  while ((ans == "y")) {
    // initializing vector containers of integers.
    vector <int> UsedCards;
    vector <int> PlayerCards;
    vector <int> DealerCards;
    ShareCard(UsedCards, PlayerCards); //initialize card
    ShareCard(UsedCards, PlayerCards); //initialize card
    ShareCard(UsedCards, DealerCards); //initialize card
    // Sorting player cards prior to printing
    sorted(PlayerCards);
    // push_back(-1) used in PrintCards.cpp later on
    DealerCards.push_back(-1);
    // Printing the cards of users and dealers
    cout << "Your Cards:" <<endl;
    PrintCard(PlayerCards);
    cout << endl;
    cout << "Dealer's Cards:" << endl;
    PrintCard(DealerCards);
    cout << endl;
    // Boolean variable answer was used to capture HitOrStand()'s output.
    // HitOrStand() function captured user's input to hit or stand.
    bool answer;
    answer = HitOrStand();
    ifstream fin;
    fin.open("OtherData/topspeed.txt");
    // If the topspeed.txt does not exist, then we print File error
    if (fin.fail()) {
      cout << "File error" <<endl;
      exit(1);
    }
    // get fin value as temp
    string temp;
    fin >> temp;
    fin.close();
    

    double Topspeed = atof(temp.c_str());
    double BestTime = 10000;
    while (true) {
      cout << "You have 15 seconds to complete the question !!" << endl;
      // generated the question and prompt for user's input in MathQuestion() function.
      double duration = MathQuestion();
      // In MathQuestion(), the function only return 0 when the user's answer is false.
      if (duration != 0) {
        // If the time exceeds 15 second, then the user will lose.
        if (duration > 15) {
          cout << "You ran out of time (" << duration << "s)" << endl;
          cout << "You lose :(" << endl;
          cout << "The winner is Dealer" << endl;
          sign = 1;
          break;
        }
        // if the duration variable are lower than BestTime, then we record BestTime as duration.
        if (duration < BestTime) {
          BestTime = duration;
        }
        // If the user chooses stand, then we break the while loop.
        if (!answer) {
          // if the value of sign is 0, then the game has not ended.
          sign = 0;
          break;
        }
        // Otherwise, the user chooses "Hit" and we add user's card, and we sort it after that.
        ShareCard(UsedCards, PlayerCards);
        sorted(PlayerCards);
        cout << "Your Cards:" << endl;
        // Then we print player's cards
        PrintCard(PlayerCards);
        cout << endl;
        // Detect CardsValue of PlayerCards for Bust condition
        if ( CardsValue(PlayerCards) > 21 ) {
          system("sleep 1");
          cout << "Your cards are bust" << endl;
          cout <<"You lose :(" << endl;
          cout << "The winner is Dealer" << endl;
          // This means the game ends and break the while loop
          sign = 1;
          break;
        }
        // Otherwise, we request user's input to hit or stand until they input "Stand"
        answer = HitOrStand();
      }
      // if the duration is 0, then the user answered wrong, therefore we end the game
      else {
        cout << "Your calculation is wrong" << endl;
        cout << "You lose :(" << endl;
        sign = 1;
        break;
      }
    }
    // If the sign is 0, meaning that the game still continues
    if (sign == 0) {
      // we pop_back the "Back.txt"/ -1 value of DealerCards
      DealerCards.pop_back();
      //inside DealerMove, there will be share card for the dealer, and print the cards
      DealerMove(UsedCards, DealerCards, PlayerCards);
      // Printing Dealer and Player's cards 
      cout << "Your cards' value is " << CardsValue(PlayerCards) << endl;
      cout << "Dealer's cards value is " << CardsValue(DealerCards) << endl;
      // If the value of PlayerCards exceed the value of DealerCards or the DealerCards' value was bust, then Player won 
      if (CardsValue(PlayerCards) > CardsValue(DealerCards) || CardsValue(DealerCards) > 21) {   
        if (CardsValue(PlayerCards) == 21) {
          cout << "BlackJack!!" << endl;
        }
        cout <<"Congratulations!! You have emerged victorious"<<endl;
      }
      else if (CardsValue(PlayerCards) == CardsValue(DealerCards)) {
        cout <<"Game Tied, your cards have the same value as the dealer's"<<endl;
      }
      else {
        cout <<"You lose :("<<endl;
        cout << "The winner is Dealer"<<endl;
      }
    }
    // If the BestTime was not the default 10000.
    if (BestTime != 10000) {
      // Then if BestTime was bigger than Topspeed, then user has not beaten the record.
      if (BestTime >= Topspeed) {
        cout << "You have not beaten the record" << endl;
        cout << "The record is " << Topspeed << "s" << endl;
      }
      // If the BestTime has lower value than Topspeed, then the user set a new record.
      else if (BestTime < Topspeed) {
        cout << "Wow, you have set a new record" << endl;
        system("sleep 1");
        cout << "Your record is " << BestTime << "s" << endl;

      }
    }
    system("sleep 2");
    // If Topspeed beat the BestTime, then we print the Topspeed on topspeed.txt
    if (Topspeed > BestTime) {
      ofstream fout("OtherData/topspeed.txt");
      if (fout.fail()) {
        cout << "Error in file opening" << endl;
        exit(1);
      }
      fout << BestTime;
      fout.close();
    }
    ans = "test";
    // We preset the ans as "test", then we prompt user's input to ans,
    // then if it is not 'y' or 'n' or "rules", then we simply ask user's input with while loop. 
    while (ans != "y" && ans != "n"){
      ifstream fiin;
      cout << "Do you want to play again? (Y/N/RULES): ";
      cin >> ans;
      for_each(ans.begin(), ans.end(), [] (char &c) {
      c = tolower(c);
      });
      string rules;
      if (ans == "rules") {
        fiin.open("OtherData/Rules.txt");
        while(getline(fiin, rules)) {
          cout << rules <<endl;
        }
        cout <<endl;
      }
      fiin.close();
    }
  }
  cout <<"BYE BYE :)"<<endl;
  return 0;

}
