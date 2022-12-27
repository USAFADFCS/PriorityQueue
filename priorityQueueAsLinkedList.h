/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Priority Queue ADT implemented using linked list
 * Purpose: Priority Queue ADT library - FIFO
 * ===========================================================
 */

#ifndef QUEUEASLIST_H
#define QUEUEASLIST_H
#include <stdbool.h>
#include <stddef.h>

#include "listAsLinkedList.h"

typedef LinkedList PriorityQueueAsLinkedList;

/** priorityQueueEnqueue()
 * @brief - puts an element into the queue based on its priority (lower numbers towards the front)
 *          in the event of a tie, the new node goes after the others
 * @param queue - a ptr to the queue structure
 * @param element - the value to add to the queue
 * @param priority - the priority of the value to add to the queue
 * @pre   - queue before element added
 * @post  - queue one element longer
 */
void priorityQueueEnqueue(PriorityQueueAsLinkedList* queue, double element, int priority);

/** priorityQueueDequeue()
 * @brief - removes an element from the front of the queue
 * @param queue - a ptr to the queue structure
 * @pre   - queue before element removed from the front
 * @post  - queue one element shorter
 */
double priorityQueueDequeue(PriorityQueueAsLinkedList* queue);

/** priorityQueueIsEmpty()
 * @brief  - determines if the queue is empty
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is empty or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; and empty status returned
 */
bool priorityQueueIsEmpty(PriorityQueueAsLinkedList* queue);

/** priorityQueueIsFull()
 * @brief - determines if the queue is full
 * @param queue - a ptr to the queue structure
 * @return - true if the queue is full or false
 * @pre    - queue unmodified
 * @post   - queue unmodified; always returns false
 */
bool priorityQueueIsFull(PriorityQueueAsLinkedList* queue);

/** priorityQueueInit()
 * @brief  - initializes the queue structure
 * @return - pointer to queue
 * @pre    - nothing
 * @post   - new empty queue returned
 */
PriorityQueueAsLinkedList* priorityQueueInit();

/** deletePriorityQueue()
 * @brief  - deletes queue, freeing all memory used
 * @param queue - a ptr to the queue structure
 * @pre    - unmodified queue
 * @post   - the queue is erased
 */
void deletePriorityQueue(PriorityQueueAsLinkedList* queue);

/** priorityQueuePeek()
 * @brief  - returns the item in the front of the
 *           queue but doesn't remove it
 * @param queue - a ptr to the queue structure
 * @return - the item on the top of the queue
 * @pre    - queue unmodified
 * @post   - queue unmodified; top element returned
 */
double priorityQueuePeek(PriorityQueueAsLinkedList* queue);

/** priorityQueueSize()
 * @brief  - determines the size of the queue
 * @param queue - a ptr to the queue structure
 * @return - number of items in the queue
 * @pre    - queue unmodified
 * @post   - queue unmodified; size of queue returned
 */
int priorityQueueSize(PriorityQueueAsLinkedList* queue);

/** queuePrint()
 * @brief  - outputs the queue to the console
 * @param queue - the queue structure
 * @pre    - queue unmodified
 * @post   - queue unmodified; queue elements printed
 */
void priorityQueuePrint(PriorityQueueAsLinkedList* queue);

#endif 
