#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define SQLIST_INIT_SIZE 100
#define SQLISTINCREMENT 10

typedef int Status;
typedef int ElemType;
typedef struct 
{
	ElemType *elem;
	int length;
	int listsize;
}SqList;

void Init_Sq(SqList *L);
Status Insert_Sq(SqList *L, int i, ElemType e);
ElemType GetElem_Sq(SqList *L, int i);
Status DeleteElem_Sq(SqList *L, int i);
Status Destroy_Sq(SqList *L);

void main()
{
	SqList L;
	//int i;
	Init_Sq(&L);
	Insert_Sq(&L, 1, 3);
	printf("The element is %d\n", GetElem_Sq(&L, 1));
	Insert_Sq(&L, 2, 4);
	printf("The element is %d\n", GetElem_Sq(&L, 2));
	DeleteElem_Sq(&L, 1);
	printf("The element is %d\n", GetElem_Sq(&L, 1));
	printf("The element is %d\n", GetElem_Sq(&L, 2));
	Destroy_Sq(&L);
}

void Init_Sq(SqList *L)
{
	L->elem = (ElemType *)malloc(SQLIST_INIT_SIZE * sizeof(ElemType));
	if (L->elem == NULL)
	{
		printf("Memory allocation is error!");
		exit(1);
	}
	L->length = 0;
	L->listsize = SQLIST_INIT_SIZE;
}

Status Insert_Sq(SqList *L, int i, ElemType e)
{
	ElemType *newbase;
	ElemType *p;
	ElemType *q;

	if (i < 1 || i > L->length + 1)
	{
		printf("The location that inserted is illegal!\n");
		return TRUE;
	}

	if (!(L->length < L->listsize))
	{
		newbase = (ElemType *)realloc(&L->elem, (L->length + SQLISTINCREMENT) * sizeof(ElemType));
	}

	p = &L->elem[i - 1];

	for (q = &L->elem[L->length - 1]; p <= q; q--)
	{
		*(q + 1) = *q;
	}

	*p = e;
	L->length++;
	return TRUE;
}

ElemType GetElem_Sq(SqList *L, int i)
{
	if (i < 1 || i > L->length)
	{
		return ERROR;
	}
	return L->elem[i - 1];
}

Status DeleteElem_Sq(SqList *L, int i)
{
	ElemType *p;
	int j;

	if (i < 1 && i > L->length)
	{
		printf("The site that store element is not exist!\n");
		return FALSE;
	}

	p = &L->elem[i - 1];

	for (j = i - 1; j < L->length - 1; j++)
	{
		*p = *(p + 1);
		p++;
	}
	L->length--;

	return TRUE;
}

Status Destroy_Sq(SqList *L)
{
	if (L->length < 1)
	{
		return FALSE;
	}
	free(L->elem);
	L->elem = NULL;
	return TRUE;
}
