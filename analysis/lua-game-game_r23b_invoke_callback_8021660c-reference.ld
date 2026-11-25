/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_r23b_invoke_callback_8021660c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
SECTIONS {
  .text.w3d_r23b_invoke_callback_8021660c 0x8021660c : { *(.text.w3d_r23b_invoke_callback_8021660c) }
  .sdata 0x804aba74 (NOLOAD) : {
    . = 0x0; r23b_callbacks_804aba74 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
