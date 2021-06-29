#if !defined(SORT_H)
#define SORT_H

#include <vector>
#include "draw.hpp"

class Sort{
public:
    virtual void sort(std::vector<float>& data, Draw& draw) = 0;
};

class Insertion final : public Sort{
public:
    void sort(std::vector<float>& data, Draw& draw) override;
};

class Buble final : public Sort{
public:
    void sort(std::vector<float>& data, Draw& draw) override;
};

class Selection final : public Sort{
public:
    void sort(std::vector<float>& data, Draw& draw) override;
};

class Merge final : public Sort{
public:
    void sort(std::vector<float>& data, Draw& draw) override;
private:
    void merge_sort(std::vector<float>& data, int left, int right, Draw& draw);
    void merge(std::vector<float>& data, int left, int mid, int right, Draw& draw);
};

class Quick final : public Sort{
public:
    void sort(std::vector<float>& data, Draw& draw) override;
private:
    void quick_sort(std::vector<float>& data, int left, int right, Draw& draw);
    int partition(std::vector<float>& data, int left, int right, Draw& draw);
};


#endif // SORT_H
