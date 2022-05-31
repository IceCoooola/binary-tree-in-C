#include"queue.h"

//typedef struct QueneNode
//{
//	QueueDataType data;
//	struct QueneNode* next;
//}QueneNode;
//
//typedef struct Quene
//{
//	QueneNode* head;
//	QueneNode* tail;
//}Q;

void initQueue(Q* q)
{
	assert(q);
	//initiate quene to size of element. 
	q->head = NULL;
	q->tail = NULL;
}

bool isEmptyQueue(Q* q)
{
	assert(q);
	//return true if quene is empty, return false if quene is not empty.
	return q->head == NULL;
}

void enQueue(Q* pq, QueueDataType x)
{
	assert(pq);
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	if (newnode == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}
void deQueue(Q* q)
{
	//delete one element from the front of quene
	assert(q);
	assert(!isEmptyQueue(q));

	if (q->head->next == NULL)
	{
		free(q->head);
		q->head = q->tail = NULL;
	}
	else
	{
		QueueNode* temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
}

QueueDataType getFrontQueue(Q* q)
{
	assert(q);
	assert(!isEmptyQueue(q));
	return q->head->data;
}

QueueDataType getBackQueue(Q* q)
{
	assert(q);
	assert(!isEmptyQueue(q));
	return q->tail->data;
}
void destroyQueue(Q* q)
{
	//delete all elements in quene
	while (q->head)
	{
		QueueNode* temp = q->head;
		q->head = q->head->next;
		free(temp);
	}
	q->tail = NULL;
}

int getQueueLength(Q* q)
{
	int size = 0;
	QueueNode* cur = q->head;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;
}