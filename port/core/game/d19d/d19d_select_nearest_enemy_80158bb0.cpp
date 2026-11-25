#define W3D_LOOSE_C 1
#include "w3d_ptr.h"
extern "C" {
#line 1 "d19d_select_nearest_enemy_80158bb0.c"
/* d19d: 0x80158bb0 (532 bytes). Turn-control handler that picks the nearest
 * enemy worm to a message position: when the turn controller is idle and the
 * game phase from 0x80023128 is at most 2, it looks up the selected worm's
 * index, scans the 16 worm slots for active worms of another, non-allied team
 * within 300 units (squared distance <= 90000) of the position carried by the
 * message, and posts the nearest one (index and team) followed by the current
 * worm (index and team) as integer messages. Built with -mps-float (SN
 * paired-single mode: one reserved 8-byte slot per saved FPR).
 * Structures are partial views: only the fields used here are named. */
typedef struct D19dVec { float x, y, z; } D19dVec;
typedef struct D19dTurns {
    unsigned char unknown00[296];
    Ptr32<void> selected_worm;            /* +296 */
    unsigned char unknown12c[80];
    int busy;                       /* +380 */
} D19dTurns;
typedef struct D19dWorm {
    unsigned char unknown00[80];
    D19dVec position;               /* +80 */
    unsigned char unknown5c[121];
    unsigned char team;             /* +213 */
    unsigned char unknownd6[6];
    int active;                     /* +220 */
} D19dWorm;
typedef struct D19dTeam {
    unsigned char unknown00[60];
    unsigned char alliance;         /* +60 */
} D19dTeam;
typedef struct D19dMessageName { int id; Ptr32<const char> name; } D19dMessageName;
typedef struct D19dMessage { unsigned short id, unknown02; Ptr32<void> type; } D19dMessage;

extern Ptr32<void> lbl_804aa7d4;
extern Ptr32<void> lbl_804b1754;
extern D19dMessageName lbl_804afef0, lbl_804aff60, lbl_804aff48, lbl_804aff58;
extern unsigned int fn_80023128(Ptr32<void> game);
extern Ptr32<void> fn_803426b4(Ptr32<void> object);
extern int fn_80178c48(Ptr32<void> worm);
extern Ptr32<D19dWorm> fn_800fc6dc(unsigned int index);
extern Ptr32<D19dTeam> fn_800fc7f8(unsigned int team);
extern Ptr32<D19dVec> fn_80126034(Ptr32<void> message);
extern Ptr32<D19dMessage> fn_801613f0(Ptr32<void> arena, int size);
extern short fn_8015f5a0(Ptr32<D19dMessageName> name, int create);
extern Ptr32<D19dMessage> fn_800a82f0(Ptr32<D19dMessage> message, unsigned short id, int value);
extern int fn_8016239c(Ptr32<D19dMessage> message);

static __inline__ unsigned char d19d_worm_team(Ptr32<const D19dWorm> worm) { return worm->team; }
static __inline__ float d19d_distance_squared(Ptr32<const D19dVec> a, Ptr32<const D19dVec> b)
{
    float x = a->x - b->x, y = a->y - b->y, z = a->z - b->z;
    return x * x + y * y + z * z;
}

void d19d_select_nearest_enemy_80158bb0(Ptr32<D19dTurns> self, Ptr32<void> message)
{
    int current;
    Ptr32<D19dWorm> worm;
    Ptr32<D19dTeam> team;

    if (self->busy) return;
    if (fn_80023128(lbl_804aa7d4) > 2) return;
    current = fn_80178c48(fn_803426b4(self->selected_worm));
    if (current == -1) return;
    {
        int selected = -1, i;
        float nearest, limit;
        worm = fn_800fc6dc(current);
        i = 0;
        team = fn_800fc7f8(worm->team);
        nearest = limit = 90000.0f;
        do {
            Ptr32<D19dWorm> other = fn_800fc6dc(i);
            if (other->active && worm->team != d19d_worm_team(other)
                && fn_800fc7f8(other->team)->alliance != team->alliance) {
                Ptr32<const D19dVec> position = &other->position;
                float distance = d19d_distance_squared(position, fn_80126034(message));
                if (distance <= limit && (selected == -1 || distance < nearest)) {
                    nearest = distance;
                    selected = i;
                }
            }
        } while (++i <= 15);
        if (selected != -1) {
            {
                Ptr32<D19dMessage> post = fn_801613f0(lbl_804b1754, 12);
                fn_8016239c(fn_800a82f0(post, fn_8015f5a0(&lbl_804afef0, 1), selected));
            }
            {
                Ptr32<D19dMessage> post;
                unsigned char selected_team = fn_800fc6dc(selected)->team;
                post = fn_801613f0(lbl_804b1754, 12);
                fn_8016239c(fn_800a82f0(post, fn_8015f5a0(&lbl_804aff60, 1), selected_team));
            }
        }
    }
    {
        Ptr32<D19dMessage> post = fn_801613f0(lbl_804b1754, 12);
        fn_8016239c(fn_800a82f0(post, fn_8015f5a0(&lbl_804aff48, 1), current));
    }
    {
        Ptr32<D19dMessage> post = fn_801613f0(lbl_804b1754, 12);
        fn_8016239c(fn_800a82f0(post, fn_8015f5a0(&lbl_804aff58, 1), worm->team));
    }
}

}
