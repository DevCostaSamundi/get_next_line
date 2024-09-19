/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:26:24 by csamundi          #+#    #+#             */
/*   Updated: 2024/05/30 16:35:01 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H : //Para verificar se o GET_NEXT_LINE_H ja esta definido caso não esta definido, definda.
# define GET_NEXT_LINE_H : //Definido o GET_NEXT_LINE_H. 

.... // Inclui as bibliotecas necessarias para função......
# include <stdlib.h>
. //Inclui o arquivo de cabeçalho da biblieteca pardrão.

# include <unistd.h>
.// Inclui o arquivo de cabeçalho para chamadas de sistemas unix.

# ifndef BUFFER_SIZE : //Se o (BUFFER_SIZE) não esta definido, defina.. 
#  define BUFFER_SIZE 1000 : //Definido o (BUFFER_SIZE) como 1000.
# endif

char	*get_next_line(int fd);
.//Esta função lê uma linha de um arquivo de texto. O parâmetro (fd) é o descritor de arquivo do qual a linha deve ser lida.

.//A função retorna a linha lida ou (NULL) se não houver linhas para ler.

char	*ft_read_to_left_str(int fd, char *left_str);
.// Esta função lê conteúdo do arquivo em um buffer e anexa buffer à string left_str.

.//A função retorna a string atualizada.

char	*ft_strchr(char *s, int c);
.// Esta função procura o caractere (C) na string (S).

.// Esta funçào retorna um ponteiro para a primeira o corrência do caractere na string, ou (NULL) se o caractere não for encontrado.

char	*ft_strjoin(char *left_str, char *buff);
.// Esta função concatena (left_str) e (buff).

.// Retorna a nova string.

size_t	ft_strlen(char *s);
.// Esta função retorna o comprimento da string (S).
char	*ft_get_line(char *left_str);
.// Esta função extrai uma linha da string.

char	*ft_new_left_str(char *left_str);
.// Esta função atualiza left_str, removendo a linha que foi lida.

#endif .//Fim da condição de Pré-processamento
