/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_auto_8025d37c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_800A4ED0 = 0x800a4ed0;
fn_8015F5A0 = 0x8015f5a0;
fn_801613F0 = 0x801613f0;
fn_8016239C = 0x8016239c;
lbl_803CA81C = 0x803ca81c;
SECTIONS {
  .text.w3d_auto_8025d37c 0x8025d37c : { *(.text.w3d_auto_8025d37c) }
  .sdata 0x804b090c (NOLOAD) : {
    . = 0x0; lbl_804B090C = .;
    . = 0xe48; lbl_804B1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
