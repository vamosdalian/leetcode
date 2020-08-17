#include "include.h"

#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<vector<int> > result;
    vector<int> tmp(2,0);
    // int count = 0;
    for(int i = N; i >= 1; i--){
        string str = to_string(i);
        reverse(str.begin(),str.end());
        int j = atoi(str.c_str());
        if(i / j== 4 && i % j == 0){
            tmp[0] = j;
            tmp[1] = i;
            result.push_back(tmp);
        }
    }
    cout << result.size()<<endl;
    for(auto item :result){
        cout << item[0]<< " "<< item[1]<<endl;
    }
    return 0;
}