//============================================================================
// Name        : asg4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include <iostream>
using namespace std;

class Client{
	string name;
	long long telephone;
public:
	Client(){
		name = "";
		telephone = 0;
	}
	Client(string n, long long t){
		name = n;
		telephone = t;
	}
	string getName(){
		return name;
	}
	long long getTele(){
		return telephone;
	}
	friend class Hash;
};

int num(long long x){
	return x % 10;
}

class Hash{
	Client hashArray[10];
	Client hashArray2[10];
public:
	Hash(){
		for(int i=0;i<10;i++){
			hashArray[i].name = "";
			hashArray[i].telephone = -1;
		}
		for(int i=0;i<10;i++){
			hashArray2[i].name = "";
			hashArray2[i].telephone = -1;
		}
	}
	void insert(string n, long long t){
		int index = num(t);
		int temp = index;
		if(hashArray[index].telephone == -1){
			hashArray[index].telephone = t;
			hashArray[index].name = n;
		}
		else{
			while(hashArray[index].telephone != -1){
				index += 1;
				if(index == temp){
					cout << ">> Hash Array is full." << endl;
					return;
				}
			}
			hashArray[index].name = n;
			hashArray[index].telephone = t;
		}
	}
	void insertfunc(string n, long long t){
		int index = num(t);
		int temp = index;
		if(hashArray2[index].telephone == -1){
			hashArray2[index].telephone = t;
			hashArray2[index].name = n;
		}
		else{
			while(hashArray2[index].telephone != -1){
				index += 1;
				if(index == temp){
					cout << ">> Hash Array is full." << endl;
					return;
				}
			}
			hashArray2[index].name = n;
			hashArray2[index].telephone = t;
		}
	}
	void insertWithReplacement(string n, long long t){
		int index = num(t);
		int i = index;
		if(hashArray2[i].telephone == -1){
			hashArray2[i].name = n;
			hashArray2[i].telephone = t;
			return;
		}
		else{
			if(num(hashArray2[i].telephone) == index){
				insertfunc(n,t);
			}
			else if(num(hashArray2[i].telephone) != index){
				Client obj = hashArray2[i];
				hashArray2[i].name = n;
				hashArray2[i].telephone = t;
				insertfunc(obj.getName(),obj.getTele());
			}
		}
	}
	void display(){
		for(int i=0;i<10;i++){
			if(hashArray[i].telephone != -1){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Name: " << hashArray[i].name << endl;
				cout << ">> Telephone: " << hashArray[i].telephone << endl;
				cout << "----------------------------------------------------" << endl;
			}
		}
	}
	void displayWithReplacement(){
		for(int i=0;i<10;i++){
			if(hashArray2[i].telephone != -1){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Name: " << hashArray2[i].name << endl;
				cout << ">> Telephone: " << hashArray2[i].telephone << endl;
				cout << "----------------------------------------------------" << endl;
			}
		}
	}
	void search(long long t){
		int index = num(t);
		for(int i=index;i<=10;i++){
			if(i == 10){
				cout << ">> Phone number not found in records." << endl;
				return;
			}
			else if(hashArray[i].telephone == -1){
				cout << ">> Phone number not found in records." << endl;
				return;
			}
			else if(hashArray[i].telephone == t){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Record of person found." << endl;
				cout << ">> Name of person: " << hashArray[i].name << endl;
				cout << ">> Number: " << hashArray[i].telephone << endl;
				cout << "----------------------------------------------------" << endl;
				return;
			}
		}
	}
	int searchCount(long long t){
		int index = num(t);
		int count = 0;
		for(int i=index;i<=10;i++){
			count++;
			if(i == 10){
				cout << ">> Phone number not found in records." << endl;
				return count;
			}
			else if(hashArray[i].telephone == -1){
				cout << ">> Phone number not found in records." << endl;
				return count;
			}
			else if(hashArray[i].telephone == t){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Record of person found." << endl;
				cout << ">> Name of person: " << hashArray[i].name << endl;
				cout << ">> Number: " << hashArray[i].telephone << endl;
				cout << "----------------------------------------------------" << endl;
				return count;
			}
		}
	}
	int searchCount2(long long t){
		int index = num(t);
		int count = 0;
		for(int i=index;i<=10;i++){
			count++;
			if(i == 10){
				cout << ">> Phone number not found in records." << endl;
				return count;
			}
			else if(hashArray2[i].telephone == -1){
				cout << ">> Phone number not found in records." << endl;
				return count;
			}
			else if(hashArray2[i].telephone == t){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Record of person found." << endl;
				cout << ">> Name of person: " << hashArray2[i].name << endl;
				cout << ">> Number: " << hashArray2[i].telephone << endl;
				cout << "----------------------------------------------------" << endl;
				return count;
			}
		}
	}
	void dele(long long t){
		int index = num(t);
		for(int i=index;i<=10;i++){
			if(i == 10){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Phone number not present." << endl;
				cout << "----------------------------------------------------" << endl;
				return;
			}
			else if(hashArray[i].telephone == t){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Record of person successfully deleted." << endl;
				cout << "----------------------------------------------------" << endl;
				int temp = num(hashArray[i].telephone);
				hashArray[i].telephone = -1;
				hashArray[i].name = "";
				i++;
				while(i<10 && num(hashArray[i].telephone) == temp){
					hashArray[i-1] = hashArray[i];
					i++;
				}
				hashArray[i-1].telephone = -1;
				hashArray[i-1].name = "";
				return;
			}
			else if(hashArray[i].telephone == -1){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Record of person not found." << endl;
				cout << "----------------------------------------------------" << endl;
				return;
			}
		}
	}
	void deleReplacement(long long t){
		int index = num(t);
		for(int i=index;i<=10;i++){
			if(i == 10){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Phone number not present." << endl;
				cout << "----------------------------------------------------" << endl;
				return;
			}
			else if(hashArray2[i].telephone == t){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Record of person successfully deleted." << endl;
				cout << "----------------------------------------------------" << endl;
				int temp = num(hashArray2[i].telephone);
				hashArray2[i].telephone = -1;
				hashArray2[i].name = "";
				i++;
				while(i<10 && num(hashArray2[i].telephone) == temp){
					hashArray2[i-1] = hashArray2[i];
					i++;
				}
				hashArray2[i-1].telephone = -1;
				hashArray2[i-1].name = "";
				return;
			}
			else if(hashArray2[i].telephone == -1){
				cout << "----------------------------------------------------" << endl;
				cout << ">> Record of person not found." << endl;
				cout << "----------------------------------------------------" << endl;
				return;
			}
		}
	}
	void CompareSearch(){
		long long int x;
		cout << ">> Enter phone number you wish to search: ";
		cin >> x;
		int withoutReplace = searchCount(x);
		int withReplace = searchCount2(x);
		cout << ">> Without Replacement count = " << withoutReplace << endl;
		cout << ">> With Replacement count = " << withReplace << endl;
	}
	void displayTable(Client arr[]){
		for(int i=0;i<10;i++){
			cout << (i+1) << ". " << arr[i].name << "\t" << arr[i].telephone << endl;
		}
	}
	void displayTables(){
		cout << "----------------------------------------------------" << endl;
		cout << "TABLE WITHOUT REPLACEMENT\n" << endl;
		displayTable(hashArray);
		cout << "----------------------------------------------------" << endl;
		cout << "TABLE WITH REPLACEMENT\n" << endl;
		displayTable(hashArray2);
		cout << "----------------------------------------------------" << endl;
	}
};

