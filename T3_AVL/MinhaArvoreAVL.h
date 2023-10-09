#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "ArvoreBinariaDeBusca.h"

/**
 * @brief Representa uma árvore AVL.
 * 
 * @tparam T O tipo de dado guardado na árvore.
 */
template <typename T>
class MinhaArvoreAVL final : public ArvoreBinariaDeBusca<T>
{
    ~MinhaArvoreAVL() {

    };

    virtual bool vazia() const {
        return true;
    };
    
    virtual int quantidade() const {
        return 0;
    };
    
    virtual bool contem(T chave) const {
        return true;
    };
    
    virtual std::optional<int> altura(T chave) const {
        return 0;
    };
       
    virtual void inserir(T chave) {
        
    };
      
    virtual void remover(T chave) {

    };

    virtual std::optional<T> filhoEsquerdaDe(T chave) const {
        return  0;
    };
       
    virtual std::optional<T> filhoDireitaDe(T chave) const {
        return  0;
    };

    virtual ListaEncadeadaAbstrata<T>* emOrdem() const { 
        return nullptr;
    };

    virtual ListaEncadeadaAbstrata<T>* preOrdem() const {
        return nullptr;
    };

    virtual ListaEncadeadaAbstrata<T>* posOrdem() const {
        return nullptr;
    };
};

#endif