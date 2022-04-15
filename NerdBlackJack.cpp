#include <iostream>
#include <fstream>
#include <ctime>
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
  cout << "ARE YOU READY TO PLAY??(Y/N)";
  char ans;
  cin >> ans;
  if ((ans != 'Y')||(ans != 'y')) {
    return 0;
  }
  initial_card();
  return 0;
}
