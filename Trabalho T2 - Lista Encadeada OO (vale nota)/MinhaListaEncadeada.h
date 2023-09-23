#ifndef DEC0006_MINHA_LISTA_ENCADEADA_H
#define DEC0006_MINHA_LISTA_ENCADEADA_H

#include <cstddef>
// std::size_t

#include "Elemento.h"
// Elemento
#include "ListaEncadeadaAbstrata.h"
#include "excecoes.h"
// ExcecaoDadoInexistente
// ExcecaoListaEncadeadaVazia
// ExcecaoNaoImplementado
// ExcecaoPosicaoInvalida

/**
 * @brief Uma lista encadeada de dados.
 * 
 * @tparam T O tipo dos dados armazenados na lista.
 */
template<typename T>
class MinhaListaEncadeada: public ListaEncadeadaAbstrata<T>
{
    //Implemente aqui as funcões marcadas com virtual na ListaEncadeadaAbstrata
    //Lembre-se de implementar o construtor e destrutor da classe
    ~MinhaListaEncadeada() {
    
        Elemento<T>* data = this->_primeiro;
        Elemento<T>* tmp = nullptr;
        for (int i = 0; i < tamanho(); i++) {
            tmp = data->proximo;
            delete data;
            data = tmp;
        }
    }

    virtual std::size_t tamanho() const {
        return this->_tamanho;
    }

    virtual bool vazia() const {
        return (this->_primeiro == nullptr);
            
    }

    virtual std::size_t posicao(T dado) const {
        
        if (vazia())
            throw ExcecaoListaEncadeadaVazia();
        
        size_t i = 0;
        Elemento<T>* data = this->_primeiro;

        while (data != nullptr) {
            if (data->dado == dado) {
                return i; 
            } 
            i++;
            data = data->proximo;
        }
        
        throw ExcecaoDadoInexistente();
    }

    virtual bool contem(T dado) const {
        
        if (vazia())
            return false;

        Elemento<T>* data = this->_primeiro;
        
        while (data != nullptr) {
            if (data->dado == dado)
                return true;  

            data = data->proximo;
        }

        return false;
    }

    virtual void inserirNoInicio(T dado) {

        Elemento<T>* novo = new Elemento(dado, this->_primeiro);

        this->_primeiro = novo;
        this->_tamanho++;
    };

    virtual void inserir(std::size_t posicao, T dado) {
       
        if (posicao < 0 || posicao > tamanho()) {
            throw ExcecaoPosicaoInvalida();
        }
        else if (posicao == 0) {
            inserirNoInicio(dado);
            return;
        }
        
        size_t i = 0;
        Elemento<T>* data = this->_primeiro;

        for (int i = 1; i < posicao; i++) {
            data = data->proximo;   
        }
        
        Elemento<T>* novo = new Elemento<T>(dado, data->proximo);
        data->proximo = novo;
        this->_tamanho++;
    }

    virtual void inserirNoFim(T dado) {
        
        if (this->vazia()) {
            inserirNoInicio(dado);
            return;
        }
        
        inserir(tamanho(), dado);
    }

    virtual T removerDoInicio() { 
        
        if (vazia())
            throw ExcecaoListaEncadeadaVazia();
        
        T dado = this->_primeiro->dado;
        remover(dado);
        
        return dado;
    }

    virtual T removerDe(std::size_t posicao) {

        if (posicao < 0 || posicao >= tamanho()) {
            throw ExcecaoPosicaoInvalida();
        } 
        
        Elemento<T>* data = this->_primeiro;

        for (int i = 0; i < posicao; i++) {
            data = data->proximo;
        }

        T dado = data->dado;
        remover(dado);
        return dado;
    }

    virtual T removerDoFim() {
        if (this->vazia()) {
            throw ExcecaoListaEncadeadaVazia();
        }

        Elemento<T>* data = this->_primeiro;

        while (data->proximo != nullptr) {
            data = data->proximo;
        } 

        T dado = data->dado;
        remover(dado);
        return dado;
    };
    
    virtual void remover(T dado) {
        if(vazia())
            throw ExcecaoListaEncadeadaVazia();
        
        Elemento<T>* data = this->_primeiro;
        Elemento<T>* tmp = nullptr;

        //remover do inicio
        if (posicao(dado) == 0) {
            Elemento<T>* primeiro = this->_primeiro;
            this->_primeiro = primeiro->proximo;
            delete primeiro;
            this->_tamanho--;
            
            return;
        }

        //remover posicao > 1
        for (int i = 1; i < posicao(dado); i++) {
            data = data->proximo;   
        }
        
        tmp = data->proximo;   
        data->proximo = tmp->proximo;
        delete tmp;
        this->_tamanho--;

        return;    
    };
};

#endif
