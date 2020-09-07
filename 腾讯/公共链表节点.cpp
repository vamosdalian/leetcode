#include "include.h"

using namespace std;

//获取一个数字
template <typename T>
T getNum(){
    T result = 0;
    string str;
    bool isFushu = false;
    getline(cin, str);
    for(int i = 0; i < str.size(); ++i){
        if(str[i] == '-'){
            isFushu = true;
            continue;
        }
        if(str[i]>='0' && str[i] <= '9'){
            result = isFushu? result*10 - str[i] + '0' : result*10 + str[i] - '0';
        }
    }
    return result;
}

//获取一维数组
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

vector<int> gonggongbufen(vector<int> nums1, vector<int> nums2){
    int i = 0, j = 0;
    vector<int> result;
    while(i < nums1.size() && j < nums2.size()){
        if(nums1[i] == nums2[j]){
            result.push_back(nums1[i]);
            i++;
            j++;
        }else if(nums1[i] > nums2[j]){
            i++;
        }else{
            j++;
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int size1 = getNum<int>();
    vector<int> nums1 = getNums<int>();
    int size2 = getNum<int>();
    vector<int> nums2 = getNums<int>();
    vector<int> nums = gonggongbufen(nums1, nums2);
    for(auto num : nums){
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
