/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25g_explosion_message_800666b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
message_id_8015f5a0 = 0x8015f5a0;
read_int_800fc1f0 = 0x800fc1f0;
s_80379f74 = 0x80379f74;
s_80379f84 = 0x80379f84;
s_80379fa0 = 0x80379fa0;
s_80379fbc = 0x80379fbc;
s_80379fdc = 0x80379fdc;
s_80379ff8 = 0x80379ff8;
s_8037a014 = 0x8037a014;
s_8037a030 = 0x8037a030;
vt_8040db38 = 0x8040db38;
write_float_800fc4c8 = 0x800fc4c8;
write_vec_800fc5dc = 0x800fc5dc;
SECTIONS {
  .text.w3d_d25g_explosion_message_800666b4 0x800666b4 : { *(.text.w3d_d25g_explosion_message_800666b4) }
  .sdata 0x804ad5a8 (NOLOAD) : {
    . = 0x0; msg_804ad5a8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
