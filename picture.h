#pragma once

#include "image loading.h"
#include <stdio.h>
#include <glut.h>
#include <windows.h>

GLuint back_loading;
GLuint back_main;
GLuint back_levelselect_1P;
GLuint back_levelselect_2P;
GLuint back_battlefield_1P;
GLuint back_battlefield_2P;
GLuint back_battlefield_2P_Sp;
GLuint back_submit_name[3];
GLuint back_ranking;
GLuint back_final[3];
GLuint help[3][6][5];
GLuint select_card[2][10];
GLuint card_bundle[2][37];
GLuint card_edge[2][37];
GLuint hiddencard_1P;
GLuint hiddencard_2P;
GLuint hiddencard_edge_1P;
GLuint hiddencard_edge_2P;
GLuint word[10];
GLuint countdown_page;
GLuint select_back_1P;
GLuint select_back_2P;
GLuint player_show;
GLuint block_screen;
GLuint bar;
GLuint digital[11];
GLuint loading_page;
GLuint loading_bar;
GLuint loading_sand[18];
GLuint round[10];
GLuint final_select;
GLuint image_gender[2];
GLuint keyboard[37];
GLuint keyboard_black[37];
GLuint player_ordering;
GLuint poker[13];
GLuint check;
GLuint plus;
GLuint notice[5];

void Loadimage_main()
{
	back_loading=LoadTexture("image_bundle\\loading1.bmp");
	back_main=LoadTexture("image_bundle\\main ground.bmp");
	back_levelselect_1P=LoadTexture("image_bundle\\level select 1P.bmp");
	back_levelselect_2P=LoadTexture("image_bundle\\level select 2P.bmp");

	loading_main = false;
}

void Loadimage_help_1P()
{
	help[0][0][0]=LoadTexture("image_bundle\\method 1P 1-1.bmp");
	help[0][1][0]=LoadTexture("image_bundle\\method 1P 2-1.bmp");
	help[0][1][1]=LoadTexture("image_bundle\\method 1P 2-2.bmp");
	help[0][1][2]=LoadTexture("image_bundle\\method 1P 2-3.bmp");
	help[0][1][3]=LoadTexture("image_bundle\\method 1P 2-4.bmp");
	help[0][1][4]=LoadTexture("image_bundle\\method 1P 2-5.bmp");
	help[0][2][0]=LoadTexture("image_bundle\\method 1P 3-1.bmp");
	help[0][2][1]=LoadTexture("image_bundle\\method 1P 3-2.bmp");
	help[0][2][2]=LoadTexture("image_bundle\\method 1P 3-3.bmp");
	help[0][2][3]=LoadTexture("image_bundle\\method 1P 3-4.bmp");
	help[0][3][0]=LoadTexture("image_bundle\\method 1P 4-1.bmp");
	help[0][3][1]=LoadTexture("image_bundle\\method 1P 4-2.bmp");
	help[0][3][2]=LoadTexture("image_bundle\\method 1P 4-3.bmp");
	help[0][3][3]=LoadTexture("image_bundle\\method 1P 4-4.bmp");
	help[0][4][0]=LoadTexture("image_bundle\\method 1P 5-1.bmp");
	help[0][4][1]=LoadTexture("image_bundle\\method 1P 5-2.bmp");
	help[0][5][0]=LoadTexture("image_bundle\\method 1P 6-1.bmp");
	help[0][5][1]=LoadTexture("image_bundle\\method 1P 6-2.bmp");

	loading_help_1P = false;
}

