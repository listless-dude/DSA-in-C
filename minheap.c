#include <stdio.h>
int size = 0; // size for the array

void swap(int *a, int *b)
{
  int temp = *b;
  *b = *a;
  *a = temp;
}

// create heap
void heap(int array[], int size, int i)
{
  if (size == 1)
    return;
  else
  {
    int smallest = i;
    int l = 2 * i + 1; // left child 
    int r = 2 * i + 2; // right child
    // if the left child element is smaller than the smallest element
    // since its minheap
    if (l < size && array[l] < array[smallest])
      smallest = l;
    if (r < size && array[r] < array[smallest])
      smallest = r;
    // swap the positions of the elements to form heap
    // we are taking parameter i as the index of array
    if (smallest != i)
    {
      swap(&array[i], &array[smallest]);
      heap(array, size, smallest);
    }
  }
}

void insert(int array[], int newNum)
{
  if (size == 0)
  {
    array[0] = newNum;
    size += 1; // increasing the size of the array
  }
  else
  {
    array[size] = newNum;
    size += 1;
    for (int i = size / 2 - 1; i >= 0; i--)
    {
      // traversing the array from first index of non-leaf node, which is n/2 - 1
      heap(array, size, i);
    }
  }
}

void deleteRoot(int array[])
{
  int i, num = array[0]; // array[0] represents root node

  for (i = 0; i < size; i++)
  {
    if (num == array[i])
      break;
  }
// swap the root node with the last node
  swap(&array[i], &array[size - 1]);
  size -= 1; // decrease the size of array i.e. deleting the last node
for (int i = size / 2 - 1; i >= 0; i--)
    {
      // traversing the array from first index of non-leaf node, which is n/2 - 1
      heap(array, size, i);
    }
}

void printArray(int array[], int size)
{
  for (int i = 0; i < size; ++i)
    printf("%d ", array[i]);
  printf("\n");
}

int main()
{
  int array[10];

  insert(array, 5);
  insert(array, 3);
  insert(array, 6);
  insert(array, 2);
  insert(array, 4);
  insert(array, 1);


  printf("Max-Heap array: ");
  printArray(array, size);

  deleteRoot(array);
  deleteRoot(array);


  printf("After deleting an element: ");

  printArray(array, size);
}