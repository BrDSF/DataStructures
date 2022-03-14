#include <iostream>

using namespace std;

struct Root
{
  char info;
  Root *next;
};

typedef Root *List;

void push(List &l, char element)
{
  if (l == NULL)
  {
    l = new Root;
    l->info = element;
    l->next = NULL;
  }
  else
  {
    List aux = l;
    List prev = NULL;

    while ((aux != NULL) && (aux->info < element))
    {
      prev = aux;
      aux = aux->next;
    }
    aux = new Root;
    aux->info = element;
    if (prev == NULL)
    {
      aux->next = l;
      l = aux;
    }
    else
    {
      aux->next = prev->next;
      prev->next = aux;
    }
  }
};

bool pop(List &l, char element)
{
  List prev = NULL;
  List aux = l;

  while ((aux != NULL) && (aux->info != element))
  {
    prev = aux;
    aux = aux->next;
  }
  if (aux == NULL)
  {
    return false;
  }
  if (aux == l)
  {
    l = l->next;
  }
  else
  {
    prev->next = aux->next;
  }

  delete aux;

  return true;
}

int main(void)
{
  char element;
  List l = new Root;
  l = NULL;

  push(l, 'a');
  push(l, 'b');
  push(l, 'c');

  if (pop(l, element))
    cout << "pop: " << element << endl;
  else
    cout << "Error " << endl;

  return 0;
}