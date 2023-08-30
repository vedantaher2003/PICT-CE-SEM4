// Assignment - 11

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int Menu()
{
    int choice;
    cout << "\nEnter 1 to Add information of student in the file" << endl;
    cout << "Enter 2 to Delete file" << endl;
    cout << "Enter 3 to Display information of particular student" << endl;
    cout << "Enter 0 to Exit" << endl;
    cout << "Enter your choice : ";
    cin >> choice;
    return choice;
}

int main()
{

    cout << "Welcome to the program" << endl;

    fstream MyFile;

    int choice = Menu();
    while (choice != 0)
    {
        if (choice == 1)
        {
            int n;
            string name, rollno, division, address;
            MyFile.open("test.txt", ios::app);
            if (!MyFile)
            {
                cout << "\nThere is an error Opening the file..." << endl;
            }
            else
            {
                cout << "\nFile opened successfully for writing" << endl;
                cout << "Enter the number of students whosee data you want to add : ";
                cin >> n;
                for (int i = 1; i <= n; i++)
                {
                    cout << "\nEnter the Details of Student " << i << " : " << endl;
                    cout << "Name : ";
                    cin >> name;
                    cout << "Roll Number : ";
                    cin >> rollno;
                    cout << "Division : ";
                    cin >> division;
                    cout << "Address : ";
                    cin >> address;
                    MyFile << name << " " << rollno << " " << division << " " << address << endl;
                }
            }
            MyFile.close();
        }
        else if (choice == 2)
        {
            string deleteString;
            cout << "\nEnter DELETE to confirm the deletion of file : ";
            cin >> deleteString;
            if (deleteString == "DELETE")
            {
                remove("test.txt");
                cout << "The file was deleted successfully" << endl;
            }
            else
            {
                cout << "The file was not deleted" << endl;
            }
        }
        else if (choice == 3)
        {
            string displayName, record;
            cout << "\nEnter the name of the student whose information you want : ";
            cin >> displayName;
            MyFile.open("test.txt", ios::in);
            if (!MyFile)
            {
                cout << "\nThere is an error Opening the file..." << endl;
            }
            else
            {
                cout << "\nFile opened successfully for reading" << endl;
                while (getline(MyFile, record))
                {
                    if (record.substr(0, displayName.length()) == displayName)
                    {
                        cout << "Details of student whose name you entered : " << record << endl;
                        break;
                    }
                }
                MyFile.close();
            }
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "\nYou entered incorrect choice. Try again!" << endl;
        }
        choice = Menu();
    }

    cout << "\nThanks for using the program\n"
         << endl;

    return 0;
}