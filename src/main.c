#include <stdio.h>
#include <stdlib.h>
#include "rep.h"

int i; 
char *ptr[20];
char first_ch, delim;
//char str[261] = "C:\\home\\qwert\\999\\openmpi\\165\\lib\OpenMPI\\mca_btl_tcp.so"; // windows
//char str[261] = "/home/qwert/9/openmpi/165/lib/OpenMPI/mca_btl_tcp.so"; // linux
char str[261];

int main() 
{
	//setlocale(LC_ALL, "Russian");
	input();
	check();
	process();
	suntok(str, delim, ptr, i);
	output();
	return 0;
}
