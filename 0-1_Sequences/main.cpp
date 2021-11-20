#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;

static const int DIVISOR = 1000000007;

// Brute force

int long long get_inverses(string str){
    int long long inverses = 0;
    int ones = 0;
    for(int i = str.length() - 1; i >= 0; --i){
        if (str[i] == '1'){
            inverses += (str.length() - i - 1 - ones);
            ++ones;
        }
    }
    return inverses % DIVISOR;
}

int long long recursion(string str, string ch){
    int index = str.find("?");
    str.replace(index, 1, ch);
    if (count(str.begin(), str.end(), '?') == 0){
        return get_inverses(str);
    } else {
        return recursion(str, "0") + recursion(str, "1");
    }
}

// Fast solution
vector<long long int> vec = {1};

long long int power(int base, int exponent){
    if (exponent < 0) {
        return 0;
    }
    if (exponent <= vec.size()-1){
        return vec[exponent];
    } else {
        while (exponent > vec.size()-1){
            long long int new_element = base*vec.back();
            vec.push_back(new_element % DIVISOR);
        }
    }
    return vec[exponent];
}

int traverse(string str){
    long long int inverses = 0;
    int zeros = 0;
    int marks = 0;
    for(int i = str.length() - 1; i >= 0; --i){
        if (str[i] == '0') {
            ++zeros;
        } else {
            if (str[i] == '?'){
                long long int add = (inverses + zeros * power(2, marks) + marks * power(2, marks - 1)) % DIVISOR;
                inverses += add;
                ++marks;
            } else {
                long long int add = (zeros * power(2, marks) + marks * power(2, marks - 1)) % DIVISOR;
                inverses += add;
            }
        }
    }
    return inverses % DIVISOR;
}

int main(){
    string str;
    cin >> str;
    cout << traverse(str) << endl;
    // Brute force
    /*
    if (count(str.begin(), str.end(), '?') == 0){
        cout << get_inverses(str) << endl;
    } else {
        cout << recursion(str, "?") << endl;
    }
    // */
    return 0;
}