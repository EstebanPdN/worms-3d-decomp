/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_service_construct_801c1ef8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_80414d80 = 0x80414d80;
w3d_tagged_construct_801ea0ec = 0x801ea0ec;
SECTIONS {
  .text.w3d_k4b_service_construct_801c1ef8 0x801c1ef8 : { *(.text.w3d_k4b_service_construct_801c1ef8) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
