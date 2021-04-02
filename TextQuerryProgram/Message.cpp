#include "Message.h"
#include "Folder.h"
//Message& operator=(const Message&);
//~Message();
//
//void save(Folder&); // add this message to specified folder
//void remove(Folder&); //remove this message from specified folder
//
//private:
//	std::string content;
//	std::set<Folder*> folders;
//
//	//utility functins
//	void add_message_to_folders(const Message&); //add this message to folders pointed by argument
//	void remove_from_folder();//remove this message from all folders

void swap(Message &l, Message &r) {
	using std::swap;
	for (auto f : l.folders) {
		f->remMsg(&l);
	}
	for (auto f : r.folders) {
		f->remMsg(&r);
	}
	swap(l.content, r.content);
	swap(l.folders, r.folders);
	for (auto f : l.folders) {
		f->addMsg(&l);
	}
	for (auto f : r.folders) {
		f->addMsg(&r);
	}


}

Message::Message(const Message& o):content(o.content), folders(o.folders){
	add_message_to_folders(o);
}


Message::Message(Message&& m): content(std::move(m.content)) {
	move_Folders(&m);
}

Message::~Message() {
	remove_from_folder();
}

void Message::addF(Folder* m) {
	folders.insert(m);
	m->addMsg(this);
}
void Message::remF(Folder* m) {
	folders.erase(m);
	m->remMsg(this);
}

Message& Message::operator=(const Message& r) {
	remove_from_folder();
	content = r.content;
	folders = r.folders;
	add_message_to_folders(r);
	return *this;
}

Message& Message::operator=( Message&& m) {
	if (this != &m) {
		remove_from_folder();
		content = std::move(m.content);
		move_Folders(&m);
	}
	return *this;
}


void Message::add_message_to_folders(const Message& m) {
	for (auto i : m.folders) {
		i->addMsg(this);
	}
}


void Message::move_Folders(Message* m) {
	folders = std::move(m->folders);
	for (auto f : folders) {
		f->remMsg(m);
		f->addMsg(this);
	}
	m->folders.clear();
}

void Message::save(Folder& f) {
	folders.insert(&f);
	f.addMsg(this);
}
void Message::remove(Folder& f) {
	folders.erase(&f);
	f.remMsg(this);
}

void Message::remove_from_folder() {
	for (auto i : folders) {
		i->remMsg(this);
	}
}

