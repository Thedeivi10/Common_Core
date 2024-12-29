/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davigome <davigome@studen.42malaga.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:20:47 by davigome          #+#    #+#             */
/*   Updated: 2024/12/29 17:07:26 by davigome         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	space(const char *str, int cont)
{
	if ((str[cont] >= 9 && str[cont] <= 13) || str[cont] == 32)
		return (1);
	return (0);
}

long long	ft_atoi_long(const char *str)
{
	size_t			cont;
	long long		number;
	int				neg;

	cont = 0;
	number = 0;
	neg = 1;
	while (space(str, cont))
		cont++;
	if (str[cont] == '-' || str[cont] == '+')
	{
		if (str[cont] == '-')
			neg = -1;
		cont++;
	}
	while (ft_isdigit(str[cont]))
	{
		number = number * 10 + (str[cont] - 48);
		cont++;
	}
	number = neg * number;
	return (number);
}

t_stack	*ft_first_value(t_nums *nums)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		ft_printf("Error\n");
		ft_free_nums(nums);
		exit(1);
	}
	new->value = nums->list[0];
	new->next = NULL;
	return (new);
}