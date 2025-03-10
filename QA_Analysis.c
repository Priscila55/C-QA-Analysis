/*
Program description:
Algorithm design CA project  
 
Author: Priscila
 
Date: 2/4/24
 
*/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
#define SIZE 50
#define DATA 12
 
struct DateTime
{
    int day;
    int hour;
    int minute;
};
struct issueCode
{
int issue;
 char issueDescription[SIZE];
};
struct resolutionIssue
{
  int resolution;
  char resolutionDescription[SIZE];
};
 
struct LogLineProduction
{
    int lineCode;
    int batchCode;
    struct DateTime dateTime;
    int productId;
    int issueCode;
    char description[SIZE];
    int employeeId;
    struct resolutionIssue;
    struct issueCode;
};
struct node 
{
    struct node *link;
    struct LogLineProduction datas;
};

// functions for task 1 - merge sort
void merge_sort(struct LogLineProduction *data, int size);
void merge_sort_recursion(struct LogLineProduction *data, int left, int right);
void merge_logs(struct LogLineProduction *data, int left, int middle, int right);
void print_sort(struct LogLineProduction *data, int size);
// functions for task 2 - linked sort
int count_node(struct node **, struct LogLineProduction datas);
void linkedList(struct LogLineProduction []); 
void printLinkedList(struct node *);
// function for task 3 - binary search
int binarySearch(struct LogLineProduction data[], int , int, int);
// functions for task 4 - linear search
void linearSearch(struct LogLineProduction [], int);
int main()
{
    
    // Binary search 
    int productId; //  product ID for which you want to find the earliest occurrence and issue code
    int issueCode;
    int i;

    // Line entry 1
    struct LogLineProduction data1[DATA] = {
    {1, 102, {1, 5, 15}, 1002, 20, "Input/Errors", 102, "Resolved by updating input validation logic."},
    {1, 110, {1, 20, 45}, 1010, 10, "Machine malfunction", 110, "Resolved by replacing faulty component."},
    {1, 107, {1, 13, 0}, 1007, 10, "Packaging error", 107, "Resolved by implementing additional quality checks."},
    {1, 103, {1, 9, 45}, 1003, 30, "Shipping delay", 103, "Resolved by expediting shipping process."},
    {1, 106, {1, 12, 0}, 1006, 30, "Product damage", 106, "Resolved by improving handling procedures."},
    {1, 111, {1, 17, 0}, 1011, 20, "Incorrect labelling", 111, "Resolved by updating labeling process."},
    {1, 105, {1, 11, 0}, 1005, 20, "Raw material shortage", 105, "Resolved by sourcing alternative suppliers."},
    {1, 104, {1, 10, 20}, 1004, 10, "Equipment failure", 104, "Resolved by conducting preventive maintenance."},
    {1, 101, {1, 8, 30}, 1001, 10, "Staff shortage", 101, "Resolved by hiring temporary staff."},
    {1, 109, {1, 15, 0}, 1009, 30, "Environmental hazard", 109, "Resolved by implementing safety measures."},
    {1, 112, {1, 18, 0}, 1012, 30, "Transportation issue", 112, "Resolved by optimizing transportation routes."},
    {1, 108, {1, 14, 0}, 1008, 20, "Customer complaint", 108, "Resolved by providing compensation or replacement."}
};
 
// Line entry 2
struct LogLineProduction data2[DATA] = {
    {2, 211, {2, 18, 0}, 2011, 30, "Raw material shortage", 123, "Resolved by sourcing alternative suppliers."},
    {2, 202, {2, 9, 30}, 2002, 30, "Incorrect labelling", 114, "Resolved by updating labeling process."},
    {2, 206, {2, 13, 0}, 2006, 10, "Environmental failure", 118, "Resolved by implementing safety measures."},
    {2, 207, {2, 14, 0}, 2007, 20, "Packaging error", 119, "Resolved by implementing additional quality checks."},
    {2, 210, {2, 17, 0}, 2010, 20, "Product damage", 122, "Resolved by improving handling procedures."},
    {2, 208, {2, 15, 0}, 2008, 30, "Input/Errors", 120, "Resolved by updating input validation logic."},
    {2, 203, {2, 10, 15}, 2003, 10, "Staff shortage", 115, "Resolved by hiring temporary staff."},
    {2, 204, {2, 11, 0}, 2004, 20, "Customer complaint", 116, "Resolved by providing compensation or replacement."},
    {2, 212, {2, 19, 0}, 2012, 10, "Machine malfunction", 124, "Resolved by replacing faulty component."},
    {2, 205, {2, 12, 0}, 2005, 30, "Transportation issue", 117, "Resolved by optimizing transportation routes."},
    {2, 201, {2, 8, 45}, 2001, 20, "Equipment hazard", 113, "Resolved by conducting preventive maintenance."},
    {2, 209, {2, 16, 0}, 2009, 10, "Shipping delay", 121, "Resolved by expediting shipping process."}
    };
    // Line entry 3
 
struct LogLineProduction data3[DATA] = {
    {3, 303, {3, 10, 0}, 3003, 20, "Transportation issue", 127, "Resolved by optimizing transportation routes."},
    {3, 308, {3, 15, 0}, 3008, 10, "Packaging error", 132, "Resolved by implementing additional quality checks."},
    {3, 307, {3, 14, 0}, 3007, 30, "Customer complaint", 131, "Resolved by providing compensation or replacement."},
    {3, 310, {3, 17, 0}, 3010, 30, "Product damage", 134, "Resolved by improving handling procedures."},
    {3, 301, {3, 8, 0}, 3001, 30,  "Shipping delay ", 125, "Resolved by expediting shipping process."},
    {3, 306, {3, 13, 0}, 3006, 20, "Equipment hazard", 130, "Resolved by conducting preventive maintenance."},
    {3, 304, {3, 11, 0}, 3004, 30, "Raw material shortage", 128, "Resolved by sourcing alternative suppliers."},
    {3, 311, {3, 18, 0}, 3011, 10, "Incorrect labelling", 135, "Resolved by updating labeling process."},
    {3, 305, {3, 12, 0}, 3005, 10, "Environmental failure", 129, "Resolved by implementing safety measures."},
    {3, 302, {3, 9, 0}, 3002, 10,  "Input/Errors", 126, "Resolved by updating input validation logic."},
    {3, 312, {3, 19, 0}, 3012, 20, "Staff shortage", 136, "Resolved by hiring temporary staff."},
    {3, 309, {3, 16, 0}, 3009, 20, "Machine malfunction", 133, "Resolved by replacing faulty component."}
};
   // Line entry 4
struct LogLineProduction data4[DATA] = {
   {4, 405, {4, 12, 15}, 4005, 20, "Equipment hazard", 141, "Resolved by conducting preventive maintenance."},
    {4, 408, {4, 15, 15}, 4008, 20, "Product damage", 144, "Resolved by improving handling procedures."},
    {4, 404, {4, 11, 15}, 4004, 10, "Input/Errors", 140, "Resolved by updating input validation logic."},
    {4, 401, {4, 8, 15}, 4001, 10,  "Machine malfunction", 137, "Resolved by replacing faulty component."},
    {4, 406, {4, 13, 15}, 4006, 30, "Staff shortage", 142, "Resolved by hiring temporary staff."},
    {4, 409, {4, 16, 15}, 4009, 30, "Customer complaint", 145, "Resolved by providing compensation or replacement."},
    {4, 402, {4, 9, 15}, 4002, 20,  "Packaging error", 138, "Resolved by implementing additional quality checks."},
    {4, 407, {4, 14, 15}, 4007, 10, "Raw material shortage", 143, "Resolved by sourcing alternative suppliers."},
    {4, 403, {4, 10, 15}, 4003, 30, "Transportation issue", 139, "Resolved by optimizing transportation routes."},
    {4, 410, {4, 17, 15}, 4010, 10, "Staff shortage", 146, "Resolved by hiring temporary staff."},
    {4, 411, {4, 18, 15}, 4011, 20, "Incorrect labelling", 147, "Resolved by updating labeling process."},
    {4, 412, {4, 19, 15}, 4012, 30, "Shipping delay", 148, "Resolved by expediting shipping process."}
};


 // Merge sort 
    printf("\n\nReport 1:");
 
    print_sort(data1, DATA);
 
    printf("\n\nReport 2:");
 
    print_sort(data2, DATA);
    
    printf("\n\nReport 3:");
 
    print_sort(data3, DATA);
 
    printf("\n\nReport 4:");
 
    print_sort(data4, DATA);

    // Linked list 
   linkedList(data1);
   linkedList(data2);
   linkedList(data3);
   linkedList(data4);

    // Binary search

    printf("\nEnter the product Id : \n"); // prompt the user to enter a product id
    scanf("%d", &productId);
    printf("\nEnter the issue code : \n"); // prompt the user to enter an issue code
    scanf("%d", &issueCode); 
     int earliestOccurrence = binarySearch(data1, DATA, productId, issueCode);
     if (earliestOccurrence != -1) 
     { // beginning of if
    printf("\nEarliest occurrence of product ID %d found at index %d in data1\n", productId, earliestOccurrence, issueCode);
    printf("\nIssue code for product ID %d: %d\n", productId, data1[earliestOccurrence].issueCode);
     } // end if
    else
   { // beginning of else
    printf("\nProduct ID %d and issue code %d not found at data1\n", productId, issueCode);
   } // end else
     earliestOccurrence = binarySearch(data2, DATA, productId, issueCode);
     if (earliestOccurrence != -1) 
     { // beginning of if
    printf("\nEarliest occurrence of product ID %d found at index %d in data2\n", productId, earliestOccurrence, issueCode);
    printf("\nIssue code for product ID %d: %d\n", productId, data2[earliestOccurrence].issueCode);
     } // end if
    else
   { // beginning of else
        printf("\nProduct ID %d and issue code %d not found at data2\n", productId, issueCode);
   } // end else
     earliestOccurrence = binarySearch(data3, DATA, productId, issueCode);
     if (earliestOccurrence != -1) 
     { // beginning of if
    printf("\nEarliest occurrence of product ID %d found at index %d in data3\n", productId, earliestOccurrence, issueCode);
    printf("\nIssue code for product ID %d: %d\n", productId, data3[earliestOccurrence].issueCode); 
     } // end if
    else
   { // beginning of else
        printf("\nProduct ID %d and issue code %d not found at data3\n", productId, issueCode);
   } // end else
     earliestOccurrence = binarySearch(data4, DATA, productId, issueCode);
     if (earliestOccurrence != -1) 
     { // beginning of if
    printf("\nEarliest occurrence of product ID %d found at index %d in data4\n", productId, earliestOccurrence, issueCode);
    printf("\nIssue code for product ID %d: %d\n", productId, data4[earliestOccurrence].issueCode);
     } // enf if
    else
   { // beginning of else
        printf("\nProduct ID %d and issue code %d not found at data4\n", productId, issueCode);
   } // end else


 
   // Linear search 
    // Perform linear search for each array
    printf("\nReport for data1:\n\n");
    linearSearch(data1, DATA);
    printf("\n\nReport for data2:\n\n");
    linearSearch(data2, DATA);
    printf("\n\nReport for data3:\n\n");
    linearSearch(data3, DATA);
    printf("\n\nReport for data4:\n\n");
    linearSearch(data4, DATA);

   
    return 0;
}
// Task 1
// merge sort
void merge_sort(struct LogLineProduction *data, int size)
{
    merge_sort_recursion(data, 0, size - 1);
} // end of function merge_sort()
 
