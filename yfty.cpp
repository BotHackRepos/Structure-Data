// yfty.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//
/*#include <iostream>
#include <cstdio>
#include <cstdlib>

#define Integer sizeof(int)
#define Character sizeof(char)
#define String sizeof(std::string)
#define Pointer 0;
#define Double sizeof(double)


void cleanup() {
    std::cout << "cleanup!" << std::endl;
}

void error(const char* args) {
    std::cout << args << std::endl;
    std::atexit(cleanup);
    std::cout << 1 << '\n';
    std::exit(0);
}


struct List {
    int num = (int)nullptr;
    List* next = nullptr;
    void init(int _num, const List *_next) {
        num = _num;
        next = (List*)_next;
    }
}; 



bool is_empty(List* ptr) {
    return (ptr->next == nullptr && ptr->num == 0);
}

int size(List *ptr) {
    int i = 1;
    if (is_empty(ptr)) {
        return 1;
    }
    else if (ptr->next == nullptr) {
        return 1;
    }
    List* pptr = ptr->next;
    while (true) {
        if (pptr->next == nullptr) {
            break;
        }
        pptr = pptr->next;
        ++i;
    }
    return i + 1;
}


int* element(List *ptr, int index) {
    if (index >= size(ptr)) {
        error("ERROR pointer point to is not list-memory, close this programm");
    }
    List* pptr = ptr->next;
    if (index == 0) {
        return &ptr->num;
    }
    if (index == 1) {
        return &ptr->next->num;
    }
    for (int i = 1; i < index; ++i) {
        pptr = pptr->next;
    }
    return &pptr->num;
}

List* getnode(List* ptr, int index) {
    if (index >= size(ptr)) {
        error("ERROR pointer point to is not list-memory, close this programm");
    }
    List* pptr = ptr->next;
    if (index == 0) {
        return ptr;
    }
    if (index == 1) {
        return ptr->next;
    }
    for (int i = 1; i < index; ++i) {
        pptr = pptr->next;
    }
    return pptr;
}

List* begin(List* ptr) {
    return ptr;
}

List* end(List* ptr) {
    return getnode(ptr, size(ptr) - 1);
}

void Free(List* ptr) {
    if (is_empty(ptr)) {
        delete ptr;
        return;
    }
    else if (size(ptr) == 1) {
        delete ptr;
        return;
    }
    int const sizelist = size(ptr);
    List** pptr = new List * [sizelist];
    for (int i = 0; i < sizelist; ++i) {
        pptr[i] = getnode(ptr, i);
    }
    for (int i = 0; i < sizelist; ++i) {
        delete &pptr[i][0];
    }
    delete[] pptr;
}

void swap(int& num1, int &num2) {
    int save = num1;
    num1 = num2;
    num2 = save;
}

void push_front(List* ptr, int num) {
    if (is_empty(ptr)) {
        ptr->num = num;
        return;
    }
    else if (ptr->next == nullptr) {
        ptr->next = new List;
        ptr->next->num = num;
        swap(ptr->num, ptr->next->num);
        return;
    }
    List* pptr = new List;
    pptr->next = ptr->next;
    pptr->num = num;
    ptr->next = pptr;
    swap(pptr->num, ptr->num);
}

void push_back(List* ptr, int num) {
    if (is_empty(ptr)) {
        ptr->num = num;
        return;
    }
    List* ptrt = getnode(ptr, size(ptr) - 1);
    ptrt->next = new List;
    ptrt->next->num = num;
}

void print(List* ptr) {
    for (int i = 0; i < size(ptr); ++i) {
        std::cout << *element(ptr, i) << " ";
    }
    std::cout << "\n";
}

List* search(List* ptr, int num) {
    if (is_empty(ptr)) {
        return nullptr;
    }
    for (int i = 0; i < size(ptr); ++i) {
        if (*element(ptr, i) == num) {
            return getnode(ptr, i);
        }
    }
    return nullptr;
}


int search_count(List *ptr, int num) {
    int count = 0;
    for (int i = 0; i < size(ptr); ++i) {
        if (*element(ptr, i) == num) {
            ++count;
        }
    }
    return count;
}

List* newlist(size_t Size) {
    List* ptr = new List;
    for (int i = 0; i < Size - 1; ++i) {
        getnode(ptr, i)->init(0, new List);
    }
    return ptr;
}




int search_index(List* ptr, int num) {
    if (is_empty(ptr)) {
        return -1;
    }
    if (search_count(ptr, num) > 0) {
    return -1;
    } 
    for (int i = 0; i < size(ptr); ++i) {
        if (*element(ptr, i) == num) {
             return i;
         }
    }
}

void input(List* ptr) {
    int* pptr;
    for (int i = 0; i < size(ptr); ++i) {
        std::cout << "Enter " << i << " element of list ";
        pptr = element(ptr, i);
        std::cin >> *pptr;
    }
}

void sort_vstavk_binary(List* ptr) {
    for (int i = 0; i < size(ptr); ++i) {
        int minus = 0;
        if (i) {
            for (int j = i; j > 0; --j) {
                if (*element(ptr, i) < *element(ptr, j)) {
                    minus++;
                }
            }
            int ii = i - minus;
            if (ii == 0) {
                continue;
            }
            else if (ii == 1) {
                swap(*element(ptr, i - 1), *element(ptr, i));

            }
            else {
                int save = *element(ptr, i);
                int* arr = new int[i - ii];
                int k = 0;
                for (int j = ii; j < i - 1; ++j) {
                    arr[k] = *element(ptr, j);
                    ++k;
                    if (j == i - 2) {
                        k = 0;
                    }
                }
                for (int j = ii + 1; j < i; ++j) {
                    *element(ptr, j) = arr[k];
                    ++k;
                }
                *element(ptr, ii) = save;
            }
        }
    }
}





int main(int argc, const char **argv[])
{
    List* ptr = newlist(1);
    push_back(ptr, 8);
    push_back(ptr, 7);
    push_back(ptr, 9);
    print(ptr);
    sort_vstavk_binary(ptr);
    print(ptr);
    Free(ptr);
}*/ */
// yfty.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cstdio>
#include <cstdlib>

