#include <stdio.h>
#include <stdlib.h>

typedef struct elementT {
	int data;
	struct elementT *next;
} element;

int main()
{
  return 1;
}

int insert(element **head){
	element *newElem;
	newElem = (element *) malloc(sizeof(element));
	if(!newElem)
		return 0;
		
	newElem->next = *head;
	*head = newElem;
	return 1;
}

element *find(element *elem, int data){
	while(elem){
		if(elem->data == data){
			return elem;
		}
		elem = elem->next;
	}
	return NULL;
}

int deleteElement(element **head, element *del){
	element *elem = *head;
	if(del == *head){
		*head = elem->next;
		free(del);
		return 1;
	}
	while(elem){
		if(elem->next==del){
			elem->next = del->next;
			free(del);
			return 1;
		}
	}
	return 0;
}

void deleteList(element *head){
	element *next, *del;
	del = head;
	while(del){
		next = del->next;
		free(del);
		del = next;
	}
}

