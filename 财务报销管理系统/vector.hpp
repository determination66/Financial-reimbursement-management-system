#pragma once
template <class T>
class vector {
public:
    //Ĭ�Ϲ��캯�����캯��,���Ҳ��ܱ���ʽ����
    explicit vector() :start(0), finish(0), end_of_storage(0)
    {}
    //���
    vector& clear()
    {
        finish = start;
        return *this;
    }
    //��������
    ~vector()
    {
        if (start != NULL)
        {
            delete[]start;
        }
    }
    //����iterator
    typedef T* iterator;
    iterator begin() { return start; }
    iterator end() { return finish; }
    size_t size() { return size_t(end() - start); }
    size_t capacity() { return size_t(end_of_storage - start); }
    bool empty() const { return begin() == end(); }
    T& operator[] (size_t n) { return *(begin() + n); }
    T& front() { return *begin(); }
    iterator rbegin() { return finish - 1; };
    T& back() { return *(end() - 1); }
    //β�巨������Ԫ��
    vector& push_back(const T& x) //β�巨����β��������x
    {
        CheckCapacity();
        //�ȸ�ֵ��Ȼ���ָ���1
        *finish++ = x;
        return *this;
    }
    //�������
    vector& insert(iterator pos, const T& data)//����λ�õĲ���
    {
        CheckCapacity();//�ж���������ռ�
        //���������ݺ���
        for (auto it=pos;it!=finish;it++)
        {
            *(it + 1) = *it;
        }
        //��ָ��λ�ò���Ԫ��
        *pos = data;
        finish++;//����ָ��
        return *this;
    }
    iterator erase(iterator pos)//����λ�õ�ɾ��
    {
        for (auto it = pos; it !=finish; it++)
        {
            *it = *(it + 1);
        }
        finish--;
        return pos+1;
    }
protected:
    iterator start;//��ʼָ��
    iterator finish;//ָ�����һ�����ݵ���һ��λ��
    iterator end_of_storage;//�ռ����ֵ����һ��λ��
private:
    //��Ҫ�Ǽ���Ƿ�ռ䲻�������ӿռ�
    void CheckCapacity()
    {
        int sz = capacity();
        int si = size();
        if (si >= sz)
        {
            int capacity = sz ? (sz * 2) : 3;//sz��Ϊ0�͸�ֵ2����С�Ŀռ䣬����͸�3
            //���Դ���cout << capacity << endl;
            T* temp = new T[capacity];
            for (int i = 0; i < si; i++)//����ԭ���ռ��ֵ
            {
                temp[i] = start[i];
            }
            delete[] start;//ɾ��ԭ�ռ����ݣ�ָ��
            //���ĵ�ǰ���е�ָ��ָ��
            start = temp;
            finish = start + si;
            end_of_storage = start + capacity;
        }
    }
};