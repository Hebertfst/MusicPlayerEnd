#ifndef FUNC_H
#define FUNC_H
#include "ListaEncadeada.h"
#include "playlist.h"
/**
 * @brief Executa o menu principal
 *
 * @param lista
 */
void menu(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Executa o menu que gerencia as playlists
 *
 * @param lista
 */
void menuPlaylist(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Executa o menu que gerencia as musicas
 *
 * @param lista
 */
void menuMusica(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Adiciona musicas a uma playlist
 *
 * @param lista
 */
void addMusica(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Adiciona uma playlist a uma lista de playlists
 *
 * @param lista
 */
void addPlaylist(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Remove uma musica de uma playlist
 *
 * @param lista
 */
void reMusica(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Remove uma playlist de uma lista de playlists
 *
 * @param lista
 */
void rePlaylist(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Imprime todas as musicas de uma playlist
 *
 * @param lista
 */
void imprimirMusic(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Imprime todas as playlists de uma lista de playlists
 *
 * @param lista
 */
void imprimirPlaylists(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Toca as musicas de uma playlist
 *
 * @param lista
 */
void tocar(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Remove uma musica de todas as playlists
 *
 * @param lista
 */
void reMusTPlay(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Move uma musica entre playlists
 *
 * @param lista
 */
void moverMusica(ListaEncadeada<Playlist *> &lista);
/**
 * @brief Metodo recursivo para imprimir a playlist
 *
 * @param node
 */
void imprimirPlay(Node<Playlist *> *node);

#endif