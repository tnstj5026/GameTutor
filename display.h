#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void best_score()
{
	if(game_1P_easy)
	{
		rankscore = fopen("data\\score easy.txt","rt");
		fscanf(rankscore,"%d",&temp);
		bestscore = temp;
		fclose(rankscore);
	}
	else if(game_1P_hard)
	{
		rankscore = fopen("data\\score hard.txt","rt");
		fscanf(rankscore,"%d",&temp);
		bestscore = temp;
		fclose(rankscore);
	}

	loading_bestscore = false;
}

void game_display_1P()
{
	for(i=0;i<position[0];i++)
	{
		glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
		drawDisplay(20, 20, 15+21*i, 200);
	}

	for(i=1;i<=current_matching[0];i++)
		for(k=1;k<4;k++)
		{
			glBindTexture(GL_TEXTURE_2D,word[Loadednumber[0][i][k]]);
			drawDisplay(12, 20, 92+45*(k-1), 275+25*(i-1));
		}
		
	if(total_score < 10)
	{
		glBindTexture(GL_TEXTURE_2D,word[total_score]);
		drawDisplay(30, 40, 145, 110);
	}
	else if(10 <= total_score && total_score < 100)
	{
		glBindTexture(GL_TEXTURE_2D,word[total_score % 10]);
		drawDisplay(30, 40, 145, 110);

		glBindTexture(GL_TEXTURE_2D,word[total_score / 10]);
		drawDisplay(30, 40, 110, 110);
	}

	rest_time = 120 - gap_1 + up_time - down_time;

	if(rest_time > 0)
	{
		if(rest_time > 120)
		{
			glBindTexture(GL_TEXTURE_2D,bar);
			drawDisplay(168, 5, 66, 666);

			glBindTexture(GL_TEXTURE_2D,plus);
			drawDisplay(35, 35, 227, 637);
		}
		else
		{
			glBindTexture(GL_TEXTURE_2D,bar);
			drawDisplay(168*((float)rest_time/120), 5, 66, 666);
		}

		glBindTexture(GL_TEXTURE_2D,digital[0]);
		drawDisplay(30, 56, 61, 576);

		glBindTexture(GL_TEXTURE_2D,digital[rest_time/60]);
		drawDisplay(30, 56, 101, 576);

		if(time(NULL)%2 == 1)
		{
			glBindTexture(GL_TEXTURE_2D,digital[10]);
			drawDisplay(19, 43, 140, 583);
		}

		glBindTexture(GL_TEXTURE_2D,digital[(rest_time%60)/10]);
		drawDisplay(30, 56, 171, 576);	

		glBindTexture(GL_TEXTURE_2D,digital[rest_time%10]);
		drawDisplay(30, 56, 211, 576);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D,final_select);
		drawDisplay(1055, 369, 70, 175);
				
		glBindTexture(GL_TEXTURE_2D,image_gender[gender[0]]);
		drawDisplay(230, 245, 145, 240);

		for(i=0;i<position[0];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
			drawDisplay(20, 20, 555+21*i, 245);
		}

		if(loading_bestscore == true) best_score();
		if(bestscore >= 100)
		{			
			glBindTexture(GL_TEXTURE_2D,word[bestscore/100]);
			drawDisplay(20, 20, 630, 347);
		}
		if(bestscore >= 10)
		{
			glBindTexture(GL_TEXTURE_2D,word[(bestscore%100)/10]);
			drawDisplay(20, 20, 650, 347);
		}
		glBindTexture(GL_TEXTURE_2D,word[bestscore%10]);
		drawDisplay(20, 20, 670, 347);

		if(total_score < 10)
		{
			glBindTexture(GL_TEXTURE_2D,word[total_score]);
			drawDisplay(30, 40, 970, 288);
		}
		else if(10 <= total_score && total_score < 100)
		{
			glBindTexture(GL_TEXTURE_2D,word[total_score % 10]);
			drawDisplay(30, 40, 935, 288);

			glBindTexture(GL_TEXTURE_2D,word[total_score / 10]);
			drawDisplay(30, 40, 970, 288);
		}

		gaming = false;
			
		initialization();
	}
}

