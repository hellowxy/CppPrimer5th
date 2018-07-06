#ifndef BLOB_PTR_H
#define BLOB_PTR_H
#include<memory>
#include<vector>
#include<stdexcept>
#include"Blob.h"
template <typename> class BlobPtr;//需要一个前向声明

template<typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T> &);

template<typename T>
bool operator!=(const BlobPtr<T>&, const BlobPtr<T> &);

template<typename T>
class BlobPtr
{
    //要定义两个友元操作符，就需要先声明这两个操作符
    //注意模板友元函数的声明方式
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    friend bool operator!=<T>(const BlobPtr<T>&, const BlobPtr<T>&);
    public:
        BlobPtr():curr(0){}
        BlobPtr(Blob<T> &a, size_t sz = 0):wptr(a.data), curr(sz){}

        T& operator*() const
        {
            std::shared_ptr<std::vector<T>> s = check(curr, "dereference past end");
            return (*s)[curr];
        }

        BlobPtr& operator++()
        {
            check(curr, "increment past end of StrBlob");
            ++curr;
            return *this;
        }
        BlobPtr& operator--()
        {
            curr--;
            check(curr, "decrement past begin of BlobPtr");
            return *this;
        }

        BlobPtr operator++(int);
        BlobPtr operator--(int);
        bool past_of_end()
        {
            std::shared_ptr<std::vector<T>> t = wptr.lock();
            if(!t)
            {
                throw std::runtime_error("unbind BlobPtr");
            }
            return curr >= t->size();
        }
    private:
        std::size_t curr;
        std::weak_ptr<std::vector<T>> wptr;
        std::shared_ptr<std::vector<T>> check(std::size_t, const std::string&) const;
};

template<typename T>
BlobPtr<T> BlobPtr<T>::operator++(int a)
{
    BlobPtr<T> t = *this;
    ++*this;
    return t;
}

template<typename T>
BlobPtr<T> BlobPtr<T>::operator--(int a)
{
    BlobPtr<T> t = *this;
    --*this;
    return t;
}

template<typename T>
std::shared_ptr<std::vector<T>> BlobPtr<T>::check(std::size_t i, const std::string& msg) const
{
    std::shared_ptr<std::vector<T>> t = wptr.lock();
    if(!t)
    {
         throw std::runtime_error("unbind BlobPtr");
    }
    if(i >= t->size())
    {
        throw std::out_of_range(msg);
    }
    return t;
}

template<typename T> bool operator==(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    if (lhs.wptr.lock() != rhs.wptr.lock()) {
		throw std::runtime_error("ptrs to different Blobs!");
	}
	return lhs.curr == rhs.curr;
}

template<typename T> bool operator!=(const BlobPtr<T> &lhs, const BlobPtr<T> &rhs) {
    return !(lhs == rhs);
}

#endif