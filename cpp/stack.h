typedef struct elementT {
	int data;
	struct elementT *next;
} element;

int push (element **head, int data);
element *pop(element **head);
void printStack(element *head);
