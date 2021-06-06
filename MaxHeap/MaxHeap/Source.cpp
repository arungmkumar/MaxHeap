#include <iostream>
#include <vector>

using namespace std;


class maxHeap
{
private:
	int m_size;
	vector<int> v;
	void heapify(int i);
	void heapifyDown(int i);
	int leftChildIndex(int i)
	{
		return i * 2;
	}
	int rightChildIndex(int i)
	{
		return i * 2 + 1;
	}
	int parentIndex(int i)
	{
		return i / 2;
	}


public:
	maxHeap()
	{
		m_size = 0;
		v.push_back(-1);
	}

	void push(int val);
	void pop();
	int top();
	bool isEmpty(){
		return m_size == 0;
	}


};

int maxHeap::top()
{
	return v[1];
}


void maxHeap::heapify(int i)
{
	if (i <= 1) return;
	int pIndex = parentIndex(i);

	if (v[pIndex]>v[i])
	{
		swap(v[pIndex], v[i]);
		heapify(pIndex);
	}
	return;
}

void maxHeap::heapifyDown(int i)
{

	if (i > m_size) return;
	int vindex = i;
	int lindex = leftChildIndex(i);
	int rindex = rightChildIndex(i);

	if (lindex <= m_size && v[lindex] < v[vindex])
	{
		vindex = lindex;
	}

	if (rindex <= m_size && v[rindex] < v[vindex])
	{
		vindex = rindex;
	}

	if (vindex != i)
	{

		swap(v[i], v[vindex]);
		heapifyDown(vindex);
	}

	return;
}
void maxHeap::push(int val)
{

	m_size++;
	if (m_size < v.size())
	{
		v[m_size] = val;
	}
	else
	{
		v.push_back(val);
	}

	heapify(m_size);
}

void maxHeap::pop()
{
	swap(v[1], v[m_size]);
	m_size--;

	heapifyDown(1);

}

int main()
{
	maxHeap mh;

	if (mh.isEmpty())
	{
		cout << "isEmpty is working" << endl;
	}
	else
	{
		cout << "isEmpty is NOT working" << endl;
	}

	mh.push(6);
	mh.push(8);
	mh.push(5);
	mh.push(10);
	mh.push(25);
	mh.push(9);
	cout << mh.top() << endl;
	mh.pop();
	cout << mh.top() << endl;
	mh.pop();
	cout << mh.top() << endl;
	mh.pop();
	cout << mh.top() << endl;
	mh.pop();
	cout << mh.top() << endl;
	return 0;
}