#include "sort.h"

/**
 * radix_sort - sorts array radix style
 * @array: pointer to input array
 * @size: size of input array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int x, max, bucket, count[10], *out;

	if (array == NULL || size < 2)
		return;

	max = array[0];
	for (x = 1; x < (int)size; x++)
		if (array[x] > max)
			max = array[x];

	for (bucket = 1; max / bucket > 0; bucket *= 10)
	{
		out = malloc(sizeof(int) * size);

		for (x = 0; x < 10; x++)
			count[x] = 0;

		for (x = 0; x < (int)size; x++)
			count[(array[x] / bucket) % 10]++;
		for (x = 1; x < 10; x++)
			count[x] += count[x - 1];
		for (x = (int)size - 1; x >= 0; x--)
		{
			out[count[(array[x] / bucket) % 10] - 1] = array[x];
			count[(array[x] / bucket) % 10]--;
		}
		for (x = 0; x < (int)size; x++)
			array[x] = out[x];

		free(out);
		print_array(array, size);

	}
}
