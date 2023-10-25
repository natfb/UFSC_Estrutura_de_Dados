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
    
    int quant(Nodo<T>* raiz) const {
            if (raiz == nullptr) {
                return 0;
            }
            return 1 + quant(raiz->filhoEsquerda) + quant(raiz->filhoDireita);
    }
    
    virtual int quantidade() const {
        Nodo<T>* raiz = this->raiz;

        return quant(raiz);
    };
    
    virtual bool contem(T chave) const {

        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave){
            // Esquerda ou direita.
            if (raiz->chave == chave){
             return true;
            }
            if (raiz->chave < chave){
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
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
    
    void Emordem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        
        Emordem(raiz->filhoEsquerda, lista); 
        lista->inserirNoFim(raiz->chave);
        Emordem(raiz->filhoDireita, lista);
    };
    
    virtual ListaEncadeadaAbstrata<T>* emOrdem() const { 
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        Emordem(raiz, lista);

        return lista;
    };

    void Preordem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        lista->inserirNoFim(raiz->chave);
        Preordem(raiz->filhoEsquerda, lista);
        Preordem(raiz->filhoDireita, lista);
    };

    virtual ListaEncadeadaAbstrata<T>* preOrdem() const {
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        Preordem(raiz, lista);

        return lista;
    };

    void Posordem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        Posordem(raiz->filhoDireita, lista);
        lista->inserirNoFim(raiz->chave);
        Posordem(raiz->filhoEsquerda, lista);
    };

    virtual ListaEncadeadaAbstrata<T>* posOrdem() const {
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        Posordem(raiz, lista);

        return lista;
    };
};

#endif