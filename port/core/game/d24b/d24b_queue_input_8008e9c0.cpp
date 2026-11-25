#include "w3d_ptr.h"
#line 1 "d24b_queue_input_8008e9c0.cpp"
/* Team-owner forwarding: if the system 0x804aab68 is active and the object's info
 * (+472, active flag +24, team index +32) names a different owner in the team list
 * 0x8043bb64 (0x800b4d98), forwards to it; otherwise queues the (object, message) pair
 * once in the pending list. Field and type names are inferred from the original
 * instructions; the lists are external views of original data. */
extern "C" Ptr32<char> w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(Ptr32<void>);
extern "C" Ptr32<void> w3d_copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Message;
struct Owner;
struct Pair { Ptr32<Owner> owner; Ptr32<Message> message; Pair(Ptr32<Owner> o, Ptr32<Message> m) { message = m; owner = o; } };
struct PairList {
    Ptr32<Pair> begin; Ptr32<Pair> end; Ptr32<Pair> capacity;
    void push(const Pair &value) {
        if (end == capacity) {
            unsigned old = (Ptr32<char>)end - (Ptr32<char>)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 3;
            Ptr32<char> p = w3d_allocate_80212fd4(bytes);
            if (begin) {
                w3d_copy_802eee50(w3d::VA(p), w3d::VA(begin), minimum(bytes, old));
                w3d_release_802134fc(begin);
            }
            begin = (Ptr32<Pair>)p;
            end = (Ptr32<Pair>)(p + old);
            capacity = (Ptr32<Pair>)(p + bytes);
        }
        *end = value;
        end++;
    }
};
template <class T>
struct List {
    Ptr32<T> begin; Ptr32<T> end; Ptr32<T> capacity;
    List() {}
    ~List() { if (begin) w3d_release_802134fc(begin); }
    T &operator[](int i) { return begin[i]; }
};
struct Team;
extern List <Ptr32<Team> > w3d_teams_8043bb64;
extern PairList w3d_pending_80431e94;
extern int w3d_active_804aab68;
struct Info { char unknown00[24]; int active; char unknown28[4]; unsigned short team; };
struct Message { char unknown00[107]; unsigned char flag107, queued, done; };
struct Sub { char unknown00[32]; Ptr32<Message> message; };
struct Owner { char unknown00[44]; Ptr32<Sub> sub; char unknown48[424]; Ptr32<Info> info; };
extern "C" Ptr32<Owner> w3d_team_owner_800b4d98(Ptr32<Team>);

extern "C" void w3d_d24b_queue_input_8008e9c0(Ptr32<Owner> self, Ptr32<Message> message)
{
    if (w3d_active_804aab68) {
        Ptr32<Info> info = self->info;
        if (info->active) {
            Ptr32<Owner> owner;
            {
                List <Ptr32<Team> > teams;
                unsigned n = (Ptr32<char>)w3d_teams_8043bb64.end - (Ptr32<char>)w3d_teams_8043bb64.begin;
                Ptr32<Ptr32<Team>> p = (Ptr32<Ptr32<Team>>)w3d_allocate_80212fd4(n);
                Ptr32<Ptr32<Team>> e = (Ptr32<Ptr32<Team>>)((Ptr32<char>)p + n);
                teams.end = e;
                teams.capacity = e;
                teams.begin = p;
                w3d_copy_802eee50(w3d::VA(p), w3d::VA(w3d_teams_8043bb64.begin), n);
                owner = w3d_team_owner_800b4d98(teams[info->team]);
            }
            if (self != owner) {
                w3d_d24b_queue_input_8008e9c0(owner, owner->sub->message);
                return;
            }
        }
        if (!message->done && !message->queued) {
            message->queued = 1;
            w3d_pending_80431e94.push(Pair(self, message));
        }
    }
}


