#include "include.h"
#include "unistd.h"
#include "thread"

using namespace std;

class myclass{
private:
    static queue<int> myque;
public:
    myclass(/* args */);
    static void producer(){
        while(1){
            myque.push(2);
            cout << "producer:" << 2 << endl;
            sleep(1);
        }
    }
    static void customer(){
        while(1){
            if(!myque.empty()){
                int i = myque.front();
                cout << "customer:" << i << endl;
                myque.pop();
            }
        }
    }
    void run(){
        thread t1(producer);
        thread t2(customer);
        t1.join();
        t2.join();
    }
    ~myclass();
};

myclass::myclass(/* args */){
}

myclass::~myclass(){
}

int main(int argc, char const *argv[])
{
    myclass * model = new myclass();
    model->run();
    return 0;
}
