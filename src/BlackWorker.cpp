#include "BlackWorker.h"

#include <iostream>
#include <unistd.h>

#include <thread>

using namespace std;

BlackWorker::BlackWorker() {
}

void BlackWorker::run(function<int(int)> f) {
    mutex mtx;

    thread threadReader  (&BlackWorker::reader , this, ref(myRawList), ref(mtx));
    thread threadExecute (&BlackWorker::execute, this, ref(myRawList), ref(mtx), f);
    thread threadPrinter (&BlackWorker::printer, this, ref(myFinishedList), ref(mtx));

    threadReader.detach();
    threadExecute.detach();
    threadPrinter.join();
}

void BlackWorker::reader(list<int>& list, mutex& mtx) {
    while (true) {
        int value;
        lock_guard<mutex> lock (mtx);
        cout << "I in reader" << endl;
        cin >> value;
        list.push_back(value);
        return;
    }
}

void BlackWorker::execute(list<int>& list, mutex& mtx, function<int(int)> f) {
    while (true) {
        lock_guard<mutex> lock (mtx);
//        cout << "I in execute" << endl;
        if (!list.empty()) {
            myFinishedList.push_back(f(list.front()));
            list.pop_front();
        }
    }
}

void BlackWorker::printer(list<int>& list, mutex& mtx){
    while (true) {
        lock_guard<mutex> lock (mtx);
//        cout << "I in printer" << endl;
        if (!list.empty()) {
            cout << "result = " << list.front() << endl;
            list.pop_front();
        }
    }
}
