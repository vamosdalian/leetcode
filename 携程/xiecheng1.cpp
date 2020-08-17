#include "include.h"

#include <bits/stdc++.h>
using namespace std;

template <typename T>
vector<T> getNums(char c = ' '){
    vector<T> result;
    string str;
    T tmp = 0;
    bool minus = false;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            result.push_back(tmp);
            tmp = 0;
            minus = false;
            continue;
        }
        if(str[i] == '-'){
            minus = true;
            continue;
        }
        tmp = minus? tmp*10 - str[i] + '0' : tmp*10 + str[i] - '0';
    }
    result.push_back(tmp);
    return result;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p = m + n;
    if(m > 0 && n > 0) {
        m--;
        n--;
        while(n >= 0) {
            if(nums1[m] <= nums2[n]) {
                p--;
                nums1[p] = nums2[n];
                n--;
            } else {
                p--;
                nums1[p] = nums1[m];
                if(m > 0) {
                    m--;
                }
                // 补丁
                else {
                    for(int i = 0; i <= n; i++) {
                        nums1[i] = nums2[i];
                    }
                }
            }
        }
    }
    // 补丁 
    else {
        for(int i = 0; i < n; i ++) {
            nums1[i] = nums2[i];
        }
    }
}


int main(int argc, char const *argv[])
{
    vector<int> Bvec = getNums<int>(' ');
    vector<int> Cvec = getNums<int>(' ');
    merge(Bvec, Bvec.size(), Cvec, Cvec.size());
    cout << Bvec[Bvec.size() / 2] << endl;
    return 0;
}
