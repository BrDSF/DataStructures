#include <iostream>

using namespace std;

class Node
{
private:
  int value;
  Node *next;

public:
  Node(int val) : value(val), next(NULL) {}
  void setNext(Node *next)
  {
    this->next = next;
  };
  void setValue(int value)
  {
    this->value = value;
  }
  int getValue()
  {
    return this->value;
  }
  Node *getNext()
  {
    return this->next;
  }
};

class LinkedQueue
{
private:
  Node *front;
  Node *rear;

public:
  LinkedQueue() : front(NULL), rear(NULL) {}
  Node *getFront()
  {
    return this->front;
  }
  void setFront(Node *front)
  {
    this->front = front;
  }
  Node *getRear()
  {
    return this->rear;
  }
  void setRear(Node *rear)
  {
    this->rear = rear;
  }
  void insert(int);
  void remove();
  void showElements();
  ~LinkedQueue();
};

void LinkedQueue::insert(int value)
{
  Node *aux = new Node(value);
  aux->setValue(value);
  if (getRear() == NULL)
  {
    setFront(aux);
    setRear(aux);
    return;
  }
  getRear()->setNext(aux);
  setRear(aux);
}

void LinkedQueue::remove()
{
  if (getFront() == NULL)
  {
    cout << "There's no element in the queue";
    return;
  }
  Node *aux = getFront();
  setFront(getFront()->getNext());

  if (getFront() == NULL)
  {
    setRear(NULL);
  }
  delete (aux);
}

void LinkedQueue::showElements()
{
  Node *aux = this->front;
  while (aux != NULL)
  {
    cout << aux->getValue() << " ";
    aux = aux->getNext();
  }
}

LinkedQueue::~LinkedQueue()
{
  Node *aux = this->front;
  while (aux != NULL)
  {
    this->front = aux->getNext();
    delete aux;
  }
}

int main()
{

  int element;
  LinkedQueue *q = new LinkedQueue();

  q->insert(2);
  q->insert(3);
  q->insert(5);
  q->insert(6);
  q->insert(8);
  q->remove();
  q->showElements();

  return 0;
}