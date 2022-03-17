#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node(int val) : data(val), next(NULL) {}
};

class LinkedList
{
public:
  Node *head;
  LinkedList() : head(NULL) {}
  void insertAtBegin(int value);
  void insertAtEnd(int value);
  void insertAtPosition(int position, int value);
  void remove(int value);
  void viewList();
};

void LinkedList::insertAtBegin(int value)
{
  Node *newNode = new Node(value);
  newNode->next = this->head;
  this->head = newNode;
}

void LinkedList::insertAtEnd(int value)
{
  if (head == NULL)
  {
    insertAtBegin(value);
    return;
  }
  Node *newNode = new Node(value);
  Node *aux = this->head;
  while (aux->next != NULL)
  {
    aux = aux->next;
  }
  aux->next = newNode;
}

void LinkedList::remove(int value)
{
  if (this->head == NULL)
  {
    cout << "List Empty";
    return;
  }
  if (this->head->data == value)
  {
    Node *aux = this->head;
    this->head = this->head->next;
    delete (aux);
    return;
  }
  Node *aux = this->head;
  while (aux->next != NULL && aux->next->data != value)
  {
    aux = aux->next;
  }
  if (aux->next == NULL)
  {
    cout << "Value Not Fount";
    return;
  }
  Node *toRemove = aux->next;
  aux->next = aux->next->next;
  delete (toRemove);
}

void LinkedList::viewList()
{
  Node *aux = this->head;
  while (aux != NULL)
  {
    cout << aux->data << " ";
    aux = aux->next;
  }
  cout << endl;
}

void LinkedList::insertAtPosition(int position, int value)
{
  Node *aux = new Node(value);
  if (position == 1)
  {
    aux->next = this->head;
    this->head = aux;
    return;
  }
  position--;
  Node *pointer = this->head;
  while (pointer != NULL && --position)
  {
    pointer = pointer->next;
  }
  if (pointer == NULL)
  {
    cout << "Invalid Position" << endl;
    return;
  }
  aux->next = pointer->next;
  pointer->next = aux;
}

int main()
{
  LinkedList *list = new LinkedList();

  list->insertAtBegin(2);
  list->insertAtBegin(3);
  list->insertAtBegin(4);
  list->insertAtEnd(5);
  list->viewList();
  list->insertAtPosition(5, 10);
  list->viewList();
  list->remove(3);
  list->viewList();

  return 0;
}