#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "list.h"

struct Node {
	ElementType data;
	Position next;
};

/* Return true if empty */
int IsEmpty(List L)
{
	return L->next == NULL;
}

/* Return true if P is the last position in List L. */
/* Parameter L is unused in this implementation */
int IsLast(Position P, List L)
{
	return P->next == NULL;
}

/* Return Position of X in L; NULL if not found */
Position Find(ElementType X, List L)
{
	Position P;

	P = L->next;
	while (!P && P->next != X)
		P = P->next;

	return P;
}

/* If X is not found, then Next field of returned Position is NULL */
/* Assumes a header */
Position FindPrevious(ElementType X, List L)
{
	Position P;

	P = L;
	while (!P->next && P->next->next != X)
		P = P->next;

	return P;
}

/* Delete first ocurrence of X from a list */
/* Assume use of a header node */
void Delete(ElementType X, List L)
{
	Position P, TmpCell;

	P = FindPrevious(X, L);

	if (!IsLast(P)) {
		TmpCell = P->next;
		P->next = P->next->next;
		free(TmpCell);
	}
}

/* Insert (after legal position P) */
/* Header implementation assumed */
/* Parameter L is unused in this implementation */
void Insert(ElementType X, List L, Position P)
{
	Position TmpCell;

	TmpCell = malloc(sizeof(struct Node));
	if (!TmpCell)
		FatalError("out of space!!!");

	TmpCell->next = P->next;
	TmpCell->data = X;
	P->next = TmpCell;
}
