#include<bits/stdc++.h>
using namespace std;

#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
public:
    virtual void setTitle(string s) = 0; // Pure virtual function
    string getTitle() {
        return title;
    }
};

// Derived class
class MyBook : public Book {
public:
    void setTitle(string s) override {
        title = s;
    }
};

int main() {
    string title;
    getline(cin, title);
    
    MyBook new_novel;
    new_novel.setTitle(title);
    
    cout << "The title is: " << new_novel.getTitle() << endl;
    
    return 0;
}
