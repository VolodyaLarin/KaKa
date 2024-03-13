#include <stdarg.h>

#include <map>
#include <vector>
#include <iostream>

#include <chrono>

extern "C" int main_main();
extern "C" void *ALLOCATE(size_t size, size_t number_of_links, ...);

void GC_ADD_STACK(void *);
extern "C" void GC_PUSHSTACK();
void GC_POPSTACK();
extern "C" void GC_CALL(size_t size, ...);


struct HeapEntry {
    std::vector<size_t> offsets;
    bool isUsed;
};

struct ShadowStackEntry {
    std::vector<void *> pointers;
};

std::map<void *, HeapEntry> *HEAP;

std::vector<ShadowStackEntry> *SHADOW_STACK;

void *ALLOCATE(size_t size, size_t number_of_links, ...) {
    va_list args;
    va_start(args, number_of_links);

    void *ptr = calloc(size, 1);
//    return  ptr;

    HeapEntry he = {
            {}
    };
    he.offsets.reserve(number_of_links);

    for (size_t i = 0; i < number_of_links; ++i) {
        he.offsets.push_back(va_arg(args, size_t));
    }

    HEAP->insert( {ptr, he});

    SHADOW_STACK->rbegin()->pointers.push_back(ptr);
    return ptr;
}


void GC_PUSHSTACK() {
//  return;
    SHADOW_STACK->push_back({});
}
void GC_POPSTACK() {
//  return;
    SHADOW_STACK->pop_back();
}

bool markHeap(void *ptr) {
    if (!ptr) {
        return true;
    }

    auto res = HEAP->find(ptr);
    if (res == HEAP->end()) {
        std::cerr << "Warning: includes pointer to non alocated memory " << ptr << std::endl;
        return false;
    }

    if (res->second.isUsed) {
        return true;
    }
    res->second.isUsed = true;

    for (auto offset: res->second.offsets) {
        void * ptrEntry = *(void **)((char *)ptr + offset);
        markHeap(ptrEntry);
    }
    return true;
}

void GC_CALL(size_t size, ...) {
    va_list args;
    va_start(args, size);
//    return;
    for (auto &he: *HEAP) {
        he.second.isUsed = false;
    }

    for (size_t i = 0; i < size; ++i) {
        void *ptr = va_arg(args, void *);
        markHeap(ptr);
    }

    GC_POPSTACK();

    {
        int i = 0;
        for (auto layer: *SHADOW_STACK) {
            i++;
            for (auto ptr: layer.pointers) {
                markHeap(ptr);
            }
        }
    }



    std::vector<void *> toRemove;
    for (auto &he: *HEAP) {
        if (!he.second.isUsed) {
            toRemove.push_back(he.first);
        }
    }

    for (auto ptr: toRemove) {
        free(ptr);
        HEAP->erase(HEAP->find(ptr));
    }
}




int main() {
    auto start_time = std::chrono::high_resolution_clock::now();

    HEAP = new std::map<void *, HeapEntry>;
    SHADOW_STACK = new std::vector<ShadowStackEntry>;

    GC_PUSHSTACK();
    int res = main_main();
    GC_CALL(0);


    delete SHADOW_STACK;
    delete HEAP;
    auto end_time = std::chrono::high_resolution_clock::now();
    printf("\n\nRuns %.2ld ms \nResult code: %d\n", (std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time)).count() , res);
}