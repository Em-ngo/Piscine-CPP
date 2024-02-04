#include <iostream>
#include <cctype>

int	main(int ac, char **av) {
	
	int i = 1;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	while (i < ac)
	{
		char	*str = av[i];
		while (*str) 
		{
			*str = std::toupper(*str);
			str++;
		}	
		std::cout << av[i] << std::flush;
		++i;
	}
	return (0);
}