#include <iostream>
#include <vector>

using namespace std;

class matrix {
    private:
        int64_t N, C;
        vector<int64_t> mat;
        int64_t mod = 1000000007;
    public:
        matrix(int64_t N, int64_t C): N(N), C(C), mat(N*(C+1), 0) {
            set(1,0,1);
            for(int64_t n = 2; n <= N; ++n){
                for(int64_t c = 0; c <= C; ++c){
                    if (c == 0) {
                        set(n, c, 1);
                    } else {
                        set(n, c, get(n, c-1) + get(n-1, c) - get(n-1, c-n) + 2*mod);
                    }
                }
            }
        }
        void set(int64_t n, int64_t c, int64_t value){
            mat[(C+1)*(n-1) + c] = value % mod;
        }
        int64_t get(int64_t n, int64_t c){
            if (n < 1 || c < 0){
                return 0;
            } else {
                return mat[(C+1)*(n-1) + c];
            }
        }
        void print(){
            for(int64_t n = 1; n <= N; ++n){
                for(int64_t c = 0; c <= C; ++c){
                    cout << get(n, c) << " "; 
                }
                cout << endl;
            }

        }
};

int main(){
    int64_t N, C;
    cin >> N >> C;
    matrix mat(N, C);
    //mat.print();
    cout << mat.get(N, C);
    return 0;
}