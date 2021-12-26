#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int32_t modulo(int32_t number, int32_t divisor){
    number = number % divisor;
    while (number < 0){
        number += divisor;
    }
    return number;
}

int32_t get_base(int32_t number){
    if(number == 3) return 4;
    number -= 3;
    int32_t range = round(sqrt(number));
    int32_t min = number;
    for(int32_t i = 1; i <= range; ++i){
        if (number % i == 0){
            if (i < 4){
                if (number / i > 3) min = number / i;
            }
            else return i;
        }
    }
    if (min < 4) return 0;
    return min;
}

int main(){
    int32_t number, result;
    while(true){
        cin >> number;
        if (number == 0) break;
        result = get_base(number);
        if(result == 0) cout << "No such base" << endl;
        else cout << result << endl;
    }
    return 0;
}