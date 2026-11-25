/* Observed primitive operations; names and external object ownership are provisional. */
extern unsigned char state_804b1648;
extern unsigned int state_804b1748, state_804b1734;
unsigned int tterra_cw39_shift_80333a4c(unsigned int x) { return x >> 8; }
void tterra_cw39_set_byte_80333c94(unsigned char x) { state_804b1648 = x; }
unsigned char tterra_cw39_get_byte_80333c9c(void) { return state_804b1648; }
void tterra_cw39_set_word_80333cc4(unsigned int x) { state_804b1748 = x; }
void tterra_cw39_reset_word_803349b0(void) { state_804b1734 = 0; }
void tterra_cw39_shift_word_803339f4(unsigned int *p) { *p <<= 8; }