#define Integer sizeof(int)
#define Character sizeof(char)
#define String sizeof(std::string)
#define Pointer 0;
#define Double sizeof(double)


void cleanup() {
    std::cout << "cleanup!" << std::endl;
}

void error(const char* args) {
    std::cout << args << std::endl;
    std::atexit(cleanup);
    std::cout << 1 << '\n';
    std::exit(0);
}


struct List {
    int num = (int)nullptr;
    List* next = nullptr;
    void init(int _num, const List *_next) {
        num = _num;
        next = (List*)_next;
    }
}; 




bool is_empty(List* ptr) {
    return (ptr->next == nullptr && ptr->num == 0);
}

bool _is_empty(List* ptr) {
    return (ptr == nullptr);
}

int size(List *ptr) {
    int i = 1;
    if (is_empty(ptr)) {
        return 1;
    }
    else if (ptr->next == nullptr) {
        return 1;
    }
    List* pptr = ptr->next;
    while (true) {
        if (pptr->next == nullptr) {
            break;
        }
        pptr = pptr->next;
        ++i;
    }
    return i + 1;
}


int* element(List *ptr, int index) {
    if (index >= size(ptr)) {
        error("ERROR pointer point to is not list-memory, close this programm");
    }
    List* pptr = ptr->next;
    if (index == 0) {
        return &ptr->num;
    }
    if (index == 1) {
        return &ptr->next->num;
    }
    for (int i = 1; i < index; ++i) {
        pptr = pptr->next;
    }
    return &pptr->num;
}

List* getnode(List* ptr, int index) {
    if (index >= size(ptr)) {
        error("ERROR pointer point to is not list-memory, close this programm");
    }
    List* pptr = ptr->next;
    if (index == 0) {
        return ptr;
    }
    if (index == 1) {
        return ptr->next;
    }
    for (int i = 1; i < index; ++i) {
        pptr = pptr->next;
    }
    return pptr;
}

List* begin(List* ptr) {
    return ptr;
}

List* end(List* ptr) {
    return getnode(ptr, size(ptr) - 1);
}

void Free(List* ptr) {
    if (is_empty(ptr)) {
        delete ptr;
        return;
    }
    else if (size(ptr) == 1) {
        delete ptr;
        return;
    }
    int const sizelist = size(ptr);
    for (int i = sizelist - 1; i >= 0; ++i) {
        delete getnode(ptr, i);
    }
}

void swap(int& num1, int &num2) {
    int save = num1;
    num1 = num2;
    num2 = save;
}

