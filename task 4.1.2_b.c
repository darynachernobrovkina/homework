#include <stdio.h>
#include <math.h>

int main(){

    const char* fname = "F.dat";

    FILE* F = fopen(fname, "wb");
    if(F == NULL){
        fprintf(stderr, "Error open file %s", fname);
        return -1;
    }

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

    F = fopen(fname, "rb");

    const char* fname2 = "G.dat";

    FILE* G = fopen(fname2, "wb");

    while(!feof(F)){
        fread(&x, 1, sizeof(int), F);
        if(x % 3 == 0 && x % 5 == 0){
            fwrite(&x, 1, sizeof(x), G);
        }

    }

    fclose(F);
    fclose(G);

    printf("\n");
    G = fopen(fname2, "rb");
    while(!feof(G)){
        fread(&x, 1, sizeof(int), G);
        printf("G:x = %d\n", x);
    }
    fclose(G);

    fclose(F);
}
