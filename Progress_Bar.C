#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
const int BAR_LENGTH = 50;
const int MAX_TASKS = 5;
typedef struct{
    int id;
    int progress;
    int step;
} Task;
void print_bar(Task tasks);

void clear_screen();
int main(){
    Task tasks[MAX_TASKS];
    srand(time(NULL));

    for (int i = 0; i < MAX_TASKS; i++)
    {
        tasks[i].id = i + 1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 1;
    }

    int incomplete_tasks = 1;
    while (incomplete_tasks)
    {
        incomplete_tasks = 0;
        clear_screen();
        for (int i = 0; i < MAX_TASKS; i++)
        {
            tasks[i].progress += tasks[i].step;
            if (tasks[i].progress > 100)
            {
                tasks[i].progress = 100;
            }
            else if (tasks[i].progress < 100)
            {
                incomplete_tasks = 1;
            }

            print_bar(tasks[i]);
        }
        sleep(1);
    }
    printf("All Tasks are Completed...!");

    return 0;
}

void clear_screen(){
    #ifdef WIN32
    system("cls");
    #else
    system("clear");
    #endif
}

void print_bar(Task tasks){
    int bar_to_show = (tasks.progress * BAR_LENGTH) / 100;
    printf("Task %d : [", tasks.id);
    for (int i = 0; i < BAR_LENGTH; i++)
    {
        if (i < bar_to_show)
        {
            printf("=");
        }else{
            printf(" ");
        }
        
    }
    

    printf("] %d%%\n", tasks.progress);

}
