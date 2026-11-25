/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_sheep_input_message_80070b64)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_80071368 = 0x80071368;
w3d_auto_800ea62c = 0x800ea62c;
w3d_d24g_super_sheep_start_80070fec = 0x80070fec;
w3d_engine_get_context = 0x80165254;
w3d_message_id_equals_cache = 0x8015f65c;
SECTIONS {
  .text.w3d_d29g_sheep_input_message_80070b64 0x80070b64 : { *(.text.w3d_d29g_sheep_input_message_80070b64) }
  .sdata 0x804ad8c4 (NOLOAD) : {
    . = 0x0; s0_804ad8c4 = .;
    . = 0x8; s1_804ad8cc = .;
    . = 0x10; s2_804ad8d4 = .;
    . = 0x18; s3_804ad8dc = .;
    . = 0x20; s4_804ad8e4 = .;
    . = 0x28; s5_804ad8ec = .;
    . = 0x30; s6_804ad8f4 = .;
    . = 0x38; s7_804ad8fc = .;
    . = 0x40; s8_804ad904 = .;
    . = 0x48; s9_804ad90c = .;
    . = 0x50; s10_804ad914 = .;
    . = 0x58; s11_804ad91c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
