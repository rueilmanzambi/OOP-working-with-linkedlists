#include <iostream>
#include "linkedlist.h"

using namespace std;

//---------------------------------------------------------------------
void test00() {
  
  LinkedList < string > A;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #0  * " << endl;
  cout << " ***************** " << endl;


  cout << "Is the list empty? " << boolalpha << A.isEmpty() <<endl; 
  cout << A << endl;
  cout << "Size of A = " << A.size() << endl;

  //TEST : Inserting 4 names to a
  cout << endl << "TEST : Inserting 4 names into A" << endl;

  A.insert_front(string("Leonardo"));
  A.insert_front(string("Donatello"));
  A.insert_front(string("Michelangelo"));
  A.insert_front(string("Raphael"));

  cout << A << endl;
  cout << "Size of a = " << A.size() << endl;

  //TEST : Clearing A
  cout << endl << "TEST : Clearing A" << endl;
  A.clear();
  cout << A << endl;
  cout << "Size of A = " << A.size() << endl;

  cout << endl << "Test 00 - Done!" << endl;
} 
  


//---------------------------------------------------------------------
void test01() {
  
  LinkedList < int > A;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #1  * " << endl;
  cout << " ***************** " << endl;


  cout << "Is the list empty? " << boolalpha << A.isEmpty() <<endl; 
  cout << A << endl;
  cout << "Size of A = " << A.size() << endl;

  //TEST : Inserting 10 numbers to a
  cout << endl << "TEST : Inserting 10 numbers to A. back" << endl;
  for (int k=0; k<10; k++){
    A.insert_back(k*2+1);
  } 
  cout << A << endl;
  cout << "Size of a = " << A.size() << endl;
  
  //TEST : Inserting 10 numbers to a
  cout << endl << "TEST : Inserting 10 numbers to A, front" << endl;
  for (int k=0; k<10; k++){
    A.insert_front(k*2);
  } 
  cout << A << endl;
  cout << "Size of a = " << A.size() << endl;

  cout << endl << "Test 01 - Done!" << endl;
  
  //TEST : Destroying A
} 
  


//---------------------------------------------------------------------
void test02() {
  
  LinkedList <int> A;
  LLNode <int>* p;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #2  * " << endl;
  cout << " ***************** " << endl;

  //TEST : Inserting 13 numbers to a
  cout << endl << "TEST : Inserting 13 numbers into A" << endl;
  for (int k=0; k<13; k++){
    A.insert_front(k*4);
  } 
  cout << A << endl;
  cout << "Size of a = " << A.size() << endl;

  // TEST : Acessing elements;
  cout << endl << "TEST : Accessing elements" << endl;
  p = A.getFirstPtr();
  cout << "First = " << p->m_data << endl;
  p = A.getAtPtr(5);
  cout << "5th = " << p->m_data << endl;
 
  cout << endl << "Test 02 - Done!" << endl;
} 



//---------------------------------------------------------------------
void test03() {
  
  LinkedList <char> A;
  LLNode <char>* p;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #3  * " << endl;
  cout << " ***************** " << endl;

  //TEST : Inserting 10 elements to a
  cout << endl << "TEST : Inserting 10 elements into A" << endl;
  for (int k=0; k<10; k++){
    A.insert_front(k+'a');
  } 
  cout << A << endl;
  cout << "Size of a = " << A.size() << endl;

  // TEST : Inserting elements;
  cout << endl << "TEST : Inserting elements at 5 and 7" << endl;
  p = A.getAtPtr(5); 
  A.insert('w', p);
  p = A.getAtPtr(7);
  A.insert('w', p);
  cout << A << " " << A.size() << endl;

  // TEST : Removing elements;
  cout << endl << "TEST : Removing elements 4 and 8, and 9" << endl;
  p = A.getAtPtr(4);
  A.remove(p);
  p = A.getAtPtr(8);
  A.remove(p);
  cout << A << " " << A.size() << endl;
  p = A.getAtPtr(9);
  A.remove(p);
  cout << A << " " << A.size() << endl;


  // TEST : Removing elements;
  cout << endl << "TEST : Removing front * 2" << endl;
  A.remove_front();
  A.remove_front();
  cout << A << " " << A.size() << endl;

  cout << endl << "TEST : Removing back * 2" << endl;
  A.remove_back();
  A.remove_back();
  cout << A << " " << A.size() << endl;

  // TEST : Finding elements;
  cout << endl << "TEST : Finding e" << endl;
  p = A.find('e');
  cout << endl << "e has been found! " << p->m_data << "."<< endl;
  

  cout << endl << "Test 03 - Done!" << endl;
} 



