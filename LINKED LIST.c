#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
};
struct node *start = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *insert_end(struct node *);
struct node *delete_beg(struct node *);
struct node *delete_end(struct node *);
struct node *sort_list(struct node *);
struct node *delete_node(struct node *);


int main()
{
	int option;
	do
	{
		printf("\n *****MAIN MENU *****");
		printf("\n 1: Create a list");
		printf("\n 2: Display the list");
		printf("\n 3: Add a node at the beginning");
		printf("\n 4: Add a node at the end");
		printf("\n 5: Delete a node from the beginning");
		printf("\n 6: Delete a node from the end");
		printf("\n 7: Sort the List");
		printf("\n 8: Delete a particular node");
		printf("\n 9: EXIT");
		printf("\n  Enter your option : ");
		scanf("%d", &option);
		switch(option)
		{
			case 1:
				start = create_ll(start);
				printf("\nLINKED LIST CREATED");
				break;
			case 2:
				start = display(start);
				break;
			case 3:
				start = insert_beg(start);
				break;
			case 4:
				start = insert_end(start);
				break;
			case 5:
				start = delete_beg(start);
				break;
			case 6:
				start = delete_end(start);
				break;
			case 7:
				start = sort_list(start);
				break;
			case 8:
				start = delete_node(start);
				break;
		}
	}
	while(option !=9);
	return 0;
}

//To create a LL
struct node *create_ll(struct node *start)
{
	struct node *new_node, *ptr;
	int num;
	printf("\n Enter the first data: ");
//Here num check if the first node is set to null by the user and then the function executes
	scanf("%d", &num);
	while(num!= 0)
	{
		printf("\n Enter the data : ");
		new_node = (struct node*)malloc(sizeof(struct node));
		new_node -> data=num;
		if(start==NULL)
		{

			new_node -> next = NULL;
			start = new_node;
		}
		else
		{
			ptr=start;
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next = new_node;
			new_node->next=NULL;
		}
		scanf("%d", &num);
	}
	return start;
}
//To display the LL
struct node *display(struct node *start)
{
	struct node *ptr;
	ptr = start;
	while(ptr != NULL)
	{
		printf("\t%d", ptr -> data);
		ptr = ptr -> next;
	}
	return start;
}

//Data insertion at the beginning
struct node *insert_beg(struct node *start)
{
	struct node *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = start;
	start = new_node;
	return start;
}
//Data insertion at the end of the LL
struct node *insert_end(struct node *start)
{
	struct node *ptr, *new_node;
	int num;
	printf("\n Enter the data : ");
	scanf("%d", &num);
	new_node = (struct node *)malloc(sizeof(struct node));
	new_node -> data = num;
	new_node -> next = NULL;
	ptr = start;
	while(ptr -> next != NULL)
		ptr = ptr -> next;
	ptr -> next = new_node;
	return start;
}
//Sort the LL
struct node *sort_list(struct node *start)
{
	struct node *ptr1, *ptr2;
	int temp;
	ptr1 = start;
	while(ptr1 -> next != NULL)
	{
		ptr2 = ptr1 -> next;
		while(ptr2 != NULL)
		{
			if(ptr1 -> data > ptr2 -> data)
			{
				temp = ptr1 -> data;
				ptr1 -> data = ptr2 -> data;
				ptr2 -> data = temp;
			}
			ptr2 = ptr2 -> next;
		}
		ptr1 = ptr1 -> next;
	}
	return start;
}

//Delete the beginning node
struct node *delete_beg(struct node *start)
{
	struct node *ptr;
	ptr = start;
	start = start -> next;
	free(ptr);
	return start;
}

//Delete the end node
struct node *delete_end(struct node *start)
{
	struct node *ptr, *preptr;
	ptr = start;
	while(ptr -> next != NULL)
	{
		preptr = ptr;
		ptr = ptr -> next;
	}
	preptr -> next = NULL;
	free(ptr);
	return start;
}

//Delete at given node
struct node *delete_node(struct node *start)
{
	struct node *ptr, *preptr;
	int val;
	printf("\n Enter the value of the node which has to be deleted : ");
	scanf("%d", &val);
	ptr = start;
	if(ptr -> data == val)
	{
		start = delete_beg(start);
		return start;
	}
	else
	{
		while(ptr -> data != val)
		{
			preptr = ptr;
			ptr = ptr -> next;
		}
		preptr -> next = ptr -> next;
		free(ptr);
		return start;
	}
}



