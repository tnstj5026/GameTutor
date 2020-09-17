#pragma once // 라이브러리를 중복해서 포함하지 않도록 설정

#include <stdio.h>
#include "sound.h"
#include <time.h>
#include <glut.h> // 이미지 처리와 관련된 함수들의 라이브러리
#include <Windows.h>

bool screen_loading = true;
bool screen_main = false;
bool screen_level_1P = false;
bool screen_level_2P = false;
bool screen_help_1P = false;
bool screen_help_2P = false;
bool screen_help_special = false;
bool screen_ranking_easy = false;
bool screen_ranking_hard = false;
bool game_1P_easy = false;
bool game_1P_hard = false;
bool game_2P_easy = false;
bool game_2P_hard = false;
bool game_2P_special = false;
bool loading_main = true;
bool loading_help_1P = true;
bool loading_help_2P = true;
bool loading_help_special = true;
bool loading_keyboard = true;
bool loading_order = true;
bool loading_game = true;
bool loading_game_1P = true;
bool loading_game_2P = true;
bool loading_rank = true;
bool loading_final = true;
bool loading_notice = true;
bool loading_bestscore = true;
bool load_data_easy = true;
bool load_data_hard = true;
bool check_time = true;
bool check_time_1 = true;
bool check_time_2 = true;
bool check_time_3 = true;
bool perfect = false;
bool select_mode = true;
bool total_checking = true;
bool waiting = false;
bool control = true;
bool gaming = true;
bool winner_loser = false;
bool naming_1P = false;
bool naming_2P = false;
bool player_order = false;
bool submit = false;
bool submit_control = true;
bool press = false;
bool order_control = false;
bool one_sound = true;
bool one_speak = true;

int current = 1;
int x_1[2][4],y_1[2][4];
int player = 0;
int mode_choice = 0;
int loading_card[2] = {1,1};
int rest_time, up_time, down_time;
int start_time, start_time_1, start_time_2, start_time_3, end_time, end_time_1, end_time_2, end_time_3, gap, gap_1, gap_2, gap_3;
int random_number[2][10];
int total_matching[2] = {0};
int i,j,k,m,n,p,a,g,s,u,r;
int Load_number[2] = {0};
int choose[2][4] = {0};
int temp_choose;
int x[2][4] = {0},y[2][4] = {0},w[2][4] = {0};
int temp;
int Loadednumber[2][10][4];
int current_matching[2] = {0};
int score[2] = {0};
int turn_player = 0;
int sand = 0;
int total_score = 0;
int rotate = 1;
int key_number[2][18];
int gamer = 0;
int position[2] = {0};
int poker_select[2];
int gender[2] = {2,2};
int rank_name[8][18], rank_score[8], rank_pos[8];
int bestscore;
int convert = 0;

FILE *rankname;
FILE *rankscore;
FILE *rankposition;

