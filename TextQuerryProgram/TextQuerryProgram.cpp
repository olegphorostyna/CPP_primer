// TextQuerryProgram.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include "TextQuery.h"
#include "QueryResult.h"
#include "StrBlobPtr.h"
#include "String.h"
#include "Foo.h"
#include "Book.h"




std::string make_plurar(const size_t size, const std::string& str, const char* ending) {
    return size > 1 ? str + ending : str;

}


std::ostream& print(std::ostream& os, const QueryResult& q) {
    os << q.sought << " occurs " << q.lines->size() << " " << make_plurar(q.lines->size(), "time", "s") << std::endl;

    for (auto num : *q.lines) { // for every element in a set
        os << "\t(line " << num + 1 << ") " <<*(q.file->begin()+num) << std::endl;       
    }
    return os;
}


void runQueries(std::ifstream &infile) {
    TextQuery tq(infile);
    while (true) {
        std::cout << "enter words to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}


int main()
{

   // Book b;
   // std::cout << b;
   /* std::vector<String> str_vec;
    str_vec.push_back("asdasdas");
    str_vec.push_back(String ("asdasd"));
    String s("asdasd");
    str_vec.push_back(s);
    str_vec.push_back(String("asdasd"));
    str_vec.push_back(String("asdasd"));
    str_vec.push_back(String("asdasd"));
    str_vec.push_back(String("asdasd"));*/
  /*  std::string filename;
    std::cout << "Enter file to reaf from:" << std::endl;
    if (std::cin >> filename) {
        std::ifstream fs(filename);
        if(fs.good())
            runQueries(fs);        
    }*/


   /* Foo f1; f1.print();
    Foo f2{ 9, 2, 6, 5, 3, 8, 4, 1, 7 }; f2.print();
    Foo f3 = f2.sorted(); f2.print(); f3.print();
    Foo f4 = Foo({ 2, 6, 5, 3, 8, 4, 1, 7 }).sorted(); f4.print();*/

   
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
