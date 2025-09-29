#include <iostream>
using namespace std;

struct Node {
    int person;
    Node* next;
};

int main() {
    int n = 5;  // Fixed to 5 people
    int k = 2;  // Fixed interval of 2

    cout << "Josephus Problem with " << n << " people, interval of " << k << "\n";
    cout << "---------------------------------------------\n\n";

    // Create first person
    Node* head = new Node;
    head->person = 1;
    head->next = head;

    // Add remaining people
    Node* current = head;
    for (int i = 2; i <= n; i++) {
        Node* newPerson = new Node;
        newPerson->person = i;
        newPerson->next = current->next;
        current->next = newPerson;
        current = newPerson;
    }

    // Elimination process
    Node* prev = current;
    current = head;
    int round = 1;

    while (current->next != current) {
        // Move k-1 steps
        for (int count = 1; count < k; count++) {
            prev = current;
            current = current->next;
        }

        cout << "Round " << round++ 
             << ": Person " << current->person 
             << " eliminated\n";

        // Remove person
        prev->next = current->next;
        Node* temp = current;
        current = current->next;
        delete temp;
    }

    cout << "\nSurvivor: Person " << current->person << endl;
    delete current;

    return 0;
}
