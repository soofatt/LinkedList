#include "unity.h"
#include "LinkedList.h"

void setUp() {}
void tearDown() {}

void test_createLinkedList_should_return_LinkedList_object(){
	LinkedList *list;
	
	list = createLinkedList();
	TEST_ASSERT_NOT_NULL(list);
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0, list->length);
}

/*void dumpLinkedList(LinkedList *list){
	Element *elem;
	printf("head: %p, tail:%p, length:%d\n", list->head, list->tail, list->length);
	for(elem = list->head; elem != NULL; elem = elem->next){
		printf("data: %d, addr: %p\n", elem->data, elem);
	}
}

void test_no_test_but_playing_around(){
	LinkedList *list = createLinkedList();
	Element arrayElem[3] = {{.next = &arrayElem[1], .data = 1},
							{.next = &arrayElem[2], .data = 2},
							{.next = NULL, .data = 3}};
							
	list->head = &arrayElem[0];
	list->length = 3; 
	dumpLinkedList(list);
}*/

void test_list_removeLast_should_remove_last_element_with_1_element(){
	LinkedList *list;
	list = createLinkedList();
	
	Element arrayElem[] = {{.next = NULL, .data = 1}};
	list->length = 1;
	list->head = &arrayElem[0];
	list->tail = &arrayElem[(list->length) - 1];
	
	printf("Addr of arrayElem[0]: %p\n", &arrayElem[0]); //Address of returned element
	
	TEST_ASSERT_EQUAL_PTR(&arrayElem[0], list_removeLast(list));
	TEST_ASSERT_NULL(list->head);
	TEST_ASSERT_NULL(list->tail);
	TEST_ASSERT_EQUAL(0, list->length);
	
}