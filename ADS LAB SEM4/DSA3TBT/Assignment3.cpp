//============================================================================
// Name        : ThreadedBST(A3).cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
using namespace std;

class Node{
	int data;
	Node *left,*right;
	bool lthread,rthread;

public:
	Node(){
		left = right = NULL;
		lthread = rthread = true;
	}

	Node (int val){
		data = val;
		left = right = NULL;
		lthread = rthread = true;
	}

	friend class TBT;
};

class TBT{

public:
	Node *root;
	TBT(){
		root = NULL;
	}

	Node *insertNode(Node *root, int key){
		Node *ptr = root;
		Node *parent = NULL;

		while (ptr != NULL){
			// If data already exists, return
			if (key == ptr->data){
				cout << "Duplicate key" << endl;
				return NULL;
			}
			parent = ptr;

			// Moving on left subtree
			if (key < ptr->data){
				if (ptr->lthread == false){
					ptr = ptr->left;
				}
				else{
					break;
				}
			}

			// Moving on right subtree.
			else{
				if (ptr->rthread == false){
					ptr = ptr->right;
				}
				else{
					break;
				}
			}
		}

		// Creating new Node
		Node *tmp = new Node;
		tmp->data = key;
		tmp->lthread = true;
		tmp->rthread = true;

		if (parent == NULL){
			root = tmp;
			tmp->left = NULL;
			tmp->right = NULL;
		}
		else if (key < (parent->data)){
			tmp->left = parent->left;
			tmp->right = parent;
			parent->lthread = false;
			parent->left = tmp;
		}
		else{
			tmp->left = parent;
			tmp->right = parent->right;
			parent->rthread = false;
			parent->right = tmp;
		}
		return root;
	}

	Node * inorderSuccessor(Node *ptr){
		if (ptr->rthread == true){
			return ptr->right;
		}

		ptr = ptr->right;
		while (ptr->lthread == false){
			ptr = ptr->left;
		}
		return ptr;
	}

	Node * inorderPredecessor(Node *ptr){
			if (ptr->lthread == true){
				return ptr->left;
			}

			ptr = ptr->left;
			while (ptr->rthread == false){
				ptr = ptr->right;
			}
			return ptr;
		}

	void inorder(Node *root){
		if (root == NULL){
			cout << "Tree is empty" << endl;
			return;
		}
		Node *ptr = root;
		while (ptr->lthread == false){
			ptr = ptr->left;
		}
		while (ptr != NULL){
			cout << ptr->data << " ";
			ptr = inorderSuccessor(ptr);
		}
	}

	void preorder(Node *root){
		if (root == NULL){
			cout << "Tree is empty" << endl;
			return;
		}
		Node *ptr = root;
		while (ptr != NULL){
			cout << ptr->data << "->";
			if (ptr->lthread == false){
				ptr = ptr->left;
			}
			else if (ptr->rthread == false){
				ptr = ptr->right;
			}
			else{
				while (ptr != NULL && ptr->rthread == true){
					ptr = ptr->right;
				}
				if (ptr != NULL){
					ptr = ptr->right;
				}
			}

		}
	}

	// Delete Cases
	Node * caseA(Node *root, Node *par, Node *ptr){
		// If Node to be deleted is root
		if (par == NULL){
			root = NULL;
		}

		else if (ptr == par->left){
			par->lthread = true;
			par->left = ptr->left;
		}
		else{
			par->rthread = true;
			par->right = ptr->right;
		}

		delete ptr;
		return root;
	}

	Node * caseB(Node *root, Node *par, Node *ptr){
		Node *child;
		if (ptr->lthread == false){
			child = ptr->left;
		}
		else{
			child = ptr->right;
		}

		if (par == NULL){
			root = child;
		}

		else if (ptr == par->left){
			par->left = child;
		}
		else{
			par->right = child;
		}

		// Find predecessor and successor
		Node *p = inorderPredecessor(ptr);
		Node *s = inorderSuccessor(ptr);

		if (ptr->lthread == false){
			p->right = s;
		}
		else{
			if (ptr->rthread == false){
				s->left = p;
			}
		}

		delete ptr;
		return root;

	}

	// Case C
	Node * caseC(Node *root, Node *par, Node *ptr){
		// Find in-order successor and its parent.
		Node *parsucc = ptr;
		Node *succ = ptr->right;

		while (succ->left != NULL){
			parsucc = succ;
			succ = succ->left;
		}

		ptr->data = succ->data;

		if (succ->lthread == true && succ->rthread == true){
			root = caseA(root, parsucc, succ);
		}
		else{
			root = caseB(root, parsucc, succ);
		}

		return root;
	}


	Node * DeleteNode(int deleteKey){
		Node *ptr = root;
		Node *parent = NULL;
		int found = 0;

		while (ptr != NULL){
			if (deleteKey == (ptr->data)){
				found = 1;
				break;
			}
			parent = ptr;

			if (deleteKey < ptr->data){
				if (ptr->lthread == false){
					ptr = ptr->left;
				}
				else{
					break;
				}
			}
			else{
				if (ptr->rthread == false){
					ptr = ptr->right;
				}
				else{
					break;
				}
			}
		}

		if (found == 0){
			cout << "Delete key not present in the tree" << endl;
		}

		else if (ptr->lthread == false && ptr->rthread == false){
			root = caseC(root, parent, ptr);
		}

		else if (ptr->lthread == false){
			root = caseB(root, parent, ptr);
		}

		else if (ptr->rthread == false){
			root = caseB(root, parent, ptr);
		}
		else{
			root = caseA(root, parent, ptr);
		}

		return root;
	}

};

int main() {
	TBT t;
	int n,inData;
	int choice;
	cout<<"Creating Threadwed binary search tree: "<<endl;
	cout << "Enter the number of elements: " << endl;
	cin >> n;
	for (int i = 0; i < n; i++){
		cout << "Enter number: " << endl;
		cin >> inData;
		t.root = t.insertNode(t.root, inData);
	}

	do{
		cout << "1. Insert element in Threaded Binary Search Tree" << endl;
		cout << "2. Perform In-order Traversal of Threaded BST" << endl;
		cout << "3. Perform Pre-order Traversal of Threaded BST" << endl;
		cout << "4. Delete an element from Threaded BST" << endl;
		cout << "5. Exit" << endl;
		cout << "Enter your choice: " << endl;
		cin >> choice;

		switch(choice){
		case 1:{
			cout << "Enter number to be inserted: " << endl;
			cin >> inData;
			t.root = t.insertNode(t.root, inData);
			break;
		}

		case 2:{
			cout << "In-order traversal: " << endl;
			t.inorder(t.root);
			cout << endl;
			break;
		}

		case 3:{
			cout << "Pre-order traversal: " << endl;
			t.preorder(t.root);
			cout << endl;
			break;
		}
		case 4:{
			int deleteItem;

			cout << "Before deleting, the in-order is : " << endl;
			t.inorder(t.root);
			cout << endl;

			cout << "Enter the number to be deleted" << endl;
			cin >> deleteItem;
			t.root=t.DeleteNode(deleteItem);

			cout << "After deleting, the in-order is : " << endl;
			t.inorder(t.root);
			cout << endl;
			break;
		}
		case 5:{
			cout << "Thank you for visiting" << endl;
			exit(0);
		}

		default:
			cout << "Invalid choice entered" << endl;
			cout << "Please re-enter your choice" << endl;
			cin >> choice;
	}
	}while(choice != 5);





	return 0;
}