void Loadimage_help_2P()
{
	help[1][0][0]=LoadTexture("image_bundle\\method 2P 1-1.bmp");
	help[1][1][0]=LoadTexture("image_bundle\\method 2P 2-1.bmp");
	help[1][1][1]=LoadTexture("image_bundle\\method 2P 2-2.bmp");
	help[1][1][2]=LoadTexture("image_bundle\\method 2P 2-3.bmp");
	help[1][1][3]=LoadTexture("image_bundle\\method 2P 2-4.bmp");
	help[1][1][4]=LoadTexture("image_bundle\\method 2P 2-5.bmp");
	help[1][2][0]=LoadTexture("image_bundle\\method 2P 3-1.bmp");
	help[1][2][1]=LoadTexture("image_bundle\\method 2P 3-2.bmp");
	help[1][2][2]=LoadTexture("image_bundle\\method 2P 3-3.bmp");
	help[1][2][3]=LoadTexture("image_bundle\\method 2P 3-4.bmp");
	help[1][3][0]=LoadTexture("image_bundle\\method 2P 4-1.bmp");
	help[1][3][1]=LoadTexture("image_bundle\\method 2P 4-2.bmp");
	help[1][3][2]=LoadTexture("image_bundle\\method 2P 4-3.bmp");
	help[1][3][3]=LoadTexture("image_bundle\\method 2P 4-4.bmp");
	help[1][4][0]=LoadTexture("image_bundle\\method 2P 5-1.bmp");
	help[1][4][1]=LoadTexture("image_bundle\\method 2P 5-2.bmp");
	help[1][5][0]=LoadTexture("image_bundle\\method 2P 6-1.bmp");
	help[1][5][1]=LoadTexture("image_bundle\\method 2P 6-2.bmp");
	
	loading_help_2P = false;
}

void Loadimage_help_special()
{
	help[2][0][0]=LoadTexture("image_bundle\\method Sp 1-1.bmp");
	help[2][0][1]=LoadTexture("image_bundle\\method Sp 1-2.bmp");
	help[2][0][2]=LoadTexture("image_bundle\\method Sp 1-3.bmp");
	help[2][1][0]=LoadTexture("image_bundle\\method Sp 2-1.bmp");
	help[2][1][1]=LoadTexture("image_bundle\\method Sp 2-2.bmp");
	help[2][1][2]=LoadTexture("image_bundle\\method Sp 2-3.bmp");
	help[2][2][0]=LoadTexture("image_bundle\\method Sp 3-1.bmp");
	help[2][2][1]=LoadTexture("image_bundle\\method Sp 3-2.bmp");
	help[2][3][0]=LoadTexture("image_bundle\\method Sp 4-1.bmp");
	help[2][3][1]=LoadTexture("image_bundle\\method Sp 4-2.bmp");

	loading_help_special = false;
}

