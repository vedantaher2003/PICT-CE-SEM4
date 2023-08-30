#include<iostream>
using namespace std ;
															// Queue class
template<class T>
class queue{
		T arr[20];
		int front;
		int rear;
	public:

		queue(){
			front=-1;
			rear=-1;
		}

		bool isfull(){
			if(rear==19){
				return true;
			}
			else{
				return false;
			}
		}

		bool isempty(){
			if(front==rear && rear==-1){
				return true;
			}
			else{
				return false;
			}
		}

		void push(T x){
			if(isfull()){
				cout<<"Queue is full"<<endl;
			}
			else if(isempty()){
				front++;
				rear++;
				arr[rear]=x;
			}
			else{
				rear++;
				arr[rear]=x;
			}
		}
		T pop(){
			if(isempty()){
				cout<<"Queue is empty"<<endl;
				return NULL ;
			}
			else if(front==rear){
				T res =  arr[front];
				front=-1;
				rear=-1;
				return res ;
			}
			else{
				T res  = arr[front];
				front=front+1;
				return res ;
			}
		}
};
															// Stack Class
template<class T>
class stack{
	int top;
	T arr[20];
public:
	bool isempty(){
		if(top==-1){
			return true;
		}
		return false;

	};
	bool isfull(){
		if(top==19){
			return true;
		}
		return false;
	};
	void push(T x){
		if(isfull()){
			cout<<"stack is full"<<endl;
		}
		else{
			top++;
			arr[top]=x;
		}
	}
	T pop(){
		if(isempty()){
			cout<<"Stack is empty"<<endl;
		}
		else{
			top--;
			return arr[top+1];
		}
	}

	stack(){
		top=-1;
	}

};

															// Node Class
class Node{
private :
	int data ;
	Node* lc ;
	Node* rc ;
public:
	Node(int data_){
		data = data_ ;
		lc = NULL ;
		rc = NULL ;
	}

	friend class BT ;
};
															// BST Class

class BT{
private:
	Node* root ;
public:
	BT(){
		root = NULL ;
	}
															// all itterative meathods ->
	void createItr(){
		queue <Node*> Q ;
		cout<<"Enter Root node value"<<endl;
		int temp ;
		cin>>temp ;
		Node* new_node = new Node(temp) ;
		root = new_node ;
		Q.push(new_node);
		while(!Q.isempty()){
			Node* retrive = Q.pop() ;
			cout<<"Enter the left child value of node child to "<<retrive->data<<endl ;
			cin>>temp ;
			if(temp != -1 ){
				Node * new_node = new Node(temp);
				retrive->lc = new_node ;
				Q.push(new_node);
			}
			cout<<"Enter the right child value of node child to "<<retrive->data<<endl ;
			cin>>temp ;
			if(temp != -1 ){
				Node * new_node = new Node(temp);
				retrive->rc = new_node ;
				Q.push(new_node);
			}
		}

	}

	void preItr(Node *n){
		stack<Node*> s ;
		s.push(n);
		Node* temp = NULL ;
		while(!s.isempty()){
			temp = s.pop();
			cout<<temp->data<<" ";
			if(temp->lc != NULL){
				s.push(temp->lc);
			}
			if(temp->lc != NULL){
				s.push(temp->lc);
			}
		}
	}
	void printPreItr(){
		preItr(root);
	}

	void inoItr(Node* n){
		stack<Node*> s ;
		s.push(n);
		Node* temp = n ;
		while(!s.isempty()){
			while( temp->lc!= NULL){
				s.push(temp->lc);
				temp = temp ->lc ;
			}
			temp = s.pop();
			cout<<temp->data<<" ";
			if(temp->rc!=NULL){
				temp = temp -> rc ;
			}
		}
	}
	void printInoItr(){
		inoItr(root);
	}

