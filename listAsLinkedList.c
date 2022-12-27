/** 
 * ===========================================================
 * Name: 
 * Section: 
 * Project: Implementation of Linked List Library
 * Purpose: List ADT as linked list
 * ===========================================================
 */

#include "listAsLinkedList.h"

#include <stdio.h>
#include <stdlib.h>

Node* findSmallest(Node* firstNode);
void swapData(Node* j, Node* k);

/** createLinkedList()
 * @brief  - initializes the linked list structure
 * @return - pointer to linked list
 * @pre    - nothing
 * @post   - new empty linked list returned
 */
LinkedList* createLinkedList() {
    // allocate memory
    LinkedList* list = malloc(sizeof(LinkedList));

    // initialize as a blank list
    list->head = NULL;
    list->tail = NULL;
    list->numberOfElements = 0;

    return list;  // return blank list ptr
}

/** deleteLinkedList()
 * @brief  - deletes linked list, freeing all memory used
 * @param list - a ptr to the linked list structure
 * @pre    - unmodified linked list
 * @post   - the linked list is erased
 */
void deleteLinkedList(LinkedList* list) {
    Node* tempPtr = list->head;  // head of the list
    Node* freePtr = NULL;

    // traverse the list freeing each
    // node as you go cannot free entire
    // list as free works only on
    // contiguous blocks of memory (a node)
    while (tempPtr != NULL) {
        freePtr = tempPtr;
        tempPtr = tempPtr->next;
        free(freePtr);
    }
    free(list);
}

/** appendElementLinkedList()
 * @brief - addes a new element to the end of the linked list
 * @param list - a ptr to the linked list structure
 * @param element - the value to append to the list
 * @pre   - linked list before element added
 * @post  - linked list one element longer
 */
void appendElementLinkedList(LinkedList* list, double element, double priority) {
    // create a new node on the heap as values on the stack
    // are free'd when the function ends
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->priority = priority;
    newNode->next = NULL;

    // check to see if the list is empty and handle that
    // special case
    if (list->head == NULL) {
        list->head = newNode;
        // list is not empty append node using tail ptr
    } else {
        // point current tail node to newNode
        list->tail->next = newNode;
    }

    // set tail to newNode
    list->tail = newNode;
    list->numberOfElements++;  // increase size by 1
}

/** lengthOfLinkedList()
 * @brief  - returns the size of the linked list
 * @param list - a ptr to the linked structure
 * @return - number of items in the linked list
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; size of linked list returned
 */
int lengthOfLinkedList(LinkedList* list) {
    return list->numberOfElements;
}

/** printLinkedList()
 * @brief  - outputs the linked list to the console
 * @param list - the linked list structure
 * @pre    - linked list unmodified
 * @post   - linked list unmodified; linked list elements printed
 */
void printLinkedList(LinkedList* list) {
    Node* tempPtr = list->head;
    while (tempPtr != NULL) {
        printf("%.2f (Priority %d) -> ", tempPtr->data, tempPtr->priority);
        tempPtr = tempPtr->next;
    }
    printf("NULL\n");
}

/** getElementLinkedList()
 * @brief  - retrieves element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value requested
 * @return - node at 'position', NULL on failure
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; value at 'position' returned
 */
Node* getElementLinkedList(LinkedList* list, int position) {
    // ensure 'position' is in range
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        return NULL;
    }

    // traverse linked list until curPos == position
    int curPos = 0;
    Node* tempPtr = list->head;
    while (curPos < position) {
        curPos++;
        tempPtr = tempPtr->next;
    }

    // return value at 'position'
    return tempPtr;
}

/** deleteElementLinkedList()
 * @brief  - deletes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to delete
 * @pre    - unmodified linked list
 * @post   - modified linked list; value at 'position' removed
 */
void deleteElementLinkedList(LinkedList* list, int position) {
    // ensure 'position' is in range
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        printf("Error, position out of range\n");
        exit(0);
    }

    // traverse linked list until curPos == position
    int curPos = 0;
    Node* tempPtr = list->head;
    Node* prevPtr = NULL;
    while (curPos < position) {
        curPos++;
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (tempPtr == list->head && tempPtr == list->tail) {
        // only 1 item in list
        list->head = NULL;
        list->tail = NULL;
    } else if (tempPtr == list->head) {
        // removing head
        list->head = tempPtr->next;
    } else if (tempPtr == list->tail) {
        // removing tail
        list->tail = prevPtr;
        list->tail->next = NULL;
    } else {
        // internal node
        prevPtr->next = tempPtr->next;
    }

    // decrease size by 1
    list->numberOfElements--;
    free(tempPtr);  // free memory of element removed
}

/** insertElementLinkedList()
 * @brief  - adds element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - value to be added
 * @pre    - unmodified linked list
 * @post   - modified linked list; value add at 'position'
 */
