#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue Q;
    createQueue(Q);

    cout << "------------------------" << endl;
    cout << " H - T \t| Queue info" << endl;
    cout << "------------------------" << endl;

    printInfo(Q);
    enqueue(Q, 7); printInfo(Q);
    enqueue(Q, 1); printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 4); printInfo(Q);
    enqueue(Q, 8); printInfo(Q); // tail muter
    dequeue(Q);    printInfo(Q);

    return 0;
}
