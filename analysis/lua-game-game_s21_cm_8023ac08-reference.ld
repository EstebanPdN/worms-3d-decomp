/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_8023ac08)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ea0ec = 0x801ea0ec;
fn_802408a0 = 0x802408a0;
lbl_8041ae28 = 0x8041ae28;
SECTIONS {
  .text.w3d_s21_construct_8023ac08 0x8023ac08 : { *(.text.w3d_s21_construct_8023ac08) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
