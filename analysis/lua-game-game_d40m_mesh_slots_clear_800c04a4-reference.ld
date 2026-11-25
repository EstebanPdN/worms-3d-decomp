/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(d40m_mesh_slots_clear_800c04a4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
format_803442b4 = 0x803442b4;
g_slots_8043c384 = 0x8043c384;
g_words_8043c394 = 0x8043c394;
memcpy = 0x802eee50;
reset_resources_80182450 = 0x80182450;
text_80382f88 = 0x80382f88;
SECTIONS {
  .text.d40m_mesh_slots_clear_800c04a4 0x800c04a4 : { *(.text.d40m_mesh_slots_clear_800c04a4) }
  .sdata 0x804aada8 (NOLOAD) : {
    . = 0x0; g_804aada8 = .;
    . = 0x6a44; g_renderer_804b17ec = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
