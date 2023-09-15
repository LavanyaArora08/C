#include <stdio.h>

int main() {

    char obj[10][10];
    float profit[10], weight[10], profitperKG[10], temp[10];
    //int addedObj[10];
    int addedWeight[10];
    int weightofBag, n;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    printf("Enter the weight of the bag: ");
    scanf("%d", &weightofBag);

    printf("Enter the objects, their profit & their weight: ");
    for (int i=0; i<n; i++) {
        scanf("%s%f%f", &obj[i], &profit[i], &weight[i]);
    }

    for (int i=0; i<n; i++) {
        float ans = profit[i]/weight[i];
        profitperKG[i] = ans;
        temp[i] = ans;
    }

    while (weightofBag) {
        for (int i=0; i<n; i++) {
            int max = temp[0], index;
            for (int j=0; j<n; j++) {
                if (temp[j] > max) {
                    max = temp[j];
                    index = j;
                }
            }
            temp[max] = 0;

            if (weightofBag > weight[index]) {
                weightofBag = weightofBag - weight[index];
                //addedObj[i] = index;
                addedWeight[i] = weight[index];
            }
            else {
                //addedObj[i] = index;
                addedWeight[i] = weightofBag;
            }
        }
    }

    int profitMade;
    for (int i=0; i<n; i++) {
        profitMade = profitMade + (profitperKG[i]*addedWeight[i]);
    }

    printf("The profit made is: %d", profitMade);

    return 0;
}
