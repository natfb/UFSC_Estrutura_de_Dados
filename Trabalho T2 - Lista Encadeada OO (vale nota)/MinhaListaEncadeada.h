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
       
        if(posicao < 0 || posicao > tamanho()){
            throw ExcecaoPosicaoInvalida();
        }
        else if (posicao == tamanho()){
            inserirNoFim(dado);
            return; 
        }
        
        size_t i = 0;
        Elemento<T>* data = this->_primeiro;
        Elemento<T>* anterior = nullptr;

        while(data != nullptr) { 
            
            if(posicao == i){
               anterior->proximo = new Elemento<T>(dado, data);
               this->_tamanho++;
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
        
        if (vazia())
            throw ExcecaoListaEncadeadaVazia();
        
        Elemento<T>* primeiro = this->_primeiro;
        
        this->_primeiro = primeiro->proximo;
        this->_tamanho--;
        //retorna e chama remover() para remover???
        return primeiro->dado;
    }

    virtual T removerDe(std::size_t posicao) {

        if(posicao < 0 || posicao >= tamanho()){
            throw ExcecaoPosicaoInvalida();
        } 
        else if (posicao == tamanho()){
            return removerDoFim();
        }
        
        Elemento<T>* data = this->_primeiro;
        Elemento<T>* anterior = nullptr;
        size_t i = 0;

        while(data != nullptr) { 
            
            if(posicao == i){
               anterior->proximo = data->proximo;
               T ultimo_dado = data->dado;
               
               this->_tamanho--;
               
               return ultimo_dado;
            }

            i++;
            anterior = data;
            data = anterior->proximo;
        }
    }

    virtual T removerDoFim() {
        
        if (this->vazia()){
            throw ExcecaoListaEncadeadaVazia();
        }

        if (tamanho() == 1){
            return removerDoInicio();
        }

        Elemento<T>* data = this->_primeiro;
        Elemento<T>* penultimo = nullptr;

        while (data->proximo != nullptr) {
            penultimo = data;
            data = data->proximo;
        } 

        penultimo->proximo = nullptr;
        this->_tamanho--;

        return ultimo->dado;
    };
    
    virtual void remover(T dado) {
        if(vazia())
            throw ExcecaoListaEncadeadaVazia();

        Elemento<T>* data = this->_primeiro;
        Elemento<T>* anterior = nullptr;
        
        while(data != nullptr) {

            if(data->dado == dado){
                
                anterior->proximo = data->proximo;         
                this->_tamanho--;
            }
            anterior = data;
            data = data->proximo;
        }
        
        throw ExcecaoDadoInexistente();
    };
};

#endif