	void posItr(Node* n){
		stack<Node*> s1 ;
		stack<Node*> s2 ;
		Node* temp = n ;
		s1.push(n);
		while(!s1.isempty()){
			temp = s1.pop();
			s2.push(temp);
			if(temp->lc != NULL){
				s1.push(temp->lc);
			}
			if(temp->rc != NULL){
				s1.push(temp->rc);
			}
		}
		while(!s2.isempty()){
			temp = s2.pop();
			cout<<temp->data<<" ";
		}
	}
	void printPosItr(){
		posItr(root);
	}

															// all recursive meathods ->
	void createRecursive(){
		cout<<"Enter Root node value"<<endl;
		int temp ;
		cin>>temp ;
		Node* new_node = new Node(temp) ;
		root = new_node ;
		creater(new_node);

	}
	void creater(Node* giv){
			int temp1 ;
			cout<<"Enter the left child value of node child to "<<giv->data<<endl ;
			cin>>temp1 ;
			if(temp1 != -1 ){
				Node * new_node = new Node(temp1);
				giv->lc = new_node ;
				creater(new_node);
			}
			cout<<"Enter the right child value of node child to "<<giv->data<<endl ;
			cin>>temp1 ;
			if(temp1 != -1 ){
				Node * new_node = new Node(temp1);
				giv->rc = new_node ;
				creater(new_node);
			}
		}
	void  inorderR(Node* n){
			if(n != NULL){
				inorderR(n->lc);
				cout<<n->data<<endl ;
				inorderR(n->rc);
			}
		}
	void printIR(){
		inorderR(root);
	}
	void  postR(Node* n){
			if(n != NULL){
				postR(n->lc);
				postR(n->rc);
				cout<<n->data<<endl ;
			}
		}
	void printporR(){
		postR(root);
	}
	void  preR(Node* n){
			if(n != NULL){
				cout<<n->data<<endl ;
				preR(n->lc);
				preR(n->rc);
			}
		}
	void printpreR(){
		preR(root);
	}
};

int main(){
	BT L ;
	int menu,menu1,menu2 ;
	while(true){
		cout<<"\n\nSelect the meathod of procedure\n1)recursive\n2)itterative\n0)exit\n";
		cin>>menu ;
		if(menu == 1){
			while(true){
				cout<<"\n\nSelect the operation you want to perform\n1)creation\n2)transversal\n0)return to lastmenu\n";
				cin>>menu1 ;
				if(menu1 == 1){
					L.createRecursive();
				}
				else if (menu1 == 2){
					while(true){
						cout<<"Select the type of tranversal\n1)Preorder\n2)Inorder\n3)Postorder\n";
						cin>>menu2 ;
						if(menu2 == 1){
							L.printpreR();
						}
						else if(menu2 == 2 ){
							L.printIR();
						}
						else if(menu2 == 3){
							L.printporR();
						}
						else if(menu2 == 0 ){
							break ;
						}
						else{
							cout<<"Enter vaild option\n";
						}
					}
				}
				else if(menu1 == 0){
					break;
				}
				else {
					cout<<"enter vaild option\n";
				}
			}
		}
		else if(menu == 2){
			cout<<"\n\nSelect the meathod of procedure\n1)recursive\n2)itterative\n0)exit\n";
		cin>>menu ;
		if(menu == 1){
			while(true){
				cout<<"\n\nSelect the operation you want to perform\n1)creation\n2)transversal\n0)return to lastmenu\n";
				cin>>menu1 ;
				if(menu1 == 1){
					L.createItr();
				}
				else if (menu1 == 2){
					cout<<"Select the type of tranversal\n1)Preorder\n2)Inorder\n3)Postorder\n";
					cin>>menu2 ;
					if(menu2 == 1){
						L.printPreItr();
					}
					else if(menu2 == 2 ){
						L.printInoItr();
					}
					else if(menu2 == 3){
						L.printPosItr();
					}
					else{ 
						cout<<"Enter vaild option\n";
					}
				}
				else if(menu1 == 0){
					break;
				}
				else {
					cout<<"enter vaild option\n";
				}
			}
		}
		else if(menu == 0){
			break;
		}
		else{
			cout<<"Enter vaild option\n";
		}
	}
}
}

