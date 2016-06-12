#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "rep.h"

int i, j, k, s;
char *ptr[20];
char first_ch, delim;
char str[261];

void input() 
{
	int i;
	char ch[500];
	printf("Введите путь:");
	fgets(ch, 500, stdin);
	if(slen(ch) > 261) {
		printf("\nПревышение допустимой длины пути...");
		exit(1);
	}
	else {
		for (i = 0; i < slen(ch); i++)
			str[i] = ch[i];
		printf("Входная строка: %s\n\n", str);
	}
	printf("Входная строка: %s\n\n", str); 
}

void check() 
{
	sspn(str); // Проверка на недопустимые символы
	printf("\n");
}

void process () 
{
									/* Определение ОС */
	int f;	
	first_ch = str[0];
	if (first_ch == '/') {
		printf("ОС: Linux\n");
		delim = '/';
		f = 1;
	}
	if (isLowCase(first_ch) == 1 || isHighCase(first_ch) == 1) {
		printf("ОС: Windows\n");
		delim = '\\';
		f = 1;
	}
	if (f == 0) {
		printf("Ошибочный путь\n");
		exit(1);
	}
	i = stok(str, delim, ptr);
	printf("Количество каталогов с учетом конечного файла: %d\n", i);
	printf("Конечный файл: %s\n", ptr[i-1]);
	s = slen(ptr[i-1]);
	printf("Длина конечного файла: %d\n\n", s - 1);
	for(k = 0; k < i; k++) {
		if (minus(ptr[k]) == 0) 
		if (isCase(ptr[k]) == 0){		
		if (atoi(ptr[k]) == 0 || atoi(ptr[k]) < 0 || atoi(ptr[k]) > 0) {
			j = atoi(ptr[k]) + 1;
			printf("Числовой каталог, который нужно увеличить на 1: <%d каталог> = %d\n", k+1, j); 
			if (((j - 1) % 1000 == 999 || (j - 1) % 1000 == 99 || (j - 1) % 1000 == 9) && ((j - 1) % 100 == 99 || (j - 1) % 100 == 9) && ((j - 1) % 10 == 9)) {
				printf("Нужно свдинуть строку на 1 вправо, начиная с %d каталога\n", k+1); 
				sdvig(str, k + 1, i, delim, ptr);
			}
			change(ptr[k], j);
		}
		}	
	}
	suntok(str ,delim, ptr, i);
}

void output() 
{
	printf("\nОбновленная строка: %s\n", str);
}

int isCase(char *s) {
	int i, f = 0;
	for (i = 0; i < slen(s); i++) 
		if (isLowCase(s[i]) == 1 || isHighCase(s[i]) == 1)
		 	f = 1;
	if (f == 1)
		return 1;
	return 0;
}

void sdvig(char *s, int j, int i, char delim, char *ptr[])
{
	char *suf = s;
	int idx = ptr[j] - suf;
	int m;

	// Сдвиг строки
	for (m = 261; m > idx-1; m--)
		s[m + 1] = s[m];
	
	// Сдвиг укозателя
	for (m = j; m < i; m++)
		ptr[m] = ptr[m] + 1;
}


void change(char *s, int k) // Замена каталога <n> на <n + 1>
{
	char* c;
	c = (char *)malloc(10 * sizeof(char));
	int i, v = 0; // Кол-во чисел в числе n
	
	// Разбираем на отдельные символы число n
	while (k > 9) {
		c[v++] = (k % 10) + '0';
		k = k / 10;
	}
	c[v++] = k + '0';
	c[v] = '\0';
	char t;

	// Инвертирование массива символов
	for (i = 0; i < v / 2; i++) {
		t = c[i];
		c[i] = c[v - 1 - i];
		c[v - 1 - i] = t;
	}
	v = 0;
	for (v=0; c[v] != '\0'; v++)
		s[v] = c[v];
	free(c);
}


int isLowCase(char ch) // Принадлежность к латинским буквам нижнего регистра
{
	if( ch >= 'a' && ch <= 'z')
		return 1;
	return 0;
}


int isHighCase(char ch) // Принадлежность к латинским буквам верхнего регистра
{
	if( ch >= 'A' && ch <= 'Z')
		return 1;
	return 0;
}

int puti (char *s)
{
	if ( s[i] <= 2)
		return 1;
	return 0;
}

int slen(char *s) //Длина строки 
{
	int i;
	for (i = 0; s[i] != '\0'; i++);
		return i;
}


int stok(char *s, char delim, char *ptr[]) // Разбиение строки на подстроки
{
	char *suf = s;
	ptr[0] = s;
	int i, j = 1;
	while( ( i = schr(suf, delim) ) >= 0 ){
		suf[i] = '\0';
		suf = suf + i + 1;
		ptr[j] = suf;
		j++;
	}
	return j;
}


int schr(char *s, char delim) // Поиск символа в строке
{
	int i, idx = -1;
	for(i = 0; (s[i] != '\0') && (s[i] != delim); i++);
		if(s[i] == delim)
			idx = i;
		return idx;
}


void sspn(char *s) // Проверка строки на недопустимые симвыло
{
	int i;
	for(i = 0; s[i] != '\0'; i++)
		if (s[i] == '*' || s[i] == '&' || s[i] == '?' || s[i] == '|' || s[i] == '"' || s[i] == '<' || s[i] == '>' || s[i] == ';' || s[i] == '$' || s[i] == '#' || s[i] == '@' || s[i] == '^' || s[i] == '(' || s[i] == ')' || s[i] == '\0' || s[i] == '%') {
			fprintf(stderr, "Недопустимый символ <%c> на позиции <%d>;", s[i], i);
			printf("\n");
		}
}


int sequal(char *s1, char *s2) // Сравнение строк
{
	int i, out = 1;
	for(i = 0; out && (s1[i] != '\0' && s2[i] != '\0'); i++)
		if (s1[i] != s2[i]){
			out = 0;
			return out;
		}
	return out;
}


void scopy(char *s1, char *s2) // Копирование строки
{
	int i;
	for(i = 0; (s1[i] != '\0' && s2[i] != '\0'); i++)
		s2[i] = s1[i];
}


void suntok(char *s, char delim, char *ptr[], int cnt) // Собирание строки
{
	int i;
	for(i = 1; i < cnt; i++)
		*(ptr[i] - 1) = delim;
}

int minus(char *s) 
{
	int i, f = 0;
	for (i = 0; i < slen(s); i++) 
		if (s[i] == '-')		
		f = 1;
	if (f == 1)
		return 1;
	return 0;
}	

