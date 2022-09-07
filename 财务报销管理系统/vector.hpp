#pragma once
template <class T>
class vector {
public:
    //默认构造函数构造函数,并且不能被隐式声明
    explicit vector() :start(0), finish(0), end_of_storage(0)
    {}
    //清除
    vector& clear()
    {
        finish = start;
        return *this;
    }
    //析构函数
    ~vector()
    {
        if (start != NULL)
        {
            delete[]start;
        }
    }
    //定义iterator
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
    //尾插法，加入元素
    vector& push_back(const T& x) //尾插法在最尾插入数据x
    {
        CheckCapacity();
        //先赋值，然后把指针加1
        *finish++ = x;
        return *this;
    }
    //插入操作
    vector& insert(iterator pos, const T& data)//任意位置的插入
    {
        CheckCapacity();//判断情况，给空间
        //让整体数据后移
        for (auto it=pos;it!=finish;it++)
        {
            *(it + 1) = *it;
        }
        //在指定位置插入元素
        *pos = data;
        finish++;//更改指针
        return *this;
    }
    iterator erase(iterator pos)//任意位置的删除
    {
        for (auto it = pos; it !=finish; it++)
        {
            *it = *(it + 1);
        }
        finish--;
        return pos+1;
    }
protected:
    iterator start;//起始指针
    iterator finish;//指向最后一个数据的下一个位置
    iterator end_of_storage;//空间最大值的下一个位置
private:
    //主要是检查是否空间不足来增加空间
    void CheckCapacity()
    {
        int sz = capacity();
        int si = size();
        if (si >= sz)
        {
            int capacity = sz ? (sz * 2) : 3;//sz不为0就复值2倍大小的空间，否则就给3
            //测试代码cout << capacity << endl;
            T* temp = new T[capacity];
            for (int i = 0; i < si; i++)//拷贝原本空间的值
            {
                temp[i] = start[i];
            }
            delete[] start;//删除原空间内容，指针
            //更改当前类中的指针指向
            start = temp;
            finish = start + si;
            end_of_storage = start + capacity;
        }
    }
};