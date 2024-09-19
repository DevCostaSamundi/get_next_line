Get_next_line
Get_next_line é um projeto da Escola 42 que tem como objetivo implementar uma função em C capaz de ler uma linha de um descritor de arquivo a cada chamada. A função retorna uma linha completa a cada vez que é chamada, permitindo ler arquivos ou entradas de maneira eficiente.

Objetivo
O objetivo do projeto é criar uma função chamada get_next_line que lê e retorna a próxima linha de um descritor de arquivo (como stdin, um arquivo de texto ou um socket).

Requisitos
A função get_next_line deve atender aos seguintes requisitos:

Ler uma linha de um arquivo, terminada por um \n ou pelo final do arquivo.
Conseguir lidar com múltiplos descritores de arquivo abertos simultaneamente.
Lidar com arquivos de qualquer tamanho, inclusive com longas linhas.
A função deve ser capaz de ser chamada repetidamente, retornando uma nova linha a cada chamada.

Função
char *get_next_line(int fd);

Parâmetros:
fd: O descritor de arquivo do qual ler a linha.
Valor de retorno:

Retorna a próxima linha lida, incluindo o caractere \n (exceto no final do arquivo).
Retorna NULL quando não há mais linhas a serem lidas ou em caso de erro.

Como Funciona

A função lê dados do arquivo em blocos de tamanho BUFFER_SIZE, que é definido no início do código ou passado como uma flag de compilação.
Ela utiliza uma memória estática para armazenar dados não processados e continuar a leitura de onde parou, permitindo o processamento eficiente de arquivos grandes ou com várias linhas.
Cada chamada de get_next_line retorna a próxima linha, permitindo a leitura sequencial de um arquivo.

Arquivos do Projeto

Principais:

get_next_line.c: Contém a lógica principal para ler e retornar a próxima linha de um descritor de arquivo.

get_next_line_utils.c: Funções auxiliares usadas por get_next_line, como manipulação de strings e memória dinâmica.

get_next_line.h: Arquivo de cabeçalho contendo as declarações da função e macros utilizadas.

Funções Utilizadas:

get_next_line: A função principal que lê uma linha por vez de um arquivo.

ft_strjoin: Junta duas strings, usada para concatenar o buffer lido com o conteúdo já existente.

ft_strdup: Faz uma cópia de uma string, usada para armazenar a linha lida.

ft_strchr: Encontra o primeiro caractere \n em uma string, usado para detectar o fim da linha.

ft_substr: Cria uma substring, usada para separar a linha completa do buffer residual.

Exemplo de Uso
Aqui está um exemplo de como usar a função get_next_line para ler um arquivo:

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    
    int fd = open("test.txt", O_RDONLY); // Abre o arquivo em modo de leitura
    
    char *line;

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line); // Exibe cada linha lida
        free(line); // Libera a memória da linha lida
    }
    close(fd); // Fecha o arquivo
    return 0;
}

Você pode compilar o projeto utilizando um compilador como o GCC, e passando o BUFFER_SIZE como uma flag de compilação, se necessário.

gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl

Testes

Testando com arquivos:

./gnl <nome_do_arquivo>


Erros Comuns

Memória não liberada: Certifique-se de liberar a memória alocada para cada linha após o uso.

BUFFER_SIZE inadequado: O desempenho pode variar com o tamanho do BUFFER_SIZE. Valores pequenos podem aumentar o número de chamadas ao sistema, enquanto valores muito grandes podem desperdiçar memória.

Uso incorreto de descritores de arquivo: Certifique-se de que o descritor de arquivo é válido e que o arquivo foi aberto corretamente.

Regras do Projeto

Não é permitido o uso de funções como lseek, malloc_size ou getline.

A função deve ser modular, bem organizada e seguir as regras da Norminette.

A função deve ser capaz de funcionar para descritores de arquivo válidos e retornar NULL em caso de erro ou no final do arquivo.

Contribuições

Sinta-se à vontade para contribuir com melhorias, abrir issues ou enviar pull requests se encontrar bugs ou formas de otimizar o código.

