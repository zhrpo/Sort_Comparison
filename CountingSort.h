#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include<vector>

using namespace std;

class countSort
{
private:
	int findMax(vector<int> unSorted, int size);
public:
	countSort();
	void buildOutput(vector<int> unSorted, int size);

};

#endif /* COUNTINGSORT_H*/

