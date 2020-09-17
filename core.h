#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void game_core()
{	
	if(game_1P_hard||game_2P_hard)
		selectingcard_1P_36();
	else
		selectingcard_1P_27();

	glEnable(GL_ALPHA_TEST); // Alpha값을 사용할 수 있게 설정 변경
	glAlphaFunc(GL_GREATER,0.0); // Alpha로 지정한 값 전달

	if(game_1P_hard||game_2P_hard)
	{
		for(i=0;i<3;i++)
			for(k=0;k<3;k++)
			{
				if(((current_matching[player]+(3*i)+k+1)%2) == 0)
				{					
					glBindTexture(GL_TEXTURE_2D,select_card[player][(3*i)+k+1]);
					drawDisplay(124, 132, 442+212*i, 124+170*k);
				}
				else
				{
					glBindTexture(GL_TEXTURE_2D,hiddencard_1P);
					drawDisplay(124, 132, 442+212*i, 124+170*k);
				}
			}
	}
	else
	{
		for(i=0;i<3;i++)
			for(k=0;k<3;k++)
			{				
				glBindTexture(GL_TEXTURE_2D,select_card[player][3*i+k+1]);
				drawDisplay(124, 132, 442+212*i, 124+170*k);
			}
	}

	total_calculation();

	if(Load_number[player] != 3)
	{
		selecting_picture();

		if(game_1P_hard||game_2P_hard)
		{
			for(g=1;g<=Load_number[player];g++)
			{
				if((current_matching[player]+(3*x[player][g])+y[player][g]+1)%2 == 0)
				{
					glBindTexture(GL_TEXTURE_2D,card_edge[player][choose[player][g]]);
					drawDisplay(124, 132, x_1[player][g], y_1[player][g]);
				}
				else
				{
					glBindTexture(GL_TEXTURE_2D,hiddencard_edge_1P);
					drawDisplay(124, 132, x_1[player][g], y_1[player][g]);
				}
			}
		}
		else
		{
			for(g=1;g<=Load_number[player];g++)
			{
				glBindTexture(GL_TEXTURE_2D,card_edge[player][choose[player][g]]);
				drawDisplay(124, 132, x_1[player][g], y_1[player][g]);
			}
		}
	}
	else
	{
		temp = matching_check(choose[player][1],choose[player][2],choose[player][3]);

		if(temp == 1)
		{
			arrange_and_coordinate();

			for(u=0;u<=current_matching[player];u++)
			{
				if((Loadednumber[player][u][1] == w[player][1])&&(Loadednumber[player][u][2] == w[player][2])&&(Loadednumber[player][u][3] == w[player][3]))
				{
					if(game_1P_hard||game_2P_hard)
					{
						for(i=1;i<=3;i++)
						{
							if((w[player][i]+current_matching[player])%2 == 1)
							{
								if(check_time_2 == true) Second_time();
								end_time_2 = time(NULL);
								gap_2 = end_time_2 - start_time_2;
						
								if(gap_2 < 3)
								{
									for(k=1;k<4;k++)
									{
										glBindTexture(GL_TEXTURE_2D,select_card[player][w[player][k]]);
										drawDisplay(124, 132, x_1[player][k], y_1[player][k]);
									}

									control = false;
									
									check_time_3 = true;
									break;
								}
								else
								{
									if(score[turn_player%2] != 0)
										score[turn_player%2] -= 1;
									down_time += 10;
	
									initialization();
									
									control = true;
									check_time_2 = true;
								
									turn_player += 1;
									check_time_3 = true;
									break;
								}
							}					
							else if(i == 3)
							{
								if(score[turn_player%2] != 0)
									score[turn_player%2] -= 1;
								down_time += 10;
	
								initialization();

								turn_player += 1;
								check_time_3 = true;
								break;
							}
						}
						break;
					}
					else
					{
						if(score[turn_player%2] != 0)
							score[turn_player%2] -= 1;
						down_time += 10;

						initialization();
						
						turn_player += 1;
						check_time_3 = true;
						break;
					}
				}
				else if(u == current_matching[player])
				{
					score[turn_player%2] += 1;
					up_time += 10;

					for(a=1;a<4;a++)
						Loadednumber[player][current_matching[player]+1][a] = w[player][a];
					current_matching[player] += 1;
						
					initialization();
					
					turn_player += 1;
					check_time_3 = true;
					break;
				}
			}
		}		
		else
		{
			if(game_1P_hard||game_2P_hard)
			{
				for(s=1;s<4;s++)
					w[player][s] = 3*x[player][s]+y[player][s]+1;

				for(i=1;i<=3;i++)
				{
					if((w[player][i]+current_matching[player])%2 == 1)
					{
						if(check_time_2 == true) Second_time();
						end_time_2 = time(NULL);
						gap_2 = end_time_2 - start_time_2;
						
						if(gap_2 < 3)
						{
							control = false;

							for(k=1;k<4;k++)
							{
								glBindTexture(GL_TEXTURE_2D,select_card[player][w[player][k]]);
								drawDisplay(124, 132, x_1[player][k], y_1[player][k]);
							}

							check_time_3 = true;
							break;
						}
						else
						{
							if(score[turn_player%2] != 0)
								score[turn_player%2] -= 1;
							down_time += 10;
	
							initialization();
								
							control = true;
							check_time_2 = true;
						
							turn_player += 1;
							check_time_3 = true;
							break;
						}
					}					
					else if(i == 3)
					{
						if(score[turn_player%2] != 0)
							score[turn_player%2] -= 1;
						down_time += 10;
	
						initialization();
								
						control = true;
						check_time_1 = true;
					
						turn_player += 1;
						check_time_3 = true;
						break;
					}
				}
			}
			else
			{
				if(score[turn_player%2] != 0)
					score[turn_player%2] -= 1;
				down_time += 10;
							
				initialization();
				check_time_3 = true;
				turn_player += 1;
			}
		}
	}

	if(perfect)
	{
		if(total_matching[player] == current_matching[player])
		{
			score[turn_player%2] += 3;
			up_time += 30;
				
			for(i=0;i<=current_matching[player];i++)
				for(k=0;k<4;k++)
					Loadednumber[player][i][k] = 0;
			current_matching[player] = 0;

			initialization();
									
			loading_card[player] = 1;
			total_checking = true;
			perfect = false;

			total_matching[0] = total_matching[1] = 0;
			turn_player += 1;
			check_time_3 = true;

			PlaySound(TEXT("sound\\perfect.wav"),NULL,SND_ASYNC);
		}
		else
		{
			if(score[turn_player%2] >= 3)
				score[turn_player%2] -= 3;
			else
				score[turn_player%2] = 0;
			down_time += 30;

			initialization();

			turn_player += 1;
			check_time_3 = true;

			perfect = false;

			PlaySound(TEXT("sound\\click3.wav"),NULL,SND_ASYNC);
		}
	}

	total_score = score[0] + score[1];
}

