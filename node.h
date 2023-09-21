#ifndef NODE_H
#define NODE_H

template <class Element>
struct Node
{
    Element data;
    Node <Element> *next;
};

#endif // NODE_H
