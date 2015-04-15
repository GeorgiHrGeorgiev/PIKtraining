#include<stdio.h>
void print();
int main(int argc, char **argv)
{
	double red = atof(argv[1]);
	double green = atof(argv[1]);
	double blue = atof(argv[1]);
	double red1, green1, blue1;
	FILE *fp;
	fp = fopen("red.dat", "rb");
	fread(&red1, sizeof(double), 1, fp);
	fclose(fp);
	fp = fopen("green.dat", "rb");
	fread(&green1, sizeof(double), 1, fp);
	fclose(fp);
	fp = fopen("blue.dat", "rb");
	fread(&blue1, sizeof(double), 1, fp);
	fclose(fp);
	if (red1 >= red && green1 >= green && blue1 >= blue)
	{
		red1 -= red;
		green1 -= green;
		blue1 -= blue;
	
		fp = fopen("red.dat", "rb");
		fwrite(&red1, sizeof(double), 1, fp);
		fclose(fp);
		
		fp = fopen("green.dat", "rb");
		fwrite(&green1, sizeof(double), 1, fp);
		fclose(fp);
	
		fp = fopen("blue.dat", "rb");
		fwrite(&blue1, sizeof(double), 1, fp);
		fclose(fp);
	}
	else printf("can't print");
}
void print()
{
	printf("OK");
}
