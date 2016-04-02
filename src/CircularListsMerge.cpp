/*
Given two SORTED Circular Linked Lists ,
Write a function to merge those two linked lists .
The First Linked List head should point to the final merged linked list .
The Final merged linked list should also be in SORTED order and a Circular Linked List.
You need to return the Length of Final SLL.

*********
The First linked list head should now point to the Final sorted(Ascending) Linked list First Node
*********
Ex : A: 0->3->5->10->20 (and 20 now pointing back to 0,instead of Null )
B: 1->2->6->11->21->50->70 (70 Pointing back to 1).

The Final Linked List is A:0->1->2->3->5->6->10->11->20->21->50->70 .

Note : Dont use Malloc or create any new nodes ,Only pointers need to be interchanged,
You can use temp pointers although.
Note : The Final Linked List should be  also be a circular Linked List where Last node is
pointing towards the first node.
Note : Return -1 for Invalid Inputs like NULL;

Input : head1 and head2 are Addresses of Two Circular Linked Lists heads .
Output :Return Length of New SLL .Modify the head1 value, such that it now points to 
Merged Sorted Circular SLL .

Difficulty : Medium
*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};
int merge_circularlists(struct node **head1, struct node **head2){
	//Returns Length of merged Sorted circular SLL and also points *head1 to final SLL .
	struct node *h1=NULL,*h2=NULL,*head = NULL, *temp = NULL, *temp1 = NULL, *temp2 = NULL, *t1 = NULL, *t2 = NULL;
/*	if (head2 == NULL&&head1 != NULL)
		return head1;
	if (head1 == NULL&&head2 != NULL)
		return head2;*/
	int c = 0;
	*h1 = **head1;
	*h2 = **head2;
	temp1 = h1;
	temp2 = h2;
	if (head1 == NULL&&head2 == NULL)
		return -1;
	if (h1 == NULL&&h2 == NULL)
		return -1;
	temp1 = h1;
	if (h1 == NULL&&h2 != NULL)
	{
		while (temp1 != NULL)
		{
			c++;
			temp1 = temp1->next;
		}
		return c;
	}
	temp2 = h2;
	if (h2 == NULL&&h1 != NULL)
	{
		while (temp2 != NULL)
		{
			c++;
			temp2 = temp2->next;
		}
		return c;
	}
	if (temp1->data <= temp2->data)
		head = temp1;
	else
		head = temp2;
	while (1)
	{
		if (temp2->data < temp1->data)
		{
			c++;
			while (temp2->next != h2)
			{
				if (temp2->next->data < temp1->data)
				{
					c++;
					temp2 = temp2->next;
				}
				else
					break;
			}
			if (temp2->next == h2)
			{
				if (t2 != h2)
					t1->next = temp2;
				temp2->next = temp1;
				temp1->next = h1;
				c++;
				break;
			}
			else
			{
				t2 = temp2;
				temp2 = temp2->next;
				t2->next = temp1;
				if (t1 != h1)
					t1->next = t2;
				t1 = temp1;
				temp1 = temp1->next;
				c++;
			}
		}
		if (temp1->data < temp2->data)
		{
			c++;
			while (temp1->next != h1)
			{
				if (temp1->next->data < temp2->data)
				{
					c++;
					temp1 = temp1->next;
				}
				else
					break;
			}
			if (temp1->next == h1)
			{
				c++;
				temp1->next = temp2;
				while (temp2->next != h2)
				{
					c++;
					temp2 = temp2->next;
				}
				temp2->next = h1;
				break;
			}
			else
			{
				t1 = temp1;
				temp1 = temp1->next;
				t1->next = temp2;
				t2 = temp2;
				temp2 = temp2->next;
				t2->next = temp1;
				c=c++;
				if (temp2->next == h2)
				{
					temp2->next = h1;
					break;
				}
			}
		}
		if (temp1->data == temp2->data)
		{
			t2 = temp2;
			temp2 = temp2->next;
			t2->next = temp1->next;
			temp1->next = t2;
			temp1 = t2->next;
			if (temp1->next ==h1&&temp2->next == h2)
			{
				c++;
				temp1->next = temp2;
				temp2->next = h1;
				break;
			}
		}
	}
	c++;
	return c;
}