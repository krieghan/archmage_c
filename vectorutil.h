#include <vector>

#ifndef VECTORUTIL_H
#define VECTORUTIL_H

template <class T>
void vector_insert(std::vector<T>& vectorToInsertInto, int index, T element){
	T currentElement = element;
	vectorToInsertInto.push_back(vectorToInsertInto[vectorToInsertInto.size() - 1]);
	for (unsigned int i = index; i < vectorToInsertInto.size(); i++){
		T tmp = vectorToInsertInto[i];
		vectorToInsertInto[i] = currentElement;
		currentElement = tmp;
	}
}

#endif