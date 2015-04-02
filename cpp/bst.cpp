using namespace std;
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(){
	BST *root = (BST *)malloc(sizeof(BST));
	root->data = 50;
	insert(&root,40);
	insert(&root,55);
	insert(&root,53);
	insert(&root,22);
	insert(&root,20);
	insert(&root,19);
	insert(&root,10);
	insert(&root,5);
	insert(&root,23);
	insert(&root,38);
	insert(&root,24);
	inOrder(root);
	cout<<"LCA: " << lowestCommonAncestor(root,5,24)<<"\n";
	return 1;
}

int insert(BST **node, int data){
	if(data == (*node)->data){
		return 0;
	} 
	if((*node)->children[data>(*node)->data]){
		return insert(&(*node)->children[data>(*node)->data],data);
	} else {
		//BST *child = (BST *) malloc(sizeof(BST));
		((*node)->children[data>(*node)->data]) = (BST *) malloc(sizeof(BST));
		((*node)->children[data>(*node)->data])->data = data;
		return 1;
	}
}

void inOrder(BST * node){
	if(node->children[0]) inOrder(node->children[0]);
	cout << "Data: "<<node->data<<"\n";
	if(node->children[1]) inOrder(node->children[1]);
}

int lowestCommonAncestor(BST * root, int val1, int val2){
	if(root->data > val1 && root->data > val2){
		return lowestCommonAncestor(root->children[0],val1,val2);
	} else if(root->data < val1 && root->data < val2){
		return lowestCommonAncestor(root->children[1],val1,val2);
	} else {
		return root->data;
	}
}
