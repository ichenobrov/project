﻿#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <limits.h>
#include <time.h>
#include <conio.h>
#ifdef _DEBUG
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC
#endif

int n = 0, i = 0, j = 0, size1 = 0, size2 = 0, count = 2;
double **m1 = nullptr, **m2 = nullptr, **m = nullptr;
char c = '\0';

int a = 0, b = 0;
void manual()
{
	system("cls");
	printf("----------------------------\n");
	printf("Ввод значений первой матрицы\n");
	printf("----------------------------\n");
	for (i = 0; i < size1; i++)
	{
		printf("%d-я строка:\n", i + 1);
		for (j = 0; j < size2; j++)
		{
			while (scanf_s("%lf%c", &m1[i][j], &c, 1) != 2 || c != '\n') {
				printf("Введите число\n-> ");
				while (getchar() != '\n');
			}
		}
		printf("\n");
	}
	system("cls");
	printf("----------------------------\n");
	printf("Ввод значений второй матрицы\n");
	printf("----------------------------\n");
	for (i = 0; i < size2; i++)
	{
		printf("%d-я строка:\n", i + 1);
		for (j = 0; j < size1; j++)
		{
			while (scanf_s("%lf%c", &m2[i][j], &c, 1) != 2 || c != '\n') {
				printf("Введите число\n-> ");
				while (getchar() != '\n');
			}
		}
		printf("\n");
	}
}
void automat()
{
	system("cls");
	srand(time(NULL));
	for (int i = 0; i < size1; i++)
	{
		for (j = 0; j < size2; j++)
		{
			m1[i][j] = 0.5 * (rand() % 101);

		}
	}
	for (int i = 0; i < size2; i++)
	{
		for (j = 0; j < size1; j++)
		{
			m2[i][j] = 0.5 * (rand() % 101);

		}
	}
	n = 0;
	printf("Готово!\n");
	_getch();
}
void menu1()
{
	for (i = 0; i < size1; i++)
	{
		delete[] m[i];
	}
	delete[] m;

	for (i = 0; i < size1; i++)
	{
		delete[] m1[i];
	}
	delete[] m1;

	for (i = 0; i < size2; i++)
	{
		delete[] m2[i];
	}
	delete[] m2;
	system("cls");
	printf("Введите размер матриц\n");
	printf("-------------------------------------------\n");
	printf("Количество строк 1-й матрицы, столбцов 2-й матрицы : ");
	while (scanf_s("%d%c", &size1, &c, 1) != 2 || c != '\n') {
		printf("Введите целое значение!\n-> ");
		while (getchar() != '\n');
	}
	printf("Количество столбцов 1-й матрицы, строк 2-й матрицы: ");
	while (scanf_s("%d%c", &size2, &c, 1) != 2 || c != '\n') {
		printf("Введите целое значение!\n-> ");
		while (getchar() != '\n');
	}
	m1 = new double*[size1];
	for (i = 0; i < size1; i++)
	{
		m1[i] = new double[size2];
	}
	m2 = new double*[size2];
	for (i = 0; i < size2; i++)
	{
		m2[i] = new double[size1];
	}
	m = new double*[size1];
	for (i = 0; i < size1; i++)
	{
		m[i] = new double[size1];
	}
	system("cls");
	printf("1.Заполнить вручную\n2.Заполнить автоматически\n");
	printf("----------------------------------- \n->");
	while (scanf_s("%d%c", &n, &c, 1) != 2 || c != '\n' || n > 2 || n < 1) {
		printf("Введите номер пункта меню\n-> ");
		while (getchar() != '\n');

	}
	switch (n)
	{
	case 1:
		manual();
		break;
	case 2:
		automat();
		break;
	default:
		break;
	}
}
void menu2()
{
	system("cls");
	if (count != 2)
	{
		printf("Вы не ввели матрицы!\n");
		_getch();
	}
	else
	{
		printf("--------------\n");
		printf("Вывод матриц\n");
		printf("--------------\n");
		printf("Первая матрица\n");
		for (i = 0; i < size1; i++)
		{
			for (j = 0; j < size2; j++)
			{
				printf("\t%.2f", m1[i][j]);
			}
			printf("\n");
		}
		printf("Вторая матрица\n");
		for (i = 0; i < size2; i++)
		{
			for (j = 0; j < size1; j++)
			{
				printf("\t%.2f", m2[i][j]);
			}
			printf("\n");
		}
		printf("-> Назад");
		_getch();
		_getch();
	}
}
void menu3()
{
	system("cls");
	if (count != 2)
	{
		printf("Вы не ввели матрицы!\n");
		_getch();
	}
	else
	{
		printf("--------------------\n");
		printf("Результат вычислений\n");
		printf("--------------------\n");
		printf("Искомая матрица\n");
		for (i = 0; i < size1; i++)
		{
			for (j = 0; j < size1; j++)
			{
				m[i][j] = 0;
				for (int p = 0; p < size2; p++)
					m[i][j] += m1[i][p] * m2[p][j];
			}
		}
		for (i = 0; i < size1; i++)
		{
			for (j = 0; j < size1; j++)
			{
				printf("\t %.2f", m[i][j]);
			}
			printf("\n");
		}
	}
	printf("-> Назад");
	_getch();
	_getch();
}
int main()
{
	do {
		setlocale(LC_ALL, "Russian");
		system("cls");
		printf("--------------------------------------\n");
		printf("Программа для перемножения двух матриц\n");
		printf("--------------------------------------\n");
		printf("1.Ввод значений\n2.Вывод матриц на экран\n3.Вычисление\n\n4.Выход\n");
		printf("--------------------------------------\n-> ");
		while (scanf_s("%d%c", &n, &c, 1) != 2 || c != '\n') {
			printf("Введите номер пункта меню\n-> ");
			while (getchar() != '\n');
		}
		switch (n)
		{
		case 1:
			menu1();
			break;
		case 2:
			menu2();
			break;
		case 3:
			menu3();
			break;
		case 4:
			printf("Спасибо за использование данной гениальной утилиты!!!!!!!!!!!/n");
			break;
		default:
			break;
		}
	} while (n != 4);
	for (i = 0; i < size1; i++)
	{
		delete[] m[i];
	}
	delete[] m;

	for (i = 0; i < size1; i++)
	{
		delete[] m1[i];
	}
	delete[] m1;

	for (i = 0; i < size2; i++)
	{
		delete[] m2[i];
	}
	delete[] m2;
	_CrtDumpMemoryLeaks();
	return 0;
}
