#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
    bool isAvailable;

    void displayBook() {
        cout << "Book Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Book ID: " << id << endl;
        cout << "Availability: " << (isAvailable ? "Available" : "Not Available") << endl;
        cout << "-----------------------------------\n";
    }

    void addBook() {
        cout << "Enter Book Title: ";
        cin.ignore();
        getline(cin, title);

        cout << "Enter Author's Name: ";
        getline(cin, author);

        cout << "Enter Book ID: ";
        cin >> id;

        isAvailable = true;
    }
};

class Library : public Book {
public:
    int size;
    Book *books;

    Library() : size(5) {
        books = new Book[size];
        initializeLibrary();
    }

    ~Library() {
        delete[] books;
    }

    void initializeLibrary() {
        // Adding content for 5 initial books
        books[0].title = "The Great Gatsby";
        books[0].author = "F. Scott Fitzgerald";
        books[0].id = 101;
        books[0].isAvailable = true;

        books[1].title = "To Kill a Mockingbird";
        books[1].author = "Harper Lee";
        books[1].id = 102;
        books[1].isAvailable = true;

        books[2].title = "1984";
        books[2].author = "George Orwell";
        books[2].id = 103;
        books[2].isAvailable = true;

        books[3].title = "Pride and Prejudice";
        books[3].author = "Jane Austen";
        books[3].id = 104;
        books[3].isAvailable = true;

        books[4].title = "The Catcher in the Rye";
        books[4].author = "J.D. Salinger";
        books[4].id = 105;
        books[4].isAvailable = true;
    }

    void displayAvailableBookTypes() {
        cout << "\n------ Types of Available Books in the Library ------\n";
        for (int i = 0; i < size; ++i) {
            cout << "Book " << i + 1 << ":\n";
            books[i].displayBook();
        }
    }

    void addBooks() {
        int newSize;
        cout << "Enter the number of books to add: ";
        cin >> newSize;

        Book *temp = new Book[size + newSize];

        for (int i = 0; i < size; ++i) {
            temp[i] = books[i];
        }

        for (int i = size; i < size + newSize; ++i) {
            temp[i].addBook();
        }

        delete[] books;
        books = temp;
        size += newSize;
    }

    void displayBooks() {
        cout << "\n------ List of Books in the Library ------\n";
        for (int i = 0; i < size; ++i) {
            cout << "\nBook " << i + 1 << ":\n";
            books[i].displayBook();
        }
    }

    void searchBookById(int bookID) {
        bool found = false;
        cout << "\n------ Searching for Book by ID ------\n";
        for (int i = 0; i < size; ++i) {
            if (books[i].id == bookID) {
                found = true;
                cout << "\nBook Found!\n";
                books[i].displayBook();
                break;
            }
        }
        if (!found) {
            cout << "\nBook with ID " << bookID << " not found.\n";
            cout << "-----------------------------------\n";
        }
    }

    void issueBook(int bookID) {
        for (int i = 0; i < size; ++i) {
            if (books[i].id == bookID && books[i].isAvailable) {
                books[i].isAvailable = false;
                cout << "\nBook " << books[i].title << " has been issued.\n";
                return;
            }
        }
        cout << "\nBook with ID " << bookID << " is either not available or doesn't exist.\n";
    }

    void returnBook(int bookID) {
        for (int i = 0; i < size; ++i) {
            if (books[i].id == bookID && !books[i].isAvailable) {
                books[i].isAvailable = true;
                cout << "\nBook " << books[i].title << " has been returned.\n";
                return;
            }
        }
        cout << "\nBook with ID :" << bookID << " \n You did not issue this book.\n";
    }
};

int main() {
    Library library;
    int choice, bookID;

    do {
        cout << "\n=========== Library Management System ===========\n";
        cout << "1. Display Available Book Types\n2. Add Books\n3. Display Book List\n4. Search Book by ID\n5. Issue Book\n6. Return Book\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.displayAvailableBookTypes();
                break;
            case 2:
                library.addBooks();
                break;
            case 3:
                library.displayBooks();
                break;
            case 4:
                cout << "Enter Book ID to search: ";
                cin >> bookID;
                library.searchBookById(bookID);
                break;
            case 5:
                cout << "Enter Book ID to issue: ";
                cin >> bookID;
                library.issueBook(bookID);
                break;
            case 6:
                cout << "Enter Book ID to return: ";
                cin >> bookID;
                library.returnBook(bookID);
                break;
            case 7:
                cout << "Exiting... Thank you!\n";
                break;
            default:
                cout << "Invalid Choice! Please enter a valid option.\n";
                break;
        }
    } while (choice != 7);

    return 0;
}