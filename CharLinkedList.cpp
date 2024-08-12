// linked_list_char.cpp

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    
    Node(char d) : data(d), next(nullptr) {}
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
    void addAtBeg(char x) {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        length++;
    }

    // Function to append a node at the end
    void append(char x) {
        Node* newNode = new Node(x);
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
    void addAtPOS(char x, int pos) {
        if (pos < 1 || pos > length + 1) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* newNode = new Node(x);
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
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to display the address, value, and next node address
    void displayMORE() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Value: " << temp->data
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
    list.addAtBeg('A');
    list.addAtBeg('B');
    list.addAtBeg('C');
    cout << "List after addAtBeg: ";
    list.display();

    // Test append
    list.append('D');
    list.append('E');
    cout << "List after append: ";
    list.display();

    // Test addAtPOS
    list.addAtPOS('F', 3);
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
