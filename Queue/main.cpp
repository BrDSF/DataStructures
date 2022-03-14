#include <iostream>

using namespace std;

struct Root
{
  char info;
  Root *link;
};

typedef Root *NoPointer;

struct Queue
{
  NoPointer front;
  NoPointer rear;
  int value;
};

void push(Queue &q, char element)
{
  NoPointer p = new Root;
  p->info = element;
  p->link = NULL;
  if (q.value == 0)
  {
    q.front = q.rear = p;
  }
  else
  {
    q.rear->link = p;
    q.rear = p;
  };
  q.value++;
};

bool pop(Queue &q, char &element)
{
  if (q.value == 0)
  {
    return false;
  }
  else
  {
    NoPointer p = q.front;
    element = p->info;
    q.front = p->link;
    q.value--;
    if (q.value == 0)
    {
      q.rear = NULL;
    }
    delete p;
    return true;
  }
}

NoPointer first(Queue &q)
{
  NoPointer p = q.front;
  return p;
}

NoPointer last(Queue &q)
{
  NoPointer p = q.rear;
  return p;
}

int main()
{

  char element;
  Queue q;

  q.value = 0;

  push(q, 'a');
  push(q, 'b');
  push(q, 'c');

  if (pop(q, element))
    cout << "Removed of queue: " << element << endl;
  else
    cout << "Error - Queue empty " << endl;

  NoPointer aux;
  aux = first(q);
  cout << "First Element: " << aux->info << endl;
  aux = last(q);
  cout << "Last Element: " << aux->info;

  aux = NULL;

  delete aux;

  return 0;
}
