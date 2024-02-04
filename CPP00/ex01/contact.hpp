/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 12:01:11 by engo              #+#    #+#             */
/*   Updated: 2024/02/03 17:08:11 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H
# include <sstream>
# include <iostream>
# include <string>
# include <iostream>

class Contact  {

private:

	std::string FirstName;
	std::string LastName;
	std::string NickName;
	std::string NumberPhone;
	std::string DarkestSecret;
	
public:
	
	Contact();
	~Contact();
	void setFirstName(std::string name);
    void setLastName(std::string name);
    void setNickname(std::string nick);
    void setPhoneNumber(std::string number);
    void setDarkestSecret(std::string secret);

    std::string getFirstName();
    std::string getLastName();
    std::string getNickname();
    std::string getPhoneNumber();
    std::string getDarkestSecret();
	
};


#endif