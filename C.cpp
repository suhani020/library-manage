#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

class Book {
private:
    string bookTitle;
    string bookAuthor;
    int publicationYear;
    int bookID;
public:
    Book(string title, string author, int year, int id) : bookTitle(title), bookAuthor(author), publicationYear(year), bookID(id) {}

    string getTitle() const { return bookTitle; }
    string getAuthor() const { return bookAuthor; }
    int getYear() const { return publicationYear; }
    int getBookID() const { return bookID; }

    void displayInfo() const {
        cout << "Title: " << bookTitle << endl;
        cout << "Author: " << bookAuthor << endl;
        cout << "Year: " << publicationYear << endl;
        cout << "Book ID: " << bookID << endl;
    }
};

class Library {
private:
    vector<Book> books;
public:
    void addBook(const Book& book) {
        books.push_back(book);
    }

    void displayBooks() const {
        if (books.empty()) {
            cout << "No books in the library." << endl;
        } else {
            cout << "Books in the library:" << endl;
            for (const auto& book : books) {
                book.displayInfo();
                cout << endl;
            }
        }
    }

    void updateBook(int bookID, const Book& newBook) {
        auto it = find_if(books.begin(), books.end(), [bookID](const Book& book) {
            return book.getBookID() == bookID;
        });
        if (it != books.end()) {
            *it = newBook;
            cout << "Book updated successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }

    void removeBook(int bookID) {
        auto it = find_if(books.begin(), books.end(), [bookID](const Book& book) {
            return book.getBookID() == bookID;
        });
        if (it != books.end()) {
            books.erase(it);
            cout << "Book removed successfully." << endl;
        } else {
            cout << "Book not found." << endl;
        }
    }
};

int main() {
    Library library;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Books" << endl;
        cout << "3. Update Book" << endl;
        cout << "4. Remove Book" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string title, author;
                int year, id;
                cout << "Enter book title: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);
                cout << "Enter author name: ";
                getline(cin, author);
                cout << "Enter publication year: ";
                cin >> year;
                cout << "Enter book ID: ";
                cin >> id;
                Book newBook(title, author, year, id);
                library.addBook(newBook);
                break;
            }
            case 2:
                library.displayBooks();
                break;
            case 3: {
                int bookID;
                cout << "Enter book ID to update: ";
                cin >> bookID;
                string title, author;
                int year;
                cout << "Enter new title: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin, title);
                cout << "Enter new author: ";
                getline(cin, author);
                cout << "Enter new publication year: ";
                cin >> year;
                Book updatedBook(title, author, year, bookID);
                library.updateBook(bookID, updatedBook);
                break;
            }
            case 4: {
                int bookID;
                cout << "Enter book ID to remove: ";
                cin >> bookID;
                library.removeBook(bookID);
                break;
            }
            case 5:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}

