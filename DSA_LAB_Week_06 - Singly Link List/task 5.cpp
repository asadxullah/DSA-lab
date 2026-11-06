
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string student;
    int priority;
    Node* next;

    Node(string s, int p) {
        student = s;
        priority = p;
        next = nullptr;
    }
};

class Book {
public:
    string bookName;
    Node* head;

    Book(string name) {
        bookName = name;
        head = nullptr;
    }

    // Add student according to priority
    void addStudent(string name, int priority) {
        Node* newNode = new Node(name, priority);

        if (head == nullptr ||
            priority < head->priority) {

            newNode->next = head;
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr &&
                temp->next->priority <= priority) {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << name << " added to "
            << bookName << " queue.\n";
    }

    // Remove student
    void removeStudent(string name) {
        if (head == nullptr) {
            cout << "Reservation list is empty.\n";
            return;
        }

        if (head->student == name) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << name << " reservation cancelled.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->student != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << name << " reservation cancelled.\n";
    }

    // Update student priority
    void updatePriority(string name, int newPriority) {
        if (newPriority < 1 || newPriority > 3) {
            cout << "Invalid priority.\n";
            return;
        }

        Node* temp = head;

        while (temp != nullptr &&
            temp->student != name) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Student not found.\n";
            return;
        }

        // Remove student temporarily
        removeStudent(name);

        // Insert student again with new priority
        addStudent(name, newPriority);

        cout << "Priority updated successfully.\n";
    }

    // Display reservation list
    void display() {
        Node* temp = head;

        cout << "\nBook: " << bookName << endl;
        cout << "Reservation List:\n";

        if (temp == nullptr) {
            cout << "No reservations.\n";
            return;
        }

        while (temp != nullptr) {
            cout << temp->student
                << " (Priority: ";

            if (temp->priority == 1)
                cout << "Research";
            else if (temp->priority == 2)
                cout << "Assignment";
            else
                cout << "Casual Reading";

            cout << ") -> ";

            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Count students
    int countStudents() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Serve first student when book is returned
    void bookReturned() {
        if (head == nullptr) {
            cout << "No students waiting for this book.\n";
            return;
        }

        Node* temp = head;

        cout << "\nBook returned: " << bookName << endl;
        cout << "Book issued to: "
            << temp->student << endl;

        head = head->next;
        delete temp;
    }

    // Destructor
    ~Book() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {

    // Create two book reservation queues
    Book book1("Data Structures");
    Book book2("C++ Programming");

    cout << "===== UNIVERSITY LIBRARY SYSTEM =====\n";

    // Book 1 reservations
    cout << "\nData Structures\n";

    book1.addStudent("Ali", 3);
    book1.addStudent("Sara", 1);
    book1.addStudent("Ahmed", 2);
    book1.addStudent("Ayesha", 1);

    book1.display();

    cout << "\nTotal Students: "
        << book1.countStudents() << endl;

    // Update priority
    cout << "\nUpdating Priority\n";

    book1.updatePriority("Ali", 1);

    book1.display();

    // Cancel reservation
    cout << "\nCancelling Reservation\n";

    book1.removeStudent("Ahmed");

    book1.display();

    // Book returned
    cout << "\nBook Returned\n";

    book1.bookReturned();

    book1.display();

    // Book 2 reservations
    cout << "\nC++ Programming\n";

    book2.addStudent("Usman", 2);
    book2.addStudent("Hina", 3);
    book2.addStudent("Zain", 1);
    book2.addStudent("Fatima", 2);

    book2.display();

    cout << "\nTotal Students: "
        << book2.countStudents() << endl;

    // Cancel reservation
    cout << "\nCancelling Reservation\n";

    book2.removeStudent("Hina");

    book2.display();

    // Book returned
    cout << "\nBook Returned\n";

    book2.bookReturned();

    book2.display();

    return 0;
}
