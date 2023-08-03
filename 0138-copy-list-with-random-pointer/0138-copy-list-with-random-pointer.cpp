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
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> nodes;
        Node* h = head;
        for (; h; h = h->next)
            nodes[h] = new Node(h->val);
        
        h = head;
        for (; h; h = h->next) {
            Node* newNode = nodes[h];
            newNode->next = nodes[h->next];
            newNode->random = nodes[h->random];
        }
        return nodes[head];
    }
};