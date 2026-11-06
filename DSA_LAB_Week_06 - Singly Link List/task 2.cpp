
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    // Delete node by value
    void deleteNode(int value) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Value not found.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "Node deleted.\n";
    }

    // Display list
    void display() {
        Node* temp = head;

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Destructor
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    LinkedList list;

    list.insertBeginning(20);
    list.insertBeginning(10);

    list.insertEnd(30);
    list.insertEnd(40);

    cout << "Original List: ";
    list.display();

    list.deleteNode(30);

    cout << "After Deletion: ";
    list.display();

    return 0;
}
