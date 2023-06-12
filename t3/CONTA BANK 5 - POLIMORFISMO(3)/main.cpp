//#include "client.hpp"
#include "cc.hpp"
#include "ce.hpp"
#include "client.hpp"
#include <vector>



int main()
{
    //implementar menu
    //1-New Client
    //2-Delete Client   //somente se nao tiver uma conta ativa
    //3-New Account
    //4-Change Client
    //5-Delete Account
    //other options for reports

    vector<Client*> clientList;
    clientList.push_back(new Client("Antonio Carlos", "Rua das Oliveiras, 3333", "Pesquisador", 49000));
    clientList.push_back(new Client("Joao da Silva"));
    clientList.push_back(new Client("Cristian Ribeiro", "Rua das Bromelias"));
    clientList.push_back(new Client("Ricardo Silva", "Rua sem nome", "Mecanico"));
    clientList.push_back(new Client("Maria da Silva", "None", "Vendedora", 5000));

    vector<ContaCorrente*> accountList;
    accountList.push_back(new ContaCorrente(clientList.at(2), 100000));
    accountList.push_back(new ContaCorrente(clientList.at(4), 50000));
    accountList.push_back(new ContaCorrente(clientList.at(2), 20000));
    accountList.push_back(new ContaCorrente(clientList.at(3), 30000));
    accountList.push_back(new ContaEspecial(clientList.at(2), 5000, 15000));
    accountList.push_back(new ContaEspecial(clientList.at(1), 10000, 2000));
    accountList.push_back(new ContaEspecial(clientList.at(3), 20000, 5000));
    accountList.push_back(new ContaEspecial(clientList.at(4), 1000000, 50000));

    for(size_t i=0; i<accountList.size(); i++)
    {
        cout << accountList.at(i)->GetInfo() << endl;
    }

    //delete
    for(size_t i=0; i<clientList.size(); i++)
        delete clientList.at(i);
    clientList.clear();

    for(size_t i=0; i<accountList.size(); i++)
        delete accountList.at(i);
    accountList.clear();

    return 0;
}
