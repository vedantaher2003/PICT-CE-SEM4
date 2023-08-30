//============================================================================
// Name        : Linkedlistprerequisite.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;


class node{
	int data;
	node * next;
public:
	node(int x){
		data=x;
		next=NULL;
	}
	friend class linkedlist;
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
int main() {

	linkedlist l1;
	int choice;
	while(true){
		cout<<"Enter the operation you want to perform\n1.Insert element at start of linked list\n2.Insert element at last of linked list\n3.Insert node before given value\n4.Insert node after given value\n5.Delete node from the start of linked list\n6.Delete node from end of the linked list\n7.Display nodes of linked list\n8.Delete  a value\n9.Exit from the program"<<endl;
		cin>>choice;
		if(choice==9){
			cout<<"Thank you "<<endl;
			break;
		}
		int x;
		int val;
		switch(choice){
		case 1:

			cout<<"Enter data you want to insert: ";
			cin>>x;
			l1.ins_start(x);
			break;

		case 2:

			cout<<"Enter data you want to insert: ";
			cin>>x;
			l1.ins_last(x);
			break;
		case 3:

			cout<<"Enter data you want to insert: ";
			cin>>x;
			cout<<"Enter Value before you want to insert: ";

			cin>>val;
			l1.ins_before(val,x);
			break;
		case 4:

			cout<<"Enter data you want to insert: ";
			cin>>x;
			cout<<"Enter Value after you want to insert: ";

			cin>>val;
			l1.ins_after(val,x);
			break;
		case 5:
			l1.del_start();
			break;
		case 6:
			l1.del_end();
			break;

		case 7:
			cout<<"Linked list is as follows: "<<endl;
			l1.display();
			break;
		case 8:
			cout<<"Enter Value you want to delete: ";
			cin>>val;
			l1.del_at(val);
			break;

		default:
			cout<<"Invalid input!!"<<endl;
			break;
		}
	}

	return 0;
}
