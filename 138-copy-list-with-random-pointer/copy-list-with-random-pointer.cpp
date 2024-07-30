/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertatTail(Node*& head, Node*& tail, int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = newNode;
            tail = newNode;

        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

public:
    Node* copyRandomList(Node* head) {
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        Node* temp = head;
        while (temp != NULL) {
            insertatTail(cloneHead, cloneTail, temp->val);
            temp = temp->next;
        }
        unordered_map<Node*, Node*> oldtonewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while (originalNode != NULL) {
            oldtonewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL) {
            cloneNode->random = oldtonewNode[originalNode->random];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        return cloneHead;
    }
};