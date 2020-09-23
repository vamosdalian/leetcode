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
            myclass::myque.push(2);
            cout << "producer:" << 2 << endl;
            sleep(1);
        }
    }
    static void customer(){
        while(1){
            if(!myclass::myque.empty()){
                int i = myclass::myque.front();
                cout << "customer:" << i << endl;
                myclass::myque.pop();
            }
        }
    }
    void run(){
        thread t1(this->producer);
        thread t2(this->customer);
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
