#ifndef MINHA_ARVORE_AVL_HPP
#define MINHA_ARVORE_AVL_HPP

#include "ArvoreBinariaDeBusca.h"
#include <algorithm>
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

        if (vazia())
            return false;
        
        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave) {
            // Esquerda ou direita.
            if (raiz->chave < chave) {
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }

        if (raiz == nullptr) 
            return false;

        return true;
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
        Nodo<T>* raiz = this->raiz;
        Nodo<T>* novo = new Nodo<T>;
        novo->chave = chave;
        inserirAux(novo, raiz);
    };
      
    void remover(T chave) {
        if (!contem(chave))
            return;
        Nodo<T>* raiz = this->raiz;
        removerAux(chave, raiz);
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

        if (!raiz->filhoEsquerda) 
            return std::nullopt;

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

        if (!raiz->filhoDireita) 
            return std::nullopt;

        return raiz->filhoDireita->chave;
    };
    
    virtual ListaEncadeadaAbstrata<T>* emOrdem() const { 
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        emOrdem(raiz, lista);

        return lista;
    };

    virtual ListaEncadeadaAbstrata<T>* preOrdem() const {
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        preOrdem(raiz, lista);

        return lista;
    };

    virtual ListaEncadeadaAbstrata<T>* posOrdem() const {
        MinhaListaEncadeada<T> *lista = new MinhaListaEncadeada<T>();
        Nodo<T>* raiz = this->raiz;

        posOrdem(raiz, lista);

        return lista;
    };

    //funcoes auxiliares/////////////////////////////////////////////
    //quantidade////////////////////////////////////////////////////
    int quant(Nodo<T>* raiz) const {
        if (raiz == nullptr) {
            return 0;
        }
        return 1 + quant(raiz->filhoEsquerda) + quant(raiz->filhoDireita);
    }
    
    //Em Ordem/////////////////////////////////////////////////////////
    void emOrdem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        
        emOrdem(raiz->filhoEsquerda, lista); 
        lista->inserirNoFim(raiz->chave);
        emOrdem(raiz->filhoDireita, lista);
    };

    //Pre Ordem//////////////////////////////////////////////////////////
    void preOrdem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        lista->inserirNoFim(raiz->chave);
        preOrdem(raiz->filhoEsquerda, lista);
        preOrdem(raiz->filhoDireita, lista);
    };

    //Pos Ordem///////////////////////////////////////////////////////
    void posOrdem(Nodo<T>*raiz, MinhaListaEncadeada<T>* lista) const {
        if(!raiz){
            return;
        }
        posOrdem(raiz->filhoEsquerda, lista);
        posOrdem(raiz->filhoDireita, lista);
        lista->inserirNoFim(raiz->chave);
    };

    //inserir/////////////////////////////////////////////////////////
    void inserirAux(Nodo<T>* novo, Nodo<T>* raiz) {
        if (vazia()) {
            this->raiz = novo;
            return;
        }

        if (raiz->chave < novo->chave) {
            if (raiz->filhoDireita == nullptr) {     
                raiz->filhoDireita = novo;  
            } else {
                inserirAux(novo, raiz->filhoDireita); 
            }         
        } 
        else {
            if (raiz->filhoEsquerda == nullptr) {
                raiz->filhoEsquerda = novo;  
            } else {
                inserirAux(novo, raiz->filhoEsquerda);
            } 
        }

        atualizarAltura(raiz);
        int altEsq, altDir;
        altEsq = altDir = -1;

        if (raiz->filhoEsquerda) {
            altEsq = raiz->filhoEsquerda->altura;
        }

        if (raiz->filhoDireita) {
            altDir = raiz->filhoDireita->altura;
        }
        if (altEsq - altDir > 1) {
            rotacaoDireitaSimples(raiz);
            atualizarAltura(raiz);
        } else if (altEsq - altDir < -1) {
            rotacaoEsquerdaSimples(raiz);
            atualizarAltura(raiz);
        }
    }

    void rotacaoDireitaSimples(Nodo<T>* raiz) {
        Nodo<T>* pai = retornaPai(raiz);
        Nodo<T>* filho = pai->filhoEsquerda;
        Nodo<T>* filhoD = filho->filhoDireita;
        pai->filhoEsquerda = filhoD;
        filho->filhoDireita = pai;

        if (pai == this->raiz) {
            this->raiz = filho;
        }
    }

    void rotacaoEsquerdaSimples(Nodo<T>* raiz) {   
        Nodo<T>* pai = retornaPai(raiz);
        Nodo<T>* filho = pai->filhoDireita;
        Nodo<T>* filhoE = filho->filhoEsquerda;
        pai->filhoDireita = filhoE;
        filho->filhoEsquerda = pai;

        if (pai == this->raiz) {
            this->raiz = filho;
        }
    }

    Nodo<T>* retornaPai(Nodo<T>* filho) {   
        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz != filho){
            // Esquerda ou direita.
            if (raiz->chave < filho->chave) {
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }

        return raiz;   
    }
    // atualizar altura ////////////////////////////////////
    void atualizarAltura(Nodo<T>* raiz) {
        int altEsq, altDir;
        altEsq = altDir = -1;

        if (raiz->filhoEsquerda) {
            altEsq = raiz->filhoEsquerda->altura;
        }
        
        if (raiz->filhoDireita) {
            altDir = raiz->filhoDireita->altura;
        }

        raiz->altura = std::max(altEsq, altDir) + 1;
    }

    //remocao ////////////////////////////////////////////////
    void removerAux(T chave, Nodo<T>* raiz) {
        //se for folha
        if (raiz->chave == chave && raiz->filhoDireita == nullptr && raiz->filhoEsquerda == nullptr) {
            Nodo<T>* pai = retornaPai(raiz);
            if (pai->chave > raiz->chave) {
                pai->filhoEsquerda = nullptr;
            } else {
                pai->filhoDireita = nullptr;
            }
            delete raiz;
        } 
        //se nao tiver filho a direita
        else if (raiz->chave == chave && raiz->filhoDireita == nullptr) {
            Nodo<T>* pai = retornaPai(raiz);
            if (pai->chave > raiz->chave) {
                pai->filhoEsquerda = raiz->filhoEsquerda;
            } else {
                pai->filhoDireita = raiz->filhoEsquerda;
            }
            delete raiz;
        } 
        //se tiver filho a direita
        else if (raiz->chave == chave && raiz->filhoDireita != nullptr) {
            Nodo<T>* menor = Menor(raiz);
            Nodo<T>* pai = retornaPai(raiz);
            
            if (pai->chave > raiz->chave) {
                pai->filhoEsquerda = menor;
            } else {
                pai->filhoDireita = menor;
            }
            Nodo<T>* tmp = raiz;
            delete raiz;
        }

        if (raiz->chave < chave) {
            removerAux(chave, raiz->filhoDireita);
        } else {
            removerAux(chave, raiz->filhoEsquerda);
        }

        atualizarAltura(raiz);

    }
    Nodo<T>* Menor(Nodo<T>* nodo) {
        int menorNum = nodo->chave;
        Nodo<T>* raiz = this->raiz;
        Nodo<T>* menor = this->raiz;
        
        while (raiz != nullptr) {
            if(raiz->chave < menor->chave) {
                menor = raiz->filhoDireita;
            }
            if (raiz->chave < nodo->chave) {
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }
        return raiz;
    }
};

#endif