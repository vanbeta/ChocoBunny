#include <iostream>
#include <unistd.h>

#include "BlackWorker.h"

using namespace std;

int heavy(int n) {
    sleep(5);
    return n + 1;
}

int main() {
    BlackWorker black;
    black.run(&heavy);
    return 0;
}
