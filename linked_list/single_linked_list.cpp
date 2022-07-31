#include <iostream>

class node {
private:
  int body;
  node *next;
  friend class Listpy;
};

class Listpy {
private:
  node *head;
  node *tail;
  int count;

public:
  Listpy();
  ~Listpy();
  void append(int value);
  int pop(int index);
  void print();
  int len();
  int operator[](int index);
};

///////////////////// Listpy class definition
Listpy::Listpy() {
  this->head = NULL;
  this->tail = NULL;
  this->count = 0;
};

Listpy::~Listpy() {
  node *garbcollector;
  node *temp; // new node is simillar to (node*)malloc(sizeof(node*)) in C
  temp = this->head; // first node
  for (; temp != NULL;) {
    // std::cout << temp->body << std::endl; // to check
    garbcollector = temp;
    temp = temp->next;
    delete (garbcollector); // simillar to free(garbcollector) in C
  };
};

void Listpy::append(int value) {
  node *temp = new node;
  temp->body = value;
  temp->next = NULL;
  if (this->head == NULL) {
    this->head = temp;
  } else {
    this->tail->next = temp;
  };
  this->tail = temp;
  this->count++;
};

void Listpy::print() {
  node *temp;
  temp = this->head;
  std::cout << "[";
  for (; temp != NULL;) {
    std::cout << " " << temp->body;
    temp = temp->next;
  };
  std::cout << " ]" << std::endl;
};

int Listpy::len() { return this->count; };

int Listpy::pop(int index = -1) {
  node *temp;
  node *target;
  int result;
  temp = target = this->head;
  if (this->head == NULL) {
    std::cout << "No such elements" << std::endl;
    return -1;
  }
  if (index == this->count - 1) { // if the argument is last index
    index = -1;
  } else if (index > this->count - 1) {
    std::cout << "No such elements" << std::endl;
    return -1;
  };
  if (index == 0 || this->count == 1) { // pop first element
    this->head = this->head->next; // target is already pointing address same
                                   // head (in line 75)
  } else if (index == -1) {        // pop last element
    for (; temp != NULL;) {
      if (temp->next == NULL) {
        this->tail = target;
      };
      target = temp;
      temp = temp->next;
    };
    this->tail->next = NULL;
  } else { // pop index's element
    for (int i = 0; i < index; i++) {
      temp = target;
      target = target->next;
    };
    temp->next = target->next;
  };
  result = target->body;
  delete (target);
  this->count--;
  return result;
};

int Listpy::operator[](int index) {
  node *temp;
  temp = this->head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  };
  return temp->body;
};

int main() {
  Listpy mylist = Listpy();
  mylist.append(10);
  mylist.append(20);
  mylist.append(30);
  mylist.append(40);
  mylist.append(50);
  mylist.print();
  std::cout << mylist.pop(2) << std::endl; // 30
  std::cout << mylist.pop(0) << std::endl; // 10
  std::cout << mylist.pop() << std::endl;  // 50
  mylist.print();
  std::cout << mylist.pop() << std::endl;
};
