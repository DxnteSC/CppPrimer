#include "Message.h"

void Message::save(Folder& f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder& f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::addFolder(Folder* f)
{
    folders.insert(f);
}

void Message::remFolder(Folder* f)
{
    folders.erase(f);
}

void Message::addToFolders(const Message& msg)
{
    for (auto f: msg.folders)
        f->addMsg(this);
}

void Message::removeFromFolders()
{
    for(auto f:folders)
        f->remMsg(this);
}

Message::Message(const Message& m): contents(m.contents), folders(m.folders)
{
    addToFolders(m);
}

Message& Message::operator=(const Message& rhs)
{
    removeFromFolders();
    contents = rhs.contents;
    folders = rhs.folders;
    addToFolders(rhs);
    return *this;
}

Message::~Message()
{
    removeFromFolders();
}

void swap(Message& lhs, Message& rhs)
{
    using std::swap;
    for (auto f: lhs.folders)
        f->remMsg(&lhs);
    for (auto f: rhs.folders)
        f->remMsg(&rhs);
    swap(lhs.contents, rhs.contents);
    swap(lhs.folders,rhs.folders);
    for (auto f: lhs.folders)
        f->addMsg(&lhs);
    for (auto f: rhs.folders)
        f->addMsg(&rhs);
}

void Message::moveFolders(Message* m)
{
    folders = std::move(m->folders);
    for (auto f: folders)
    {
        f->remmsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

Message::Message(Message&& m)
{
    moveFolders(&m);
}

Message& Message::operator=(Message&& rhs)
{
    if (this != rhs)
    {
        removeFromFolders();
        contents = std::move(rhs.contents);
        moveFolders(&rhs);
    }
    return *this;
}

