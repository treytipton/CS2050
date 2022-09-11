#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses);
int searchArray(char haystack[100], char needle[3]);

int main(void){
        char player1[3] = "HHT";
        char player2[3] = "THH";
        int winner = 0; 
        int numTosses = 0;
        int coinTossResult=0;
        int p1wins = 0;
        int p2wins = 0; 
        int loopTimes = 1000000;
        float winRate = 0;
        srand(time(NULL));
        
        for(int i=0;i<loopTimes;i++){
                coinTossResult = coinTossGame(player1, player2, &winner, &numTosses);
                if(coinTossResult == 1){
                i--;
                continue;
                } 
                if(winner==1){
                        p1wins++;
                }
                if(winner==2){
                        p2wins++;
                }
        }
        printf("\nScore - P1: %d P2: %d\nNumber of Tosses: %d",p1wins,p2wins,numTosses);
        winRate = ((float)p1wins/loopTimes)*100;
        printf("\nAlice win rate: %.2f%%",winRate);
        winRate = ((float)p2wins/loopTimes)*100;
        printf("\nBob win rate: %.2f%%\n",winRate);
}
int coinTossGame(char player1[3], char player2[3], int *winner, int *numTosses){
        char results[100] = "";
        int matchFound = 0;
        int i = 0;
        int toss = 0;
        int cWinner = 0;
        int cTossCount = 0;

        while(matchFound == 0 && (i<100)){
                toss = rand() % 2;
                cTossCount++;
                if(toss == 0){(strcat(results,"H"));}
                if(toss == 1){(strcat(results,"T"));}
                if(searchArray(results,player1)){
                        matchFound = 1;
                        cWinner = 1;
                        break;
                }
                if(searchArray(results,player2)){
                        matchFound = 1;
                        cWinner = 2;
                        break;
                }
                i++;
        }
        if(matchFound){
		//printf("\n%s",results);
                *winner = cWinner;
                *numTosses = *numTosses + cTossCount;
                return 0;
        }
        return 1;
}
int searchArray(char haystack[100], char needle[3]){
	int i = 0;
	
	for(i=0;i<97;i++){
		if(haystack[i]==needle[0]){
			if(haystack[i+1]==needle[1]){
				if(haystack[i+2]==needle[2]){
					return 1;
				}
			}
		}
	}
	return 0;
}
