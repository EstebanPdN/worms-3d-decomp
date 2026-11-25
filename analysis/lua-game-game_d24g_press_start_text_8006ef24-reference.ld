/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_press_start_text_8006ef24)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
as_text_80343580 = 0x80343580;
context_80165254 = 0x80165254;
fill_text_8018d35c = 0x8018d35c;
load_8015adf4 = 0x8015adf4;
read_800fc2b0 = 0x800fc2b0;
s_8037c4a8 = 0x8037c4a8;
s_8037c4b0 = 0x8037c4b0;
string_finish_8020c5c4 = 0x8020c5c4;
string_release_80341588 = 0x80341588;
text_set_8018c5b0 = 0x8018c5b0;
text_style_8018d324 = 0x8018d324;
SECTIONS {
  .text.w3d_d24g_press_start_text_8006ef24 0x8006ef24 : { *(.text.w3d_d24g_press_start_text_8006ef24) }
  .rodata 0x8037c4c0 : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