void Loadimage_keyboard()
{
	back_submit_name[0]=LoadTexture("image_bundle\\submit name1.bmp");
	back_submit_name[1]=LoadTexture("image_bundle\\submit name2.bmp");
	back_submit_name[2]=LoadTexture("image_bundle\\submit name3.bmp");

	keyboard[0]=LoadTexture("image_bundle\\key 0.bmp");
	keyboard[1]=LoadTexture("image_bundle\\key q.bmp");
	keyboard[2]=LoadTexture("image_bundle\\key w.bmp");
	keyboard[3]=LoadTexture("image_bundle\\key e.bmp");
	keyboard[4]=LoadTexture("image_bundle\\key r.bmp");
	keyboard[5]=LoadTexture("image_bundle\\key t.bmp");
	keyboard[6]=LoadTexture("image_bundle\\key y.bmp");
	keyboard[7]=LoadTexture("image_bundle\\key u.bmp");
	keyboard[8]=LoadTexture("image_bundle\\key i.bmp");
	keyboard[9]=LoadTexture("image_bundle\\key o.bmp");
	keyboard[10]=LoadTexture("image_bundle\\key p.bmp");
	keyboard[11]=LoadTexture("image_bundle\\key 7.bmp");
	keyboard[12]=LoadTexture("image_bundle\\key 8.bmp");
	keyboard[13]=LoadTexture("image_bundle\\key 9.bmp");
	keyboard[14]=LoadTexture("image_bundle\\key a.bmp");
	keyboard[15]=LoadTexture("image_bundle\\key s.bmp");
	keyboard[16]=LoadTexture("image_bundle\\key d.bmp");
	keyboard[17]=LoadTexture("image_bundle\\key f.bmp");
	keyboard[18]=LoadTexture("image_bundle\\key g.bmp");
	keyboard[19]=LoadTexture("image_bundle\\key h.bmp");
	keyboard[20]=LoadTexture("image_bundle\\key j.bmp");
	keyboard[21]=LoadTexture("image_bundle\\key k.bmp");
	keyboard[22]=LoadTexture("image_bundle\\key l.bmp");
	keyboard[23]=LoadTexture("image_bundle\\key 5.bmp");
	keyboard[24]=LoadTexture("image_bundle\\key 6.bmp");
	keyboard[25]=LoadTexture("image_bundle\\key space.bmp");
	keyboard[26]=LoadTexture("image_bundle\\key z.bmp");
	keyboard[27]=LoadTexture("image_bundle\\key x.bmp");
	keyboard[28]=LoadTexture("image_bundle\\key c.bmp");
	keyboard[29]=LoadTexture("image_bundle\\key v.bmp");
	keyboard[30]=LoadTexture("image_bundle\\key b.bmp");
	keyboard[31]=LoadTexture("image_bundle\\key n.bmp");
	keyboard[32]=LoadTexture("image_bundle\\key m.bmp");
	keyboard[33]=LoadTexture("image_bundle\\key 1.bmp");
	keyboard[34]=LoadTexture("image_bundle\\key 2.bmp");
	keyboard[35]=LoadTexture("image_bundle\\key 3.bmp");
	keyboard[36]=LoadTexture("image_bundle\\key 4.bmp");

	keyboard_black[0]=LoadTexture("image_bundle\\0.bmp");
	keyboard_black[1]=LoadTexture("image_bundle\\q.bmp");
	keyboard_black[2]=LoadTexture("image_bundle\\w.bmp");
	keyboard_black[3]=LoadTexture("image_bundle\\e.bmp");
	keyboard_black[4]=LoadTexture("image_bundle\\r.bmp");
	keyboard_black[5]=LoadTexture("image_bundle\\t.bmp");
	keyboard_black[6]=LoadTexture("image_bundle\\y.bmp");
	keyboard_black[7]=LoadTexture("image_bundle\\u.bmp");
	keyboard_black[8]=LoadTexture("image_bundle\\i.bmp");
	keyboard_black[9]=LoadTexture("image_bundle\\o.bmp");
	keyboard_black[10]=LoadTexture("image_bundle\\p.bmp");
	keyboard_black[11]=LoadTexture("image_bundle\\7.bmp");
	keyboard_black[12]=LoadTexture("image_bundle\\8.bmp");
	keyboard_black[13]=LoadTexture("image_bundle\\9.bmp");
	keyboard_black[14]=LoadTexture("image_bundle\\a.bmp");
	keyboard_black[15]=LoadTexture("image_bundle\\s.bmp");
	keyboard_black[16]=LoadTexture("image_bundle\\d.bmp");
	keyboard_black[17]=LoadTexture("image_bundle\\f.bmp");
	keyboard_black[18]=LoadTexture("image_bundle\\g.bmp");
	keyboard_black[19]=LoadTexture("image_bundle\\h.bmp");
	keyboard_black[20]=LoadTexture("image_bundle\\j.bmp");
	keyboard_black[21]=LoadTexture("image_bundle\\k.bmp");
	keyboard_black[22]=LoadTexture("image_bundle\\l.bmp");
	keyboard_black[23]=LoadTexture("image_bundle\\5.bmp");
	keyboard_black[24]=LoadTexture("image_bundle\\6.bmp");
	keyboard_black[25]=LoadTexture("image_bundle\\space.bmp");
	keyboard_black[26]=LoadTexture("image_bundle\\z.bmp");
	keyboard_black[27]=LoadTexture("image_bundle\\x.bmp");
	keyboard_black[28]=LoadTexture("image_bundle\\c.bmp");
	keyboard_black[29]=LoadTexture("image_bundle\\v.bmp");
	keyboard_black[30]=LoadTexture("image_bundle\\b.bmp");
	keyboard_black[31]=LoadTexture("image_bundle\\n.bmp");
	keyboard_black[32]=LoadTexture("image_bundle\\m.bmp");
	keyboard_black[33]=LoadTexture("image_bundle\\1.bmp");
	keyboard_black[34]=LoadTexture("image_bundle\\2.bmp");
	keyboard_black[35]=LoadTexture("image_bundle\\3.bmp");
	keyboard_black[36]=LoadTexture("image_bundle\\4.bmp");

	check=LoadTexture("image_bundle\\check box.bmp");

	loading_keyboard = false;
}

