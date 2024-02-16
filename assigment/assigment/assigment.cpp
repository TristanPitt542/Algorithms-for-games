#include <iostream>
using namespace std;

//linked list node
class Node {
public:
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data)
{
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void deleteNodes(Node** head_ref, int position, int amount)
{
    // If linked list is empty
    if (*head_ref == NULL)
        return;

    // Store head node
    Node* temp = *head_ref;

    // If head needs to be removed
    if (position == 0) {
        for (int i = 0; i < amount && temp != NULL; i++) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
        *head_ref = temp;
        return;
    }

    // Find previous node of the node to be deleted
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    // If position is more than number of nodes
    if (temp == NULL || temp->next == NULL)
        return;

    Node* prev = temp;
    temp = temp->next;
    for (int i = 0; i < amount && temp != NULL; i++) {
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
    prev->next = temp;
}

// This function prints contents of linked
// list starting from the given node
void printList(Node* node)
{
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

int main()
{
    //Linked List
    Node* head = NULL;

    //add numbers to linked list
    push(&head, 5);
    push(&head, 4);
    push(&head, 1);
    push(&head, 6);
    push(&head, 5);
    push(&head, 8);
    push(&head, 3);
    push(&head, 9);

    cout << "Created Linked List: " << endl;
    printList(head);

    //the position of the node to delete nodes after
    cout << "\nPosition to delete node from: " << endl;
    int node_pos;
    cin >> node_pos;
    //amount of nodes to be deleted
    cout << "Amount of nodes to delete: " << endl;
    int del_amount;
    cin >> del_amount;
    //delete set of nodes
    deleteNodes(&head, node_pos, del_amount);

    cout << "\nLinked List after Deletion at position " << node_pos << ": ";
    printList(head);
    return 0;
}