void push_front(List* ptr, int num) {
    if (is_empty(ptr)) {
        ptr->num = num;
        return;
    }
    else if (ptr->next == nullptr) {
        ptr->next = new List;
        ptr->next->num = num;
        swap(ptr->num, ptr->next->num);
        return;
    }
    List* pptr = new List;
    pptr->next = ptr->next;
    pptr->num = num;
    ptr->next = pptr;
    swap(pptr->num, ptr->num);
}

void push_back(List* ptr, int num) {
    if (is_empty(ptr)) {
        ptr->num = num;
        return;
    }
    List* ptrt = getnode(ptr, size(ptr) - 1);
    ptrt->next = new List;
    ptrt->next->num = num;
}
/* template <std::size_t n> List* newList(const int(&arr)[n]) {
    List* ptr = new List;
    for (int i = 1; i < n; ++i) {
        getnode(ptr, i - 1)->init(arr[i - 1], new List);
    }
    getnode(ptr, size(ptr) - 1)->num = arr[n - 1];
    return ptr;
}*/

void print(List* ptr) {
    for (int i = 0; i < size(ptr); ++i) {
        std::cout << *element(ptr, i) << " ";
    }
    std::cout << "\n";
}

List* search(List* ptr, int num) {
    if (is_empty(ptr)) {
        return nullptr;
    }
    for (int i = 0; i < size(ptr); ++i) {
        if (*element(ptr, i) == num) {
            return getnode(ptr, i);
        }
    }
    return nullptr;
}


int search_count(List *ptr, int num) {
    int count = 0;
    for (int i = 0; i < size(ptr); ++i) {
        if (*element(ptr, i) == num) {
            ++count;
        }
    }
    return count;
}

List* newlist(size_t Size) {
    List* ptr = new List;
    for (int i = 0; i < Size - 1; ++i) {
        getnode(ptr, i)->init(0, new List);
    }
    return ptr;
}




int search_index(List* ptr, int num) {
    if (is_empty(ptr)) {
        return -1;
    }
    if (search_count(ptr, num) > 0) {
    return -1;
    } 
    for (int i = 0; i < size(ptr); ++i) {
        if (*element(ptr, i) == num) {
             return i;
         }
    }
}

void input(List* ptr) {
    int* pptr;
    for (int i = 0; i < size(ptr); ++i) {
        std::cout << "Enter " << i << " element of list ";
        pptr = element(ptr, i);
        std::cin >> *pptr;
    }
}

void sort_vstavk_binary(List* ptr) {
    for (int i = 0; i < size(ptr); ++i) {
        int minus = 0;
        if (i) {
            for (int j = i; j > 0; --j) {
                if (*element(ptr, i) < *element(ptr, j)) {
                    minus++;
                }
            }
            int ii = i - minus;
            if (ii == 0) {
                continue;
            }
            else if (ii == 1) {
                swap(*element(ptr, i - 1), *element(ptr, i));

            }
            else {
                int save = *element(ptr, i);
                int* arr = new int[i - ii];
                int k = 0;
                for (int j = ii; j < i - 1; ++j) {
                    arr[k] = *element(ptr, j);
                    ++k;
                    if (j == i - 2) {
                        k = 0;
                    }
                }
                for (int j = ii + 1; j < i; ++j) {
                    *element(ptr, j) = arr[k];
                    ++k;
                }
                *element(ptr, ii) = save;
            }
        }
    }
}

List* twox_search(List * ptr, int number) {
    sort_vstavk_binary(ptr);
    const int beginb = ptr->num;
    const int middle = *element(ptr, size(ptr) / 2);
    const int high = *element(ptr, size(ptr));
    if (number == beginb) {
        return begin(ptr);
    }
    if (number == high) {
        return getnode(ptr, size(ptr));
    }
    if (number == middle) {
        return getnode(ptr, size(ptr) / 2);
    }
    if (number > middle) {
        for (int i = size(ptr) / 2 + 1; i < size(ptr) - 1; ++i) {
            if (*element(ptr, i) == number) {
                return getnode(ptr, i);
            }
        }
        return nullptr;
    }
    else {
        for (int i = 1; i < size(ptr) / 2; ++i) {
            if (*element(ptr, i) == number) {
                return getnode(ptr, i);
            }
            return nullptr;
        }
    }
    return nullptr;
}




int main(int argc, const char **argv[])
{
    List* ptr = newlist(4);
    for (int i = 0; i < 4; ++i) {
        *element(ptr, i) = i;
    }
    print(ptr);
    push_front(ptr, 8);
    print(ptr);
}
