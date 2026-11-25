/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_camera_system_start_8006f62c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
arena_alloc_801613f0 = 0x801613f0;
compute_8006fca0 = 0x8006fca0;
context_80165254 = 0x80165254;
lookup_80164fc8 = 0x80164fc8;
message_id_8015f5a0 = 0x8015f5a0;
message_post_8016239c = 0x8016239c;
message_string_8010a8e0 = 0x8010a8e0;
query_8015a6b8 = 0x8015a6b8;
read_800fc230 = 0x800fc230;
read_800fc2b0 = 0x800fc2b0;
s_8037c8c4 = 0x8037c8c4;
s_8037c8dc = 0x8037c8dc;
s_8037c8e8 = 0x8037c8e8;
s_8037c8f0 = 0x8037c8f0;
s_8037c8f8 = 0x8037c8f8;
s_8037c904 = 0x8037c904;
s_8037c91c = 0x8037c91c;
s_8037c928 = 0x8037c928;
s_8037c934 = 0x8037c934;
s_8037c944 = 0x8037c944;
set_data_8006fc24 = 0x8006fc24;
SECTIONS {
  .text.w3d_d24g_camera_system_start_8006f62c 0x8006f62c : { *(.text.w3d_d24g_camera_system_start_8006f62c) }
  .sdata 0x804ad878 (NOLOAD) : {
    . = 0x0; msg_804ad878 = .;
    . = 0x8; msg_804ad880 = .;
    . = 0x3edc; arena_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
