/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_rope_enter_mode_800d0d6c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_message_allocate_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_str_80388170 = 0x80388170;
w3d_str_8038817c = 0x8038817c;
w3d_str_80388188 = 0x80388188;
w3d_str_80388194 = 0x80388194;
SECTIONS {
  .text.w3d_rope_enter_mode_800d0d6c 0x800d0d6c : { *(.text.w3d_rope_enter_mode_800d0d6c) }
  .text.w3d_rope_exit_mode_800d0e60 0x800d0e60 : { *(.text.w3d_rope_exit_mode_800d0e60) }
  .sdata 0x804ae948 (NOLOAD) : {
    . = 0x0; w3d_rope_message_804ae948 = .;
    . = 0x8; w3d_rope_message_804ae950 = .;
    . = 0x2e0c; w3d_message_pool_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
