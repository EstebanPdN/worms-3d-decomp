/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_fn_8004e964)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
w3d_auto_8011ab68 = 0x8011ab68;
w3d_auto_8015fd1c = 0x8015fd1c;
w3d_cached_message_id = 0x8015f5a0;
w3d_fn_8004ed24 = 0x8004ed24;
w3d_fn_800fc1f0 = 0x800fc1f0;
w3d_fn_8011ac1c = 0x8011ac1c;
w3d_fn_8011adf8 = 0x8011adf8;
w3d_sprintf_802ec254 = 0x802ec254;
w3d_str_8037787c = 0x8037787c;
w3d_str_80377888 = 0x80377888;
w3d_str_8037788c = 0x8037788c;
w3d_str_803778a4 = 0x803778a4;
w3d_vtable_8040db38 = 0x8040db38;
SECTIONS {
  .text.w3d_fn_8004e964 0x8004e964 : { *(.text.w3d_fn_8004e964) }
  .text.w3d_fn_8004e9c8 0x8004e9c8 : { *(.text.w3d_fn_8004e9c8) }
  .text.w3d_fn_8004ea78 0x8004ea78 : { *(.text.w3d_fn_8004ea78) }
  .text.w3d_fn_8004ec64 0x8004ec64 : { *(.text.w3d_fn_8004ec64) }
  .text.w3d_fn_8004ee4c 0x8004ee4c : { *(.text.w3d_fn_8004ee4c) }
  .sdata 0x804ad460 (NOLOAD) : {
    . = 0x0; w3d_message_804ad460 = .;
    . = 0x1f54; w3d_color_804af3b4 = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
