//============================================================================
// Name        : Assignment_6.cpp
// Author      : Mayur Waghmare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


#define size 50
class node{
	node * next;
	int data;
public:
	node(int x){
		next=NULL;
		data=x;
	}
	friend class Stack;
	friend class Queue;
};
class Stack{
    int top;
    node* s[size];
    public:
    Stack(){
        top=-1;
    }
    void push(node* x)
    {
		if(top<size){
		  top=top+1;
		  s[top]=x;
		}
		else{
			cout<<"Stack is full"<<endl;
		}
		}

node* pop()
{
 node* c;
  c=s[top];
  top=top-1;
  return c;



}

int isfull()
{
  if(top==size-1)
  return 1;
  else
  return 0;
}

int isempty()
{
  if(top==-1)
  return 1;
  else
  return 0;
}
node* top_(){
if(isempty()){
cout<<"Stack Underflow"<<endl;
}
node* c=s[top];
return c;
}

    friend class Graph;
};

class Queue{
int front,rear;
node * arr[size];
public:
Queue(){
front = rear = -1;
}

bool isEmpty(){
if (front == -1 && rear == -1){
return true;
}
return false;
}

bool isFull(){
if ((front == 0 && rear == size - 1) || (front == rear + 1)){
return true;
}
return false;
}

void enqueue(node * obj){
if (isFull()){
cout << "The queue is full" << endl;

}
else if (isEmpty()){
front = rear = 0;
arr[rear] = obj;
}
else{
rear++;
arr[rear] = obj;
}
}

node * dequeue(){
	if (isEmpty()){
	cout << "The queue is empty" << endl;
	cout << "Nothing to remove" << endl;
	return NULL;
	}
	else{
	node * temp = arr[front];
	front++;
	return temp;
	}
	}

	node *getfront(){
		return arr[front];
	}
	friend class Graph;
};

class linkedlist{
	node * start;
public:
	linkedlist(){
		start=NULL;
	}
	void ins_start(int x){
		node * temp=new node(x);
		if(start==NULL){
			start=temp;
			cout<<"Operation performed succesfully"<<endl;

		}
		else{
			temp->next=start;
			start=temp;
			cout<<"Operation performed succesfully"<<endl;
		}
	}
	void ins_last(int x){
		if(start==NULL){
			ins_start(x);
		}
		else{
			node * temp=start;
			node * ptr=new node(x);
			while(temp->next!=NULL){
				temp=temp->next;
			}
			temp->next=ptr;
			cout<<"Operation performed succesfully"<<endl;
		}
	}
	void ins_before(int val,int x){
		if(start==NULL){
			cout<<"No such checkpoint present"<<endl;
		}
		else if(start->data==val){
			ins_start(x);
			cout<<"Operation performed succesfully"<<endl;
		}
		else{
			node * temp=new node(x);
			bool flag=false;
			node * ptr=start;
			while(ptr->next!=NULL){
				if(ptr->next->data==val){
					temp->next=ptr->next;
					ptr->next=temp;
					flag=true;
					cout<<"Operation performed succesfully"<<endl;
					break;
				}
				ptr=ptr->next;
			}
			if(!flag){
				cout<<"No such checkpoint is present"<<endl;
			}
		}
	}
	void ins_after(int val,int x){
		if(start==NULL){
			cout<<"No such checkpoint present"<<endl;
		}
		else if(start->data==val){
			node * temp=new node(x);
			temp->next=start->next;
			start->next=temp;
			cout<<"Operation performed succesfully"<<endl;
		}
		else{
			node * temp=new node(x);
			bool flag=false;
			node * ptr=start;
			while(ptr!=NULL){
				if(ptr->data==val){
					temp->next=ptr->next;
					ptr->next=temp;
					flag=true;
					cout<<"Operation performed succesfully"<<endl;
					break;
				}
				ptr=ptr->next;
			}
			if(!flag){
				cout<<"No such checkpoint is present"<<endl;
			}
		}
	}
	void del_start(){
		if(start==NULL){
			cout<<"Linked list is empty"<<endl;
		}
		else{
		node * temp=start;
		start=start->next;
		delete(temp);
		cout<<"Operation performed succesfully"<<endl;
		}
	}
	void del_end(){
		if(start==NULL){
			cout<<"Linked list is empty"<<endl;
		}
		else{
			node * ptr=start;
			node * temp=start->next;
			while(temp->next!=NULL){
				ptr=ptr->next;
				temp=temp->next;
			}
			ptr->next=NULL;
			delete(temp);
			cout<<"Operation performed succesfully"<<endl;
		}
	}

	void display(){
		if(start==NULL){
			cout<<"Linked list is empty";
		}
		else{
		node * temp=start;

		while(temp!=NULL){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<endl;
		}
	}
	void del_at(int val){
		if(start==NULL){
			cout<<"No such checkpoint present"<<endl;
		}
		else if(start->data==val){
			del_start();
		}
		else{
			node * temp=start->next;
			bool flag=false;
			node * ptr=start;
			while(temp!=NULL){
				if(temp->data==val){
					ptr->next=temp->next;
					temp->next=NULL;
					delete(temp);
					flag=true;
					cout<<"Operation performed succesfully"<<endl;
					break;
				}
				ptr=ptr->next;
				temp=temp->next;
			}
			if(!flag){
				cout<<"No such checkpoint is present"<<endl;
			}
		}
	}

};
class Graph{
	node*start;
	linkedlist adjacency[size];
public:
	Graph(){
		start=NULL;

	}
	void insert(int x){

	}
};

int main() {

	return 0;
}
