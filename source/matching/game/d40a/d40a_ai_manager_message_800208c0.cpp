// GWMP8P rev0 0x800208c0. AI manager message handler. Message 64 runs the
// base handler and starts the level (0x80020d18), failing with 0x80004005 on
// a negative result; 66 ends the level; other ids, when the AI bit of the
// game state is set, drive the planner state globals and the current team's
// turn, then go to the base handler. Field and id meanings are inferred; ids
// and strings are external views.
struct Message { unsigned short id; };
struct MessageCache { unsigned short id; unsigned char unknown[6]; };
struct GameState { char unknown00[188]; unsigned unknown188 : 6; unsigned ai_enabled : 1; unsigned unknown188b : 25; };
struct AiManager {
    char unknown00[28];
    void *team_source;
    char unknown32[4];
    int speech_pending;
    char unknown40[4];
    int active;
    char unknown48[68];
    void *speech;
};
struct TeamEntry { char unknown00[213]; unsigned char team; };
extern "C" int base_handle_8016293c(AiManager *, Message *);
extern "C" void level_start_80020d18(AiManager *);
extern "C" void level_end_80021050(AiManager *);
extern "C" int id_equals_8015f65c(unsigned short, MessageCache *);
extern "C" void read_8002107c(AiManager *);
extern "C" void planner_cleanup_800068b0(int);
extern "C" void end_turn_80020b20(AiManager *);
extern "C" void reset_dispatch_80021234(AiManager *);
extern "C" void *cast_803426b4(void *);
extern "C" int value_80178c48(void *);
extern "C" void begin_turn_80007b64(int);
extern "C" int active_team_80020834(AiManager *);
extern "C" TeamEntry *team_entry_800fc6dc(int);
extern "C" void start_turn_80020880(AiManager *, int, int);
extern "C" int select_80035714(void *, const char *, float);
extern "C" void speech_800226d0(void *);
extern GameState *w3d_state_804b1788;
extern MessageCache msg_804ac9a8, msg_804ac960, msg_804ac9b0, msg_804ac9b8, msg_804ac9c0, msg_804ac958, msg_804ac990, msg_804ac998, msg_804ac9a0;
extern int g_804aa7a4, g_804aa7a8, g_804aa59c;
extern void *w3d_game_804aa8c8;
extern const char s_default_8036bba8[];
extern float k_8036bbdc[];
extern "C" int w3d_d40a_ai_manager_message_800208c0(AiManager *self, Message *m)
{
    switch (m->id) {
    case 64:
        if (base_handle_8016293c(self, m) >= 0) {
            level_start_80020d18(self);
            return 0;
        }
        return 0x80004005;
    case 66:
        level_end_80021050(self);
        break;
    default: {
        int enabled = w3d_state_804b1788->ai_enabled;
        if (enabled == 1) {
            if (id_equals_8015f65c(m->id, &msg_804ac9a8)) {
                read_8002107c(self);
            } else if (id_equals_8015f65c(m->id, &msg_804ac960)) {
                g_804aa7a4 = 0;
                self->active = enabled;
                g_804aa7a8 = 0;
                planner_cleanup_800068b0(1);
                g_804aa59c = 0;
            } else if (id_equals_8015f65c(m->id, &msg_804ac9b0)) {
                g_804aa7a4 = enabled;
            } else if (id_equals_8015f65c(m->id, &msg_804ac9b8)) {
                g_804aa7a4 = 0;
            } else if (id_equals_8015f65c(m->id, &msg_804ac9c0)) {
                end_turn_80020b20(self);
                self->active = 0;
                planner_cleanup_800068b0(0);
                g_804aa7a4 = 0;
                g_804aa7a8 = 0;
            } else if (id_equals_8015f65c(m->id, &msg_804ac958)) {
                reset_dispatch_80021234(self);
                g_804aa7a8 = enabled;
            }
            int team = value_80178c48(cast_803426b4(self->team_source));
            if (team != -1) {
                if (id_equals_8015f65c(m->id, &msg_804ac990)) {
                    begin_turn_80007b64(team);
                    g_804aa7a8 = 0;
                }
                if (active_team_80020834(self)) {
                    unsigned char index = team_entry_800fc6dc(team)->team;
                    if (id_equals_8015f65c(m->id, &msg_804ac998)) {
                        end_turn_80020b20(self);
                    } else if (id_equals_8015f65c(m->id, &msg_804ac990)) {
                        g_804aa7a8 = 0;
                        start_turn_80020880(self, team, index);
                    } else if (id_equals_8015f65c(m->id, &msg_804ac9a0)) {
                        g_804aa7a8 = 0;
                        if (self->speech_pending) {
                            select_80035714(w3d_game_804aa8c8, s_default_8036bba8, k_8036bbdc[0]);
                            speech_800226d0(self->speech);
                        }
                    }
                }
            }
        }
        break;
    }
    }
    return base_handle_8016293c(self, m);
}