int main() {
	Hash obj;
	while(true){
		cout << "1. Insert details without replacement." << endl;
		cout << "2. Display details." << endl;
		cout << "3. Search a number." << endl;
		cout << "4. Delete a number." << endl;
		cout << "5. Insert details with replacement." << endl;
		cout << "6. Display with replacement." << endl;
		cout << "7. Compare the search efficiency." << endl;
		cout << "8. Display both tables." << endl;
		cout << "0. Exit." << endl;
		int choice;
		cout << ">> Make choice: ";
		cin >> choice;
		if(choice == 1){
			string name;
			cin.ignore();
			cout << ">> Enter name: ";
			getline(cin,name);
			long long t;
			cout << ">> Enter the telephone number: ";
			cin >> t;
			obj.insert(name,t);
		}
		else if(choice == 2){
			obj.display();
		}
		else if(choice == 3){
			cout << ">> Enter phone number to search: ";
			long long t;
			cin >> t;
			obj.search(t);
		}
		else if(choice == 4){
			cout << ">> Enter phone number to delete: ";
			long long t;
			cin >> t;
			obj.dele(t);
		}
		else if(choice == 5){
			string n;
			cout << ">> Enter the name of the person: " << endl;
			cin.ignore();
			getline(cin,n);
			long long t;
			cout << ">> Enter the number: " << endl;
			cin >> t;
			obj.insertWithReplacement(n,t);
		}
		else if(choice == 6){
			obj.displayWithReplacement();
		}
		else if(choice == 7){
			obj.CompareSearch();
		}
		else if(choice == 8){
			obj.displayTables();
		}
		else if(choice == 0){
			cout << ">> GoodBye!" << endl;
			break;
		}
		cout << "----------------------------------------------------" << endl;
	}
	return 0;
}
