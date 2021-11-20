#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// has memory leaks in deleteAtPos func, will fix it later
struct node
{
  char name[50];
  int total_marks;
  struct node *prev;
  struct node *next;
};

struct node *create_ll (struct node *start, char name[50], int marks);
void print_ll (struct node *start);
void InsertLast (struct node *start);
struct node *DeleteLast (struct node *start);
struct node *InsertAtPos (struct node *start);
struct node *DeleteAtPos (struct node *start);
void PrintInRev (struct node *start);

int
main ()
{
  struct node *start = NULL;
  // Creating List with some initial elements
  start = create_ll (start, "abc", 200);
  start = create_ll (start, "def", 300);
  start = create_ll (start, "ghij", 250);
  printf ("\nInitial data in the list are ! \n");
  print_ll (start);

  printf ("\n1. Insertion of a node (last position).\n");

  printf ("2. Deletion of a node (the last node).\n");

  printf
    ("3. Insertion at a specific position of the current list (input the position).\n");

  printf
    ("4. Deletion from a specific position of the current list (input the position).\n");

  printf ("5. Print the list in reverse direction.\n");

  int choice;
  printf ("Input=");
  scanf ("%d", &choice);

  switch (choice)
    {
    case 1:
      {
	InsertLast (start);
	print_ll (start);
	printf ("\n");
	break;
      }
    case 2:
      {
	start = DeleteLast (start);
	print_ll (start);
	printf ("\n");
	break;
      }
    case 3:
      {
	start = InsertAtPos (start);
	print_ll (start);
	printf ("\n");
	break;
      }
    case 4:
      {
	start = DeleteAtPos (start);
	print_ll (start);
	printf ("\n");
	break;
      }
    case 5:
      {
	PrintInRev (start);
	printf ("\n");
	break;
      }
    default:
      printf ("Output=Invalid input. No function with this serial.\n");
    }

  return 0;
}

struct node *
create_ll (struct node *st, char Name[50], int marks)
{
  struct node *new_node, *ptr;
  new_node = (struct node *) malloc (sizeof (struct node));

  strcpy (new_node->name, Name);
  new_node->total_marks = marks;
  new_node->next = NULL;
  if (st == NULL)
    {
      st = new_node;
      new_node->prev = NULL;
    }
  else
    {
      ptr = st;
      while (ptr->next != NULL)
	{
	  ptr = ptr->next;
	}
      ptr->next = new_node;
      new_node->prev = ptr;
    }
  return st;
}

void
print_ll (struct node *st)
{
  struct node *ptr;
  ptr = st;
  printf ("Output=");
  if (st == NULL)
    {
      printf ("The Link List is empty\n");
    }
  else
    {
      while (ptr != NULL)
	{
	  printf ("(%s,%d),", ptr->name, ptr->total_marks);
	  ptr = ptr->next;
	}
    }
}

void
InsertLast (struct node *start)
{
  char Name[50];
  scanf ("%s", &Name);
  int marks;
  scanf ("%d", &marks);
  struct node *new_node = (struct node *) malloc (sizeof (struct node));
  strcpy (new_node->name, Name);
  new_node->total_marks = marks;
  new_node->next = NULL;
  if (start == NULL)
    {
      new_node->prev = NULL;
      start = new_node;
    }
  else
    {
      struct node *temp = start;
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->next = new_node;
      new_node->prev = temp;
    }
}

struct node *
DeleteLast (struct node *start)
{
  if (start == NULL)
    {
      return start;
    }
  else if (start->next == NULL)
    {
      struct node *temp = start;
      start = start->next;
      free (temp);
    }
  else
    {
      struct node *temp = start;
      while (temp->next != NULL)
	{
	  temp = temp->next;
	}
      temp->prev->next = NULL;
      free (temp);
    }
  return start;
}

struct node *
InsertAtPos (struct node *start)
{
  int pos;
  scanf ("%d", &pos);
  char Name[50];
  scanf ("%s", &Name);
  int marks;
  scanf ("%d", &marks);
  struct node *new_node = (struct node *) malloc (sizeof (struct node));
  strcpy (new_node->name, Name);
  new_node->total_marks = marks;
  new_node->prev = NULL;
  new_node->next = NULL;
  if (start == NULL)
    {
      return start;
    }
  if (pos == 1)
    {
      new_node->next = start;
      start->prev = new_node;
      start = new_node;
      return start;
    }
  struct node *temp = start, *pre = NULL;
  int i = 1;
  while (i < pos && temp != NULL)
    {
      pre = temp;
      temp = temp->next;
      i++;
    }
  if (temp == NULL)
    {
      pre->next = new_node;
      new_node->prev = pre;
      return start;
    }
  new_node->prev = temp->prev;
  new_node->next = temp;
  temp->prev->next = new_node;
  temp->prev = new_node;
  return start;
}

struct node *
DeleteAtPos (struct node *start)
{
  int pos;
  scanf ("%d", &pos);
  if (pos <= 0 || start == NULL)
    {
      return start;
    }
  if (pos == 1)
    {
      start = start->next;
      start->prev = NULL;
      return start;
    }
  int i = 1;
  struct node *temp = start;

  while (i < pos && temp != NULL)
    {
      temp = temp->next;
      i++;
    }
  if (temp == NULL)
    {
      return start;
    }
  if (temp->next == NULL)
    {
      return DeleteLast (start);;
    }

  temp->prev->next = temp->next;
  temp->next->prev = temp->prev;

  return start;
}

void
PrintInRev (struct node *start)
{
  if (start == NULL)
    {
      printf ("The Link List is empty\n");
    }
  struct node *temp = start;
  while (temp->next != NULL)
    {
      temp = temp->next;
    }
  printf ("Output=");
  while (temp != start)
    {
      printf ("(%s,%d),", temp->name, temp->total_marks);
      temp = temp->prev;
    }
  printf ("(%s,%d)", temp->name, temp->total_marks);
}