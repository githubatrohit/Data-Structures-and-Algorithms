# include<stdio.h>
# include<stdlib.h>
//Name : Rohit Raj || Roll : 1928113
struct DAStack{
	int *arr;
    int size;
	int top;
};

struct DAStack* initialise(int size)
{
	struct DAStack *temp = (struct DAStack *)malloc(sizeof(struct DAStack));
    temp->size = size;
	temp->arr = (int*)malloc(temp->size*sizeof(int));
	temp->top = -1;
	return temp;
}

int FullStack(struct DAStack* temp){
    return temp->top == temp->size -1;
}
int EmptyStack(struct DAStack* temp){
    return temp->top == -1;
}


void push(struct DAStack* temp, int data){
    if(FullStack(temp))
        return;
    temp->arr[++temp->top] = data;
    printf("\n %d is pushed to the stack\n", data);
}
int pop(struct DAStack* temp){
    if (EmptyStack(temp)){
        printf("\nThe Stack is empty");
    }
    return temp->arr[temp->top--];
}
int top(struct DAStack *temp){
    if (EmptyStack(temp)){
        printf("The Stack is empty");
    }
    return temp->arr[temp->top];
}
void printStack(struct DAStack *temp, int size)
{
	int i = 0;
	printf("Top data is : ");
	for(i=temp->top; i>-1; i--)
	{
		printf("%d\n", temp->arr[i]);
	 } 
	 printf("\n");
}

int main()
{
	int n = 0;
    int choice;
    int data;
    int t;
	printf("\nEnter size of the array : ");
	scanf("%d",&n);
	struct DAStack *temp = initialise(n);
    for(;;){
    printf("1: Push items to stack\n");
    printf("2: Pop items from the stack\n");
    printf("3: Display top data of the Stack\n");
    printf("4: Display all data of the stack\n");
    printf("Enter your choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:
        printf("\nEnter the data to be pushed\n");
        scanf("%d",&data);
        push(temp,data);
        break;
    case 2:
        pop(temp);
        printf("\nData removed successfully\n");
        break;
    case 3:
        printf("\nThe top element is %d\n",top(temp));
        break;
    case 4:
        printStack(temp,n);
    default:
        printf("\nWrong choice entered, Try again\n");
        break;
    }
    }
	return 0;
}
