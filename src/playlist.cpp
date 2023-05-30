#include "Playlist.h"

Playlist::Playlist() {}

Playlist::~Playlist() {}
Playlist::Playlist(std::string nome)
{
  this->nome = nome;
}
bool Playlist::operator==(const Playlist &outra) const
{
  return this->nome == outra.nome;
}

void Playlist::adicionarMusica(std::string titulo, std::string autor)
{
  Music musica(titulo, autor);
  listaMusicas.inserir(musica);
}

void Playlist::removerMusica(std::string titulo, std::string autor)
{
  Music musica(titulo, autor);
  listaMusicas.remover(musica);
}

void Playlist::imprimirMusicas()
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

void Playlist::imprimirMus(Node<Music> *node)
{
  if (node == nullptr)
  {
    return;
  }
  std::cout << "Titulo: " << node->getValor().getTitulo();
  std::cout << ", Autor: " << node->getValor().getAutor() << std::endl;

  imprimirMus(node->getProx());
}

bool Playlist::buscarMusica(std::string titulo, std::string autor)
{
  Music m1(titulo, autor);
  return listaMusicas.buscarNodeBool(m1);
}

void Playlist::play(std::string nome)
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
Node<Music> *Playlist::getPrimeiraMusica()
{
  Node<Music> *primeiroNode = listaMusicas.getHead();
  if (primeiroNode != nullptr)
  {
    return primeiroNode;
  }
  return nullptr;
}
void Playlist::adicionarPlaylist(Playlist &outraPlaylist)
{
  listaMusicas.adicionarLista(listaMusicas, outraPlaylist.listaMusicas);
}
int Playlist::removerPlaylist(Playlist &outraPlaylist)
{
  int elementosRemovidos = listaMusicas.removerElementos(listaMusicas, outraPlaylist.listaMusicas);
  return elementosRemovidos;
}
void Playlist::copiaPlaylist(Playlist &outraPlaylist)
{
  listaMusicas.construtorCopia(outraPlaylist.listaMusicas);
}

void Playlist::operator>>(Node<Music> *&no)
{
  listaMusicas >> no;
}

void Playlist::operator<<(Node<Music> *no)
{
  listaMusicas << no;
}
