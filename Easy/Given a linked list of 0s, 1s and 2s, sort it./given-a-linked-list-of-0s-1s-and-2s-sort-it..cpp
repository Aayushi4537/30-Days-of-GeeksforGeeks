//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;


// } Driver Code Ends
/*
 
  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/
class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        /*vector<int>arr;
        Node* temp= head;
        while(temp!=NULL){
            arr.push_back(temp->data);
            temp= temp->next;
        }
        
        for(int i=0; i<arr.size(); i++){
            for(int j=i+1; j<arr.size(); j++){
                if(arr[j]<=arr[i]){
                    swap(arr[i], arr[j]);
                }
            }
        }
        head->data= arr[0];
        Node* mover= head;
        for(int i=1;i<arr.size();i++){
            Node* temp= new Node(arr[i]);
            mover->next= temp;
            mover= temp;
        }
        return head;*/
        
        
        // More optimal solution with just one traversal
        if(head==NULL|| head-> next== NULL){
            return head;
        }
        
        Node* zerohead= new Node(-1);
        Node* onehead= new Node(-1);
        Node* twohead= new Node (-1);
        
        
        Node* zero= zerohead;
        Node* one= onehead;
        Node* two= twohead;
        Node* temp= head;
        
        while( temp){
            if(temp->data==0){
                zero->next= temp;
                zero= zero->next;
            }
            else if(temp->data==1){
                one->next= temp;
                one= one->next;
            }
            else {
                two->next= temp;
                two= two->next;
                
            }
            temp= temp->next;
        }
        
        zero->next= (onehead->next)? onehead->next: twohead->next;
        one->next= twohead->next;
        two->next= NULL;
        return zerohead->next;
        
    }
};


//{ Driver Code Starts.

// Function to sort a linked list of 0s, 1s and 2s
void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

/* Drier program to test above function*/
void insert(int n1) {
    int n, value, i;
    // scanf("%d",&n);
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        Solution ob;
        struct Node *newHead = ob.segregate(start);
        printList(newHead);
    }

    return 0;
}
// } Driver Code Ends