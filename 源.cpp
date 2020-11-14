#include <stdio.h>
void bubble_sort(int arr[], int len) {
    int i, j, tmp;
    for(i=0;i<len;i++)
        for (j = 0; j < len; j++) {
            if (arr[j] < arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
}
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void select_sort(int arr[],int len){
    int i, j;
    for (i = 0; i < len - 1; i++) {
        int min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                swap(&arr[j], &arr[min]);
            }
        }
    }
}
void insert_sort(int arr[], int len) {
    int i, j, tmp;
    for (i = 1; i < len; i++) {
        tmp = arr[i];
        for (j = i; j > 0 && arr[j - 1] > tmp;j--)
            arr[j] = arr[j - 1];
        arr[j] = tmp;      //这条语句的j是上条语句的j-1     
        }
}
void shell_sort(int arr[],int len) {
    int i, j, increment;
    for (increment = len/2; increment >= 1; increment /= 2) {
        for (i = increment; i < len; i++) {
            int tmp = arr[i];
            for (j = i - increment; j >= 0 && arr[j] > arr[i]; j -= increment)
                arr[j + increment] = arr[j];
            arr[j + increment] = tmp;   //这条语句的j是上条语句的j-increment
        }
        }
}
void merge(int arr[], int start, int mid,int end) {
    int result[20] = {0};
    int i,j, k;
    mid = (start + end) / 2;
    i = start;
    j = mid + 1;
    k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            result[k++] = arr[i++];
        }
        else {
            result[k++] = arr[j++];
        }
    }
    if (i == mid + 1) {
        while (j <= end)
            result[k++] = arr[j++];
    }
    if (j == end + 1) {
        while (i <= mid)
            result[k++] = arr[i++];
    }
    for (j = 0, i = start; j < k; i++, j++) {
        arr[i] = result[j];
    }
}
void mergeSort(int arr[], int start, int end) {
    if (start >= end)
        return;
    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}
void quick_sort(int arr[],int low,int high) {
    int first = low;
    int last = high;
    int key = arr[first];
    if (low >= high) {
        return;
    }
    while (first < last)
    {
        while (first<last && arr[last]>key)
            last--;
        arr[first] = arr[last];
        
        while (first < last && arr[first] < key)
                first++;    
        arr[last] = arr[first];
    }
    arr[first] = key;
    quick_sort(arr, low, first - 1);
    quick_sort(arr, first + 1, high);
}
int main(int argc, char* argv[])
{
    int arr[] = { 22, 34, 3, 32, 82 , 56 , 35 };
    int len = (int)sizeof(arr) / sizeof(*arr);
    quick_sort(arr, 0,6);
    for (int i = 0; i < 6; i++)
        printf("%d ", arr[i]);
    return 0;
}