#include <iostream>

template <typename T>
class node;
template <typename T>
class Pylist;

template <typename T>
class node {
private:
  node *next;
  node *prev;
  T body;
  friend class Pylist<T>;
  template <typename U>
  friend std::ostream &operator<<(std::ostream &strm, const Pylist<U> &list);
};

template <typename T>
class Pylist {
private:
  node<T> *head;
  node<T> *tail;
  int count;
  friend class Pylist<T>;
  template <typename U>
  friend std::ostream &operator<<(std::ostream &strm, const Pylist<U> &list);

public:
  Pylist();
  ~Pylist();
  void append(T value);
  T pop(int idx = -1);
  int len();
  T operator[](int index);
};

template <typename T>
Pylist<T>::Pylist() {
  this->head = NULL;
  this->tail = NULL;
  this->count = 0;
};

template <typename T>
Pylist<T>::~Pylist() { // Release all objects being allocated to heap memory.
  node<T> *garbcoll;
  node<T> *temp;
  temp = this->head;
  for (; temp != NULL;) {
    garbcoll = temp;
    temp = temp->next;
    delete (garbcoll);
  };
};

template <typename T>
void Pylist<T>::append(T value) {
  node<T> *temp = new node<T>;
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

template <typename T>
int Pylist<T>::len() { return this->count; };

template <typename T>
T Pylist<T>::pop(int idx) { // if use template, setting default value must be in the definition line not in implementation line.
  try {
    if (idx > this->count - 1) // exception
      throw idx;
    if (idx * -1 > this->count) // exception
      throw idx;

    node<T> *temp;
    node<T> *target;
    T result;

    // preprocessing index
    if (idx == this->count - 1) {
      idx = -1;
    };
    if (idx < 0) {
      if (idx * -1 > this->count / 2) {
        idx = this->count + idx;
      };
    } else {
      if (idx + 1 > this->count / 2) {
        idx = (this->count - idx) * -1;
      };
    };

    // pop process start
    if (idx < 0) {     // if index < 0
      if (idx == -1) { // last element
        target = this->tail;
        this->tail = this->tail->prev;
        this->tail->next = NULL;
      } else {
        temp = target = this->tail;
        for (int i = 0; i > idx + 1; i--) {
          temp = target;
          target = target->prev;
        };
        temp->prev = target->prev;
        target->prev->next = temp;
      };
    } else { // if index > -1
      temp = target = this->head;
      if (idx == 0 || this->count == 1) { // first element
        this->head = this->head->next;
      } else { // and the others
        for (int i = 0; i < idx; i++) {
          temp = target;
          target = target->next;
        };
        temp->next = target->next;
        target->next->prev = temp;
      };
    };
    result = target->body;
    delete (target);
    this->count--;
    return result;
  } catch (int idx) {
    std::cout << "index out of range: index(" << idx
              << ") is bigger than the list size." << std::endl;
    exit(1); // kill process (common error)
  }
};

template <typename T>
T Pylist<T>::operator[](int index) { // add process to handle if index < 0
  try {
    if (index > this->count - 1) // exception
      throw index;
    if (index * -1 > this->count) // exception
      throw index;

    // index preprocessing
    if (index < 0) {
      if (index * -1 > this->count / 2) {
        index = this->count + index;
      };
    } else {
      if (index + 1 > this->count / 2) {
        index = (this->count - index) * -1;
      };
    };

    node<T> *temp;

    if (index < 0) {
      temp = this->tail;
      for (int i = 0; i > index + 1; i--) {
        temp = temp->prev;
      };
    } else {
      temp = this->head;
      for (int i = 0; i < index; i++) {
        temp = temp->next;
      };
    };
    return temp->body;
  } catch (int idx) {
    std::cout << "index out of range: index(" << idx
              << ") is bigger than the list size." << std::endl;
    exit(1); // kill process (common error)
  };
};

// instead of to sting, overloading io operators
template <typename U>
std::ostream &operator<<(std::ostream &strm, const Pylist<U> &list) {
  node<U> *temp;
  temp = list.head;
  std::cout << "[";
  for (; temp != NULL;) {
    std::cout << " " << temp->body;
    temp = temp->next;
  };
  std::cout << " ]";
  return strm;
};

int main() {
  Pylist<int> dl;
  dl.append(10);
  dl.append(20);
  dl.append(30);
  dl.append(40);
  dl.append(50);
  std::cout << dl << std::endl;
  std::cout << dl[-1] << std::endl; // error
  std::cout << dl << std::endl;
    Pylist<char> dc;
    dc.append('a');
    dc.append('b');
    dc.append('c');
    std::cout << dc << std::endl;
    std::cout << dc[-2] << std::endl;
};
