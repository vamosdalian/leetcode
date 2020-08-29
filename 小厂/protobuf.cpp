#include "include.h"

using namespace std;

void EtoI(string ext){
    
}

void ItoE(string str){
    int num = atoi(str.c_str());
    vector<unsigned char> nums;  
    while(num >0){
        nums.push_back(num % 128);
        num /= 128;
    }
    auto item = nums.begin();
    while(item != nums.end() - 1){
        *item = *item | 0x80;
        printf("0x%02x", *item);
        item++;
    }
    *item = *item | 0x00;
    printf("0x%02x", *item);

}

int main(int argc, char const *argv[])
{
    string input;
    cin >> input;
    if(input[0] == '0'){
        EtoI(input);
    }else{
        ItoE(input);
    }
    return 0;
}
