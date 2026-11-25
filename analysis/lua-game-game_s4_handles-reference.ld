/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_s4_handles_construct)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_ctor_8015fef0 = 0x8015fef0;
w3d_vtable_8041c010 = 0x8041c010;
SECTIONS {
  .text.w3d_s4_handles_construct 0x80287a84 : { *(.text.w3d_s4_handles_construct) }
  .text.w3d_s4_handles_clear 0x80287d30 : { *(.text.w3d_s4_handles_clear) }
  .sdata 0x804abbc8 (NOLOAD) : {
    . = 0x0; w3d_handles_instance_804abbc8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
