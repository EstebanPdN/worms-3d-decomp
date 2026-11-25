/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d24g_target_messages_8004ddc8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
base_8015fb34 = 0x8015fb34;
clips_8004e5ac = 0x8004e5ac;
end_8015fd1c = 0x8015fd1c;
id_equals_8015f65c = 0x8015f65c;
init_8004def0 = 0x8004def0;
search_8004e324 = 0x8004e324;
stop_8004e0d8 = 0x8004e0d8;
SECTIONS {
  .text.w3d_d24g_target_messages_8004ddc8 0x8004ddc8 : { *(.text.w3d_d24g_target_messages_8004ddc8) }
  .sdata 0x804ad424 (NOLOAD) : {
    . = 0x0; c_804ad424 = .;
    . = 0x18; c_804ad43c = .;
    . = 0x20; c_804ad444 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
