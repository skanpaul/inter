/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ski <marvin@42lausanne.ch>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:40:12 by ski               #+#    #+#             */
/*   Updated: 2022/01/16 13:40:19 by ski              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "inter.h"
/* ************************************************************************** */
void reset_mem(bool *memory);
bool is_common_char(char c, char *text);
/* ************************************************************************** */
int main(int argc, char **argv)
{
	char *text1;
	char *text2;
	bool memory[256];
	int i;

	reset_mem(memory);
	
	if (argc == 3)
	{
		text1 = argv[1];
		text2 = argv[2];

		i = 0;
		while (text1[i] != '\0')
		{
			if (is_common_char(text1[i], text2))
				if (memory[(unsigned char)text1[i]] == false)
					{
						write(1, &text1[i], 1);
						memory[(unsigned char)text1[i]] = true;
					}
			i++;
		}

	}
	write(1, "\n", 1);
	return (0);
}

/* ************************************************************************** */
void reset_mem(bool *memory)
{
	int i;

	i = 0;
	while(i < 256)
	{
		memory[i] = false;
		i++;
	}
	return ;
}
/* ************************************************************************** */
bool is_common_char(char c, char *text)
{
	int i;

	i = 0;
	while (text[i] != '\0')
	{
		if (c == text[i])
			return (true);
		i++;
	}
	return (false);
}
