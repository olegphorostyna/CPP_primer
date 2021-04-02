#pragma once
#include <set>
#include <string>

class Folder;
class Message {
	friend void swap(Message& l, Message& r);

public:
	explicit Message(const std::string& str = "") :content(str) {
	}

	Message(const Message&);
	Message( Message&&);
	Message& operator=(const Message&);
	Message& operator=( Message&&);
	~Message();

	void save(Folder&); // add this message to specified folder
	void remove(Folder&); //remove this message from specified folder


	void addF(Folder* m);
	void remF(Folder* m);

private:
	std::string content;
	std::set<Folder*> folders; // folders where this message belong

	//utility functins
	void add_message_to_folders(const Message&); //add this message to folders pointed by argument
	void remove_from_folder();//remove this message from all folders
	void move_Folders(Message* m);
	
};