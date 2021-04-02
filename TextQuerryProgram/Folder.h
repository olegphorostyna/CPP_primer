#pragma once
#include<set>
class Message;
class Folder {
public:
	void addMsg(Message* m);
	void remMsg(Message* m);
private:
	std::set<Message*> messages;
};