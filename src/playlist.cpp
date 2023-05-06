#include "playlist.h"

Playlist::Playlist(std::string nome, ListaEncadeada<Music> listaMusicas)
{
  this->nome = nome;
  this->listaMusicas = listaMusicas;
}

void adicionarMusica(std::string titulo, std::string autor, ListaEncadeada<Music> listaMusicas)
{
  Music musica(titulo, autor);
  listaMusicas.inserir(musica);
}

void removerMusica(std::string titulo, std::string autor, ListaEncadeada<Music> &listaMusicas)
{
  Music musica(titulo, autor);
  listaMusicas.remover(musica);
}

void imprimirMusicas(ListaEncadeada<Music> &listaMusicas)
{
  Playlist
          std::cout
      << "Playlist: " << nome << std::endl;
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