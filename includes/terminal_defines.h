/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_defines.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldevelle <ldevelle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:13:48 by ldevelle          #+#    #+#             */
/*   Updated: 2019/05/07 11:23:53 by ldevelle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_DEFINES_H
# define TERMINAL_DEFINES_H

# define _RED			"\x1b[31m"
# define _GREEN			"\x1b[32m"
# define _BLUE			"\x1b[34m"
# define _YELLOW		"\x1b[33m"
# define _MAGENTA		"\x1b[35m"
# define _CYAN			"\x1b[36m"
# define _RESET			"\x1b[0m"
# define _BROWN			"\x1b[38;2;238;205;163m"
# define _PINK			"\x1b[38;2;239;100;100m"
# define _PURPLE		"\x1b[38;2;101;78;163m"
# define _ORANGE		"\x1b[38;2;155;75;43m"
# define _TURQUOISE		"\x1b[38;2;68;140;121m"
# define CU_RESET		"\033[0;0H"
# define CU_LOAD		"\033[u"
# define CU_SAVE		"\033[s"
# define CU_SCREEN		"\033[2J"

# define _C_RED			write(1, _RED, 5)
# define _C_GREEN		write(1, _GREEN, 5)
# define _C_BLUE		write(1, _BLUE, 5)
# define _C_YELLOW		write(1, _YELLOW, 5)
# define _C_MAGENTA		write(1, _MAGENTA, 5)
# define _C_CYAN		write(1, _CYAN, 5)
# define _C_RESET		write(1, _RESET, 5)
# define _C_BROWN		write(1, _BROWN, 19)
# define _C_PINK		write(1, _PINK, 19)
# define _C_PURPLE		write(1, _PURPLE, 18)
# define _C_ORANGE		write(1, _ORANGE, 17)
# define _C_TURQUOISE	write(1, _TURQUOISE, 18)
# define _CURSOR_RESET	write(1, CU_RESET, 6)
# define _CURSOR_LOAD	write(1, CU_LOAD, 3)
# define _CURSOR_SAVE	write(1, CU_SAVE, 3)
# define _CLEAR_SCREEN	write(1, CU_SCREEN, 4)

# define C_RED			_C_RED;
# define C_GREEN		_C_GREEN;
# define C_BLUE			_C_BLUE;
# define C_YELLOW		_C_YELLOW;
# define C_MAGENTA		_C_MAGENTA;
# define C_CYAN			_C_CYAN;
# define C_RESET		_C_RESET;
# define C_BROWN		_C_BROWN;
# define C_PINK			_C_PINK;
# define C_PURPLE		_C_PURPLE;
# define C_ORANGE		_C_ORANGE;
# define C_TURQUOISE	_C_TURQUOISE;
# define CURSOR_RESET	_CURSOR_RESET;
# define CURSOR_LOAD	_CURSOR_LOAD;
# define CURSOR_SAVE	_CURSOR_SAVE;
# define CLEAR_SCREEN	_CLEAR_SCREEN;

#endif
