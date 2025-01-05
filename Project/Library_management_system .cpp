#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Book class to store book details
class Book {
public:
    string title;
    string author;
    string ISBN;
    int copies;

    Book(string t, string a, string i, int c) : title(t), author(a), ISBN(i), copies(c) {}

    void display() {
        cout << "Title: " << title << "\nAuthor: " << author
             << "\nISBN: " << ISBN << "\nCopies Available: " << copies << "\n\n";
    }
};

// Library class to manage the collection of books
class Library {
private:
    vector<Book> books;

public:
    Library() {
        // pre-load books
        books.push_back(Book("Ion", "Liviu Rebreanu", "9789734606424", 5));
        books.push_back(Book("Baltagul", "Mihail Sadoveanu", "9786066000028", 3));
        books.push_back(Book("Morometii", "Marin Preda", "9789734608961", 7));
        books.push_back(Book("Ultima noapte de dragoste, întâia noapte de război", "Camil Petrescu", "9789734608855", 4));
        books.push_back(Book("Enigma Otiliei", "George Călinescu", "9786066002329", 6));
        cout << "Pre-loaded books added to the library.\n";
    }

    void addBook() {
        string title, author, ISBN;
        int copies;
        cout << "Enter book title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter author: ";
        getline(cin, author);
        cout << "Enter ISBN: ";
        getline(cin, ISBN);
        cout << "Enter number of copies: ";
        cin >> copies;

        books.push_back(Book(title, author, ISBN, copies));
        cout << "The book has been added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "There are no books in the library.\n";
            return;
        }
        cout << "\nList of books in the library:\n";
        for (auto &book : books) {
            book.display();
        }
    }
};

// Main function
int main() {
    Library lib;
    int choice;

    do {
        cout << "\nLibrary - Main Menu\n";
        cout << "1. Display all books\n";
        cout << "2. Add a new book\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.displayBooks();
                break;
            case 2:
                lib.addBook();
                break;
            case 3:
                cout << "Exiting the program.\n";
                break;
            default:
                cout << "Invalid option! Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}