/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:05:45 by csamundi          #+#    #+#             */
/*   Updated: 2024/05/30 16:25:47 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"// Cabeçalho....

char	*ft_read_to_left_str(int fd, char *left_str): //Declarando a nossa função
{
	char	*buff; //Declara um ponteiro para (char) chamado (buff).
	int		rd_bytes; //Declara uma variavel inteira chamada rd_bytes.

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));//Aloca memória para buff com o tamanho de BUFFER_SIZE + 1.
	
	if (!buff) //Se a alocação de memória falhar, retorn NULL
		return (NULL);
		
	rd_bytes = 1; //Inicializando a minha variavel com valor (1) ou na posição (1).
	
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)//: Enquanto não encontrar um caractere de nova linha em left_str e rd_bytes for diferente de zero (0).
	
	{ Inicializanod a nossa condição (while).
	
		rd_bytes = read(fd, buff, BUFFER_SIZE); //Lê o BUFFER_SIZE de caracteres do arquivo e armazena em buff.
		if (rd_bytes == -1): //Caso a leitura falhe, lebera a memória alocada para o buff e retorna (NULL).
		
		{ //Iniciando a condição (if).
			free (buff); //Utilezei o (free) pra liberar memória no buff.
			return (NULL); //Após isso retorna (NULL).
		}//FIm da condição.
		
		buff[rd_bytes] = '\0'; //Adicionando um caractere nulo no final do (buff).
		left_str = ft_strjoin(left_str, buff); //Juntando (left_str e buff) e armazena em left. 
	} //Fim do (while).
	
	free(buff); //Liberando a memória do (buff).
	return (left_str); //Retorna o valor de left_str.
}

char	*get_next_line(int fd) //Nome da mina função com um parametro fd ou (Descritor de arquivos).
{
	char		*line; //Uma variavel do tipo (char) para um ponteiro (*line).
	static char	*left_str;// Uma variavel do tipo (static char) para o ponteiro (*left_str).

	if (fd < 0 || BUFFER_SIZE <= 0): //Se fd(Descritor de arquivos) for menor ou ique que a 0 retorna (0)
		return (0);
		
	left_str = ft_read_to_left_str(fd, left_str); //Chama a função ft_read_to_left_str e armazena  o resultadpo em left_str...
	
	if (!left_str) // Se left_str for (NULL), retorna (NULL).
		return (NULL);
		
	line = ft_get_line(left_str); //Chamando a função ft_get_line e armazena o resultado em line.
	left_str = ft_new_left_str(left_str);// chama a função ft_new_left_str e armazena o resultado em left_str.
	return (line); //retorna line.
}
