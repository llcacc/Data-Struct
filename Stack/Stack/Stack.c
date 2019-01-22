#include"Stack.h"
void StackInit(Stack* ps)
{
	assert(ps);
	ps->arry = (DataType*)malloc(sizeof(DataType) * 3);//初始长度为三
	ps->capacity = 3;
	ps->top = 0;
}
void ChackCapacity(Stack* ps)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		int newcapacity = ps->capacity * 2;
		DataType* t = (DataType*)malloc(sizeof(DataType)*newcapacity);
		if (NULL == t)
		{
			assert(0);
			return;
		}
		else
		{
			ps->capacity = newcapacity;
			memcpy(t, ps->arry, sizeof(DataType)*ps->top);
			free(ps->arry);
			ps->arry = t;
		}
	}
}
void StackPush(Stack* ps, DataType data)
{
	ChackCapacity(ps);
	ps->arry[ps->top] = data;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	ps->top--;
}
void StackDestory(Stack* ps)
{
	assert(ps);
	ps->capacity = 0;
	ps->top = 0;
	free(ps->arry);
	ps->arry = NULL;
}