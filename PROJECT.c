#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int pick()
{
	int i,arr[30];
	int random;
	
	for(i=0;i<30;i++)
	{
		arr[i]=i;
	}
	
	srand(time(NULL));
	random = arr[rand() % 30];
	return random;
}

void shuffle(char *a)
{
    int i, random, length;
    char temp;
    
     length = strlen(a);

    for (i = length-1; i > 0; i--)
    {
        random = rand()%(i+1);
        temp = a[random];
        a[random] = a[i];
        a[i] = temp;
    }
    printf("\n GUESS THE WORD: %s \n",a);
}

int comp(char *a)
{
	char s[50];
	int x;
	static int flag=0;
	
	printf("\n ENTER YOUR ANSWER: ");
	scanf("%s",s);
	
	x=strcmp(a,s);
	
	if(x==0)
	{
		printf("------------------------------\n");
		printf("\n ******CORRECT ANSWER******\n\n");
		printf("------------------------------\n");
		flag++;
	}
	else
	{
		printf("------------------------------\n");
		printf("\n ******INCORRECT******\n\n");
		printf("------------------------------\n");
	}
	return flag;
}

int read(int ch)
{
	int i=0;
	FILE *fp;
	switch(ch)
	{
	case 1:
	fp = fopen ("test.txt", "r");

	fscanf (fp, "%d", &i);    
	while (!feof(fp))
    {  
    	fscanf (fp, "%d", &i);      
    }
    fclose (fp);      
	break;	
	
	
	case 2:
    fp = fopen ("Medium.txt", "r");

	fscanf (fp, "%d", &i);    
	while (!feof(fp))
    {  
    	fscanf (fp, "%d", &i);      
    }
    fclose (fp);      
	break;	
	
	
	case 3:
    fp = fopen ("Hard.txt", "r");

	fscanf (fp, "%d", &i);    
	while (!feof(fp))
    {  
    	fscanf (fp, "%d", &i);      
    }
    fclose (fp);      
	break;	
	
      	
}

  return i;  
}


void write(int ch,int k) 
{
	FILE *fptr;
  switch(ch)
{
	case 1:
  fptr = fopen("test.txt", "w");
  
  fprintf(fptr, "%d",k);
  
  fclose(fptr);
  break;
  
  	case 2:

  fptr = fopen("test.txt", "w");
  
  fprintf(fptr, "%d",k);
  
  fclose(fptr);
  break;
  
  	case 3:

  fptr = fopen("test.txt", "w");
  
  fprintf(fptr, "%d",k);
  
  fclose(fptr);
	break;
}
  
  
}

void main()
{
	char s[50],a[50];
	char word_easy[30][3] = {"wax","bar","air","bet","any","bud","ark","mix","zip","did","yen","web","age","sue","app","toe","and","ape","ago","rug","ask","fun","axe","ace","jog","mud","aim","ale","amp","cap"};
	char word_medium[30][5] = {"acute","agent","breed","buyer","chase","civil","dying","enemy","faith","fiber","grand","hence","heavy","issue","joint","known","laser","label","mount","novel","order","phase","pitch","quick","round","scene","serve","tight","threw","undue"};
	char word_hard[30][7] = {"acquire","anxious","balance","beating","chronic","complex","dispute","elderly","faculty","genetic","highway","however","insight","justify","kingdom","leisure","medical","nervous","organic","phoenix","precise","witness","veteran","unknown","typical","upgrade","species","stretch","radical","purpose"};
	int q,p,ch,i,k,j,r;
	
	printf("\n****************************** WELCOME TO JUMBLEX ******************************\n");
	
	printf("\n 1.EASY\n\n 2.MEDIUM\n\n 3.HARD\n\n 4.LAST HIGH SCORE\n\n 5.EXIT\n\n");
	
	printf("\n ENTER YOUR CHOICE: ");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
		    
			printf("\n\t\t\t\t   EASY MODE\n\n");
	        for(j=0;j<10;j++)
            {
				k = pick();  
        		for(i=0;i<3;i++)
	            {   
					a[i]=word_easy[k][i];
	                s[i]=word_easy[k][i];
	            }
	  			shuffle(s);	
		        p=comp(a);
	        }
			printf("\nYOUR SCORE: %d/10",p);
			q=read(1);
			if(p>q)
			{
				write(1,p);
			}
			r=read(1);
			printf("\nHigh score: %d/10",r);
			break;
			
		case 2:
			printf("\n\t\t\t\t   MEDIUM MODE\n\n");
        	for(j=0;j<10;j++)
            {   
				k=pick();
        		for(i=0;i<5;i++)
	            {   
					a[i]=word_medium[k][i];
	                s[i]=word_medium[k][i];
	            }
	  			shuffle(s);	
		        p=comp(a);
	        }
		    printf("\n YOUR SCORE: %d/10",p);
		    q=read(2);
			if(p>q)
			{
				write(2,p);
			}
			r=read(2);
			printf("\nHigh score: %d/10",r);
			break;
	        break;
			
		case 3:
			printf("\n\t\t\t\t   HARD MODE\n\n");
           	for(j=0;j<10;j++)
           	{           
			    k=pick();
        		for(i=0;i<7;i++)
	            {   
					a[i]=word_hard[k][i];
	                s[i]=word_hard[k][i];
	            }
	  			shuffle(s);	
		        p=comp(a);
	       	}
			printf("\n YOUR SCORE: %d/10",p);
			q=read(3);
			if(p>q)
			{
				write(3,p);
			}
			r=read(3);
			printf("\nHigh score: %d/10",r);
			break;
			break;
			
		case 4:
			printf("\n\t\t\t\t   LAST HIGH SCORE");
			printf("\n\nEASY MODE   : %d",read(1));
			printf("\n\nMEDIUM MODE : %d",read(2));
			printf("\n\nHARD MODE   : %d",read(3));
			break;
			
		case 5:
			printf("\n THANK YOU FOR PLAYING, HOPE TO SEE YOU SOON.");
			break;
			
		default:
			printf("\n WRONG CHOICE, PLEASE SELECT ONE OF THE ABOVE OPTION");
	}
}
