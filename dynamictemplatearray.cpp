/*
 ============================================================================
 File Name   : dynamictemplatearray.cpp
 Author      : Chris Jordan
 Revision History: None
 Date             Version     Change ID    Author          Comment
 7-25-15          1.0         NA           Chris Jordan    None
 ============================================================================

 Description: Implementation file for the class template dynamicTemplateArray.
 Contains two data members; a pointer of type T to an array, and an int "size"
 that represents how big that array is.
 
 The template is protected against memory leak.



*/

#include <iostream>
#include <string>
#include <cassert>
//#include "dynamictemplatearray.h"

namespace cs2b_7 {

   template<class T>
   dynamicTemplateArray<T>::dynamicTemplateArray(): myStringArray(NULL), size(0) {}






   template<class T>
   dynamicTemplateArray<T>::dynamicTemplateArray(const dynamicTemplateArray &right) {
      size = right.size;
      myStringArray = new T[size];
      for (int i = 0; i < size; i++) {
         myStringArray[i] = right.myStringArray[i];
      }
   }






   template<class T>
   dynamicTemplateArray<T>::~dynamicTemplateArray() {
      delete [] myStringArray;
   }






   template<class T>
   dynamicTemplateArray<T> dynamicTemplateArray<T>::operator=(const dynamicTemplateArray &right) {
      if (this != &right) {
         size = right.size;
         delete [] myStringArray;
         myStringArray = new T[size];
         for (int i = 0; i < size; i++) {
            myStringArray[i] = right.myStringArray[i];

         }
      }
      return *this;
   }






   template<class T>
   int dynamicTemplateArray<T>::getSize() const {
      return size;
   }






   template<class T>
   void dynamicTemplateArray<T>::addEntry(const T entryString) {
      T *tempArray = new T[size+1];
      for (int i = 0; i < size; i++) {
         tempArray[i] = myStringArray[i];
      }
      tempArray[size] = entryString;  // add last element
      delete [] myStringArray;
      myStringArray = tempArray;
      size++;
   }






   template<class T>
   bool dynamicTemplateArray<T>::deleteEntry(const T removedString) {
      for (int i = 0; i < size; i++) {
         if (myStringArray[i] == removedString) {
            T *tempArray = new T[size-1];   // new array (1 smaller)
            for (int j = 0; j < (size-1); j++) {
               if (j < i) {
                  tempArray[j] = myStringArray[j];    // prior to i, just copy
               }
               else {
                  tempArray[j] = myStringArray[j+1];  // skip i, use next index
               }
            }
            delete [] myStringArray;
            myStringArray = tempArray;
            size--;
            return true;
         }
      }
      return false;
   }






   template<class T>
   T& dynamicTemplateArray<T>::getEntry(int index) const {
      assert (index >= 0 && index < getSize());
      return myStringArray[index];
   }
}














