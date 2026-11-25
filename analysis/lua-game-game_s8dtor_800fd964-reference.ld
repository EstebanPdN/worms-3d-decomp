/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s8_destroy_800fd964)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_801628ec = 0x801628ec;
w3d_vtable_80410520 = 0x80410520;
SECTIONS {
  .text.s8_destroy_800fd964 0x800fd964 : { *(.text.s8_destroy_800fd964) }
  .sdata 0x804aaf64 (NOLOAD) : {
    . = 0x0; lbl_804aaf64 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
