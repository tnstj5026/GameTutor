#include "image loading.h" // 이미지 파일을 로딩하기 위해 필요한 헤더 파일 (이미지 출력을 위한 GLUT가 이미 포함된 라이브러리)
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
		
		glEnable(GL_ALPHA_TEST); // Alpha값을 사용할 수 있게 설정 변경
		glAlphaFunc(GL_GREATER,0.0); // Alpha로 지정한 값 전달

		name();
	}

	if(player_order)
	{
		if(loading_order==true) Loadimage_order();
		if(loading_notice == true) Loadimage_notice();

		if(check_time == true) First_time_help();
		end_time = time(NULL);
		gap = end_time - start_time;
				
		glEnable(GL_ALPHA_TEST); // Alpha값을 사용할 수 있게 설정 변경
		glAlphaFunc(GL_GREATER,0.0); // Alpha로 지정한 값 전달

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
		
		glEnable(GL_ALPHA_TEST); // Alpha값을 사용할 수 있게 설정 변경
		glAlphaFunc(GL_GREATER,0.0); // Alpha로 지정한 값 전달

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

		glEnable(GL_ALPHA_TEST); // Alpha값을 사용할 수 있게 설정 변경
		glAlphaFunc(GL_GREATER,0.0); // Alpha로 지정한 값 전달
		
		score_display();
	}

	if(screen_ranking_hard)
	{
		if(loading_rank == true) Loadimage_ranking();

		glBindTexture(GL_TEXTURE_2D,back_ranking);
		drawDisplay(width, height, 0, 0);
			
		if(load_data_hard == true) data_hard();

		glEnable(GL_ALPHA_TEST); // Alpha값을 사용할 수 있게 설정 변경
		glAlphaFunc(GL_GREATER,0.0); // Alpha로 지정한 값 전달
		
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

		glEnable(GL_ALPHA_TEST); // Alpha값을 사용할 수 있게 설정 변경
		glAlphaFunc(GL_GREATER,0.0); // Alpha로 지정한 값 전달

		winner_display();

		if(gap > 10)
		{
			winner_loser = false;
			screen_level_2P = true;
			check_time = true;

			cleaning();
		}
	}
	
	glDisable(GL_ALPHA_TEST); // Alpha값을 사용 중지
	glutSwapBuffers();
}

void MyIdle() // 계속 실행이 반복되는 내용을 설정하는 함수
{
	Sleep(100);

	glutPostRedisplay(); // display 함수의 재호출
}

void MyReshape(GLsizei newwidth, GLsizei newheight) // 창 크기가 변경될 때 호출되는 함수
{  
	// 시점과 출력에 대한 설정
	glViewport(0, 0, newwidth, newheight);
	width=newwidth;
	height=newheight;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, width, height, 0.0, 0.0, 100.0);
	glMatrixMode(GL_MODELVIEW);

	glutPostRedisplay(); // display 함수의 재호출
}

void InitGL(int w, int h) // 그래픽 품질에 대한 설정 함수
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

int main(int argc, char **argv) // 프로그램 실행 메인
{
	glutInit(&argc, argv); // GLUT(그래픽 유틸리티) 초기화
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA); // 더블 버퍼모드 사용
	glutInitWindowSize(DEFAULT_WIDTH, DEFAULT_HEIGHT); // 윈도우 초기 크기 설정
	
	glutCreateWindow("bmp blend program"); // 생성되는 윈도우의 이름

	// 이미지 파일 로딩

	InitGL(DEFAULT_WIDTH, DEFAULT_HEIGHT); // 그래픽 품질 초기화

	glutDisplayFunc(MyDisplay); // 화면을 색칠할 때 호출하는 함수 설정 (화면 출력)
	glutIdleFunc(MyIdle); // 화면을 색칠할 때 호출하는 함수 설정 (화면 출력)
	glutReshapeFunc(MyReshape); // 윈도우의 크기 변경 시 호출하는 함수 설정 (화면 크기에 따른 변화 방향 설정)
	glutKeyboardFunc(MyKey); // 키 입력 이벤트 처리 방식 설정
	glutMouseFunc(MyMouse); // 마우스 입력 이벤트 처리 방식 설정

	
	// 윈도우에서의 메뉴 설정

	int sub1; // 보조 메뉴1의 순서 저장 변수
	sub1=glutCreateMenu(sub_menu1); // 보조 메뉴1에 실행될 함수 설정 및 순서 할당
	// 보조 메뉴의 선택사항 등록
	glutAddMenuEntry("A", 1); // 첫 번째 항목
	glutAddMenuEntry("B", 2); // 두 번째 항목
	
	int sub2; // 보조 메뉴1의 순서 저장 변수
	sub2=glutCreateMenu(sub_menu2); // 보조 메뉴1에 실행될 함수 설정 및 순서 할당
	// 보조 메뉴의 선택사항 등록
	glutAddMenuEntry("a", 1); // 첫 번째 항목
	glutAddMenuEntry("b", 2); // 두 번째 항목

	glutCreateMenu(top_menu); // 보조 메뉴로 들어가기 이전의 최상위 메뉴 설정
	glutAddSubMenu("upper case", sub1); // 보조 메뉴의 항목 이름 및 실행될 메뉴 결정
	glutAttachMenu(GLUT_RIGHT_BUTTON); // 메뉴로 접속하기 위한 이벤트 설정 (마우스 오른쪽 버튼 클릭)
	glutAddSubMenu("lower case", sub2); // 보조 메뉴의 항목 이름 및 실행될 메뉴 결정
	glutAttachMenu(GLUT_RIGHT_BUTTON); // 메뉴로 접속하기 위한 이벤트 설정 (마우스 오른쪽 버튼 클릭)
	glutAddMenuEntry("music", 1);

	glutMainLoop(); // 메인의 반복 유지

	// 프로그램 종료 전 이미지 메모리 할당 해제
	FreeTexture(back_main);
	FreeTexture(back_battlefield_1P);

	return 0; // 프로그램 종료
}