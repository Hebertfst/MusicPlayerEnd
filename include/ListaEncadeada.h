#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "music.h"
#include "Node.h"
template <typename T>
class ListaEncadeada
{

private:
  Node<T> *head;
  Node<T> *tail;

public:
  ListaEncadeada()
  {
    head = nullptr;
    tail = nullptr;
  };
  ListaEncadeada(T valor)
  {
    head = new Node<T>(valor);
    tail = head;
  }
  ~ListaEncadeada()
  {
    Node<T> *atual = head;
    while (atual != nullptr)
    {
      Node<T> *proximo = atual->getProx();
      delete atual;
      atual = proximo;
    }
  }
  Node<T> *getHead() { return head; }
  /**
   * @brief Verifica se a lista esta vazia
   *
   * @return true
   * @return false
   */
  bool vazia() { return (head == NULL); }
  /**
   * @brief Insere nós em uma lista encadeada
   *
   * @param valor
   */
  void inserir(T valor)
  {
    Node<T> *novo_no = new Node<T>(valor);

    if (vazia())
    {
      head = novo_no;
      tail = novo_no;
    }
    else
    {
      tail->setProx(novo_no);
      tail = novo_no;
    }
  }
  /**
   * @brief Remove nós da lista encadeada
   *
   * @param valor
   */
  void remover(T valor)
  {
    Node<T> *anterior = nullptr;
    Node<T> *atual = head;

    while (atual != nullptr)
    {
      if (atual->getValor() == valor)
      {
        if (anterior == nullptr)
        {
          head = atual->getProx();
          delete atual;
          return;
        }
        else
        {
          anterior->setProx(atual->getProx());
          if (atual == tail)
          {
            tail = anterior;
          }
          delete atual;
          return;
        }
      }
      else
      {
        anterior = atual;
        atual = atual->getProx();
      }
    }
  }
  // Transformar o remover e o removerPlay em uma so funçao
  void removerPlay(Node<T> *valor)
  {
    Node<T> *anterior = nullptr;
    Node<T> *atual = head;

    while (atual != nullptr)
    {
      if (atual == valor)
      {
        if (anterior == nullptr)
        {
          head = atual->getProx();
          delete atual->getValor();
          delete atual;
          return;
        }
        else
        {
          anterior->setProx(atual->getProx());
          if (atual == tail)
          {
            tail = anterior;
          }
          delete atual->getValor();
          delete atual;
          return;
        }
      }
      else
      {
        anterior = atual;
        atual = atual->getProx();
      }
    }
  }
  /**
   * @brief Busca nós atraves de uma string
   *
   * @param valor
   * @return Node<T>*
   */
  Node<T> *buscarNode(std::string valor)
  {
    Node<T> *atual = head;
    while (atual != nullptr)
    {
      if (atual->getValor()->getTitulo() == valor)
      {
        return atual;
      }
      atual = atual->getProx();
    }
    return nullptr;
  }
  /**
   * @brief Retorna se o nó existe na lista Encadeada
   *
   * @param titulo
   * @param autor
   * @return true
   * @return false
   */

  bool buscarNodeBool(T valor)
  {
    Node<T> *atual = head;
    while (atual != nullptr)
    {
      if (atual->getValor() == valor)
      {
        return true;
      }
      atual = atual->getProx();
    }
    return false;
  }
  // Metodos novos
  void adicionarLista(ListaEncadeada<T> &listaAtual, ListaEncadeada<T> &listaRecebida)
  {
    Node<T> *atual = listaRecebida.getHead();
    while (atual != nullptr)
    {
      listaAtual.inserir(atual->getValor());
      atual = atual->getProx();
    }
  }
  int removerElementos(ListaEncadeada<T> &lista, ListaEncadeada<T> &elementosRemover)
  {
    int qtd = 0;
    Node<T> *atual = elementosRemover.getHead();
    while (atual != nullptr)
    {
      lista.remover(atual->getValor());
      atual = atual->getProx();
      qtd++;
    }
    return qtd;
  }

  ListaEncadeada<T> construtorCopia(ListaEncadeada<T> &lista)
  {
    ListaEncadeada<T> copia;

    Node<T> *atual = lista.getHead();
    while (atual != nullptr)
    {
      copia.inserir(atual->getValor());
      atual = atual->getProx();
    }

    return copia;
  }
  // Operador '+': concatena duas listas
  ListaEncadeada<T> operator+(const ListaEncadeada<T> &lista)
  {
    ListaEncadeada<T> novaLista = construtorCopia(*this); // Cria uma cópia da lista atual

    Node<T> *atual = lista.getHead();
    while (atual != nullptr)
    {
      novaLista.inserir(atual->getValor());
      atual = atual->getProx();
    }

    return novaLista;
  }

  // Operador '>>': extrai o último elemento da lista
  void operator>>(Node<T> *&no)
  {
    if (tail != nullptr)
    {
      no = new Node<T>(tail->getValor());
      remover(tail->getValor());
    }
    else
    {
      no = nullptr;
    }
  }

  // Operador '<<': insere um nó no fim da lista
  void operator<<(Node<T> *no)
  {
    if (no != nullptr)
    {
      inserir(no->getValor());
    }
  }
};

#endif