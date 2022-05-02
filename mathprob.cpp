#include <iostream>
#include <cstdlib>
#include <chrono>
#include "mathprob.h"
#include <cmath>
using namespace std::chrono;
using namespace std;

// double math_time(){
//     auto start = high_resolution_clock::now();

//     auto stop = high_resolution_clock::now();
// } 

double random_operator(double first, double second, double three){
    int temp_rand = rand() % 10;
    if(temp_rand <= 3){
        cout << first << " + " << second << " + " << three<< endl;
        return first + second + three;
    }
    if( temp_rand > 3 && temp_rand <= 5){
        cout << first << " - " << second << " - " << three<< endl;
        return first - second - three;
    }
    if( temp_rand > 5 && temp_rand <= 7){
        cout << "Remember, only input 1 decimal point" << endl;
        cout << first << " : " << second << endl;
<<<<<<< HEAD
=======
        cout <<"Befol " <<first / second<<endl;
        first = ceil(first * 10.0) / 10.0;
        second = ceil(second * 10.0) / 10.0;
        cout << "After "<<first / second<<endl;
>>>>>>> 1a509f80d6b39d76d575de73def080ae23b17de0
        return first / second;
    }
    if( temp_rand > 7 && temp_rand <= 9){
        cout << first << " * " << second << " * " << three << endl;
        return first * second * three;
    }
    return 0;
}

double MathQuestion(){
    //Initialize random seed.
    
    srand(time(NULL));

    //Initialize random 2 numbers
    double rand_1 = rand() % 10 + 1;
    double rand_2 = rand() % 10 + 1;
    double rand_3 = rand() % 10 + 1;
    //generating the true answer
    double true_ans = random_operator(rand_1, rand_2, rand_3);
    double user_answer;
    auto start = high_resolution_clock::now();
    cin >> user_answer;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    double duration_double = std::chrono::duration<double>(duration).count();
    // double duration_double = double(duration);
    // if the user's answer 
    if(user_answer == true_ans){
        cout << "User continue the game"<< endl;
        return duration_double;
    }
    else{
        cout << "User Lost" << endl;
        return 0;
    }
}
