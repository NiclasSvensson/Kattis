#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <unordered_map>

using namespace std;

uint64_t calculate_ways(unordered_map<int32_t,uint64_t> &m, vector<int32_t> &v){
    uint64_t result = 0;
    int count = 0;
    for (int x = 0; x < v.size(); ++x){
        for (int y = count; y < v.size(); ++y){
            //cout << v[x] << ", " << v[y] << endl;
            //cout << m[v[x]] << ", " << m[v[y]] << endl;
            if (m.find(v[x] + v[y]) != m.end()){ //m.find(v[x] + v[y]) != m.end() //m[v[x] + v[y]] != 0
                if (v[x] == 0 && v[y] == 0){
                    result += (m[v[x]] < 3 ? 0 : m[v[x]]*(m[v[x]]-1)*(m[v[x]]-2));
                } else if (v[x] == 0 || v[y] == 0){
                    if (v[x] == 0 && m[v[y]] > 1){
                        result += 2*(m[v[x]] * m[v[y]] * (m[v[y]]-1));
                    } else if (v[y] == 0 && m[v[x]] > 1){
                        result += 2*(m[v[y]] * m[v[x]] * (m[v[x]]-1));
                    }
                } else if(v[x] == v[y]) {
                    result += (m[v[x]] * (m[v[x]]-1) * m[v[x] + v[y]]);
                } else {
                    result += 2*(m[v[x]] * m[v[y]] * m[v[x] + v[y]]);
                }
            }
            //cout << result << "\n---------" << endl;
        }
        ++ count;
    }
    return result;
}

int main(){
    // Read input
    int32_t amount;
    cin >> amount;
    unordered_map<int32_t, uint64_t> m;
    vector<int32_t> v;
    for(int32_t i = 0; i<amount; ++i){
        int32_t input;
        cin >> input;
        if (m.find(input) != m.end()) {
            m[input] ++;
        } else {
            m[input] = 1;
            v.push_back(input);
        }
    }
    cout << calculate_ways(m, v) << endl;
    return 0;
}