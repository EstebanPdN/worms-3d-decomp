/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(k4a_chat_initialize_80038c74)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_80164514 = 0x80164514;
w3d_auto_80038d1c = 0x80038d1c;
w3d_constructor_lookup_name = 0x800fc1b0;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_service_8040e640 = 0x8040e640;
w3d_str_8037400c = 0x8037400c;
w3d_str_8037401c = 0x8037401c;
w3d_str_80374024 = 0x80374024;
w3d_str_8037402c = 0x8037402c;
w3d_string_assign = 0x8020bd38;
SECTIONS {
  .text.k4a_chat_initialize_80038c74 0x80038c74 : { *(.text.k4a_chat_initialize_80038c74) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; w3d_context_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
