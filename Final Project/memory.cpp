#include "memory.h"
#include<iostream>

using namespace std;

Memory::Memory(int id, Object* sharedBy, char* text, date& shareDay, Post* originalPost) : Post(id, sharedBy, text, shareDay), originalPost(originalPost){}

void Memory::display() const {
    cout << sharedBy->getName() << " shared a memory" << endl;
    cout << "(";
    shareDay.print();
    cout << ")" << endl;

    cout << "\"" << text << "\"" << endl;  // Memory text

    // how many years ago calculation
    int yearsAgo = originalPost->getSharedDay().yeardifference(shareDay);
    cout << "(" << yearsAgo << " Years Ago)" << endl << endl;

    originalPost->display();  // Display original post now 
}