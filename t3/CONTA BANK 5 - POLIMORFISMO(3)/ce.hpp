#ifndef CE_HPP
#define CE_HPP

#include <iostream>
#include "client.hpp"
#include "cc.hpp"

using namespace std;

class ContaEspecial : public ContaCorrente
{
protected:
    float m_limit;

public:
    ContaEspecial(Client *client, float balance=0, float limit=1000) : ContaCorrente(client, balance), m_limit(limit)  {};

    string GetInfo();

    bool WithDraw(float value);
    bool operator -=(float value);

    bool Transfer(float value, ContaCorrente &conta);

    /*//methods 
    void operator +=(float value);*/

};


#endif
