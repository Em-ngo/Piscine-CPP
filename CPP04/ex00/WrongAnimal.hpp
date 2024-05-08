/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:49:02 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 16:51:16 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {

	public :
		WrongAnimal();
		WrongAnimal(WrongAnimal const &src);
		virtual ~WrongAnimal();

		WrongAnimal	&operator=(WrongAnimal const &rhs);

		std::string const		getType() const;
		void					makeSound() const;

	protected :
		std::string		type;
};

#endif