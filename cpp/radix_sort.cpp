#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

struct node {
	int value;
	struct node * next;
};

class List {
	struct node * head;
	struct node * tail;
    public:
    List();
    int insert(int);
    void insertNode(struct node *);
    struct node * getTail();
    struct node * pop();
    struct node * empty();
    void appendEnd(struct node *, struct node *);
    void radixSort(int); //I am passing the max value since I know it for this case. I could actually not pass it and just make 
                         //a helper function to get it.
    void printList();
};

List::List(){
	head = NULL;
	tail = NULL;
}
void List::insertNode(struct node * n){
	if(head==NULL){
		head = n;
		tail = n;
	} else {
		tail->next = n;
		tail = tail->next;
	}
}
int List::insert(int value){
	if(head == NULL){
		head = (node*)malloc(sizeof(node));
		head->value = value;
		head->next = NULL;
		tail = head;
		return 1;
	}
	tail->next = (node*)malloc(sizeof(node));
	tail->next->value = value;
	tail = tail->next;
	if(tail->value == value){
		return 1;
	}
	return 0;
}

struct node * List::getTail(){
	return tail;
}
struct node * List::pop(){
	if(head == NULL){
		return NULL;
	}
	struct node * h = head;
	head = head->next;
	h->next = NULL;
	return h;
}

struct node * List::empty(){
	struct node * h = head;
	head = NULL;
	tail = NULL;
	return h;
}

void List::appendEnd(struct node * head_, struct node * tail_){
	if(head_ == NULL){
		return;
	}
	if(head == NULL){
		head = head_;
		tail = tail_;
	} else {
		tail->next = head_;
		tail = tail_;
	}
}

void List::radixSort(int zeros){
	cout << "Radix sort started..." << endl;
	List buckets[10];
	struct node * holder;
	int val;
	int div = 1;
	for(int i = 0; i < zeros; i++){
		while((holder = pop()) != NULL){
			val = holder->value;
			buckets[(val/div)%10].insertNode(holder);
		}
		struct node * t_tail;
		for(int j = 0; j<10; j++){
			t_tail = buckets[j].getTail();
			holder = buckets[j].empty();
			appendEnd(holder,t_tail);
		}
		div*=10;
	}
}

void List::printList(){
	struct node * ptr = head;
	while(ptr != NULL){
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
}

int main() {
    int numbers; cin >> numbers;
    List mylist;
    int temp;
    int max = 0;
    int zeros = 0;
    while(numbers--){
		cin >> temp;
		mylist.insert(temp);
		if(temp > max){
			max = temp;
		}
	}
	cout << "Max was: " << max << endl;
	do{
		zeros++;
	} while(max/=10);
	cout << "Max has: " << zeros << " zeros" << endl;
	mylist.radixSort(zeros);
	mylist.printList();
    return 0;
}
