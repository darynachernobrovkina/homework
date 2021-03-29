#include <stdio.h>
#include <math.h>

float count_area(float mas[5])
{
    return (mas[3] - mas[1]) * (mas[2] - mas[4]);
}

void find_max_area(char *fname){
    FILE* F = fopen(fname, "rb");
    float mas[5];
    float max_area=0;
    while(!feof(F)){
        fread(&mas, 5, sizeof(float), F);
        float area = count_area(mas);
        if(max_area < area)
            max_area = area;
        printf("%f (%.2f, %.2f) (%.2f, %.2f) - area: %.2f\n", mas[0], mas[1], mas[2], mas[3], mas[4], area);
    }
    printf("Max - %.2f", max_area);
    fclose(F);
}

void write_entered_to_file(char *fname){
    FILE* F = fopen(fname, "wb");
    if(F == NULL){
        fprintf(stderr, "Error open file %s", fname);
        return -1;
    }
    float mas[5];
    int n;
    printf("Number of rectangles - ");
    scanf("%d", &n);
    printf("Enter rectangle's number, coords of left top and right bottom points: \n");
    // int x;
    for(int i=0; i<n; i++){
        printf("data = ");
        scanf("%f %f %f %f %f", &mas[0], &mas[1], &mas[2], &mas[3], &mas[4]);
        fwrite(&mas, 5, sizeof(float), F);
    }
    fclose(F);
}

void print_file(char *fname)
{
    FILE* F = fopen(fname, "rb");
    float mas[5];
    while(!feof(F)){
        fread(&mas, 5, sizeof(float), F);
        printf("%f (%f, %f) (%f, %f)\n", mas[0], mas[1], mas[2], mas[3], mas[4]);
    }
    fclose(F);
}

int main(){

    const char* fname = "F.dat";
    const char* fname2 = "G.dat";
    write_entered_to_file(fname);

    find_max_area(fname);
    //from_file_to_file(fname, fname2);

    printf("\n");
    //print_file(fname);
    //print_file(fname2);
}
