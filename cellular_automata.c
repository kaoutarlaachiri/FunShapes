#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEAD '-'
#define ALIVE '#' 
#define LENGTH 100

int cells[LENGTH] = {0};

void init_cells (){
    srand(time(NULL));
    for (size_t i=0; i<LENGTH; i++){
        cells[i] = rand()%2;
        printf("%d",cells[i]);
    } 
    printf("\n");
    }
int apply_rule(int prev, int cell, int nxt) {
    int result = 0;
    if (prev == 0 && cell == 0 && nxt == 0) {
        result = 0;
    } else if (prev == 0 && cell == 0 && nxt == 1) {
        result = 1;
    } else if (prev == 0 && cell == 1 && nxt == 0) {
        result = 1;
    } else if (prev == 0 && cell == 1 && nxt == 1) {
        result = 0;
    } else if (prev == 1 && cell == 0 && nxt == 0) {
        result = 1;
    } else if (prev == 1 && cell == 0 && nxt == 1) {
        result = 1;
    } else if (prev == 1 && cell == 1 && nxt == 0) {
        result = 0;
    } else if (prev == 1 && cell == 1 && nxt == 1) {
        result = 1;
    }
    return result;
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

int* update_cells(const int* cells){
    int* new_cells = (int*)malloc(LENGTH * sizeof(int));
    // int prev_cell = 0;
    // int current_cell = 0;
    // int next_cell = 0;
    // int res = 0;
    if (new_cells == NULL){
        exit(1);
    }
    new_cells[0] = cells[0];
    new_cells[LENGTH-1] = cells[LENGTH-1];
    for (size_t i=1; i<LENGTH-1; i++){
        // prev_cell = cells[i-1];
        // current_cell = cells[i];
        // next_cell = cells[i+1];
        new_cells[i] = apply_rule(cells[i-1], cells[i], cells[i+1]);
    }
    return new_cells;
}
int main(){

    init_cells();
    print_cells(cells);
    for (size_t i=0; i<10; i++){
        int* new_cells = update_cells(cells);
        for (size_t j=0; j< LENGTH; j++){
            cells[j] = new_cells[j];
        }
        print_cells(cells);
        free(new_cells);
    }
    printf("done");
    return 0;
}