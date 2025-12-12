#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;



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
    cout << endl;
}

// Muffin Queue
void printMuffinQueue(const deque<string>& dq) {
    cout << "Mufffin Booth Queue: ";
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

    // Initial Coffee Queue with (3 random customers)
    for (int i = 0; i < 3; i++) {
        enqueue(names[rand() % 5], drinks[rand() % 5]);
    }
    
    // Initial Muffin Queue with (3 random customers)
    deque<string> muffinQueue;
    for (int i = 0; i < 3; i++) {
        muffinQueue.push_back(names[rand() % 5] + string(" --> ") + muffins[rand() % 4]);
    }

    cout << "Beginning the Coffee + Muffin Booth Simulation (10 Rounds)\n\n";
        
    // 10 round simulation
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
            cout << "Muffin Served: " << muffinQueue.front() << endl;
            muffinQueue.pop_front();
        } else {
            cout << "No customers at Muffin Booth.\n";
    }
        // 50% chance
        if (rand() % 2 == 0) {
            string customerName = names[rand() % 5];
            string customerOrder = muffins[rand() % 4];
            muffinQueue.push_back(customerName + string(" --> ") + customerOrder);
            cout << "Muffin new arrival: " << customerName << " --> " << customerOrder << endl;
        }

        printCoffeeQueue();
        printMuffinQueue(muffinQueue);
        
        cout << endl;
    }

    return 0;
}



