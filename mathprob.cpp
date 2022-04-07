#include <iostream>
#include <cstdlib>
using namespace std;

double random_operator(int first, int second, int three){
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
        return first / second;
    }
    if( temp_rand > 7 && temp_rand <= 9){
        cout << first << " * " << second << " * " << three << endl;
        return first * second * three;
    }
    return 0;
}

int main(){
    //Initialize random seed.
    srand(time(NULL));

    //Initialize random 2 numbers
    int rand_1 = rand() % 10 + 1;
    int rand_2 = rand() % 10 + 1;
    int rand_3 = rand() % 10 + 1;


    int true_ans = random_operator(rand_1, rand_2, rand_3);
    int user_answer;
    cin >> user_answer;

    // if the user's answer 
    if(user_answer == true_ans){
        cout << "User continue the game"<< endl;
        return true;
    }
    else{
        cout << "User Lost" << endl;
        return false;
    }

    return 0;
}
