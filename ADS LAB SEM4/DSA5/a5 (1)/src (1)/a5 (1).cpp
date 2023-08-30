//============================================================================
// Name        : Assignment_5.cpp
// Author      : Mayur Waghmare
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;
#define SIZE 10


class node{
	string name;
	string meaning;
	node * next;
public:
	node(string n,string m){
		name=n;
		meaning=m;
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
	void ins_start(string n,string m){
		node * temp=new node(n,m);
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
	void ins_last(string n,string m){
		node*newNode = new node(n, m);
		cout << "Name = " << newNode->name<< endl;
		cout << "Meaning = " << newNode->meaning<< endl;
		if (start== NULL){
		start = newNode;
		}
		else
		{
		node*temp = start;

		int duplicateKeyFound = 0;
		do {
		if (temp->name == n){
		cout << "Duplicate key " << n << " found!!" << endl;
		cout << "Replacing old value " << temp->meaning << " with new value " << m << endl;
		temp->meaning = m;
		duplicateKeyFound=1;
		break;
		}
		if (temp->next != NULL){
		temp = temp->next;
		if (temp->name == m){
		cout << "Duplicate key " << m << " found!!" << endl;
		cout << "Replacing old value " << temp->meaning << " with new value " << m << endl;
		temp->meaning = m;
		duplicateKeyFound=1;
		break;
		}
		}
		}while (temp->next != NULL);

		if (duplicateKeyFound != 1){
		temp->next = newNode;
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
			cout<<"NULL";
		}
		else{
		node * temp=start;

		while(temp!=NULL){
			cout<<"["<<temp->name<<","<<temp->meaning<< "]"<<"->";
			temp=temp->next;
		}

		}
	}
	void del_at(string val){
		if(start==NULL){
			cout<<"No such checkpoint present"<<endl;
		}
		else if(start->name==val){
			del_start();
		}
		else{
			node * temp=start->next;
			bool flag=false;
			node * ptr=start;
			while(temp!=NULL){
				if(temp->name==val){
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

	void LLsearch(string m){
		if(start==NULL){
			cout<<"No such Value is present "<<endl;
			return;
		}
		int i=0;
		node *temp=start;
		while(temp!=NULL){
			if(temp->name==m){
				cout<<"The required data is found at: "<<i+1<<"st/th Location"<<endl;
				return;
			}
			i++;
		}
		cout<<"No such Data present in the hash table"<<endl;

	}

	friend class HTable;

};
class HTable{
	linkedlist LL[SIZE];
public:
	HTable(){

	}

	int Hashfunc(string name){
		int hash=0;
		for(int i=0;i<name.length();i++){
			hash+=int(name[i]);
		}

		return hash%SIZE;
	}

	void insertHash(){
		cout<<"Enter the word and meaning you want to insert: "<<endl;
		cout<<"Enter word: ";
		string word,mean;
		cin>>word;
		cout<<"Enter meaning: ";
		cin>>mean;
		int key=Hashfunc(word);
		LL[key].ins_last(word, mean);
	}

	void searchHash(){
		cout<<"Enter the word you want to Search: "<<endl;
		cout<<"Enter word: ";
		string word;
		cin>>word;

		int key=Hashfunc(word);
		cout<<"In "<<key<<"th location :"<<endl;
		LL[key].LLsearch(word);
	}

	void deleteHash(){
		cout<<"Enter the word you want to Delete: "<<endl;
		cout<<"Enter word: ";
		string word;
		cin>>word;

		int key=Hashfunc(word);
		LL[key].del_at(word);
	}

	void displayHash(){
		cout<<"Index: \t[Words,Meaning]"<<endl;
		for(int i=0;i<SIZE;i++){
			cout<<i<<"\t";
			LL[i].display();
			cout<<endl;
		}
	}


};


int main() {
	HTable h1;
	int choice;
	while(true){
		cout<<"Enter the operation you want to perform: \n1.Insert Word and Meaning In hash table\n2.Search a word in Hash Table\n3.Display Hash Table \n4.Delete a word from Hash Table\n5.Exit from the program"<<endl;
		cin>>choice;
		if(choice==5){
			cout<<"Thank you"<<endl;
			cout<<endl;
			break;
		}
		switch(choice){
		case 1:
			h1.insertHash();
			cout<<endl<<endl;
			break;
		case 2:
			h1.searchHash();
			cout<<endl<<endl;
			break;
		case 3:
			h1.displayHash();
			cout<<endl<<endl;
			break;
		case 4:
			h1.deleteHash();
			cout<<endl<<endl;
			break;
		default:
			cout<<"Invalid choice"<<endl<<endl;
			break;

		}
	}
	return 0;
}
