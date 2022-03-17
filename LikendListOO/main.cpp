#include <iostream>
using namespace std;

class Node
{
private:
  int data;
  Node *next;

public:
  Node(int val) : data(val), next(NULL) {}
  int getData()
  {
    return this->data;
  }
  void setData(int data)
  {
    this->data = data;
  }
  Node *getNext()
  {
    return this->next;
  }
  void setNext(Node *next)
  {
    this->next = next;
  }
};

class LinkedList
{
private:
  Node *head;

public:
  LinkedList() : head(NULL) {}
  Node *getHead()
  {
    return this->head;
  }
  void setHead(Node *head)
  {
    this->head = head;
  }
  void insertAtBegin(int value);
  void insertAtEnd(int value);
  void insertAtPosition(int position, int value);
  void remove(int value);
  void viewList();
};

void LinkedList::insertAtBegin(int value)
{
  Node *newNode = new Node(value);
  newNode->setNext(getHead());
  setHead(newNode);
}

void LinkedList::insertAtEnd(int value)
{
  if (getHead() == NULL)
  {
    insertAtBegin(value);
    return;
  }
  Node *newNode = new Node(value);
  Node *aux = getHead();
  while (aux->getNext() != NULL)
  {
    aux = aux->getNext();
  }
  aux->setNext(newNode);
}

void LinkedList::remove(int value)
{
  if (getHead() == NULL)
  {
    cout << "List Empty";
    return;
  }
  if (getHead()->getData() == value)
  {
    Node *aux = getHead();
    setHead(getHead()->getNext());
    delete (aux);
    return;
  }
  Node *aux = getHead();
  while (aux->getNext() != NULL && aux->getNext()->getData() != value)
  {
    aux = aux->getNext();
  }
  if (aux->getNext() == NULL)
  {
    cout << "Value Not Fount";
    return;
  }
  Node *toRemove = aux->getNext();
  aux->setNext(aux->getNext()->getNext());
  delete (toRemove);
}

void LinkedList::viewList()
{
  Node *aux = getHead();
  while (aux != NULL)
  {
    cout << aux->getData() << " ";
    aux = aux->getNext();
  }
  cout << endl;
}

void LinkedList::insertAtPosition(int position, int value)
{
  Node *aux = new Node(value);
  if (position == 1)
  {
    aux->setNext(getHead());
    setHead(aux);
    return;
  }
  position--;
  Node *pointer = getHead();
  while (pointer != NULL && --position)
  {
    pointer = pointer->getNext();
  }
  if (pointer == NULL)
  {
    cout << "Invalid Position" << endl;
    return;
  }
  aux->setNext(pointer->getNext());
  pointer->setNext(aux);
}

int main()
{
  LinkedList *list = new LinkedList();

  list->insertAtBegin(2);
  list->insertAtBegin(3);
  list->insertAtBegin(4);
  list->insertAtEnd(5);
  list->viewList();
  list->insertAtPosition(3, 10);
  list->viewList();
  list->remove(3);
  list->viewList();

  return 0;
}