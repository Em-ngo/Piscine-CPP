/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 16:55:05 by engo              #+#    #+#             */
/*   Updated: 2024/05/08 16:55:06 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public :
		WrongCat();
		WrongCat(WrongCat const &src);
		virtual ~WrongCat();

		WrongCat	&operator=(WrongCat const &rhs);

		void		makeSound() const;
} ;

#endif