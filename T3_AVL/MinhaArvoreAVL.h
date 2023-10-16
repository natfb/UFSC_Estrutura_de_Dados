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
        return !this->raiz;
    };
    
    virtual int quantidade() const {
        Nodo<T>* raiz = this->raiz;

        Nodo<T>* busca (T dado, raiz){
            if (raiz == nullptr){ 
                return 0;
            }
        
            if (raiz->chave < chave) {
                return busca(dado, raiz->_filhoDireita);
            } 
            else {
                return busca(dado, raiz->_filhoEsquerda);
            }        
       }
    };
    
    virtual bool contem(T chave) const {

        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave){
            // Esquerda ou direita.
            if (raiz->chave < chave){
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }

        if (raiz->chave == chave){
            return true;
        }

        return false;
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