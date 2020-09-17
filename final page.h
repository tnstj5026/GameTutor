#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void winner_display()
{
	if(score[0] > score[1])
	{
		glBindTexture(GL_TEXTURE_2D,back_final[1]);
		drawDisplay(width, height, 0, 0);

		if(poker_select[0] > poker_select[1])
		{
			for(i=0;i<position[0];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
				drawDisplay(30, 30, 420+30*i, 625);
			}
		}
		else
		{
			for(i=0;i<position[1];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
				drawDisplay(30, 30, 420+30*i, 625);
			}
		}
	}
	else if(score[0] < score[1])
	{
		glBindTexture(GL_TEXTURE_2D,back_final[2]);
		drawDisplay(width, height, 0, 0);

		if(poker_select[0] > poker_select[1])
		{
			for(i=0;i<position[1];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
				drawDisplay(30, 30, 420+30*i, 625);
			}
		}
		else
		{
			for(i=0;i<position[0];i++)
			{
				glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
				drawDisplay(30, 30, 420+30*i, 625);
			}
		}
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D,back_final[0]);
		drawDisplay(width, height, 0, 0);
	}
}