void insertElementLinkedList(LinkedList* list, int position, double element, int priority) {
    // ensure 'position' is in range
    if (list->numberOfElements < position) {
        printf("Error, position out of range\n");
        exit(0);
    }

    // create a new node on the heap as values on the stack
    // are free'd when the function ends
    Node* newNode = malloc(sizeof(Node));
    newNode->data = element;
    newNode->priority = priority;
    newNode->next = NULL;

    // traverse linked list until curPos == position
    int curPos = 0;
    Node* tempPtr = list->head;
    Node* prevPtr = NULL;
    while (tempPtr != NULL && curPos < position) {
        curPos++;
        prevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }

    if (tempPtr == NULL) {
        // empty list
        list->head = newNode;
        list->tail = newNode;
    } else if (tempPtr == list->head) {
        // insert at the head
        list->head = newNode;
        newNode->next = tempPtr;
    } else {
        // insert internally
        newNode->next = tempPtr;
        prevPtr->next = newNode;
    }

    // increase number of elements
    list->numberOfElements++;
}

/** changeElementLinkedList()
 * @brief  - changes element at a given position
 * @param  list - a ptr to the linked list structure
 * @param  position - index of value to add
 * @param  element - new value
 * @pre    - unmodified linked list
 * @post   - modified linked list; value changed at 'position'
 */
void changeElementLinkedList(LinkedList* list, int position, double newElement) {
    // ensure 'position' is in range
    if (list->numberOfElements == 0 || list->numberOfElements <= position) {
        printf("Error\n");
        exit(0);
    }

    // traverse linked list until curPos == position
    int curPos = 0;
    Node* tempPtr = list->head;
    while (curPos < position) {
        curPos++;
        tempPtr = tempPtr->next;
    }

    // set new value
    tempPtr->data = newElement;
}

/** findElementLinkedList()
 * @brief  - finds the postion of a given element, if it exists
 * @param  list - a ptr to the linked list structure
 * @param  element - value to find
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; position returned if found
 */
int findElementLinkedList(LinkedList* list, double element) {
    // traverse linked list until end is reached or value found
    int curPos = 0;
    Node* tempPtr = list->head;
    while (tempPtr != NULL && tempPtr->data != element) {
        curPos++;
        tempPtr = tempPtr->next;
    }

    if (tempPtr != NULL) {
        return curPos;  // value found
    } else {
        return -1;  // value not found
    }
}

/** insertSortLinkedList()
 * @brief - Perform an insertion sort on a LinkedList
 * @param list - the LinkedList to sort
 * @pre    - unmodified linked list
 * @post   - sorted linked list
 */
void insertSortLinkedList(LinkedList* list) {
    double insertElem;
    Node* tempPtr = list->head->next;  // element 1
    Node* tempPrevPtr = list->head;    // element 0
    Node* insPtr;
    Node* insPrevPtr = list->head;

    while (tempPtr != NULL) {
        insertElem = tempPtr->data;                               // the item to insert
        insPtr = list->head;                                      // element 0
        while (insPtr->data < insertElem && insPtr != tempPtr) {  // find the insertion
            insPrevPtr = insPtr;
            insPtr = insPtr->next;
        }
        if (insPtr != tempPtr) {
            // swap
            tempPrevPtr->next = tempPtr->next;
            tempPtr->next = insPtr;
            insPrevPtr->next = tempPtr;
            if (insPtr == list->head) {
                list->head = insPtr;
            }
        }

        // move boundary over by 1
        tempPrevPtr = tempPtr;
        tempPtr = tempPtr->next;
    }
}

/** selSortLinkedList()
 * @brief - Perform an selection sort on a LinkedList
 * @param list - the LinkedList to sort
 * @pre    - unmodified linked list
 * @post   - sorted linked list
 */
void selSortLinkedList(LinkedList* list) {
    Node* tempPtr = list->head;
    Node* nodeWithSmallest;
    while (tempPtr != NULL) {
        // select smallest
        nodeWithSmallest = findSmallest(tempPtr);
        swapData(tempPtr, nodeWithSmallest);  // swap
        tempPtr = tempPtr->next;              // move boundary
    }
}

/** findSmallest()
 * @brief - Find the node that contains the smallest
 *          element in a sub-section of a LinkedList
 * @param firstNode - the node in the LinkedList to start the search
 * @return - a pointer to the node that contains the smallest element
 * @pre    - unmodified linked list
 * @post   - unmodified linked list; pointer returned
 */
Node* findSmallest(Node* firstNode) {
    // traverse the list until nodePtr == NULL
    Node* nodeWithSmallest = firstNode;
    Node* nodePtr = firstNode;
    while (nodePtr != NULL) {
        if (nodePtr->data < nodeWithSmallest->data) {
            nodeWithSmallest = nodePtr;  // set smallest
        }
        nodePtr = nodePtr->next;
    }
    return nodeWithSmallest;  // return smallest
}

/** swapData()
 * Given a array and two positions within the array, swap the contents
 * of the two positions.
 * @param array - the array to change
 * @param j - one location in the array
 * @param k - another location in the array
 * @pre     - node j and k unmodified
 * @post    - data in both nodes swaped
 */
void swapData(Node* j, Node* k) {
    double temp = j->data;
    j->data = k->data;
    k->data = temp;
}