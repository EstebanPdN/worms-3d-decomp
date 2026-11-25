/* Team-owner forwarding: if the system 0x804aab68 is active and the object's info
 * (+472, active flag +24, team index +32) names a different owner in the team list
 * 0x8043bb64 (0x800b4d98), forwards to it; otherwise queues the (object, message) pair
 * once in the pending list. Field and type names are inferred from the original
 * instructions; the lists are external views of original data. */
extern "C" char *w3d_allocate_80212fd4(unsigned);
extern "C" void w3d_release_802134fc(void *);
extern "C" void *w3d_copy_802eee50(...);
template <class T> inline const T &maximum(const T &a, const T &b) { return a < b ? b : a; }
template <class T> inline const T &minimum(const T &a, const T &b) { return b < a ? b : a; }
struct Message;
struct Owner;
struct Pair { Owner *owner; Message *message; Pair(Owner *o, Message *m) { message = m; owner = o; } };
struct PairList {
    Pair *begin, *end, *capacity;
    void push(const Pair &value) {
        if (end == capacity) {
            unsigned old = (char *)end - (char *)begin;
            int one = old + 1, grow = old + (old >> 1);
            unsigned bytes = maximum(one, grow) << 3;
            char *p = w3d_allocate_80212fd4(bytes);
            if (begin) {
                w3d_copy_802eee50(p, begin, minimum(bytes, old));
                w3d_release_802134fc(begin);
            }
            begin = (Pair *)p;
            end = (Pair *)(p + old);
            capacity = (Pair *)(p + bytes);
        }
        *end = value;
        end++;
    }
};
template <class T>
struct List {
    T *begin, *end, *capacity;
    List() {}
    ~List() { if (begin) w3d_release_802134fc(begin); }
    T &operator[](int i) { return begin[i]; }
};
struct Team;
extern List<Team *> w3d_teams_8043bb64;
extern PairList w3d_pending_80431e94;
extern int w3d_active_804aab68;
struct Info { char unknown00[24]; int active; char unknown28[4]; unsigned short team; };
struct Message { char unknown00[107]; unsigned char flag107, queued, done; };
struct Sub { char unknown00[32]; Message *message; };
struct Owner { char unknown00[44]; Sub *sub; char unknown48[424]; Info *info; };
extern "C" Owner *w3d_team_owner_800b4d98(Team *);

extern "C" void w3d_d24b_queue_input_8008e9c0(Owner *self, Message *message)
{
    if (w3d_active_804aab68) {
        Info *info = self->info;
        if (info->active) {
            Owner *owner;
            {
                List<Team *> teams;
                unsigned n = (char *)w3d_teams_8043bb64.end - (char *)w3d_teams_8043bb64.begin;
                Team **p = (Team **)w3d_allocate_80212fd4(n);
                Team **e = (Team **)((char *)p + n);
                teams.end = e;
                teams.capacity = e;
                teams.begin = p;
                w3d_copy_802eee50(p, w3d_teams_8043bb64.begin, n);
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
