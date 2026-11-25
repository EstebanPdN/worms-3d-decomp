/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k5b_shared_defaults_create_801edab8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80417670 = 0x80417670;
lbl_804176a0 = 0x804176a0;
lbl_804176d0 = 0x804176d0;
w3d_aligned_allocate = 0x801fe2a8;
w3d_tagged_construct_801ee1e4 = 0x801ee1e4;
SECTIONS {
  .text.w3d_k5b_shared_defaults_create_801edab8 0x801edab8 : { *(.text.w3d_k5b_shared_defaults_create_801edab8) }
  .sdata 0x804b05a8 (NOLOAD) : {
    . = 0x0; lbl_804b05a8 = .;
    . = 0x4; lbl_804b05ac = .;
    . = 0x8; lbl_804b05b0 = .;
    . = 0xc; lbl_804b05b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
