#include <iostream.h>
#include <conio.h>

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinarySearchTree {
private:
    Node* root;

    Node* createNode(int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
    }

    Node* insertRecursively(Node* root, int val) {
	if (root == NULL) {
	    return createNode(val);
	}

	if (val < root->data) {
	    root->left = insertRecursively(root->left, val);
	} else if (val > root->data) {
	    root->right = insertRecursively(root->right, val);
	}

	return root;
    }

    void preorderRecursive(Node* root) {
	if (root != NULL) {
	    cout << root->data << " ";
	    preorderRecursive(root->left);
	    preorderRecursive(root->right);
	}
    }

    void inorderRecursive(Node* root) {
	if (root != NULL) {
	    inorderRecursive(root->left);
	    cout << root->data << " ";
	    inorderRecursive(root->right);
	}
    }

    void postorderRecursive(Node* root) {
	if (root != NULL) {
	    postorderRecursive(root->left);
	    postorderRecursive(root->right);
	    cout << root->data << " ";
	}
    }

    Node* findLargestNode(Node* root) {
	if (root->right == NULL) {
	    return root;
	}
	return findLargestNode(root->right);
    }

    Node* findSmallestNode(Node* root) {
	if (root->left == NULL) {
	    return root;
	}
	return findSmallestNode(root->left);
    }

    int countNodes(Node* root) {
	if (root == NULL) {
	    return 0;
	}
	return 1 + countNodes(root->left) + countNodes(root->right);
    }

public:
    BinarySearchTree() : root(NULL) {}

    void insert(int val) {
	root = insertRecursively(root, val);
    }

    void preorderTraversal() {
	cout << "Preorder Traversal: ";
	preorderRecursive(root);
	cout << endl;
    }

    void inorderTraversal() {
	cout << "Inorder Traversal: ";
	inorderRecursive(root);
	cout << endl;
    }

    void postorderTraversal() {
	cout << "Postorder Traversal: ";
	postorderRecursive(root);
	cout << endl;
    }

    void searchLargestNode() {
	Node* largest = findLargestNode(root);
	cout << "Largest Node: " << largest->data << endl;
    }

    void searchSmallestNode() {
	Node* smallest = findSmallestNode(root);
	cout << "Smallest Node: " << smallest->data << endl;
    }

    void countTotalNodes() {
	int count = countNodes(root);
	cout << "Total Nodes: " << count << endl;
    }
};


void main() {
clrscr();
    BinarySearchTree bst;
    int choice, value;

    do {
	cout << "\n1. Insert\n2. Preorder Traversal\n3. Inorder Traversal\n4. Postorder Traversal\n5. Search Largest Node\n6. Search Smallest Node\n7. Count Total Nodes\n8. Exit\nEnter choice: ";
	cin >> choice;

	switch (choice) {
	    case 1:
		cout << "Enter value to insert: ";
		cin >> value;
		bst.insert(value);
		break;
	    case 2:
		bst.preorderTraversal();
		break;
	    case 3:
		bst.inorderTraversal();
		break;
	    case 4:
		bst.postorderTraversal();
		break;
	    case 5:
		bst.searchLargestNode();
		break;
	    case 6:
		bst.searchSmallestNode();
		break;
	    case 7:
		bst.countTotalNodes();
		break;
	    case 8:
		cout << "Exit";
		break;
	    default:
		cout << "Invalid choice! Please enter a valid option." << endl;
	}

    } while (choice != 8);

    getch();

}