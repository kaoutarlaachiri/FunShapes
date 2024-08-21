#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define DEAD ' '
#define ALIVE '*' 
#define LENGTH 50
#define HEIGHT 15
/*
This code implements cellular automata where the user gives input  the number of the rule (256)
The code then prints the cellular automata
*/
int cells[LENGTH] = {0};

int convert_binary_to_decimal(int prev, int current, int next){
    //decimal = prev*pow(2,2)+current*pow(2,1)+next*pow(2,0);
    return prev*4+current*2+next*1;
}

void print_cells(const int* cells) {
    for (size_t i=0; i<LENGTH; i++){
        if (cells[i] == 0){
            printf("%c",DEAD);
        }else {
            printf("%c",ALIVE);
        }
    }
    printf("\n");
}


int main(){

    // init_cells();
    int rule;
    int rule_bin[8] = {0};
    printf("Enter Rule Number ---> ");
    scanf("%d", &rule);
    int i=0;
    //convert rule to binary
    while(rule > 0){
        rule_bin[i] = rule % 2;
        rule = rule/2;
        i++;
    }

    cells[LENGTH/2] = 1;
    print_cells(cells);
    for (size_t i=0; i<HEIGHT; i++){
        // int new_cells[LENGTH] = {0};
        int new_cells[LENGTH] = {0};
        new_cells[0] = cells[0];
        new_cells[LENGTH-1] = cells[LENGTH-1];
        
        for (size_t i=1; i<LENGTH-1; i++){
            int decimal = 0;
            decimal = convert_binary_to_decimal(cells[i-1], cells[i], cells[i+1]);
            new_cells[i] = rule_bin[decimal];
        }
    
        for (size_t j=0; j< LENGTH; j++){
            cells[j] = new_cells[j];
        }
        print_cells(cells);
    }
    return 0;
}