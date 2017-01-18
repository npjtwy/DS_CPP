
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "List.h"
#include <string>
#include <vector>
#include <algorithm>

#include "VST_and_visit.h"
using  namespace std;

int main()
{
	List<int> iList;
	iList.insertAsFirst(2);
	iList.insertAsFirst(9);
	iList.insertAsFirst(6);
	iList.insertAsFirst(1);
	iList.insertAsFirst(3);
	iList.insertAsFirst(1);
	iList.insertAsFirst(4);


	int i = 123;
	printf("%d\n", iList.last()->pred->data);

	iList.traverse(visit);	//使用函数指针访问列表元素
	printf("\n");

	VST ivisit;
	iList.traverse(ivisit);	//使用函数对象访问列表元素

	iList.sort();
	iList.traverse(ivisit);	//使用函数对象访问列表元素
	printf("\n");

	cout << iList.deduplicate() << endl;
	iList.traverse(ivisit);
	printf("\n");

	if (iList.find(9) != NULL)
		cout << "find successed\n" << endl;

	iList.insertAsFirst(4); iList.insertAsFirst(4); iList.insertAsFirst(4);

	cout << "deleted " << iList.deduplicate() << " elements\n";

	cout << iList[0] << endl;

	iList.traverse(ivisit);
	printf("\n");

	iList.reverse();

	iList.traverse(ivisit);
	printf("\n");

	system("pause");
	return 0;
}