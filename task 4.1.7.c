#include <stdio.h>
#include <math.h>

void write_entered_to_file(char *fname){
    FILE* F = fopen(fname, "wb");
    if(F == NULL){
        fprintf(stderr, "Error open file %s", fname);
        return -1;
    }
    int n;
    printf("numbers = ");
    scanf("%d", &n);
    int x;
    for(int i=0; i<n; i++){
        printf("x = ");
        scanf("%d", &x);
        fwrite(&x, 1, sizeof(x), F);
    }
    fclose(F);
}

void from_file_to_file(char *fname_f, char *fname_g, int n){
    FILE* first = fopen(fname_f, "rb");
    FILE* second = fopen(fname_g, "wb");
    int x, maxx;

    while(!feof(first)){
        for(int i=0; i<n; i++)
        {
            fread(&x, 1, sizeof(int), first);
            if(i==0){
                maxx = x;
            }
            if(x > maxx){
                maxx = x;
            }
        }
        fwrite(&maxx, 1, sizeof(int), second);

    }
    fclose(first);
    fclose(second);
}

void print_file(char *fname)
{
    printf("\n");
    FILE* F = fopen(fname, "rb");
    int x;
    while(!feof(F)){
        fread(&x, 1, sizeof(int), F);
        printf("x = %d\n", x);
    }
    fclose(F);
    printf("\n");
}

int main(){

    const char* fname = "F.dat";
    const char* fname2 = "G.dat";
    int n;
    printf("Every N numbers - ");
    scanf("%d", &n);
    write_entered_to_file(fname);

    from_file_to_file(fname, fname2, n);

    print_file(fname);
    print_file(fname2);
}
