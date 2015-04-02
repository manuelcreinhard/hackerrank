typedef struct BST {
	int data;
	struct BST *children[2];
} BST;

int insert(BST **node, int data);
void inOrder(BST * node);
int lowestCommonAncestor(BST * root, int val1, int val2);
