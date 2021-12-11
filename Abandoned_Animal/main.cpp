#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
    uint32_t nr_shops, nr_shop_items;
    cin >> nr_shops;
    vector<vector<string>> shops(nr_shops);
    cin >> nr_shop_items;
    for(int32_t j = 0; j < nr_shop_items; ++j){
        int32_t i; string S;
        cin >> i >> S;
        shops[i].push_back(S);
    }
    uint32_t items;
    cin >> items;
    stack<string> backward, forward;
    for(int32_t j = 0; j < items; ++j){
        string S;
        cin >> S;
        backward.push(S);
    }
    uint32_t push_idx = items;
    vector<int> indices_back(items, 0);
    for (int32_t j = nr_shops - 1; j >= 0; --j){
        for(int32_t k = 0; k < shops[j].size(); ++k){
            if(backward.empty()) break;
            if(find(shops[j].begin(), shops[j].end(), backward.top()) != shops[j].end()){
                --push_idx;
                forward.push(backward.top());
                indices_back[push_idx] = j;
                backward.pop();
            }
        }
    }
    vector<int> indices_forw(items, 1);
    for (int32_t j = 0; j < nr_shops; ++j){
        for(int32_t k = 0; k < shops[j].size(); ++k){
            if(forward.empty()) break;
            if(find(shops[j].begin(), shops[j].end(), forward.top()) != shops[j].end()){
                indices_forw[push_idx] = j;
                forward.pop();
                ++push_idx;
            }
        }
    }
    //for (int i = 0; i < items; ++i){
    //    cout << indices_forw[i] << " " << indices_back[i] << endl;
    //}
    if (!backward.empty()){
        cout << "impossible" << endl;
    } else if (indices_back == indices_forw){
        cout << "unique" << endl;
    } else {
        cout << "ambiguous" << endl;
    }
    return 0;
}