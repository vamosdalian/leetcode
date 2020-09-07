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

void addNum(int num, priority_queue<int> &low, priority_queue<int, vector<int>, greater<int> > & high)
{
    low.push(num);                                    

    high.push(low.top());                               
    low.pop();

    if (low.size() < high.size()) {                     
        low.push(high.top());
        high.pop();
    }
}

vector<int> getmid(vector<int> nums){
    priority_queue<int> low;                              
    priority_queue<int, vector<int>, greater<int> > high;   
    for(auto num : nums){
        addNum(num, low, high);
    }
    cout << low.top() << high.top() << endl;;
    int left = low.top();
    int right = high.top();
    vector<int> result;
    for(auto num : nums){
        if(num <= left){
            result.push_back(right);
        }else if(num >= right){
            result.push_back(left);
        }
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n = getNum<int>();
    vector<int> nums = getNums<int>();
    vector<int> result = getmid(nums);
    for(auto res : result){
        cout << res << endl;
    }
    return 0;
}
