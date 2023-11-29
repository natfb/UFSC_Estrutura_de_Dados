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
        destructor(this->raiz);
    };

    void destructor(Nodo<T>* nodo) {
        if (nodo != nullptr) {
           destructor(nodo->filhoEsquerda);
           destructor(nodo->filhoDireita);
           delete nodo; 
        }
    }

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
        
        Nodo<T>* raiz = getNodo(chave);

        if (raiz == nullptr) 
            return false;

        return true;
    };
    
    std::optional<int> altura(T chave) const {
        
        if (!this->contem(chave))
            return std::nullopt;
        
        Nodo<T>* raiz = getNodo(chave);

        return raiz->altura;
    };

    void inserir(T chave) {
        Nodo<T>* raiz = this->raiz;
        Nodo<T>* novo = new Nodo<T>;
        novo->chave = chave;
        inserirAux(novo, raiz);
    };
      
    void remover(T chave) {
        if (!contem(chave)){
            return;    
        }

        Nodo<T>* raiz = this->raiz;
        removerAux(chave, raiz);
    };

    std::optional<T> filhoEsquerdaDe(T chave) const {
        
        if (!this->contem(chave))
            return std::nullopt;
        
        Nodo<T>* raiz = getNodo(chave);

        if (!raiz->filhoEsquerda) 
            return std::nullopt;

        return raiz->filhoEsquerda->chave;
    };
       
    std::optional<T> filhoDireitaDe(T chave) const {
        
        if (!this->contem(chave))
            return std::nullopt;
        
        Nodo<T>* raiz = getNodo(chave);

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
    //retorna o nodo da chave parametro
    Nodo<T>* getNodo(T chave) const {
        Nodo<T>* raiz = this->raiz;
        
        while (raiz != nullptr && raiz->chave != chave) {
            // Esquerda ou direita.
            if (raiz->chave < chave){
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }
        }
        return raiz;
    }
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
        
        int bRaiz, bEsq, bDir;
        bRaiz = balanco(raiz);
        bEsq = balanco(raiz->filhoEsquerda);
        bDir = balanco(raiz->filhoDireita);
        
        if (bRaiz == 2 && bEsq >= 0) {
            rotacaoDireitaSimples(raiz);      
        } else if (bRaiz == -2 && bDir <= 0) {
            rotacaoEsquerdaSimples(raiz);
        } else if (bRaiz == 2 && bEsq < 0) {
            rotacaoEsquerdaDireita(raiz);
        } else if (bRaiz == -2 && bDir > 0) {
            rotacaoDireitaEsquerda(raiz);
        }
        atualizarAltura(raiz);
    }

    int balanco(Nodo<T>* nodo) {
        int altEsq, altDir;
        
        if (nodo == nullptr) {
            return 0;
        } 
        
        (nodo->filhoEsquerda) ? altEsq = nodo->filhoEsquerda->altura : altEsq = -1;

        (nodo->filhoDireita) ? (altDir = nodo->filhoDireita->altura) : altDir = -1;

        return altEsq - altDir;
    }

    void rotacaoDireitaSimples(Nodo<T>* raiz) {
        Nodo<T>* pai = raiz;
        Nodo<T>* filho = pai->filhoEsquerda;
        Nodo<T>* filhoD = filho->filhoDireita;
        Nodo<T>* paiRaiz = paiDe(pai);
        
        pai->filhoEsquerda = filhoD;
        filho->filhoDireita = pai;
        
        //atualizar filho do pai de raiz se raiz != this->raiz
        if (paiRaiz != nullptr) {
            if (pai != this->raiz && paiRaiz->chave < pai->chave) {
                paiRaiz->filhoDireita = filho;
            } else if (pai != this->raiz) {
                paiRaiz->filhoEsquerda = filho;
            }
        }

        atualizarAltura(filho->filhoEsquerda);
        atualizarAltura(filho->filhoDireita);
        atualizarAltura(filho);

        if (pai == this->raiz) {
            this->raiz = filho;
        }
    }

    void rotacaoEsquerdaSimples(Nodo<T>* raiz) {   
        Nodo<T>* pai = raiz;
        Nodo<T>* filho = pai->filhoDireita;
        Nodo<T>* filhoE = filho->filhoEsquerda;
        Nodo<T>* paiRaiz;
        
        if (pai != this->raiz) {
            paiRaiz = paiDe(pai);
        }

        pai->filhoDireita = filhoE;

        
        filho->filhoEsquerda = pai;
        
        if (pai != this->raiz && paiRaiz->chave < pai->chave) {
            paiRaiz->filhoDireita = filho;
        } else if (pai != this->raiz){
            paiRaiz->filhoEsquerda = filho;
        }
        
        atualizarAltura(filho->filhoEsquerda);
        atualizarAltura(filho->filhoDireita);
        atualizarAltura(filho);

        if (pai == this->raiz) {
            this->raiz = filho;
        }
    }

    void rotacaoEsquerdaDireita(Nodo<T>* raiz) {
        Nodo<T>* pai = raiz;
        Nodo<T>* filho = pai->filhoEsquerda;
        Nodo<T>* filhoD = filho->filhoDireita;
        Nodo<T>* paiRaiz;
        filho->filhoDireita = filhoD->filhoEsquerda;
        filhoD->filhoEsquerda = filho;
        pai->filhoEsquerda = filhoD;

        filho = pai->filhoEsquerda;
        pai->filhoEsquerda = filho->filhoDireita;
        if (pai != this->raiz) {
            paiRaiz = paiDe(pai);
        }    
        filho->filhoDireita = pai;

        if (pai != this->raiz && paiRaiz->chave < pai->chave) {
            paiRaiz->filhoDireita = filho;
        } else if (pai != this->raiz){
            paiRaiz->filhoEsquerda = filho;
        }
  
        atualizarAltura(filho->filhoEsquerda);
        atualizarAltura(filho->filhoDireita);
        atualizarAltura(filho);

        if (pai == this->raiz) {
            this->raiz = filho;
        }
    }

    void rotacaoDireitaEsquerda(Nodo<T>* raiz) {
        // rotacaoDireitaSimples(raiz->filhoEsquerda);
        // rotacaoEsquerdaSimples(raiz);
        Nodo<T>* pai = raiz;
        Nodo<T>* filho = pai->filhoDireita;
        Nodo<T>* filhoE = filho->filhoEsquerda;
        Nodo<T>* paiRaiz;
        filho->filhoEsquerda = filhoE->filhoDireita;
        filhoE->filhoDireita = filho;
        pai->filhoDireita = filhoE;

        filho = pai->filhoDireita;
        pai->filhoDireita = filho->filhoEsquerda;
        if (pai != this->raiz) {
            paiRaiz = paiDe(pai);
        }
        filho->filhoEsquerda = pai;
      
        if (pai != this->raiz && paiRaiz->chave < pai->chave) {
            paiRaiz->filhoDireita = filho;
        } else if (pai != this->raiz){
            paiRaiz->filhoEsquerda = filho;
        }
        atualizarAltura(filho->filhoEsquerda);
        atualizarAltura(filho->filhoDireita);
        atualizarAltura(filho);

        if (pai == this->raiz) {
            this->raiz = filho;
        }
    }

    Nodo<T>* paiDe(Nodo<T>* filho) {   
        if (!contem(filho->chave)) {
            return nullptr;
        }
        if (filho == this->raiz) {
            return nullptr;
        }
        Nodo<T>* raiz = this->raiz;
        Nodo<T>* pai = nullptr;
        Nodo<T>* tmp = nullptr;

        while (pai == nullptr) {
            // Esquerda ou direita. 
            tmp = raiz;

            if (raiz->chave <= filho->chave) {
                raiz = raiz->filhoDireita;
            } else { 
                raiz = raiz->filhoEsquerda;
            }

            if (raiz == filho) {
                pai = tmp;
            } 
        }

        return pai;
    }

    // atualizar altura ////////////////////////////////////
    void atualizarAltura(Nodo<T>* raiz) {
        int altEsq, altDir;
        altEsq = altDir = -1;

        if (raiz == nullptr) {
            return;
        }

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
        //remover folha
        if (raiz->chave == chave && raiz->filhoDireita == nullptr && raiz->filhoEsquerda == nullptr) {
            if (raiz == this->raiz) {
                this->raiz = nullptr;
            } else {
                Nodo<T>* pai = paiDe(raiz);
                
                if (pai->chave > raiz->chave) {
                    pai->filhoEsquerda = nullptr;
                } else {
                    pai->filhoDireita = nullptr;
                }   
            }
            delete raiz; 
            return;
        } 
        //remover nodo sem filho a direita
        else if (raiz->chave == chave && raiz->filhoDireita == nullptr) {
            Nodo<T>* pai = paiDe(raiz);
            if (raiz == this->raiz) {
                this->raiz = raiz->filhoEsquerda;
                delete raiz;
            }    
            else if (pai->chave > raiz->chave) {
                pai->filhoEsquerda = raiz->filhoEsquerda;
            } else {
                pai->filhoDireita = raiz->filhoEsquerda;
            }
            delete raiz;
            return;
        } 
        //remover nodo com filho a direita
        else if (raiz->chave == chave && raiz->filhoDireita != nullptr) {
            removerComFilhoDir(raiz, raiz->filhoDireita);
        }
        else if (raiz->chave < chave) {
            removerAux(chave, raiz->filhoDireita);
        } else {
            removerAux(chave, raiz->filhoEsquerda);
        }

        atualizarAltura(raiz);
        
        int bRaiz, bEsq, bDir;
        bRaiz = balanco(raiz);
        bEsq = balanco(raiz->filhoEsquerda);
        bDir = balanco(raiz->filhoDireita);
        
        if (bRaiz == 2 && bEsq >= 0) {
            rotacaoDireitaSimples(raiz);      
        } else if (bRaiz == -2 && bDir <= 0) {
            rotacaoEsquerdaSimples(raiz);
        } else if (bRaiz == 2 && bEsq < 0) {
            rotacaoEsquerdaDireita(raiz);
        } else if (bRaiz == -2 && bDir > 0) {
            rotacaoDireitaEsquerda(raiz);
        }
        
        atualizarAltura(raiz);
    }

    void removerComFilhoDir(Nodo<T>* remover, Nodo<T>* raiz) {

        if (raiz->filhoEsquerda == nullptr) {
            remover->chave = raiz->chave;
            
            if (raiz->filhoDireita != nullptr) {
                removerComFilhoDir(raiz, raiz->filhoDireita);
                return;
            } 
            else if (raiz->filhoDireita == nullptr) {
                Nodo<T>* pai = paiDe(raiz);
                
                if (pai->chave > raiz->chave) {
                    pai->filhoEsquerda = nullptr;
                } else {
                    pai->filhoDireita = nullptr;
                }

                delete raiz;
                atualizarAltura(pai);
            }
        } else {
            removerComFilhoDir(remover, raiz->filhoEsquerda);
        }
  
        atualizarAltura(remover);
    }
};

#endif