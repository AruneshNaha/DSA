#include<stdio.h>
#include<conio.h>
#include<string.h>

int cand_num[10]={0,1,2,3,4,5,6,7,8,9};//to store candidate number
char contestants[10][10]={"Sekhar","Varun","Dinesh","Kartik","Sushant","Rohit","Gambhir","Rajat","Ashu","Badal"};//candidate names
int votes[10]={0,0,0,0,0,0,0,0,0,0};//initial votes
char symbol[10]={1,2,3,4,5,6,11,12,15,14};//candidate symbols

void main(){

    printf("\t\t\t<<EVM>>\t\t\t\nElectronic Voting Machine\n");//display
    int t=1;
    while(t!=0)
    {
        poll();//invoking function to poll votes
        printf("\nAny more votes?1/0: ");
        scanf("%d",&t);
    }
    fetch_results();
}
void poll(){
    int i;
    printf("Vote wisely!\n---------------------------------------------\n");
    for(i=0;i<10;i++)
    {
        printf("Enter %d for voting to %s\n",cand_num[i],contestants[i]);
    }

    printf("\n\nEnter your choice:");
    int v=getch();
    v=v-48;

    votes[v]++;
    printf("Your voting is complete!");
}

void fetch_results()
{
    char winner_name[10],winner_symbol;
    int max=0;
    int i,g,j;
    char s=(char)219;
    printf("Names\t\tVotes\tSymbols\tGraph\n--------------------------------------------------------\n");
    for(i=0;i<10;i++)
    {
        printf("%s\t\t %d \t %c \t",contestants[i],votes[i],symbol[i]);
        g=votes[i];
        for(j=1;j<=g;j++)
            printf("%c",s);
        printf("\n");
        if(max<votes[i])
        {
            max=votes[i];
            strcpy(winner_name,contestants[i]);
            winner_symbol=symbol[i];
        }
    }
    printf("\n\nSo the winner is %s %c and has won with %d votes!",winner_name,winner_symbol,max);

}
