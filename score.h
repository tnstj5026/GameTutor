#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void data_read()
{
	for(k=0,i=0;;k++)
	{
		fscanf(rankname,"%d",&temp);
			
		if(temp == 40)
		{
			++i;
			k=-1;
			if(i == 8)
				break;
			else
				continue;
		}

		rank_name[i][k] = temp;
	}

	for(i=0;i<8;i++)
	{		
		fscanf(rankscore,"%d",&temp);
		rank_score[i] = temp;
	}

	for(i=0;i<8;i++)
	{		
		fscanf(rankposition,"%d",&temp);
		rank_pos[i] = temp;
	}
}

void data_arrage()
{
	for(i=0;i<8;i++)
	{
		if(total_score > rank_score[i])
		{
			for(k=7;k>i;k--)
			{
				rank_score[k] = rank_score[k-1];
				rank_pos[k] = rank_pos[k-1];
				
				for(j=0;j<rank_pos[k-1];j++)
					rank_name[k][j] = rank_name[k-1][j];				
			}

			rank_score[i] = total_score;
			rank_pos[i] = position[0];
			
			for(j=0;j<position[0];j++)
				rank_name[i][j] = key_number[0][j];

			break;
		}
	}
}

void data_write()
{
	for(i=0;i<8;i++)
	{
		for(k=0;k<rank_pos[i];k++)
			fprintf(rankname,"%d\n",rank_name[i][k]);

		fprintf(rankname,"%d\n",40);
	}
	
	for(i=0;i<8;i++)
	{		
		fprintf(rankscore,"%d\n",rank_score[i]);
	}

	for(i=0;i<8;i++)
	{		
		fprintf(rankposition,"%d\n",rank_pos[i]);
	}
}

void data_easy()
{
	rankname = fopen("data\\name easy.txt","rt");
	rankscore = fopen("data\\score easy.txt","rt");
	rankposition = fopen("data\\position easy.txt","rt");
	
	data_read();

	fclose(rankname);
	fclose(rankscore);
	fclose(rankposition);

	data_arrage();

	rankname = fopen("data\\name easy.txt","wt");
	rankscore = fopen("data\\score easy.txt","wt");
	rankposition = fopen("data\\position easy.txt","wt");

	data_write();

	fclose(rankname);
	fclose(rankscore);
	fclose(rankposition);

	load_data_easy = false;
}

void data_hard()
{
	rankname = fopen("data\\name hard.txt","rt");
	rankscore = fopen("data\\score hard.txt","rt");
	rankposition = fopen("data\\position hard.txt","rt");
	
	data_read();

	fclose(rankname);
	fclose(rankscore);
	fclose(rankposition);

	data_arrage();

	rankname = fopen("data\\name hard.txt","wt");
	rankscore = fopen("data\\score hard.txt","wt");
	rankposition = fopen("data\\position hard.txt","wt");

	data_write();

	fclose(rankname);
	fclose(rankscore);
	fclose(rankposition);

	load_data_hard = false;
}

void score_display()
{
	for(i=0;i<8;i=i+2)
	{
		for(k=0;k<rank_pos[i];k++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard_black[rank_name[i][k]]);
			drawDisplay(25, 25, 125+26*k, 180+135*(i/2));
		}
			
		if(rank_score[i] >= 100)
		{			
			glBindTexture(GL_TEXTURE_2D,word[rank_score[i]/100]);
			drawDisplay(40, 40, 400, 218+133*(i/2));
		}
		if(rank_score[i] >= 10)
		{
			glBindTexture(GL_TEXTURE_2D,word[(rank_score[i]%100)/10]);
			drawDisplay(40, 40, 440, 218+133*(i/2));
		}
		glBindTexture(GL_TEXTURE_2D,word[rank_score[i]%10]);
		drawDisplay(40, 40, 480, 218+133*(i/2));
	}

	for(i=1;i<8;i=i+2)
	{
		for(k=0;k<rank_pos[i];k++)
		{
			glBindTexture(GL_TEXTURE_2D,keyboard_black[rank_name[i][k]]);
			drawDisplay(25, 25, 680+26*k, 180+132*(i/2));
		}

		if(rank_score[i] >= 100)
		{			
			glBindTexture(GL_TEXTURE_2D,word[rank_score[i]/100]);
			drawDisplay(40, 40, 990, 218+133*(i/2));
		}
		if(rank_score[i] >= 10)
		{
			glBindTexture(GL_TEXTURE_2D,word[(rank_score[i]%100)/10]);
			drawDisplay(40, 40, 1030, 218+133*(i/2));
		}
		glBindTexture(GL_TEXTURE_2D,word[rank_score[i]%10]);
		drawDisplay(40, 40, 1070, 218+133*(i/2));
	}
}