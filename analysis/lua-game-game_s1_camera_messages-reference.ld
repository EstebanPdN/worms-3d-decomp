/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_80067a04)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_800fc230 = 0x800fc230;
w3d_fn_801613f0 = 0x801613f0;
w3d_message_post_current = 0x8016239c;
w3d_message_string_init = 0x8010a8e0;
w3d_service_mode_virtual_query = 0x8015a6b8;
w3d_str_8037a11c = 0x8037a11c;
w3d_str_8037a134 = 0x8037a134;
w3d_str_8037a144 = 0x8037a144;
w3d_str_8037a14c = 0x8037a14c;
w3d_str_8037a154 = 0x8037a154;
w3d_str_8037a160 = 0x8037a160;
w3d_str_8037a178 = 0x8037a178;
w3d_str_8037a184 = 0x8037a184;
w3d_str_8037a190 = 0x8037a190;
SECTIONS {
  .text.w3d_fn_80067a04 0x80067a04 : { *(.text.w3d_fn_80067a04) }
  .sdata 0x804ad5e0 (NOLOAD) : {
    . = 0x0; w3d_message_804ad5e0 = .;
    . = 0x8; w3d_message_804ad5e8 = .;
    . = 0x4174; w3d_queue_804b1754 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
