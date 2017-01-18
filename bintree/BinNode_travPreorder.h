#pragma once
#include "BinNode_Trav_R.h"
#include "BinNode_travPreorder_I.h"

template <typename T>
template<typename VST>
void BinNode<T>::travPre(VST& visit)
{
	srand((unsigned)time(NULL));
	switch (rand() % 3)
	{
	case 1:
		travPre_I1(this, visit);
		break;
	case 2:
		travPre_I2(this, visit);
		break;
	default:
		travPre_R(this, visit);
		break;
	}
}