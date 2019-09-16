#ifndef FOLDER_H
#define FOLDER_H

#include <iostream>
#include <set>
#include <string>

#include "Message.h"
class Message;

class Folder
{
public:
    friend class Message;
    friend void swap(Folder&, Folder&);
    friend void swap(Message&, Message&);
public:
    Folder(const std::string& s = " "): name(s) {}
    // Copy Control
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();
    // add/remove message from folder
    void addMsg(Message*);
    void remMsg(Message*);
    void print();
private:
    std::string name;
    std::set<Message*> messages;
    void addToMessages(const Folder&);
    void removeFromMessages();
};

#endif
