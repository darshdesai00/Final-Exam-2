#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <stack>
using namespace std;

// Milestone 1 : Coffee Booth Node Struct
struct Node {
    string name;
    string order;
    Node * next;
};

Node * head = NULL;
Node * tail = NULL;

// Add customers to coffee queue
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

// Print Functions

void printCoffeeQueue() {
    Node * temp = head;
    cout << "Coffee Booth Queue: ";
    while (temp != NULL) {
        cout << "[" << temp->name << " --> " << temp->order << "] ";
        temp = temp->next;
    } 
    cout << endl;
}

void printMuffinQueue(const deque<string>& dq) {
    cout << "Mufffin Booth Queue: ";
    for (int i = 0; i < dq.size(); i++) {
        cout << "[" << dq[i] << "] "; 
    }
    cout << endl;
}

void printBraceletQueue(const vector<string>& v) {
    cout << "Bracelet Booth Queue: ";
    for (int i = 0; i < v.size(); i++)
        cout << "[" << v[i] << "] ";
    cout << endl;
}

void printStickerStack(stack<string> s) {
    cout << "Sticker Booth Queue: ";
    while (!s.empty()) {
        cout << "[" << s.top() << "] ";
        s.pop();
    }
    cout << endl;
}

// Main Simulation
int main() {
    srand(time(0));

    string names[] = {"Alex", "Jordan", "Riley", "Taylor", "Casey"};
    string drinks[] = {"Latte", "Mocha", "Matcha", "Cold Brew", "Cappuccino"};
    string muffins[] = {"Blueberry Muffin", "Chocolate Muffin", "Banana Muffin", "Lemon Poppy Seed Muffin"};
    string bracelets[] = {"Beaded Bracelet", "Charm Bracelet", "Friendship Tie", "Woven Bracelet"};
    string stickers[] = {"Star Sticker", "Smile Sticker", "Sparkle Sticker", "Lightning Sticker"};

    // Initial Coffee Booth with (3 random customers)
    for (int i = 0; i < 3; i++) {
        enqueue(names[rand() % 5], drinks[rand() % 5]);
    }
    
    // Muffin Queue (Deque)
    deque<string> muffinQueue;
    for (int i = 0; i < 3; i++) {
        muffinQueue.push_back(names[rand() % 5] + string(" --> ") + muffins[rand() % 4]);
    }

    // Bracelet Booth (Vector)
    vector<string>braceletQueue;
    for(int i = 0; i < 3; i++)
    braceletQueue.push_back(names[rand() % 5] + " --> " + bracelets[rand() % 4]);
    
    // Sticker Booth (stack
    stack<string> stickerStack;
    for (int i = 0; i < 3; i++) {
        stickerStack.push(names[rand() % 5] + string(" --> ") + stickers[rand() % 4]);
    }

    cout << "Beginning Multi-Booth Simulation (10 Rounds)\n\n";     

    // 10 round simulation
    for(int round = 1; round <= 10; round++) {
        cout << "---- Round " << round << " ----\n";
    
        
        // *** COFFEE BOOTH ***
        
        if (head != NULL) {
            cout << "Coffee Served: " << head->name << " --> " << head->order << endl;

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

        if (rand() % 2 == 0) {
            string customerName = names[rand() % 5];
            string customerOrder = muffins[rand() % 4];
            muffinQueue.push_back(customerName + string(" --> ") + customerOrder);
            cout << "Muffin new arrival: " << customerName << " --> " << customerOrder << endl;
        }

    // *** BRACELET BOOTH ***

        if (!braceletQueue.empty()) {
            cout << "Bracelet Served: " << braceletQueue.front() << endl;
            braceletQueue.erase(braceletQueue.begin());
        } else {
            cout << "No customers at Bracelet Booth.\n";
        }

        if (rand() % 2 == 0) {
            string n = names[rand() % 5];
            string b = bracelets[rand() % 4];
            braceletQueue.push_back(n + " --> " + b);
            cout << "Bracelet new arrival: " << n << " --> " << b << endl;
        }
        
        // *** STICKER BOOTH ***

        if (!stickerStack.empty()) {
            cout << "Sticker Served: " << stickerStack.top() << endl;
            stickerStack.pop();
        } else {
            cout << "No customers at Sticker Booth.\n";
        }

        if (rand() % 2 == 0) {
            string sn = names[rand() % 5];
            string so = stickers[rand() % 4];
            stickerStack.push(sn + string(" --> ") + so);
            cout << "Sticker new arrival: " << sn << " --> " << so << endl;
        }
       
        // End of the round status
        cout << "--- Queue Status After Round " << round << " ---\n";
        printCoffeeQueue();
        printMuffinQueue(muffinQueue);
        printBraceletQueue(braceletQueue);
        printStickerStack(stickerStack);
        cout << endl;
    }

    return 0;
}



