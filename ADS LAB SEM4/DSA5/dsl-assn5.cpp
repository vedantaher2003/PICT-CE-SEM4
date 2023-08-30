#include <iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

class hash_node
{

	string Word;
	string Meaning;
	hash_node *next;
public:
	hash_node()
	{
		Word="----";
		Meaning="----";
		next=NULL;
	}
friend class HashTable;
};

class HashTable
{
	hash_node *HT[10];
    public:
	void createHT()
	{
		int i, Tablesize = 10;
		hash_node *Newnode;

		for(i=0; i<Tablesize; i++)
		{
			Newnode = new hash_node;
			HT[i] = Newnode;
		}
	}

    // void search()
    // {

    // }

	void displayHT()
	{
		int i, Tablesize = 10;
		hash_node *Newnode;

		cout<<"\nHash Table\n";
		for(i=0; i<Tablesize; i++)
		{
				Newnode = HT[i];
				cout<<"\n"<<i<<" : ";
				while(Newnode)
				{
					cout<<"("<<Newnode->Word<<": "<<Newnode->Meaning<<")-->";
					Newnode = Newnode->next;
				}

		}

	}
	int Hash(string word)
	{
		int i, Tablesize = 10;
		int sum = 0;
		for(i=0; word[i] != '\0'; i++)
			sum = sum + word[i];
		return sum % Tablesize;
	}
	void insertKey()
	{
		int i, cnt, index;
		string key;
		string value;
		hash_node *temp, *Newnode;

		cout<<"\n\n enter the number of entries: ";
		cin>>cnt;

		for(i=0; i<cnt; i++)
		{

			cout<<"\n\t Enter the Word: ";
			cin>>key;
			cout<<"\n\t Enter the Meaning: ";
			cin>>value;

			Newnode = new hash_node;

			Newnode->Word=key;
			Newnode->Meaning=value;
			Newnode->next = NULL;

			index = Hash(key);

			temp = HT[index];
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = Newnode;
		}
	}

};
int main()
{

	HashTable H1;
	H1.createHT();
	H1.displayHT();
	H1.insertKey();
	H1.displayHT();
	return 0;
}
