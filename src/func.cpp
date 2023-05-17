#include "func.h"
#include <memory>
#include <limits>

void menu(ListaEncadeada<Playlist *> &lista)
{
  int x;
  std::cout << "\n===============MusicLab================" << std::endl;
  std::cout << "\n1 - Gerenciar playlists" << std::endl;
  std::cout << "2 - Gerenciar musicas" << std::endl;
  std::cout << "0 - Sair" << std::endl;
  std::cout << "\n=======================================" << std::endl;
  std::cout << "O que voce deseja fazer?" << std::endl;

  while (!(std::cin >> x))
  {
    std::cin.clear();                                                   // Limpa o estado de erro de cin
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da linha
    std::cout << "Comando invalido. Tente novamente." << std::endl;
  }

  if (x == 1)
    menuPlaylist(lista);
  else if (x == 2)
    menuMusica(lista);
  else if (x == 0)
  {
    auto atual = lista.getHead();
    while (atual != nullptr)
    {
      delete atual->getValor();
      atual = atual->getProx();
    }
    return;
  }

  else
  {
    std::cout << "Comando invalido. Tente novamente." << std::endl;
    menu(lista);
  }
}
void addPlaylist(ListaEncadeada<Playlist *> &lista)
{
  std::string nome;
  std::cin.ignore();
  std::cout << "Digite o nome da playlist a ser adicionada:" << std::endl;
  std::getline(std::cin, nome);

  if (lista.buscarNode(nome) == nullptr)
  {
    Playlist *play = new Playlist(nome);
    lista.inserir(play);
    std::cout << "Playlist adicionada com sucesso." << std::endl;
  }
  else
  {
    std::cout << "A playlist ja existe" << std::endl;
  }
  menuPlaylist(lista);
}
void rePlaylist(ListaEncadeada<Playlist *> &lista)
{
  std::string nome;
  std::cin.ignore();
  std::cout << "Digite o nome da playlist a ser removida:" << std::endl;
  std::getline(std::cin, nome);

  if (lista.buscarNode(nome) != nullptr)
  {
    lista.remover(lista.buscarNode(nome)->getValor());
    std::cout << "Playlist removida com sucesso" << std::endl;
  }
  else
  {
    std::cout << "Playlist nao encontrada." << std::endl;
  }
  menuPlaylist(lista);
}
void addMusica(ListaEncadeada<Playlist *> &lista)
{
  std::string nome, titulo, autor;
  std::cin.ignore();
  std::cout << "Digite o nome da playlist:" << std::endl;
  std::getline(std::cin, nome);
  if (lista.buscarNode(nome) != nullptr)
  {
    std::cout << "Digite o nome da musica:" << std::endl;
    std::getline(std::cin, titulo);
    std::cout << "Digite o autor da musica:" << std::endl;
    std::getline(std::cin, autor);
    if (lista.buscarNode(nome)->getValor()->buscarMusica(titulo, autor) == false)
    {
      lista.buscarNode(nome)->getValor()->adicionarMusica(titulo, autor);
      std::cout << "Musica adicionada com sucesso." << std::endl;
    }
    else
    {
      std::cout << "Essa musica ja existe na playlist" << std::endl;
    }
  }
  else
  {
    std::cout << "A playlist nao existe." << std::endl;
  }
  menuMusica(lista);
}
void reMusica(ListaEncadeada<Playlist *> &lista)
{
  std::string titulo, autor, nome;
  std::cin.ignore();
  std::cout << "Digite o nome da playlist:" << std::endl;
  std::getline(std::cin, nome);
  if (lista.buscarNode(nome) != nullptr)
  {
    std::cout << "Digite o nome da musica a ser removida:" << std::endl;
    std::getline(std::cin, titulo);
    std::cout << "Digite o nome do autor:" << std::endl;
    std::getline(std::cin, autor);
    if (lista.buscarNode(nome)->getValor()->buscarMusica(titulo, autor) == true)
    {
      lista.buscarNode(nome)->getValor()->removerMusica(titulo, autor);
      std::cout << "Musica removida com sucesso." << std::endl;
    }
    else
    {
      std::cout << "A musica nao existe" << std::endl;
    }
  }
  else
  {
    std::cout << "A playlist nao existe." << std::endl;
  }
  menuMusica(lista);
}

