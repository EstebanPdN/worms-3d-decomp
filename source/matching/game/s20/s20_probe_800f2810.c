typedef struct S20Vec { float x; float y; float z; } S20Vec;
extern float lbl_8038c4a4[];
void w3d_s20_push_entry_800f2810(char *self, S20Vec *position) {
    if (*(unsigned int *)(self + 1032) <= 48) {
        char *fields = self + 44;
        int life = 200;
        float scale;
        char *tail;
        *(S20Vec *)(self + *(int *)(self + 1032) * 20 + 32) = *position;
        scale = lbl_8038c4a4[0];
        *(float *)(fields + *(int *)(self + 1032) * 20) = scale;
        tail = self + *(int *)(self + 1032) * 20;
        *(unsigned char *)(tail + 48) = life;
        *(int *)(self + 1032) += 1;
    }
}
