/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s21_entity_start_802af894)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8015f5a0 = 0x8015f5a0;
fn_80162024 = 0x80162024;
fn_80165254 = 0x80165254;
fn_802b0b84 = 0x802b0b84;
SECTIONS {
  .text.w3d_s21_entity_start_802af894 0x802af894 : { *(.text.w3d_s21_entity_start_802af894) }
  .sdata 0x804b0f44 (NOLOAD) : {
    . = 0x0; lbl_804b0f44 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
