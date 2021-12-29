#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int32_t> MAP{
                       {'A', 0},{'B', 1},{'C', 2},
                       {'D', 3},{'E', 4},{'F', 5},
                       {'G', 6},{'H', 7},{'I', 8},
                       {'J', 9},{'K', 10},{'L', 11},
                       {'M', 12},{'N', 13},{'O', 12},
                       {'P', 11},{'Q', 10},{'R', 9},
                       {'S', 8},{'T', 7},{'U', 6},
                       {'V', 5},{'W', 4},{'X', 3},
                       {'Y', 2},{'Z', 1}
                      };

class circular_list{
    private:
        int32_t nr_A = 0;
        int32_t vertical_moves = 0;
        int32_t horizontal_moves = 1001;
        int32_t start = 0;
        int32_t start_a = 0, end_a = 0, longest_a = 0;
        string name;
    public:
        circular_list(string Name){
            name = Name;
            calculate_vertical_moves();
            if(vertical_moves == 0){
                horizontal_moves = 0;
                return;
            }
            if(nr_A == 0){
                horizontal_moves = (name.length() - 1);
                return;
            }
            name[start] = 's';
            calculate_horizontal_moves();
            reverse_name();
            calculate_horizontal_moves();
        }
        int32_t get_index(int32_t i){
            while(i < 0) i += name.length();
            return i % name.length();
        }
        void calculate_vertical_moves(){
            for(int32_t i = 0; i < name.length(); ++i){
                vertical_moves += MAP[name[get_index(i)]];
                if (name[get_index(i)] == 'A') nr_A += 1;
            }
        }
        void calculate_horizontal_moves(){
            int32_t i, j, a;
            i = 1; j = 1; a = 0;
            while(name[get_index(i)] != 's'){
                if(name[get_index(i)] == 'A'){
                    if(name[get_index(i - 1)] == 'A'){
                        a += 1;
                    } else {
                        j = i;
                        a += 1;
                    }
                } else if(name[get_index(i - 1)] == 'A') {
                    if(a > (j - 1) && 2*(j - 1) + (name.length() - i) < horizontal_moves){
                        horizontal_moves = 2*(j - 1) + (name.length() - i);
                    }
                    a = 0;
                }
                ++ i;
            }
            if (name.length() - a - 1 < horizontal_moves) horizontal_moves = name.length() - a - 1;
        }
        void reverse_name(){
            string inter = name;
            for(int32_t i = 1; i < name.length(); ++i){
                name[i] = inter[name.length() - i];
            }
        }
        int32_t get_result(){
            return vertical_moves + horizontal_moves;
        }
};

int32_t get_moves(string name){
    circular_list cl(name);
    return cl.get_result();
}

int main(){
    int32_t test_cases;
    string name;
    cin >> test_cases;
    for(int32_t i; i < test_cases; ++i){
        cin >> name;
        cout << get_moves(name) << endl; 
    }
    return 0;
}