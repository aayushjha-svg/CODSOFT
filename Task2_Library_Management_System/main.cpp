#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Book
{
public:
    string title;
    string author;
    string isbn;
    bool issued = false;
};

vector<Book> library;

void loadBooks();
void saveBooks();

void addBook();
void viewBooks();
void searchBook();

void issueBook();
void returnBook();

void deleteBook();

void dashboard();


void saveBooks()
{
    ofstream file("books.txt");

    for(Book b : library)
    {
        file << b.title << "|"
             << b.author << "|"
             << b.isbn << "|"
             << b.issued << endl;
    }

    file.close();
}

void loadBooks()
{
    ifstream file("books.txt");

    if(!file)
        return;

    string line;

    while(getline(file,line))
    {
        stringstream ss(line);

        Book b;

        string status;

        getline(ss,b.title,'|');
        getline(ss,b.author,'|');
        getline(ss,b.isbn,'|');
        getline(ss,status);

        b.issued = (status=="1");

        library.push_back(b);
    }

    file.close();
}
void addBook()
{
    Book b;

    cin.ignore();

    cout << "\nEnter Book Title : ";
    getline(cin,b.title);

    cout << "Enter Author Name : ";
    getline(cin,b.author);

    cout << "Enter ISBN : ";
    getline(cin,b.isbn);

    // Duplicate ISBN Check
    for(Book book : library)
    {
        if(book.isbn == b.isbn)
        {
            cout << "\nBook with this ISBN already exists.\n";
            return;
        }
    }

    library.push_back(b);

    saveBooks();

    cout << "\nBook Added Successfully.\n";
}

void viewBooks()
{
    if(library.empty())
    {
        cout << "\nNo Books Available.\n";
        return;
    }

    cout << "\n========== BOOK LIST ==========\n";

    for(int i=0;i<library.size();i++)
    {
        cout << "\nBook " << i+1 << endl;

        cout << "Title : " << library[i].title << endl;
        cout << "Author : " << library[i].author << endl;
        cout << "ISBN : " << library[i].isbn << endl;

        if(library[i].issued)
            cout << "Status : Issued\n";
        else
            cout << "Status : Available\n";
    }
}

void searchBook()
{
    int choice;

    cin.ignore();

    cout << "\nSearch By\n";
    cout << "1. Title\n";
    cout << "2. Author\n";
    cout << "3. ISBN\n";

    cout << "Enter Choice : ";
    cin >> choice;

    cin.ignore();

    string key;

    cout << "Enter Search Value : ";
    getline(cin,key);

    bool found = false;

    for(Book b : library)
    {
        if((choice==1 && b.title==key) ||
           (choice==2 && b.author==key) ||
           (choice==3 && b.isbn==key))
        {
            cout << "\nBook Found\n";

            cout << "Title : " << b.title << endl;
            cout << "Author : " << b.author << endl;
            cout << "ISBN : " << b.isbn << endl;

            if(b.issued)
                cout << "Status : Issued\n";
            else
                cout << "Status : Available\n";

            found = true;
        }
    }

    if(!found)
        cout << "\nBook Not Found.\n";
}


void issueBook()
{
    cin.ignore();

    string isbn;

    cout << "Enter ISBN : ";
    getline(cin,isbn);

    for(Book &b : library)
    {
        if(b.isbn==isbn)
        {
            if(b.issued)
            {
                cout << "\nBook Already Issued.\n";
            }
            else
            {
                b.issued = true;
                saveBooks();
                cout << "\nBook Issued Successfully.\n";
            }

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}


void returnBook()
{
    cin.ignore();

    string isbn;

    cout << "Enter ISBN : ";
    getline(cin,isbn);

    for(Book &b : library)
    {
        if(b.isbn==isbn)
        {
            if(!b.issued)
            {
                cout << "\nBook is already available.\n";
            }
            else
            {
                b.issued = false;
                saveBooks();
                cout << "\nBook Returned Successfully.\n";
            }

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}
void deleteBook()
{
    cin.ignore();

    string isbn;

    cout << "Enter ISBN : ";
    getline(cin,isbn);

    for(int i=0;i<library.size();i++)
    {
        if(library[i].isbn==isbn)
        {
            library.erase(library.begin()+i);

            saveBooks();

            cout << "\nBook Deleted Successfully.\n";

            return;
        }
    }

    cout << "\nBook Not Found.\n";
}
void dashboard()
{
    int available = 0;
    int issued = 0;

    for(Book b : library)
    {
        if(b.issued)
            issued++;
        else
            available++;
    }

    cout << "\n========== DASHBOARD ==========\n";

    cout << "Total Books : " << library.size() << endl;
    cout << "Available Books : " << available << endl;
    cout << "Issued Books : " << issued << endl;
}
int main()
{
    loadBooks();

    int choice;

    do
    {
        cout << "\n========== LIBRARY MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Issue Book\n";
        cout << "5. Return Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Dashboard\n";
        cout << "8. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: issueBook(); break;
            case 5: returnBook(); break;
            case 6: deleteBook(); break;
            case 7: dashboard(); break;
            case 8: cout << "\nThank You!\n"; break;
            default: cout << "\nInvalid Choice!\n";
        }

    } while(choice != 8);

    return 0;
}

