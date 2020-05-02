//PIC MINI PROJECT Sci-Man`
//FE COMPS B-3
//1911120 JAINAM SHAH
//1911121 PARTHIV SHAH
//1911122 RUSHIL SHAH

//header files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//declaring and initialising global variables
int choice,lives=6,round=1,score=0,k=0,high=0,vcoins=0;;
char name[20],highname[20];
//main menu screen function
void main_menu()
{
    system("cls");//clearing screen
    printf("Sciman - v2.0\n\n");
    //intro page
    printf("Sciman is an upgraded version of hangman with a scientific twist\n");
    printf("1. Play\n2. Rules\n3. Store\n4. High Score\n5. Credits\n6. Exit\n");
    scanf("%d",&choice);
    //menu driven options
    if(choice==1)
        play();
    if(choice==2)
        rules();
    if(choice==3)
        store();
    if(choice==4)
        high_score();
    if(choice==5)
        credits();
    if(choice==6)
        end();
}
//draw function is common for all the rounds and it creates the blanks and tells status of everything
void draw(char *blanks,char *word,char *telepathy,char *alphabets, char *printquantum,char *printtelepathy ,char *category)
{
    system("cls");
        if(strcmp(word,blanks)==0)//checking if the round is completed
        {
            char chse[10];
            score=score+30;
            system("cls");
            printf("Congratulations, your answer was correct!\nYour score = %d\n\nPress any key to continue\n",score);
            scanf("%s",chse);
            if(round==5)
            {
                if(high>score)
                {
                    high=score;
                    strcat(highname,name);
                }
                vcoins=vcoins+score;
                score=0;
            }
            return;
        }
        if(lives==0)//checking if the lives are over
        {
            char chse[10];
            if(high>score)
            {
                high=score;
                strcat(highname,name);
            }
            system("cls");
            printf("You are out of lives!\nThe answer was %s\nBetter luck next time\nYour score = %d\n\nPress any key to continue\n",word,score);
            scanf("%s",chse);
            //resetting all values
            vcoins=vcoins+score;
            score=0;
            main_menu();
        }
    char choose[1];
    int x;
    printf("Category - %s\nRound - %d\n\nScore = %d points\nLives Left = %d\nWrong guesses = %d\n\n\n%s\n\n\n%s",category,round,score,lives,(6-lives),blanks,alphabets);
    printf("\n\nGuess the word by typing a letter one at a time\n\nPress 1 to teleport to next round(-5 points)\n%s\n%s\nPress 4 to ask Einstein(give up)\n\nPress 0 to go back to main menu(Warning! All your progress will be lost)\n",printquantum,printtelepathy);
        scanf("%s",choose);
        //taking inputs from user
        if(choose[0]=='1')//teleporting algorithm
        {
            score=score-5;
            return;
        }
         else if(choose[0]=='2')//quantum letters algorithm
        {
            int x,y,a=0;
            char repeat[50]=" ";//repeating letters

            //checking which letters occur more than once
            for(x=0;x<strlen(word);x++)
            {
                for(y=x+1;y<strlen(word);y++)
                {
                    if(word[x]==word[y])
                    {
                        repeat[a]=word[x];
                        a++;
                    }
                }
            }
            //revealing quantum letters
            for(x=0;x<strlen(word);x++)
            {
                for(y=0;y<strlen(repeat);y++)
                {
                        if(word[x]==repeat[y])
                        blanks[x]=repeat[y];
                }
            }
            score=score-5;
            draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        }
        //telepathy means shows the hint for the answer
        else if(choose[0]=='3')
        {
            strcpy(printtelepathy,telepathy);
            score=score-10;
            draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        }
        //give up algorithm
        else if(choose[0]=='4')
        {
            system("cls");
            //giving highscore
            if(score>=high)
            {
                high=score;
                strcat(highname,name);
            }
            printf("Don't give up so easily!\nThe answer was %s\nBetter luck next time\nYour score = %d\n\nPress any key to continue",word,score);
            scanf("%s",choose);
            score=0;
            main_menu();
        }
        //go back to main menu
        else if(choose[0]=='0')
        {
            score=0;
            main_menu();
        }
        else
        {//input of letters
            k=0;
            for(x=0;x<strlen(word);x++)
            {
                if(choose[0]==word[x])
                {
                    blanks[x]=choose[0];
                    k=1;
                }
            }
            if(k!=1)
                lives--;
            for(x=0;x<strlen(alphabets);x++)
            {
                if(choose[0]==alphabets[x]+32)
                    alphabets[x]=' ';
            }
            system("cls");
            draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        }
}
void single_player()
{
    system ("cls");
    printf("Welcome to Sciman!\n\nEnter your username(no spaces allowed): ");
    scanf("%s",name);
    system("cls");
    printf("Hi %s,\nSelect your category:-\n\n1. Sports\n2. Car Brands\n3. Personalities\n\n",name);
    printf("\n\nPress 0 to go back to main menu\n");
    scanf("%d",&choice);
    //selection of categories
    if(choice==1)
        categ_sports();
    if(choice==2)
        categ_carbrands();
    if(choice==3)
        categ_personalities();
    if(choice==0)
        main_menu();
}

