#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
// MinhaListaEncadeada
#include "TabelaEspalhamentoAbstrata.h"
// TabelaEspalhamentoAbstrata
#include "excecoes.h"
// ExcecaoDadoInexistente

#include <cmath>

template<typename T, std::size_t capac>
class MinhaTabelaEspalhamento final:
    public TabelaEspalhamentoAbstrata<T, capac>
{
    public:

        virtual std::size_t capacidade() const {
            return this->tabela.max_size();
        };

        virtual void inserir(T dado) {
            size_t indice = funcaoEspalhamento(dado);
            
            this->tabela[indice].inserirNoFim(dado);      
        };

        virtual void remover(T dado) {
            size_t indice = funcaoEspalhamento(dado);

            this->tabela[indice].remover(dado);
        };

        virtual bool contem(T dado) const {
            size_t indice = funcaoEspalhamento(dado);
            
            if (this->tabela[indice].contem(dado))
                return true;

            return false;
        };

        virtual std::size_t quantidade() const {
            size_t quant = 0;
            
            for (int i = 0; i <= this->tabela.size() - 1; i++) {
                quant += this->tabela[i].tamanho();
            }
            
            return quant;
        };
    
    protected:

        virtual std::size_t funcaoEspalhamento(T dado) const {
            size_t chave = codigoEspalhamento(dado);
            return chave % capacidade();
        };
        
    private:
        /**
         * @brief Calcula a representação numérica de um tipo integral.
         * 
         * @tparam U O tipo integral.
         * @param integral Um valor integral.
         * @return Um inteiro calculado através de static_cast<std::size_t>(integral)
         */
        template<typename U>
        std::size_t codigoEspalhamento(U integral) const
        {
            if (std::is_integral_v<U>) {
                return static_cast<std::size_t>(integral);
            } else {
                return codigoEspalhamento(integral);
            }
        }
        
        std::size_t codigoEspalhamento(std::string const& string) const
        {
            size_t valor = 0;
            
            for (int i = 0; i <= string.length() - 1; i++) {
                valor += string[i] * std::pow(31, string.length() - (i + 1));
            }

            return valor;
        }
        
    };

#endif
