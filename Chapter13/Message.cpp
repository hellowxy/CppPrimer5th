#include"Message.h"
#include<string>
#include<set>
#include"Folder.h"
using std::string;
using std::set;

void Message::add_to_Folders(const Message& msg){
    for(Folder* f:folders){
        f->addMsg(msg);
    }
}

void Message::remove_from_Folders(){
    for(Folder* f:folders){
        f->remMsg(*this);
    }
}

Message::Message(const Message& msg):contents(msg.contents),folders(msg.folders){
    add_to_Folders(msg);
}

Message& Message::operator=(const Message& rhs){
    remove_from_Folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_Folders(ths);
    return *this; 
}

Message::~Message(){
    remove_from_Folders();
}

void Message::save(Folder& folder){
    folders.insert(folder);
    folder.addMsg(this);
}

void Message::remove(Folder& folder){
    folders.erase(folder);
    f.remMsg(this);
}

void swap(Message& lhs, Message& rhs){
    using std::swap;
    for(Folder* f:lhs.folders){
        f->remMsg(&lhs);
    }

    for(Folder* f : rhs.folders){
        f->remMsg(&rhs);
    }

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    for(Folder* f : lhs.folders){
        f->addMsg(&lhs);
    }

    for(Folder* f : rhs.folders){
        f->addMsg(&ths);
    }
}
