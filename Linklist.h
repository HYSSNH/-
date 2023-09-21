#ifndef LINKLIST_H
#define LINKLIST_H

#include "head.h"

template <class Element>
class Linklist
{
public:
    Linklist();
    Linklist(Element a[],int n);
    ~Linklist();
    int getLength();
    Element getItem(int i);
    int locate(Element x);
    void insert(int i,Element x);
    Element remove(int i);
    bool empty();
    void printlist();
    void reversePrint();
private:
    Node <Element> *head;
};

#endif // LINKLIST_H