void game_display_2P()
{
	if(poker_select[0] > poker_select[1])
	{
		for(i=0;i<position[0];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
			drawDisplay(9, 15, 17.5+10*i, 222);
		}

		for(i=0;i<position[1];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
			drawDisplay(9, 15, 165.5+10*i, 222);
		}
	}
	else
	{
		for(i=0;i<position[1];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
			drawDisplay(9, 15, 17.5+10*i, 222);
		}

		for(i=0;i<position[0];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
			drawDisplay(9, 15, 165.5+10*i, 222);
		}
	}

	if((turn_player%2) == 0)
	{				
		glBindTexture(GL_TEXTURE_2D,player_show);
		drawDisplay(81, 116, 19, 15);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D,player_show);
		drawDisplay(81, 116, 166, 15);
	}

	for(i=1;i<=current_matching[0];i++)
		for(k=1;k<4;k++)
		{
			glBindTexture(GL_TEXTURE_2D,word[Loadednumber[0][i][k]]);
			drawDisplay(15, 20, 109+43*(k-1), 279+24*(i-1));
		}

	if(score[0] < 10)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[0]]);
		drawDisplay(30, 40, 90, 130);
	}
	else if(10 <= score[0] && score[0] < 100)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[0] % 10]);
		drawDisplay(30, 40, 90, 130);

		glBindTexture(GL_TEXTURE_2D,word[score[0] / 10]);
		drawDisplay(30, 40, 55, 130);
	}

	if(score[1] < 10)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[1]]);
		drawDisplay(30, 40, 238, 130);
	}
	else if(10 <= score[1] && score[1] < 100)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[1] % 10]);
		drawDisplay(30, 40, 238, 130);

		glBindTexture(GL_TEXTURE_2D,word[score[1] / 10]);
		drawDisplay(30, 40, 203, 130);
	}
				
	glBindTexture(GL_TEXTURE_2D,bar);
	drawDisplay(168*(turn_player/39.0), 5, 66, 666);

	if((turn_player/2)+1 >= 10)
	{
		glBindTexture(GL_TEXTURE_2D,round[((turn_player/2)+1)/10]);
		drawDisplay(44, 59, 12, 552);
	}
	glBindTexture(GL_TEXTURE_2D,round[((turn_player/2)+1)%10]);
	drawDisplay(44, 59, 63, 552);

	if(gap_3 >= 16)
	{
		check_time_3 = true;
		initialization();
		turn_player += 1;
	}

	glBindTexture(GL_TEXTURE_2D,digital[0]);
	drawDisplay(23, 45, 178, 558);

	glBindTexture(GL_TEXTURE_2D,digital[0]);
	drawDisplay(23, 45, 206, 558);

	if(time(NULL)%2 == 1)
	{
		glBindTexture(GL_TEXTURE_2D,digital[10]);
		drawDisplay(16, 43, 230, 559);
	}
	
	glBindTexture(GL_TEXTURE_2D,digital[(15-gap_3)/10]);
	drawDisplay(23, 45, 249, 558);

	glBindTexture(GL_TEXTURE_2D,digital[(15-gap_3)%10]);
	drawDisplay(23, 45, 278, 558);
}

void special_display()
{
	if(poker_select[0] > poker_select[1])
	{
		for(i=0;i<position[0];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
			drawDisplay(9, 15, 17.5+10*i, 222);
		}

		for(i=0;i<position[1];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
			drawDisplay(9, 15, 165.5+10*i, 222);
		}
	}
	else
	{
		for(i=0;i<position[1];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[1][i]]);
			drawDisplay(9, 15, 17.5+10*i, 222);
		}

		for(i=0;i<position[0];i++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard[key_number[0][i]]);
			drawDisplay(9, 15, 165.5+10*i, 222);
		}
	}

	if((turn_player%2) == 0)
	{				
		glBindTexture(GL_TEXTURE_2D,player_show);
		drawDisplay(81, 116, 19, 15);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D,player_show);
		drawDisplay(81, 116, 166, 15);
	}

	for(i=1;i<=current_matching[0];i++)
		for(k=1;k<4;k++)
		{
			glBindTexture(GL_TEXTURE_2D,word[Loadednumber[0][i][k]]);
			drawDisplay(15, 20, 33+45*(k-1), 254+24*i);
		}

	for(i=1;i<=current_matching[1];i++)
		for(k=1;k<4;k++)
		{
			glBindTexture(GL_TEXTURE_2D,word[Loadednumber[1][i][k]]);
			drawDisplay(15, 20, 181+45*(k-1), 254+24*i);
		}

	if(score[0] < 10)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[0]]);
		drawDisplay(30, 40, 90, 130);
	}
	else if(10 <= score[0] && score[0] < 100)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[0] % 10]);
		drawDisplay(30, 40, 90, 130);

		glBindTexture(GL_TEXTURE_2D,word[score[0] / 10]);
		drawDisplay(30, 40, 55, 130);
	}

	if(score[1] < 10)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[1]]);
		drawDisplay(30, 40, 238, 130);
	}
	else if(10 <= score[1] && score[1] < 100)
	{
		glBindTexture(GL_TEXTURE_2D,word[score[1] % 10]);
		drawDisplay(30, 40, 238, 130);

		glBindTexture(GL_TEXTURE_2D,word[score[1] / 10]);
		drawDisplay(30, 40, 203, 130);
	}

	glBindTexture(GL_TEXTURE_2D,bar);
	drawDisplay(168*(turn_player/39.0), 5, 66, 666);
		
	if((turn_player/2)+1 >= 10)
	{
		glBindTexture(GL_TEXTURE_2D,round[((turn_player/2)+1)/10]);
		drawDisplay(44, 59, 12, 552);
	}
	glBindTexture(GL_TEXTURE_2D,round[((turn_player/2)+1)%10]);
	drawDisplay(44, 59, 63, 552);

	glBindTexture(GL_TEXTURE_2D,digital[0]);
	drawDisplay(23, 45, 178, 558);

	glBindTexture(GL_TEXTURE_2D,digital[0]);
	drawDisplay(23, 45, 206, 558);

	if(time(NULL)%2 == 1)
	{
		glBindTexture(GL_TEXTURE_2D,digital[10]);
		drawDisplay(16, 43, 230, 559);
	}

	if(select_mode)
	{
		glBindTexture(GL_TEXTURE_2D,digital[(5-gap_2)/10]);
		drawDisplay(23, 45, 249, 558);

		glBindTexture(GL_TEXTURE_2D,digital[(5-gap_2)%10]);
		drawDisplay(23, 45, 278, 558);
	}
	else
	{
		glBindTexture(GL_TEXTURE_2D,digital[(15-gap_2)/10]);
		drawDisplay(23, 45, 249, 558);

		glBindTexture(GL_TEXTURE_2D,digital[(15-gap_2)%10]);
		drawDisplay(23, 45, 278, 558);
	}

	if(turn_player == 40)
	{
		game_2P_special = false;
		winner_loser = true;
			
		initialization();
	}
}