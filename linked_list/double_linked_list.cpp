#include <iostream>

class node;
class Pylist;
// void concat(char res[], char str[]);

class node {
private:
  node *next;
  node *prev;
  int body;
  friend class Pylist;
  friend std::ostream &operator<<(std::ostream &strm, const Pylist &list);
};

class Pylist {
private:
  node *head;
  node *tail;
  int count;
  friend std::ostream &operator<<(std::ostream &strm, const Pylist &list);

public:
  Pylist();
  ~Pylist();
  void append(int value);
  int pop(int idx);
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

// instead of to sting, overloading io operators
std::ostream &operator<<(std::ostream &strm, const Pylist &list) {
  node *temp;
  temp = list.head;
  std::cout << "[";
  for (; temp != NULL;) {
    std::cout << " " << temp->body;
    temp = temp->next;
  };
  std::cout << " ]";
  return strm;
};

// //////////////additional funcs
// void concat(char res[], char str[]) {
//   int count;
//   for (count = 0; res[count] != '\0'; count++)
//     ;
//   for (int i = 0; str[i] != '\0'; i++) {
//     res[count] = str[i];
//     count++;
//   };
//   res[count] = '\0';
// };

int main() {
  Pylist dl = Pylist();
  Pylist ddl = Pylist();
  dl.append(10);
  dl.append(20);
  std::cout << dl << std::endl;
  ddl.append(100);
  ddl.append(200);
  std::cout << dl << ddl << std::endl;
  std::cout << "hello" << std::endl;
};
