#include "image loading.h" // �̹��� ������ �ε��ϱ� ���� �ʿ��� ��� ���� (�̹��� ����� ���� GLUT�� �̹� ���Ե� ���̺귯��)
#include "event callback.h"
#include "menu setting.h"
#include "sound.h"
#include "repeat.h"
#include "time.h"
#include "picture.h"
#include "time check.h"
#include "help.h"
#include "game card.h"
#include "core.h"
#include "display.h"
#include "personal information.h"
#include "final page.h"
#include "score.h"

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glMatrixMode(GL_MODELVIEW);

	if(loading_main == true) Loadimage_main();

	if(screen_loading)
	{
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = end_time - start_time;

		glBindTexture(GL_TEXTURE_2D,back_loading);
		drawDisplay(width, height, 0, 0);

		if(gap > 5)
		{
			screen_loading = false;
			screen_main = true;
			check_time = true;
		}
	}

	if(screen_main)
	{
		if(one_speak == true)
		{
			if(time(NULL)%2 == 0)
				bgm_start(L"sound\\BGM_main.mp3");
			else
				bgm_start(L"sound\\BGM_game.mp3");

			one_speak = false;
		}

		glBindTexture(GL_TEXTURE_2D,back_main);
		drawDisplay(width, height, 0, 0);
	}

	if(screen_level_1P)
	{
		glBindTexture(GL_TEXTURE_2D,back_levelselect_1P);
		drawDisplay(width, height, 0, 0);
	}

	if(screen_level_2P)
	{
		glBindTexture(GL_TEXTURE_2D,back_levelselect_2P);
		drawDisplay(width, height, 0, 0);
	}

	if(screen_help_1P)
	{
		temp = 0;
		help_bundle();
	}

	if(screen_help_2P)
	{
		temp = 1;
		help_bundle();
	}

	if(screen_help_special)
	{
		help_special();
	}

	if(naming_1P||naming_2P)
	{
		if(loading_keyboard==true) Loadimage_keyboard();
		if(loading_notice == true) Loadimage_notice();
		
		glEnable(GL_ALPHA_TEST); // Alpha���� ����� �� �ְ� ���� ����
		glAlphaFunc(GL_GREATER,0.0); // Alpha�� ������ �� ����

		name();
	}

	if(player_order)
	{
		if(loading_order==true) Loadimage_order();
		if(loading_notice == true) Loadimage_notice();

		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = end_time - start_time;
				
		glEnable(GL_ALPHA_TEST); // Alpha���� ����� �� �ְ� ���� ����
		glAlphaFunc(GL_GREATER,0.0); // Alpha�� ������ �� ����

		glBindTexture(GL_TEXTURE_2D,player_ordering);
		drawDisplay(width, height, 0, 0);
		
		order();
	}

	if(game_1P_easy)
	{
		if(loading_game==true) Loadimage_game();
		if(loading_game_1P==true) Loadimage_game_1P();

		glBindTexture(GL_TEXTURE_2D,back_battlefield_1P);
		drawDisplay(width, height, 0, 0);

		if(check_time_1 == true) First_time();
		end_time_1 = time(NULL);
		gap_1 = end_time_1 - start_time_1;

		game_core();
		game_display_1P();
	}
	
	if(game_1P_hard)
	{
		if(loading_game==true) Loadimage_game();
		if(loading_game_1P==true) Loadimage_game_1P();

		glBindTexture(GL_TEXTURE_2D,back_battlefield_1P);
		drawDisplay(width, height, 0, 0);
		
		if(check_time_1 == true) First_time();
		end_time_1 = time(NULL);
		gap_1 = end_time_1 - start_time_1;
		
		game_core();
		game_display_1P();
	}	

	if(game_2P_easy)
	{
		if(loading_game==true) Loadimage_game();
		if(loading_game_1P==true) Loadimage_game_1P();
		if(loading_game_2P==true) Loadimage_game_2P();

		glBindTexture(GL_TEXTURE_2D,back_battlefield_2P);
		drawDisplay(width, height, 0, 0);
		
		if(check_time_3 == true) Third_time();
		end_time_3 = time(NULL);
		gap_3 = end_time_3 - start_time_3;

		game_core();
		game_display_2P();

		if(turn_player == 40)
		{
			game_2P_easy = false;
			winner_loser = true;
			
			initialization();
		}
	}

	if(game_2P_hard)
	{
		if(loading_game==true) Loadimage_game();
		if(loading_game_1P==true) Loadimage_game_1P();
		if(loading_game_2P==true) Loadimage_game_2P();

		glBindTexture(GL_TEXTURE_2D,back_battlefield_2P);
		drawDisplay(width, height, 0, 0);

		if(check_time_3 == true) Third_time();
		end_time_3 = time(NULL);
		gap_3 = end_time_3 - start_time_3;

		game_core();
		game_display_2P();

		if(turn_player == 40)
		{
			game_2P_hard = false;
			winner_loser = true;

			initialization();
		}
	}	

	if(game_2P_special)
	{
		if(loading_game == true) Loadimage_game();
		if(loading_game_1P == true) Loadimage_game_1P();
		if(loading_game_2P == true) Loadimage_game_2P();
		
		if(check_time_1 == true) First_time();
		end_time_1 = time(NULL);
		gap_1 = end_time_1 - start_time_1;
		
		glBindTexture(GL_TEXTURE_2D,back_battlefield_2P_Sp);
		drawDisplay(width, height, 0, 0);
		
		glEnable(GL_ALPHA_TEST); // Alpha���� ����� �� �ְ� ���� ����
		glAlphaFunc(GL_GREATER,0.0); // Alpha�� ������ �� ����

		if(gap_1 < 4) 
		{
			glBindTexture(GL_TEXTURE_2D,loading_page);
			drawDisplay(width, height, 0, 0);

			glBindTexture(GL_TEXTURE_2D,loading_bar);
			drawDisplay(237*(gap_1/3.0), 7, 482, 397);

			glBindTexture(GL_TEXTURE_2D,loading_sand[sand]);
			drawDisplay(121, 129, 539, 229);

			sand += 1;
			if(sand == 17)
				sand = 0;
		}
		else
		{
			waiting = true;

			selectingcard_1P_36();
			selectingcard_2P_36();
			total_calculation();
			
			if(check_time_2 == true) Second_time();
			end_time_2 = time(NULL);
			gap_2 = end_time_2 - start_time_2;
									
			if(mode_choice == 2)
			{
				if((turn_player%2) == 0)
					player = 0;
				else
					player = 1;
			}
			else if(mode_choice == 1)
			{
				if((turn_player%2) == 0)
					player = 1;
				else
					player = 0;				
			}
			else if(gap_2 > 5 && mode_choice == 0)
			{
				turn_player += 1;
				check_time_2 = true;
				select_mode = true;
			}
			
			if(select_mode)
			{
				glBindTexture(GL_TEXTURE_2D,block_screen);
				drawDisplay(738, 636, 319, 50);

				if((turn_player%2) == 0)
				{
					glBindTexture(GL_TEXTURE_2D,select_back_1P);
					drawDisplay(655, 407, 272, 156);
				}
				else
				{
					glBindTexture(GL_TEXTURE_2D,select_back_2P);
					drawDisplay(655, 407, 272, 156);
				}
			}
			else
			{
				special_core();
			}

			special_display();
		}
	}

	if(screen_ranking_easy)
	{
		if(loading_rank == true) Loadimage_ranking();

		glBindTexture(GL_TEXTURE_2D,back_ranking);
		drawDisplay(width, height, 0, 0);
		
		if(load_data_easy == true) data_easy();

		glEnable(GL_ALPHA_TEST); // Alpha���� ����� �� �ְ� ���� ����
		glAlphaFunc(GL_GREATER,0.0); // Alpha�� ������ �� ����
		
		score_display();
	}

	if(screen_ranking_hard)
	{
		if(loading_rank == true) Loadimage_ranking();

		glBindTexture(GL_TEXTURE_2D,back_ranking);
		drawDisplay(width, height, 0, 0);
			
		if(load_data_hard == true) data_hard();

		glEnable(GL_ALPHA_TEST); // Alpha���� ����� �� �ְ� ���� ����
		glAlphaFunc(GL_GREATER,0.0); // Alpha�� ������ �� ����
		
		score_display();
	}

	if(winner_loser)
	{
		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = end_time - start_time;

		if(one_sound)
		{
			PlaySound(TEXT("sound\\end.wav"),NULL,SND_ASYNC);
			one_sound = false;
		}
		if(loading_final==true) Loadimage_final();

		glEnable(GL_ALPHA_TEST); // Alpha���� ����� �� �ְ� ���� ����
		glAlphaFunc(GL_GREATER,0.0); // Alpha�� ������ �� ����

		winner_display();

		if(gap > 10)
		{
			winner_loser = false;
			screen_level_2P = true;
			check_time = true;

			cleaning();
		}
	}
	
	glDisable(GL_ALPHA_TEST); // Alpha���� ��� ����
	glutSwapBuffers();
}

