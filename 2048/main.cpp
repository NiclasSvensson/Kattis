#include <iostream>
#include <vector>
#include <string>

using namespace std;

int WIDTH = 4;
// {dir_x, dir_y, start}
vector<vector<int>> VEC = {{-1,0,0}, {0,-1,0}, {1,0,3}, {0,1,3}};

class board {
    private:
        vector<int> matrix;
    public:
        board(): matrix(WIDTH*WIDTH, 0){
            int in;
            for (int y = 0; y < WIDTH; ++y){
                for (int x = 0; x < WIDTH; ++x){
                    cin >> in;
                    set(x, y, in);
                }
            }
        }
        void set(int x, int y, int value){
            matrix[WIDTH*y + x] = value;
        }
        int get (int x, int y){
            return matrix[WIDTH*y + x];
        }
        void print(){
            for(int y = 0; y < WIDTH; ++y){
                for(int x = 0; x < WIDTH; ++x){
                    cout << get(x,y) << " ";
                }
                cout << "\n";
            }
        }
        int add(int dir, int x, int y, int prev){
            if (x >= WIDTH || y >= WIDTH || x < 0 || y < 0){
                return prev;
            }
            if (get(x, y) == 0){
                return add(dir, x - VEC[dir][0], y - VEC[dir][1], prev);
            } else if (get(x, y) == prev) {
                set(x, y, 0);
                add(dir, x - VEC[dir][0], y - VEC[dir][1], 0);
                return 2*prev;
            } else {
                set(x, y, add(dir, x - VEC[dir][0], y - VEC[dir][1], get(x, y)));
                return prev;
            }
            //cout << get(x,y) << " ";
            //recursion(dir, x - VEC[dir][0], y - VEC[dir][1], 0);
        }
        void shift(int dir, int x, int y, int zeros){
            if (x >= WIDTH || y >= WIDTH || x < 0 || y < 0){
                return;
            }
            if(get(x, y) == 0){
                shift(dir, x - VEC[dir][0], y - VEC[dir][1], zeros + 1);
            } else {
                int inter = get(x, y);
                set(x, y, 0);
                set(x + zeros * VEC[dir][0], y + zeros * VEC[dir][1], inter);
                shift(dir, x - VEC[dir][0], y - VEC[dir][1], zeros);
            }
        }
        void slide(int dir){
            bool x_dir = VEC[dir][0] == 0 ? false : true;
            for (int i = 0; i < WIDTH; ++i){
                int x = x_dir ? VEC[dir][2] : i;
                int y = x_dir ? i : VEC[dir][2];
                add(dir, x, y, 1);
                shift(dir, x, y, 0);
                //cout << endl;
            }
        }
};

int main(){
    // Read input
    board b;
    int in;
    cin >> in;
    // Perform move
    b.slide(in);
    // Print
    b.print();
    return 0;
}