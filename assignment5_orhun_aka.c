#include <stdio.h>

void print_matrix(int matrix[5][2]) {

    int rows = 2;
    int columns = 5;

    int rowsLoop;
    int columnsLoop;

    for (columnsLoop = 0; columnsLoop < columns; columnsLoop++) {

        for (rowsLoop = 0; rowsLoop < rows; rowsLoop++) {

            printf("%d\t", matrix[columnsLoop][rowsLoop]);
        }
        printf("\n");
    }
}

void print_array(int array[]) {

    int loop = 0;

    for (loop = 0; array[loop] != 0; loop++) {
        printf("%d ", array[loop]);
    }
}

int find_path(int source_matrix[5][2], int destination_array[10], int numberOfRows) {

    int flag = 1;

    int rowCheck = 1;
    int columnCheck = 1;

    int destination = 1;

    int sum = 0;
    int begin = source_matrix[0][0];

    sum = sum + begin;

    destination_array[0] = begin;

    while (flag) {
        if (rowCheck != 2 && columnCheck != 5) {

            if (source_matrix[columnCheck][rowCheck - 1] > source_matrix[columnCheck - 1][rowCheck]) {

                begin = source_matrix[columnCheck][rowCheck - 1];
                destination_array[destination] = begin;
                destination = destination + 1;
                columnCheck = columnCheck + 1;

                sum = sum + begin;
            } else if (source_matrix[columnCheck][rowCheck - 1] < source_matrix[columnCheck - 1][rowCheck]) {

                begin = source_matrix[columnCheck - 1][rowCheck];
                destination_array[destination] = begin;
                destination = destination + 1;
                rowCheck = rowCheck + 1;

                sum = sum + begin;
            }
        } else if (rowCheck == 2 && columnCheck != 5) {

            begin = source_matrix[columnCheck][rowCheck - 1];
            destination_array[destination] = begin;
            destination = destination + 1;
            columnCheck = columnCheck + 1;

            sum = sum + begin;
        } else if (rowCheck != 2 && columnCheck == 5) {

            begin = source_matrix[columnCheck - 1][rowCheck];
            destination_array[destination] = begin;
            destination = destination + 1;
            rowCheck = rowCheck + 1;

            sum = sum + begin;
        } else if (rowCheck == 2 && columnCheck == 5) {

            //sum = sum + source_matrix[columnCheck][rowCheck];
            /*destination_array[destination] = source_matrix[5][2];
            destination = destination + 1;
            destination_array[destination] = 0;*/
            flag = 0;
        }
        
    }

    print_array(destination_array);

    return sum;
}

int main() {

    int theMatrix[5][2];
    int destination_array[10];

    int numberOfColumns = 5;
    int numberOfRows = 2;

    int columnsLoop;
    int rowsLoop;

    // Enter matrix data
    for (columnsLoop = 0; columnsLoop < numberOfColumns; columnsLoop++)
    {
        for (rowsLoop = 0; rowsLoop < numberOfRows; rowsLoop++)
        {
            printf("Entering data for [%d][%d]: ", columnsLoop, rowsLoop);
            scanf("%d", &theMatrix[columnsLoop][rowsLoop]);
        }
    }

    int sum = find_path(theMatrix, destination_array, numberOfRows);

    printf("\nSum is %d", sum);

    return 0;
}