//---------------------------------------------------------------------
void test04() {
	
  LinkedList <int> A;
  LinkedList <int> B;
  LinkedList <int> C;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #4  * " << endl;
  cout << " ***************** " << endl;

  //TEST : Inserting 10 elements to a
  cout << endl << "TEST : Inserting 10 elements into A" << endl;
  for (int k=0; k<10; k++){
    A.insert_front(k*10);
  } 
  cout << A << endl;
  cout << "Size of A = " << A.size() << endl;
  
  //TEST : Inserting 10 elements into b
  cout << endl << "TEST : Inserting 10 elements into B" << endl;
  for (int k=0; k<10; k++){
    B.insert_front(20+k*5);
  } 
  cout << B << endl;
  cout << "Size of B = " << B.size() << endl;
  
  // TEST : Comparison Operator==;
  cout << endl << "TEST : Comparison" << endl;
  cout << "Is A == B ? " << boolalpha << (A == B) << endl;
  
  // TEST : Operator=
  cout << endl << "TEST : Operator=" << endl;
  C = A;
  cout << "A = " << A << " " << A.size() << endl;
  cout << "C = " << C << " " << C.size() << endl;
  cout << "Is A == C ? " << boolalpha << (A == C) << endl;
  
  cout << endl << "Making sure is a deep copy" << endl;
  C.insert_front(42);
  C.insert_back(43);
  cout << "A = " << A << " " << A.size() << endl;
  cout << "C = " << C << " " << C.size() << endl;
  
  
  // TEST : Copy Constructor
  cout << endl << "TEST : Copy Constructor" << endl;
  LinkedList<int> D ( A );
  cout << "A = " << A << " " << A.size() << endl;
  cout << "D = " << D << " " << D.size() << endl;
  cout << "Is A == D ? " << boolalpha << (A == D) << endl;
  
  cout << endl << "Making sure is a deep copy" << endl;
  D.insert_front(111);
  D.insert_back(222);
  cout << "A = " << A << " " << A.size() << endl;
  cout << "D = " << D << " " << D.size() << endl;
	
  cout << endl << "Test 04 - Done!" << endl;
}


//---------------------------------------------------------------------
void test05() {
  
  LinkedList<int> A;
  LinkedList<int> B;
  LinkedList<int> C;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #5  * " << endl;
  cout << " ***************** " << endl;

  //TEST : Inserting 10 elements to a
  cout << endl << "TEST : Inserting 7 elements into A and B" << endl;
  for (int k=0; k<7; k++){
    A.insert_front(k*2+10);
    B.insert_front(3*k+10);
  } 
  cout << "A = " << A << " " << A.size() << endl;
  cout << "B = " << B << " " << B.size() << endl;

  // TEST : Append
  cout << endl << "TEST : Append B into A" << endl;
  A.append(B);
  cout << "Making sure it is a deep copy.." << endl;
  B.insert_back(77);
  cout << B << " " << B.size() << endl;
  cout << A << " " << A.size() << endl;  
    
  // TEST : Reverse;
  cout << endl << "TEST : Reversing A" << endl;
  A.reverse();
  cout << A << " " << A.size() << endl;
    

  LLNode<int> *p;
  LLNode<int> *q;
  // TEST : Slice
  cout << endl << "TEST : Slicing B into C from '22' to '13' " << endl;
  p = B.find(22);
  q = B.find(13);
  C.slice(B, p, q); 
  cout << "C = " << C << " " << C.size() << endl;


  cout << endl << "Test 05 - Done!" << endl;
} 



//---------------------------------------------------------------------
void test06() {
  
  LinkedList<int> E;
  LLNode<int>* tmp;
  
  cout << endl << endl; 
  cout << " ***************** " << endl;
  cout << " *  TEST SET #6  * " << endl;
  cout << " ***************** " << endl;


  //TEST : Handling of an empty list
  cout << endl << "TEST : Handling an empty list" << endl;
  cout << E << endl;
  cout << "Size of E = " << E.size() << endl;
  tmp = E.getFirstPtr();
  cout << "First = " << tmp << endl;

  //TEST : Inserting 10 elements to a
  cout << endl << "TEST : Inserting 10 elements into E" << endl;
  for (int k=0; k<10; k++){
    E.insert_front(k*11);
  } 
  cout << E << endl;
  cout << "Size of E = " << E.size() << endl;


  //TEST : Handling Invalid Index
  cout << endl << "TEST : Handling an Invalid Index" << endl;
  tmp = E.getAtPtr(99);
  cout << tmp << endl;

  cout << endl << "Test 06 - Done!" << endl;
} 


int main () {
  
  cout << "Hello World!!, This is the LinkedList LARGE Tester" << endl; 
  
  test00();
  test01();
  test02();
  test03();
  test04();
  test05();
  test06();

  cout << endl << "LARGE Done!" << endl;
  return 0;
}
