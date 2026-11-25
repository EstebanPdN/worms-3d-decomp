/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f6a_destroy_console_8028e02c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800c45b8 = 0x800c45b8;
fn_801628ec = 0x801628ec;
fn_8020c5c4 = 0x8020c5c4;
fn_80341588 = 0x80341588;
fn_8035edbc = 0x8035edbc;
vt_8041c1b0 = 0x8041c1b0;
SECTIONS {
  .text.w3d_f6a_destroy_console_8028e02c 0x8028e02c : { *(.text.w3d_f6a_destroy_console_8028e02c) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
