#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> vec = {{-1,0}, {1,0}, {0, -1}, {0, 1}};

class square{
    public:
        char value;
        bool open = false;
        int segment = 0;
        square(char value): value(value){}
};

class map {
    private:
        int width, height;
        vector<square> matrix;
    public:
        map(int x, int y): width(x), height(y), matrix(height*width, 0){}
        void set(){
            string row;
            for(int y = 0; y < height; ++y){
                cin >> row;
                for(int x = 0; x < row.length(); ++x){
                    matrix[width*y + x] = row[x];
                }
            }
        }
        char get(int x, int y){
            return matrix[width*(y-1) + (x-1)].value;
        }
        void open(int x, int y){
            matrix[width*(y-1) + (x-1)].open = true;
        }
        bool is_open(int x, int y){
            return matrix[width*(y-1) + (x-1)].open;
        }
        void set_segment(int x, int y, int seg){
            matrix[width*(y-1) + (x-1)].segment = seg;
        }
        int get_segment(int x, int y){
            return matrix[width*(y-1) + (x-1)].segment;
        }
        void print(){
            for(int y = 0; y < height; ++y){
                for(int x = 0; x < width; ++x){
                    cout << matrix[width*y + x].segment;
                }
                cout << "\n";
            }
        }
        void search(int x, int y, char value, int seg){
            int ret = 0;
            if (x < 1 || y < 1 || x > width || y > height){
            } else if (is_open(x, y)){
            } else if (get(x, y) != value){
            } else{
                open(x, y);
                set_segment(x, y, seg);
                for (int i = 0; i < vec.size(); ++i){
                    search(x + vec[i][0], y + vec[i][1], value, seg);
                }
            }
        }
        void reset(){
            for(int y = 0; y < height; ++y){
                for(int x = 0; x < width; ++x){
                    matrix[width*y + x].open = false;
                }
            }
        }
};

int main(){
    // Read dimennsions
    int x, y;
    cin >> y >> x;
    // Read map
    map m(x, y);
    m.set();
    // Read number of tests
    int tests;
    cin >> tests;
    // Read test and perform it
    int r_1, c_1, r_2, c_2;
    for (int test = 0; test < tests; ++test){
        cin >> r_1 >> c_1 >> r_2 >> c_2;
        if (m.get_segment(c_1, r_1) == 0){
            m.search(c_1, r_1, m.get(c_1, r_1), test + 1);
        } else if (m.get_segment(c_2, r_2) == 0){
            m.search(c_2, r_2, m.get(c_2, r_2), test + 1);
        }
        if(m.get_segment(c_1, r_1) == m.get_segment(c_2, r_2)) {
            if (m.get(c_1, r_1) == '0'){
                cout << "binary" << endl;
            } else {
                cout << "decimal" << endl;
            }
        } else {
            cout << "neither" << endl;
        }
    }
    return 0;
}