void Loadimage_order()
{
	player_ordering=LoadTexture("image_bundle\\player select.bmp");
		
	poker[0]=LoadTexture("image_bundle\\poker2.bmp");
	poker[1]=LoadTexture("image_bundle\\poker3.bmp");
	poker[2]=LoadTexture("image_bundle\\poker4.bmp");
	poker[3]=LoadTexture("image_bundle\\poker5.bmp");
	poker[4]=LoadTexture("image_bundle\\poker6.bmp");
	poker[5]=LoadTexture("image_bundle\\poker7.bmp");
	poker[6]=LoadTexture("image_bundle\\poker8.bmp");
	poker[7]=LoadTexture("image_bundle\\poker9.bmp");
	poker[8]=LoadTexture("image_bundle\\pokerJ.bmp");
	poker[9]=LoadTexture("image_bundle\\pokerK.bmp");
	poker[10]=LoadTexture("image_bundle\\pokerQ.bmp");
	poker[11]=LoadTexture("image_bundle\\pokerA.bmp");
	poker[12]=LoadTexture("image_bundle\\pokerback.bmp");

	loading_order = false;
}

void Loadimage_game()
{
	bar=LoadTexture("image_bundle\\progress bar.bmp");
	
	image_gender[0]=LoadTexture("image_bundle\\male.bmp");
	image_gender[1]=LoadTexture("image_bundle\\female.bmp");

	word[0]=LoadTexture("image_bundle\\word0.bmp");
	word[1]=LoadTexture("image_bundle\\word1.bmp");
	word[2]=LoadTexture("image_bundle\\word2.bmp");
	word[3]=LoadTexture("image_bundle\\word3.bmp");
	word[4]=LoadTexture("image_bundle\\word4.bmp");
	word[5]=LoadTexture("image_bundle\\word5.bmp");
	word[6]=LoadTexture("image_bundle\\word6.bmp");
    word[7]=LoadTexture("image_bundle\\word7.bmp");
	word[8]=LoadTexture("image_bundle\\word8.bmp");
	word[9]=LoadTexture("image_bundle\\word9.bmp");

	digital[0]=LoadTexture("image_bundle\\digit0.bmp");
	digital[1]=LoadTexture("image_bundle\\digit1.bmp");
	digital[2]=LoadTexture("image_bundle\\digit2.bmp");
	digital[3]=LoadTexture("image_bundle\\digit3.bmp");
	digital[4]=LoadTexture("image_bundle\\digit4.bmp");
	digital[5]=LoadTexture("image_bundle\\digit5.bmp");
	digital[6]=LoadTexture("image_bundle\\digit6.bmp");
	digital[7]=LoadTexture("image_bundle\\digit7.bmp");
	digital[8]=LoadTexture("image_bundle\\digit8.bmp");
	digital[9]=LoadTexture("image_bundle\\digit9.bmp");
	digital[10]=LoadTexture("image_bundle\\digit.bmp");

	player_show=LoadTexture("image_bundle\\player show.bmp");

	loading_game = false;
}

