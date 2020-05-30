#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
struct TList {
    Aeroporto aeroporto;
    struct TList* next;
};

typedef struct TList* List;

List initNodeList();

#endif // LIST_H_INCLUDED