void MyIdle() // ��� ������ �ݺ��Ǵ� ������ �����ϴ� �Լ�
{
	Sleep(100);

	glutPostRedisplay(); // display �Լ��� ��ȣ��
}

void MyReshape(GLsizei newwidth, GLsizei newheight) // â ũ�Ⱑ ����� �� ȣ��Ǵ� �Լ�
{  
	// ������ ��¿� ���� ����
	glViewport(0, 0, newwidth, newheight);
	width=newwidth;
	height=newheight;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay(); // display �Լ��� ��ȣ��
}

void InitGL(int w, int h) // �׷��� ǰ���� ���� ���� �Լ�
{
	glViewport(0, 0, w, h);
	glEnable(GL_TEXTURE_2D);

	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity();
	glOrtho(0.0, w, h, 0.0, 0.0, 100.0);

	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); 
	glClearDepth(0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
}

int main(int argc, char **argv) // ���α׷� ���� ����
{
	glutInit(&argc, argv); // GLUT(�׷��� ��ƿ��Ƽ) �ʱ�ȭ
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA); // ���� ���۸�� ���
	glutInitWindowSize(DEFAULT_WIDTH, DEFAULT_HEIGHT); // ������ �ʱ� ũ�� ����
	
	glutCreateWindow("bmp blend program"); // �����Ǵ� �������� �̸�

	// �̹��� ���� �ε�

	InitGL(DEFAULT_WIDTH, DEFAULT_HEIGHT); // �׷��� ǰ�� �ʱ�ȭ

	glutDisplayFunc(MyDisplay); // ȭ���� ��ĥ�� �� ȣ���ϴ� �Լ� ���� (ȭ�� ���)
	glutIdleFunc(MyIdle); // ȭ���� ��ĥ�� �� ȣ���ϴ� �Լ� ���� (ȭ�� ���)
	glutReshapeFunc(MyReshape); // �������� ũ�� ���� �� ȣ���ϴ� �Լ� ���� (ȭ�� ũ�⿡ ���� ��ȭ ���� ����)
	glutKeyboardFunc(MyKey); // Ű �Է� �̺�Ʈ ó�� ��� ����
	glutMouseFunc(MyMouse); // ���콺 �Է� �̺�Ʈ ó�� ��� ����

	
	// �����쿡���� �޴� ����

	int sub1; // ���� �޴�1�� ���� ���� ����
	sub1=glutCreateMenu(sub_menu1); // ���� �޴�1�� ����� �Լ� ���� �� ���� �Ҵ�
	// ���� �޴��� ���û��� ���
	glutAddMenuEntry("A", 1); // ù ��° �׸�
	glutAddMenuEntry("B", 2); // �� ��° �׸�
	
	int sub2; // ���� �޴�1�� ���� ���� ����
	sub2=glutCreateMenu(sub_menu2); // ���� �޴�1�� ����� �Լ� ���� �� ���� �Ҵ�
	// ���� �޴��� ���û��� ���
	glutAddMenuEntry("a", 1); // ù ��° �׸�
	glutAddMenuEntry("b", 2); // �� ��° �׸�

	glutCreateMenu(top_menu); // ���� �޴��� ���� ������ �ֻ��� �޴� ����
	glutAddSubMenu("upper case", sub1); // ���� �޴��� �׸� �̸� �� ����� �޴� ����
	glutAttachMenu(GLUT_RIGHT_BUTTON); // �޴��� �����ϱ� ���� �̺�Ʈ ���� (���콺 ������ ��ư Ŭ��)
	glutAddSubMenu("lower case", sub2); // ���� �޴��� �׸� �̸� �� ����� �޴� ����
	glutAttachMenu(GLUT_RIGHT_BUTTON); // �޴��� �����ϱ� ���� �̺�Ʈ ���� (���콺 ������ ��ư Ŭ��)
	glutAddMenuEntry("music", 1);

	glutMainLoop(); // ������ �ݺ� ����

	// ���α׷� ���� �� �̹��� �޸� �Ҵ� ����
	FreeTexture(back_main);
	FreeTexture(back_battlefield_1P);

	return 0; // ���α׷� ����
}