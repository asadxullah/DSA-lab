
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

    // Insert at specific position
    void insertAtPosition(int value, int pos) {
        if (pos < 1) {
            cout << "Invalid position.\n";
            return;
        }

        Node* newNode = new Node(value);

        if (pos == 1) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << "Node inserted successfully.\n";
    }

    // Delete at specific position
    void deleteAtPosition(int pos) {
        if (head == nullptr || pos < 1) {
            cout << "Invalid operation.\n";
            return;
        }

        Node* temp = head;

        if (pos == 1) {
            head = head->next;
            delete temp;
            cout << "Node deleted.\n";
            return;
        }

        for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Invalid position.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << "Node deleted.\n";
    }

    // Search element
    void search(int value) {
        Node* temp = head;
        int pos = 1;

        while (temp != nullptr) {
            if (temp->data == value) {
                cout << "Element found at position "
                    << pos << endl;
                return;
            }

            temp = temp->next;
            pos++;
        }

        cout << "Element not found.\n";
    }

    // Count nodes
    int countNodes() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    // Display list
    void display() {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

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
    int choice, value, pos;

    do {
        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at Position\n";
        cout << "2. Delete at Position\n";
        cout << "3. Search Element\n";
        cout << "4. Count Nodes\n";
        cout << "5. Display List\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> pos;

            list.insertAtPosition(value, pos);
            break;

        case 2:
            cout << "Enter position: ";
            cin >> pos;

            list.deleteAtPosition(pos);
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;

            list.search(value);
            break;

        case 4:
            cout << "Total nodes: "
                << list.countNodes() << endl;
            break;

        case 5:
            list.display();
            break;

        case 6:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 6);

    return 0;
}
