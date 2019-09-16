#include "Folder.h"

void Folder::addMsg(Message* m)
{
    messages.insert(m);
}

void Folder::remMsg(Message* m)
{
    messages.erase(m);
}

void Folder::addToMessages(const Folder& f)
{
    for (auto m: f.messages)
        m->save(*this);
}

void Folder::removeFromMessages()
{
    for(auto m: messages)
        m->remove(*this);
}

Folder::Folder(const Folder& f): name(f.name), messages(f.messages)
{
    addToMessages(f);
}

Folder& Folder::operator=(const Folder& rhs)
{
    removeFromMessages();
    name = rhs.name;
    messages = rhs.messages;
    addToMessages(*this);
    return *this;
}

Folder::~Folder()
{
    removeFromMessages();
}

void swap(Folder& lhs, Folder& rhs)
{
    using std::swap;
    for (auto m: lhs.messages)
        m->remove(lhs);
    for (auto m: rhs.messages)
        m->remove(rhs);
    swap(lhs.name,rhs.name);
    swap(lhs.messages,rhs.messages);
    for (auto m: lhs.messages)
        m->save(lhs);
    for (auto m: rhs.messages)
        m->save(rhs);
}

void Folder::print()
{
    for (auto m: messages)
    {
        std::cout << m->contents << std::endl;
    }
}
