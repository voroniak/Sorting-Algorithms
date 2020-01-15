#include <iostream>
#include <ctime>
#include<fstream>
#include<string>
using namespace std;
void print(int *arr, int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << "-";
	}
	cout << endl;
}
int  BubbleSort(int  *arr, int size) {
	long long count_BubbleSort = 0;
	for (int k = 0; k < size - 1; ++k) {
		for (int i = 0; i < size - k - 1; ++i) {
			if (arr[i] > arr[i + 1]){
				swap(arr[i] ,arr[i + 1]);
				count_BubbleSort++;
			}
		}
	}
	return count_BubbleSort;
}
int InsertionSort(int *arr, int n) {
	long long count_InsertionSort = 0;
	for (int k = 0; k < n; ++k) {
		int min_index = k;
		int min_number = arr[k];
		for (int i = k + 1; i < n; ++i) {
			count_InsertionSort++;
			if (min_number > arr[i]) {
				min_number = arr[i];
				min_index = i;
				
			}
		}
		arr[min_index] = arr[k];
		arr[k] = min_number;
	}
	return count_InsertionSort;
}
int SelectionSort(int *arr, int size) {
	long long count_SelectionSort = 0;
	for (int i = 0; i < size - 1; i++) {
		int el = i;
		for (int j = i + 1; j < size; j++) {
			count_SelectionSort++;
			if (arr[j] < arr[el]) {
				el = j;
			}
		}
		if (el != i) {
			swap(arr[i], arr[el]);
			count_SelectionSort++;

		}
	}
	return count_SelectionSort;
}
void QuickSort(int *arr, int left, int right, int &count_QuickSort) {
	int i = left, j = right;
	int tmp;
	int pivot = arr[(left + right) / 2];
	while (i <= j) {
		while (arr[i] < pivot) {
			i++;
			count_QuickSort++;
		}
		while (arr[j] > pivot) {
			j--;
			count_QuickSort++;
		}
		if (i <= j) {
			swap(arr[i], arr[j]);
			//cout << endl <<"pivot=  "<< pivot<< "  i= " << i << "  j=  " << j << endl;
			i++;
			j--;
			count_QuickSort++;
			//print(arr, right+1);
		}
	}
	if (left < j) {
		QuickSort(arr, left, j, count_QuickSort);
		count_QuickSort++;
	}
	if (i < right) {
		QuickSort(arr, i, right, count_QuickSort);
		count_QuickSort++;
	}
}
int  CountingSort(int *arr, int size)
{
	long long count_CountingSort = 0;
	int max = INT_MIN, min = INT_MAX;
	for (int i = 0; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
			count_CountingSort++;
		}
		if (arr[i] < min) {
			min = arr[i];
			count_CountingSort++;
		}
	}
	int *c = new int[max + 1 - min];
	for (int i = 0; i < max + 1 - min; i++) {
		c[i] = 0;
	}
	for (int i = 0; i < size; i++) {
		c[arr[i] - min] = c[arr[i] - min] + 1;
		count_CountingSort++;
	}
	int i = 0;
	for (int j = min; j < max + 1; j++) {
		while (c[j - min] != 0) {
			arr[i] = j;
			c[j - min]--;
			i++;
			count_CountingSort++;
		}
	}
	int count_copy = 0;
	for (int i = 0; i < max + 1 - min; i++) {
			while (c[i]!=0)
			{
				arr[count_copy] = c[i];
				count_copy++;
				c[i]--;
				count_CountingSort++;
			}
	}
	count_copy--;
	return count_CountingSort;
}
void merge(int *a, int p, int q, int r, int size, int &count_MergeSort) {
	int *b = new int[size];
	int  i, j, k;
	k = 0;
	i = p;
	j = q + 1;
	while (i <= q && j <= r) {
		if (a[i] < a[j]) {
			b[k++] = a[i++];
			count_MergeSort++;
		}
		else {
			b[k++] = a[j++];
			count_MergeSort++;
		}
	}
	while (i <= q) {
		b[k++] = a[i++];
		count_MergeSort++;
	}
	while (j <= r) {
		b[k++] = a[j++];
		count_MergeSort++;
	}
	for (i = r; i >= p; i--) {
		a[i] = b[--k];
		count_MergeSort++;
	}
}
void mergeSort(int *a, int p, int r, int SIZE, int &count_MergeSort) {
	int q;
	q = (p + r) / 2;
	if (p < r) {
		mergeSort(a, p, q, SIZE, count_MergeSort);
		mergeSort(a, q + 1, r, SIZE, count_MergeSort);
		merge(a, p, q, r, SIZE, count_MergeSort);
	}
}
int HeapSort(int *arr, int size) {
	bool ok = false;
	int a = 0;
	int length = size;
	int count_heapSort = 0;
	for (int i = length / 2; i > 0; i--) {
		int child = 2 * i - 1;
		if (size >= child + 2) {
			bool flag = false;
			if (arr[child] > arr[child + 1]) flag = true;
			if (flag) {
				if (arr[i - 1] < arr[child]) {
					int temp = arr[i - 1];
					arr[i - 1] = arr[child];
					arr[child] = temp;
					a++;
					count_heapSort++;
				}
			}
			else {

				if (arr[i - 1] < arr[child + 1]) {

					int temp = arr[i - 1];
					arr[i - 1] = arr[child + 1];
					arr[child + 1] = temp;
					a++;
					count_heapSort++;
				}
			}
		}
		else {
			if (arr[i - 1] < arr[child]) {
				int temp = arr[i];
				arr[i] = arr[child];
				arr[child] = temp;
				a++;
				count_heapSort++;
			}

		}
	}
	if (length != 2) {
		int temp = arr[0];
		arr[0] = arr[size - 1];
		arr[size - 1] = temp;
		a++;
		count_heapSort++;
	}
	return count_heapSort;

}
int main()
{
	srand(time(NULL));
	cout << "Max array Size: ";
	int n; 
	cin >> n;
	cout << endl;
	int sw;
	cout << "1 - BubbleSort " << endl;
	cout << "2 - InsertionSort " << endl;
	cout << "3 - SelectionSort " << endl;
	cout << "4 - QuickSort " << endl;
	cout << "5 - CountingSort " << endl;
	cout << "6 - MergeSort " << endl;
	cout << "7 - HeapSort " << endl;
	cin >> sw;
	switch (sw)
	{
	case 1: {
		ofstream OutData;
		OutData.open("BubbleSort.csv");
		int i = 1;
		while (i <= n + 1) {
			int* arr_coppy = new int[i];
			for (int k = 0; k < i; k++) {
				arr_coppy[k] = rand() % 100;
			}
			int k = BubbleSort(arr_coppy, i);
			OutData << i << ';' << k << endl;
			i += 10;
			delete[]arr_coppy;
		}
		OutData.close();
		cout << "end" << endl;
		break;
	}
	case 2: {
		ofstream OutData;
		OutData.open("InsertionSort.csv");
		int i = 1;
		while (i <= n + 1) {
			int* arr_coppy = new int[i];
			for (int k = 0; k < i; k++) {
				arr_coppy[k] = rand() % 100;
			}
			int k = InsertionSort(arr_coppy, i);
			OutData << i << ';' << k << endl;
			i += 10;
			delete[]arr_coppy;
		}
		OutData.close();
		cout << "end" << endl;
		break;
	}
	case 3: {
		ofstream OutData;
		OutData.open("SelectionSort.csv");
		int i = 1;
		while (i <= n + 1) {
			int* arr_coppy = new int[i];
			for (int k = 0; k < i; k++) {
				arr_coppy[k] = rand() % 100;
			}
			int k = SelectionSort(arr_coppy, i);
			OutData << i << ';' << k << endl;
			i += 10;
			delete[]arr_coppy;
		}
		OutData.close();
		cout << "end" << endl;
		break;
	}
	case 4: {
		ofstream OutData;
		
		OutData.open("QuickSort.csv");
		int i = 1;
		while (i <= n + 1) {
			int count_QuickSort = 0;
			int* arr_coppy = new int[i];
			for (int k = 0; k < i; k++) {
				arr_coppy[k] = rand() % 100;
			}
			QuickSort(arr_coppy, 0, i-1, count_QuickSort);
			OutData << i << ';' << count_QuickSort << endl;
			i += 10;
			delete[]arr_coppy;
		}
		OutData.close();
		cout << "end" << endl;
		break;
	}
	case 5: {
		ofstream OutData;

		OutData.open("CountingSort.csv");
		int i = 1;
		while (i <= n + 1) {
			int* arr_coppy = new int[i];
			for (int k = 0; k < i; k++) {
				arr_coppy[k] = rand() % 100;
			}
			int counn=CountingSort(arr_coppy, i);
			OutData << i << ';' << counn << endl;
			i += 10;
			delete[]arr_coppy;
		}
		OutData.close();
		cout << "end" << endl;
		break;
	}
	case 6: {
		ofstream OutData;
		 int count_MergeSort = 0;
		OutData.open("MergeSort.csv");
		int i = 1;
		while (i <= n + 1) {
			int* arr_coppy = new int[i];
			for (int k = 0; k < i; k++) {
				arr_coppy[k] = rand() % 100;
			}
			mergeSort(arr_coppy, 0, i - 1, i, count_MergeSort);
			OutData << i << ';' << count_MergeSort << endl;
			i += 10;
			count_MergeSort = 0;
			delete[]arr_coppy;
		}
		OutData.close();
		cout << "end" << endl;
		break;
	}
	case 7: {
		ofstream OutData;

		OutData.open("HeapSort.csv");
		int i = 1;
		while (i <= n + 1) {
			int* arr_copy = new int[i];
			for (int k = 0; k < i; k++) {
				arr_copy[k] = rand() % 100;
			}
			int counn = HeapSort(arr_copy, i);
			OutData << i << ';' << counn << endl;
			i += 10;
			delete[]arr_copy;
		}
		OutData.close();
		cout << "end" << endl;
		break;
	}
	default:
		break;
	}
}