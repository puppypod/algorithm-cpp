#include <iostream>
#include <vector>

using namespace std;

typedef struct Node* nodePointer;
typedef struct Node {
	nodePointer left = NULL;
	nodePointer right = NULL;
	int value;
} Node;


nodePointer makeNode(nodePointer node, int data) {
	if (node == NULL) { // 루트노드라면
		node = new Node();
		node->value = data;
		node->left = NULL;
		node->right = NULL;
	}
	else if (data < node->value) {
		node->left = makeNode(node->left, data);
	}
	else if (node->value < data) {
		node->right = makeNode(node->right, data);
	}
	return node;
}
// 후위 순회
void postOrder(nodePointer pointer) {
	if (pointer) {
		postOrder(pointer->left);
		postOrder(pointer->right);
		cout << pointer->value << '\n';
	}
}
int main()
{
	nodePointer root = NULL;
	int num = 0;
	while (1) {
		int tmp;
		cin >> tmp;
		if (cin.eof()) {
			break;
		}
		root = makeNode(root, tmp);
	}
	postOrder(root);
}