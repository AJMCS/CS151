/*
This lab we will investigate in more detail three situations that can create a dangling pointer.
Author: AJ McDaniel
Module 3 Lab 3
Date: 4/1/2025
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;


// Return the address of a local variable 
  int * badReturn() { 
      int x = 19 ;
      return &x ;    
  } 


int main() {
  // Dangling pointer issue #1
  cout << "Part #1" << endl;
  int *ptr1;
  if (true) {
      int square = 36;  
      ptr1 = &square;  
  } 
  *ptr1 = 49; 
  cout << "Dangling pointer: " << *ptr1 << endl << endl; 



  // Dangling pointer issue #2 
  cout << "Part #2" << endl;
  int *ptr2 = new int(11);  

  // Now free that memory and try to use it
  delete ptr2;  
  *ptr2 = 85; 
  cout << "Dangling pointer: " << *ptr2 << endl << endl;
  
  return 0;



  // Dangling pointer issue #3
  cout << "Part #3" << endl ;
  int *ptr3 = badReturn() ;
  cout << "Dangling pointer: " << *ptr3 << endl ; 

  // Will the value in ptr3 be re-initialized?
  *ptr3 = 45 ;
  ptr3 = badReturn() ;
  cout << "When called again:   " << *ptr3 << endl ;
}