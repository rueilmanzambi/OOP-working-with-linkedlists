/* @file: linkedlist.h
 * Definition of templated class LinkedList
 * Implementation of List A.D.T.
 * @C - Galaxy Express Software
 *
 * Version 21.3
 */

/* __________________
  /                  \
  | LinkedList Class |
  \__________________/

    Purpose: Implements a List ADT using a dynamically allocated
        linked list to store the elements of the list.

    Design: This linked list implementation is designed with 2 classes, 
        a "Node" class to store data and a "LinkedList" class to manage the nodes.
        The "LinkedList" class has a pointer "head" to the first Node in the list.
        This is a VERY POINTER HAPPY design...   :-)

    Error Handling: Whenever a function is given invalid parameter values
        the list should remain unchanged.
        If such function returns a value this value is specified in the
        function description.

*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>


// ---------------------- Class Prototypes ---------------------

template <class T> 
class LLNode;

template <class T> 
class LinkedList;

// ---------------------- Function Prototypes ---------------------

// Utility Function for Printing
// Purpose: prints a LinkedList
template <typename T>
std::ostream& operator<< (std::ostream& out, const LinkedList<T>& list);


// ---------------------- Class Node -----------------------
template <class T>
class LLNode
{
public:
  T m_data;              // Data to be stored
  LLNode<T>* m_next;     // Pointer to the next element in the list


  // Purpose: Default constructor
  // Postconditions: next pointer set to NULL
  // --- DEFINED HERE ---
  LLNode() : m_next(NULL) {}

  // Purpose: Auxiliaty constructor, construct from parameters
  // Postconditions: data and next pointer set to parameters
  // --- DEFINED HERE ---
  LLNode(const T& x, LLNode<T>* p) : m_data(x), m_next(p) {}
};


// ---------------------- Class LinkedList ---------------------
template <class T>
class LinkedList
{

  LLNode<T>* m_head;     // Pointer to the first element
  int m_size;            // The number of elements in the list


public:

  // Purpose: Default constructor
  // Postconditions: the list represents the empty list.
  //   m_size is initialized to 0
  //   m_head points to a "sentinel" node.
  //  -- DEFINED HERE ---
  LinkedList() : m_size(0)
    { m_head = new LLNode<T>; }


  // -------------
  // --------- Big 3 Member Functions ---
  // -------------

  // Purpose: Destructor
  // Postconditions: All dynamically allocated Nodes are de-allocated
  ~LinkedList();

  // Purpose: performs a deep copy of the data from rhs into this linkedlist
  // Parameters: rhs is linked list to be copied
  // Returns: *this
  // Postconditions: this list contains same data values (in the same order)
  //     as are in rhs; any memory previously used by this list has been
  //     deallocated.
  const LinkedList<T>&  operator= (const LinkedList<T>& rhs);

  // Purpose: copy constructor
  // Parameters: rhs is the LinkedList that is to be copied
  // Postconditions: this list contains same data values (in same order) 
  //      as in rhs.
  LinkedList(const LinkedList<T>& rhs);



  // -------------
  // --------- Basic Accessor Operations ---
  // -------------

  // Purpose: accessor function to the size the list
  // Returns: current size of the list
  int size() const;

  // Purpose: determines whether the list is empty
  // Returns: 'true' if list is empty; 'false' otherwise
  bool isEmpty() const;

  // Purpose: Get a pointer to the first element node
  // Returns: pointer to the first node in the list; 
  //     returns NULL if the list is empty
  LLNode<T>* getFirstPtr();

  // Purpose: accessor function for a node in the list
  // Returns: pointer to the node at the i'th position in the list;
  //          counting starts from '0' .
  //     returns NULL if no such element exists.
  LLNode<T>* getAtPtr(int i);



  // -------------
  // --------- Basic Mutator Operations ---
  // -------------

  // Purpose: effectively "empties" the list, 
  //          Turn the list into an empty list.
  // Postconditions: dynamically allocated non-sentinel nodes 
  //          are de-allicated.
  //          m_size is set to zero.
  //          m_head points to a sentinel node.
  void clear();

  // Purpose: insert element x in the front of the list 
  // Parameters: x is data value to inserted
  // Postconditions: x is the first element of the list
  void insert_front(const T& x);

  // Purpose: insert element x in the back of the list 
  // Parameters: x is data value to inserted
  // Postconditions: x is the last element of the list
  void insert_back(const T& x);

  // Purpose: puts the data value x at the position pointed by pos
  // Parameters: x : data value to be inserted
  //     pos : pointer to the position to insert x at.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: x is inserted at the position pointed by pos
  void insert(const T& x, LLNode<T>* pos);


  // Purpose: remove the element in the front of the list 
  // Postconditions: the first element of the list is removed
  void remove_front();

  // Purpose: removes the element at the back of the list 
  // Postconditions: the last element of the list is removed
  void remove_back();

  // Purpose: remove the element in the position pointed by pos
  // Parameters: pos : pointer to the position to remove.
  // Preconditions: pos is a pointer to a node in this list.
  // Postconditions: element pointed by pos is removed from the list
  void remove(LLNode<T>* pos);


  // --------
  // ---- Complex Operations ---
  // --------

  // Purpose: determines whether this list is identical to rhs list in
  //      terms of data values and their order in the list
  // Parameters: rhs is list to be compared to this list
  // Returns: true if lists are identical; otherwise, false
  bool operator== (const LinkedList<T>& rhs) const;

  // Purpose: determines whether x is in the list
  // Parameters: x : data value to be found
  // Returns: a pointer to the position of x in the list; 
  //     otherwise, NULL
  LLNode<T>* find(const T& x);

    
  // Purpose: reverses the elements from the list
  // Postconditions: the list is now in reverse order
  void reverse();

  // Purpose: appends two lists
  // Parameters: l2, a list to append to the end of 'this' list
  // Postconditions: elements of l2 are appended to 'this' list 
  void append(const LinkedList<T>& l2);
  
  // Purpose: Makes 'this' list a slice of another list.
  // Parameters:    l2, the source of a slice of data.
  //                start, pointer to the begining of the slice.
  //                end, pointer to the end of the slice.
  // Preconditions: 'start' and 'end' are pointers to nodes in the l2 list.
  //                'start' precedes 'end' in the l2 list
  // Postconditions: 'this' list is made a copy of the elements between 'start'
  //                  and 'end' (*exclusive*) in l2.
  void slice( const LinkedList<T>& l2, LLNode<T>* start, LLNode<T>* stop);


  // Purpose: prints the LinkedList
  friend std::ostream& operator<< <> (std::ostream& out, 
                                      const LinkedList<T>& list);

}; // of class LinkedList



#include "linkedlist.hpp"
#endif
