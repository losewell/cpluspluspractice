#include <future>
#include <list>
#include <iostream>
#include <exception>
using namespace std;

// this endless loop will throw bad_alloc execption eventually.
void task1()
{
    list<int> v;
    while (true) {
        for (int i = 0; i < 1000000; ++i) {
            v.push_back(i);
        }
        cout.put('.').flush();
    }
}

int main()
{
    auto f1 = async(task1);

    cout << "\nwait for the end of task1: " << endl;
    try {
        f1.get();
    }
    catch(const exception& e) {
        cerr << "EXCEPTION: " << e.what() << endl;
    }
}
