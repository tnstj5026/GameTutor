#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void name()
{
	if(naming_1P)
	{
		glBindTexture(GL_TEXTURE_2D,back_submit_name[2]);
		drawDisplay(width, height, 0, 0);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D,back_submit_name[gamer]);
		drawDisplay(width, height, 0, 0);
	}

	if(gender[gamer] == 0)
	{
		glBindTexture(GL_TEXTURE_2D,check);
		drawDisplay(19, 19, 473, 333);
	}
	else if(gender[gamer] == 1)
	{
		glBindTexture(GL_TEXTURE_2D,check);
		drawDisplay(19, 19, 601, 333);
	}

	for(i=0;i<position[gamer];i++)
	{
		glBindTexture(GL_TEXTURE_2D,keyboard[key_number[gamer][i]]);
		drawDisplay(10, 15, 495+12*i, 270);
	}

	if(submit||press)
	{
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = end_time - start_time;

		if(position[gamer] == 0)
		{
			glBindTexture(GL_TEXTURE_2D,notice[0]);
			drawDisplay(414, 244, 393, 190);
		}
		else if(position[gamer] == 18)
		{
			glBindTexture(GL_TEXTURE_2D,notice[2]);
			drawDisplay(414, 244, 393, 190);
		}
        else if(gender[gamer] == 2)
		{
			glBindTexture(GL_TEXTURE_2D,notice[1]);
			drawDisplay(414, 244, 393, 190);
		}			

		if(gap < 3)
		{
			submit_control = false;
		}
		else
		{
			submit_control = true;
			check_time = true;
			submit = false;
			press = false;
		}
	}
}

void order()
{
	if(gamer == 0)
	{			
		glBindTexture(GL_TEXTURE_2D,poker[12]);
		drawDisplay(173, 281, 283, 46);	

		glBindTexture(GL_TEXTURE_2D,poker[12]);
		drawDisplay(173, 281, 370, 46);		

		if(gap < 3)
		{
			order_control = false;

			glBindTexture(GL_TEXTURE_2D,notice[3]);
			drawDisplay(414, 244, 393, 190);

			for(i=0;i<position[0];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard_black[key_number[0][i]]);
				drawDisplay(10, 15, 510+12*i, 310);
			}
		}
		else
		{
			order_control = true;
		}
	}
	else if(gamer == 1)
	{
		glBindTexture(GL_TEXTURE_2D,poker[12]);
		drawDisplay(173, 281, 345, 46);

		glBindTexture(GL_TEXTURE_2D,poker[poker_select[0]]);
		drawDisplay(168, 276, 432, 368);

		if(gap < 3)
		{
			order_control = false;

			glBindTexture(GL_TEXTURE_2D,notice[3]);
			drawDisplay(414, 244, 393, 190);

			for(i=0;i<position[1];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard_black[key_number[1][i]]);
				drawDisplay(10, 15, 510+12*i, 310);
			}
		}
		else
		{
			order_control = true;
		}
	}
	else
	{
		if(check_time_1 == true) First_time();
		end_time_1 = time(NULL);
		gap_1 = end_time_1 - start_time_1;

		glBindTexture(GL_TEXTURE_2D,poker[max(poker_select[0],poker_select[1])]);
		drawDisplay(225, 374, 641, 269);

		glBindTexture(GL_TEXTURE_2D,poker[min(poker_select[0],poker_select[1])]);
		drawDisplay(225, 374, 908, 269);

		if(poker_select[0] > poker_select[1])
		{
			for(i=0;i<position[0];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
				drawDisplay(20, 20, 641+21*i, 650);
			}

			for(i=0;i<position[1];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
				drawDisplay(20, 20, 908+21*i, 650);
			}
		}
		else
		{
			for(i=0;i<position[1];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
				drawDisplay(20, 20, 641+21*i, 650);
			}

			for(i=0;i<position[0];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
				drawDisplay(20, 20, 908+21*i, 650);
			}
		}

		if(gap_1 > 5)
		{
			player_order = false;
			screen_level_2P = true;

			gamer = 0;
			check_time_1 = true;
			check_time = true;
			order_control = false;
		}
	}	
}