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

        while(data != nullptr) {
            if(data->dado == dado){
                return i; 
            } 
            i++;
            data = data->proximo;
        }
        
        throw ExcecaoDadoInexistente();
    }

    virtual bool contem(T dado) const {
        
        Elemento<T>* data = this->_primeiro;
        
        while(data != nullptr) {
            
            if(data->dado == dado)
                return true;  

            data = data->proximo;
        }
        return false;
    }

    virtual void inserirNoInicio(T dado) {

        Elemento<T>* novo = new Elemento<T>(dado, this->_primeiro);

        this->_primeiro = novo;
        this->_tamanho++;
    };

    virtual void inserir(std::size_t posicao, T dado) {
        if(posicao < 0 || posicao >= this->_tamanho)
            throw ExcecaoPosicaoInvalida();

        size_t i = 0;
        Elemento<T>* data = this->_primeiro;

        while(data->proximo != nullptr) { 
            Elemento<T>* anterior = nullptr;
            
            if(posicao == i){
               Elemento<T>* novo = new Elemento<T>(dado, data);
               anterior->proximo = novo;
            }
            anterior = data;
            data = data->proximo;
            i++;
        }
    }

    virtual void inserirNoFim(T dado) {
        
        if (this->vazia()){
            inserirNoInicio(dado);
            return;
        }

        Elemento<T>* data = this->_primeiro;

        while(data->proximo != nullptr) {
            data = data->proximo;
        }
        data->proximo = new Elemento<T>(dado, nullptr);
        this->_tamanho++;
    }

    virtual T removerDoInicio() {
        return 0;
    }

    virtual T removerDe(std::size_t posicao) {
        return 0;
    }

    virtual T removerDoFim() {
        return 0;
    };

    virtual void remover(T dado) {

    };
};

#endif