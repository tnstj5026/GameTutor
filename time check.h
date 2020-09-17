#pragma once

#include <stdio.h>
#include <glut.h>
#include <windows.h>

void First_time_help()
{
	start_time = time(NULL);
	check_time = false;
}

void First_time()
{
	start_time_1 = time(NULL);
	check_time_1 = false;
}

void Second_time()
{
	start_time_2 = time(NULL);
	check_time_2 = false;
}

void Third_time()
{
	start_time_3 = time(NULL);
	check_time_3 = false;
}