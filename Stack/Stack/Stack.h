#include<stdlib.h>
#include<assert.h>
#include<string.h>
typedef int DataType;
typedef struct Stack
{
	DataType* arry;
	int capacity;
	int top;
}Stack;
void StackInit(Stack* ps);
void StackPush(Stack* ps,DataType data);
void StackPop(Stack* ps);
void StackDestory(Stack* ps);
