/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarcez- < dgarcez-@student.42lisboa.com > +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:54:25 by dgarcez-          #+#    #+#             */
/*   Updated: 2026/01/22 19:08:05 by dgarcez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

class Fixed
{
	private:
		int	fixed_value;
		static const int	bits;
	public:
		Fixed();
		Fixed(const Fixed &obj);
		Fixed &operator=(const Fixed &obj);
		~Fixed();
};