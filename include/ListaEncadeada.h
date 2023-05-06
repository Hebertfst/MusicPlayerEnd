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
};

#endif