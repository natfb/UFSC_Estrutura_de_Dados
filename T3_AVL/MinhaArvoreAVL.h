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

    bool vazia() const {
        return !this->raiz;
    };

    virtual int quantidade() const {
        Nodo<T>* raiz = this->raiz;

        return quant(raiz);
    };
    
    bool contem(T chave) const {

        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave){
            // Esquerda ou direita.
            if (raiz->chave == chave) {
                return true;
            } else if (raiz->chave < chave) {
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }

        return false;
    };
    
    std::optional<int> altura(T chave) const {
        
        if (!this->contem(chave))
            return std::nullopt;
        
        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave) {
            // Esquerda ou direita.
            if (raiz->chave < chave){
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }

        return raiz->altura;
    };
       
    void inserir(T chave) {
        
    };
      
    void remover(T chave) {

    };

    std::optional<T> filhoEsquerdaDe(T chave) const {
        
        if (!this->contem(chave))
            return std::nullopt;
        
        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave) {
            // Esquerda ou direita.
            if (raiz->chave < chave){
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }

        return raiz->filhoEsquerda->chave;
    };
       
    std::optional<T> filhoDireitaDe(T chave) const {
        
        if (!this->contem(chave))
            return std::nullopt;
        
        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave) {
            // Esquerda ou direita.
            if (raiz->chave < chave){
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }

        return raiz->filhoDireita->chave;
    };
    
    virtual ListaEncadeadaAbstrata<T>* emOrdem() const { 
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        Emordem(raiz, lista);

        return lista;
    };

    virtual ListaEncadeadaAbstrata<T>* preOrdem() const {
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        Preordem(raiz, lista);

        return lista;
    };

    virtual ListaEncadeadaAbstrata<T>* posOrdem() const {
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        Posordem(raiz, lista);

        return lista;
    };

    //funcoes auxiliares/////////////////////////////////////////////
        
    int quant(Nodo<T>* raiz) const {
        if (raiz == nullptr) {
            return 0;
        }
        return 1 + quant(raiz->filhoEsquerda) + quant(raiz->filhoDireita);
    }

    void Emordem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        
        Emordem(raiz->filhoEsquerda, lista); 
        lista->inserirNoFim(raiz->chave);
        Emordem(raiz->filhoDireita, lista);
    };

    void Preordem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        lista->inserirNoFim(raiz->chave);
        Preordem(raiz->filhoEsquerda, lista);
        Preordem(raiz->filhoDireita, lista);
    };

    void Posordem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        Posordem(raiz->filhoDireita, lista);
        lista->inserirNoFim(raiz->chave);
        Posordem(raiz->filhoEsquerda, lista);
    };
};

#endif