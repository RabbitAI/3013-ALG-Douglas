#include <iostream>
#include <fstream>
#include <string>
#include "Json.hpp"
#include "JsonFacade.hpp"
#include "mygetch.hpp"
#include "Timer.hpp"

using namespace std;

struct wordNode
{
    string word;
    string definition;
    wordNodes* next;

    wordNode(string w, string d)
    {
        word = w;
        definition = d;
        next = nullptr;
    }

    wordNode(json obj)
    {
        word = obj.getKeys();
        definition = obj.getValue(word);
    }
};

class DictionaryList
{
private:
    wordNode* head;

public:
    DictionaryList()
    {
        head = nullptr;
    }

    bool isEmpty()
    {
        if(head == nullptr)
        {
            return true;
        }
        return false;
    }

    void insert(json obj)
    {
        wordNode* temp = new wordNode(obj);

        if(head = nullptr)
        {
            head = temp;
        }
        else
        {
            temp->next = head;
            head = temp;
        }
    }
};

void fillList(DictionaryList &dl, JsonFacade J);

int main()
{
    DictionaryList dl;
    Timer T;
    json obj;
    filename = "dict_w_defs.json";
    JsonFacade J(filename);

    fillList(dl, J);
    

    return 0;
}

void fillList(DictionaryList &dl,JsonFacade J)
{
    for(int i = 0; i < J.getSize(); i++)
    {
        dl.insert(J);
        J.getNext();
    }
}