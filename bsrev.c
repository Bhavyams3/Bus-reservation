#include<stdio.h>
#include<math.h>
int nop;

int n,i,j=0;
struct tick
{
    long int pnr;
     int age;
    char name[20];
}ti;
void main()
{
    int ch;
    printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t-----welcome-----\n\n\n\t\t\t\t\t\t");
    system("pause");
    while(1)
    {
        system("cls");
        printf("\n1.Book ticket");
        printf("\n2.My bookings");
        printf("\n3.Cancel ticket");
        printf("\n4.Exit");
        printf("\n Enter your choice...");scanf("%d",&ch);
        switch(ch)
        {
            case 1 : bookticket();
                        break;
            case 2 : display();
                        break;
            case 3 : cancelticket();
                        break;
            case 4 : exit(0);
            default : printf("\nWrong option entered..\n");
                        break;
        }
    }
}
int passenger()
{
    FILE *fp;
    fp = fopen("btick", "a");

    printf("Enter number of passengers - ");scanf("%d",&n);
    nop=n;
    for(i=0;i<n;i++)
    {
        printf("------------------------------\n");
        printf("passenger %d name - ",i+1);scanf("%s",&ti.name);
        printf("passenger Age - ");scanf("%d",&ti.age);
        ti.pnr= rand ();
        fwrite(&ti, sizeof(ti), 1, fp);
    }


    fclose(fp);
    system("pause");
    return 0;
}

int bookticket()
{
    int ch;
     float total;
     int coach[3]={50,100,200};
    printf("\n1.General ticket\n");
    printf("2.Sleeper coach");
    printf("\n3.AC coach\n");
    printf("Enter your choice - ");scanf("%d",&ch);
    if(ch==1)
    {
        passenger();
        printf("\nTicket booked .....\n");
        total=nop*coach[0];
        printf("Total=%f ",total);
        j++;
    }
    else if(ch==2)
    {
        passenger();
       printf("\nTicket booked .....\n");
        total=nop*coach[1];
        printf("Total=%f ",total);
        j++;
    }
    else if(ch==3)
    {
        passenger();
        printf("\nTicket booked .....\n");
        total=nop*coach[2];
        printf("Total=%f ",total);
        j++;
    }
    else
    {
        printf("Wrong option entered...\n");
    }
    system("pause");
}
void display()
{

        system("cls");
        FILE *fp1;
        fp1 = fopen("btick", "r");
        printf("\n__________Bookings________\n");
        printf("\n\nName\tAge\tPNR\n");
        while (fread(&ti, sizeof(ti), 1, fp1))
        {
            printf("\t\n%s\t%d\t%d\n",ti.name,ti.age,ti.pnr);

        }
        printf("\n");
         fclose(fp1);
        system("pause");

}
int searchpnr( int r)
{
    FILE *fp;
     fp = fopen("btick", "r");
     while (!feof(fp))
     {
      fread(&ti, sizeof(ti), 1, fp);

      if (r == ti.pnr)
      {
       fclose(fp);
       return 1;
      }
     }
     fclose(fp);
     return 0;
}


void cancelticket()
{
    system("cls");
    FILE *fpo;
     FILE *fpt;
     int r, s;
     printf("Enter the PNR :");
     scanf("%d", &r);
     if (searchpnr(r) == 0)
      {
          printf("Ticket with PNR %d is not available in the file\n", r);
          system("pause");
      }
     else
     {
          fpo = fopen("btick", "r");
          fpt = fopen("TempFile", "w");
          while (fread(&ti, sizeof(ti), 1, fpo))
          {
               s = ti.pnr;
               if (s != r)
                fwrite(&ti, sizeof(ti), 1, fpt);
          }
          fclose(fpo);
          fclose(fpt);
          fpo = fopen("btick", "w");
          fpt = fopen("TempFile", "r");
          while (fread(&ti, sizeof(ti), 1, fpt))
           fwrite(&ti, sizeof(ti), 1, fpo);
          printf("\nTICKET DELETED\n");
          system("pause");
          fclose(fpo);
          fclose(fpt);
     }

}

