#include <stdio.h>
#include <math.h>

struct PolinomElement{
    double coef;
    int deg;
    int number;
};

void print_element(struct PolinomElement elem){
    printf("Coef, deg, number - %lf %d %d\n", elem.coef, elem.deg, elem.number);
}

void write_entered_to_file(char *fname, int n){
    FILE* opened = fopen(fname, "wb");
    if(opened == NULL){
        fprintf(stderr, "Error open file %s", opened);
        return -1;
    }

    struct PolinomElement element;
    for(int i=0; i<n; i++){
        printf("coef | deg | polinom-number = ");
        scanf("%lf %d %d", &element.coef, &element.deg, &element.number);
        fwrite (&element, sizeof(struct PolinomElement), 1, opened);
    }
    fclose(opened);
}

void parse_file(char *fname, int number, double coef)
{
    printf("\n");
    char *temp_name = "temp.txt";
    FILE* opened = fopen(fname, "rb");
    FILE* newfile = fopen(temp_name, "wb");
    struct PolinomElement element;
    int counter=0;
    while(!feof(opened)){
        fread(&element, sizeof(struct PolinomElement), 1, opened);
        if(number == counter)
        {
            printf("%d ", counter);
            print_element(element);
            element.coef = coef;
            printf("Modified: \n");
            print_element(element);
        }
        fwrite (&element, sizeof(struct PolinomElement), 1, newfile);
        counter += 1;
    }
    fclose(opened);
    fclose(newfile);

    remove(fname);
    rename(temp_name, fname);
    //print_file(fname);
}


void print_file(char *fname)
{
    printf("\n");
    FILE* opened = fopen(fname, "rb");
    struct PolinomElement element;
    int counter=0;
    while(!feof(opened)){
        fread(&element, sizeof(struct PolinomElement), 1, opened);
        printf("%d ", counter++);
        print_element(element);
    }
    fclose(opened);
    printf("\n");
}

int main(){

    const char* fname = "file.dat";
    int n, elem_number;
    double coef;
    printf("Every N numbers - ");
    scanf("%d", &n);
    write_entered_to_file(fname, n);
    print_file(fname);

    printf("Enter number of element to change and it's new coef - ");
    scanf("%d %lf", &elem_number, &coef);
    parse_file(fname, elem_number, coef);
}
