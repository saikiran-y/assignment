#include<stdio.h>
void main()
{
 int n,i,j,temp,TEMP1,TEMP2,TEMP3,TEMP4;
 float WTSUM=0,TATSUM=0;
 int bt[10],at[10],P[10],ct[10],tat[10],wt[10],pt[10];
 printf("enter the no of  process\n");
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
  printf("Enter the arrival time of p%d:\t",i);
  scanf("%d",&at[i]);
  printf("Enter burst time of p%d: \t",i);
  scanf("%d",&bt[i]);
  printf("Enter the priority :\t");
  scanf("%d",&pt[i]);
  P[i]=i;
  printf("\n");
 }
 ct[0]=0;
    if(bt[1]>=at[n])
    {
        ct[1]=bt[1]+at[1];
        tat[1]=ct[1]-at[1];
        wt[1]=tat[1]-bt[1];
  WTSUM=wt[1];
  TATSUM=tat[1];
        for(i=2;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(pt[j]<pt[i])
                {
                    TEMP4=pt[i];
                    pt[i]=pt[j];
                    pt[j]=TEMP4;
                    TEMP1=bt[i];
                    bt[i]=bt[j];
                    bt[j]=TEMP1;
                    TEMP2=at[i];
                    at[i]=at[j];
                    at[j]=TEMP2;
                    TEMP3=P[i];
                    P[i]=P[j];
                    P[j]=TEMP3;
                }
            }
                if(ct[i-1]<at[i])
                {
                    temp=at[i]-ct[i-1];
                    ct[i]=ct[i-1]+bt[i]+temp;
                    TEMP1=bt[i];
                }
                else
                {
                    ct[i]=ct[i-1]+bt[i];
                }
                tat[i]=ct[i]-at[i];
                wt[i]=tat[i]-bt[i];
                WTSUM=WTSUM+wt[i]+wt[1];
                TATSUM=TATSUM+tat[i]+tat[1];
       }
   }
            if(at[n]==0)
            {
            ct[0]=0;
            for(i=1;i<=n;i++)
                {
                    for(j=i+1;j<=n;j++)
                    {
                        if(pt[j]<pt[i])
                        {
                            TEMP4=pt[i];
                            pt[i]=pt[j];
                            pt[j]=TEMP4;
                          TEMP1=bt[i];
                          bt[i]=bt[j];
                          bt[j]=TEMP1;
                        TEMP2=at[i];
                        at[i]=at[j];
                        at[j]=TEMP2;
                        }
                    }
                if(ct[i-1]<at[i])
                {

                    temp=at[i]-ct[i-1];
                    ct[i]=ct[i-1]+bt[i]+temp;
                    TEMP1=bt[i];
                }
                else
                {
                    ct[i]=ct[i-1]+bt[i];
                }
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
            WTSUM=WTSUM+wt[i];
           TATSUM=TATSUM+tat[i];
        }
    }
 printf("\n\n\n");
 printf("\tPROCESS\tBT\tAT\tPT\tTAT\tWT\n");
 for(i=1;i<=n;i++)
 {
 printf("\tP%d\t%d\t%d\t%d  \t%d\t%d\n\n",P[i],bt[i],at[i],pt[i],tat[i],wt[i]);
 }
 printf("Average_waiting_time = %f\n",WTSUM/n);
 printf("Average_turn_around_time= %f\n",TATSUM/n);
 printf("\n\n");
 printf("Gantt chart\n");
 for(i=1;i<=n;i++)
 {
  printf("\tP%d\t",P[i]);

 }
 printf("\n");
 for(i=1;i<=n;i++)
 {
 printf("\t%d\t",ct[i]);
 }
}
