#include "cc.hpp"
#include <sstream>

string ContaCorrente::GetInfo()
{
    stringstream buffer;
    buffer << "Basic Account. ";
    buffer << m_client->GetInfo();
    buffer << "  Balance: " << m_balance;

    return buffer.str();
};

void ContaCorrente::Deposit(float value)
{
    m_balance += value;
}

void ContaCorrente::operator +=(float value)
{
    m_balance += value;
}

bool ContaCorrente::operator -=(float value)
{
    return(WithDraw(value));
}

bool ContaCorrente::WithDraw(float value)
{
    if(m_balance-value >= 0)
    {
        m_balance -= value;
        return true;
    }
    else
        return false;
}

bool ContaCorrente::Transfer(float value, ContaCorrente &conta)
{
    if(m_balance-value >= 0)
    {
        m_balance -= value;
        conta.Deposit(value);
        return true;
    }
    else
        return false;
}

bool ContaCorrente::operator >>(ContaCorrente &conta)
{
    conta.Deposit(m_balance);
    m_balance = 0;
    return true;
}

