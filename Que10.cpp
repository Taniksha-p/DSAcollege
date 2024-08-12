#include <iostream>
#include <cstring>
using namespace std;

const int MAX_NAME_LENGTH = 100;
const int MAX_MOBILE_LENGTH = 15;

struct Contact {
    char name[MAX_NAME_LENGTH];
    char mobile[MAX_MOBILE_LENGTH];

    Contact(const char* n, const char* m) {
        strncpy(name, n, MAX_NAME_LENGTH);
        name[MAX_NAME_LENGTH - 1] = '\0'; // Ensure null-termination
        strncpy(mobile, m, MAX_MOBILE_LENGTH);
        mobile[MAX_MOBILE_LENGTH - 1] = '\0'; // Ensure null-termination
    }
};

struct Node {
    Contact contact;
    Node* next;

    Node(const char* name, const char* mobile) : contact(name, mobile), next(nullptr) {}
};

class ContactList {
private:
    Node* head;
    int length;

public:
    ContactList() : head(nullptr), length(0) {}

    // Function to get the length of the list
    int getLength() {
        return length;
    }

    // Function to add a contact at the beginning
    void addAtBeg(const char* name, const char* mobile) {
        Node* newNode = new Node(name, mobile);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Function to append a contact at the end
    void append(const char* name, const char* mobile) {
        Node* newNode = new Node(name, mobile);
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

    // Function to display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Name: " << temp->contact.name << ", Mobile: " << temp->contact.mobile << endl;
            temp = temp->next;
        }
    }

    // Function to display the address, value, and next node address
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Name: " << temp->contact.name 
                 << ", Mobile: " << temp->contact.mobile 
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // Function to remove the first contact
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

    // Function to remove the last contact
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

    // Function to remove a contact at a specific position
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

    ~ContactList() {
        while (head != nullptr) {
            removeFirst();
        }
    }
};

int main() {
    ContactList list;

    // Test addAtBeg
    list.addAtBeg("Alice", "123-456-7890");
    list.addAtBeg("Bob", "234-567-8901");
    list.addAtBeg("Charlie", "345-678-9012");
    cout << "List after addAtBeg:" << endl;
    list.display();

    // Test append
    list.append("David", "456-789-0123");
    list.append("Eve", "567-890-1234");
    cout << "List after append:" << endl;
    list.display();

    // Test removeFirst
    list.removeFirst();
    cout << "List after removeFirst:" << endl;
    list.display();

    // Test removeLast
    list.removeLast();
    cout << "List after removeLast:" << endl;
    list.display();

    // Test removePOS
    list.removePOS(2);
    cout << "List after removePOS(2):" << endl;
    list.display();

    // Test displayMORE
    cout << "Detailed List Info (displayMORE):" << endl;
    list.displayMORE();

    return 0;
}
