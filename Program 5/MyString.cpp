#include "MyString.hpp"

//Default Constructor
MyString::MyString():size(0), capacity(0), data(new char[capacity]){
    data[size]  = '\0';
}


//Custom Constructor
MyString::MyString(const char* s1){
    size     = strlen(s1);
    capacity = size + 1;
    data     = new char[capacity];
    strcpy(data, s1);
}


//Deallocate
MyString::~MyString(){
    memset(data, 0, capacity);
}


//Copy Constructor
MyString::MyString(const MyString& other):
size(other.size),capacity(other.capacity), data(new char[capacity])
{
    strcpy(data, other.data);
}


//Overload assignment operator
MyString MyString::MyString operator=(const MyString& other){
    if(this != &other){
        memset(data,0,capacity);
        delete [] data;
        
        size     = other.size;
        capacity = other.capacity;
        data     = new char[capacity];
        strcpy(data, other.data);
    }
    return *this;
}


//Output overload
ostream& operator<<(ostream&, MyString&){
    out << str.data;
}



//Getline
void MyString::getline(istream& in, char delimit = '\n'){
    size = 0;
    char c;
    
    while(in.get(c) && c != delimit){
        if(size + 1 >= capacity){
            capacity *= 2;
            char *p = new char[capacity];
            strcpy(p, data);
            memset(data, 0, size);
            delete [] data;
            data = p;
        }
        data[size] = c;
        size++;
    }
    data[size] = '\0';
}
