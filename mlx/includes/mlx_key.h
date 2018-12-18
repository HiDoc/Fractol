/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_key.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 19:43:54 by wescande          #+#    #+#             */
/*   Updated: 2018/07/26 20:49:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_KEY_H
# define MLX_KEY_H

# ifdef __APPLE__ 
/*
** Working on QWERTY
*/
#  define K_ESC				0x35
/*
** line 1
*/
#  define K_TILDE			0x32
#  define K_1				0x12
#  define K_2				0x13
#  define K_3				0x14
#  define K_4				0x15
#  define K_5				0x17
#  define K_6				0x16
#  define K_7				0x1A
#  define K_8				0x1C
#  define K_9				0x19
#  define K_0				0x1D
#  define K_SUB				0x1B
#  define K_ADD				0x18
#  define K_DELETE			0x33
/*
** line 2
*/
#  define K_TAB				0x30
#  define K_Q				0xC
#  define K_W				0xD
#  define K_E				0xE
#  define K_R				0xF
#  define K_T				0x11
#  define K_Y				0x10
#  define K_U				0x20
#  define K_I				0x22
#  define K_O				0x1F
#  define K_P				0x23
#  define K_BRACKET_OPEN	0x21
#  define K_BRACKET_CLOSE	0x1E
#  define K_PIPE			0x2A
/*
** line 3
*/
#  define K_A				0x0
#  define K_S				0x1
#  define K_D				0x2
#  define K_F				0x3
#  define K_G				0x5
#  define K_H				0x4
#  define K_J				0x26
#  define K_K				0x28
#  define K_L				0x25
#  define K_DOUBLE_DOTS		0x29
#  define K_QUOTE			0x27
#  define K_RETURN			0x24
/*
** line 4
*/
#  define K_SHIFT_LEFT		0x101
#  define K_Z				0x6
#  define K_X				0x7
#  define K_C				0x8
#  define K_V				0x9
#  define K_B				0xB
#  define K_N				0x2D
#  define K_M				0x2E
#  define K_INFERIOR		0x2B
#  define K_SUPERIOR		0x2F
#  define K_QUESTION_MARK	0x2C
#  define K_SHIFT_RIGHT		0x102
/*
** line 5
*/
#  define K_CTRL_LEFT		0x100
#  define K_ALT_LEFT		0x105
#  define K_CMD_LEFT		0x103
#  define K_SPACE			0x31
#  define K_CMD_RIGHT		0x104
#  define K_ALT_RIGHT		0x106
#  define K_CTRL_RIGHT		0x10D
/*
** line 1 | col 2 && line 2 | col 2
*/
#  define K_FN				0x117
#  define K_HOME			0x73
#  define K_PAGE_UP			0x74
#  define K_SUPPR			0x75
#  define K_END				0x77
#  define K_PAGE_DOWN		0x79
/*
** direction pad
*/
#  define K_UP				0x7E
#  define K_LEFT			0x7B
#  define K_DOWN			0x7D
#  define K_RIGHT			0x7C
/*
** numpad
*/
#  define K_CLEAR			0x47
#  define K_NUMPAD_EQUAL	0x51
#  define K_NUMPAD_DIV		0x4B
#  define K_NUMPAD_MUL		0x43
#  define K_NUMPAD_7		0x59
#  define K_NUMPAD_8		0x5B
#  define K_NUMPAD_9		0x5C
#  define K_NUMPAD_SUB		0x4E
#  define K_NUMPAD_4		0x56
#  define K_NUMPAD_5		0x57
#  define K_NUMPAD_6		0x58
#  define K_NUMPAD_ADD		0x45
#  define K_NUMPAD_1		0x53
#  define K_NUMPAD_2		0x54
#  define K_NUMPAD_3		0x55
#  define K_NUMPAD_0		0x52
#  define K_NUMPAD_DOT		0x41
#  define K_NUMPAD_ENTER	0x4C

#  define M_BUTTON_LEFT		1
#  define M_BUTTON_RIGHT	2
#  define M_BUTTON_MIDDLE	3
#  define M_SCROLL_UP		4
#  define M_SCROLL_DOWN		5

