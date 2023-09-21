#include <Linklist.h>

//template  <class Element >//头插法
//Linklist <Element> ::Linklist(Element a[],int n)
//{
//    head = new Node<Element>;
//    head->next = nullptr;
//    for (int i = 0;i < n;i++)
//    {
//        Node<Element> *s = new Node <Element>;
//        s->data = a[i];
//        s->next = head->next;
//        head->next = s;
//    }
//}


template  <class Element >//尾插法
Linklist <Element> ::Linklist(Element a[],int n)
{
    head = new Node<Element>;
    head->next = nullptr ;
    Node<Element> *rear = head;
    for (int i = 0;i < n;i++)
    {
        Node<Element> *s = new Node <Element>;
        s->data = a[i];
        s->next = rear->next;
        rear->next = s;
        rear = s;
    }
}



template < class Element >//无参构造
Linklist<Element>::Linklist()
{
    head = new Node<Element>;//创建头节点
    head->next = nullptr;
}

template  < class Element >//析构
Linklist <Element> :: ~Linklist()
{
    Element *p = head;
    while(p)
    {
        Element *q = p;
        p = p->next;
        delete q;
    }
}

template < class Element >//判空
bool Linklist <Element> ::empty()
{
    if(head->next == nullptr)   return true;
    else return false;
}

template < class Element >//输出
void Linklist <Element> ::printlist()
{
    Element *p = head->next;
    while (p != nullptr)
    {
        qDebug() << p->data << " ";
        p = p->next;
    }
}

template < class Element >//遍历
int Linklist <Element> ::getLength()
{
//    qDebug()<<"getLength  head";
    Node<Element> *p = head->next;
    int count = 0;
    while(p != nullptr)
    {
        count++;
        p = p->next;
    }
    return count;
//    qDebug()<< "getLength rear";
}

template < class Element >//按位查找
Element Linklist <Element>::getItem(int i)
{
    Node<Element> *p = head->next;
    int count = 1;
    while (p != nullptr && count < i)
    {
        p = p->next;
        count++;
    }
    if (p == nullptr) qDebug() << "查找位置错误";
    else return p->data;
}

template < class Element >//按值查找
int Linklist <Element> ::locate(Element x)
{
    Element *p = head->next;
    int j = 1;
    while (p != nullptr && p->data != x)
    {
        p = p->next;
        j++;
    }
    if (p != nullptr)   return j;
    else return 0;
}

template < class Element >//插入
void Linklist <Element> ::insert(int i,Element x)
{
    Node<Element> *p = head;
    int j = 0;
    while (p != nullptr && j < i-1)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr)   qDebug() << "插入位置异常";
    else
    {
        Node<Element>  *s = new Node <Element>;
        s->data = x;
        s->next = p->next ;
        p->next = s ;
    }
}

template < class Element >//删除
Element Linklist <Element> ::remove(int i)
{
    Node<Element> *p = head;
    int j = 0;
    while (p != nullptr && j < i-1)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr || p->next == nullptr) qDebug() << "删除位置异常";
    else
    {
        Node<Element> *q = p->next;
        Element x;
        x = q->data;
        p->next = q->next;
        delete q;
        return x;
    }
}

template < class Element >//逆序
void  Linklist<Element>:: reversePrint()
{
    // 逆序输出
    Node<Element>* reverseHead = nullptr;//1. 定义一个反转后的新链表头指针reverseHead,初始化为nullptr
    int len = getLength(); // 获取原链表长度
    int i = 0;

//    qDebug()<<head->data.name;

    while (head != nullptr)//2. 通过while循环遍历原链表,每次循环中:
    {
      Node<Element>* temp = head;//(1) 保存当前头节点指针tmp
      head = head->next;//(2) 将head移动到下一个节点

      temp->next = reverseHead;//(3) 修改tmp的next指向新链表头reverseHead
      reverseHead = temp;//(4) 然后将tmp作为新的链表头

      qDebug()<<temp->data.name;

      i++;
          if (i == len)
          {
            reverseHead = temp;
            temp->next = nullptr;
            break;
          }
    }
    head = reverseHead;//3. 遍历结束后,将原链表头head指向反转后的新链表头reverseHead

    qDebug()<<head->data.name;
}


//    // 保存反转后链表的头节点
//      Node<Element>* newHead = reverseHead;
//      // 找到反转后链表的下一个节点
//      Node<Element>* nextNode = newHead->next;
//      // 原链表头指针指向反转链表的下一个节点
//      head = nextNode;
//      // 断开反转链表头节点的next指针
//      newHead->next = nullptr;


//template <class Element>
//void Linklist<Element>::reversePrint()
//{
//  Node<Element>* reverseHead = nullptr;

//  while (head != nullptr)
//  {
//    Node<Element>* tmp = nullptr;
//    // 特殊判断尾节点
//    if (head->next == nullptr) tmp = head;
//    else
//    {
//      tmp = head;
//      head = head->next;
//    }
//    tmp->next = reverseHead;
//    reverseHead = tmp;
//  }
//  head = reverseHead;
//}
