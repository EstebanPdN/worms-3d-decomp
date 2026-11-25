/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(w3d_d29g_sky_start_8004f564)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
__6StringPCc = 0x8020bb54;
bind_804143e0 = 0x804143e0;
effect_803778fc = 0x803778fc;
name_804100a8 = 0x804100a8;
name_80410680 = 0x80410680;
name_80417120 = 0x80417120;
w3d_auto_8020b648 = 0x8020b648;
w3d_load_8015adf4 = 0x8015adf4;
w3d_register_80164514 = 0x80164514;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s20_forward_global_800e5ca4 = 0x800e5ca4;
w3d_string_base_finish = 0x8020c5c4;
w3d_string_release = 0x80341588;
SECTIONS {
  .text.w3d_d29g_sky_start_8004f564 0x8004f564 : { *(.text.w3d_d29g_sky_start_8004f564) }
  .rodata 0x80377948 : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; registry_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
