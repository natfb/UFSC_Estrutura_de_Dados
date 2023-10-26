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
    
    int quantidade() const {
        Nodo<T>* raiz = this->raiz;

    //     Nodo<T>* busca (T dado, raiz){
    //         if (raiz == nullptr){ 
    //             return 0;
    //         }
        
    //         if (raiz->chave < chave) {
    //             return busca(dado, raiz->_filhoDireita);
    //         } 
    //         else {
    //             return busca(dado, raiz->_filhoEsquerda);
    //         }        
    //    }
        return 0;
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

    ListaEncadeadaAbstrata<T>* emOrdem() const { 
        return nullptr;
    };

    ListaEncadeadaAbstrata<T>* preOrdem() const {
        // void Preordem(Nodo *raiz, ListaEncadeada* lista)
        // início
        // se raiz != NULO então
        // adicionaNoFim(lista, raiz->_dado);
        // Preordem(raiz->_filhoEsquerda, 		lista);
        // Preordem(raiz->_filhoDireita, 	lista);
        // fim se
        // fim
        
        return nullptr;
    };

    ListaEncadeadaAbstrata<T>* posOrdem() const {
        return nullptr;
    };
};

#endif