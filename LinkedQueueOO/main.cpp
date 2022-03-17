#include <iostream>

using namespace std;

class Node
{
public:
  int value;
  Node *next;

  Node(int val) : value(val), next(NULL) {}
};

class LinkedQueue
{
public:
  Node *front;
  Node *rear;
  LinkedQueue() : front(NULL), rear(NULL) {}

  void insert(int);
  void remove();
  void showElements();
  ~LinkedQueue();
};

void LinkedQueue::insert(int value)
{
  Node *aux = new Node(value);
  aux->value = value;
  if (this->rear == NULL)
  {
    this->front = this->rear = aux;
    return;
  }
  this->rear->next = aux;
  this->rear = aux;
}

void LinkedQueue::remove()
{
  if (this->front == NULL)
  {
    cout << "There's no element in the queue";
    return;
  }
  Node *aux = front;
  this->front = front->next;

  if (this->front == NULL)
  {
    this->rear = NULL;
  }
  delete (aux);
}

void LinkedQueue::showElements()
{
  Node *aux = this->front;
  while (aux != NULL)
  {
    cout << aux->value << " ";
    aux = aux->next;
  }
}

LinkedQueue::~LinkedQueue()
{
  Node *aux = this->front;
  while (aux != NULL)
  {
    this->front = aux->next;
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