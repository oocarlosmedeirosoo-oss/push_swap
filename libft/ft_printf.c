/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mifranci <mifranci@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 12:57:06 by mifranci          #+#    #+#             */
/*   Updated: 2026/05/06 18:41:13 by mifranci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	choose_data_type(const char *format, va_list ap)
{
	int	counter;

	counter = 0;
	if (*format == 'c')
		counter += ft_printf_c(va_arg(ap, int));
	else if (*format == 's')
		counter += ft_printf_str(va_arg(ap, char *));
	else if (*format == 'p')
		counter += ft_printf_ptr(va_arg(ap, void *));
	else if (*format == 'x' || *format == 'X')
		counter += ft_printf_hex(va_arg(ap, unsigned int), *format);
	else if (*format == 'd' || *format == 'i')
		counter += ft_printf_dec_int(va_arg(ap, int));
	else if (*format == 'u')
		counter += ft_printf_u(va_arg(ap, unsigned int));
	else if (*format == '%')
		counter += ft_printf_c('%');
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	size_t	counter;
	va_list	ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	counter = 0;
	while (*format)
	{
		if (*format == '%')
			counter += choose_data_type(++format, ap);
		else
			counter += ft_printf_c(*format);
		if (*format)
			format++;
	}
	va_end(ap);
	return (counter);
}

/*static int	is_valid(char *format)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (!*(format + 1) || ft_strchr("cspdiuxX%", *(format + 1)) == NULL)
				return (0);
			if (*(format + 1) == '%')
				format++;
		}
		format++;
	}
	return (1);
} */
/*	if (is_valid((char *)format) == 0)
		return (-1);*/
/*void printstr(const char *format, va_list ap)
{
	printf("strt\n"); 
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 's')
		{
			ft_putstr_fd(va_arg(ap, char *), 1);
			format += 2;
		}
		ft_putchar_fd(*format, 1);
		format++;
	}
	printf("end\n"); 
}
int ft_printf(const char *format, ...)
{
	char *ptr;
	int i;
	char *res;
	va_list ap;
	char *array;
	
	if (!ft_strchr(format, '%'))
		ft_putstr_fd((char *)format, 1);
	else
	{
		ptr = ft_strchr(format, '%');
		va_start(ap, format);
		if (*(++ptr) == 's')
			printstr(format, ap);
	}
	return 1;
}*/
/*int ft_printf(const char *fmt, ...)
{
	char **splited;
	int i;
	char *res;
	va_list ap;
	
	splited = ft_split(fmt , '%');
	printf("fmt 		   = %s\n", fmt);
	i = 0;
	
	printf("First split\n"); 
	while (splited[i])
		printf("splited = %s\n", splited[i++]);
	printf("\n"); 
	splited[1]++; 
	i = 0;
	
	printf("Split after ptr[1]++\n"); 
	while (splited[i])
		printf("splited = %s\n", splited[i++]);
	printf("\n"); 
	
	va_start(ap, fmt);
	splited[1] = ft_strjoin(va_arg(ap, char *) , splited[1]);
	i = 0;
	
	printf("Split after ptr[1] = ft_strjoin(va_arg(ap, char *), ptr[1])\n"); 
	while (splited[i])
		printf("splited = %s\n", splited[i++]);
	printf("\n");

	res = ft_strjoin(splited[0], splited[1]);
	printf("res after ft_strjoin(splited[0], splited[1]))\n"); 
	printf("res = %s\n", res); 
	
	return 1;
}*/
/*	char array[8];
	
	array = {'c', 's', 'p', 'd', 'i', 'u', 'x', 'X'};*/
/*
void printstr(const char *fmt, ...)
{
	
	char **splited;
	int i;
	char *res;
	va_list ap;
	
	 
	splited = ft_split(fmt , '%');
	i = 0;
	splited[1]++; 
	i = 0;
	va_start(ap, fmt);
	printf("kii\n");
	printf("res = %s\n", va_arg(ap, char *)); 
	splited[1] = ft_strjoin(va_arg(ap, char *) , splited[1]);
	printf("kii\n");
	i = 0;
	res = ft_strjoin(splited[0], splited[1]);
	
	ft_putstr_fd(res, 1);
}
void print(const char *fmt, ...)
{
	char *ptr;

	ptr = ft_strchr(fmt, '%');
	
	ptr++;
	
	if (*ptr == 's')
		printstr(fmt);
}

int ft_printf(const char *fmt, ...)
{
	char **splited;
	int i;
	char *res;
	va_list ap;
	char *array;
	
	array = "cspdiuxX";
	if (ft_strchr(fmt, '%'))
		print(fmt);
	else
	{
		
	}
	
	return 1;
}*/
/*int ft_printfhex1(long nb)
{
	long div_mult_16;
	long nbr;

 	div_mult_16 = 1;
	nbr = nb;
	while (nbr / 16 > 0)
	{
		nbr /= 16;
	 div_mult_16 *= 16;
	}
	nbr = 0;
	while  (div_mult_16 >= 1)
	{
		if ((nb / div_mult_16) % 16 > 9)
			ft_putchar_fd(((nb / div_mult_16) % 16) + 87, 1);
		else
			ft_putnbr_fd((nb / div_mult_16) % 16, 1);
		div_mult_16 /= 16;
		nbr++;
	}
	return (nbr + 2);
}*/