#pragma once
#include <iostream>
#include <initializer_list>
#include <vector>

template<typename T>
class Set {
private:
    std::vector<T> elements;
public:
    Set();

    Set(const Set<T>& set);

    Set(Set<T>&& set) noexcept;

    Set(std::initializer_list<T> list);

    ~Set();

    Set<T>& operator=(const Set<T>& set);

    Set<T>&
        operator=(Set<T>&& set) noexcept;
    void add(const T& element);

    void add(const std::initializer_list<T>& list);

    bool remove(const T& element);

    void clear();

    bool contains(const T& element) const;

    [[nodiscard]] size_t size() const;

    Set<T> unite(const Set<T>& set) const;

    Set<T> intersect(const Set<T>& set) const;

    Set<T> subtract(const Set<T>& set) const;

    template<typename U>
    friend std::ostream& operator<<(std::ostream& out, const Set<U>& set);

};

template<typename T>
Set<T>::Set() {
    elements = std::vector<T>();
}

template<typename T>
Set<T>::Set(const Set<T>& set) {
    elements = set.elements;
}

template<typename T>
Set<T>::Set(Set<T>&& set) noexcept {
    elements = std::move(set.elements);
}

template<typename T>
Set<T>::Set(std::initializer_list<T> list) {
    elements = std::vector<T>(list);
}

template<typename T>
Set<T>::~Set() {
    elements.clear();
}

template<typename T>
Set<T>& Set<T>::operator=(const Set<T>& set) {
    elements = set.elements;
    return *this;
}

template<typename T>
Set<T>& Set<T>::operator=(Set<T>&& set) noexcept {
    elements = std::move(set.elements);
    return *this;
}

template<typename T>
void Set<T>::add(const T& element) {
    if (!contains(element)) {
        elements.push_back(element);
    }
}

template<typename T>
void Set<T>::add(const std::initializer_list<T>& list) {
    for (const T& element : list) {
        add(element);
    }
}

template<typename T>
bool Set<T>::remove(const T& element) {
    for (size_t i = 0; i < elements.size(); i++) {
        if (elements[i] == element) {
            elements.erase(elements.begin() + i);
            return true;
        }
    }
    return false;
}

template<typename T>
void Set<T>::clear() {
    elements.clear();
}

template<typename T>
bool Set<T>::contains(const T& element) const {
    for (const T& el : elements) {
        if (el == element) {
            return true;
        }
    }
    return false;
}

template<typename T>
size_t Set<T>::size() const {
    return elements.size();
}

template<typename T>
Set<T> Set<T>::unite(const Set<T>& set) const {
    Set<T> result = *this;
    for (const T& element : set.elements) {
        result.add(element);
    }
    return result;
}

template<typename T>
Set<T> Set<T>::intersect(const Set<T>& set) const {
    Set<T> result;
    for (const T& element : elements) {
        if (set.contains(element)) {
            result.add(element);
        }
    }
    return result;
}

template<typename T>
Set<T> Set<T>::subtract(const Set<T>& set) const {
    Set<T> result = *this;
    for (const T& element : set.elements) {
        result.remove(element);
    }
    return result;
}

template<typename U>
std::ostream& operator<<(std::ostream& out, const Set<U>& set) {
    out << "{";
    for (size_t i = 0; i < set.elements.size(); i++) {
        out << set.elements[i];
        if (i != set.elements.size() - 1) {
            out << ", ";
        }
    }
    out << "}";
    return out;
}

