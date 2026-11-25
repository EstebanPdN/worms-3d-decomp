/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004a7f4)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
strcmp = 0x802ef234;
w3d_fn_8003a264 = 0x8003a264;
w3d_fn_8004a930 = 0x8004a930;
w3d_fn_8004a988 = 0x8004a988;
w3d_fn_8004aa60 = 0x8004aa60;
w3d_fn_8004af78 = 0x8004af78;
w3d_fn_8004b3c8 = 0x8004b3c8;
w3d_fn_8004b448 = 0x8004b448;
w3d_fn_8004b7e0 = 0x8004b7e0;
w3d_fn_800fc1f0 = 0x800fc1f0;
w3d_fn_800fc270 = 0x800fc270;
w3d_fn_801613f0 = 0x801613f0;
w3d_lowercase_802efa2c = 0x802efa2c;
w3d_message_post_current = 0x8016239c;
w3d_sprintf_802ec254 = 0x802ec254;
w3d_str_80376f58 = 0x80376f58;
w3d_str_80376f5c = 0x80376f5c;
w3d_str_80376f74 = 0x80376f74;
w3d_str_8037710c = 0x8037710c;
SECTIONS {
  .text.w3d_fn_8004a7f4 0x8004a7f4 : { *(.text.w3d_fn_8004a7f4) }
  .text.w3d_fn_8004b3f0 0x8004b3f0 : { *(.text.w3d_fn_8004b3f0) }
  .text.w3d_fn_8004b908 0x8004b908 : { *(.text.w3d_fn_8004b908) }
  .sdata 0x804aa9b0 (NOLOAD) : {
    . = 0x0; w3d_kind_804aa9b0 = .;
    . = 0x4; w3d_kind_804aa9b4 = .;
    . = 0x8; w3d_kind_804aa9b8 = .;
    . = 0xc; w3d_kind_804aa9bc = .;
    . = 0x6da4; w3d_queue_804b1754 = .;
    . = 0x6df0; w3d_result_804b17a0 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
