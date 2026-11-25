/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_f13c_activate_vector_8026a048)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
fn_8026d488 = 0x8026d488;
fn_8026d5c0 = 0x8026d5c0;
fn_8026d8e8 = 0x8026d8e8;
fn_8026d9a0 = 0x8026d9a0;
SECTIONS {
  .text.w3d_f13c_activate_vector_8026a048 0x8026a048 : { *(.text.w3d_f13c_activate_vector_8026a048) }
  .sdata 0x804abb7c (NOLOAD) : {
    . = 0x0; instance_804abb7c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
