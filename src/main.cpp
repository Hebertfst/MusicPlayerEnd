#include <iostream>
#include "ListaEncadeada.h"
#include "func.h"
#include <memory>

int main()
{
  /**
   * @brief Criação da lista de playlists
   *
   */
  ListaEncadeada<Playlist *> listaPlaylist;
  // Criando algumas playlists
  Playlist *pla1 = new Playlist("p1");
  Playlist *pla2 = new Playlist("p2");
  Playlist *pla3 = new Playlist("p3");

  // Inserindo as playlists na lista
  listaPlaylist.inserir(pla1);
  listaPlaylist.inserir(pla2);
  listaPlaylist.inserir(pla3);
  // Adicionando algumas musicas nas playlists
  pla1->adicionarMusica("m1", "a1");
  pla2->adicionarMusica("m2", "a2");
  pla3->adicionarMusica("m3", "a3");
  menu(listaPlaylist);

  return 0;
}
