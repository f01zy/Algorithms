#include <iostream>

class Node final {
public:
  Node(int value) : value(value) {};
  Node(Node &) = delete;

  int value;
  Node *next = nullptr;
};

class LinkedList final {
public:
  LinkedList() {};
  LinkedList(LinkedList &) = delete;

  ~LinkedList() {
    Node *node = head;

    while (node) {
      Node *temp = node->next;
      delete node;
      node = temp;
    }
  };

  void append(int value) {
    if (!head) {
      head = new Node(value);
      return;
    }

    Node *node = head;

    while (node->next) {
      node = node->next;
    }

    node->next = new Node(value);
  };

  void remove() {
    if (!head) {
      return;
    }

    if (!head->next) {
      delete head;
      head = nullptr;
      return;
    }

    Node *node = head;

    while (node->next && node->next->next) {
      node = node->next;
    }

    delete node->next;
    node->next = nullptr;
  };

  void print() {
    if (!head) {
      return;
    }

    Node *node = head;

    while (node) {
      std::cout << node->value;

      if (node->next) {
        std::cout << " -> ";
      }

      node = node->next;
    }

    std::cout << std::endl;
  }

private:
  Node *head = nullptr;
};

int main() {
  LinkedList linkedList;

  linkedList.append(1);
  linkedList.append(7);
  linkedList.append(3);
  linkedList.append(9);
}
