/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_construct_802371dc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801ea0ec = 0x801ea0ec;
fn_8025d618 = 0x8025d618;
lbl_8041a798 = 0x8041a798;
SECTIONS {
  .text.w3d_s21_construct_802371dc 0x802371dc : { *(.text.w3d_s21_construct_802371dc) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
