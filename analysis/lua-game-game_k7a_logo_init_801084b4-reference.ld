/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_k7a_logo_init_801084b4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_engine_get_context = 0x80165254;
w3d_f32_80399bcc = 0x80399bcc;
w3d_f32_80399bd0 = 0x80399bd0;
w3d_f32_80399bd4 = 0x80399bd4;
w3d_handle_set_name = 0x8015adf4;
w3d_str_80399bbc = 0x80399bbc;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_from_text = 0x8020bb54;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_k7a_logo_init_801084b4 0x801084b4 : { *(.text.w3d_k7a_logo_init_801084b4) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
