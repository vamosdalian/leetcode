#include "include.h"

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
//获取多个数字
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
int method(){
    int n = getNum<int>();
    vector<int> one = getNums<int>(' ');
    vector<int> two = getNums<int>(' ');
    vector<bool> he(n,false);
    vector<int> time(n,0);
    time[0] = one[0];
    for(int i = 1;i < n ;i ++){
        if(time[i-1] + two[i] < one[i] && he[i] == false){
            he[i] = true;
            time[i] = time[i-1] + two[i];
        }else{
            time[i] = one[i];
        }
    }
    return accumulate(time.begin(),time.end(),0);

}

int main(){
    //dp
    int T = getNum<int>();
    for(int i = 0;i < T;i++){
        int time = method();
        int hour = time/3600+8;
        int minute = time %3600 /60;
        int second = time%60;
        if(time < 12){
            cout << hour <<":"<<minute<<":"<<second<<" am"<<endl;
        }else{
            cout << hour <<":"<<minute<<":"<<second<<" pm"<<endl;
        }
    }
    return 0;
}