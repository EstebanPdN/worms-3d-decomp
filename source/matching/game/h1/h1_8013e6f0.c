/* Property reads (session 47b5d14a, hand-matched). The property readers
 * return a value that these callers ignore; declaring them void changes
 * GCC 2.95's argument scheduling, so they are declared returning int. */

typedef struct W3dTeamRecord_8021eb00 {
    unsigned char unknown_00[32];
    int value;                      /* +32 */
} W3dTeamRecord_8021eb00;

extern char w3d_string_worm_script_speech_8039fca0[];
extern char w3d_string_current_team_index_803b4f6c[];

int w3d_auto_800fc1f0(const char **name, int *value);
int w3d_auto_800fc2b0(const char **name, int *value);
W3dTeamRecord_8021eb00 *s8_index_query_800fc7f8(int index);
void fn_8013bd0c(void *self, int value);

void w3d_h1_worm_script_speech_apply_8013e6f0(void *self)
{
    const char *name;
    int value;
    value = 0;
    name = w3d_string_worm_script_speech_8039fca0;
    w3d_auto_800fc2b0(&name, &value);
    fn_8013bd0c(self, value);
}

int w3d_h1_current_team_value_8021eb00(void)
{
    const char *name;
    int value;
    value = -1;
    name = w3d_string_current_team_index_803b4f6c;
    w3d_auto_800fc1f0(&name, &value);
    return s8_index_query_800fc7f8(value)->value;
}
