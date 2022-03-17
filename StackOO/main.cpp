#include <iostream>

using namespace std;

class Stack
{
private:
  char value;
  Stack *top;

public:
  Stack() : top(NULL) {}
  Stack(int val) : value(val), top(NULL) {}

  void push(char);
  void pop();
  void showTop();
  bool isEmpty();
};

void Stack::push(char value)
{
  Stack *aux = new Stack(value);
  aux->value = value;
  aux->top = this->top;
  this->top = aux;
}

void Stack::pop()
{
  if (isEmpty())
  {
    cout << endl
         << "The stack is empty" << endl;
    return;
  }
  Stack *aux = new Stack();
  aux = this->top;
  this->top = this->top->top;
  cout << endl
       << "Removed from stack: " << aux->value;
  delete aux;
}

void Stack::showTop()
{
  if (isEmpty())
  {
    cout << endl
         << "The stack is empty";
    return;
  }
  cout << endl
       << "The element on top is: " << this->top->value;
}

bool Stack::isEmpty()
{
  if (this->top == NULL)
  {
    return true;
  }
  return false;
}

int main()
{
  Stack *stack = new Stack();
  stack->push('a');
  stack->showTop();
  stack->push('b');
  stack->showTop();
  stack->pop();
  stack->showTop();
  stack->pop();
  stack->showTop();

  if (stack->isEmpty())
  {
    cout << " :(";
  }

  return 0;
}
