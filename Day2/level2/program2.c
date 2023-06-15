/*W.A.P to compare the items in a box, assume equal size boxes
Boxes shall have unique items stored in random order
Boxes are compared True if there is one to one mapping of items
return the final result 1 or 0

Example of Equal Boxes:
A[3] = {200, 10, -90}
B[3] = {-90, 200, 10}    

Example of Unequal Boxes:
A[3] = {200, 9, -90}
B[3] = {-90, 200, 10}    

Note: The array should not be sorted

Topics to be covered
- Arrays
- Loops
- Basic Operators*/



#include <stdio.h>

int compareBoxes(int A[], int B[], int size) {
    int i, j, found;

    // Initialize array to mark items in box B as found
    int visited[size];
    for (i = 0; i < size; i++)
        visited[i] = 0;

    // Compare items in the box A with box B
    for (i = 0; i < size; i++) {
        found = 0;
        for (j = 0; j < size; j++) {
            if (A[i] == B[j] && !visited[j]) {
                found = 1;
                visited[j] = 1;
                break;
            }
        }
        if (!found)
            return 0; // Items don't match
    }

    // Check if all items in box B were visited
    for (i = 0; i < size; i++) {
        if (!visited[i])
            return 0; // Items don't match
    }

    return 1; // Items match
}

int main() {
    int size;
    printf("Enter the size of the boxes: ");
    scanf("%d", &size);

    int A[size], B[size];

    printf("Enter the items in box A:\n");
    for (int i = 0; i < size; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("Enter the items in box B:\n");
    for (int i = 0; i < size; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d", &B[i]);
    }

    int result = compareBoxes(A, B, size);

    printf("Result: %d\n", result);

    return 0;
}
