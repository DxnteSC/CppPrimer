pen #ifndef MESSAGE_H
#define MESSAGE_H

#include <set>
#include <string>

#include "Folder.h"
class Folder;

class Message
{
    friend class Folder;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
public:
    // folders implicitly initialised to the empty set
    explicit Message(const std::string& str = " "): contents(str) {}
    // Copy Control
    Message(const Message&); // copy constructor
    Message& operator=(const Message&); // copy assignment
    ~Message(); // destructor
    Message (Message&&); // move constructor
    Message& operator=(Message&&); // move assignment
    // add/remove this message from the specified folder's set of messages
    void save(Folder&);
    void remove(Folder&);
    // add/remove a folder into folders
    void addFolder(Folder*);
    void remFolder(Folder*);
    
private:
    std::string contents; // message text
    std::set<Folder*> folders; // folders that contain this message
    // utility functions used by copy constructor, assignment and destruction
    void addToFolders(const Message&); // add this message to the folders that point to the parameter
    void removeFromFolders(); // remove this message from every folder in Folder
    void moveFolders(Message*); // move the Folder pointers to this Message
};

#endif
