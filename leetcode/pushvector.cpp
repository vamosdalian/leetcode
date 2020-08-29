#include "include.h"

using namespace std;

class A
{
private:
    /* data */
public:
    A(/* args */);
    ~A();
};

A::A(/* args */)
{
    cout << "create"<<endl;
}

A::~A()
{
    cout <<"delete" << endl;
}


int main(int argc, char const *argv[])
{
    int a[6][9][6];
    for (size_t i = 0; i < 6; i++)
    {
        for (size_t j = 0; j < 9; j++)
        {
            for (size_t k = 0; k < 6; k++)
            {
                a[i][j][k] = i*54+j*6+k;
            }
            
        }
        
    }
    // cout << ***(a+736);
    
    return 0;
}
