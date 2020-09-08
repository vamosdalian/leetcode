#include "include.h"

using namespace std;

//获取一维字符串组
vector<string> getStrings(char c = ' '){
    vector<string> result;
    string str;
    string tmpStr;
    getline(cin, str);
    if(str.size() == 0) return result;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == c){
            if(!tmpStr.empty()){
                result.push_back(tmpStr);
                tmpStr.clear();
            }
            continue;
        }
        tmpStr.push_back(str[i]);
    }
    result.push_back(tmpStr);
    return result;
}

int checkPassword(string password){
    // int result = 0;
    bool hasxx = false;
    bool hasdx = false;
    bool hasnum = false;
    bool hasfh = false;
    if(password.size() < 8 || password.size() > 120){
        return 1;
    }
    for(auto c : password){
        if(c >= '0' && c <= '9'){
            hasnum = true;
        }else if(c >= 'a' && c <= 'z'){
            hasxx = true;
        }else if(c >= 'A' && c <= 'Z'){
            hasdx = true;
        }else if(c >= 32 && c <= 126){
            hasfh = true;
        }
    }
    if(hasfh && hasnum && hasxx && hasdx){
        return 0;
    }
    return 2;
}

int main(int argc, char const *argv[])
{
    vector<string> inputs = getStrings();
    for(auto input : inputs){
        cout << checkPassword(input) << endl;
    }
    return 0;
}
