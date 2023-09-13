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
        if (this->_primeiro == nullptr)
            return true;
        
        return false;
    }

    virtual std::size_t posicao(T dado) const {
        
        if (vazia())
            throw ExcecaoListaEncadeadaVazia();
        
        size_t i = 0;
        Elemento<T>* data = this->_primeiro;

        do {
            if(data->dado == dado){
                return i; 
            } 
            i++;
            data = data->proximo;
        } while (data != nullptr);
        
        throw ExcecaoDadoInexistente();
    }

    virtual bool contem(T dado) const {
        //
        return false;
    }

    virtual void inserirNoInicio(T dado) {

        // if (vazia()) 
        //     throw ExcecaoListaEncadeadaVazia();

        Elemento<T>* novo = new Elemento<T>(dado, this->_primeiro);

        this->_primeiro = novo;
        this->_tamanho++;
    };

    virtual void inserir(std::size_t posicao, T dado) {

    }

    virtual void inserirNoFim(T dado) {
        
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