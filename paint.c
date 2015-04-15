#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	FILE *fp;
	int count;
	char *colorNumber, *colorName;
	double red, green, blue;
	while (!feof(fp))
	{
		fp = fopen("colors.dat", "rb");
		fread(&count, sizeof(int), 1, fp);
		colorNumber = (char*)malloc(sizeof(char)*count);
		fread(colorNumber, sizeof(char), count, fp);
		fread(&count, sizeof(int), 1, fp);
		colorName = (char*)malloc(sizeof(char)*count);
		fread(colorName, sizeof(char), count, fp);
		fread(&red, sizeof(double), 1, fp);
		fread(&green, sizeof(double), 1, fp);
		fread(&blue, sizeof(double), 1, fp);
		if (!strcmp(argv[1], colorNumber))
		{
			char buffer[50];
			sprintf(buffer, "start.exe %lf %lf %lf", red*atoi(argv[2]), green*atoi(argv[2]), blue*atoi(argv[2]));
			system(buffer);
			break;
		}
		fclose(fp);
	}
}