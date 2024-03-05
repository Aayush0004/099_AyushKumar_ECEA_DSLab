/*
NAME :- AYUSH KUMAR
BRANCH :- ECE A
ROLL NUMBER :- 2023ECE099
EXAM ROLL NUMBER :- 23294917099
ENROLLMENT NUMBER :- 23DOECBTEC000099
*/
#include <stdio.h>

#define MAX 10

void sparseMatrix(int arr[MAX][MAX], int r, int c) {
    int ctr = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            if(arr[i][j] == 0) {
                ctr++;
            }
        }
    }

    if(ctr > (r * c) / 2) {
        printf("The given matrix is a sparse matrix.\n");
        int nonZero = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(arr[i][j] != 0) {
                    nonZero++;
                }
            }
        }

        int sparseArr[nonZero][3];
        int index = 0;
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                if(arr[i][j] != 0) {
                    sparseArr[index][0] = i;
                    sparseArr[index][1] = j;
                    sparseArr[index][2] = arr[i][j];
                    index++;
                }
            }
        }

        printf("Sparse Matrix Representation:\n");
        printf("row\tcolumn\tvalue\n");
        for(int i = 0; i < nonZero; i++) {
            printf("%d\t%d\t%d\n", sparseArr[i][0], sparseArr[i][1], sparseArr[i][2]);
        }
    } else {
        printf("The given matrix is not a sparse matrix.\n");
    }
}

int main() {
    int arr[MAX][MAX];
    int r, c;

    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of the matrix:\n");
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    sparseMatrix(arr, r, c);

    return 0;
}
