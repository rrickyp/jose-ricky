#include <iostream>
#include <cstdlib>
#include <chrono>
#include "mathprob.h"
#include <cmath>
using namespace std::chrono;
using namespace std;


// A logic function in generating user's input 
double random_operator(double first, double second, double three){
  // Initializing the random variable
  int temp_rand = rand() % 10;

  // Logic board of random number, each number was generated in the MathQuestion function via function argument
  // And then calculated, and returned the correct answer to the MathQuestion function
  if(temp_rand <= 3){
    cout << first << " + " << second << " + " << three<< endl;
    return first + second + three;
  }
  if( temp_rand > 3 && temp_rand <= 6){
    cout << first << " - " << second << " - " << three<< endl;
    return first - second - three;
  }
  if( temp_rand > 6 && temp_rand <= 9){
    cout << first << " * " << second << " * " << three << endl;
    return first * second * three;
  }
  return 0;
}

double MathQuestion(){
  // Initialize random seed.
  srand(time(NULL));

  // Initialize random 3 numbers
  double rand_1 = rand() % 10 + 1;
  double rand_2 = rand() % 10 + 1;
  double rand_3 = rand() % 10 + 1;

  // Generating the true answer
  double true_ans = random_operator(rand_1, rand_2, rand_3);
  double user_answer;

  // Calculating the time for users to answer the math problem
  auto start = high_resolution_clock::now();
  cin >> user_answer;
  auto stop = high_resolution_clock::now();

  // Substrating the start time and stop to have total duration, then convert it to double
  auto duration = duration_cast<microseconds>(stop - start);
  double duration_double = std::chrono::duration<double>(duration).count();

  // if the user's answer is true, then we return the duration, otherwise we return 0
  // the return would be processed further on the NerdblackJack.cpp file and if the user have the true answer
  // then it will print the duration, otherwise user will lose.
  if(user_answer == true_ans){
    cout << "User continue the game"<< endl;
    return duration_double;
  }
  else{
    cout << "User Lost" << endl;
    return 0;
  }
}