// function that handles recursion 
void merge_sort_recursion(struct LogLineProduction *data, int left, int right)
{
    if (left < right) // checks for duplicates in the dataset for the structure logLineProduction
    {
        int middle = left + (right - left) / 2; // calculate the middle 
 
        merge_sort_recursion(data, left, middle); // does the recursive calls 
        merge_sort_recursion(data, middle + 1, right);
 
        merge_logs(data, left, middle, right);
    }
}
 
void merge_logs(struct LogLineProduction *data, int left, int middle, int right)
{
    // calculate the sizes of the left and right temporary arrays
    int leftSize = middle - left + 1;
    int rightSize = right - middle;
 
    // Temporary arrays
    struct LogLineProduction leftArray[leftSize];
    struct LogLineProduction rightArray[rightSize];
 
    // Copy data to the temporary arrays
    for (int i = 0; i < leftSize; i++)
        leftArray[i] = data[left + i];
    for (int j = 0; j < rightSize; j++)
        rightArray[j] = data[middle + 1 + j];
 
     int i = 0; 
     int j = 0;
     int k = left;
 
    // Merge temporary arrays back into data
    while (i < leftSize && j < rightSize)
    {
        if (leftArray[i].dateTime.day <= rightArray[j].dateTime.day)
        {
            data[k] = leftArray[i];
            i++;
        } // end if
        else
        {
            data[k] = rightArray[j];
            j++;
        } // end else
        k++;
    } // end main while
 
    // Copy the remaining elements of leftArray
    while (i < leftSize)
    {
        data[k] = leftArray[i];
        i++;
        k++;
    } // end while
 
    // Copy the remaining elements of rightArray
    while (j < rightSize)
    { // beginning of while
        data[k] = rightArray[j];
        j++;
        k++;
    } // end while
} // end function merge_logs()
void print_sort(struct LogLineProduction *data, int size)
{
    merge_sort(data, size);
 
    for (int i = 0; i < size; i++)
    {
        printf("\n-----------------------------");
        printf("\n\nRecord %d\n", i + 1);
        printf("\nLine Code: %d", data[i].lineCode);
        printf("\nBatch Code: %d", data[i].batchCode);
        printf("\nDate & Time: %d:%d:%d", data[i].dateTime.day, data[i].dateTime.hour, data[i].dateTime.minute);
        printf("\nProduct ID: %d", data[i].productId);
        printf("\nIssue Code: %d", data[i].issueCode);
       // printf("\nDescription: %s", data[i].description);
       // printf("\nEmployee ID: %d\n", data[i].employeeId);
    } // end for
} // end function print_sort()
 
