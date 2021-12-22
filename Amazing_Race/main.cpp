#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class board {
    private:
        vector<vector<int16_t>> tasks;
        vector<int16_t> matrix;
        vector<int16_t> not_visited_tasks;
        int16_t max_time, number_tasks, max_points;
    public:
        board(int16_t n, int16_t T): tasks(n), matrix((n+2)*(n+2)), number_tasks(n), max_time(T), max_points(0){
            for(int16_t i = 0; i < n; ++i){
                int16_t p, t, d;
                cin >> p >> t >> d;
                tasks[i] = {p, t, d};
            }
            tasks.push_back({0,0,1400});
            tasks.push_back({0,0,max_time});
            int16_t value;
            for (int16_t y = 0; y < number_tasks + 2; ++y){
                for(int16_t x = 0; x < number_tasks + 2; ++x){
                    cin >> value;
                    matrix[(number_tasks + 2)*y + x] = value;
                }
            }
        }
        int16_t get_travel_time(int16_t to, int16_t from){
            return matrix[(number_tasks + 2)*from + to];
        }
        int16_t get_points(int16_t i){
            return tasks[i][0];
        }
        int16_t get_time(int16_t i){
            return tasks[i][1];
        }
        int16_t get_deadline(int16_t i){
            return tasks[i][2] != -1 ? tasks[i][2] : 1400;
        }
        void print_result(){
            cout << max_points << endl;
            for(int16_t i = 0; i < number_tasks; ++i){
                if(find(not_visited_tasks.begin(), not_visited_tasks.end(), i) != not_visited_tasks.end()){

                } else {
                    cout << i + 1 << " ";
                }
            }
        }
        // Brute force...
        void search(vector<int16_t> original, int16_t i, int16_t t, int16_t p){
            //cout << "Points: " << p << endl;
            //cout << "Time: " << t << endl;
            if(t > get_deadline(i) || t > max_time){
                //cout << "reached deadline" << endl;
                return;
            } else if(i == number_tasks + 1){
                //cout << "new high" << endl;
                if (p > max_points){
                    max_points = p;
                    not_visited_tasks = original;
                }
                return;
            }
            for(int16_t j = 0; j < original.size(); ++j){
                vector<int16_t> new_vector = original;
                new_vector.erase(new_vector.begin() + j);
                search(new_vector, original[j], t + get_time(i) + get_travel_time(original[j], i), p + get_points(original[j]));
            }
        }
        void print(){
            for(int16_t i = 0; i < number_tasks; ++i){
                cout << get_points(i) << " " << get_time(i) << " " << get_deadline(i) << endl;
            }
            for (int16_t y = 0; y < number_tasks + 2; ++y){
                for(int16_t x = 0; x < number_tasks + 2; ++x){
                    cout << get_travel_time(x, y) << " ";
                }
                cout << endl;
            }
        }
};

int main(){
    int16_t n, T;
    cin >> n >> T;
    board b(n, T);
    vector<int16_t> vec(n);
    for(int16_t i = 0; i < n; ++i){
        vec[i] = i;
    }
    vec.push_back(n + 1);
    b.search(vec, n, 0, 0);
    b.print_result();
    return 0;
}
