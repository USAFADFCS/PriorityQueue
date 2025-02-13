/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Priority Queue ADT implemented using linked list
 * Purpose: Priority Queue ADT library - FIFO
 * ===========================================================
 */

#include "priorityQueueAsLinkedList.h"

int main() {
    PriorityQueueAsLinkedList* pq = priorityQueueInit();

    // Try Adding Different Items to the Priority Queue Here
    priorityQueueEnqueue(pq, 5, 2);
    priorityQueueEnqueue(pq, 6, 1);
    priorityQueueEnqueue(pq, 7, 1);
    priorityQueueEnqueue(pq, 7, 3);

    // Prints the Priority Queue
    priorityQueuePrint(pq);
}