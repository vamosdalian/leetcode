#include "include.h"

using namespace std;

int GetFragment(string str) {
    // if(str.size() == 0) return 0;
    char tmp = ' ';
    int tmpCon = 0;
    int sum = 0;
    for(auto s : str){
        sum++;
        if(s != tmp){
            tmpCon ++;
            tmp = s;
        }
    } 
    return sum / tmpCon;
}

int main(int argc, char const *argv[])
{
    cout << GetFragment("aaabbaaac");
    return 0;
}
