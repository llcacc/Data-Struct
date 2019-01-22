#include"Stack.h"
int main()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	printf("%d\n", s.arry[s.top-1]);
	StackPush(&s, 2);
	printf("%d\n", s.arry[s.top-1]);

	StackPush(&s, 3);
	printf("%d\n", s.arry[s.top-1]);

	StackPush(&s, 4);
	printf("%d\n", s.arry[s.top-1]);

	StackPush(&s, 5);
	printf("%d\n", s.arry[s.top-1]);

	StackPop(&s);
	printf("%d\n", s.arry[s.top-1]);

	StackDestory(&s);
	system("pause");
	return 0;
}