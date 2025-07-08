#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
typedef struct {
char word[25];
char hint[100];
} WordHint;
WordHint arr[10]={
{"PIZZA","A Famous Italian Dish"},
{"VIRATKOHLI","Modern Cricket Icon"},
{"LABORATORY","A Place Where Experiments Are Conducted"},
{"IIITVADODARA","An Institute Of National Importance"},
{"ROHITSHARMA","Captain of Indian Cricket Team In Test & ODI
Formats"},
{"INDIGO","A Color In The Rainbow"},
{"PYTHON","A Programming Language"},
{"SUNFLOWER","A Flower Represented With Sun"},
{"NARENDRAMODI","Prime Minister Of India"},
{"BREAKFAST","Meal Eaten In Morning"}
};
int correct=0;
#define max_wrong 7
int used_num[10]={0,0,0,0,0,0,0,0,0,0};
void check_word(char letter, char correct_word[], char* guessed_ptr, int
length){
int repeat=0;
for(int i=0;i<length;i++){
if (*(guessed_ptr+i)==letter){
repeat=1;
correct--;
}
if (correct_word[i]==letter){
*(guessed_ptr+i)=letter;
correct++;
}
}
if (repeat==1) printf("You already guessed this letter! Try another one!\n");
}
void display(char guessed_word[], int word_length) {
if (correct==word_length) printf("\nWell done! The word was:\n");
else printf("Word to guess: ");
for (int i = 0; i < word_length; i++) printf("%c ", guessed_word[i]);
printf("\n\n");
}
int random_word(){
srand(time(NULL));
int random=rand()%10;
for(int i=0;i<10;i++){
if (used_num[i]==random) return random_word();
}
for(int i=0;i<10;i++){
if (used_num[i]==0){
used_num[i]=random;
return random;
}
}
}
void display_hangman(int tries){
switch (tries) {
case 1: printf(" -----\n | |\n | \n | \n | \n |\n"); break;
case 2: printf(" -----\n | |\n | O\n | \n | \n |\n"); break;
case 3: printf(" -----\n | |\n | O\n | |\n | \n |\n"); break;
case 4: printf(" -----\n | |\n | O\n | /|\n | \n |\n"); break;
case 5: printf(" -----\n | |\n | O\n | /|\\\n | \n |\n"); break;
case 6: printf(" -----\n | |\n | O\n | /|\\\n | / \n |\n"); break;
case 7: printf(" -----\n | |\n | O\n | /|\\\n | / \\\n |\nYou have been
hanged!\n");break;
}
}
int main(){
printf("\n\n");
printf("\t________________________________________________
______________________________________________________
_______\n\n\n");
printf("\t\t\t** ** ***** ** ** ****** ** ** ***** ** **\n");
printf("\t\t\t** ** ** ** *** ** ** *** *** ** ** *** **\n");
printf("\t\t\t** ** ** ** **** ** ** **** **** ** ** **** **\n");
printf("\t\t\t******* ******* ** ** ** ** *** ** ** ** ** ******* ** ** **\n");
printf("\t\t\t** ** ** ** ** **** ** ** ** ** ** ** ** ** ** ****\n");
printf("\t\t\t** ** ** ** ** *** ** ** ** **** ** ** ** ** ***\n");
printf("\t\t\t** ** ** ** ** ** ****** ** ** ** ** ** **
**\n\n\n");
printf("\t________________________________________________
______________________________________________________
_______\n\n\n");
printf("Welcome to Hangman!\n");
printf("Instructions:\n");
printf("1. A word will be chosen secretly, and you have to guess it letter by
letter.\n");
printf("2. You can guess one letter at a time.\n");
printf("3. Each incorrect guess will add to the hangman drawing.\n");
printf("4. You have a maximum of %d incorrect guesses before you
lose.\n", max_wrong);
printf("5. Guess all the letters correctly to win the game!\n");
printf("6. Good luck!\n");
int flag='Y';
while(flag=='Y'){
int try=0;
correct=0;
int k=random_word();
printf("\nHint: %s\n", arr[k].hint);
char correct_word[25];
strcpy(correct_word,arr[k].word);
int length=strlen(correct_word);
char guessed_word[25];
char *guessed_ptr=guessed_word;
for (int i=0;i<length;i++){
*(guessed_ptr+i)='_';
}
*(guessed_ptr+length)='\0';
for(int i=0;i<length;i++) printf("_ ");
printf("\n\n");
while(correct!=length){
char letter;
printf("Enter letter: ");
scanf(" %c",&letter);
letter=toupper(letter);
if(strchr(correct_word,letter)==NULL){
try++;
printf("Oops! You guessed wrong!\n");
display_hangman(try);
}
else check_word(letter,correct_word,guessed_ptr,length);
if(try==max_wrong){
printf("Game Over!\n\n");
break;
}
else display(guessed_word,length);
}
char choice;
while(1){
printf("Do you want to continue? [Y/N]");
scanf(" %c",&choice);
flag=toupper(choice);
if(flag!='Y' && flag!='N') printf("Not a valid choice. Please enter Y or
N\n");
else break;
}
}
printf("Thank you for playing");
return 0;
}
