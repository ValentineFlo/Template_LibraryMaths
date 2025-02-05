template <typename T>

class Iterator 
{
private:
    T* ptr;
public:
    explicit Iterator(T* p) : ptr(p) {}

    T& operator*() { return *ptr; }
    Iterator& operator++() { ++ptr; return *this; }
    Iterator operator++(int) { Iterator tmp = *this; ++ptr; return tmp; }
    Iterator& operator--() { --ptr; return *this; }
    Iterator operator--(int) { Iterator tmp = *this; --ptr; return tmp; }

    bool operator==(const Iterator& other) const { return ptr == other.ptr; }
    bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
};