void Loadimage_game_1P()
{
	back_battlefield_1P=LoadTexture("image_bundle\\battle field.bmp");
		
	card_bundle[0][1]=LoadTexture("image_bundle\\card1.bmp");
	card_bundle[0][2]=LoadTexture("image_bundle\\card2.bmp");
	card_bundle[0][3]=LoadTexture("image_bundle\\card3.bmp");
	card_bundle[0][4]=LoadTexture("image_bundle\\card4.bmp");
	card_bundle[0][5]=LoadTexture("image_bundle\\card5.bmp");
	card_bundle[0][6]=LoadTexture("image_bundle\\card6.bmp");
	card_bundle[0][7]=LoadTexture("image_bundle\\card7.bmp");
	card_bundle[0][8]=LoadTexture("image_bundle\\card8.bmp");
	card_bundle[0][9]=LoadTexture("image_bundle\\card9.bmp");
	card_bundle[0][10]=LoadTexture("image_bundle\\card10.bmp");
	card_bundle[0][11]=LoadTexture("image_bundle\\card11.bmp");
	card_bundle[0][12]=LoadTexture("image_bundle\\card12.bmp");
	card_bundle[0][13]=LoadTexture("image_bundle\\card13.bmp");
	card_bundle[0][14]=LoadTexture("image_bundle\\card14.bmp");
	card_bundle[0][15]=LoadTexture("image_bundle\\card15.bmp");
	card_bundle[0][16]=LoadTexture("image_bundle\\card16.bmp");
	card_bundle[0][17]=LoadTexture("image_bundle\\card17.bmp");
	card_bundle[0][18]=LoadTexture("image_bundle\\card18.bmp");
	card_bundle[0][19]=LoadTexture("image_bundle\\card19.bmp");
	card_bundle[0][20]=LoadTexture("image_bundle\\card20.bmp");
	card_bundle[0][21]=LoadTexture("image_bundle\\card21.bmp");
	card_bundle[0][22]=LoadTexture("image_bundle\\card22.bmp");
	card_bundle[0][23]=LoadTexture("image_bundle\\card23.bmp");
	card_bundle[0][24]=LoadTexture("image_bundle\\card24.bmp");
	card_bundle[0][25]=LoadTexture("image_bundle\\card25.bmp");
	card_bundle[0][26]=LoadTexture("image_bundle\\card26.bmp");
	card_bundle[0][27]=LoadTexture("image_bundle\\card27.bmp");
	card_bundle[0][28]=LoadTexture("image_bundle\\card28.bmp");
	card_bundle[0][29]=LoadTexture("image_bundle\\card29.bmp");
	card_bundle[0][30]=LoadTexture("image_bundle\\card30.bmp");
    card_bundle[0][31]=LoadTexture("image_bundle\\card31.bmp");
	card_bundle[0][32]=LoadTexture("image_bundle\\card32.bmp");
	card_bundle[0][33]=LoadTexture("image_bundle\\card33.bmp");
	card_bundle[0][34]=LoadTexture("image_bundle\\card34.bmp");
	card_bundle[0][35]=LoadTexture("image_bundle\\card35.bmp");
	card_bundle[0][36]=LoadTexture("image_bundle\\card36.bmp");
	
	card_edge[0][1]=LoadTexture("image_bundle\\edge1.bmp");
	card_edge[0][2]=LoadTexture("image_bundle\\edge2.bmp");
	card_edge[0][3]=LoadTexture("image_bundle\\edge3.bmp");
	card_edge[0][4]=LoadTexture("image_bundle\\edge4.bmp");
	card_edge[0][5]=LoadTexture("image_bundle\\edge5.bmp");
	card_edge[0][6]=LoadTexture("image_bundle\\edge6.bmp");
	card_edge[0][7]=LoadTexture("image_bundle\\edge7.bmp");
	card_edge[0][8]=LoadTexture("image_bundle\\edge8.bmp");
	card_edge[0][9]=LoadTexture("image_bundle\\edge9.bmp");
	card_edge[0][10]=LoadTexture("image_bundle\\edge10.bmp");
	card_edge[0][11]=LoadTexture("image_bundle\\edge11.bmp");
	card_edge[0][12]=LoadTexture("image_bundle\\edge12.bmp");
	card_edge[0][13]=LoadTexture("image_bundle\\edge13.bmp");
	card_edge[0][14]=LoadTexture("image_bundle\\edge14.bmp");
	card_edge[0][15]=LoadTexture("image_bundle\\edge15.bmp");
	card_edge[0][16]=LoadTexture("image_bundle\\edge16.bmp");
	card_edge[0][17]=LoadTexture("image_bundle\\edge17.bmp");
	card_edge[0][18]=LoadTexture("image_bundle\\edge18.bmp");
	card_edge[0][19]=LoadTexture("image_bundle\\edge19.bmp");
	card_edge[0][20]=LoadTexture("image_bundle\\edge20.bmp");
	card_edge[0][21]=LoadTexture("image_bundle\\edge21.bmp");
	card_edge[0][22]=LoadTexture("image_bundle\\edge22.bmp");
	card_edge[0][23]=LoadTexture("image_bundle\\edge23.bmp");
	card_edge[0][24]=LoadTexture("image_bundle\\edge24.bmp");
	card_edge[0][25]=LoadTexture("image_bundle\\edge25.bmp");
	card_edge[0][26]=LoadTexture("image_bundle\\edge26.bmp");
	card_edge[0][27]=LoadTexture("image_bundle\\edge27.bmp");
	card_edge[0][28]=LoadTexture("image_bundle\\edge28.bmp");
	card_edge[0][29]=LoadTexture("image_bundle\\edge29.bmp");
	card_edge[0][30]=LoadTexture("image_bundle\\edge30.bmp");
	card_edge[0][31]=LoadTexture("image_bundle\\edge31.bmp");
	card_edge[0][32]=LoadTexture("image_bundle\\edge32.bmp");
	card_edge[0][33]=LoadTexture("image_bundle\\edge33.bmp");
	card_edge[0][34]=LoadTexture("image_bundle\\edge34.bmp");
	card_edge[0][35]=LoadTexture("image_bundle\\edge35.bmp");
	card_edge[0][36]=LoadTexture("image_bundle\\edge36.bmp");
	
	hiddencard_1P=LoadTexture("image_bundle\\hiddencard.bmp");
	hiddencard_edge_1P=LoadTexture("image_bundle\\hiddencard edge.bmp");

	final_select=LoadTexture("image_bundle\\go stop.bmp");
	plus=LoadTexture("image_bundle\\plus.bmp");
	
	loading_game_1P = false;
}

