#include <iostream>
#include <vector>
#include <string>
using namespace std;
class PhoneBook
{
public:
    void addContact(vector<pair<string, string>> &contacts)
    {
    string Name;
    cout << "Enter the Name : ";
    getline(cin, Name);

    cout << "Enter the phone no : ";
    string phoneNo;
    getline(cin, phoneNo);

    contacts.push_back(make_pair(Name, phoneNo));
    cout << "Record added to list." << endl;
    }

   int searchByPhoneNo(vector<pair<string, string>> &contacts, int &index, bool displayResult)
   {
    string key;
    cout << "Enter the Phone number to be searched: ";
    cin.ignore(); // Fixes input issue
    getline(cin, key);
    displayResult = false;

    for (int i = 0; i < contacts.size(); i++)
    {
        if (key == contacts[i].second)
        {   displayResult = true;
            if (displayResult)
            { 
                cout << "Name: " << contacts[i].first << "   Phone Number : " << contacts[i].second << endl;
                cout << "Record found" << endl;
                 index = i;  // Set correct index
                 cout<<"Contact present at index is :";
                 return index;
                 cout<<endl;
            }
            
        }
    }

    // If no match is found
    if (displayResult ==false)
    {
        cout << "Record Not Found" << endl;
    }
    index = -1;
    return -1;  // Ensure a return value for all cases
    }

    int searchByName(vector<pair<string, string>> &contacts, int &index, bool displayResult)
    {
    string name;
    cout << "Enter the Name to be searched: ";
    cin.ignore(); 
    getline(cin, name);
    displayResult =false;

    for (int i = 0; i < contacts.size(); i++)
    {
        if (name == contacts[i].first)
        { displayResult = true;
            if (displayResult == true)
            {
                cout << "Name: " << contacts[i].first << "   Phone Number : " << contacts[i].second << endl;
                cout << "Record found" << endl;
                index = i;  // Set correct index
                cout<<"Contact  present at index is :";
                return index;
                cout<<endl;
            }
        }
    }

    // If no match is found
    if (displayResult == false)
    {
        cout << "Record Not Found" << endl;
    }
    index = -1;
    return -1;  // Ensure a return value for all cases
    }

    void searchContact(vector<pair<string, string>> &contacts, int &index, bool displayResult)
    {
       int choice;
       int res = -1;
       do{
           
            cout << "1. Search Contact by Phone number\n2. Search contact by Name\n0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                 searchByPhoneNo(contacts, index, displayResult);
                break;
            case 2:
                 searchByName(contacts, index, displayResult);
                break;
            case 0:
                cout << "Exiting search." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
                index = -1;
                break;
            }
        }while(choice != 0);
    }
    void updateByPhoneNo(vector<pair<string, string>> &contacts)
    {
        string key;
        cout << "Enter the phone no to be update :";
        cin.ignore(100, '\n');
        getline(cin, key);
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (key == contacts[i].second)
            {
                cout << "Name: " << contacts[i].first << "  Phone Number: " << contacts[i].second << endl;
                cout << "Record  found" << endl;
                string newPhoneNo;
                cout << "Enter the new Phone no to be updated :";
                getline(cin, newPhoneNo);
                contacts[i].second = newPhoneNo;
                cout << "Updated Successfully !!" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Records Not Found"<<endl;
        }
    }
    void updateByName(vector<pair<string, string>> &contacts)
    {
        string name;
        cout << "Enter the Name to be searched :";
        cin.ignore(100, '\n');
        getline(cin, name);
        bool found = false;
        for (int i = 0; i < contacts.size(); i++)
        {
            if (name == contacts[i].first)
            {
                cout << "Name: " << contacts[i].first << "  Phone Number: " << contacts[i].second << endl;
                cout << "Record  found" << endl;

                string newName;
                cout << "Enter the new name to be updated :";
                cin >> newName;
                contacts[i].first = newName;
                cout << "Updated Successfully !!" << endl;
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "Record not Found" << endl;
        }
    }
    void updateContact(vector<pair<string, string>> &contacts)
    {
        int choice;
        do
        {
            cout << "1. Update contact's phone number\n2. Update contact's name\n0. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;
            switch (choice)
            {
            case 1:
                updateByPhoneNo(contacts);
                break;
            case 2:
                updateByName(contacts);
                break;
            case 0:
                cout << "Exiting update." << endl;
                break;
            default:
                cout << "This is not either of the options" << endl;
            }
        } while (choice != 0);
    }
    void deleteContact(vector<pair<string, string>> &contacts)
    { 
        int index = -1;
        
        searchContact(contacts, index, false); // Call searchContact without displaying results
        if (index  != -1)
        {
            contacts.erase(contacts.begin() + index);
            cout << "Record deleted" << endl;
        }
        else
        {
            cout << "Record not found" << endl;
        }
    }
    void printContact(vector<pair<string, string>> &contacts)
    {
        for (int i = 0; i < contacts.size(); i++)
        {
            cout << "Name: " << contacts[i].first << "   Phone No: " << contacts[i].second << endl;
        }
    }
};

int main()
{
    PhoneBook phoneBook;
    vector<pair<string, string>> contacts;
    int index = -1 ;
    int choice;
    cout<<"PHONEBOOK.\n";
    do
    {
        cout << "1. Add Contact\n2. Search Contact\n3. Update Contact\n4. Delete Contact\n5. Print Contacts\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            phoneBook.addContact(contacts);
            break;
        case 2:
            phoneBook.searchContact(contacts, index,false); // Pass index as a reference
            break;
        case 3:
            phoneBook.updateContact(contacts);
            break;
            phoneBook.printContact(contacts);
            break;
        case 4:
            phoneBook.deleteContact(contacts);
            break;    
        case 5:
            phoneBook.printContact(contacts);
            break;
        case 0:
            cout << "Exiting the program." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 0);

    return 0;
}