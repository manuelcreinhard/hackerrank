#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
	public:
	int ch_count;
	int value;
	Node(int);
	vector<Node *> children;
};

Node::Node(int v){
	value = v;
	ch_count = 1;
}


class Tree {
	Node * root;
	public:
	Tree(int);
	~Tree();
	Node * findNode(Node*,int);
	void addTo(int,int);
	void print();
	int height();
	int getPairChildren();
	private:
	int heightSub(Node *);
	void printSub(Node *, int);
	int getPairChSub(Node *);
};

int Tree::height(){
	return heightSub(root);
}

int Tree::heightSub(){
	
}

int Tree::getPairChildren(){
	Node * n = root;
	int count = 0;
	for(vector<Node *>::iterator it = n->children.begin(); it != n->children.end();it++){
		count += getPairChSub(*it);
	}	
	return count;
}

int Tree::getPairChSub(Node * n){
	int count = 0;
	for(vector<Node *>::iterator it = n->children.begin(); it != n->children.end();it++){
		count += getPairChSub(*it);
	}
	if(n->ch_count != 0 && n->ch_count %2 == 0){
		count++;
	}
	return count;
}

void Tree::print(){
	printSub(root,0);
}

void Tree::printSub(Node * n, int spaces){
	cout << std::string(spaces*2, '*');
	cout << "Node: " << n->value << "\n";
	for(vector<Node *>::iterator it = n->children.begin(); it != n->children.end();it++){
		printSub(*it, spaces+1);
	}
}

Tree::Tree(int init) {
	root = new Node(init);
}

Node * Tree::findNode(Node * p,int n){
	if(p->value == n){
		return p;
	}
	for(vector<Node *>::iterator it = p->children.begin(); it != p->children.end();it++){
		Node * temp = *it;
		Node * r = findNode(temp,n);
		if(r != NULL){
			return r;
		}
	}
	return NULL;
}

void Tree::addTo(int v, int to){
	Node * toN = findNode(root,to);
	Node * n = new Node(v);
	if(toN != NULL){
		toN->children.push_back(n);
		toN->ch_count++;
	}
}

int main(){
	int v;
	int e;
	if( scanf("%d %d", &v, &e) != 2 ) 
	{
		fprintf( stderr, "Expected at least two numbers as input\n");
		exit(1);
	}
	
	v++;
	v--;
	int nv;
	int into;
	Tree * tr;
	
	for(int i = 0; i < e; i++){
		if(scanf("%d %d", &nv, &into) != 2){
			fprintf( stderr, "Expected at least two numbers as input\n");
			exit(1);
		}
		if(i == 0){
			tr = new Tree(into);
		}
		tr->addTo(nv,into);
	}
	tr->print();
	int pairs = tr->getPairChildren();
	cout << pairs << "\n";
	return 1;
}
