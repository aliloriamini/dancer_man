#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define arrownum 2000

int n = 1;
int time_game = 60;
int d_time = 60;
int game_size_x = 15,game_size_y = 20;
int y_arrow;
int score = 0;
int score_shows = 0;
int x_arrow =0;
int arrow_num[arrownum];
int arrow_input;
int arrow_sign;
int pl_num = 10;
char player_name[80];
int f=0,g=1;
int game_speed = 1000;
int c_t = 1000 ;
int df = 1;
struct student
{
    int rollno;
    char name[80];
    int marks;
}data[20];

int menu_input(int menu_number,int len);
void input_name(char player_name[]);
void game_place();
void gotoxy(int x,int y);
void earth();
void human();
void score_show(char player_name[],int score_shows);
void random();
void random_choose(int random_number);
void arrow_maker(char player_name[]);
void Marker_up();
void Marker_down();
void Marker_left();
void Marker_right();
void key_check(char player_name[]);
void game_over();
void game_timing();
void waitFor (unsigned int secs);
void bsortDesc(struct student list[], int score_1, char player_name[],int pl_num);
void bsortDesc_show(struct student list[],int pl_num);
void menu();
static int get_code(void);

enum
    {
        ARROW_UP    = 256 + 72,
        ARROW_DOWN  = 256 + 80,
        ARROW_LEFT  = 256 + 75,
        ARROW_RIGHT = 256 + 77
    };

int main()
{
    srand(time(0));
    menu();
    getch();
    return 0;
}

void menu(){
    y_arrow = game_size_y -2;
    int menu_number;
    printf("\n  1.start\n  2.high scores\n  3.setting\n  4.exit\n");
    menu_number = menu_input(menu_number,4);
    system("cls");
    time_game = d_time;
    if(menu_number == 1){
        printf("choose difficulty:\n  1.easy\n  2.medium\n  3.hard");
        int d_f= menu_input(menu_number,3);
        switch(d_f){
            case 2 :
            game_speed = game_speed /2;
            df = 2;
            break;
            case 3 :
            game_speed = game_speed /3;
            df = 3;
            break;
        }
        system("cls");
        input_name(player_name);
        system("cls");
        game_place();
        earth();
        human();
        score_show(player_name,score);
        arrow_maker(player_name);
        system("cls");
        bsortDesc(data,score_shows,player_name,pl_num);
    }

    if(menu_number == 2){
        bsortDesc_show(data,pl_num);
    }
    if (menu_number == 3){
        int s_c,num;
        printf("what you want change?\n  1.size\n  2.game time\n  3.top_player shows\n  4.game speed\n  5.color\n");
        s_c = menu_input(menu_number,5);
        system("cls");
        switch(s_c){
            case 1 :
            printf("enter width of game :\t");
            scanf("%d",&game_size_x);
            printf("\nenter hight of game :\t");
            scanf("%d",&game_size_y);
            break;
            case 2 :
            printf("enter time of game :\t");
            scanf("%d",&d_time);
            break;
            case 3 :
            printf("enter how many top player shows :\t");
            scanf("%d",&pl_num);
            break;
            case 4 :
            printf("enter speed of game :\t");
            scanf("%d",&game_speed);
            break;
            case 5 :
                printf("which color you want for background and text (for no change type 0):\n");
                printf("  1. background --> GREEN & text color --> BLUE\n");
                printf("  2. background --> RED & text color --> BLACK\n");
                printf("  3. background --> WHITE & text color --> BLACK\n");
                printf("  4. background --> YELLOW & text color --> WHITE\n");
                num = menu_input(menu_number,4);
                    switch(num){
                        case 1:
                            system("COLOR 21");
                        break;
                        case 2:
                            system("COLOR 40");
                        break;
                        case 3:
                            system("COLOR F0");
                        break;
                        case 4:
                            system("COLOR EF");
                        break;
                        default :
                            system("COLOR 0F");
                        break;
		}
        }
            system("cls");
            menu();
    }
    if (menu_number == 4){
        thx();
        exit("true");
    }
}

