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

// Coffee Queue
void printCoffeeQueue() {
    Node * temp = head;
    cout << "Coffee Booth Queue: ";
    while (temp != NULL) {
        cout << "[" << temp->name << " --> " << temp->order << "] ";
        temp = temp->next;
    }    
}

// Muffin Queue
void printMuffinQueue(const deque<string>& dq) {
    cout << "Mufffin Booth Queue: ";
    while (temp != NULL) {
    for (int i = 0; i < dq.size(); i++) {
        cout << "[" << dq[i] << "] "; 
    }
    cout << endl;
}




int main() {
    srand(time(0));

    string names[] = {"Alex", "Jordan", "Riley", "Taylor", "Casey"};
    string drinks[] = {"Latte", "Mocha", "Matcha", "Cold Brew", "Cappuccino"};
    string muffins[] = {"Blueberry Muffin", "Chocolate Muffin", "Banana Muffin", "Lemon Poppy Seed Muffin"};

    // Queue with 3 random customers
    for (int i = 0; i < 3; i++) {
        string customerName = names[rand() % 5];
        string customerOrder = drinks[rand() % 5];
        enqueue(customerName, customerOrder);
    }
        cout << "Begining the Coffee Booth Simulation (10 Rounds)\n\n";
        
        // 10 round sim
        for(int round = 1; round <= 10; round++) {
            cout << "---- Round " << round << " ----\n";
        
// *** COFFEE BOOTH ***
        // Served customer at the head spot
        if (head != NULL) {
            cout << "Served: " << head->name << " --> " << head->order << endl;

            Node * temp = head;
            head = head->next;
            delete temp;

            if (head == NULL){
                tail = NULL;
            }
        } else {
            cout << "No customers (Empty Queue).\n";
        }
    
        // 50% chance someone joins line
        if (rand() % 2 == 0) {
            string customerName = names[rand() % 5];
            string customerOrder = drinks[rand() % 5];
            enqueue(customerName , customerOrder);
            cout << "Cofffe new arrival: " << customerName << " --> " << customerOrder << endl;
        }

// *** MUFFIN BOOTH ***
        if (!muffinQueue.empty()) {

        }



        printQueue();
        cout << endl;
    }

    return 0;
}



