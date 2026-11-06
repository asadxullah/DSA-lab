#include <iostream>
#include <string>
using namespace std;

// Abstract class
class LibraryItem {
public:
    virtual void display() = 0;
};

// Book class
class Book : public LibraryItem {
public:
    string title, author;
    int pages;

    Book() {}

    Book(string t, string a, int p) {
        title = t;
        author = a;
        pages = p;
    }

    void display() override {
        cout << "Title: " << title
            << "\nAuthor: " << author
            << "\nPages: " << pages << endl;
    }
};

// Newspaper class
class Newspaper : public LibraryItem {
public:
    string name, date, edition;

    Newspaper() {}

    Newspaper(string n, string d, string e) {
        name = n;
        date = d;
        edition = e;
    }

    void display() override {
        cout << "Name: " << name
            << "\nDate: " << date
            << "\nEdition: " << edition << endl;
    }
};

// Template for linear search
template <class T>
int linearSearch(T arr[], int size, string key) {
    for (int i = 0; i < size; i++) {
        if (arr[i].title == key)
            return i;
    }
    return -1;
}

// Template for binary search by name
template <class T>
int binarySearch(T arr[], int size, string key) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid].name == key)
            return mid;
        else if (arr[mid].name < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

// Library class
class Library {
public:
    Book books[100];
    Newspaper newspapers[100];
    int bCount = 0, nCount = 0;

    void addBook(Book b) {
        books[bCount++] = b;
    }

    void addNewspaper(Newspaper n) {
        newspapers[nCount++] = n;
    }

    void displayCollection() {
        cout << "\nBooks:\n";
        for (int i = 0; i < bCount; i++)
            books[i].display();

        cout << "\nNewspapers:\n";
        for (int i = 0; i < nCount; i++)
            newspapers[i].display();
    }

    void sortBooksByPages() {
        for (int i = 0; i < bCount - 1; i++)
            for (int j = 0; j < bCount - i - 1; j++)
                if (books[j].pages > books[j + 1].pages) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
    }

    void sortNewspapersByEdition() {
        for (int i = 0; i < nCount - 1; i++)
            for (int j = 0; j < nCount - i - 1; j++)
                if (newspapers[j].edition >
                    newspapers[j + 1].edition) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }
    }

    Book* searchBookByTitle(string title) {
        int i = linearSearch(books, bCount, title);
        return (i == -1) ? nullptr : &books[i];
    }

    Newspaper* searchNewspaperByName(string name) {
        // Sort by name before binary search
        for (int i = 0; i < nCount - 1; i++)
            for (int j = 0; j < nCount - i - 1; j++)
                if (newspapers[j].name > newspapers[j + 1].name) {
                    Newspaper temp = newspapers[j];
                    newspapers[j] = newspapers[j + 1];
                    newspapers[j + 1] = temp;
                }

        int i = binarySearch(newspapers, nCount, name);
        return (i == -1) ? nullptr : &newspapers[i];
    }
};

int main() {
    Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
    Book book2("To Kill a Mockingbird", "Harper Lee", 324);

    Newspaper newspaper1(
        "Washington Post", "2024-10-13", "Morning Edition");
    Newspaper newspaper2(
        "The Times", "2024-10-12", "Weekend Edition");

    Library library;

    library.addBook(book1);
    library.addBook(book2);
    library.addNewspaper(newspaper1);
    library.addNewspaper(newspaper2);

    cout << "Before Sorting:\n";
    library.displayCollection();

    library.sortBooksByPages();
    library.sortNewspapersByEdition();

    cout << "\nAfter Sorting:\n";
    library.displayCollection();

    Book* foundBook =
        library.searchBookByTitle("The Catcher in the Rye");

    if (foundBook) {
        cout << "\nFound Book:\n";
        foundBook->display();
    }
    else {
        cout << "\nBook not found.\n";
    }

    Newspaper* foundNewspaper =
        library.searchNewspaperByName("The Times");

    if (foundNewspaper) {
        cout << "\nFound Newspaper:\n";
        foundNewspaper->display();
    }
    else {
        cout << "\nNewspaper not found.\n";
    }

    return 0;
}
