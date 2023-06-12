#ifndef CLIENTE_HPP
#define CLIENTE_HPP


#include <iostream>

using namespace std;

class Client
{
private:
    string m_name, m_address, m_profession;
    float m_income;

public:
    //Client() : m_name(""), m_address(""), m_profession(""), m_income(0) {};

    Client(string name, string address="", string profession="", float income=0) : m_name(name), m_address(address), m_profession(profession), m_income(income) {};

    //getters and setters
    //void ShowInfo();   display
    string GetInfo();    //string, stringstream
};


#endif
