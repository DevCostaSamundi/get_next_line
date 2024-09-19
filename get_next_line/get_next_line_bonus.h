/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:58:12 by csamundi          #+#    #+#             */
/*   Updated: 2024/05/30 17:03:50 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H Verifica se o nosso cabeçalho já foi definido senão defini ele.
# define GET_NEXT_LINE_BONUS_H Defini o cabeçalho.

....Colocando as Bibliotecas....
# include <stdlib.h>
# include <unistd.h>
.......................


# ifndef BUFFER_SIZE
. Esta linha verifica se "BUFFER_SIZE" não foi definido anteriormente no código-fonte.

. Se "BUFFER_SIZE" não estiver definido, o bloco de código entre #ifndef e #endif sera processado.

#define BUFFER_SIZE 1000
. Se "BUFFER_SIZE" não estiver definido, esta linha o define como 1000.

. Este valor é arbitrário e pode ser ajustado conforme necessário, dependendo dos requisitos do programa.

# endif
. Fecha o bloco de código condicional iniciado pelo #ifndef.

. Este bloco de código será ignorado se "BUFFER_SIZE" já estiver definido anteriormente no código do programa.

...Pontos Importantes de cada função...

char	*get_next_line(int fd);
. Esta é a função principal que será usada para obter a próxima linha de um arquivo.

. Ela recebe um descritor de arquivo (fd) como argumento e retorn a proxima linha do arquivo associado a esse descitor de arquivo.

char	*ft_read_to_left_str(int fd, char *left_str);
. Esta função é responsável por ler o conteúdo de um arquivo referenciado por (fd) e concatená-lo com a string de "resto" left_str.

. Ela retorna uma nova string que contém o conteúdo do arquivo e o "resto" não lido.

char	*ft_strchr(char *s, int c);
. Esta função procura a primeira ocorrência do caractere "c" na string "s".

. Retorna um ponteiro para a posicção do caractere na string ou "NULL" se o caractere não for encontrado.

size_t  ft_strlen(char *s);
. Esta função calcula o comprimento da string "s", excluindo o caractere nulo de determinção.

.Retorna o comprimento da string.

char	*ft_strjoin(char *left_str, char *buff);
. Esta função concatena duas string, (left_str e buff).

. Retorna uma nova string que é a concatenação das duas string fornecidas.

char	*ft_get_line(char *left_str);
. Esta função é responsável por extrair a próxima linha da string "left_str";

. Retorna a próxima linha encontrada na estring "left_str";

char	*ft_new_left_str(char *left_str);
. Esta função é usada para atualizar a string "left_str" para conter o restante da string não lida após a extração de uma linha.

. Retorna uma nova string contendo o restante da string não lida.

#endif Fecha o bloco de execução.

Essas funções são essenciais para implementação da função "get_next_line" e para a manipulação de strings usadas na leitura e processamentos de arquivos.

Esses macros são úteis para garantir que o cabeçalho seja incluido corretamente apenas uma vez em cada arquivo de código-fonte, além de definir um valor padrão para o tamanho do buffer usada na leitura dos arquivos. Isso torna o código mais modular e portável.