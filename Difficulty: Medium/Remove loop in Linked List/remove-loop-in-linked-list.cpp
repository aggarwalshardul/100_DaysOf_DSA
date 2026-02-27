/*
class Node {
  public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    void removeLoop(Node* head) {
        // code here
            if (head == NULL || head->next == NULL)
            return;
            
        Node *slow = head, *fast = head;
        
        // Step 1: Detect loop using Floyd's Algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast)
                break;
        }
        
        // If no loop found
        if (slow != fast)
            return;
        
        // Step 2: Move slow to head
        slow = head;
        
        // If loop starts at head
        if (slow == fast) {
            while (fast->next != slow)
                fast = fast->next;
        } 
        else {
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        // Step 3: Remove loop
        fast->next = NULL;
    
        
    }
};