/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d30j_load_geometry_block_8017ffbc)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__3StrPCc = 0x8020bb54;
lbl_8040e078 = 0x8040e078;
lbl_80418de0 = 0x80418de0;
tsonnet_c26_temp_alloc_801fe0b8 = 0x801fe0b8;
w3d_buffer_request_read = 0x8020f618;
w3d_buffer_request_service = 0x80343944;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s21_create_80208af8 = 0x80208af8;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
w3d_temporary_release = 0x801fe160;
SECTIONS {
  .text.d30j_load_geometry_block_8017ffbc 0x8017ffbc : { *(.text.d30j_load_geometry_block_8017ffbc) }
  .rodata 0x803a77fc : { *(.rodata) }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
