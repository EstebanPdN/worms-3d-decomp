/* Names describe only the observed container and interface operations. */
typedef struct S12Node { int reserved; struct S12Node *parent, *left, *right; } S12Node;
typedef struct S12Tree { int reserved; S12Node *sentinel; int count, reserved12; } S12Tree;
typedef struct S12Element { int words[4]; } S12Element;
typedef struct S12ElementVector { S12Element *begin, *end, *limit; } S12ElementVector;
typedef struct S12Service S12Service;
typedef struct S12ServiceMethods {
    void (*reserved[3])(void);
    void (*retain)(S12Service *);
    void (*release)(S12Service *);
    void (*reserved20[9])(void);
    void (*configure)(S12Service *, int);
} S12ServiceMethods;
struct S12Service { S12ServiceMethods *methods; };
typedef struct S12ServiceOwner {
    char reserved[100];
    S12Tree tree;
    S12ElementVector elements;
    int reserved128;
    S12Service *service;
    int state;
} S12ServiceOwner;
extern char lbl_8045e748[], lbl_80413b28[];
extern void fn_801acd6c(S12ServiceOwner *, void *);
extern void fn_80355800(S12Tree *, S12Node *);
extern void fn_801f2758(S12Element *, int);
extern S12Service *fn_8020b680(void *);
int w3d_s12_reset_service_801acb34(S12ServiceOwner *object)
{
    S12Tree *tree;
    S12ElementVector *elements;
    S12Element *begin, *end, *cursor;
    S12Service *service;
    fn_801acd6c(object, lbl_8045e748);
    tree = &object->tree;
    object->state = 1;
    if (tree->count) {
        S12Node *sentinel;
        fn_80355800(tree, tree->sentinel->parent);
        sentinel = tree->sentinel;
        sentinel->left = sentinel;
        tree->sentinel->parent = 0;
        sentinel = tree->sentinel;
        sentinel->right = sentinel;
        tree->count = 0;
    }
    begin = object->elements.begin;
    elements = &object->elements;
    end = elements->end;
    cursor = begin;
    while (cursor != end) {
        fn_801f2758(cursor, 2);
        ++cursor;
    }
    elements->end = begin;
    service = fn_8020b680(lbl_80413b28);
    if (service)
        service->methods->retain(service);
    if (object->service)
        object->service->methods->release(object->service);
    object->service = service;
    service->methods->configure(service, 0);
    return 0;
}
