#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void selectingcard_1P_27()
{
	srand((unsigned)time(NULL));
	
	if(loading_card[0])
	{
		for(i=1; i<10; i++)
		{
			random_number[0][i]=(rand()%26)+1;
			for(k=1; k<i; k++)
				if(random_number[0][i]==random_number[0][k])
				{
					random_number[0][i]=(rand()%26)+1;
					k=0;
				}
		}

		for(i=1;i<10;i++)
			select_card[0][i] = card_bundle[0][random_number[0][i]];
		
		loading_card[0] = 0;
	}
}

void selectingcard_1P_36()
{
	srand((unsigned)time(NULL));
	
	if(loading_card[0])
	{
		for(i=1; i<10; i++)
		{
			random_number[0][i]=(rand()%35)+1;
			for(k=1; k<i; k++)
				if(random_number[0][i]==random_number[0][k])
				{
					random_number[0][i]=(rand()%35)+1;
					k=0;
				}
		}

		for(i=1;i<10;i++)
			select_card[0][i] = card_bundle[0][random_number[0][i]];
		
		loading_card[0] = 0;
	}
}

void selectingcard_2P_36()
{
	srand((unsigned)time(NULL)+1);
	
	if(loading_card[1])
	{
		for(i=1; i<10; i++)
		{
			random_number[1][i]=(rand()%35)+1;
			for(k=1; k<i; k++)
				if(random_number[1][i]==random_number[1][k])
				{
					random_number[1][i]=(rand()%35)+1;
					k=0;
				}
		}

		for(i=1;i<10;i++)
			select_card[1][i] = card_bundle[1][random_number[1][i]];
		
		loading_card[1] = 0;
	}
}

int matching_check(int number1, int number2, int number3)
{
	int count = 0;
	int a[3],a_1[3],a_2[3],a_3[3];

	a[0] = number1;
	a[1] = number2;
	a[2] = number3;

	for(m=0;m<3;m++)
		a_1[m] = a[m]%3;

	for(n=0;n<3;n++)
	{
		if(1<=a[n] && a[n]<=9 || 28<=a[n] && a[n]<=30)
			a_2[n] = 1;
		else if(10<=a[n] && a[n]<=18 || 31<=a[n] && a[n]<=33)
			a_2[n] = 2;
		else
			a_2[n] = 3;
	}

	for(p=0;p<3;p++)
	{
		if((1<=a[p] && a[p]<=3) || (10<=a[p] && a[p]<=12) || (19<=a[p] && a[p]<=21))
			a_3[p] = 1;
		else if((4<=a[p] && a[p]<=6) || (13<=a[p] && a[p]<=15) || (22<=a[p] && a[p]<=24))
			a_3[p] = 2;
		else if((7<=a[p] && a[p]<=9) || (16<=a[p] && a[p]<=18) || (25<=a[p] && a[p]<=27))
			a_3[p] = 3;
		else
			a_3[p] = 4;
	}

	if(a_1[0] == a_1[1])
	{
		if(a_1[1] == a_1[2])
		{
			if(a_2[0] == a_2[1])
			{
				if(a_2[1] == a_2[2])
				{
					if(a_3[0] == a_3[1])
					{
						if(a_3[1] == a_3[2])
							count+=1;
					}
					else
					{
						if(a_3[1] != a_3[2] && a_3[0] != a_3[2])
							count+=1;
					}
				}
			}
			else
			{
				if(a_2[1] != a_2[2] && a_2[0] != a_2[2])
				{
					if(a_3[0] == a_3[1])
					{
						if(a_3[1] == a_3[2])
							count+=1;
					}
					else
					{
						if(a_3[1] != a_3[2] && a_3[0] != a_3[2])
							count+=1;
					}
				}
			}
		}
	}

	else
	{
		if(a_1[1] != a_1[2] && a_1[0] != a_1[2])
		{
			if(a_2[0] == a_2[1])
			{
				if(a_2[1] == a_2[2])
				{
					if(a_3[0] == a_3[1])
					{
						if(a_3[1] == a_3[2])
							count+=1;		
					}
					else
					{
						if(a_3[1] != a_3[2] && a_3[0] != a_3[2])
							count+=1;
					}
				}
			}
			else
			{
				if(a_2[1] != a_2[2] && a_2[0] != a_2[2])
				{
					if(a_3[0] == a_3[1])
					{
						if(a_3[1] == a_3[2])
							count+=1;
					}
					else
					{
						if(a_3[1] != a_3[2] && a_3[0] != a_3[2])
							count+=1;
					}
				}
			}
		}
	}

	return count;
}