# endif

# ifdef __linux__

/*
** Working on QWERTY
*/
#  define K_ESC				0xff1b
/*
** line 1
*/
#  define K_TILDE			0x60
#  define K_1				0x31
#  define K_2				0x32
#  define K_3				0x33
#  define K_4				0x34
#  define K_5				0x35
#  define K_6				0x36
#  define K_7				0x37
#  define K_8				0x38
#  define K_9				0x39
#  define K_0				0x30
#  define K_SUB				0x2d
#  define K_ADD				0x3d
#  define K_DELETE			0xff08
/*
** line 2
*/
#  define K_TAB				0xff09
#  define K_Q				0x71
#  define K_W				0x77
#  define K_E				0x65
#  define K_R				0x72
#  define K_T				0x74
#  define K_Y				0x79
#  define K_U				0x75
#  define K_I				0x69
#  define K_O				0x6f
#  define K_P				0x70
#  define K_BRACKET_OPEN	0x5b
#  define K_BRACKET_CLOSE	0x5d
#  define K_PIPE			0x5c
/*
** line 3
*/
#  define K_A				0x61
#  define K_S				0x73
#  define K_D				0x64
#  define K_F				0x66
#  define K_G				0x67
#  define K_H				0x68
#  define K_J				0x6a
#  define K_K				0x6b
#  define K_L				0x6c
#  define K_DOUBLE_DOTS		0x3b
#  define K_QUOTE			0x27
#  define K_RETURN			0xff0d
/*
** line 4
*/
#  define K_SHIFT_LEFT		0xffe1
#  define K_Z				0x7a
#  define K_X				0x78
#  define K_C				0x63
#  define K_V				0x76
#  define K_B				0x62
#  define K_N				0x6e
#  define K_M				0x6d
#  define K_INFERIOR		0x2c
#  define K_SUPERIOR		0x2e
#  define K_QUESTION_MARK	0x2f
#  define K_SHIFT_RIGHT		0xffe2
/*
** line 5
*/
#  define K_CTRL_LEFT		0xffe3
#  define K_ALT_LEFT		0xffe9
#  define K_CMD_LEFT		0xff67
#  define K_SPACE			0x20
#  define K_CMD_RIGHT		0xff67
#  define K_ALT_RIGHT		0xff20
#  define K_CTRL_RIGHT		0xffe4
/*
** line 1 | col 2 && line 2 | col 2
*/
/* #  define K_FN				0x0 */
#  define K_HOME			0xff50
#  define K_PAGE_UP			0xff55
#  define K_SUPPR			0xffff
#  define K_END				0xff57
#  define K_PAGE_DOWN		0xff56
/*
** direction pad
*/
#  define K_UP				0xff52
#  define K_LEFT			0xff51
#  define K_DOWN			0xff54
#  define K_RIGHT			0xff53
/*
** numpad
*/
/* #  define K_CLEAR			0x0 */
/* #  define K_NUMPAD_EQUAL	0x0 */
#  define K_NUMPAD_DIV		0xffaf
#  define K_NUMPAD_MUL		0xffaa
#  define K_NUMPAD_7		0xff95
#  define K_NUMPAD_8		0xff97
#  define K_NUMPAD_9		0xff9a
#  define K_NUMPAD_SUB		0xffad
#  define K_NUMPAD_4		0xff96
#  define K_NUMPAD_5		0xff9d
#  define K_NUMPAD_6		0xff98
#  define K_NUMPAD_ADD		0xffab
#  define K_NUMPAD_1		0xff9c
#  define K_NUMPAD_2		0xff99
#  define K_NUMPAD_3		0xff9b
#  define K_NUMPAD_0		0xff9e
#  define K_NUMPAD_DOT		0xff9f
#  define K_NUMPAD_ENTER	0xff8d

#  define M_BUTTON_LEFT		1
#  define M_BUTTON_RIGHT	2
#  define M_BUTTON_MIDDLE	3
#  define M_SCROLL_UP		4
#  define M_SCROLL_DOWN		5

# endif
#endif
