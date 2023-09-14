#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int extraMemoryAllocated;

// implements heap sort
// extraMemoryAllocated counts bytes of memory allocated
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int array[], int n, int i)
{
	int largest = i;
	int left = (2 * i);
	int right = (2 * i) + 1;

	while (left < n && array[left] > array[largest])
		largest = left;

	while (right < n && array[right] > array[largest])
		largest = right;

	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		heapify(array, n, largest);
	}

}

void heapSort(int arr[], int n)
{
	for (int i = n/2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for (int j = n - 1; j > 0; j--)
	{
		swap(&arr[0], &arr[j]);
		heapify(arr, j, 0);
	}
}


// implement merge sort
// extraMemoryAllocated counts bytes of extra memory allocated
void merge(int* array, int left, int mid, int right)
{
	int i, j, k;

	int n1 = mid - left + 1;
	int n2 = right - mid;

	int* L = (int*)malloc(n1 * sizeof(int));
	int* R = (int*)malloc(n2 * sizeof(int));
	extraMemoryAllocated += 2;

	for (i = 0; i < n1; i++)
		L[i] = array[left + i];

	for (j = 0; j < n2; j++)
		R[j] = array[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			array[k] = L[i];
			i++;
		}
		else
		{
			array[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		array[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		array[k] = R[j];
		j++;
		k++;
	}

	free(L);
	free(R);

}

void mergeSort(int pData[], int l, int r)
{
	if (l < r)
	{
		int m = (r + l) / 2;

		mergeSort(pData, l, m);
		mergeSort(pData, m + 1, r);

		merge(pData, l, m, r);
	}
}

// parses input file to an integer array
int parseData(char *inputFileName, int **ppData)
{
	FILE* inFile = fopen(inputFileName,"r");
	int dataSz = 0;
	int i, n, *data;
	*ppData = NULL;
	
	if (inFile)
	{
		fscanf(inFile,"%d\n",&dataSz);
		*ppData = (int *)malloc(sizeof(int) * dataSz);
		// Implement parse data block
		if (*ppData == NULL)
		{
			printf("Cannot allocate memory\n");
			exit(-1);
		}
		for (i=0;i<dataSz;++i)
		{
			fscanf(inFile, "%d ",&n);
			data = *ppData + i;
			*data = n;
		}

		fclose(inFile);
	}
	
	return dataSz;
}

// prints first and last 100 items in the data array
void printArray(int pData[], int dataSz)
{
	int i, sz = dataSz - 100;
	printf("\tData:\n\t");
	for (i=0;i<100 && i < dataSz;++i)
	{
		printf("%d ",pData[i]);
	}
	printf("\n\t");
	
	if (dataSz > 100)
	{
		for (i=sz;i<dataSz;++i)
		{
			printf("%d ",pData[i]);
		}
	}
	printf("\n\n");
}

int main(void)
{
	clock_t start, end;
	int i;
    double cpu_time_used;
	char* fileNames[] = { "input1.txt", "input2.txt", "input3.txt", "input4.txt" };
	
	for (i=0;i<4;++i)
	{
		int *pDataSrc, *pDataCopy;
		int dataSz = parseData(fileNames[i], &pDataSrc);
		
		if (dataSz <= 0)
			continue;
		
		pDataCopy = (int *)malloc(sizeof(int)*dataSz);
	
		printf("---------------------------\n");
		printf("Dataset Size : %d\n",dataSz);
		printf("---------------------------\n");
		
		printf("Heap Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz*sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		heapSort(pDataCopy, dataSz);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n",cpu_time_used);
		printf("\textra memory allocated\t: %d\n",extraMemoryAllocated);
		printArray(pDataCopy, dataSz);
		
		printf("Merge Sort:\n");
		memcpy(pDataCopy, pDataSrc, dataSz*sizeof(int));
		extraMemoryAllocated = 0;
		start = clock();
		mergeSort(pDataCopy, 0, dataSz - 1);
		end = clock();
		cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
		printf("\truntime\t\t\t: %.1lf\n",cpu_time_used);
		printf("\textra memory allocated\t: %d\n",extraMemoryAllocated);
		printArray(pDataCopy, dataSz);
		
		free(pDataCopy);
		free(pDataSrc);
	}
	
}