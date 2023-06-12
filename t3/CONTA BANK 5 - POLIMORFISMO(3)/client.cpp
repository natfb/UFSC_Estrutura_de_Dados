#include "client.hpp"
#include <sstream>

string Client::GetInfo()
{
    stringstream buffer;

    buffer << "Client: " << m_name << "  Address: " << m_address << "  Job descr: " << m_profession << "  Income: " << m_income;

    //set_precision
    //fixed

    return buffer.str();
}
