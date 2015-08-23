//
//  client.cpp
//  CS 2b_7.10.6
//
//  Created by Chris on 7/25/15.
//  Copyright (c) 2015 Chris. All rights reserved.
//

#include <stdio.h>
#include "dynamictemplatearray.h"
//#include "dynamictemplatearray.cpp"

using namespace cs2b_7;
using namespace std;


int main() {

   dynamicTemplateArray<string> tester;
   cout << &tester << " = tester memory address" << endl;
   tester.addEntry("1");
   tester.addEntry("2");
   tester.addEntry("3");
   tester.addEntry("4");
   tester.addEntry("5");
   tester.addEntry("6");
   cout << "length = " << tester.getSize() << endl;

   for (int i = 0; i<tester.getSize(); i++) {
      cout << &(tester.getEntry(i)) << " = " << tester.getEntry(i) << endl;
   }
   cout << endl;
   if (tester.deleteEntry("3")) {
      cout << "tester length = " << tester.getSize() << endl;
      for (int i = 0; i<tester.getSize(); i++) {
         cout << &(tester.getEntry(i)) << " = " << tester.getEntry(i) << endl;
      }
   }

   dynamicTemplateArray<string> testTwo;
   cout << endl << &testTwo << " = testTwo memory" << endl;
   testTwo = tester;
   for (int i = 0; i<testTwo.getSize(); i++) {
      cout << &(testTwo.getEntry(i)) << " = " << testTwo.getEntry(i) << endl;
   }

   cout <<&tester << " = tester memory address"<< endl << &testTwo << " = testTwo memory address"<< endl;

}


