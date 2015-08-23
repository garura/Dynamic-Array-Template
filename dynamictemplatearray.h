/*
 ============================================================================
 File Name   : dynamictemplatearray.h
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 7-25-15          1.0         NA           Chris Jordan    None
 ============================================================================
 Description:     Header file for class dynamicTemplateArray.
                  dynamicTemplateArray is designed to be a class template for
                  arrays.
               
 
 Public functions:
 
 dynamicTemplateArray();
 Precondition: None.
 Postcondition: An object of dynamicTemplateArray is created.
 

 dynamicTemplateArray(const T &right);
 Precondition: Right is a dynamicTemplateArray passed by copy, of same type.
 Postcondition: object is copied (deep copy).

 ~dynamicTemplateArray();
 Precondition: Object being deallocated has a pointer to an array.
 Postcondition: Array pointed to has been deallocated.


 dynamicTemplateArray operator= (const T &right);
 Precondition: Both left and right objects are of same type.
 Postcondition: A deep copy of right's array has been made in left.


 int getSize() const;
 Precondition: None.
 Postcondition: Returns the size data-member.
 

 void addEntry(const T entryString);
 Precondition: entryString is of same type as the array.
 Postcondition: entryString has been appended to end of array, which has been
                increased in size by 1. size data member incremented.
 

 bool deleteEntry(const T removedString);
 Precondition: removedString is of same type as array.
 Postcondition: If removedString is found in the array, a new array is created 
                (one fewer elements), copied from previous array, excluding 
                removedString. Size decremented, returns true. If not found,
                returns false.

 

 T& getEntry(int index) const;
 Precondition: index >= 0, index < size.
 Postcondition: Returns the object found in the index of the array.

*/
#ifndef DYNAMICTEMPLATEARRAY_H
#define DYNAMICTEMPLATEARRAY_H

#include <iostream>
#include <string>

namespace cs2b_7 {

   template<class T>
   class dynamicTemplateArray {

      public:
         dynamicTemplateArray();
         dynamicTemplateArray(const dynamicTemplateArray &right);
         ~dynamicTemplateArray();
         dynamicTemplateArray operator= (const dynamicTemplateArray &right);
         int getSize() const;
         void addEntry(const T entryString);
         bool deleteEntry(const T removedString);
         T& getEntry(int index) const;

      private:
         T *myStringArray;
         int size;
   };
}

#include "dynamictemplatearray.cpp"

#endif
