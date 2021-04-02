#include "Folder.h"

//class Folder {
//public:
//	void addMsg(Message* m);
//	void remMsg(Message* m);
//private:
//	std::set<Message*> messages;
//};


void Folder::addMsg(Message* m) {
	messages.insert(m);
}
void Folder::remMsg(Message* m) {
	messages.erase(m);
}
