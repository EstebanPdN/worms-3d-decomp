// Estadísticas de partida de cada equipo: al terminar, las de la partida van a las del equipo activo. Y lista de equipos en juego.
#include "native_game.h"

namespace {
struct TeamStats {
    char pad[0x14];
    w3d_u32 best_points;       // +0x14
    w3d_u32 most_kills;        // +0x18
    char pad2[4];
    w3d_u32 total_damage;      // +0x20
    w3d_u32 total_shots;       // +0x24
    w3d_u32 last_round_score;  // +0x28
    w3d_u32 last_round_bonus;  // +0x2c
    w3d_u32 play_time;         // +0x30
    w3d_u32 games_empty;       // +0x34
    w3d_u32 total_games;       // +0x38
    w3d_u32 total_points;      // +0x3c
    w3d_u32 total_kills;       // +0x40
};
struct MatchRecorder {
    char pad[0x54];
    w3d_u32 points_a, points_b;  // +0x54
    w3d_u32 kills;               // +0x5c
    w3d_u32 shots;               // +0x60
    w3d_u32 damage;              // +0x64
    w3d_u32 round_score;         // +0x68
    w3d_u32 round_bonus;         // +0x6c
    w3d_u32 games;               // +0x70
    w3d_u32 started;             // +0x74
};
struct TeamInfo { char pad[0xd5]; uint8_t group; char pad2[0xdc - 0xd6]; w3d_u32 in_play; };
struct GroupInfo { char pad[0x2c]; w3d_u32 is_human; };
struct EngineContext { char pad[0x34]; w3d_u32 time; };
const w3d_u32 kHumanBonus = 9;
}
extern "C" {
extern const char A80399cd8[], A80399ce8[];
w3d_u32 A800fc1f0(void *key, void *out, ...);
w3d_u32 A800fc1b0(void *key, void *out, ...);
void A803426b8(GameString *string);
void A8020c510(GameString *string, const char *format, ...);
void A80341588(GameString *string);
w3d_u32 A800fc6dc(void *team);
w3d_u32 A800fc7f8(void *group);
w3d_u32 A80165254();

// El recurso de estadísticas de un equipo, por nombre.
static void find_stats(GameString *name, w3d_u32 team, Ptr32<void> *found) {
    A8020c510(name, A80399ce8, (long)team);
    Ptr32<char> key = name->text;
    ((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, found);
}
// 0x80109bec
void A80109bec(Ptr32<MatchRecorder> self) {
    Ptr32<const char> team_key(A80399cd8);
    int team = 0;
    ((w3d_u32 (*)(void *, void *))A800fc1f0)(&team_key, &team);
    if (team < 0) return;
    ResourceRef ref;
    GameString name;
    A803426b8(&name);
    Ptr32<void> found{(void *)nullptr};
    find_stats(&name, team, &found);
    TeamStats *stats = (TeamStats *)typed_resource(found.get(), &ref);
    const w3d_u32 group = at<TeamInfo>(A800fc6dc(arg(team)))->group;
    if (group <= 3 && at<GroupInfo>(A800fc7f8(arg(group)))->is_human == 1) self->round_score += kHumanBonus;
    w3d_u32 play_time = stats->play_time;
    const w3d_u32 now = at<EngineContext>(A80165254())->time;
    if (now > self->started) play_time += now - self->started;
    stats->play_time = play_time;
    stats->total_games += self->games;
    stats->last_round_score = self->round_score;
    stats->last_round_bonus = self->round_bonus;
    if (!self->points_a && !self->points_b) {
        stats->games_empty++;
    } else {
        const w3d_u32 points = self->points_a + self->points_b;
        if (points > stats->best_points) stats->best_points = points;
        stats->total_points += self->points_a;
    }
    stats->total_damage += self->damage;
    stats->total_kills += self->kills;
    stats->total_shots += self->shots;
    if (self->kills > stats->most_kills) stats->most_kills = self->kills;
    release_if_set(stats);
    // El original recorre los otros equipos en juego y no hace nada con sus datos, salvo crear y soltar las referencias.
    for (w3d_u32 other = 0; other < 16; other++) {
        if (at<TeamInfo>(A800fc6dc(arg(other)))->in_play != 1) continue;
        ResourceRef other_ref;
        Ptr32<void> other_found{(void *)nullptr};
        find_stats(&name, other, &other_found);
        release_if_set(typed_resource(other_found.get(), &other_ref));
        release_if_set(other_found.get());
        A80178474(&other_ref, 2);
    }
    A80341588(&name);
    release_if_set(found.get());
    A80178474(&ref, 2);
}

// 0x80156214: reparte los equipos que pueden jugar por grupo. Las listas de cada grupo quedan en el orden de los equipos.
struct TurnQueues { char pad[0x64]; WordVector groups[4]; };
extern const char A803a2aa4[];
w3d_u32 A80155850(void *self, w3d_u32 team);

void A80156214(Ptr32<TurnQueues> self) {
    Ptr32<void> found{(void *)nullptr};
    ResourceRef ref;
    Ptr32<const char> key(A803a2aa4);
    if ((int)((w3d_u32 (*)(void *, void *))A800fc1b0)(&key, &found) < 0) {
        A80178474(&ref, 2);
        release_if_set(found.get());
        return;
    }
    void *order = typed_resource(found.get(), &ref);
    for (WordVector &group : self->groups) group.end = group.begin;
    for (w3d_u32 team = 0; team <= 3; team++) {
        const w3d_u32 group = *(uint8_t *)((char *)g2h(A800fc7f8(arg(team))) + 60);
        if (A80155850(self.get(), team) == 1 && group <= 3) self->groups[group].push_back(team);
    }
    release_if_set(order);
    A80178474(&ref, 2);
    release_if_set(found.get());
}
}
