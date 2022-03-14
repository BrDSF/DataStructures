#include <iostream>

using namespace std;

struct Root
{
  char Info;
  Root *Lig;
};

typedef Root *Stack;

Stack StackTop(Stack Top)
{
  Root *Aux = new Root;
  Aux = Top;
  return Aux;
}

void push(Stack &Top, char Element)
{
  Root *Aux = new Root;
  Aux->Info = Element;
  Aux->Lig = Top;
  Top = Aux;
}

bool pop(Stack &Top, char &Element)
{
  if (Top == NULL)
    return false;
  Element = Top->Info;
  Root *Aux = Top;
  Top = Top->Lig;
  delete Aux;
  return true;
}

int main()
{

  char Elemento;
  Root *Top = new Root;
  Top = NULL; // Iniciando a pilha

  Root *Aux = new Root;

  push(Top, 'a');
  push(Top, 'b');
  push(Top, 'c');

  Aux = StackTop(Top);
  cout << "Top: " << Aux->Info << endl;

  if (pop(Top, Elemento))
    cout << "pop: " << Elemento << endl;
  else
    cout << "Error " << endl;

  Aux = StackTop(Top);
  cout << "Top: " << Aux->Info << endl;

  delete Top;

  return 0;
}
