#include<iostream>
using namespace std;
class libraryitem {
protected:
	string title;
public:
	libraryitem() {
	}
	libraryitem(string t) {
		title = t;
	}
	virtual void display() = 0;
	virtual string gettype() = 0;
	string gettitle() {
		return title;
	}
};
class Book :public libraryitem {
private:
	string author;
	int pages;
public:
	Book() {
		pages = 0;
	}
	Book(string t, string a, int p) : libraryitem(t) {
		author = a;
		pages = p;
	}
	void display() override {
		cout << "Title : " << title << endl
			<< "Author : " << author << endl
			<< "Pages : " << pages << endl;
	}

	string gettype() override {
		return "Book";
	}

	string getauthor() {
		return author;
	}

	int getpages() {
		return pages;
	}
};

class Newspaper : public libraryitem {
private:
	string date;
	string edition;
public:
	Newspaper() {
	}
	Newspaper(string t, string d, string e) : libraryitem(t) {
		date = d;
		edition = e;
	}
	void display()override {
		cout << "Title : " << title << endl
			<< "Date : " << date << endl
			<< "Edition : " << edition << endl;
	}

	string gettype() {
		return "Newspaper";
	}
	string getedition() {
		return edition;
	}

	string getdate() {
		return date;
	}
};

class Library {
private:
	Book book[50];
	Newspaper newspaper[50];
	int bookcount;
	int newscount;
public:
	Library() {
		bookcount = 0;
		newscount = 0;
	}
	void addBook(Book b) {
		if (bookcount < 50) {
			book[bookcount] = b;
			bookcount++;
		}
	}
	void addNewspaper(Newspaper n) {
		if (newscount < 50) {
			newspaper[newscount] = n;
			newscount++;
		}
	}
	void displayCollection() {
		cout << endl << "--- Books ---" << endl;

		for (int i = 0; i < bookcount; i++) {
			book[i].display();
			cout << endl;
		}

		cout << endl << "--- Newspapers ---" << endl;

		for (int i = 0; i < newscount; i++) {
			newspaper[i].display();
			cout << endl;
		}
	}
	void sortBooksByPages() {
		for (int i = 0; i < bookcount - 1; i++) {
			int smallsub = i;
			for (int j = i + 1; j < bookcount; j++) {
				if (book[j].getpages() < book[smallsub].getpages()) {
					smallsub = j;
				}
			}
			Book temp = book[i];
			book[i] = book[smallsub];
			book[smallsub] = temp;
		}
	}

	void sortNewspapersByEdition() {
		for (int i = 0; i < newscount - 1; i++) {
			int smallsub = i;
			for (int j = i + 1; j < newscount; j++) {
				if (newspaper[j].getedition() < newspaper[smallsub].getedition()) {
					smallsub = j;
				}
			}
			Newspaper temp = newspaper[i];
			newspaper[i] = newspaper[smallsub];
			newspaper[smallsub] = temp;
		}
	}

	Book* searchBookByTitle(string title) {
		for (int i = 0; i < bookcount; i++) {
			if (book[i].gettitle() == title) {
				return &book[i];
			}
		}
		return nullptr;
	}

	Newspaper* searchNewspaperByName(string name) {
		for (int i = 0; i < newscount; i++) {
			if (newspaper[i].gettitle() == name) {
				return &newspaper[i];
			}
		}
		return nullptr;
	}
};

int main() {
	Book book1("The Catcher in the Rye", "J.D. Salinger", 277);
	Book book2("To Kill a Mockingbird", "Harper Lee", 324);

	Newspaper newspaper1("Washington Post", "2024-10-13", "Morning Edition");
	Newspaper newspaper2("The Times", "2024-10-12", "Weekend Edition");

	Library library;

	library.addBook(book1);
	library.addBook(book2);
	library.addNewspaper(newspaper1);
	library.addNewspaper(newspaper2);

	cout << "Before Sorting:" <<endl;
	library.displayCollection();

	library.sortBooksByPages();
	library.sortNewspapersByEdition();

	cout <<endl << "After Sorting:" <<endl;
	library.displayCollection();

	Book* foundBook = library.searchBookByTitle("The Catcher in the Rye");
	if (foundBook) {
		cout <<endl << "Found Book:" <<endl;
		foundBook->display();
	}
	else {
		cout <<endl << "Book not found." <<endl;
	}

	Newspaper* foundNewspaper = library.searchNewspaperByName("The Times");
	if (foundNewspaper) {
		cout <<endl << "Found Newspaper:" <<endl;
		foundNewspaper->display();
	}
	else {
		cout <<endl << "Newspaper not found." <<endl;
	}

	return 0;
}
