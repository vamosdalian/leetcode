#include "include.h"

using namespace std;

bool checkPassword(string str){
    if(str.size() < 8) return false;
    bool hasNum = false;
    bool hasDx = false;
    bool hasXx = false;
    bool hasTszf = false;
    for(auto c : str){
        if(c >= '0' && c <= '9'){
            hasNum = true;
        }else if(c >= 'a' && c <= 'z'){
            hasXx = true;
        }else if(c >= 'A' && c <= 'Z'){
            hasDx = true;
        }else if(c >= 32){
            hasTszf = true;
        }
    }
    if(hasTszf && hasDx && hasXx && hasNum){
        return true;
    }
    return false;
}


int main(int argc, char const *argv[])
{
    string str;
    while(getline(cin, str)){
        auto result = checkPassword(str);
        if(result){
            cout << "Ok" << endl;
        }else
        {
            cout << "Irregular password" << endl;
        }
        
    }
    return 0;
}
