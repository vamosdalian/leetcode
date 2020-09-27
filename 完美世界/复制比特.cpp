#include <iostream>
#include <vector>
#include <numeric>
#include <limits>

using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int replaceBits(int src, int dst, int bitIndex, int bitCount) {
    int mask = (int)pow(2,bitCount) - 1;
    int rightMask = (int)pow(2,bitIndex) - 1;
    src = src >> bitIndex;
    src = src & mask;
    int leftdst = dst >> (bitIndex + bitCount);
    int rightdst = dst & rightMask;
    dst = 0;
    dst = leftdst << bitCount;
    dst = dst | src;
    dst = dst << bitIndex;
    dst = dst | rightdst;
    return dst;
}
/******************************结束写代码******************************/


int main() {
    int res;
    

    int _src;
    cin >> _src;
    // cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _dst;
    cin >> _dst;
    // cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _bitIndex;
    cin >> _bitIndex;
    // cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    int _bitCount;
    cin >> _bitCount;
    // cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');


    
    res = replaceBits(_src, _dst, _bitIndex, _bitCount);
    cout << res << endl;
    
    return 0;

}

/*
45
83
1
3
*/

