#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
using namespace std;


class MyString
{
   public:
      MyString();
      MyString(const char*);
      ~MyString();
      MyString(const MyString&);
      MyString operator=(const MyString&);
      bool operator==(const MyString&) const;
      char& operator[](const int);
      void operator+=(const MyString&);
      MyString operator+(const MyString&) const;
      void getline(istream&, char delimit = '\n');
      int length() const;
      friend ostream& operator<<(ostream&, MyString&);

   private:
      int capacity;
      int size;
      char* data;
};

#endif
