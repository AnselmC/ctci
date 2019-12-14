#include <iostream>
#include <memory>
#include <string>

namespace ctci {
template <class T>
struct Node {
  T data;
  Node<T> *next = nullptr;
  Node<T>(T data) { this->data = data; };
};

template <class T>
class SinglyLinkedList {
 private:
  Node<T> *head;

 public:
  SinglyLinkedList() { this->head = nullptr; }
  ~SinglyLinkedList() {
    Node<T> *tmp;
    while (head) {
      tmp = head;
      head = head->next;
      delete tmp;
    }
  }

  void insertBack(T data) {
    Node<T> *new_node = new Node<T>(data);
    if (this->head == nullptr) {
      this->head = new_node;
      return;
    }
    Node<T> *tmp = this->head;
    while (tmp->next) {
      tmp = tmp->next;
    }
    tmp->next = new_node;
    return;
  }

  void print() {
    Node<T> *tmp = head;
    while (tmp) {
      std::cout << tmp->data << std::endl;
      tmp = tmp->next;
    }
  }
};
template <class T>
class Stack {
  Node<T> *top;

 public:
  Stack() { this->top = nullptr; }
  ~Stack() {
    while (top) {
      Node<T> *tmp = top;
      top = top->next;
      delete tmp;
    }
  }

  void push(T data) {
    Node<T> *new_node = new Node<T>(data);
    new_node->next = this->top;
    this->top = new_node;
  };
  T pop() {
    if (this->isEmpty()) {
      throw "Stack is empty";
    }
    Node<T> *old_top = this->top;
    T data = old_top->data;
    this->top = this->top->next;
    delete old_top;
    return data;
  };
  T peek() { return this->top->data; };
  bool isEmpty() { return !top; };
};

}  // namespace ctci

int main() {
  std::cout << "Running programm" << std::endl;
  ctci::SinglyLinkedList<double> doubleList;
  doubleList.insertBack(2.3);
  doubleList.insertBack(1.2);
  doubleList.insertBack(0.002);
  doubleList.insertBack(2);
  doubleList.print();
  ctci::SinglyLinkedList<int> intList;
  intList.insertBack(1);
  intList.insertBack(2);
  intList.insertBack(3);
  intList.print();
  ctci::SinglyLinkedList<std::string> stringList;
  stringList.insertBack("hello");
  stringList.insertBack("World");
  stringList.print();

  ctci::Stack<int> intStack;
  intStack.push(1);
  std::cout << intStack.peek() << std::endl;
  std::cout << (intStack.isEmpty() ? "Empty" : "Not empty") << std::endl;
  intStack.push(3);
  std::cout << intStack.peek() << std::endl;
  std::cout << intStack.pop() << std::endl;
  std::cout << intStack.peek() << std::endl;
  std::cout << intStack.pop() << std::endl;
  std::cout << (intStack.isEmpty() ? "Empty" : "Not empty") << std::endl;

  return 0;
}
