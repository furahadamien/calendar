#include<stdio.h>
#include<stdlib.h>

//Name:Furaha Damien
//McGill ID :260754407


int num_Days_ofMonth =30;


char *months[]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};
char *num_charsInMOnth []={" ","7","8","5","5","3","4","4","6","9","7","8","8"};

char *days9[]={" ","Sunday                   ","Monday                  ","Tuesday                ","Wednesday                        ","Thursday                  ","Friday                   ","Saturday                        "};

int print_Calendar(int firstday, int daysize){

    

	int num_symbols =(daysize + 3)*7 +1;
	int i;
	int j;
	int endSpaces;
	int month;
	int space;
	int n;
	int day;

	for(month = 1; month <= 12; month++){
		endSpaces= (num_symbols - atoi(num_charsInMOnth[month]) )/2;
		printf("|");

		for(i = 1; i < num_symbols-1; i++){
			printf("-");
		}

		printf("|\n");
		printf("|");

		for(j = 1; j < endSpaces; j++){
			printf(" ");
		}

		printf("%s",months[month]);

		for(j = 1; j < endSpaces+(num_symbols - atoi(num_charsInMOnth[month]) )%2; j++){
			printf(" ");
		}

		printf("|\n|");

		for(i = 1; i < num_symbols-1; i++){
			printf("-");
		}

		printf("|\n");

		space = num_symbols/7;

        int m=1;
        for(n = 1; n <num_symbols & m <= 7; n * space){
               
                printf("| %.*s",daysize,days9[m]);
                for(int k=0; k < (space-daysize-2) ; k++){
                    printf(" ");
                }
                m++;
        }


		for(int l = 1; l<=num_symbols;l++){
			if(l==num_symbols){
				printf("|");
			}
		}

		printf("\n");
		printf("|");


		for(i = 1; i < num_symbols-1; i++){
			printf("-");
		}
		printf("|\n");
		 //printf(" firstday %d",firstday);
		int nu_spaces = (num_symbols - 22)/7;

		int date = 1;
		//for(int date = 1; date <= num_Days_ofMonth; date++){
		//adjust first day date


		for(int week_row = 1; week_row<7; week_row++){
			for(int day_col = 1; day_col<8; day_col++){
				if(date == 1){
					for(int y = 1; y<firstday; y++){
						printf("|");
						for(int p = 0; p<nu_spaces+2; p++){
							printf(" ");
						}
					}

					printf("| %d ",date);
					date++;
					for (int x=1; x<nu_spaces; x++){
						printf(" ");
					}
                    day_col = firstday;
                    //day_col++;
                    //printf("|");
				}
				else {
                    
                    if(date<10){
                        printf("| %d ",date);
                    }
                    else{
                        printf("| %2d",date);
                    }
                    date++;
                    if(date==31){
                        for (int g=1; g<nu_spaces; g++){
                            printf(" ");
                        }
                        printf("|");
                        for (int k = day_col + 1; k < 8; k++) {
                            for (int j=0; j<nu_spaces + 2; j++){
                                printf(" ");
                            }
                            printf("|");
                        }
                        date=1;
                        week_row = 7;
                        day_col = 8;
                    }
                    for (int x=1; x<nu_spaces; x++){
                        printf(" ");
                    }
                }
                if (day_col == 7) {
                    printf("|");
                }
			}
			printf("\n");

		}




			


		// //position for next month


        if(month==12){
            printf("|");
            for(i = 1; i < num_symbols-1; i++){
		 		printf("-");
            }
		 	printf("|\n");
        }

        firstday = ( firstday + 2 ) % 7;
        if (firstday == 0) {
            firstday = 7;
        }
	}

}



int main(int argc, char *argv[])
{
	int daysize = atoi(argv[1]);
	int firstday= atoi(argv[2]);
	


	if(daysize<2){
		printf("can not print day size smaller than 2\n");
		exit(-1);
	}
	if(firstday<1 | firstday>7){
		printf("first day of the week must be between 1 and 7\n");
		exit(-1);
	}
	if((argv[1]) == NULL || argv[2]== NULL){
		printf("you should enter both the first day and day size");
		exit(-1);
	}//take care of seg fault when no inputs are supplied of more

	print_Calendar(firstday, daysize);

	
}
