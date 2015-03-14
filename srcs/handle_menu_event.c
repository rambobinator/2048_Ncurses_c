/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_menu_event.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleger <gleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:40:42 by gleger            #+#    #+#             */
/*   Updated: 2015/03/01 20:26:46 by gleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "norme.h"

static void display_header(int y, int x)
{
	int		i;
	char	*header[HEADER_Y];

	header[0] = "                                   ,--,               ";
	header[1] = "      ,----,     ,----..         ,--.'|      ,----,   ";
	header[2] = "    .'   .' \\   /   /   \\     ,--,  | :    .'   .' \\  ";
	header[3] = "  ,----,'    | /   .     : ,---.'|  : '  ,----,'    | ";
	header[4] = "  |    :  .  ;.   /   ;.  \\;   : |  | ;  |    :  .  ; ";
	header[5] = "  ;    |.'  /.   ;   /  ` ;|   | : _' |  ;    |.'  /  ";
	header[6] = "  `----'/  ; ;   |  ; \\ ; |:   : |.'  |  `----'/  ;   ";
	header[7] = "    /  ;  /  |   :  | ; | '|   ' '  ; :    /  ;  /    ";
	header[8] = "   ;  /  /-, .   |  ' ' ' :\\   \\  .'. |   ;  /  /-,   ";
	header[9] = "  /  /  /.`| '   ;  \\; /  | `---`:  | '  /  /  /.`|   ";
	header[10] = "./__;      :  \\   \\  ',  /       '  ; |./__;      :   ";
	header[11] = "|   :    .'    ;   :    /        |  : ;|   :    .'    ";
	header[12] = ";   | .'        \\   \\ .'         '  ,/ ;   | .'       ";
	header[13] = "`---'            `---`           '--'  `---'          ";
	header[14] = NULL;
	i = -1;
	while (header[++i])
		display(header[i], ((y - HEADER_Y) + i), (x - HEADER_X / 2), STRING);
}

static void	display_choices(t_menu *menu, int entry, int y, int x)
{
	t_pt	win_s;
	int		i;

	i = -1;
	getmaxyx(stdscr, win_s.y, win_s.x);
	y = (y * win_s.y) / 100;
	x = (x * win_s.x) / 100;
	while (++i < entry)
	{
		if (win_s.x > HEADER_X && win_s.y > HEADER_Y + entry)
			display_header(y, x);
		if (menu[i].select)
			display("-> ", y + i, x, STRING);
		else
			display("   ", y + i, x, STRING);
		display(menu[i].str, y + i, x + 3, STRING);
	}
}

static void	select_answer(t_menu *menu, int choice, int entry)
{
	int		i;

	i = -1;
	while (++i < entry)
		menu[i].select = 0;
	menu[choice].select = 1;
}

int			handle_keyboard_menu_event(t_env *env, t_menu *menu, int entry)
{
	int		key;
	int		choice;

	choice = 0;
	while (1)
	{
		select_answer(menu, choice, entry);
		display_choices(menu, entry, 60, 45);
		key = getch();
		if (key)
			clear();
		if (key == KEY_END)
			return (END_APP);
		else if (key == '\n')
		{
			if (menu[choice].menu_cmd)
				menu[choice].menu_cmd(env);
			return (menu[choice].ret);
		}
		else if (key == KEY_UP)
			choice = ((choice - 1 >= 0) ? choice - 1 : choice);
		else if (key == KEY_DOWN)
			choice = ((choice + 1 < entry) ? choice + 1 : choice);
	}
	return (CONTINUE_APP);
}