void special_core()
{
	if(gap_2 <= 15)
	{
		if((turn_player%2)+player == 1)
		{
			if(turn_player%2 == 0)
			{
				for(i=0;i<3;i++)
					for(k=0;k<3;k++)
					{								
						glBindTexture(GL_TEXTURE_2D,hiddencard_1P);
						drawDisplay(124, 132, 442+212*i, 124+170*k);
					}
			}
			else
			{
				for(i=0;i<3;i++)
					for(k=0;k<3;k++)
					{								
						glBindTexture(GL_TEXTURE_2D,hiddencard_2P);
						drawDisplay(124, 132, 442+212*i, 124+170*k);
					}
			}
		}
		else
		{
			for(i=0;i<3;i++)
				for(k=0;k<3;k++)
				{
					glBindTexture(GL_TEXTURE_2D,select_card[player][3*i+k+1]);
					drawDisplay(124, 132, 442+212*i, 124+170*k);
				}
		}
		
		if(Load_number[player] != 3)
		{
			selecting_picture();
						
			if((turn_player%2)+player == 1)
			{
				if(turn_player%2 == 0)
				{
					for(g=1;g<=Load_number[player];g++)
					{								
						glBindTexture(GL_TEXTURE_2D,hiddencard_edge_1P);
						drawDisplay(124, 132, x_1[player][g], y_1[player][g]);
					}
				}
				else
				{
					for(g=1;g<=Load_number[player];g++)
					{								
						glBindTexture(GL_TEXTURE_2D,hiddencard_edge_2P);
						drawDisplay(124, 132, x_1[player][g], y_1[player][g]);
					}
				}
			}
			else
			{
				for(g=1;g<=Load_number[player];g++)
				{
					glBindTexture(GL_TEXTURE_2D,card_edge[player][choose[player][g]]);
					drawDisplay(124, 132, x_1[player][g], y_1[player][g]);
				}
			}
		}
		else
		{
			temp = matching_check(choose[player][1],choose[player][2],choose[player][3]);

			if(temp == 1)
			{
				arrange_and_coordinate();

				for(u=0;u<=current_matching[player];u++)
				{
					if((Loadednumber[player][u][1] == w[player][1])&&(Loadednumber[player][u][2] == w[player][2])&&(Loadednumber[player][u][3] == w[player][3]))
					{
						if(turn_player%2 == player)
						{
							if(score[turn_player%2] >= 1)
								score[turn_player%2] -= 1;
							else
								score[turn_player%2] = 0;
						}
						else
						{
							if(score[turn_player%2] >= 2)
								score[turn_player%2] -= 2;
							else
								score[turn_player%2] = 0;
						}

						initialization();

						mode_choice = 0;
						turn_player += 1;
						check_time_2 = true;
						select_mode = true;
									
						break;
					}
					else if(u == current_matching[player])
					{
						if(turn_player%2 == player)
							score[turn_player%2] += 1;
						else
							score[turn_player%2] += 2;

						for(a=1;a<4;a++)
							Loadednumber[player][current_matching[player]+1][a] = w[player][a];						
						current_matching[player] += 1;
									
						initialization();
						
						mode_choice = 0;
						turn_player += 1;
						check_time_2 = true;
						select_mode = true;
									
						break;
					}
				}
			}		
			else
			{
				if(turn_player%2 == player)
				{
					if(score[turn_player%2] >= 1)
						score[turn_player%2] -= 1;
					else
						score[turn_player%2] = 0;
				}
				else
				{
					if(score[turn_player%2] >= 2)
						score[turn_player%2] -= 2;
					else
						score[turn_player%2] = 0;
				}

				initialization();

				mode_choice = 0;
				turn_player += 1;
				check_time_2 = true;
				select_mode = true;
			}
		}

		if(perfect)
		{
			if(total_matching[player] == current_matching[player])
			{
				if(turn_player%2 == player)
					score[turn_player%2] += 3;
				else
					score[turn_player%2] += 6;
				
				for(i=0;i<=current_matching[player];i++)
					for(k=0;k<4;k++)
						Loadednumber[player][i][k] = 0;
				current_matching[player] = 0;

				initialization();
							
				total_matching[player] = 0;
				mode_choice = 0;
				turn_player += 1;
				check_time_2 = true;
				select_mode = true;
				loading_card[player] = 1;
				total_checking = true;

				perfect = false;

				PlaySound(TEXT("sound\\perfect.wav"),NULL,SND_ASYNC);
			}
			else
			{
				if(turn_player%2 == player)
				{
					if(score[turn_player%2] >= 3)
						score[turn_player%2] -= 3;
					else
						score[turn_player%2] = 0;
				}
				else
				{
					if(score[turn_player%2] >= 6)
						score[turn_player%2] -= 6;
					else
						score[turn_player%2] = 0;
				}

				initialization();

				mode_choice = 0;
				turn_player += 1;
				check_time_2 = true;
				select_mode = true;

				perfect = false;

				PlaySound(TEXT("sound\\click3.wav"),NULL,SND_ASYNC);
			}
		}	
	}
	else
	{
		mode_choice = 0;
		turn_player += 1;
		check_time_2 = true;
		select_mode = true;
					 
		initialization();
	}
}