void total_calculation()
{
	if(total_checking)
	{
		for(i=1;i<8;i++)
			for(k=i+1;k<9;k++)
				for(j=k+1;j<10;j++)
				{
					total_matching[0] += matching_check(random_number[0][i],random_number[0][k],random_number[0][j]);
					total_matching[1] += matching_check(random_number[1][i],random_number[1][k],random_number[1][j]);
				}
	}

	total_checking = false;
}

void selecting_picture()
{
	if((x_1[player][0] != 0)&&(y_1[player][0] != 0))
	{
		for(x[player][0]=0;x[player][0]<3;x[player][0]++)
			for(y[player][0]=0;y[player][0]<3;y[player][0]++)
				if((x_1[player][0] == (442+212*x[player][0]))&&(y_1[player][0] == (124+170*y[player][0])))
				{
					temp_choose = random_number[player][(3*x[player][0])+y[player][0]+1];
					goto skip;
				}

skip:

		for(i=0;i<=Load_number[player];i++)
		{
			if(choose[player][i] == temp_choose)
			{
				if(((i == 1)&&(Load_number[player] == 1))||((i == 2)&&(Load_number[player] == 2)))
				{
					Load_number[player] -= 1;
					choose[player][i] = 0;
					x_1[player][i] = y_1[player][i] = x[player][i] = y[player][i] = x_1[player][0] = y_1[player][0] = 0;
				}
				else if((i == 1)&&(Load_number[player] == 2))
				{
					Load_number[player] -= 1;
					choose[player][1] = choose[player][2];
					choose[player][2] = 0;
					x_1[player][1] = x_1[player][2];
					y_1[player][1] = y_1[player][2];
					x[player][1] = x[player][2];
					y[player][1] = y[player][2];
					x_1[player][2] = y_1[player][2] = x[player][2] = y[player][2] = x_1[player][0] = y_1[player][0] = 0;
				}
				break;
			}
			else if(i == Load_number[player])
			{
				Load_number[player] += 1;
				choose[player][Load_number[player]] = temp_choose;
				x_1[player][Load_number[player]] = x_1[player][0];
				y_1[player][Load_number[player]] = y_1[player][0];
				x[player][Load_number[player]] = x[player][0];
				y[player][Load_number[player]] = y[player][0];
				x_1[player][0] = y_1[player][0] = 0;
				break;
			}
		}
	}
}

void arrange_and_coordinate()
{
	for(s=1;s<4;s++)
		w[player][s] = 3*x[player][s]+y[player][s]+1;

	for(u=1;u<3;u++)
	{
		for(r=u+1;r<4;r++)
		{
			if(w[player][u] < w[player][r])
			{
				temp = w[player][u];
				w[player][u] = w[player][r];
				w[player][r] = temp;

				temp = choose[player][u];
				choose[player][u] = choose[player][r];
				choose[player][r] = temp;

				temp = x[player][u];
				x[player][u] = x[player][r];
				x[player][r] = temp;

				temp = y[player][u];
				y[player][u] = y[player][r];
				y[player][r] = temp;

				temp = x_1[player][u];
				x_1[player][u] = x_1[player][r];
				x_1[player][r] = temp;

				temp = y_1[player][u];
				y_1[player][u] = y_1[player][r];
				y_1[player][r] = temp;
			}
		}
	}
}

void initialization()
{
	temp = 0;	
	Load_number[player] = 0;	
	w[player][0] = w[player][1] = w[player][2] = w[player][3] = 0;
	x[player][0] = x[player][1] = x[player][2] = x[player][3] = 0;	
	y[player][0] = y[player][1] = y[player][2] = y[player][3] = 0;
	x_1[player][0] = x_1[player][1] = x_1[player][2] = x_1[player][3] = 0;
	y_1[player][0] = y_1[player][1] = y_1[player][2] = y_1[player][3] = 0;
	choose[player][0] = choose[player][1] = choose[player][2] = choose[player][3] = 0;
}