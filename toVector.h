#ifndef TOVECTOR_H
#define TOVECTOR_H

using namespace std;

class toVector
{
private:
	void setSize();
	void setVector();

public:
	toVector();
	void setFileName(string name);
	int getSize();
	vector<int> getVector();

private:
	ifstream datafile;
	string fileName;
	vector<int> unSorted;
	int size;
};
#endif /* TOVECTOR_H */