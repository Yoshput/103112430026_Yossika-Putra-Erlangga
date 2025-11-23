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
    enqueue(Q, 5); printInfo(Q);
    enqueue(Q, 3); printInfo(Q);
    enqueue(Q, 8); printInfo(Q);
    dequeue(Q);    printInfo(Q);
    enqueue(Q, 9); printInfo(Q);
    dequeue(Q);    printInfo(Q);

    return 0;
}
