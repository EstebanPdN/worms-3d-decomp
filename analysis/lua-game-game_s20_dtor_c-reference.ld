/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s20_destroy_listed_801a2668)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801fe1f8 = 0x801fe1f8;
fn_80210990 = 0x80210990;
fn_802134fc = 0x802134fc;
lbl_80411ac0 = 0x80411ac0;
lbl_80413a00 = 0x80413a00;
SECTIONS {
  .text.w3d_s20_destroy_listed_801a2668 0x801a2668 : { *(.text.w3d_s20_destroy_listed_801a2668) }
  .sdata 0x804ab750 (NOLOAD) : {
    . = 0x0; lbl_804ab750 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
