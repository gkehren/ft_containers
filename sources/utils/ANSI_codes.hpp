/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ANSI_codes.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkehren <gkehren@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:30:24 by gkehren           #+#    #+#             */
/*   Updated: 2023/01/10 14:51:23 by gkehren          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANSI_CODES_HPP
#define ANSI_CODES_HPP

// Text formatting codes
#define RESET	"\033[0m"
#define BOLD	"\033[1m"
#define UNDER	"\033[4m"
#define INVERT	"\033[7m"

// Text color codes
#define BLACK	"\033[30m"
#define RED		"\033[31m"
#define GREEN	"\033[32m"
#define YELLOW	"\033[33m"
#define BLUE	"\033[34m"
#define MAGENTA	"\033[35m"
#define CYAN	"\033[36m"
#define WHITE	"\033[37m"

// Background color codes
#define BG_BLACK	"\033[40m"
#define BG_RED		"\033[41m"
#define BG_GREEN	"\033[42m"
#define BG_YELLOW	"\033[43m"
#define BG_BLUE		"\033[44m"
#define BG_MAGENTA	"\033[45m"
#define BG_CYAN		"\033[46m"
#define BG_WHITE	"\033[47m"

#define SUCS		"\033[1m\033[32mOK\033[0m"
#define FAIL		"\033[1m\033[31mKO\033[0m"

#endif
