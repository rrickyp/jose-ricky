#include <iostream>
#include <fstream>
using namespace std;

int random_card(){


};

void initial_card(int player[5], int dealer[5]){
  int i =0;
  while(i < 2){
    player[i] = random_card();
    dealer[i] = random_card();
    i++;
  }

}

int main() {
  ifstream fin;
  fin.open("ASCII-NERD.txt");
  string welcome;
  while (getline(fin, welcome)){
    cout << welcome << endl;
    
  //
  initial_card();


  }
}