void Loadimage_notice()
{
	notice[0]=LoadTexture("image_bundle\\notice1.bmp");
	notice[1]=LoadTexture("image_bundle\\notice2.bmp");
	notice[2]=LoadTexture("image_bundle\\notice3.bmp");
	notice[3]=LoadTexture("image_bundle\\notice4.bmp");

	loading_notice = false;
}

void Loadimage_game_2P()
{
	back_battlefield_2P=LoadTexture("image_bundle\\battle field 2P.bmp");
	back_battlefield_2P_Sp=LoadTexture("image_bundle\\battle field 2P special.bmp");
	loading_page=LoadTexture("image_bundle\\loading.bmp");

	select_back_1P=LoadTexture("image_bundle\\mode select 1P.bmp");
	select_back_2P=LoadTexture("image_bundle\\mode select 2P.bmp");

	card_bundle[1][1]=LoadTexture("image_bundle\\card37.bmp");
	card_bundle[1][2]=LoadTexture("image_bundle\\card38.bmp");
	card_bundle[1][3]=LoadTexture("image_bundle\\card39.bmp");
	card_bundle[1][4]=LoadTexture("image_bundle\\card40.bmp");
	card_bundle[1][5]=LoadTexture("image_bundle\\card41.bmp");
	card_bundle[1][6]=LoadTexture("image_bundle\\card42.bmp");
	card_bundle[1][7]=LoadTexture("image_bundle\\card43.bmp");
	card_bundle[1][8]=LoadTexture("image_bundle\\card44.bmp");
	card_bundle[1][9]=LoadTexture("image_bundle\\card45.bmp");
	card_bundle[1][10]=LoadTexture("image_bundle\\card46.bmp");
	card_bundle[1][11]=LoadTexture("image_bundle\\card47.bmp");
	card_bundle[1][12]=LoadTexture("image_bundle\\card48.bmp");
	card_bundle[1][13]=LoadTexture("image_bundle\\card49.bmp");
	card_bundle[1][14]=LoadTexture("image_bundle\\card50.bmp");
	card_bundle[1][15]=LoadTexture("image_bundle\\card51.bmp");
	card_bundle[1][16]=LoadTexture("image_bundle\\card52.bmp");
	card_bundle[1][17]=LoadTexture("image_bundle\\card53.bmp");
	card_bundle[1][18]=LoadTexture("image_bundle\\card54.bmp");
	card_bundle[1][19]=LoadTexture("image_bundle\\card55.bmp");
	card_bundle[1][20]=LoadTexture("image_bundle\\card56.bmp");
	card_bundle[1][21]=LoadTexture("image_bundle\\card57.bmp");
	card_bundle[1][22]=LoadTexture("image_bundle\\card58.bmp");
	card_bundle[1][23]=LoadTexture("image_bundle\\card59.bmp");
	card_bundle[1][24]=LoadTexture("image_bundle\\card60.bmp");
	card_bundle[1][25]=LoadTexture("image_bundle\\card61.bmp");
	card_bundle[1][26]=LoadTexture("image_bundle\\card62.bmp");
	card_bundle[1][27]=LoadTexture("image_bundle\\card63.bmp");
	card_bundle[1][28]=LoadTexture("image_bundle\\card64.bmp");
	card_bundle[1][29]=LoadTexture("image_bundle\\card65.bmp");
	card_bundle[1][30]=LoadTexture("image_bundle\\card66.bmp");
    card_bundle[1][31]=LoadTexture("image_bundle\\card67.bmp");
	card_bundle[1][32]=LoadTexture("image_bundle\\card68.bmp");
	card_bundle[1][33]=LoadTexture("image_bundle\\card69.bmp");
	card_bundle[1][34]=LoadTexture("image_bundle\\card70.bmp");
	card_bundle[1][35]=LoadTexture("image_bundle\\card71.bmp");
	card_bundle[1][36]=LoadTexture("image_bundle\\card72.bmp");

	card_edge[1][1]=LoadTexture("image_bundle\\edge37.bmp");
	card_edge[1][2]=LoadTexture("image_bundle\\edge38.bmp");
	card_edge[1][3]=LoadTexture("image_bundle\\edge39.bmp");
	card_edge[1][4]=LoadTexture("image_bundle\\edge40.bmp");
	card_edge[1][5]=LoadTexture("image_bundle\\edge41.bmp");
	card_edge[1][6]=LoadTexture("image_bundle\\edge42.bmp");
	card_edge[1][7]=LoadTexture("image_bundle\\edge43.bmp");
	card_edge[1][8]=LoadTexture("image_bundle\\edge44.bmp");
	card_edge[1][9]=LoadTexture("image_bundle\\edge45.bmp");
	card_edge[1][10]=LoadTexture("image_bundle\\edge46.bmp");
	card_edge[1][11]=LoadTexture("image_bundle\\edge47.bmp");
	card_edge[1][12]=LoadTexture("image_bundle\\edge48.bmp");
	card_edge[1][13]=LoadTexture("image_bundle\\edge49.bmp");
	card_edge[1][14]=LoadTexture("image_bundle\\edge50.bmp");
	card_edge[1][15]=LoadTexture("image_bundle\\edge51.bmp");
	card_edge[1][16]=LoadTexture("image_bundle\\edge52.bmp");
	card_edge[1][17]=LoadTexture("image_bundle\\edge53.bmp");
	card_edge[1][18]=LoadTexture("image_bundle\\edge54.bmp");
	card_edge[1][19]=LoadTexture("image_bundle\\edge55.bmp");
	card_edge[1][20]=LoadTexture("image_bundle\\edge56.bmp");
	card_edge[1][21]=LoadTexture("image_bundle\\edge57.bmp");
	card_edge[1][22]=LoadTexture("image_bundle\\edge58.bmp");
	card_edge[1][23]=LoadTexture("image_bundle\\edge59.bmp");
	card_edge[1][24]=LoadTexture("image_bundle\\edge60.bmp");
	card_edge[1][25]=LoadTexture("image_bundle\\edge61.bmp");
	card_edge[1][26]=LoadTexture("image_bundle\\edge62.bmp");
	card_edge[1][27]=LoadTexture("image_bundle\\edge63.bmp");
	card_edge[1][28]=LoadTexture("image_bundle\\edge64.bmp");
	card_edge[1][29]=LoadTexture("image_bundle\\edge65.bmp");
	card_edge[1][30]=LoadTexture("image_bundle\\edge66.bmp");
	card_edge[1][31]=LoadTexture("image_bundle\\edge67.bmp");
	card_edge[1][32]=LoadTexture("image_bundle\\edge68.bmp");
	card_edge[1][33]=LoadTexture("image_bundle\\edge69.bmp");
	card_edge[1][34]=LoadTexture("image_bundle\\edge70.bmp");
	card_edge[1][35]=LoadTexture("image_bundle\\edge71.bmp");
	card_edge[1][36]=LoadTexture("image_bundle\\edge72.bmp");

	round[0]=LoadTexture("image_bundle\\round0.bmp");
	round[1]=LoadTexture("image_bundle\\round1.bmp");
	round[2]=LoadTexture("image_bundle\\round2.bmp");
	round[3]=LoadTexture("image_bundle\\round3.bmp");
	round[4]=LoadTexture("image_bundle\\round4.bmp");
	round[5]=LoadTexture("image_bundle\\round5.bmp");
	round[6]=LoadTexture("image_bundle\\round6.bmp");
	round[7]=LoadTexture("image_bundle\\round7.bmp");
	round[8]=LoadTexture("image_bundle\\round8.bmp");
	round[9]=LoadTexture("image_bundle\\round9.bmp");

	hiddencard_2P=LoadTexture("image_bundle\\hiddencard2.bmp");
	hiddencard_edge_2P=LoadTexture("image_bundle\\hiddencard edge2.bmp");
	
	loading_sand[0]=LoadTexture("image_bundle\\sand1.bmp");
	loading_sand[1]=LoadTexture("image_bundle\\sand2.bmp");
	loading_sand[2]=LoadTexture("image_bundle\\sand3.bmp");
	loading_sand[3]=LoadTexture("image_bundle\\sand4.bmp");
	loading_sand[4]=LoadTexture("image_bundle\\sand5.bmp");
	loading_sand[5]=LoadTexture("image_bundle\\sand6.bmp");
	loading_sand[6]=LoadTexture("image_bundle\\sand7.bmp");
	loading_sand[7]=LoadTexture("image_bundle\\sand8.bmp");
	loading_sand[8]=LoadTexture("image_bundle\\sand9.bmp");
	loading_sand[9]=LoadTexture("image_bundle\\sand10.bmp");
	loading_sand[10]=LoadTexture("image_bundle\\sand11.bmp");
	loading_sand[11]=LoadTexture("image_bundle\\sand12.bmp");
	loading_sand[12]=LoadTexture("image_bundle\\sand13.bmp");
	loading_sand[13]=LoadTexture("image_bundle\\sand14.bmp");
	loading_sand[14]=LoadTexture("image_bundle\\sand15.bmp");
	loading_sand[15]=LoadTexture("image_bundle\\sand16.bmp");
	loading_sand[16]=LoadTexture("image_bundle\\sand17.bmp");
	loading_sand[17]=LoadTexture("image_bundle\\sand18.bmp");
		
	loading_bar=LoadTexture("image_bundle\\loading bar.bmp");
	block_screen=LoadTexture("image_bundle\\block.bmp");

	loading_game_2P = false;
}

void Loadimage_final()
{
	back_final[0]=LoadTexture("image_bundle\\winner page.bmp");
	back_final[1]=LoadTexture("image_bundle\\winner page_1P.bmp");
	back_final[2]=LoadTexture("image_bundle\\winner page_2P.bmp");

	loading_final = false;
}

void Loadimage_ranking()
{
	back_ranking=LoadTexture("image_bundle\\final page.bmp");

	loading_rank = false;
}