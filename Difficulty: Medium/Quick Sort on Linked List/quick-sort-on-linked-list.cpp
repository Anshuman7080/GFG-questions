//{ Driver Code Starts
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* a node of the singly linked list */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct Node*& head_ref, int new_data) {
    /* allocate node */
    struct Node* new_node = new Node(new_data);

    /* link the old list off the new node */
    new_node->next = head_ref;

    /* move the head to point to the new node */
    head_ref = new_node;
}

/* A utility function to print linked list */
void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Partitions the list taking the last element as the pivot
struct Node* partition(struct Node* head, struct Node* end, struct Node*& newHead,
                       struct Node*& newEnd) {
    struct Node* pivot = end;
    struct Node *prev = NULL, *cur = head, *tail = pivot;

    // During partition, both the head and end of the list might change
    // which is updated in the newHead and newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the pivot - becomes the new head
            if (newHead == NULL)
                newHead = cur;

            prev = cur;
            cur = cur->next;
        } else { // If cur node is greater than pivot
            // Move cur node to next of tail, and change tail
            if (prev)
                prev->next = cur->next;
            struct Node* tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }

    // If the pivot data is the smallest element in the current list, pivot becomes the
    // head
    if (newHead == NULL)
        newHead = pivot;

    // Update newEnd to the current last node
    newEnd = tail;

    // Return the pivot node
    return pivot;
}


// } Driver Code Ends

/* a node of the singly linked list
struct node
{
    int data;
    struct node *next;

    node(int x){
        data = x;
        next = NULL;
    }
}; */

// Solution class with quickSort function
class Solution {
  public:
  int partition(vector<int>&arr,int s,int e){
      int pivot=arr[s];
      int cnt=0;
      for(int i=s+1;i<=e;i++){
          if(arr[i]<=pivot){
              cnt++;
          }
      }
      
      int pivotIndex=s+cnt;
      swap(arr[s],arr[pivotIndex]);
      
      int i=s;
      int j=e;
      
      while(i<pivotIndex && j>pivotIndex){
          
          while(arr[i]<=arr[pivotIndex]){
              i++;
          }
          
          while(arr[j]>arr[pivotIndex]){
              j--;
          }
          if(i<pivotIndex && j>pivotIndex){
              swap(arr[i++],arr[j--]);
          }
          
      }
      
      return pivotIndex;
      
  }
  
  
  void sort(vector<int>&arr,int s,int e){
      if(s>=e){
          return;
      }
      
      int p=partition(arr,s,e);
      
      
      sort(arr,p+1,e);
      
      sort(arr,s,p-1);
      
      
  }
    struct Node* quickSort(struct Node* head) {
       
       vector<int>arr;
        struct Node* temp=head;
       while(temp!=NULL){
           arr.push_back(temp->data);
           temp=temp->next;
       }
       
       
     
      
      sort(arr,0,arr.size()-1);
       
      
       struct Node* newHead= new struct Node(arr[0]);
        struct Node* curr=newHead;
       for(int i=1;i<arr.size();i++){
           struct Node* tempo=new struct Node(arr[i]);
          curr->next=tempo;
          curr=curr->next;
       }
       
       curr=curr->next;
       
       return newHead;
       
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after reading t

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }

        Solution ob;
        head = ob.quickSort(head);

        printList(head);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends