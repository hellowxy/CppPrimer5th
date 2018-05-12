#include"Message.h"
#include"Folder.h"
#include<set>

void Folder::addMsg(Message const* pmsg){
    messages.insert(pmsg);
}

void Folder::remMsg(Message const *pmsg){
    messages.erase(pmsg);
}