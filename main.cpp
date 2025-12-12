#include <iostream>
#include <string>
using namespace std;
#include <cstdlib>
#include <ctime>


// Milestone 1 :

// Node Struct
struct Node {
    string name;
    string order;
    Node * next;
};

// Front and Back
Node * head = NULL;
Node * tail = NULL;

// Add to the Back
void enqueue(string name, string order) {
Node * n = new Node;
n->name= name;
n->order = order;
n->next = NULL;

if (head == NULL) {
    head = tail = n;
    
    } else {
    
    tail->next = n;
    tail = n;
    }
}

// Queue
void printQueue() {
    Node * temp = head;
    cout << "Coffee Booth Queue: ";
    while (temp != NULL) {
        cout << "[" << temp->name << " - " << temp->order << "] ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    srand(time(0));

    string names[] = {"Alex", "Jordan", "Riley", "Taylor", "Casey"};
    string drinks[] = {"Latte", "Mocha", "Matcha", "Cold Brew", "Cappuccino"};

    // Queue with 3 random customers
    for (int i = 0; i < 3; i++) {
        string customerName = names[rand() % 5];
        string customerOrder = drinks[rand() % 5];
        enqueue(customerName, customerOrder);
    }
        printQueue();

    return 0;
}

