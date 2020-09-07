#include "include.h"

using namespace std;

    
int question(int a, int b) {
    unordered_set<int> nums;
    for (int i = 0; i < 50; i++)
    {
        nums.insert(i * i);
    }
    for (int i = 0; i < 500; i++)
    {
        if(nums.find(i+a) != nums.end() && nums.find(i+b) != nums.end()){
            return i;
        }
    }
    
    
}

int main(int argc, char const *argv[])
{
    int a ,b;
    cin >> a >> b;
    cout << question(a,b);
    return 0;
}
