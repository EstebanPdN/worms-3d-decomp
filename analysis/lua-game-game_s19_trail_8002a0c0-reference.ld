/* Generated reference-only placements. All bodies are source-built. */
OUTPUT_FORMAT("elf32-powerpc")
OUTPUT_ARCH(powerpc)
ENTRY(s19_start_trail_8002a0c0)
_SDA_BASE_ = 0x804b2540;
_SDA2_BASE_ = 0x804c2540;
FUN_800517a4 = 0x800517a4;
FUN_80164514 = 0x80164514;
lbl_8040eb10 = 0x8040eb10;
w3d_motion_get_2c_800668ec = 0x800668ec;
w3d_s10_service_forward_8020b680 = 0x8020b680;
w3d_s20_lookup_handle_object_80164fc8 = 0x80164fc8;
SECTIONS {
  .text.s19_start_trail_8002a0c0 0x8002a0c0 : { *(.text.s19_start_trail_8002a0c0) }
  .rodata 0x80372378 : { *(.rodata) }
  .sdata 0x804b178c (NOLOAD) : {
    . = 0x0; lbl_804b178c = .;
    . += 1; }
  /DISCARD/ : { *(.text*) *(.rodata*) *(.data*) *(.bss*) *(.sdata*) *(.sbss*) *(.comment) }
}
