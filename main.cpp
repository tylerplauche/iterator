#include <iostream>
#include <string>
#include <cctype>

#include <iterator>

#include "iterator.h"

using namespace std;

#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif


int main(int argc, char *argv[]) {
    ifstream in(argv[1]);
    ofstream out(argv[2]);
    LinkedList<string> linked_list;
 out << endl;
    for (string line; getline(in, line);)
    {
        string item1, item2, item3;
        if (line.size() == 0) continue;
        if(isspace(line.back()))
        {
            line.pop_back();
        }
        out << line;
        istringstream iss(line);
        iss >> item1;
        try {
            if (item1 == "Insert") {
                while (iss >> item2) {
                    linked_list.push_front(item2);
                }
                out << endl;
            }
            if (item1 == "PrintList") {
                if (linked_list.size() == 0) {
                    out << " Empty!" << endl;
                } else {
                    out << " " << linked_list << endl;
                }
            }
            if (item1 == "Clear") {
                linked_list.clear();
                out << " OK" << endl;
            }
            if (item1 == "Iterate")
            {
                if (linked_list.size() == 0)
                {
                    throw string(" Empty!");
                }
                LinkedList<string>::Iterator iter = linked_list.begin();
                out << endl;
                while (iter != linked_list.end())
                {
                    out << " [" << *iter << "]" << endl ;
                    iter = ++iter;
                }
            }
            if (item1 == "Find") {
                iss >> item2;
                LinkedList<string>::Iterator position = linked_list.find(linked_list.begin(), linked_list.end(), item3);
                out << " OK" << endl;
            }
            /*if (item1 == "InsertAfter")
            {
                 iss >> item2;
                 //cout << item2 << endl;
                 iss >> item3;
                LinkedList<string>::Iterator position = linked_list.find(linked_list.begin(), linked_list.end(), item3);
                //LinkedList<string>::Iterator debug = position;
                linked_list.insert_after(position, item2);
            }*/
            /*if (item1 == "Erase")
            {
                iss >> item2
                LinkedList<string>::Iterator position = linked_list.find(linked_list.begin(), linked_list.end(), item2);
                linked_list.erase(position, value);
            }*/
        }

        catch (const string &s) { out << s << endl; }

    }

    return 0;
}
