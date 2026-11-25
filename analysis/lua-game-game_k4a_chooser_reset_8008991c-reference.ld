/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_chooser_reset_8008991c)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80164514 = 0x80164514;
s8_index_query_800fc6dc = 0x800fc6dc;
w3d_auto_800fc1f0 = 0x800fc1f0;
w3d_auto_800fc230 = 0x800fc230;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_80410f70 = 0x80410f70;
w3d_str_8037d7d0 = 0x8037d7d0;
w3d_str_8037d874 = 0x8037d874;
SECTIONS {
  .text.k4a_chooser_reset_8008991c 0x8008991c : { *(.text.k4a_chooser_reset_8008991c) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
