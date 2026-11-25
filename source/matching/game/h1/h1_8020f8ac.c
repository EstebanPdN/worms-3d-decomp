/* Stack pop of an 8-byte entry (session 47b5d14a). */

typedef struct W3dPair_8020f8ac {
    int a;
    int b;
} W3dPair_8020f8ac;

typedef struct W3dPairStack_8020f8ac {
    char pad[16];
    W3dPair_8020f8ac items[256];    /* +16 */
    int count;                      /* +2064 */
} W3dPairStack_8020f8ac;

void w3d_h1_pair_stack_pop_8020f8ac(W3dPairStack_8020f8ac *s, W3dPair_8020f8ac *out)
{
    int i = --s->count;
    W3dPair_8020f8ac t = s->items[i];
    out->b = t.b;
    out->a = t.a;
}
