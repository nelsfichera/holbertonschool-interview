#include "sort.h"


/**
 * merge - merges two arrays
 * @copy: copied o.g. array
 * @size: size of array
 * @mid: middle index
 * @main: pointer to o.g. array
 * Return: void
 */
void merge(int *copy, int size, int mid, int *main)
{
	 int x, n = mid, i = 0;

	for (x = 0; x < size; x++)
	{
		if (i < mid && (n >= size || copy[i] <= copy[n]))
			main[x] = copy[i], i++;
		else
			main[x] = copy[n], n++;
	}
}

/**
 * merge_recur - recursive function for merging
 * @copy: copy of o.g. array
 * @size: size of array
 * @main: pointer to o.g. array
 * Return: void
 */
void merge_recur(int *copy, int size, int *main)
{
	int mid = size / 2;

	if (size <= 1)
		return;
	merge_recur(main, mid, copy);
	merge_recur((main + mid), size - mid, (copy + mid));

	printf("Merging...\n");
	printf("[left]: ");
	print_array(copy, mid);
	printf("[right]: ");
	print_array((copy + mid), size - mid);

	merge(copy, size, mid, main);

	printf("[Done]: ");
	print_array(main, size);
}

/**
 * merge_sort - sorts merge from top down
 * @array: input array
 * @size: size of input array
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	int x, *a_copy;

	a_copy = malloc(sizeof(int) * size);
	for (x = 0; x < (int)size; x++)
		a_copy[x] = array[x];
	merge_recur(a_copy, (int)size, array);
	free(a_copy);
}
