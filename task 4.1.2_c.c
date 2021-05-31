#include <stdio.h>
#include <math.h>

void write_entered_to_file(FILE* F){
    int n;
    printf("n = ");
    scanf("%d", &n);
    int x;
    for(int i=0; i<n; i++){
        printf("x = ");
        scanf("%d", &x);
        fwrite(&x, 1, sizeof(x), F);
    }
    fclose(F);
}

void from_file_to_file(FILE* F, FILE* G){
    int x;
    float root;
    while(!feof(F)){
        fread(&x, 1, sizeof(int), F);
        root = sqrt(x);
        if(root == (int)root){
            fwrite(&x, 1, sizeof(int), G);
        }
    }
    fclose(F);
    fclose(G);
}

void print_file(FILE* F)
{
    int x;
    while(!feof(F)){
        fread(&x, 1, sizeof(int), F);
        printf("x = %d\n", x);
    }
    fclose(F);
}

int main(){

    const char* fname = "F.dat";

    FILE* F = fopen(fname, "wb");
    if(F == NULL){
        fprintf(stderr, "Error open file %s", fname);
        return -1;
    }

    write_entered_to_file(F);

    F = fopen(fname, "rb");
    const char* fname2 = "G.dat";
    FILE* G = fopen(fname2, "wb");

    from_file_to_file(F, G);

    printf("\n");
    G = fopen(fname2, "rb");
    print_file(G);

    fclose(F);
}