void number_select(int x, int y)
{
	if(1078<= x && x <= 1166)   // perfect
	{
		if(573 <= y && y <= 668)
		{
			perfect = true;
		}
	}

	if(442<= x && x <= 566)   // 1번 그림
	{
		if(124 <= y && y <= 256)
		{
			x_1[player][0] = 442;
			y_1[player][0] = 124;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(442<= x && x <= 566)   // 2번 그림
	{
		if(294 <= y && y <= 426)
		{
			x_1[player][0] = 442;
			y_1[player][0] = 294;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(442<= x && x <= 566)   // 3번 그림
	{
		if(464 <= y && y <= 596)
		{
			x_1[player][0] = 442;
			y_1[player][0] = 464;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(654<= x && x <= 778)   // 4번 그림
	{
		if(124 <= y && y <= 256)
		{
			x_1[player][0] = 654;
			y_1[player][0] = 124;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(654<= x && x <= 778)   // 5번 그림
	{
		if(294 <= y && y <= 426)
		{
			x_1[player][0] = 654;
			y_1[player][0] = 294;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(654<= x && x <= 778)   // 6번 그림
	{
		if(464 <= y && y <= 596)
		{
			x_1[player][0] = 654;
			y_1[player][0] = 464;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(866<= x && x <= 990)   // 7번 그림
	{
		if(124 <= y && y <= 256)
		{
			x_1[player][0] = 866;
			y_1[player][0] = 124;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(866<= x && x <= 990)   // 8번 그림
	{
		if(294 <= y && y <= 426)
		{
			x_1[player][0] = 866;
			y_1[player][0] = 294;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}

	if(866<= x && x <= 990)   // 9번 그림
	{
		if(464 <= y && y <= 596)
		{
			x_1[player][0] = 866;
			y_1[player][0] = 464;

			PlaySound(TEXT("sound\\click1.wav"),NULL,SND_ASYNC);
		}
	}
}

void cleaning()
{
	total_checking = true;
					
	player = 0;

	check_time_1 = true;
	check_time_2 = true;
	check_time_3 = true;
	
	loading_card[0] = loading_card[1] = 1;

	temp = 0;
	bestscore = 0;
	Load_number[0] = Load_number[1] = 0;
	current_matching[0] = current_matching[1] = 0;
	score[0] = score[1] = 0;

	up_time = down_time = 0;
	turn_player = sand = total_score = 0;
					
	mode_choice = 0;
	total_matching[0] = total_matching[1] = 0;

	load_data_easy = true;
	load_data_hard = true;
	loading_bestscore = true;
	gaming = true;
	control = true;
	waiting = false;
	select_mode = true;
	one_sound = true;
}

void player_ID_cleaning()
{
	gamer = 0;
	position[0] = position[1] = 0;
	gender[0] = gender[1] = 2;
}

void MyKey(unsigned char key, int x, int y) // 키 입력 이벤트에 대한 처리 함수
{
	if (key == 'q' || key == 'Q') // Q를 눌렀을 때
	{
		exit(0); // 프로그램 종료
	}
}

void MyMouse(int btn, int state, int x, int y) // 마우스 입력 이벤트에 대한 처리 함수
{
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN) // 왼쪽 버튼을 클릭했을 때
	{
		if(screen_main)   // 게임 초기화면 
		{ 
			if(384 <= x && x <= 568)   // 1P start
			{
				if(507 <= y && y <= 553)
				{
					screen_main = false;
					naming_1P = true;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(635<= x && x <= 818)   // 2P start
			{
				if(507 <= y && y <= 553)
				{
					screen_main = false;
					naming_2P = true;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}

		if(screen_level_1P)
		{
			if(256 <= x && x <= 525)   // Easy
			{
				if(219 <= y && y <= 476)
				{
					screen_level_1P = false;
					game_1P_easy = true;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(669 <= x && x <= 937)   // Hard
			{
				if(219 <= y && y <= 476)
				{
					screen_level_1P = false;
					game_1P_hard = true;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(35 <= x && x <= 119)   // main return
			{
				if(43 <= y && y <= 131)
				{
					screen_level_1P = false;					
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(1079 <= x && x <= 1200)   // help
			{
				if(43 <= y && y <= 131)
				{
					screen_level_1P = false;					
					screen_help_1P = true;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}

		if(screen_level_2P)
		{
			if(93 <= x && x <= 361)   // Easy
			{
				if(219 <= y && y <= 476)
				{
					screen_level_2P = false;
					game_2P_easy = true;
					
					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(462 <= x && x <= 730)   // Hard
			{
				if(219 <= y && y <= 476)
				{
					screen_level_2P = false;
					game_2P_hard = true;
					
					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(832 <= x && x <= 1099)   // Special
			{
				if(219 <= y && y <= 476)
				{
					screen_level_2P = false;
					screen_help_special = true;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(35 <= x && x <= 119)   // main return
			{
				if(43 <= y && y <= 131)
				{
					screen_level_2P = false;
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(1079 <= x && x <= 1160)   // help
			{
				if(45 <= y && y <= 131)
				{
					screen_level_2P = false;
					screen_help_2P = true;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}

		if(screen_help_1P)
		{
			if(1132 <= x && x <= 1190)   // next
			{
				if(380 <= y && y <= 442)
				{
					if(current != 6)
						current += 1;
					check_time = true;

					PlaySound(TEXT("sound\\next.wav"),NULL,SND_ASYNC);
				}
			}

			if(13 <= x && x <= 71)   // prior
			{
				if(380 <= y && y <= 442)
				{
					if(current != 1)
						current -= 1;
					check_time = true;

					PlaySound(TEXT("sound\\prior.wav"),NULL,SND_ASYNC);
				}
			}

			if(1079 <= x && x <= 1161)   // return
			{
				if(45 <= y && y <= 132)
				{
					screen_help_1P = false;
					screen_level_1P = true;
					check_time = true;
					current = 1;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}

		if(screen_help_2P)
		{
			if(1132 <= x && x <= 1190)   // next
			{
				if(380 <= y && y <= 442)
				{
					if(current != 6)
						current += 1;
					check_time = true;

					PlaySound(TEXT("sound\\next.wav"),NULL,SND_ASYNC);
				}
			}

			if(13 <= x && x <= 71)   // prior
			{
				if(380 <= y && y <= 442)
				{
					if(current != 1)
						current -= 1;
					check_time = true;

					PlaySound(TEXT("sound\\prior.wav"),NULL,SND_ASYNC);
				}
			}

			if(1079 <= x && x <= 1161)   // return
			{
				if(45 <= y && y <= 132)
				{
					screen_help_2P = false;
					screen_level_2P = true;
					check_time = true;
					current = 1;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}

		if(screen_help_special)
		{
			if(1086 <= x && x <= 1141)   // next
			{
				if(389 <= y && y <= 471)
				{
					if(current != 4)
						current += 1;
					check_time = true;

					PlaySound(TEXT("sound\\next.wav"),NULL,SND_ASYNC);
				}
			}

			if(57 <= x && x <= 115)   // prior
			{
				if(389 <= y && y <= 471)
				{
					if(current != 1)
						current -= 1;
					check_time = true;

					PlaySound(TEXT("sound\\prior.wav"),NULL,SND_ASYNC);
				}
			}

			if(36 <= x && x <= 118)   // return
			{
				if(47 <= y && y <= 130)
				{
					screen_help_special = false;
					screen_level_2P = true;
					check_time = true;
					current = 1;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(1080 <= x && x <= 1159)   // start
			{
				if(47 <= y && y <= 131)
				{
					screen_help_special = false;
					game_2P_special = true;
					check_time = true;
					current = 1;

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}

		if(naming_1P||naming_2P)
		{
			if(1078<= x && x <= 1162)   // main return
			{
				if(44 <= y && y <= 131)
				{
					if(naming_1P)
						naming_1P = false;
					else if(naming_2P)
						naming_2P = false;

					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(submit_control)
			{
				if(473<= x && x <= 491)   // male
				{
					if(333 <= y && y <= 352)
					{
						gender[gamer] = 0;

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}

				if(601<= x && x <= 620)   // female
				{
					if(333 <= y && y <= 352)
					{
						gender[gamer] = 1;

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}

				if(457<= x && x <= 739)   // submit
				{
					if(385 <= y && y <= 434)
					{
						if(gender[gamer] != 2 && position[gamer] != 0)
						{
							if(naming_1P)
							{
								naming_1P = false;
								screen_level_1P = true;
							}
							else if(naming_2P)
							{
								gamer += 1;

								if(gamer == 2)
								{
									naming_2P = false;
									player_order = true;
						
									gamer = 0;
								}
							}
						}
						else
						{
							submit = true;
						}

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}

				if(936 <= x && x <= 1039)
				{
					if(547<= y && y <= 601)   // back space
					{
						if(position[gamer] != 0)
							position[gamer] -= 1;

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}

				if(481 <= y && y <= 536)
				{
					for(i=0;i<14;i++)
					{
						if(162+63*i<= x && x <= 217+63*i)   // 1열
						{
							if(position[gamer] == 18)
							{
								press = true;
							}
							else
							{
								key_number[gamer][position[gamer]] = i;
								position[gamer] += 1;
							}

							PlaySound(TEXT("sound\\keyboard.wav"),NULL,SND_ASYNC);
						}
					}
				}

				if(547 <= y && y <= 601)
				{
					for(i=0;i<11;i++)
					{
						if(241+63*i<= x && x <= 296+63*i)   // 2열
						{
							if(position[gamer] == 18)
							{
								press = true;
							}
							else
							{
								key_number[gamer][position[gamer]] = 14+i;
								position[gamer] += 1;
							}

							PlaySound(TEXT("sound\\keyboard.wav"),NULL,SND_ASYNC);
						}
					}
				}

				if(612 <= y && y <= 666)
				{
					if(161<= x && x <= 262)   // space
					{
						if(position[gamer] == 18)
						{
							press = true;
						}
						else
						{
							key_number[gamer][position[gamer]] = 25;
							position[gamer] += 1;
						}

						PlaySound(TEXT("sound\\keyboard.wav"),NULL,SND_ASYNC);
					}

					for(i=0;i<11;i++)
					{
						if(271+63*i<= x && x <= 325+63*i)   // 3열
						{
							if(position[gamer] == 18)
							{
								press = true;
							}
							else
							{
								key_number[gamer][position[gamer]] = 26+i;
								position[gamer] += 1;	
							}

							PlaySound(TEXT("sound\\keyboard.wav"),NULL,SND_ASYNC);
						}
					}
				}
			}

			x=0;
			y=0;
		}

		if(game_1P_easy)
		{
			if(1078<= x && x <= 1162)   // main return
			{
				if(44 <= y && y <= 131)
				{
					game_1P_easy = false;
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(gaming)
			{
				number_select(x, y);
			}
			else
			{
				if(545<= x && x <= 731)  // 그만하기
				{
					if(420 <= y && y <= 504)
					{
						screen_ranking_easy = true;
						game_1P_easy = false;

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}

				if(845<= x && x <= 1031)  // 계속하기
				{
					if(420 <= y && y <= 504)
					{
						cleaning();

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}
			}

			x=0;
			y=0;
		}

		if(game_1P_hard)
		{
			if(gaming)
			{
				if(1078<= x && x <= 1162)   // main return
				{
					if(44 <= y && y <= 131)
					{
						game_1P_hard = false;
						screen_main = true;

						cleaning();
						player_ID_cleaning();

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}

				if(control)
				{
					number_select(x, y);
				}
			}
			else
			{
				if(545<= x && x <= 731)  // 그만하기
				{
					if(420 <= y && y <= 504)
					{
						screen_ranking_hard = true;
						game_1P_hard = false;

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}

				if(845<= x && x <= 1031)  // 계속하기
				{
					if(420 <= y && y <= 504)
					{
						cleaning();

						PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
					}
				}
			}

			x=0;
			y=0;
		}

		if(player_order)
		{
			if(order_control)
			{
				if(gamer == 0)
				{
					if(370<= x && x <= 543)   //
					{
						if(46 <= y && y <= 327)
						{
							srand((unsigned)time(NULL));

							poker_select[gamer] = rand()%12;
							gamer += 1;
							
							check_time = true;
						}
					}
				}
				else if(gamer == 1)
				{
					if(345<= x && x <= 518)   //
					{
						if(46 <= y && y <= 327)
						{
							srand((unsigned)time(NULL));

							poker_select[gamer] = rand()%12;
							while(1)
							{
								if(poker_select[0] == poker_select[1])
									poker_select[gamer] = rand()%12;
								else
									break;
							}
							gamer += 1;
						}
					}
				}
			}
		}

		if(game_2P_easy)
		{
			if(1078<= x && x <= 1162)   // main return
			{
				if(44 <= y && y <= 131)
				{
					game_2P_easy = false;
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			number_select(x, y);
		}

		if(game_2P_hard)
		{
			if(1078<= x && x <= 1162)   // main return
			{
				if(44 <= y && y <= 131)
				{
					game_2P_hard = false;
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			number_select(x, y);
		}


		if(game_2P_special)
		{
			if(1078<= x && x <= 1162)   // main return
			{
				if(44 <= y && y <= 131)
				{
					game_2P_special = false;
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			if(waiting)
			{
				if(!select_mode)
				{
					number_select(x, y);
				}
				else
				{
					if(629<= x && x <= 731)   // attack
					{
						if(297 <= y && y <= 417)
						{
							mode_choice = 1;
							select_mode = false;
							check_time_2 = true;

							PlaySound(TEXT("sound\\attack.wav"),NULL,SND_ASYNC);
						}
					}

					if(779<= x && x <= 881)   // defence
					{
						if(297 <= y && y <= 417)
						{
							mode_choice = 2;
							select_mode = false;
							check_time_2 = true;

							PlaySound(TEXT("sound\\defence.wav"),NULL,SND_ASYNC);
						}
					}
				}
			}

			x=0;
			y=0;
		}

		if(screen_ranking_easy)
		{
			if(1077<= x && x <= 1159)   // return
			{
				if(45 <= y && y <= 128)
				{
					screen_ranking_easy = false;
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}

		if(screen_ranking_hard)
		{
			if(1077<= x && x <= 1159)   // return
			{
				if(45 <= y && y <= 128)
				{
					screen_ranking_hard = false;
					screen_main = true;

					cleaning();
					player_ID_cleaning();

					PlaySound(TEXT("sound\\button.wav"),NULL,SND_ASYNC);
				}
			}

			x=0;
			y=0;
		}
	}
}