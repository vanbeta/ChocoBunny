#ifndef BLACKWORKER_H
#define BLACKWORKER_H

#include <list>
#include <functional>
#include <mutex>

using namespace std;

class BlackWorker {
public:
    BlackWorker();
public:
    void run(function<int(int)> f);
    void reader(list<int>& list, mutex& mtx);
    void execute(list<int>& list, mutex& mtx, function<int(int)> f);
    void printer(list<int>& list, mutex& mtx);
private:
    list<int> myRawList;
    list<int> myFinishedList;
};

#endif // BLACKWORKER_H
