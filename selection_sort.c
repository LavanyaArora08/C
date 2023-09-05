// perform selection sort on an array entered by a user, and make a number of steps vs size of array graph to calculate the time complexity of selection sort
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void plot_graph(double *x, double *y, int n) {
    FILE *gp;
    gp = popen("gnuplot", "w");
    fprintf(gp, "set title \"Time Complexity of Selection Sort\"\n");
    fprintf(gp, "set xlabel \"Size of array\"\n");
    fprintf(gp, "set ylabel \"Time (in seconds)\"\n");
    fprintf(gp, "plot '-' with lines title \"Time Complexity of Selection Sort\"\n");
    for (int i = 0; i < n; i++) {
        fprintf(gp, "%d %f\n", i + 1, y[i]);
    }
    fprintf(gp, "e\n"); // add a delay to keep the graph window open
}

int main() {
    int n, i, j, temp, f = 0;
    // printf("Enter n ");
    // scanf("%d",&n);
    // if(n==0)
    // {
    //     printf("Empty array");
    //     return 0;
    // }
    // int arr[n];
    // for(i=0;i<n;i++,f++)
    // {
    //     printf("enter value ");
    //     scanf("%d",&arr[i]);
    // }
    // array of size 10 with random values
    n = 10;
    int arr[n];
    srand(time(0));
    for (i = 0; i < n; i++, f++) {
        arr[i] = rand() % 100;
    }
    printf("Unsorted array: ");
    for (i = 0; i < n; i++, f++) {
        printf("%d ", arr[i]);
    }

    double time_complexity[n];
    clock_t start, end;
    for (i = 0; i < n; i++) {
        int arr_copy[n];
        for (j = 0; j <= i; j++) {
            arr_copy[j] = arr[j];
        }
        start = clock();
        for (j = 0; j <= i; j++) {
            int min = j;
            for (int k = j + 1; k <= i; k++) {
                if (arr_copy[k] < arr_copy[min]) {
                    min = k;
                }
            }
            int temp = arr_copy[j];
            arr_copy[j] = arr_copy[min];
            arr_copy[min] = temp;
        }
        end = clock();
        double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        time_complexity[i] = cpu_time_used;
    }

    for (i = 0; i < n; i++, f++) {
        int min = i;
        for (j = i + 1; j < n; j++, f++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("\nSorted array: ");
    for (i = 0; i < n; i++, f++) {
        printf("%d ", arr[i]);
    }
    printf("\nNumber of steps: %d", f);

    plot_graph(NULL, time_complexity, n);
}