#include <iostream>

class node {
private:
  node *next;
  node *prev;
  int body;
  friend class Pylist;
};

class Pylist {
private:
  node *head;
  node *tail;
  int count;

public:
  Pylist();
  ~Pylist();
  void append(int value);
  int pop(int idx);
  void print();
  int len();
  int operator[](int index);
};

Pylist::Pylist() {
  this->head = NULL;
  this->tail = NULL;
  this->count = 0;
};

Pylist::~Pylist() { // Release all objects being allocated to heap memory.
  node *garbcoll;
  node *temp;
  temp = this->head;
  for (; temp != NULL;) {
    garbcoll = temp;
    temp = temp->next;
    delete (garbcoll);
  };
};

void Pylist::append(int value) {
  node *temp = new node;
  temp->body = value;
  temp->next = NULL;
  temp->prev = NULL;
  if (this->head == NULL) {
    this->head = temp;
  } else {
    this->tail->next = temp;
    temp->prev = this->tail;
  };
  this->tail = temp;
  this->count++;
};

void Pylist::print() {
  node *temp;
  temp = this->head;
  std::cout << "[";
  for (; temp != NULL;) {
    std::cout << " " << temp->body;
    temp = temp->next;
  };
  std::cout << " ]" << std::endl;
};

int Pylist::len() { return this->count; };

int Pylist::pop(int idx = -1) {
  node *temp;
  node *target;
  int result;
  temp = target = this->head;
  if (idx > this->count - 1) { // exception, next
                               // time I'll process it by using try
    std::cout << "index out of range" << std::endl;
    return -1;
  };
  if (idx == this->count - 1) {
    idx = -1;
  };
  // pop process start
  if (idx == 0 || this->count == 1) { // first element
    this->head = this->head->next;
  } else if (idx == -1) { // last element
    target = this->tail;
    this->tail = this->tail->prev;
    this->tail->next = NULL;
  } else { // and the others
    for (int i = 0; i < idx; i++) {
      temp = target;
      target = target->next;
    };
    temp->next = target->next;
    target->next->prev = temp;
  };
  result = target->body;
  delete (target);
  this->count--;
  return result;
};

int Pylist::operator[](int index) {
  if (index > this->count - 1) { // same as pop
    std::cout << "index out of range" << std::endl;
    return -1;
  };
  node *temp;
  if (index > this->count / 2) {
    temp = this->tail;
    for (int i = this->count - 1; i > index; i--) {
      temp = temp->prev;
    };
  } else {
    temp = this->head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    };
  };
  return temp->body;
};

int main() {
  Pylist dl = Pylist();
  dl.append(10);
  dl.append(20);
  dl.append(30);
  dl.append(40);
  dl.append(50);
  dl.print();
  std::cout << dl.pop(2) << std::endl;
  std::cout << dl.pop(0) << std::endl;
  std::cout << dl.pop() << std::endl;
  dl.print();
  dl.append(dl.pop(0));
  dl.print();
  std::cout << dl[1] << std::endl;
};
