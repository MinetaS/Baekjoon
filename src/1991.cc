#include <cstdio>

struct Node {
	char data;
	Node *left, *right;

	Node () {
		data = -1;
		left = right = NULL;
	}

	Node(int data) {
		this->data = data;
		left = right = NULL;
	}
};

void preorder_traversal(struct Node *);
void inorder_traversal(struct Node *);
void postorder_traversal(struct Node *);

int main() {
	int n;
	struct Node nodes[26];

	scanf("%d", &n);
	getchar();

	for (int i=0 ; i<n ; i++)
		nodes[i] = Node(i+65);

	for (int i=0 ; i<n ; i++) {
		char parent, left, right;

		scanf("%c %c %c", &parent, &left, &right);
		getchar();

		if (left != '.') nodes[parent-65].left = &nodes[left-65];
		if (right != '.') nodes[parent-65].right = &nodes[right-65];
	}

	preorder_traversal(&nodes[0]);
	printf("\n");
	inorder_traversal(&nodes[0]);
	printf("\n");
	postorder_traversal(&nodes[0]);

	return 0;
}

void preorder_traversal(struct Node *node) {
	if (node == NULL) return;
	printf("%c", node->data);
	if (node->left != NULL) preorder_traversal(node->left);
	if (node->right != NULL) preorder_traversal(node->right);
}

void inorder_traversal(struct Node *node) {
	if (node == NULL) return;
	if (node->left != NULL) inorder_traversal(node->left);
	printf("%c", node->data);
	if (node->right != NULL) inorder_traversal(node->right);
}

void postorder_traversal(struct Node *node) {
	if (node == NULL) return;
	if (node->left != NULL) postorder_traversal(node->left);
	if (node->right != NULL) postorder_traversal(node->right);
	printf("%c", node->data);
}