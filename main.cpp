#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>
#include <regex>
#include <stdio.h>
using namespace std;

class Student
{
private:
    string name, course, email, phone, id;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deletes();
};

void Student::menu()
{
menustart:
    int choice;
    char ch;
    system("cls");
    cout << "\t\t\t-----------------------------------------" << endl;
    cout << "\t\t\t-------STUDENT MANAGEMENT PROGRAM--------" << endl;

    cout << "\t\t\t-----------------------------------------" << endl;
    cout << "\t\t\t\t\t1->Enter New Record." << endl;
    cout << "\t\t\t\t\t2->Display the Record." << endl;
    cout << "\t\t\t\t\t3->Modify the Record." << endl;
    cout << "\t\t\t\t\t4->Search a Record." << endl;
    cout << "\t\t\t\t\t5->Delete a Record." << endl;
    cout << "\t\t\t\t\t6->Exit." << endl;

    cout << "\t\t\t---------------------------" << endl;
    cout << "\t\t\tChoose Option:[1/2/3/4/5/6]" << endl;
    cout << "\t\t\t---------------------------" << endl;
    cout << "Enter Your Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            cout << "\n\t\t\t Add Another Student Record (Y/N): \n";
            cin >> ch;
        } while (ch == 'y' || ch == 'Y');
        break;
    case 2:
        display();
        cout << "Enter any character" << endl;
        getch();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deletes();
        break;
    case 6:
        exit(0);
    default:
        cout << "\n\t\t\t Invalid choice... Please Try Again..";
    }

    goto menustart;
}
void Student ::insert()
{
    system("cls");
    fstream file;
    cout << "\t\t\t-----------ADD STUDENT DETAILS------------\n"
         << endl;
    cout << "\t\t\tStudent Name:"
         << " ";
    cin >> name;
    cout << "\t\t\tStudent's ID:"
         << " ";
    cin >> id;
    cout << "\t\t\tStudent's Course:"
         << " ";
    cin >> course;
    cout << "\t\t\tStudent's Contact number:"
         << " ";
    cin >> phone;
    cout << "\t\t\tStudent's E-mail Address:"
         << " ";
    cin >> email;
    cout << "\t\t\t-------Record Added Successfully-------\n"
         << " ";

    file.open("Record.txt", ios::app | ios::out);
    file << " " << name << " " << id << " " << course << " " << phone << " " << email << "\n";
    file.close();
}

void Student::display()
{
    system("cls");
    fstream file;
    int count = 1;
    cout << "------------------------------------- STUDENT RECORD TABLE --------------------------------------------\n"
         << endl;
    file.open("Record.txt", ios::in);
    if (!file)
    {
        /* code */
        cout << "\n\t\t\tData Not Found!\n";
        file.close();
    }
    else
    {
        file >> name >> id >> course >> phone >> email;
        while (!file.eof())
        {
            cout << "\n\n\t\t\t Student No.: " << count++ << endl;
            cout << "\t\t\t Student's Name: " << name << endl;
            cout << "\t\t\t Student's ID: " << id << endl;
            cout << "\t\t\t Student's course: " << course << endl;
            cout << "\t\t\t Student's Contact no.: " << phone << endl;
            cout << "\t\t\t Student's Email Address: " << email << endl;
            file >> name >> id >> course >> phone >> email;
        }
        if (count == 0)
        {
            cout << "\n\t\t\tEmpty File!\n";
        }
    }
    file.close();
}

void Student::modify() // Modify Students Details
{
    system("cls");
    fstream file, files;
    string Id;
    int found = 0;

    cout << "-------------------------------------  MODIFY STUDENT DETAILS ------------------------------------------\n"
         << endl;
    file.open("Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tData Not Found!";
    }
    else
    {
        cout << "\nEnter ID of Student which you want to Modify: ";
        cin >> Id;
        files.open("record.txt", ios::app | ios::out);
        file >> name >> id >> course >> phone >> email;
        while (!file.eof())
        {
            if (Id != id)

                files << " " << name << " " << id << " " << course << " " << phone << " " << email << "\n";
            else
            {
                cout << "\n\t\t\tEnter Student's Name: ";
                cin >> name;
                cout << "\t\t\tEnter Student's Id.: ";
                cin >> id;
                cout << "\t\t\tEnter Course: ";
                cin >> course;

                cout << "\t\t\tEnter Contact No.: ";
                cin >> phone;
                cout << "\t\t\tEnter Email Id: ";
                cin >> email;
                files << " " << name << " " << id << " " << course << " " << phone << " " << email << "\n";
                found++;
                cout << "\n\n\t\t\t Modified Successfully!\n";
            }
            file >> name >> id >> course >> phone >> email;
            if (found == 0)
            {
                cout << "\n\n\t\t\t Data Not Found!\n";
            }
        }

        files.close();
        file.close();
        remove("Record.txt");
        rename("record.txt", "Record.txt");
    }
}
void Student::search() // search data of student
{
    system("cls");
    fstream file;
    int found = 0;
    cout << "------------------------------------- SEARCH STUDENT DATA ------------------------------------------\n"
         << endl;
    file.open("Record.txt", ios::in);
    if (!file)
    {

        cout << "\n\t\t\t No Match Found!\n";
    }
    else
    {
        string Id;

        cout << "\n Enter ID of Student Which You Want to Search: ";
        cin >> Id;
        file >> name >> id >> course >> phone >> email;
        while (!file.eof())
        {
            if (Id == id)
            {
                cout << "\n\t\t\tStudent's Name: "
                     << name << endl;
                cout << "\t\t\tStudent's Id.: "
                     << id << endl;
                cout << "\t\t\tStudent's Course: "
                     << course << endl;

                cout << "\t\t\tContact No.: "
                     << phone << endl;
                cout << "\t\t\tEmail Id: "
                     << email << endl;

                found++;
            }
            file >> name >> id >> course >> phone >> email;
        }
        if (found == 0)
        {
            cout << "\n\t\t\tData Not Found!\n";
        }
        file.close();
    }
}

void Student::deletes()
{
    system("cls");
    fstream file, files;
    int found = 0;
    string Id;

    cout << "------------------------------------- DELETE STUDENT DETAILS ------------------------------------------\n"
         << endl;
    file.open("Record.txt", ios::in);
    if (!file)
    {
        cout << "\n\t\t\tData Not Found!\n";
        file.close();
    }
    else
    {
        cout << "\nEnter ID of Student which you want Delete Data: ";
        cin >> Id;
        files.open("record.txt", ios::app | ios::out);
        file >> name >> id >> course >> phone >> email;
        while (!file.eof())
        {
            if (Id != id)
            {
                files << " " << name << " " << id << " " << course << " " << phone << " " << email << "\n";
            }
            else
            {
                found++;
                cout << "\n\t\t\tSuccessfully Deleted Data\n";
            }
            file >> name >> id >> course >> phone >> email;
        }
        if (found == 0)
        {
            cout << "\n\t\t\t Data Not Found!\n";
        }
        files.close();
        file.close();
        remove("Record.txt");
        rename("record.txt", "Record.txt");
    }
}
int main()
{
    Student program;
    program.menu();
    return 0;
}