// Task 2
// function signatures linked list
// the node represents the head of the linked list 
// The struct with data
int count_nodes(struct node **head, struct LogLineProduction datas) 
{
    // Allocate memory for the new node 
   struct node *nextNode = malloc(sizeof(struct node)); // to ensure that enough memory is allocated to hold struct node and malloc returns the pointer
  // Check if memory allocation was successful
   if(nextNode == NULL)
   {
     printf("Failed to allocate memory\n");
     return -1; // return if it doesn't allocate the memory
   }
   // Assign the data to the new node
   nextNode->datas = datas;
   nextNode->link = NULL; // indicates it doesn't point to any other node
   // if the list is empty, set the new node as the head
   if(*head == NULL)
   {
    *head = nextNode;
   } // end if
   // If the list is not empty, traverse to the end and append the new node
   else 
   {
    struct node *temp_arr = *head;
    while (temp_arr->link != NULL)
    {
      temp_arr = temp_arr->link;
    }
    temp_arr->link = nextNode;
   }
   return 0;
} // end count_node function
// Function to create linked list from array of LogLineProduction data
 void linkedList(struct LogLineProduction datas[])
{
    // Initialize head pointer to NULL
    struct node *head = NULL;
    // Iterate through the array of data and append each element to the linked list
    for (int i = 0; i < DATA; i++)
    {
        count_nodes(&head, datas[i]);
    } // end for loop 
     // Print the linked list
    printLinkedList(head);
     // Free memory allocated for the linked list nodes
    struct node *temp = head;
    while (temp != NULL)
    {
        struct node *next = temp->link;
        free(temp);
        temp = next;
    }
} // end of function linkedList()
// Function to print the elements of the linked list
void printLinkedList(struct node *head)
{
    // Initialize a temporary pointer to traverse the linked list
    struct node *temp = head;
    // Print the column headers
    printf("\n\nProduct ID\tLine ID\t\tIssue Codes\n");
    while (temp != NULL)//while loop to display the content for the linked list for each production line
    {//beginning of while loop
      // Print the data of the current node
        printf("%d\t\t%d\t\t%d\n", temp->datas.productId, temp->datas.lineCode, temp->datas.issueCode);
        //move temp to the next node in the linked list
        temp = temp->link;
    }//end of while loop
} // end of function printLinkedList()


