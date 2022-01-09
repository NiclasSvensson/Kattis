#include <iostream>

using namespace std;

// Extended Euclidean Algorithm
void extended_euclidean_algorithm(int64_t a, int64_t n, int64_t b, int64_t m){
    int64_t K = n*m;
    int64_t old_r = n;
    int64_t r = m;
    int64_t old_s = 1;
    int64_t s = 0;
    int64_t old_t = 0;
    int64_t t = 1;
    int64_t q, prov, x;
    while (r != 0){
        q = old_r / r;

        prov = r;
        r = old_r - q*prov;
        old_r = prov;

        prov = s;
        s = old_s - q*prov;
        old_s = prov;

        prov = t;
        t = old_t - q*prov;
        old_t = prov;
    }
    //x = (((b*n)%K)*(old_s)) + (((a*m)%K)*(old_t));
    x = b + (a - b)*((m*old_t)%K);
    x %= K;
    while (x < 0) x += K;
    cout << x << " " << K << endl;
}

int main(){
    int64_t T, a, n, b, m, x, K;
    cin >> T;
    for(int64_t i = 0; i < T; ++i){
        cin >> a >> n >> b >> m;
        K = n*m;
        extended_euclidean_algorithm(a, n, b, m);
    }
    return 0;
}