
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class PatientQueue {
private:
    Node* head;

public:
    PatientQueue() {
        head = nullptr;
    }

    // Add patient at end
    void addPatient(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* temp = head;

            while (temp->next != nullptr) {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << name << " added to queue.\n";
    }

    // Remove patient by name
    void removePatient(string name) {
        if (head == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }

        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << name << " cancelled appointment.\n";
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr &&
            temp->next->name != name) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Patient not found.\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;
        delete del;

        cout << name << " removed from queue.\n";
    }

    // Display patients
    void display() {
        Node* temp = head;

        if (temp == nullptr) {
            cout << "No patients waiting.\n";
            return;
        }

        cout << "\nPatient Waiting List:\n";

        while (temp != nullptr) {
            cout << temp->name << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    // Count patients
    int countPatients() {
        int count = 0;
        Node* temp = head;

        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        return count;
    }

    ~PatientQueue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    PatientQueue hospital;

    cout << "HOSPITAL PATIENT MANAGEMENT SYSTEM\n\n";

    hospital.addPatient("Ali");
    hospital.addPatient("Ahmed");
    hospital.addPatient("Sara");
    hospital.addPatient("Ayesha");
    hospital.addPatient("Usman");

    hospital.display();

    cout << "\nTotal Patients: "
        << hospital.countPatients() << endl;

    cout << "\nAhmed cancels appointment:\n";
    hospital.removePatient("Ahmed");

    hospital.display();

    cout << "\nTotal Patients: "
        << hospital.countPatients() << endl;

    return 0;
}
