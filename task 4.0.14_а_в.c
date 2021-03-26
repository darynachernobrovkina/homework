#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3

struct Person
{
    char gender[10];
    int height;
};

struct Person enter_person()
{
    struct Person person;
    printf("Enter gender (male, female) - ");
    scanf("%s", person.gender);
    printf("Enter person height - ");
    scanf("%d", &person.height);
    return person;
}

void display(struct Person person)
{
    printf("\nGender: %s\n", person.gender);
    printf("Height: %d\n", person.height);
}

double medium_female_height(struct Person *people)
{
    int counter=0;
    double summ=0;
    for(int i=0; i<N; i++){
        if(!strcmp(people[i].gender, "female")){
            summ += people[i].height;
            counter += 1;
        }
    }
    return summ / counter;
}

bool is_equal_height(struct Person first, struct Person second)
{
    if(first.height == second.height)
        return true;
    else return false;
}

int main(){

    struct Person *people = calloc(N, sizeof(struct Person));
    for(int i=0; i<N; i++){
        people[i] = enter_person();
    }
    printf("\n");
    for(int i=0; i<N; i++){
        display(people[i]);
        if(i != N-1)
            printf("Equal height with next person - %d\n", is_equal_height(people[i], people[i+1]));
    }

    printf("\nMedium female height - %lf", medium_female_height(people));
    return 0;
}
