#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
int main() {
  ifstream fin;
  system("clear");
  fin.open("ASCII-NERD.txt");
  string welcome;
  while (getline(fin, welcome)){
    cout <<welcome<<endl;
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
  return 0;
}
