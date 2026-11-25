/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s9_destroy_shared_owner_8017922c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_80178958 = 0x80178958;
lbl_80412450 = 0x80412450;
lbl_804124a0 = 0x804124a0;
SECTIONS {
  .text.s9_destroy_shared_owner_8017922c 0x8017922c : { *(.text.s9_destroy_shared_owner_8017922c) }
  .text.s9_destroy_shared_owner_80179520 0x80179520 : { *(.text.s9_destroy_shared_owner_80179520) }
  .sdata 0x804ab5cc (NOLOAD) : {
    . = 0x0; lbl_804ab5cc = .;
    . = 0x4; lbl_804ab5d0 = .;
    . = 0x4b8c; lbl_804b0158 = .;
    . = 0x4b90; lbl_804b015c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
