#if !defined(SORT_H)
#define SORT_H

#include <vector>

class Sort{
public:
    virtual void sort(std::vector<float>& data) = 0;
};

class Insertion final : public Sort{
public:
    void sort(std::vector<float>& data) override;
};

class Buble final : public Sort{
public:
    void sort(std::vector<float>& data) override;
};

class Merge final : public Sort{
public:
    void sort(std::vector<float>& data) override;
private:
    void merge_sort(std::vector<float>& data, int left, int right);
    void merge(std::vector<float>& data, int left, int mid, int right);
};

#endif // SORT_H