void reMusTPlay(ListaEncadeada<Playlist *> &lista)
{
  std::string titulo, autor;
  std::cin.ignore();
  std::cout << "Digite o nome da musica a ser removida:" << std::endl;
  std::getline(std::cin, titulo);
  std::cout << "Digite o nome do autor:" << std::endl;
  std::getline(std::cin, autor);
  Node<Playlist *> *atual = lista.getHead();
  int v = 0;
  while (atual != nullptr)
  {
    if (lista.buscarNode(atual->getValor()->getTitulo())->getValor()->buscarMusica(titulo, autor) == true)
    {
      atual->getValor()->removerMusica(titulo, autor);
      v++;
    }
    atual = atual->getProx();
  }
  if (v == 0)
  {
    std::cout << "Essa musica nao existe." << std::endl;
  }
  else
  {
    std::cout << "Musica removida de " << v << " playlists" << std::endl;
  }
  menuMusica(lista);
}
void moverMusica(ListaEncadeada<Playlist *> &lista)
{
  std::string titulo, autor, nome1, nome2;
  std::cin.ignore();
  std::cout << "Digite o nome da playlist a mover:" << std::endl;
  std::getline(std::cin, nome1);
  if (lista.buscarNode(nome1) != nullptr)
  {
    std::cout << "Digite o nome da musica a ser movida:" << std::endl;
    std::getline(std::cin, titulo);
    std::cout << "Digite o nome do autor:" << std::endl;
    std::getline(std::cin, autor);
    if (lista.buscarNode(nome1)->getValor()->buscarMusica(titulo, autor) == true)
    {
      std::cout << "Digite o nome da playlist que ira receber a musica:" << std::endl;
      std::getline(std::cin, nome2);
      if (lista.buscarNode(nome2) != nullptr)
      {
        if (lista.buscarNode(nome2)->getValor()->buscarMusica(titulo, autor) == false)
        {
          lista.buscarNode(nome1)->getValor()->removerMusica(titulo, autor);
          lista.buscarNode(nome2)->getValor()->adicionarMusica(titulo, autor);
          std::cout << "Musica movida com sucesso." << std::endl;
        }
        else
        {
          std::cout << "Essa musica ja existe na playlist" << std::endl;
        }
      }
      else
      {
        std::cout << "A playlist nao existe." << std::endl;
      }
    }
    else
    {
      std::cout << "A musica nao esta na playlist" << std::endl;
    }
  }
  else
  {
    std::cout << "A playlist nao existe." << std::endl;
  }

  menuMusica(lista);
}
void imprimirMusic(ListaEncadeada<Playlist *> &lista)
{
  std::string nome;
  std::cin.ignore();
  std::cout << "Digite o nome da playlist:" << std::endl;
  std::getline(std::cin, nome);
  if (lista.buscarNode(nome) != nullptr)
  {
    std::cout << "Imprimindos todas as musicas da playlist: " << nome << std::endl;
    lista.buscarNode(nome)->getValor()->imprimirMusicas();
  }
  else
  {
    std::cout << "A playlist nao existe" << std::endl;
  }
  menuMusica(lista);
}

void tocar(ListaEncadeada<Playlist *> &lista)
{
  std::string nome;
  std::cin.ignore();
  std::cout << "Digite o nome da playlist:" << std::endl;
  std::getline(std::cin, nome);
  if (lista.buscarNode(nome) != nullptr)
  {
    lista.buscarNode(nome)->getValor()->play(nome);
    std::cout << "Fim da playlist" << std::endl;
  }
  else
  {
    std::cout << "A playlist nao existe" << std::endl;
  }
  menuPlaylist(lista);
}
void imprimirPlay(Node<Playlist *> *node)
{
  if (node == nullptr)
  {
    return;
  }
  std::cout << "Titulo: " << node->getValor()->getTitulo() << std::endl;
  imprimirPlay(node->getProx());
}
void imprimirPlaylists(ListaEncadeada<Playlist *> &lista)
{
  if (lista.getHead() != nullptr)
  {
    std::cout << "Imprimindo todas as playlists..." << std::endl;
    imprimirPlay(lista.getHead());
  }
  else
  {
    std::cout << "Nao ha playlists cadastradas no momento." << std::endl;
  }
  menuPlaylist(lista);
}
void menuPlaylist(ListaEncadeada<Playlist *> &lista)
{
  int y;
  std::cout << "\n=======Gerenciador de playlists========" << std::endl;
  std::cout << "\n1 - Ver playlists" << std::endl;
  std::cout << "2 - Adicionar playlist" << std::endl;
  std::cout << "3 - Remover playlist" << std::endl;
  std::cout << "4 - Tocar musicas de uma playlist" << std::endl;
  std::cout << "0 - Voltar" << std::endl;
  std::cout << "\n=======================================" << std::endl;
  std::cout << "O que voce deseja fazer?" << std::endl;
  std::cin >> y;
  switch (y)
  {
  case 1:
    imprimirPlaylists(lista);
    break;
  case 2:
    addPlaylist(lista);
    break;
  case 3:
    rePlaylist(lista);
    break;
  case 4:
    tocar(lista);
    break;
  case 0:
    menu(lista);
    break;
  default:
    std::cout << "Comando invalido. Tente novamente." << std::endl;
    menuPlaylist(lista);
    break;
  }
}

void menuMusica(ListaEncadeada<Playlist *> &lista)
{
  int y;
  std::cout << "\n========Gerenciador de Musicas=========" << std::endl;
  std::cout << "\n1 - Adicionar musica a uma playlist" << std::endl;
  std::cout << "2 - Remover musica de uma playlist" << std::endl;
  std::cout << "3 - Ver musicas de uma playlist" << std::endl;
  std::cout << "4 - Remover musica de todas as playlists" << std::endl;
  std::cout << "5 - Mover musica de uma playlist" << std::endl;
  std::cout << "0 - Voltar" << std::endl;
  std::cout << "\n=======================================" << std::endl;
  std::cout << "O que voce deseja fazer?" << std::endl;
  std::cin >> y;
  switch (y)
  {
  case 1:
    addMusica(lista);
    break;
  case 2:
    reMusica(lista);
    break;
  case 3:
    imprimirMusic(lista);
    break;
  case 4:
    reMusTPlay(lista);
    break;
  case 5:
    moverMusica(lista);
    break;
  case 0:
    menu(lista);
    break;
  default:
    std::cout << "Comando invalido. Tente novamente." << std::endl;
    menuMusica(lista);
    break;
  }
}