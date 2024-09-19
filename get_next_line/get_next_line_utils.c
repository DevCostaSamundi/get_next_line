/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csamundi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 17:05:39 by csamundi          #+#    #+#             */
/*   Updated: 2024/05/31 08:42:47 by csamundi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"//Incluindo o cabeçalho GET_NEXT_LINE

size_t	ft_strlen(char *s)//Função para calcular o comprimento de uma string.

{
	size_t	i;//Declara uma variavel (i) do tipo size_t par iterar a string.

	i = 0;
	if (!s)//Se (s) for (NULL).
	
		return (0);//Retorna (0).
		
	while (s[i] != '\0')//Enquanto o caractere na posição (i) de (s) não for o caractere nulo
	
		i++;//Incrementa para percorrer a string
		
	return (i);//Retorna o tamanho da string.
}

char	*ft_strchr(char *s, int c)// Função para encontrar a primeira ocorrência do caractere (c) em (s).
{
	int	i;//Declara uma variavel (i) do tipo int.

	i = 0; //Inicializa com (0).
	
	if (!s)// Se (s) for (NULL).
	
		return (0);//Retorna (NUL).
		
	if (c == '\0')//Se (c) for o caractere nulo, retorna um ponteiro para o final de (s).
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')// Enquanto o caractere na posição (i) de (s) não for o caractere nulo
	{
		if (s[i] == (char) c)//Se o caractere na posição (i) de (s) for igual a (c).
		
			return ((char *)&s[i]);//Retorna um ponteiro para a posição (i) de (s).
		i++;//Incrementa (i).
	}
	return (0);//Se (c) não for encontrado em (s), retorna (0).
}

char	*ft_strjoin(char *left_str, char *buff)//Função para concatenar letf_str e buff. 
{
	size_t	i; //Declara uma variavel (i) do tipo size_t.
	
	size_t	j;//Declara uma variavel (j) do tipo size_t.
	
	char	*str; //Declara uma variavel ponteiro para char chamado str

	if (!left_str)// Se left_str for (NULL)
	{
		left_str = (char *)malloc(1 * sizeof(char));//Aloca memória para left_str
		
		left_str[0] = '\0';//Inicializa left_str com o caractere nulo
	}
	if (!left_str || !buff)// Se left_str ou buff for (NULL), Retorna(NULL).
		return (NULL);//Retorna (NULL)
		
		
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));// Aloca memória para str com o tamanho de left_str + buff + 1.
	
	if (str == NULL)//Se for Igual A (NULL).
	
		return (NULL);//Retorna (NULL).
		
	i = -1;//Inicializa (i) com (0)
	
	j = 0;//Inicializa (j) com (0)
	
	if (left_str) // Se left_str não for (NULL).
		while (left_str[++i] != '\0')// Enquanto o caractere na posição (i) de left_str não for o caractere nulo 
		
			str[i] = left_str[i];// Copia o caractere na posição (i) de left_str não for o caractere nulo
	while (buff[j] != '\0')//Enquanto o caractere na posição (i) de left_str não for o caractere nulo
	
		str[i++] = buff[j++];// Copia o caractere na posição (j) de buff para a posição (i) de str e incrementada (i) e (j).
		
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';//Adiciona o caractere nulo ao final de str.
	
	free(left_str);//Libera a memória alocada para left_str
	
	return (str);//Retorna Str.
}

char	*ft_get_line(char *left_str)// Função obter uma linha de left_str
{
	int		i;//Declara um a variavel (i) do tipo int
	
	char	*str; //Declara um ponteiro para char chamado str.

	i = 0; //Inicializa (i) com (0).
	if (!left_str[i])//SE o primeiro caractere de left_str for o caractere nulo, retorna (NULL).
		return (NULL); //retorna (NULL).
	while (left_str[i] && left_str[i] != '\n') //Enquanto o caractere na posição (i) de left_str não for o caractere nulo ou caractere de nova linha.
		i++;// Incrementa (i).
		
	str = (char *)malloc(sizeof(char) * (i + 2));// Aloca memória para str com tamanho de i +2.
	
	if (!str)//Se a alocação de memória falhar, retorna (NULL). 
	
		return (NULL);//Retorna (NULL).
		
	i = 0;//Inicializa (i) com 0.
	
	while (left_str[i] && left_str[i] != '\n') //Enquanto o caractere na posição de (i) de left_str não for  caractere nulo ou o caractere de nova linha.
	{
		str[i] = left_str[i];// Copia o caractere na posição (i) de left_str para a posição (i) de str.
		
		i++;//Incrementa (i).
	}
	if (left_str[i] == '\n') //Se o caractere na posição (i) de left_str for o caractere de nova linha
	{
		str[i] = left_str[i]; //Copia o caractere na posição (i) de left_str para posição (i) de str.
		
		i++;// Incrementa (i).
	}
	str[i] = '\0';//Adiciona o caractere nulo no final da (str);
	
	return (str);//Retorna (str).
}

char	*ft_new_left_str(char *left_str) //Função para atualizar left_str removendo a linha que foi lida.
{
	int		i;//Declara uma variavel (i) do tipo int
	
	int		j;//Declara uma variavel (j) do tipo int.
	
	char	*str;//Declara um ponteiro para char chamado(str).

	i = 0; //Inicializa com (0).
	while (left_str[i] && left_str[i] != '\n') //Enquanto o caractere na posição (i) de left_str não for o caractere nulo ou o caractere de nova linha.
	
		i++;// Incrementa (i).
		
	if (!left_str[i])//Se o caractere na posição (i) de left_str for o caractere nulo.
	{
		free(left_str);//Libera memória alocada para left_str
		
		return (NULL); // Retorna (NULL).
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1)); //Aloca memória para str com o tamanho de left_str - i + 1.
	
	if (!str) //Se a alocação de memória falhar, retorna (NULL).
		return (NULL);
		
	i++;// incrementada (i).
	
	j = 0;// Inicializa (j) com (0).
	
	while (left_str[i]) //Enquanto o caractere na posição (i) de left_str não for o caractere nulo.
	
		str[j++] = left_str[i++]; //Copia o caractere na posição (i) de left_str para a posição (j) de str e incrementa (i).
		
	str[j] = '\0'; //Adiciona o caractere nulo ao final de str
	
	free(left_str);//Libera a memória alocada para left_str
	
	return (str); //Retorna str.
}