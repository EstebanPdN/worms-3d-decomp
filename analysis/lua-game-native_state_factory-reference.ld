/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_state_completion_callback)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_original_8017ec0c_for_state = 0x8017ec0c;
w3d_original_801d4544 = 0x801d4544;
w3d_original_801fe1d8_for_state = 0x801fe1d8;
w3d_ref_state_registry = 0x80361b98;
SECTIONS {
  .text.w3d_state_completion_callback 0x8017ea68 : { *(.text.w3d_state_completion_callback) }
  .text.w3d_state_create 0x8017eae4 : { *(.text.w3d_state_create) }
  .text.w3d_state_register 0x8020fd04 : { *(.text.w3d_state_register) }
  .sdata 0x804b01b0 (NOLOAD) : {
    . = 0x0; w3d_ref_state_callback_argument = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
