//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}


// } Driver Code Ends



class Solution {
public:
    Node* sortedInsert(Node* head, int x) {
        Node* temp = new Node();
        temp->data = x;

        // Handle empty list or insert at head
        if (head == NULL || head->data >= x) {
            temp->next = head;
            if (head) head->prev = temp;
            temp->prev = NULL;
            head = temp;
            return head;
        }

        Node* curr = head;
        while (curr->next && curr->next->data <= x) {
            curr = curr->next;
        }

        // Insert at the end
        if (!curr->next) {
            curr->next = temp;
            temp->prev = curr;
            temp->next = NULL;
        } 
        // Insert in the middle
        else {
            Node* temp1 = curr;
            curr = curr->next;
            temp1->next = temp;
            temp->prev = temp1;
            temp->next = curr;
            curr->prev = temp;
        }

        return head;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }

        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }

        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}

// } Driver Code Ends