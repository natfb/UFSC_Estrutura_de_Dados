#include "ce.hpp"
#include <sstream>


string ContaEspecial::GetInfo()
{
    stringstream buffer;
    buffer << "Special Account. ";
    buffer << m_client->GetInfo();
    buffer << "  Balance: " << m_balance;
    buffer << "  Limit: " << m_limit;

    return buffer.str();
};

bool ContaEspecial::operator -=(float value)
{
    return(WithDraw(value));
}

bool ContaEspecial::WithDraw(float value)
{
    if(m_balance-value+m_limit >= 0)
    {
        m_balance -= value;
        return true;
    }
    else
        return false;
}

bool ContaEspecial::Transfer(float value, ContaCorrente &conta)
{
    if(m_balance-value+m_limit >= 0)
    {
        m_balance -= value;
        conta.Deposit(value);
        return true;
    }
    else
        return false;
}

/*


*/
