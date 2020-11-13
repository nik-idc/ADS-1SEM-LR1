#include "list.h"
#include <string>

int main()
{
	list list1, list2;
	
	for (int i = 1; i <= 3; i++)
		list1.insert("1_t_" + std::to_string(i), i);

	for (int i = 1; i <= 3; i++)
		list2.insert("2_t_" + std::to_string(i), i);

	for (int i = 0; i <= list2.getSize(); i++)
	{
		list1.insertSubList(list2, i);
		list1.printToConsole();
		std::cout << std::endl;
		list1.clear();
		for (int i = 1; i <= 3; i++)
			list1.insert("1_t_" + std::to_string(i), i);
	}
	system("pause");
	return 0;
}