//double player logic starts
int r=0,p1=0,p2=0,lives2=6;
void double_player()
{
    system ("cls");
    char name1[20],name2[20];
    r=0;
    //Takes the name input without space and stores it in respective variables
    printf("Welcome to Sciman Two player!\n\nEnter Player one's name: (without spaces)\n");
    scanf("%s",name1);
    printf("\n\nEnter Player two's name: (without spaces)\n");
    scanf("%s",name2);
    input(name1,name2);
}
    void input(char *name1, char *name2)
    {
        system("cls");
        int x,n=0,lives2=6;
        char blank2[100],word2[100];
        char alphabet2[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";  //Checks the inputted word and removes it from here
        r++;           //To check round number
        printf("%s has to guess the word\n\n%s has to write the word: \n",name1,name2);
        //Logic to check if the letter guess in the word or not
        do{
        fgets(word2,sizeof(word2),stdin);
        }while(word2[0]=='\n');
        //prints the dashes or black whichever applicable

        for(x=0;x<strlen(word2)-1;x++)
        {
            if(word2[x]==' ')
            {
                blank2[x]=' ';
            }
            else
            {
                blank2[x]='-';
            }
        }
        blank2[x]='\0';
        strcat(blank2,"\n");


            char temp[50];
            strcpy(temp,name1);
            strcpy(name1,name2);
            strcpy(name2,temp);
            int tem;
            tem=p1;
            p1=p2;
            p2=tem;


        draw2(word2,blank2,name1,name2,alphabet2);   //Main logic of double player word checking
    }
    void draw2(char* word2, char* blank2, char*name1,char*name2,char *alphabet2)//values to be passed -
    {
        if(lives2==0)   //Checks lives remaining
        {
            lives2=6;
            input(name1,name2);
        }
        if(strcmp(word2,blank2)==0)   //Compares the word
        {
            printf("same");
            if(r%2!=0)
                p2++;
            else
                p1++;
            lives2=6;
            input(name1,name2);
        }
        char shm[1];
        int x;
        system("cls");
        //Updates the point count
        printf("Round %d\n\nLives = %d\n\n%s = %d points\n%s = %d points\n\n%s\n\n%s\n\n",r,lives2,name1,p1,name2,p2,blank2,alphabet2);
        printf("\nPress 0 to go to back to main menu\n");
        scanf("%s",shm);
        if(shm[0]=='0')
        main_menu();
        //Continues until the word is guessed or not
        else
        {

            k=0;
            for(x=0;x<strlen(word2);x++)
            {
                if(shm[0]==word2[x])
                {
                    blank2[x]=shm[0];
                    k=1;
                }
            }
            if(k!=1)
                lives2--;
            for(x=0;x<strlen(alphabet2);x++)
            {
                if(shm[0]==alphabet2[x]+32)
                    alphabet2[x]=' ';
            }
            system("cls");
            draw2(word2,blank2,name1,name2,alphabet2);
        }
    }
    //double player logic ends

void play()
{
    lives=6;
    system ("cls");
    printf("Welcome to Sciman!\n\n1. Single Player\n2. Two Player\n\nPress 0 to go back to main menu\n");
    scanf("%d",&choice);
    if(choice==1)
        single_player();
    if(choice==2)
        double_player();
    if(choice==0)
        main_menu();
}
void rules()
{
    system ("cls");
    printf("Rules:\n-You have to guess the word by guessing a letter one at a time\n-You will get 30 points for guessing a word correctly\n-You will be given 6 lives for a round\n-Lives will be deducted by wrong guess of letters\n-You will earn points(vcoins) by winning in a round\n-You can buy spells from the store in exchange of vcoins\n");
    printf("\n\nPress 0 to go back to main menu\n");
    scanf("%d",&choice);
    if(choice==0)
        main_menu();
}
void store()
{
    system ("cls");
    printf("Store\n\nYou have %d vcoins\n(currently the store is under construction)",vcoins);
    printf("\n\nPress 0 to go back to main menu\n");
    scanf("%d",&choice);
    if(choice==0)
        main_menu();
}
void high_score()
{
    system ("cls");
    int no;
    printf("Name = %s\nHigh Score = %d",highname,high);
    printf("\n\nPress 0 to go back to main menu\n");
    scanf("%d",&no);
    if(no==0)
        main_menu();

}
void credits()
{
    system ("cls");
    printf("Sciman is an upgraded version of hangman inspired by scientific principles.\nSciman was developed by \nJainam Shah - 1911120\nParthiv Shah - 1911121\nRushil Shah - 1911122\nUnder the guidance of Prof. Vaibhav Vasani");
    printf("\n\nPress 0 to go back to main menu\n");
    scanf("%d",&choice);
    if(choice==0)
        main_menu();
}

void end()
{
    system("cls");
    int a;
    printf("Thanks for playing Sciman!\nPlease give us ratings out of 5\n");
    scanf("%d",&a);
    printf("\n");
    exit;
}
void categ_sports()
{
    system("cls");
    sports_round1();//calling for the first round

}
    void sports_round1()
    {
        //feeding the answer, blank and hint system
        printf("Category - Sports\n");
        round=1;
        lives=6;
        char category[50]="Sports";
        char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
        char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
        char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="table tennis";
        char blanks[100]="----- ------";
        char telepathy[100]="It is also known as Ping Pong";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        sports_round2();

    }
    void sports_round2()
    {
        //feeding the answer, blank and hint system
        round=2;
        lives=6;
        char category[50]="Sports";
        printf("Category - Sports\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="cricket";
        char blanks[100]="-------";
        char telepathy[100]="Each team consists of 11 players";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        sports_round3();

    }
    void sports_round3()
    {
        //feeding the answer, blank and hint system
        round=3;
        lives=6;
        char category[50]="Sports";
        printf("Category - Sports\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="golf";
        char blanks[100]="----";
        char telepathy[100]="This game has something to do with holes";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        sports_round4();

    }
    void sports_round4()
    {
        //feeding the answer, blank and hint system
        round=4;
        lives=6;
        char category[50]="Sports";
        printf("Category - Sports\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="hockey";
        char blanks[100]="------";
        char telepathy[100]="National sport of India";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        sports_round5();

    }
    void sports_round5()
    {
        //feeding the answer, blank and hint system
        round=5;
        lives=6;
        char category[50]="Sports";
        printf("Category - Sports\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="hockey";
        char blanks[100]="------";
        char telepathy[100]="Passing, shooting and tackling are some of the skills required";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        main_menu();

    }


void categ_carbrands()
{//calling for the first round
    system("cls");
    car_round1();
}
    void car_round1()
    {
        //feeding the answer, blank and hint system
        round=1;
        lives=6;
        char category[50]="Car Brands";
        printf("Category - Car brands\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="audi";
        char blanks[100]="----";
        char telepathy[100]="Four rings";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        car_round2();

    }
    void car_round2()
    {
        //feeding the answer, blank and hint system
        char category[50]="Car Brands";
        round=2;
        lives=6;
        printf("Category - Car brands\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="aston martin";
        char blanks[100]="----- ------";
        char telepathy[100]="Luxury British sports car brand";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        car_round3();

    }
    void car_round3()
    {
        //feeding the answer, blank and hint system
        char category[50]="Car Brands";
        round=3;
        lives=6;
        printf("Category - Car brands\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="bmw";
        char blanks[100]="---";
        char telepathy[100]="Bavarian Motor Works";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        car_round4();

    }
    void car_round4()
    {
        //feeding the answer, blank and hint system
        char category[50]="Car Brands";
        round=4;
        lives=6;
        printf("Category - Car brand\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="volkswagen";
        char blanks[100]="----------";
        char telepathy[100]="V and W";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        sports_round5();

    }
    void car_round5()
    {
        //feeding the answer, blank and hint system
        char category[50]="Car Brands";
        round=5;
        lives=6;
        printf("Category - Car brand\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="ferrari";
        char blanks[100]="-------";
        char telepathy[100]="Italian sports car brand";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        main_menu();

    }

void categ_personalities()
{//calling for the first round
    system("cls");
    personalities_round1();
}
    void personalities_round1()
    {
        //feeding the answer, blank and hint system
        char category[50]="Personalities";
        round=1;
        lives=6;
        printf("Category - Personalities\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="elon musk";
        char blanks[100]="---- ----";
        char telepathy[100]="Owns a company named after a famous scientist";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        personalities_round2();

    }
    void personalities_round2()
    {
        //feeding the answer, blank and hint system
        char category[50]="Personalities";
        round=2;
        lives=6;
        printf("Category - Personalities\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="albert einstein";
        char blanks[100]="------ --------";
        char telepathy[100]="Received a Nobel prize in Physics";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        personalities_round3();

    }
    void personalities_round3()
    {
        //feeding the answer, blank and hint system
        char category[50]="Personalities";
        round=3;
        lives=6;
        printf("Category - Personalities\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="bill nye";
        char blanks[100]="---- ---";
        char telepathy[100]="The Science guy";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        personalities_round4();

    }
    void personalities_round4()
    {//feeding the answer, blank and hint system
        char category[50]="Personalities";
        round=4;
        lives=6;
        printf("Category - Personalities\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="srinivasa ramanujan";
        char blanks[100]="--------- ---------";
        char telepathy[100]="India's famous Mathematician";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        personalities_round5();

    }
    void personalities_round5()
    {//feeding the answer, blank and hint system
        char category[50]="Personalities";
        round=5;
        lives=6;
        printf("Category - Personalities\n");
          char alphabets[100]="A B C D E F G H I J K L M\nN O P Q R S T U V W X Y Z";
          char printquantum[100]="Press 2 to reveal quantum letters(-5 points)";
          char printtelepathy[100]="Press 3 to use telepathy(-10 points)";
        char word[100]="bobby fischer";
        char blanks[100]="----- -------";
        char telepathy[100]="Regarded as the best Chess player of all time";
        draw(blanks,word,telepathy,alphabets,printquantum,printtelepathy,category);
        main_menu();

    }




int main()
{
    //start of the program
    system ("cls");
    main_menu(); //calling the main menu function
    //end of the program
    return 0;
}
