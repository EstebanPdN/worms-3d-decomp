/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_cc17c_object_register_801e74d0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
allocate_80212fd4 = 0x80212fd4;
copy_802eee50 = 0x802eee50;
fn_801e7e24 = 0x801e7e24;
fn_801ffea8 = 0x801ffea8;
fn_80356474 = 0x80356474;
free_802134fc = 0x802134fc;
lbl_8045e024 = 0x8045e024;
SECTIONS {
  .text.w3d_cc17c_object_register_801e74d0 0x801e74d0 : { *(.text.w3d_cc17c_object_register_801e74d0) }
  .sdata 0x804ab894 (NOLOAD) : {
    . = 0x0; lbl_804ab894 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
