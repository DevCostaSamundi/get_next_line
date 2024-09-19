/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:35:46 by csamundi          #+#    #+#             */
/*   Updated: 2024/06/05 08:21:16 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h" Incluindo o cabeçalho que contêm as definições de funções e estruturas necessarias para o funcionamento do código.

char	*ft_read_to_left_str(int fd, char *left_str) Assinatura da função, que recebe um descritor de arquivos(fd), e uma string contendo o "resto" do arquivo(left_str);
a função retorna um ponteiro para char.
{
	char	*buff; Aqui, declaramos duas variáveis locais: buff, que será usada para armazenar os bytes lidos do arquivo.
	int		rd_bytes; Esta variável armazenará o número de bytes lidos a cada chamada de read.

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char)); Alocando memória para o buffer de leitura(buff) com o tamanho de BUFFER_SIZE + 1 bytes. O +1 é para acomodar o caractere nulo no final da string.
	
	if (!buff): Esta linha verifica se a alocação de memória foi bem-sucessida. Se não for, a função retorna NULL.
		return (NULL);
		
		
	rd_bytes = 1; Inicializa rd_bytes como 1, para entrar no loop abaixo na primeira iteração.
	
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)Este é um loop que continua até que a função ft_strchr(Que procura um caractere nulo, na string left_str), retorna verdadeiro ou procura o caracteres de nova linha '\n' na string (left_str) retorne verdadeiro ou até rd_bytes ser igual a 0, indicando o final do arquivo ou um erro de leitura.
	
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE); O read é usada para ler bytes do arqiuvo referenciado por fd para o buffer "buff". O número maximo de bytes a serem lidos é especificado por buffer_size.
		
		if (rd_bytes == -1)
		{
			free(buff);
			return (NULL);
		}Se read retorn -1, indica um erro de leitura, Nesse caso, liberamos a memória alocada para "buff" e retornamos "NULL".
		
		
		
		buff[rd_bytes] = '\0';Coloca um caractere nulo no final do buffer para garantirn que ele seja taratdo como string C válida.
		
		left_str = ft_strjoin(left_str, buff);Concatena "buff
 ao final de left_str usando a função ft_strjoin. Isso é feito para acumular os dados lidos até o momento na variável left_str.
 
	free(buff);Para liberar memória.
	
	return (left_str);Retornamos a string left_str, que agora contêm os dados lidos do arquivo até o momento.

	    
	}Fim do loop;

    
}fim da função.




char	*get_next_line(int fd) : Esta linha a função get_next_line, qie recebe um descritor de arquivo (fd) e retorna um ponteiro para char, representando a próxima linha do arquivo.
{
    Aqui declaramos duas variáveis locais: line: Que será usada para armazenar a linha lida do arquivo, e left_str, que é uma matriz estática de ponteiros para caracteres usada para armazenar o "resto" não lido de cada arquivo aberto.
	char		*line;
	static char	*left_str[4096]; O número 4096 na declaração da variável left_str, é o tamanho da matriz estática que armazena os "restos" das leituras dos arquivos abertos. Nesse caso, left_str é uma matriz de ponteiros para caracteres (char *), onde cada elemento da matriz corresponde a um arquivo identificado pelo seu descritor de arquivo (fd).
	
	Esse número específico provalvemente foi escolhido como um limite superior para o número de arquivos que o programa pode manipular simultaneamente. Isso significa que o programa pode manipular até 4096 arquivos abertos simultaneamente, com cada arquivo tendo seu prórpio "resto" não lido armazenado em "left_str".


	if (fd < 0 || BUFFER_SIZE <= 0) Esta linha verifica se o descritor de arquivo "fd" é válida (ou seja, maior ou igual a 0) e se o BUFFER_SIZE é maior que 0. Se uma das condições não for atendida, a função retorna "NULL".
		return (0);
		
	left_str[fd] = ft_read_to_left_str(fd, left_str[fd]); Chama a função ft_read_to_left_str, para ler o conteúdo do arquivo referenciado por "fd" e atualiza left_str[fd] com o "resto" não lidodo arquivo.
	
	if (!left_str[fd]) verifica se houve erro na leitura do arquivo. Se left_str[fd] for NULL, Indica que ocorreu um erro, então a função retorna NULL;
		return (NULL); 
		
	line = ft_get_line(left_str[fd]);  Chama a função get_next_line para estrair a proxima linha apartir do "resto" não lido(left_str[fd]) e armazenar na variável (line);
	
	left_str[fd] = ft_new_left_str(left_str[fd]);Atualiza left_str[fd] para conter o restante do "resto" não lido, ou seja, os caracteres que não foram lidos na linha atual.
	
	
	return (line);Retorna a linha lida do arguivo.
	
}Fim da função.

Variáveis estátiticas em  linguegem c são variáveis que mantêm seu valor mesmo após a saida do escopo em que foram definidas. Elas são declaradas com palavra-chave static e podem ser usadas em diferentes contextos dentro de um programa.

As variáveis estaticas são úteis por várias razões:

1. Manutenção de valor: As variáveis estáticas mantêm seu valor entre chamadas de função, oque pode ser útil quando você precisa preservar o estado de uma variável entra chamadas consecutivas da mesma função.

2. Escopo Local Permanente: Variáveis estáticas tem escopo local dentro da função em que são definidas, mas mantêm sua existência e valor entre as chamadas dessa função.

3. Evitar a Redefinição: Em algumas situações, é desejável evitar que uma variável local seja redefinida toda vez que função é chamada. Variáveis estáticas fornecem uma maneira de evitar isso.

4. Privacidade  de escopo: Variáveis estáticas são acessiveis apenas dentro do escopo da função em que são definidas, o que pode ajudar a evitar colissões de nomes e manter a modularidade do codigo.

Em resumo, as variáveis estáticas são úteis quando você precisa preservar o valor de uma variável entre chamadas de função ou garantir que seu escoppo seja restrito a função ou garantir que seu escopo seja restrito à função em que são definidas. Elas são uma ferramenta importante para o controle de estado e modularidade em programas de linguagem C.