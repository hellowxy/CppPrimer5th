#ifndef FOLDER_H
#define FOLDER_H
#include<set>
class Message;
class Folder{
    
    private:
        std::set<Message*> messages;
    public:
        void addMsg(Message const*);
        void remMsg(Message const*);
};
#endif