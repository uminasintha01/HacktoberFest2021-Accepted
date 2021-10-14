#include<stdio.h>
#include<string.h>

int front = -1,rear= -1,top=-1;
struct process
{
	char pname[10];
	int at,bt,wt,tt,index;
}p[10],temp,ready_queue[10];

struct done
{
	char pname[10];
	int time;
}done_stack[10];


void enqueue(struct process k)
{
	printf("\nReady queue : %s",k.pname);
	if(front == -1 || rear == -1)
	{
		front = 0;
		rear = 0;
	}
	ready_queue[rear] = k;
	rear++;
}

struct process  dequeue(int* stat)
{
	struct process k;
	if(front == -1 || front == rear)
		*stat = -1;//empty
	else
	{
		k = ready_queue[front];
		front++;
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
		*stat = 1;
		
	}
	//printf("\nstatus from dequeue %d : ",s);
	
	return k;
		
	
}
void push(char* name,int time)
{
		top++;
		printf("Inserted %s to done stack",name);
		struct done k;
		strcpy(k.pname,name);
		k.time = time;
		done_stack[top] = k;
}

int main()
{
	int time_elapsed=0,n,sumTT=0,sumWT=0,time_slice,stat;
	printf("Enter the number of process : ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("\nEnter the process name : ");
		__fpurge(stdin);
		fgets(p[i].pname,10,stdin);
		
		p[i].pname[strcspn(p[i].pname, "\n")] = 0;
	
		printf("\nEnter the arrival time : ");
		scanf("%d",&p[i].at);
		printf("\nEnter the burst time : ");
		scanf("%d",&p[i].bt);
	}
	printf("\nEnter the time slice : ");
	scanf("%d",&time_slice);

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(p[i].at > p[j].at)
			{
				temp=p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
		p[i].index = i;
	}
	
	int i=1;
	temp = p[0];
	stat = 1;
	
	printf("\n| pname\t| arrival time\t| burst time\t| wait\t| turn");
	
	for(int i=0;i<n;i++)
	{
		printf("\n\n| %s\t| %d\t\t| %d\t\t| %d\t| %d",p[i].pname,p[i].at,p[i].bt,p[i].wt,p[i].tt);
	}
	printf("\n");
	while(stat > 0)
	{
		if(time_elapsed >= temp.at)
		{
			push(temp.pname,time_elapsed);
			if(temp.bt <= time_slice)
			{
				time_elapsed += temp.bt;
				temp.bt = 0;
				p[temp.index].tt = time_elapsed - temp.at;
				p[temp.index].wt = p[temp.index].tt - p[temp.index].bt;
				sumWT += p[temp.index].wt;
				sumTT += p[temp.index].tt;
				printf("\nProcess %s has TT = %d and WT = %d",p[temp.index].pname,p[temp.index].tt,p[temp.index].wt);
			}
			else
			{
				time_elapsed += time_slice;
				temp.bt -= time_slice;
			}
			if(i<n)
			{
				int j= p[i].at;
				while(j<=time_elapsed)
				{
					enqueue(p[i]);
					i++;
					if(i<n)
						j=p[i].at;
					else
						break;
				}
			}
			if(temp.bt != 0)
				enqueue(temp);
			temp = dequeue(&stat);
			printf("\nstatus = %d",stat);
			if(stat < 0 || i<n)
			{
				temp = p[i];
				i++;
			}
		}
		else
		{
				push("ideal",time_elapsed);
				time_elapsed += temp.at - time_elapsed;
		}
			
		
	}
	printf("\n| pname\t| arrival time\t| burst time\t| wait\t| turn");
	
	for(int i=0;i<n;i++)
	{
		printf("\n\n| %s\t| %d\t\t| %d\t\t| %d\t| %d",p[i].pname,p[i].at,p[i].bt,p[i].wt,p[i].tt);
	}
	printf("\n\nGantt Chart");
	printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
	
	for(int i=0;i<=top;i++)
	{
		printf("|%s\t",done_stack[i].pname);
	}
	printf("|\t");
	printf("\n------------------------------------------------------------------------------------------------------------------------------\n");
	for(int i=0;i<=top;i++)
		printf("|%d\t", done_stack[i].time);
		
	printf("|%d\t",time_elapsed);
		
	printf("\n\nAverage Turn Around Time : %f",(float)sumTT/n);
	printf("\n\nAverage Waiting Time : %f",(float)sumWT/n);
	return 0;
	
}
