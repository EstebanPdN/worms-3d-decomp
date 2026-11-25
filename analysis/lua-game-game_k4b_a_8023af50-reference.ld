/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k4b_counter_set_construct_8023af50)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
lbl_8041ae00 = 0x8041ae00;
w3d_props_set_i32_80240b9c = 0x80240b9c;
w3d_tagged_construct_801ea0ec = 0x801ea0ec;
SECTIONS {
  .text.w3d_k4b_counter_set_construct_8023af50 0x8023af50 : { *(.text.w3d_k4b_counter_set_construct_8023af50) }
  .sdata 0x804b05ac (NOLOAD) : {
    . = 0x0; lbl_804b05ac = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
