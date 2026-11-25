/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40c_rope_trail_start_800cf2e8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
calc_800d1698 = 0x800d1698;
euler_801a3eb0 = 0x801a3eb0;
eye_803880c0 = 0x803880c0;
k_8043fde8 = 0x8043fde8;
malloc = 0x80212fd4;
memcpy_802eee50 = 0x802eee50;
query_800fc6dc = 0x800fc6dc;
read_800fc270 = 0x800fc270;
release_802134fc = 0x802134fc;
zero_8045e788 = 0x8045e788;
SECTIONS {
  .text.d40c_rope_trail_start_800cf2e8 0x800cf2e8 : { *(.text.d40c_rope_trail_start_800cf2e8) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
