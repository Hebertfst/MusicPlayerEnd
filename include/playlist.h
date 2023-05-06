#include "ListaEncadeada.h"
#include "music.h"

class Playlist
{
private:
  std::string nome;
  ListaEncadeada<Music> listaMusicas;

public:
  Playlist(){};
  ~Playlist()
  {
    Node<Music> *atual = listaMusicas.getHead();
    while (atual != nullptr)
    {
      Node<Music> *proximo = atual->getProx();
      delete atual;
      atual = proximo;
    }
  }
  Playlist(std::string nome, ListaEncadeada<Music> listaMusicas);
  ListaEncadeada<Music> getLista() { return listaMusicas; }
  /**
   * @brief Pega o membro titulo
   *
   * @return std::string nome
   */
  std::string getTitulo() { return nome; }
  /**
   * @brief Metodo para comparar objetos do tipo playlist
   *
   * @param outra
   * @return true
   * @return false
   */
  bool operator==(const Playlist &outra) const
  {
    return this->nome == outra.nome;
  }
  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, cria um objeto musica e o adiciona a playlist atraves da função inserir() da lista encadeada
   *  @param titulo
   * @param autor
   */

  void adicionarMusica(std::string titulo, std::string autor)
  {
    Music musica(titulo, autor);
    listaMusicas.inserir(musica);
  }

  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, cria um objeto musica e o remove da playlist atraves da função remover() da lista encadeada.
   * @param titulo
   * @param autor
   */

  void removerMusica(std::string titulo, std::string autor)
  {
    Music musica(titulo, autor);
    listaMusicas.remover(musica);
  }
  /**
   * @brief Metodo da classe playlist que imprimi as musicas de uma playlist traves da função imprimir() da lista encadeada.
   */

  void imprimirMusicas()
  {
    std::cout << "Playlist: " << nome << std::endl;
    if (listaMusicas.getHead() != nullptr)
    {
      std::cout << "Musicas:" << std::endl;
      imprimirMus(listaMusicas.getHead());
    }
    else
    {
      std::cout << "Nao ha musicas cadastradas no momento." << std::endl;
    }
  }

  void imprimirMus(Node<Music> *node)
  {
    if (node == nullptr)
    {
      return;
    }
    std::cout << "Titulo: " << node->getValor().getTitulo();
    std::cout << ", Autor: " << node->getValor().getAutor() << std::endl;

    imprimirMus(node->getProx());
  }

  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, e passa os parametros para o metodo buscarNodeM() da lista encadada e retorna true para caso a musica esteja na playlist e false para oposto.
   * @param titulo
   * @param autor
   * @return bool
   */

  bool buscarMusica(std::string titulo, std::string autor)
  {
    Music m1(titulo, autor);
    return listaMusicas.buscarNodeBool(m1);
  }
  /**
   *@brief Metodo da classe playlist que imprime as musicas da playlist uma de cada vez, de forma que o usuario possa controlar a passagem das musicas ou voltar para o menu.
   */

  void play(std::string nome)
  {
    int opc;
    Node<Music> *atual = listaMusicas.getHead();
    while (atual != nullptr)
    {
      std::cout << "Playlist: " << nome << std::endl;
      std::cout << "Tocando: " << atual->getValor().getTitulo() << ","
                << " de " << atual->getValor().getAutor() << std::endl;
      std::cout << "1. Proxima musica." << std::endl;
      std::cout << "0 - Voltar" << std::endl;
      std::cin >> opc;
      if (opc == 1)
      {
        atual = atual->getProx();
      }
      else
      {
        return;
      }
    }
  }
};
