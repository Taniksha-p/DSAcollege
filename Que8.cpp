#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NAME_LENGTH = 100;

struct Node {
    char name[MAX_NAME_LENGTH];
    Node* next;

    Node(const char* n) {
        strncpy(name, n, MAX_NAME_LENGTH);
        name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    int length;

public:
    LinkedList() : head(nullptr), length(0) {}

    // Function to get the length of the list
    int getLength() {
        return length;
    }

    // Function to add a node at the beginning
    void addAtBeg(const char* name) {
        Node* newNode = new Node(name);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Function to append a node at the end
    void append(const char* name) {
        Node* newNode = new Node(name);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        length++;
    }

    // Function to add a node at a specific position
    void addAtPOS(const char* name, int pos) {
        if (pos < 1 || pos > length + 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(name);
        if (pos == 1) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        length++;
    }

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->name << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to display the address, value, and next node address
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Name: " << temp->name
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // Function to remove the first node
    void removeFirst() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        length--;
    }

    // Function to remove the last node
    void removeLast() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
        } else {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
        length--;
    }

    // Function to remove a node at a specific position
    void removePOS(int pos) {
        if (pos < 1 || pos > length) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 1) {
            removeFirst();
        } else {
            Node* temp = head;
            for (int i = 1; i < pos - 1; i++) {
                temp = temp->next;
            }
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
            length--;
        }
    }

    ~LinkedList() {
        while (head != nullptr) {
            removeFirst();
        }
    }
};

int main() {
    LinkedList list;

    // Test addAtBeg
    list.addAtBeg("Alice");
    list.addAtBeg("Bob");
    list.addAtBeg("Charlie");
    cout << "List after addAtBeg: ";
    list.display();

    // Test append
    list.append("David");
    list.append("Eve");
    cout << "List after append: ";
    list.display();

    // Test addAtPOS
    list.addAtPOS("Frank", 3);
    cout << "List after addAtPOS(3): ";
    list.display();

    // Test removeFirst
    list.removeFirst();
    cout << "List after removeFirst: ";
    list.display();

    // Test removeLast
    list.removeLast();
    cout << "List after removeLast: ";
    list.display();

    // Test removePOS
    list.removePOS(2);
    cout << "List after removePOS(2): ";
    list.display();

    // Test displayMORE
    cout << "Detailed List Info (displayMORE):" << endl;
    list.displayMORE();

    return 0;
}
