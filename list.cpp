#include "list.h"

list::list()
{
	head = NULL;
	tail = NULL;
}

void list::pushBack(std::string data)
{
	if (!head)
	{
		head = new node;
		head->prev = NULL;
		head->next = NULL;
		head->data = data;
	}
	else
	{
		node *newTail = new node, *last;

		if (tail)
			last = tail;
		else
			last = head;

		newTail->prev = last;
		last->next = newTail;
		newTail->data = data;
		tail = newTail;
	}
}

void list::pushFront(std::string data)
{
	if (!head)
	{
		head = new node;
		head->prev = NULL;
		head->next = NULL;
		head->data = data;
	}
	else
	{
		node *newHead = new node;

		newHead->prev = NULL;
		newHead->next = head;
		newHead->data = data;
		head->prev = newHead;
		head = newHead;

		if (!tail)
		{
			tail = head->next;
			tail->prev = head;
		}
	}
}

void list::popBack()
{
	if (head && !tail)
	{
		delete head;
		head = NULL;
	}
	else if (head && tail)
	{
		node *temp = tail->prev;
		tail->prev->next = NULL;
		delete tail;
		tail = temp;
		if (tail == head)
			tail = NULL;
	}
}

void list::popFront()
{
	if (head && !tail)
	{
		delete head;
		head = NULL;
	}
	else if (head && tail)
	{
		node *temp = head->next;
		head->next->prev = NULL;
		delete head;
		head = temp;
		if (tail == head)
			tail = NULL;
	}
}

std::string list::at(int index)
{
	if (index >= 1 && index <= getSize()) // Can't get an element if it's outside the list
	{
		node *current = head;
		int k = 1;
		while (k != index)
		{
			current = current->next;
			k++;
		}

		return current->data;
	}
}

void list::insert(std::string data, int index)
{
	if (index >= 1 && index <= getSize() + 1) // Can't get an element if it's outside the list
	{
		if (index == 1)
			pushFront(data);
		else if (index == getSize() + 1)
			pushBack(data);
		else
		{
			node *current = head;
			int k = 1;
			while (k != index - 1)
			{
				current = current->next;
				k++;
			}

			node *newAtIndex = new node;
			node *preIndex = current;
			node *postIndex = current->next;

			preIndex->next = newAtIndex;
			postIndex->prev = newAtIndex;

			newAtIndex->next = postIndex;
			newAtIndex->prev = preIndex;
			newAtIndex->data = data;
		}
	}
}

void list::remove(int index)
{
		if (index >= 1 && index <= getSize() && !isEmpty()) // Can't get an element if it's outside the list
		{
			if (index == 1)
				popFront();
			else if (index == getSize())
				popBack();
			else
			{
				node *current = head;
				int k = 1;
				while (k != index)
				{
					current = current->next;
					k++;
				}

				node *preIndex = current->prev;
				node *atIndex = current;
				node *postIndex = current->next;

				preIndex->next = postIndex;
				postIndex->prev = preIndex;
				delete atIndex;
			}
		}
}

int list::getSize()
{
	if (!isEmpty())
	{
		node *current = head;
		int k = 0;
		while (current != NULL)
		{
			current = current->next;
			k++;
		}
		return k;
	}
}

void list::printToConsole()
{
	if (!isEmpty())
	{
		node *current = head;
		int k = 1;
		while (current != NULL)
		{
			std::cout << "#" << k << " data - " << current->data << " <-> ";
			current = current->next;
			k++;
		}
		std::cout << "NULL";
	}
}

bool list::isEmpty()
{
	if (head)
		return false;
	else
		return true;
}

void list::clear()
{
	if (!isEmpty())
	{
		node *current = head;
		node *del;
		while (current != NULL)
		{
			del = current;
			current = current->next;
			delete del;
		}
		head = NULL;
		tail = NULL;
	}
}

void list::set(std::string data, int index)
{
	if (!isEmpty())
	{
		if (index >= 1 && index <= getSize())
		{
			node *current = head;
			int k = 1;
			while (k != index)
			{
				current = current->next;
				k++;
			}

			current->data = data;
		}
	}
}

void list::insertSubList(list &subList, int index)
{
	if (!isEmpty() && !subList.isEmpty())
	{
		if (!index)
		{
			node *newHead = new node, *temp, *prev;

			newHead->prev = NULL;
			newHead->data = subList.at(1);
			prev = newHead;
			temp = newHead;
			for (int i = 2; i <= subList.getSize(); i++)
			{
				temp = new node;
				temp->data = subList.at(i);
				temp->prev = prev;
				prev->next = temp;
				prev = temp;
			}
			temp->next = head;
			head->prev = temp;
			if (!tail)			
				tail = head;			
			head = newHead;
		}
		else if (index == getSize())
		{
			node *temp = new node, *prev, *subHeadPrev;

			if (!tail)
				subHeadPrev = head;
			else
				subHeadPrev = tail;

			temp->data = subList.at(1);
			temp->prev = subHeadPrev;
			subHeadPrev->next = temp;
			prev = temp;
			for (int i = 2; i <= subList.getSize(); i++)
			{
				temp = new node;
				temp->data = subList.at(i);
				temp->prev = prev;
				prev->next = temp;
				prev = temp;
			}
			temp->next = NULL;
			tail = temp;
		}
		else if (index >= 1 && index < getSize())
		{
			node *temp = new node, *prev, *subHeadPrev;

			node *atIndex = head, *atIndexNext;
			int k = 1;
			while (k != index)
			{
				atIndex = atIndex->next;
				k++;
			}
			atIndexNext = atIndex->next;

			temp->prev = atIndex;
			atIndex->next = temp;
			temp->data = subList.at(1);
			prev = temp;
			for (int i = 2; i <= subList.getSize(); i++)
			{
				temp = new node;
				temp->data = subList.at(i);
				temp->prev = prev;
				prev->next = temp;
				prev = temp;
			}
			temp->next = atIndexNext;
			atIndexNext->prev = temp;
		}
	}
}

list::~list()
{
	clear();
}