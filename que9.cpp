#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class OddEvenLinkedList {
private:
    Node* oddHead;
    Node* evenHead;
    Node* oddTail;
    Node* evenTail;
    int length;

public:
    OddEvenLinkedList() : oddHead(nullptr), evenHead(nullptr), oddTail(nullptr), evenTail(nullptr), length(0) {}

    // Function to get the length of the list
    int getLength() {
        return length;
    }

    // Function to add a node at the beginning
    void addAtBeg(int x) {
        Node* newNode = new Node(x);
        if (x % 2 != 0) { // Odd
            if (oddHead == nullptr) {
                oddHead = oddTail = newNode;
            } else {
                newNode->next = oddHead;
                oddHead = newNode;
            }
        } else { // Even
            if (evenHead == nullptr) {
                evenHead = evenTail = newNode;
            } else {
                newNode->next = evenHead;
                evenHead = newNode;
            }
        }
        length++;
    }

    // Function to append a node at the end
    void append(int x) {
        Node* newNode = new Node(x);
        if (x % 2 != 0) { // Odd
            if (oddHead == nullptr) {
                oddHead = oddTail = newNode;
            } else {
                oddTail->next = newNode;
                oddTail = newNode;
            }
        } else { // Even
            if (evenHead == nullptr) {
                evenHead = evenTail = newNode;
            } else {
                evenTail->next = newNode;
                evenTail = newNode;
            }
        }
        length++;
    }

    // Function to display the list
    void display() {
        Node* temp = oddHead;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        temp = evenHead;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to display the address, value, and next node address
    void displayMORE() {
        Node* temp = oddHead;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Value: " << temp->data
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
        temp = evenHead;
        while (temp != nullptr) {
            cout << "Address: " << temp << ", Value: " << temp->data
                 << ", Next Node Address: " << temp->next << endl;
            temp = temp->next;
        }
    }

    // Function to remove the first node
    void removeFirst() {
        if (oddHead != nullptr) {
            Node* temp = oddHead;
            oddHead = oddHead->next;
            if (oddHead == nullptr) {
                oddTail = nullptr;
            }
            delete temp;
        } else if (evenHead != nullptr) {
            Node* temp = evenHead;
            evenHead = evenHead->next;
            if (evenHead == nullptr) {
                evenTail = nullptr;
            }
            delete temp;
        } else {
            cout << "List is empty!" << endl;
            return;
        }
        length--;
    }

    // Function to remove the last node
    void removeLast() {
        if (oddTail != nullptr) { // Odd list is not empty
            if (oddHead == oddTail) {
                delete oddTail;
                oddHead = oddTail = nullptr;
            } else {
                Node* temp = oddHead;
                while (temp->next != oddTail) {
                    temp = temp->next;
                }
                delete oddTail;
                oddTail = temp;
                oddTail->next = nullptr;
            }
        } else if (evenTail != nullptr) { // Even list is not empty
            if (evenHead == evenTail) {
                delete evenTail;
                evenHead = evenTail = nullptr;
            } else {
                Node* temp = evenHead;
                while (temp->next != evenTail) {
                    temp = temp->next;
                }
                delete evenTail;
                evenTail = temp;
                evenTail->next = nullptr;
            }
        } else {
            cout << "List is empty!" << endl;
            return;
        }
        length--;
    }

    ~OddEvenLinkedList() {
        while (oddHead != nullptr) {
            removeFirst();
        }
        while (evenHead != nullptr) {
            removeFirst();
        }
    }
};

int main() {
    OddEvenLinkedList list;

    // Test addAtBeg
    list.addAtBeg(5);
    list.addAtBeg(2);
    list.addAtBeg(7);
    cout << "List after addAtBeg: ";
    list.display();

    // Test append
    list.append(8);
    list.append(1);
    cout << "List after append: ";
    list.display();

    // Test removeFirst
    list.removeFirst();
    cout << "List after removeFirst: ";
    list.display();

    // Test removeLast
    list.removeLast();
    cout << "List after removeLast: ";
    list.display();

    // Test displayMORE
    cout << "Detailed List Info (displayMORE):" << endl;
    list.displayMORE();

    return 0;
}
