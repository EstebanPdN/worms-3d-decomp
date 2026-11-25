extern void * w3d_auto_800fc1f0(const char **, int *);

int s19_weapons_dont_end_turn_800157cc(void) {
    const char *name = "AI.WeaponsDontEndTurn";
    int value;
    w3d_auto_800fc1f0(&name, &value);
    return value == 1;
}
