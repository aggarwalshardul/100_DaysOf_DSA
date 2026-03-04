#include <stdlib.h>

typedef struct {
    long *stack;
    int top;
    long min;
} MinStack;

MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->stack = (long*)malloc(sizeof(long) * 10000);
    obj->top = -1;
    obj->min = 0;
    return obj;
}

void minStackPush(MinStack* obj, int val) {
    if (obj->top == -1) {
        obj->stack[++obj->top] = 0;
        obj->min = val;
    } else {
        long diff = (long)val - obj->min;
        obj->stack[++obj->top] = diff;

        if (diff < 0)
            obj->min = val;
    }
}

void minStackPop(MinStack* obj) {
    long diff = obj->stack[obj->top--];

    if (diff < 0)
        obj->min = obj->min - diff;
}

int minStackTop(MinStack* obj) {
    long diff = obj->stack[obj->top];

    if (diff > 0)
        return obj->min + diff;
    else
        return obj->min;
}

int minStackGetMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    free(obj->stack);
    free(obj);
}
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/