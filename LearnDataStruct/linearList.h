#pragma once
#include <ostream>

template<typename T>
class linearList
{
public:
	virtual ~linearList() {};
	// ����true�����ҽ������Ա�Ϊ��
	virtual bool empty() const = 0;
	//�������Ա�Ԫ�صĸ���
	virtual int size() const = 0;
	//��������ΪtheIndex��Ԫ��
	virtual T& get(int theIndex) const = 0;
	//����Ԫ��theElements������
	virtual int indexOf(const T& theElements) const = 0;
	//ɾ������ΪtheIndex��Ԫ��
	virtual void erase(int theIndex) = 0;
	// ��theElement�������Ա�������ΪtheIndex��λ����
	virtual void insert(int theInex, const T& theElement) = 0;
	//�����Ա���������out
	virtual void output(std::ostream& out) const = 0;
};
