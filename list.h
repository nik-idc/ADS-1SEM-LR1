#pragma once
#ifndef LIST_H
#define LIST_H

#include <iostream>

class node
{
public:
	std::string data; // Data variable to store whatever the user wants to store
	node* next; // Pointer to next element
	node* prev; // Pointer to previous element

	node() // Basic constructor of node class
	{
		data = "0";
		next = NULL;
		prev = NULL;
	}
};

class list
{
public:
	// Basic constructor of list class. Assignes NULL to head and tail
	list();

	// 'list' class object destructor
	~list();

	// Adds an element at the end of the list
	void pushBack(std::string data);
	
	// Adds an element at the start of the list
	void pushFront(std::string data);

	// Removes an element at the end of the list
	void popBack();

	// Removes an element at the start of the list
	void popFront();

	// Returns data form an element at index 'index'
	std::string at(int index);

	// Inserts a new element with elements's data being 'data' inside the list at index 'index'
	void insert(std::string data, int index);
	
	// Removes an element at index 'index' from the list
	void remove(int index);

	// Return the size of the current list
	int getSize();

	// Prints the list's elements to console
	void printToConsole();

	// Checks if the list is empty. As long as head is not NULL list is considered initialised
	bool isEmpty();

	// Removes all elements from the list
	void clear();

	// Changes the data of the element at index 'index' to 'data'
	void set(std::string data, int index);

	// Inserts a sub-list inside the main list
	void insertSubList(list &subList, int index);
private:
	node* head; // Head of the list
	node* tail; // Tail of the list
};

#endif