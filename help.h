#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void help_bundle()
{
	if(temp == 0)
	{
		if(loading_help_1P == true) Loadimage_help_1P();
	}
	else
	{
		if(loading_help_2P == true) Loadimage_help_2P();
	}

	if(current == 1)
	{			
		glBindTexture(GL_TEXTURE_2D,help[temp][0][0]);
		drawDisplay(width, height, 0, 0);
	}		
	else if(current == 2)
	{
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 20;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][1][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][1][1]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=8 && gap <=11)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][1][2]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=12 && gap <=15)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][1][3]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=16 && gap <=19)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][1][4]);
			drawDisplay(width, height, 0, 0);
		}
	}		
	else if(current == 3)
	{			
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 16;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][2][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][2][1]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=8 && gap <=11)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][2][2]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=12 && gap <=15)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][2][3]);
			drawDisplay(width, height, 0, 0);
		}
	}		
	else if(current == 4)
	{			
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 16;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][3][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][3][1]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=8 && gap <=11)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][3][2]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=12 && gap <=15)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][3][3]);
			drawDisplay(width, height, 0, 0);
		}
	}		
	else if(current == 5)
	{			
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 8;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][4][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][4][1]);
			drawDisplay(width, height, 0, 0);
		}
	}
	else if(current == 6)
	{			
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 8;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][5][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[temp][5][1]);
			drawDisplay(width, height, 0, 0);
		}
	}
}

void help_special()
{
	if(loading_help_special == true) Loadimage_help_special();
		
	if(current == 1)
	{
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 12;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][0][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][0][1]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=8 && gap <=11)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][0][2]);
			drawDisplay(width, height, 0, 0);
		}
	}		
	else if(current == 2)
	{
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 12;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][1][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][1][1]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=8 && gap <=11)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][1][2]);
			drawDisplay(width, height, 0, 0);
		}
	}		
	else if(current == 3)
	{			
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 8;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][2][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][2][1]);
			drawDisplay(width, height, 0, 0);
		}
	}		
	else if(current == 4)
	{			
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = (end_time - start_time) % 8;

		if(gap>=0 && gap <=3)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][3][0]);
			drawDisplay(width, height, 0, 0);
		}
		else if(gap>=4 && gap <=7)
		{
			glBindTexture(GL_TEXTURE_2D,help[2][3][1]);
			drawDisplay(width, height, 0, 0);
		}
	}
}