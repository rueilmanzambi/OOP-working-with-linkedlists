/////////////////////////////////
//                             //
// Rueil Manzambi              //
// hpp file for linkedlist.h   //
//                             //
/////////////////////////////////


#include <iostream>
using namespace std;


template <typename T>
LinkedList<T>::~LinkedList()
{
  clear();
  delete m_head;
}

template <typename T>
const LinkedList<T>& LinkedList<T>:: operator= (const LinkedList<T>& rhs)
{
  clear();
  LLNode<T>* p = m_head;
  LLNode<T>* q = rhs.m_head;
  while (q->m_next != NULL)
  {
    insert(q-> m_data,p);
    q = q -> m_next;
    p = p -> m_next;
  }
  m_size = rhs.m_size;
  return *this;
}

template <typename T>
LinkedList<T> :: LinkedList(const LinkedList<T>& rhs)
{
  m_head = new LLNode<T>;
  m_head -> m_next = NULL;
  *this = rhs;
}

template <typename T>
int LinkedList<T> :: size() const
{
  return m_size;
}

template <typename T>
bool LinkedList<T> :: isEmpty() const
{
  if (m_size == 0)
    return true;
  else
    return false;
}

template <typename T>
LLNode<T>* LinkedList<T> :: getFirstPtr()
{
  if (m_size == 0)
    return NULL;
  else
    return m_head;
}

template <typename T>
LLNode<T>* LinkedList<T> :: getAtPtr(int i)
{
  if (i >= 0 && i <= m_size)
  {
    LLNode<T>* tmp = m_head;
    for (int j = 0; j < i; j++)
      tmp = tmp -> m_next;
    return tmp;
  }
  else
    return NULL;
}

template <typename T>
void LinkedList<T> :: clear()
{
  LLNode<T>* tmp = m_head;
  while (m_head -> m_next != NULL)
  {
    m_head = tmp -> m_next;
    delete tmp;
    tmp = m_head;
  }
  m_size = 0;
  return;
}

template <typename T>
void LinkedList<T> :: insert_front(const T& x)
{
  if (getFirstPtr() != NULL)
    insert(x,getFirstPtr());
  else
    insert(x,m_head);
  return;
}

template <typename T>
void LinkedList<T> :: insert_back(const T& x)
{
  if (getAtPtr(m_size) != NULL)
    insert(x,getAtPtr(m_size));
  else
    insert(x,m_head);
  return;
}

template <typename T>
void LinkedList<T> :: insert(const T& x, LLNode<T>* pos)
{
  LLNode<T>* tmp = new LLNode<T>;
  *tmp = *pos;
  pos->m_data = x;
  pos -> m_next = tmp;
  m_size++;
  return;
}

template <typename T>
void LinkedList<T> :: remove_front()
{
  remove(getFirstPtr());
  return;
}

template <typename T>
void LinkedList<T> :: remove_back()
{
  remove(getAtPtr(m_size -1));
  return;
}

template <typename T>
void LinkedList<T> :: remove(LLNode<T>* pos)
{
  LLNode<T>* tmp = pos -> m_next;
  *pos = *tmp;
  delete tmp;
  m_size--;
}

template <typename T>
bool LinkedList<T> :: operator==(const LinkedList<T>& rhs) const
{
  bool result = true;
  bool comparing = true;
  if (m_size == rhs.m_size)
  {
    LLNode<T>* tmp1 = m_head;
    LLNode<T>* tmp2 = rhs.m_head;
    while ((tmp1 -> m_next != NULL) && (comparing))
    {
      if (tmp1 -> m_data != tmp2 -> m_data)
      {
        comparing = false;
        result = false;
      }
      tmp1 = tmp1 -> m_next;
      tmp2 = tmp2 -> m_next;
    }
    return result;
  }
  else
  {
    result = false;
    return result;
  }
}

template <typename T>
LLNode<T>* LinkedList<T> :: find(const T& x)
{
  LLNode<T>* tmp = m_head;
  LLNode<T>* result = NULL;
  while (tmp -> m_next != NULL)
  {
    if (tmp -> m_data == x)
      return tmp;
    tmp = tmp -> m_next;
  }
  return result;
}

template <typename T>
void LinkedList<T> :: reverse()
{
  LinkedList <T> tmplist;
  LLNode<T>* tmp = m_head;
  while (tmp -> m_next != NULL)
  {
    tmplist.insert_front(tmp -> m_data);
    tmp = tmp -> m_next;
  }
  clear();
  *this = tmplist;
  return;
}

template <typename T>
void LinkedList<T> :: append(const LinkedList<T>& l2)
{
  LLNode<T>* tmp = l2.m_head;
  while(tmp -> m_next != NULL)
  {
    insert_back(tmp -> m_data);
    tmp = tmp -> m_next;
  }
  return;
}

template <typename T>
void LinkedList<T> :: slice(const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop)
{
  if (!l2.isEmpty())
  {
    clear();
    LLNode<T>* tmp = start;
    while (tmp -> m_next != stop -> m_next)
    {
      insert_back(tmp -> m_data);
      tmp = tmp -> m_next;
    }
  }
  return;
}

template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list)
{
  LLNode<T>* tmp = list.m_head;
  out << "[ ";
  for (int i = 0; i < list.m_size; i++)
  {
    out << tmp -> m_data << ", ";
    tmp = tmp -> m_next;
  }
  out << "]";
  return out;
}
