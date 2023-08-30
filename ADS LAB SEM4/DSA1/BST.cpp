//============================================================================
// Name        : BST.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<string.h>
using namespace std;

class node{
	string word;
	string meaning;
	node *lchild;
	node *rchild;
public:
	node(){
		word="";
		meaning="";
		lchild=NULL;
		rchild=NULL;
	}
	node(string word1, string meaning1){
		word=word1;
		meaning=meaning1;
		lchild=NULL;
		rchild=NULL;
	}
	friend class bst;
};

class bst{
	node *root;
public:
	int count=0;
	bst(){
		root=NULL;
	}
	node *getroot(){
		return root;
	}
	void insert(string w, string m){
		node *new1=new node(w,m);
		if(root==NULL){
			root=new1;
		}
		else{
			node *curr;
			node *parent;
			curr=root;
			parent=NULL;
			while(curr!=NULL){
				parent=curr;
				if(w<curr->word){
					curr=curr->lchild;
				}
				else{
					curr=curr->rchild;
				}
			}
			if(parent->word>w){
				parent->lchild=new1;
			}
			else{
				parent->rchild=new1;
			}
		}

	}
	void display(node *temp){
		if(temp!=NULL){
			display(temp->lchild);
			cout<<temp->word<<" "<<temp->meaning<<endl;
			display(temp->rchild);
		}
	}
	void reverse_display(node *temp){
		if(temp!=NULL){
			reverse_display(temp->rchild);
			cout<<temp->word<<" "<<temp->meaning<<endl;
			reverse_display(temp->lchild);
		}
	}
	bool search(string w, node *&curr1, node *&parent1){
		count=0;
		while(curr1!=NULL){
            count++;
			if(curr1->word==w){
				return true;
			}
			else{
				if(curr1->word>w){
					parent1=curr1;
					curr1=curr1->lchild;
				}
				else{
					parent1=curr1;
					curr1=curr1->rchild;
				}
            }
		}
		return false;
	}
	void update(string w, string m){
		node *curr;
		curr=root;
		while(curr!=NULL){
			if(curr->word==w){
				curr->meaning=m;
				return;
			}
			else{
				if(curr->word>w){
					curr=curr->lchild;
				}
				else{
					curr=curr->rchild;
				}
			}
		}
	}
//	void Delete1(node *&curr1, node *&parent1, node *&child1){
//		cout<<curr1->meaning<<endl;
//		if(curr1->lchild!=NULL){
//			child1=curr1->lchild;
//		}
//		else if(curr1->rchild!=NULL){
//			child1=curr1->rchild;
//		}
//		else{
//			child1=NULL;
//		}
//
//	}
	void Delete(string w_){
		node *curr;
		node *parent;
		node *child;
		curr=root;
		parent=NULL;
		child=NULL;
		if(!search(w_, curr, parent)){
			cout<<"Node not found"<<endl;
			return;
		}
		else{
			if(curr->lchild!=NULL && curr->rchild!=NULL){
				node *temp;
				temp=curr->rchild;
				while(temp->lchild!=NULL){
					parent=temp;
					temp=temp->lchild;
				}
				string wrd=temp->word;
				string mng=temp->meaning;
			    curr->word=wrd;
			    curr->meaning=mng;
			    curr=temp;
			    if(curr->lchild!=NULL){
			    	child=curr->lchild;
			    }
			    else if(curr->rchild!=NULL){
			    	child=curr->rchild;
			    }
			    else{
			    	child=NULL;
			    }
			}
			else{
				    if(curr->lchild!=NULL){
						child=curr->lchild;
					}
					else if(curr->rchild!=NULL){
						child=curr->rchild;
					}
					else{
						child=NULL;
					}
			}
		}
		if(w_<(parent->word)){
			parent->lchild=child;
		}
		else{
			parent->rchild=child;
		}
		delete(curr);
	}
};

int main() {
	bst b1;
	string w1,m1,w2;
	int ch;
	while(true){
		cout<<endl<<"Menu"<<endl;
		cout<<"1. Insert"<<endl;
		cout<<"2. Display"<<endl;
		cout<<"3. Reverse Display"<<endl;
		cout<<"4. Search"<<endl;
		cout<<"5. Update"<<endl;
		cout<<"6. Delete"<<endl;
		cout<<"7. Exit"<<endl;
		cout<<"Enter your choice: ";
		cin>>ch;
		switch(ch){
		case 1:
			cout<<"Enter word: ";
			cin>>w1;
			cout<<"Enter meaning: ";
			cin>>m1;
			b1.insert(w1, m1);
			break;
		case 2:
			b1.display(b1.getroot());
			break;
		case 3:
			b1.reverse_display(b1.getroot());
			break;
		case 4:
			cout<<"Enter word to be searched: ";
			cin>>w2;
			node *curr2;
			node *parent2;
			curr2=b1.getroot();
			parent2=NULL;
			if(b1.search(w2, curr2, parent2)){
				cout<<"Found!!"<<endl;
				cout<<"No. of comparisons: "<<b1.count<<endl;
			}
			else{
				cout<<"Not found!!"<<endl;
			}
			break;
		case 5:
			cout<<"Enter the word to be updated: ";
			cin>>w1;
			cout<<"Enter the new meaning: ";
			cin>>m1;
			b1.update(w1, m1);
			break;
		case 6:
			cout<<"Enter the word that you want to delete: ";
			cin>>w2;
			b1.Delete(w2);
			break;
		case 7:
			return 0;
			break;
		default:
			cout<<"Enter valid choice!!"<<endl;
			break;
		}
	}
	return 0;
}
