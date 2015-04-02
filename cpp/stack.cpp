using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main()
{
	element *stack = NULL;
	push(&stack,1);
	push(&stack,2);
	printStack(stack);
	element * elem = pop(&stack);
	if(elem != NULL){
		cout << "Popped: " << elem->data<<"\n";
	}
	free(elem);
	printStack(stack);
	return 1;
}

int push(element **stack, int data){
	if(!*stack){
		cout<<"Stack was null\n";
		*stack = (element *) malloc(sizeof(element));
		(*stack)->data = data;
		(*stack)->next = NULL;
		return 1;
	}
	element *nHead = (element *) malloc(sizeof(element));
	nHead->data = data;
	nHead->next = *stack;
	*stack = nHead;
	return 1;
}
element *pop(element **stack){
	if(!*stack){
		return NULL;
	}
	element * elem = *stack;
	*stack = (*stack)->next;
	return elem;
}

void printStack(element *head){
	while(head != NULL){
		cout << "Data: " << head->data << "\n";
		head = head->next;
	}
}
