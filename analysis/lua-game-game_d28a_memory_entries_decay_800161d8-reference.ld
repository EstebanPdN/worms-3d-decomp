/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d28a_memory_entries_decay_800161d8)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
memcpy = 0x802eee50;
w3d_auto_80015588 = 0x80015588;
w3d_auto_800155ac = 0x800155ac;
w3d_auto_80015d18 = 0x80015d18;
SECTIONS {
  .text.w3d_d28a_memory_entries_decay_800161d8 0x800161d8 : { *(.text.w3d_d28a_memory_entries_decay_800161d8) }
  .rodata 0x8036a650 : { *(.rodata) }
  .sdata 0x804aa6f8 (NOLOAD) : {
    . = 0x0; g_entries_804aa6f8 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
