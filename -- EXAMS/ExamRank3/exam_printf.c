/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:45:44 by brisly            #+#    #+#             */
/*   Updated: 2023/02/27 22:20:18 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>

int	ft_base16(unsigned long nb)
{
	int	count;
	char	*alpha = "0123456789ABCDEF";

	count = 0;
	if (nb > 15)
	{
		count += ft_base16(nb / 16);
		count += ft_base16(nb % 16);
	}
	else
		count += write(1, &alpha[nb], 1);
	if (count < 0)
		return (-1);
	return (count);
}


int	ft_putstr(char *str)
{
	int i = 0;

	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	int	count;

	count = 0;
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		count = 11;
	}
	else if (nb < 0)
	{
		count += write(1,"-", 1);
		count += ft_putnbr(-nb);
	}
	else if (nb > 9)
		count += ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	count += write(1, &nb, 1);
	if (count < 0)
		return (-1);
	return (count);
}

int	ft_printf(char *str, ...)
{
	int	i = 0;
	int count = 0;
	va_list args;

	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 's')
				count += ft_putstr(va_arg(args, char *));
			else if (str[i] == 'd')
				count += ft_putnbr(va_arg(args, int));
			else if (str[i] == 'x')
				count += ft_base16(va_arg(args, int));
		}
		else
			count += write (1, &str[i], 1);
		i++;
	}
	va_end(args);
	write(1, "\n", 1);
	if (count < 0)
		return (-1);
	return (count);
}

int main ()
{
	ft_printf("hello my name is %s and i'm %d", "laura", -23);
	ft_printf("%d", ft_printf("hello my name is %s and i'm %d", "laura", -23));
}

// OR SECOND RIGHT RESPONSE (shorter)

/*
void	put_string(char *string, int *length)
{
	if (!string)
		string = "(null)";
	while (*string)
		*length += write(1, string++, 1);
}

void	put_digit(long long int number, int base, int *length)
{
	char	*hexadecimal = "0123456789abcdef";

	if (number < 0)
	{
		number *= -1;
		*length += write(1, "-", 1);
	}
	if (number >= base)
		put_digit((number / base), base, length);
	*length += write(1, &hexadecimal[number % base], 1);
}

int	ft_printf(const char *format, ...)
{
	int length = 0;
	
	va_list	pointer;
	va_start(pointer, format);
	
	while (*format)
	{
		if ((*format == '%') && *(format + 1))
		{
			format++;
			if (*format == 's')
				put_string(va_arg(pointer, char *), &length);
			else if (*format == 'd')
				put_digit((long long int)va_arg(pointer, int), 10, &length);
			else if (*format == 'x')
				put_digit((long long int)va_arg(pointer, unsigned int), 16, &length);
		}
		else
			length += write(1, format, 1);
		format++;
	}
	return (va_end(pointer), length);
}
*/
