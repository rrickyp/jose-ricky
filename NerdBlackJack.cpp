#include <iostream>
#include <fstream>
using namespace std;
int main() {
  ifstream fin;
  fin.open("ASCII-NERD.txt");
  string welcome;
  while (getline(fin, welcome)){
    cout <<welcome<<endl;

  }
}
