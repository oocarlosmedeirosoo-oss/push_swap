#include "push_swap.h"

// Escreve uma string num file descriptor. - Eles dizem In case of error, it must display "Error" followed by a \n on the standard error.
void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
// Verifica se o char é um dígito.
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
Converte string para int com validação completa.
Retorna 1 se válido, 0 se erro (não é inteiro, overflow - questao do INT_MAX, chars inválidos).
O valor é guardado em *result.
*/
int	ft_atoi_safe(char *str, int *value)
{
	long	result;
	int		sign;
	int		i;

	if (!str || !*str)
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);

		result = result * 10 + (str[i] - '0');

		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && -result < INT_MIN))
			return (0);
		i++;
	}
	*value = (int)(result * sign);
	return (1);
}

int	has_duplicate(t_stack *stack, int value)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		if (temp->value == value)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	print_stack(t_stack *stack)
{
	t_node	*temp;

	temp = stack->top;
	while (temp)
	{
		ft_printf("%d ", temp->value);
		temp = temp->next;
	}
	ft_printf("\n");
}
