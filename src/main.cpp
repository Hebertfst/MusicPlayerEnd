#include <iostream>
#include "ListaEncadeada.h"
#include "func.h"

int main()
{
  /**
   * @brief Criação da lista de playlists
   *
   */
  ListaEncadeada<Playlist *> listaPlaylist;
  // Criando algumas playlists
  Playlist *play1 = new Playlist("p1");
  Playlist *play2 = new Playlist("p2");
  Playlist *play3 = new Playlist("p3");
  // Inserindo as playlists na lista
  listaPlaylist.inserir(play1);
  listaPlaylist.inserir(play2);
  listaPlaylist.inserir(play3);
  // Adicionando algumas musicas nas playlists
  play1->adicionarMusica("m1", "a1");
  play2->adicionarMusica("m2", "a2");
  play3->adicionarMusica("m3", "a3");
  menu(listaPlaylist);
  delete play1;
  delete play2;
  delete play3;

  return 0;
}
