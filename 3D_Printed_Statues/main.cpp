#include <iostream>
#include <cmath>

using namespace std;

int power2(int exponent){
    int result = 1;
    for(int i = 0; i < exponent; ++i){
        result *= 2;
    }
    return result;
}

int calculate_days(int statues){
    int days = 1;
    while(power2(days) <= statues){
        ++ days;
    }
    days = days + (power2(days-1) == statues ? 0 : 1);
    return days;
}

int main(){
    //cout << power2(1) << endl;
    int input;
    cin >> input;
    cout << calculate_days(input) << endl;;
    return 0;
}