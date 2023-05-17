#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
#include "ListaEncadeada.h"
#include "music.h"

class Playlist
{
private:
  std::string nome;
  ListaEncadeada<Music> listaMusicas;

public:
  Playlist();
  ~Playlist();
  Playlist(std::string nome);
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
  void setNome(std::string nome) { this->nome = nome; }
  bool operator==(const Playlist &outra) const;
  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, cria um objeto musica e o adiciona a playlist atraves da função inserir() da lista encadeada
   *  @param titulo
   * @param autor
   */

  void adicionarMusica(std::string titulo, std::string autor);
  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, cria um objeto musica e o remove da playlist atraves da função remover() da lista encadeada.
   * @param titulo
   * @param autor
   */
  void removerMusica(std::string titulo, std::string autor);
  /**
   * @brief Metodo da classe playlist que imprimi as musicas de uma playlist traves da função imprimir() da lista encadeada.
   */
  void imprimirMusicas();
  /**
   * @brief Metodo da classe playlist que recebe os parametros string titulo e autor, e passa os parametros para o metodo buscarNodeM() da lista encadada e retorna true para caso a musica esteja na playlist e false para oposto.
   * @param titulo
   * @param autor
   * @return bool
   */

  bool buscarMusica(std::string titulo, std::string autor);
  /**
   *@brief Metodo da classe playlist que imprime as musicas da playlist uma de cada vez, de forma que o usuario possa controlar a passagem das musicas ou voltar para o menu.
   *@param nome
   */
  void play(std::string nome);
  /**
   * @brief Metodo recursivo que imprime as musicas de uma playlist
   *
   * @param node
   */
  void imprimirMus(Node<Music> *node);
};

#endif
