/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d25g_ambient_sounds_start_800517a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_update_8015fd1c = 0x8015fd1c;
engine_80165254 = 0x80165254;
factor_800668e4 = 0x800668e4;
level_80051a18 = 0x80051a18;
names_803f40f4 = 0x803f40f4;
offset_80051a24 = 0x80051a24;
position_80066894 = 0x80066894;
random_8015ff5c = 0x8015ff5c;
zero_80378178 = 0x80378178;
SECTIONS {
  .text.w3d_d25g_ambient_sounds_start_800517a4 0x800517a4 : { *(.text.w3d_d25g_ambient_sounds_start_800517a4) }
  .sdata 0x804b1788 (NOLOAD) : {
    . = 0x0; game_804b1788 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