// Task 3 Binary search
// Binary Search
int binarySearch(struct LogLineProduction data[], int size, int productId, int issueCode) {
    int left = 0;
    int right = size - 1;
    int earliestOccurrence = -1;
    while (left <= right)
     { // beginning of while loop 
        int middle = left + (right - left) / 2;
        if (data[middle].productId == productId && data[middle].issueCode == issueCode) 
        { // beginning of if
            earliestOccurrence = middle;
            right = middle - 1; // Search for earlier occurrences
        } else if (data[middle].productId < productId || (data[middle].productId == productId && data[middle].issueCode < issueCode)) 
        { // beginning of else if
            left = middle + 1;
        } // end else if
        else 
        { 
            right = middle - 1;
        } // end else 
    }
    return earliestOccurrence;
} // end of binarySearch() function

// Task 4
// Function to perform linear search
void linearSearch(struct LogLineProduction data[], int data_record) 
{
    // Loop through the array 
    for(int i = 0; i < data_record; i++)
    {
        // Get the product ID at index i
        int productId = data[i].productId;
         // Initialize the count of issues for the current product ID
        int issues = 1;
         // Iterate through the remaining elements to count occurrences of the same product ID
        for(int j = i + 1; j < data_record; j++)
        { // beginning of for
             // Ccheck if the product ID matches 
            if (productId == data[j].productId)
            { // beginning of if
                issues = issues + 1; // increment the issue count
            } // end if
        } // end for
        // Print the product ID and its corresponding issue count
        printf("\nProduct Id : %d, Issues : %d\n", productId, issues);
        // Move to the next unique product ID by skipping consecutive identical product IDs
        while (i + 1 < data_record && productId == data[i + 1].productId)
        { // beginning of while
            i = i + 1;
        } // end while
    } // end for
} // end function linearSearch()

