#include"SeqList.h"
void SeqListInit(SeqList* p)				//初始化
{
	assert(p);
	p->array = (DataType*)malloc(sizeof(DataType) * 3);
	if (NULL == p->array)
	{
		assert(0);
		return;
	}
	else
	{
		p->capacity = 3;
		p->size = 0;
	}
}
void ChackCapacity(SeqList* p)				//检查容量
{
	int newcapacity = p->capacity * 2;
	if (p->size == p->capacity)
	{
		DataType *temp = (DataType*)malloc(sizeof(DataType)*newcapacity);
		if (NULL == temp)
		{
			assert(0);
			return;
		}
		else
		{
			memcpy(temp,p->array,p->size*sizeof(DataType));
			free(p->array);
			p->array = temp;
			p->capacity = newcapacity;
		}
	}
}
void SeqListPushBack(SeqList* p,DataType data)				//尾插
{
	assert(p);
	ChackCapacity(p);
	p->array[p->size] = data;
	p->size++;
}
void SeqListPopback(SeqList* p)				//尾删
{
	assert(p);
	if (0 == p->size)
	{
		return;
	}
	else
	{
		p->size--;
	}
}
void SeqListPushFront(SeqList* p,DataType Data)			//头插
{
	assert(p);
	ChackCapacity(p);
	int i = 0;
	if (p->size != 0)
	{
		for (i = p->size - 1; i >= 0; i--)
		{
			p->array[i + 1] = p->array[i];
		}
		p->array[0] = Data;
		p->size++;
	}
	else
	{
		p->array[p->size] = Data;
		p->size++;
	}
}
void SeqListPopFront(SeqList* p)			//头删
{
	assert(p);
	int i = 0;
	if (0 == p->size)
	{
		return;
	}
	else
	{
		for (i = 1; i < p->size; i++)
		{
			p->array[i-1] = p->array[i];
		}
		p->size--;
	}
}
void SeqListInsert(SeqList* p,int pos,DataType data)		//在pos位置插入一个数
{
	assert(p);
	if (pos >= 0 && pos <= p->size)
	{
		int i = 0;
		for (i = p->size; i > pos; i--)
		{
			p->array[i] = p->array[i - 1];
		}
		p->array[pos] = data;
		p->size++;
	}

}
void SeqListDelete(SeqList* p, int pos)					//删除pos位置的数
{
	assert(p);
	if (pos >= 0 && pos < p->size)
	{
		int i = 0;
		for (i = pos; i < p->size; i++)
		{
			p->array[i] = p->array[i+1];
		}
		p->size--;
	}
}
void SeqListDestroy(SeqList*p)
{
	assert(p);
	p->size = 0;
	p->capacity = 0;
	free(p->array);
	p->array = NULL;
}
int SeqListFind(SeqList* p, DataType data)
{
	assert(p);
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (data == p->array[i])
		{
			return i;
		}
	}
	return -1;
}
void SeqListRemove(SeqList* p, DataType data)//移除顺序表中第一个值为data的元素 
{
	assert(p);
	int i = 0;
	int pos = 0;
	for (i = 0; i < p->size; i++)
	{
		if (p->array[i] == data)
		{
			pos = i;
			for (i = pos; i < p->size; i++)
			{
				p->array[i] = p->array[i+1];
			}
			p->size--;
			break;
		}
			
	}	
}
int SeqListSize(SeqList *p)			//返回有效元素个数
{
	return p->size;
}
int SeqListCapacity(SeqList* p)			//返回内存
{
	return p->capacity;
}
int SeqListEmpty(SeqList *p)		//是否为空
{
	if (p->size == 0)
	{
		return 0; //0为空
	}
	else
		return 1;
}
DataType SeqListFront(SeqList *p)			//返回第一个元素
{
	return p->array[0];
}
DataType SeqListBack(SeqList* p)			//返回最后一个元素
{
	return p->array[p->size-1];
}
void SeqListRemoveAll(SeqList* p, DataType data)		//移除顺序表中所有值为data的元素 
{
	assert(p);
	int i = 0;
	int pos = 0;
	int count = 0;
	for (i = 0; i < p->size; i++)
	{
		if (p->array[i] == data)
			count++;
	}
	while (count)
	{
		for (i = pos; i < p->size; i++)
		{
			if (p->array[i] == data)
			{
				pos = i;
				for (i = pos; i < p->size; i++)
				{
					p->array[i] = p->array[i+1];
				}
				p->size--;
				break;
			}
		}
		
		count--;
	}
}