int menu_input(int menu_number,int len){
    menu_number=1;
    gotoxy(0,menu_number);
    printf(">");
    while(1>0){
           int ch;
            ch = get_code();
                switch (ch)
                {
                case ARROW_UP:
                    if(menu_number>1){
                    gotoxy(0,menu_number);
                    printf(" ");
                    menu_number--;
                    gotoxy(0,menu_number);
                    printf(">");
                    }
                    break;
                case ARROW_DOWN:
                    if(menu_number<len){
                    gotoxy(0,menu_number);
                    printf(" ");
                    menu_number++;
                    gotoxy(0,menu_number);
                    printf(">");
                    }
                    break;
                case 13:
                    return menu_number;
                }
            }
}
void input_name(char player_name[]){
        printf("enter your name:\n");
        scanf("%s",player_name);
}
void gotoxy(int x,int y){
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void game_place(){
    int i,j;
            gotoxy(15,5);
                for(i=0;i<game_size_x;i++) printf("%c%c%c",219,219,219);
                for(j=0;j<game_size_y;j++) {
                        gotoxy(15,j+5);
                        printf("%c%c",219,219);}
                for(j=0;j<=game_size_y;j++) {
                        gotoxy(15+3*(game_size_x),j+5);
                        printf("%c%c",219,219);}
                gotoxy(15,game_size_y+5);
                for(i=0;i<game_size_x;i++) printf("%c%c%c",219,219,219);
}
void earth(){
    int i,j;
    for(i=0;i<n;i++){
        gotoxy(17,game_size_y+4-i);
        for(j=0;j<3*(game_size_x)-2;j++)
            printf("%c",177);
    }
    game_size_y=game_size_y - i +1;
}

void human(){
    gotoxy(15+5,game_size_y-2);
      printf("___");
    gotoxy(15+4,game_size_y-1);
    printf("/0.0\\");
    gotoxy(15+4,game_size_y);
      printf(" ***");
    gotoxy(15+4,game_size_y+1);
    printf("/| |\\");
    gotoxy(15+4,game_size_y+2);
      printf(" | |");
    gotoxy(15+4,game_size_y+3);
    printf("/   \\");
}
void score_show(char player_name[],int score_shows){
    gotoxy(18,6);
    puts(player_name);
    gotoxy(18,7);
    printf("score :%d",score_shows);
}
int randoms(){
  int random_number = rand() % 4 + 1;
  return random_number;
}
void random_choose(int random_number){
  switch(random_number){
  case 1:
    Marker_up();
    arrow_input = 1;
    break;
  case 2:
      Marker_right();
      arrow_input = 2;
      break;
  case 3:
      Marker_down();
      arrow_input = 3;
      break;
  case 4:
      Marker_left();
      arrow_input = 4;
      break;
  }
}
void Marker_up(){
    gotoxy(x_arrow,y_arrow);
    printf(" /\\");
    gotoxy(x_arrow,y_arrow+1);
    printf("/  \\");
    gotoxy(x_arrow,y_arrow+2);
    printf(" ||");
    gotoxy(x_arrow,y_arrow+3);
    printf(" ||");
    }
void Marker_down(){
    gotoxy(x_arrow,y_arrow);
    printf(" ||");
    gotoxy(x_arrow,y_arrow+1);
    printf(" ||");
    gotoxy(x_arrow,y_arrow+2);
    printf("\\  /");
    gotoxy(x_arrow,y_arrow+3);
    printf(" \\/");
}
void Marker_left(){
    gotoxy(x_arrow,y_arrow);
    printf("/---");
    gotoxy(x_arrow,y_arrow+1);
    printf("\\---");
}
void Marker_right(){
    gotoxy(x_arrow,y_arrow);
    printf("---\\");
    gotoxy(x_arrow,y_arrow+1);
    printf("---/");
}
void game_over(){
    int l;
    char game_over[9]="game over";
        gotoxy(12+3*game_size_x/2,5+game_size_y/2);
        for(l=0;l<9;l++){
            printf("%c",game_over[l]);
            Sleep(200);
        }
        Sleep(1000);
}
void arrow_maker(char player_name[]){
    int i,j,k,m;
    int order = 1;
    for(i=0;i<arrownum;i++){
    arrow_input = randoms();
    arrow_num[i]=arrow_input;
    }
    for(j=0;j<arrownum;j++){
    if(j>0){
    system("cls");
    game_place();
    earth();
    human();
    key_check(player_name);
    if (arrow_sign == arrow_num[order]){
        arrow_sign = 0;
        order = order + 1;
        score = score+1;
        score_shows = score_shows + df;
        if(game_speed > 200){
        game_speed = game_speed -25;}
    }
    else if (arrow_sign > 0  && arrow_sign != arrow_num[order]) {
        score_shows = score_shows - 1;
        arrow_sign = 0;
    }
    score_show(player_name,score_shows);
    for(k=j,m=0;k>score;k--,m++){
        x_arrow =10+(3*game_size_x)-(m*5);
        random_choose(arrow_num[k]);
        }
    }
    if(j-score>=3*game_size_x/5-1 || time_game == 0){
        game_over();
        break;
    }
        game_timing();
    }
}
void game_timing(){
gotoxy(8+3*game_size_x,6);
printf("time:");
        if(time_game<=9){
            gotoxy(10+3*game_size_x,7);
            printf("\b0");
            gotoxy(11+3*game_size_x,7);
            printf("\b%d",time_game);
           }
        else{
            gotoxy(11+3*game_size_x,7);
            printf("\b\b%d",time_game);
            }
            Sleep(game_speed);
            c_t = c_t + game_speed;
            if(c_t >= 1000 ) {
            time_game = time_game - 1;
            c_t =c_t - 1000;
            }
}
void key_check(char player_name[]){
        if (_kbhit()){
            int ch;
            ch = get_code();
                switch (ch)
                {
                case ARROW_UP:
                    arrow_sign =1;
                    break;
                case ARROW_RIGHT:
                    arrow_sign =2;
                    break;
                case ARROW_DOWN:
                    arrow_sign =3;
                    break;
                case ARROW_LEFT:
                    arrow_sign =4;
                    break;
                }
        }
}
static int get_code(void)
    {
        int ch = getch();
        if (ch == 0 || ch == 224)
            ch = 256 + getch();
        return ch;
    }
void bsortDesc(struct student list[80], int score_1,char player_name[80],int pl_num)
{
        for(f;f<g;f++){
            strcpy(list[f].name, player_name);
        ///////////////////////////////////////////
            list[f].marks = score_shows;
        }
        g=g+1;
        ///////////////////////////////////////////
            int i, j;
            struct student temp;

            for (i = 0; i < pl_num; i++)
                {
                    for (j = 0; j < (pl_num-i); j++)
                        {
                        if (list[j].marks < list[j + 1].marks && list[j + 1].marks !=0)
                            {
                            temp = list[j];
                            list[j] = list[j + 1];
                            list[j + 1] = temp;
                            }
                        }
                }
          /////////////////////////////////////////
       bsortDesc_show(data,pl_num);
}
void bsortDesc_show(struct student list[80],int pl_num){
         printf("\tnumber\t\tname\t\tscore\n    *********************************************\n");
            int l;
        for (l = 0; l < pl_num; l++)
            {
                    list[l].rollno = l+1;
                    printf("\t %d\t\t%s\t\t%d\n", list[l].rollno, list[l].name, list[l].marks);
            }
        score = 0;
        time_game = d_time;
        printf("go to first menu?(y/n)");
        char an;
        scanf("%s",&an);
        if(an == 121){
            system("cls");
            score_shows = 0;
            game_speed = 1000;
            menu();
        }
        else{
            thx();
            exit("true");
        }
}
void thx(){
    int l;
    char thx[76]="thanks for your play work by ali amini special thanks from professor zangere";
        system("cls");
        gotoxy(15,12);
        for(l=0;l<76;l++){
            printf("%c",thx[l]);
            Sleep(200);
        }
        Sleep(1000);
}



//  /\
// /  \
//  ||
//  ||
//-------
//  ||
//  ||
// \  /
//  \/
//--------



//    /---
//    \---
//---------
//    ---\
//    ---/

//  ___
// /0.0\
//  ***
// /| |\
//  | |
// /   \
