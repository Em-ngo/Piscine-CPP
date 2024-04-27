/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engo <engo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:25:38 by engo              #+#    #+#             */
/*   Updated: 2024/04/27 17:26:48 by engo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

std::string replaceAll(const std::string &str, const std::string &s1, const std::string &s2) {
    
    std::string result;
    std::string::size_type pos = 0;
    std::string::size_type prev = 0;
    
    while ((pos = str.find(s1, pos)) != std::string::npos) {
        
        result.append(str.substr(prev, pos - prev));
        result.append(s2);
        pos += s1.size();
        prev = pos;
    }
    result.append(str.substr(prev));
    return (result);
}
