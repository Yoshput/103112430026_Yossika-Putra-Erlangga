#ifndef STACK_H

#define MaxEl 20
#define Nil -1

#include <iostream>
using namespace std;

typedef int infotype;
struct Stack{
    infotype info[MaxEl];
    int top;
};

void CreateStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype X);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif